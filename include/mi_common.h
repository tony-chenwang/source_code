//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// @file    mi_common.h
/// @brief The common interface definition
/// @author MStar Semiconductor Inc.
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MI_COMMON_H_
#define _MI_COMMON_H_

#ifndef MSOS_TYPE_LINUX_KERNEL
#include <stdio.h>
#include <stdlib.h>

#ifndef __BIONIC__
#include <execinfo.h>
#else
#endif
#else
#endif

#ifdef MSOS_TYPE_ECOS
#include <cyg/infra/diag.h>
#endif

//-------------------------------------------------------------------------------------------------
//  System Data Type
//-------------------------------------------------------------------------------------------------

/// data type unsigned char, data length 1 byte
typedef unsigned char                            MI_U8;         // 1 byte
/// data type unsigned short, data length 2 byte
typedef unsigned short                           MI_U16;        // 2 bytes
/// data type unsigned int, data length 4 byte
typedef unsigned int                             MI_U32;        // 4 bytes
/// data type unsigned int, data length 8 byte
typedef unsigned long long                       MI_U64;        // 8 bytes
/// data type signed char, data length 1 byte
typedef signed char                              MI_S8;         // 1 byte
/// data type signed short, data length 2 byte
typedef signed short                             MI_S16;        // 2 bytes
/// data type signed int, data length 4 byte
typedef signed int                               MI_S32;        // 4 bytes
/// data type signed int, data length 8 byte
typedef signed long long                         MI_S64;        // 8 bytes
/// data type float, data length 4 byte
typedef float                                    MI_FLOAT;      // 4 bytes
/// data type 64bit physical address
typedef unsigned long long                       MI_PHY;        // 8 bytes
/// data type pointer content
typedef size_t                                   MI_VIRT;       // 4 bytes when 32bit toolchain, 8 bytes when 64bit toolchain.

/// data type null pointer
#ifdef NULL
#undef NULL
#endif
#define NULL                                     0


//-------------------------------------------------------------------------------------------------
//  Software Data Type
//-------------------------------------------------------------------------------------------------
/// definition for MI_BOOL
typedef unsigned char                            MI_BOOL;
typedef MI_S32                                   MI_HANDLE;

#ifndef true
/// definition for true
#define true                                     1
/// definition for false
#define false                                    0
#endif

#if !defined(TRUE) && !defined(FALSE)
/// definition for TRUE
#define TRUE                                     1
/// definition for FALSE
#define FALSE                                    0
#endif

//-------------------------------------------------------------------------------------------------
//  Defines
//-------------------------------------------------------------------------------------------------
#define MI_HANDLE_NULL                           (-1)
#define MI_INVALID_PTS                              ((MI_U64)-1)

typedef MI_HANDLE           MI_DISPLAY_HANDLE;
typedef MI_HANDLE           MI_WINDOW_HANDLE;
typedef MI_HANDLE           MI_DISPOUT_HANDLE;
typedef MI_HANDLE           MI_V3D_HANDLE;

///ASCII color code
#define ASCII_COLOR_RED                          "\033[1;31m"
#define ASCII_COLOR_WHITE                        "\033[1;37m"
#define ASCII_COLOR_YELLOW                       "\033[1;33m"
#define ASCII_COLOR_BLUE                         "\033[1;36m"
#define ASCII_COLOR_GREEN                        "\033[1;32m"
#define ASCII_COLOR_END                          "\033[0m"

#ifdef MI_ENABLE_DBG
// mdules who want to use DBG_INFO for debugging should define DBG_LEVEL by itself.
#define MI_PRINT(fmt, args...)      ({do{printf(fmt, ##args);}while(0);})
#define DBG_INFO(fmt, args...)      ({do{if(DBG_LEVEL>=MI_DBG_INFO){printf(ASCII_COLOR_GREEN);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_PPID_INFO(fmt, args...)	({do{if(DBG_LEVEL>=MI_DBG_INFO){printf(ASCII_COLOR_GREEN"[MI PPID INFO]: ");printf("[CallingPId :%d]",IPCThreadState::self()->getCallingPid());printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_WRN(fmt, args...)       ({do{if(DBG_LEVEL>=MI_DBG_WRN){printf(ASCII_COLOR_YELLOW);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_ERR(fmt, args...)       ({do{if(DBG_LEVEL>=MI_DBG_ERR){printf(ASCII_COLOR_RED"[MI ERR ]: %s[%d]: ", __FUNCTION__,__LINE__);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_ENTER()                 ({do{if(DBG_LEVEL>=MI_DBG_ALL){printf(ASCII_COLOR_BLUE">>>%s[%d] \n",__FUNCTION__,__LINE__);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_EXIT_OK()               ({do{if(DBG_LEVEL>=MI_DBG_ALL){printf(ASCII_COLOR_BLUE"<<<%s[%d] \n",__FUNCTION__,__LINE__);printf(ASCII_COLOR_END);}}while(0);})
#define DBG_EXIT_ERR(fmt, args...)  ({do{if(DBG_LEVEL>=MI_DBG_ERR){printf(ASCII_COLOR_RED"<<<%s[%d] ",__FUNCTION__,__LINE__);printf(fmt, ##args);printf(ASCII_COLOR_END);}}while(0);})
#else
#define MI_PRINT(fmt, args...)
#define DBG_INFO(fmt, args...)
#define DBG_PPID_INFO(fmt, args...)
#define DBG_WRN(fmt, args...)
#define DBG_ERR(fmt, args...)
#define DBG_ENTER()
#define DBG_EXIT_OK()
#define DBG_EXIT_ERR(fmt, args...)
#endif

