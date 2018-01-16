#ifndef _MI_OSD_H_
#define _MI_OSD_H_

#ifdef __cplusplus
extern "C" {
#endif


#define SWAP(ValueA,ValueB) \
	{\
		MI_U32 u32Tmp = ValueA;\
		ValueA = ValueB; \
        ValueB = u32Tmp;  \
    } \



#define GETMAX(MAX,b,c,d) \
    {   \
        if( MAX < b)  SWAP(MAX,b);  \
        if( MAX < c)  SWAP(MAX,c);  \
        if( MAX < d)  SWAP(MAX,d);  \
    }   \

#define GETMIN(MIN,b,c,d) \
	{	\
		if( MIN > b)  SWAP(MIN,b);	\
		if( MIN > c)  SWAP(MIN,c);	\
		if( MIN > d)  SWAP(MIN,d);	\
	}	\


#define MEM_ALIGN( unit, val )  (1 + (((val) - 1) | (unit - 1))) 

#define ALIGN_DOWNTO_16(_val_) (((_val_) >> 4) << 4)



#ifdef __cplusplus
}
#endif

#endif
