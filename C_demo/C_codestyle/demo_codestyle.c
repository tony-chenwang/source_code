/*******************************************************************************
  * Copyright(C),2018,Mstar semi.co.,Ltd
  * @file Namev : 
  * @author  tony.chen@mstarsemi.com
  * @version V1.0.0
  * @date     
  * @brief
  * @History
*******************************************************************************/
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MI must define before mi_common.h 
#define  MI_ENABLE_DBG  true
#define  DBG_LEVEL  MI_DBG_ALL

#include "mi_common.h"
#include "mi_internal.h"


#define CHECK_RET(X)  \
    {   \
        if( X < 0 )  \
        {   \
            DBG_ERR("INVALID RETURN VALUE \n");  \
            fprintf(stderr," error msg is :%s\n",strerror(errno));\
            exit(-1);\
        }   \
    }   \

// typedef enum  
// MI_OSD_ColorKeyOperation_e; end with _e
// every enum must be start with E_
// must add E_MI_OSD_COLOR_KEY_OPERATION_MAX for max
// must follow this style 
typedef enum
{
    /// If EQUAL then perform CK operation
    E_MI_OSD_COLOR_KEY_OPERATION_RGB_EQUAL = 0,
    /// If NOT EQUAL then perform CK operation
    E_MI_OSD_COLOR_KEY_OPERATION_RGB_NOT_EQUAL,
    /// If EQUAL then perform Alpha Key operation
    E_MI_OSD_COLOR_KEY_OPERATION_ALPHA_EQUAL,
    /// If NOT EQUAL then Alpha Key operation
    E_MI_OSD_COLOR_KEY_OPERATION_ALPHA_NOT_EQUAL,
    /// If EQUAL then perform Alpha + Color  Key operation
    E_MI_OSD_COLOR_KEY_OPERATION_ARGB_EQUAL,
    /// If NOT EQUAL then Alpha + Color Key operation
    E_MI_OSD_COLOR_KEY_OPERATION_ARGB_NOT_EQUAL,
    /// Max of CKey op
    E_MI_OSD_COLOR_KEY_OPERATION_MAX,
} MI_OSD_ColorKeyOperation_e;


// we can also follow this style  use MI_OS_Attribute_s
typedef enum MI_OS_Attribute_s
{
    E_MI_OS_ATTRIBUTE_INVALID = -1,
    E_MI_OS_ATTRIBUTE_MIN = 0,

    E_MI_OS_ATTRIBUTE_PRIORITY = E_MI_OS_ATTRIBUTE_MIN, ///< Priority-order suspension
    E_MI_OS_ATTRIBUTE_FIFO,                             ///< FIFO-order suspension

    E_MI_OS_ATTRIBUTE_MAX,
} MI_OS_Attribute_e;


//  struct use  MI_OS_FixSizeMemPoolParams_s for struct name
//  MI_OS_FixSizeMemPoolParams_t for type name 
typedef struct MI_OS_FixSizeMemPoolParams_s
{
    MI_U32 u32PoolSize;                                 ///[IN]: Pool size in bytes
    MI_U32 u32BlockSize;                                ///[IN]: Fixed block size for each allocated block in the pool
    void *pPoolAddr;                                    ///[IN]: Starting virtual address for the memory pool
} MI_OS_FixSizeMemPoolParams_t;

typedef struct MI_OS_CreateTaskParams_s
{
    MI_OS_TaskEntry pfTaskEntry;                        ///[IN]: Task entry function
    void *pTaskEntryData;                               ///[IN]: The parameter data when the task entry function is invoked
    MI_OS_TaskPriority_e eTaskPriority;                 ///[IN]: Task's priority
    MI_BOOL bAutoStart;                                 ///[IN]: Start immediately or later
    void *pStackEntry;                                  ///[IN]: Task's stack
    MI_U32 u32StackSize;                                ///[IN]: Stack's size
    MI_U8 *pszTaskName;                                 ///[IN]: Task's name
} MI_OS_CreateTaskParams_t;


/************************************************************
********************  variable define **********************
**************************************************************/
// use prefix + pascal name 
//Varable define   must have prefix b
MI_BOOL                 bWaitCallback;
MI_BOOL                 bWaitSync;

// u32  variable

MI_U32                  u32TVTime;
MI_U32                  u32TotalTime;

//s32   variable
MI_S32 s32TaskId;                       ///< task id

//u8 variable
MI_U8 u8ServiceCnt;

//hanle start with h 
MI_HANDLE hCapDS;

// physical address start with phy
MI_PHY phyFzBufAddr;

// pointer start with pointer 
void*   pEventparam;  ///< Event parameter
void*   pUsrParam;    ///< User parameter