#ifndef __BIONIC__
#define BACKTRACE(_size_) \
	do {	\
		int j = 0, nptrs = 0;	\
		void *buffer[_size_];	\
		char **strings;	\
		nptrs = backtrace(buffer, _size_);	\
		strings = backtrace_symbols(buffer, nptrs);	\
		for (j = 0; j < nptrs; j++)	\
		printf("[Backtrace] %s\n", strings[j]);	\
		free(strings);	\
		} while(0)
#else
#define BACKTRACE(_size_)
#endif

#ifndef ASSERT
#define ASSERT(_x_)                                                                         \
    do  {                                                                                   \
        if ( ! ( _x_ ) )                                                                    \
        {                                                                                   \
            printf("ASSERT FAIL: %s %s %d\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);     \
            abort();                                                                        \
        }                                                                                   \
    } while (0)
#endif

#define CHECK_TIME 30 //ms

#define FUNCTION_IN_TIME      struct  timeval in_time;gettimeofday(&in_time,NULL);

#define RETURN(ret) \
    do{\
        struct  timeval out_time;\
        gettimeofday(&out_time,NULL);\
        int timecost = (out_time.tv_sec - in_time.tv_sec)*1000 + (out_time.tv_usec -in_time.tv_usec)/1000;\
        printf("[Warning][Function] %s cost time %d ms!!!\n" , __FUNCTION__ ,timecost);\
        return ret;\
    }while(0)
//-------------------------------------------------------------------------------------------------
//  Structures
//-------------------------------------------------------------------------------------------------
typedef enum
{
    MI_OK = 0x0,                   ///< succeeded
    MI_CONTINUE = 0x1,                 ///< not error but hasn' be succeeded. Flow is continue...
    MI_HAS_INITED = 0x2,               ///< not error but init has be called again

    MI_ERR_FAILED = 0x3,               ///< general failed
    MI_ERR_NOT_INITED = 0x4,           ///< moudle hasn't be inited
    MI_ERR_NOT_SUPPORT = 0x5,          ///< not supported
    MI_ERR_NOT_IMPLEMENT = 0x6,        ///< not implemented
    MI_ERR_INVALID_HANDLE = 0x7,       ///< invalid handle
    MI_ERR_INVALID_PARAMETER = 0x8,    ///< invalid parameter
    MI_ERR_RESOURCES = 0x9,            ///< system resource issue
    MI_ERR_MEMORY_ALLOCATE = 0xa,      ///< memory allocation
    MI_ERR_CHAOS = 0xb,                ///< chaos state-mechine
    MI_ERR_DATA_ERROR = 0xc,           ///< data error
    MI_ERR_TIMEOUT = 0xd,              ///< timeout
    MI_ERR_LIMITION = 0xe,             ///< limitation
    MI_ERR_BUSY = 0xf,                    ///< the required operation can not be done due to current system is busy.

    MI_ERR_MAX,                  ///< maximum value of D_RESULT
}MI_RESULT;

typedef enum
{
    MI_DBG_NONE = 0,
    MI_DBG_ERR,
    MI_DBG_WRN,
    MI_DBG_INFO,
    MI_DBG_ALL
}MI_DBG_LEVEL_e;

typedef enum
{
    MI_DBG_CMD_SET_LEVEL = 0,
    MI_DBG_CMD_DUMP_INFO,
    MI_DBG_CMD_BAD_PARA = 0xbad,
}MI_DBG_CMD_e;

#define INIT_ST(st) do { \
    memset(&st, 0, sizeof(st));\
    st.u16SizeofStructure = sizeof(st);\
}while(0)


typedef enum
{
    MI_ENTERSTRMODE_NONE = 0x0,
    MI_ENTERSTRMODE_SUSPENDSTAGE0,
    MI_ENTERSTRMODE_SUSPENDSTAGE1,
    MI_ENTERSTRMODE_SUSPENDSTAGE2,
    MI_ENTERSTRMODE_RESUMESTAGE1,
    MI_ENTERSTRMODE_RESUMESTAGE2,
    MI_ENTERSTRMODE_RESUMESTAGE3,
}MI_ENTERSTRMODE_TYPE;

typedef void (*MI_EnterStrModeCallback)(MI_U32 nEvt, MI_U32 wParam, MI_U32 lParam);


#endif///_MI_COMMON_H_