/*
pointer to multi type : pu64 pu32 pu8 pu16  ps64 ps32 ps8 ps16

pointer to struct : pst

array of multi type : au64 au32 au16 au8  as64 as32 as16 as8

array of stuct ast

array of pointer ap
*/

// global variables start with g + type   gu32  gb gu64  donot use _
static MI_VMON_SystemInfo_t *gstZapSysInfo[MI_VMON_PATH_MAX] = {0};
/// VMon handle pointer for Main/Sub decoder
static MI_VMON_Handle_t *gstVMonHandle[MI_VMON_PATH_MAX] = {0};
/// VMon event handler info
static MI_VMON_EventHandlerTaskInfo_t *_pstEventHandlerInfo = NULL;



/************************************************************
********************  Macro define **********************
**************************************************************/
// all use Captial & use _  use () 
#define VMON_FRAMERDY_TIMEOUT             (500)
/// VMon reach sync timeout
#define VMON_REACHSYNC_TIMEOUT            (300)
/// VMon task delay time
#define VMON_TASK_DELAYTIME               (10)
/// VMon task stack size
#define VMON_STACK_SIZE                   (8192)
/// vmon start event id
#define VMON_START_EVENT                  (0x00000001)


// MI(FBDEVDEMO)_modules_operation operaion must be  SurfaceDestroy type
/**********************************************************/
MI_RESULT MI_OSD_SurfaceDestroy(MI_HANDLE hSurface);

//------------------------------------------------------------------------------
/// @brief get mem type of the surface (the mem is from MMP or linux OS)
/// @param[in] hSurface: the handle of the surface
/// @param[out] peMemoryType: the mem type
/// @return MI_OK: Process success.
/// @return MI_ERR_INVALID_HANDLE: Handle is invalid.
//------------------------------------------------------------------------------
MI_RESULT MI_OSD_SurfaceGetMemoryType(MI_HANDLE hSurface, MI_OSD_MemoryType_e *peMemoryType);

//------------------------------------------------------------------------------
/// @brief get owner of the surface (the surface is controlled by AP or SDK)
/// @param[in] hSurface: the handle of the surface
/// @param[out] peOwner: the owner
/// @return MI_OK: Process success.
/// @return MI_ERR_INVALID_PARAMETER: Parameters is invalid.
/// @return MI_ERR_INVALID_HANDLE: Handle is invalid.
//------------------------------------------------------------------------------
MI_RESULT MI_OSD_SurfaceGetOwner(MI_HANDLE hSurface, MI_OSD_SurfaceOwner_e *peOwner);

//------------------------------------------------------------------------------
/// @brief set const alpha value of the surface,
/// this alpha value will be applied once when alpha blend with const alpha enabled
/// @param[in] hSurface: the handle of the surface
/// @param[in] u8Alpha: constant alpha value
/// @return MI_OK: Process success.
/// @return MI_ERR_INVALID_HANDLE: Handle is invalid.
//------------------------------------------------------------------------------
MI_RESULT MI_OSD_SurfaceSetConstAlpha(MI_HANDLE hSurface, const MI_U8 u8Alpha);

//------------------------------------------------------------------------------
/// @brief get const alpha value of the surface,
/// @param[in] hSurface: the handle of the surface
/// @param[out] pu8Alpha: constant alpha value
/// @return MI_OK: Process success.
/// @return MI_ERR_INVALID_HANDLE: Handle is invalid.
//------------------------------------------------------------------------------
MI_RESULT MI_OSD_SurfaceGetConstAlpha(MI_HANDLE hSurface, MI_U8 *pu8Alpha);


//***
// file name
mi_osd.c
mi_osd.h

mi_vmon.c
mi_vmon.h
int main(int argc,char * argv[])
{
    MI_PRINT("This is my first demo! %s builddate:%s %s\n",__FUNCTION__,__DATE__,__TIME__);
    MI_U32 ValueA = 100;
	MI_U32 ValueB = 200;
    MI_U32 ValueC = 300;
	MI_U32 ValueMAX = 0;
	MI_U32 ValueMIN = 0;
   
     while(1)
     {
        //system("clear");	
		MI_U32 ALIGNVALUE = 13+16;
		MI_PRINT("The ALIGN value  is %d \n",ALIGN_DOWNTO_16(ALIGNVALUE));
		MI_PRINT("The ALIGN value  is %d \n",MEM_ALIGN(ALIGNVALUE,16));

		GETMAX(ValueMAX,ValueA,ValueB,ValueC)
	        MI_PRINT("The MAX value of A&B&C is %d \n",ValueMAX);

		GETMIN(ValueMIN,ValueA,ValueB,ValueC)
		MI_PRINT("The MIN value of A&B&C is %d \n",ValueMIN);
	        sleep(2);    
    } 
     return 0;
}
