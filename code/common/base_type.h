#ifndef __BASE_TYPEDEF_H
#define __BASE_TYPEDEF_H

#include "stm32f4xx.h"

#define _SUCCESS	1
#define _FAIL		0

#undef _TRUE
#define _TRUE		1

#undef _FALSE
#define _FALSE		0

#undef TRUE
#define TRUE		1

#undef FALSE
#define FALSE		0

#undef NULL
#define NULL		0

typedef  unsigned char      	bool;     	/* Boolean value type. */

typedef  unsigned long			uint32;      	/* Unsigned 32 bit value */
typedef  unsigned short     	uint16;      	/* Unsigned 16 bit value */
typedef  unsigned char      	uint8;       	/* Unsigned 8  bit value */

typedef  signed long    		int32;       	/* Signed 32 bit value */
typedef  signed short       	int16;       	/* Signed 16 bit value */
typedef  signed char        	int8;     		/* Signed 8  bit value */

//typedef  uint32_t  				u32;
//typedef  uint16_t  				u16;
//typedef  uint8_t   				u8;

typedef  unsigned long long	 	uint64;
typedef  signed long long	 	int64;

typedef  unsigned long 			SIZE_T;
typedef  signed long 			SSIZE_T;

#if defined ( __ICCARM__ )
#define __inline__                      inline
#define __inline                        inline
#define __inline_definition			//In dialect C99, inline means that a function's definition is provided 
								//only for inlining, and that there is another definition 
								//(without inline) somewhere else in the program. 
								//That means that this program is incomplete, because if 
								//add isn't inlined (for example, when compiling without optimization), 
								//then main will have an unresolved reference to that other definition.

								// Do not inline function is the function body is defined .c file and this 
								// function will be called somewhere else, otherwise there is compile error
#elif defined ( __CC_ARM   )
#define __inline__			__inline	//__linine__ is not supported in keil compilor, use __inline instead
#define inline				__inline
#define __inline_definition			// for dialect C99
#elif defined   (  __GNUC__  )
#define __inline__                      inline
#define __inline                        inline
#define __inline_definition	inline
#endif

#ifdef __func__
#define __WLAN_FUNC__	__func__
#elif defined __FUNC__
#define __WLAN_FUNC__ 	__FUNC__
#elif defined __function__
#define __WLAN_FUNC__ 	__function__
#elif defined __FUNCTION__
#define __WLAN_FUNC__ 	__FUNCTION__
#else
#define __STRING_FMT(x) #x
#define STRING_FMT(x) __STRING_FMT(x)
#define __FUNCTION__ "[Function@" __FILE__ " (" STRING_FMT(__LINE__) ")]"
#define __WLAN_FUNC__ 	__FUNCTION__
#endif

#ifndef BIT
#define BIT(x)		((uint32)0x00000001 << (x))
#endif

#ifndef BIT0
#define BIT0		0x00000001
#define BIT1		0x00000002
#define BIT2		0x00000004
#define BIT3		0x00000008
#define BIT4		0x00000010
#define BIT5		0x00000020
#define BIT6		0x00000040
#define BIT7		0x00000080
#define BIT8		0x00000100
#define BIT9		0x00000200
#define BIT10	0x00000400
#define BIT11	0x00000800
#define BIT12	0x00001000
#define BIT13	0x00002000
#define BIT14	0x00004000
#define BIT15	0x00008000
#define BIT16	0x00010000
#define BIT17	0x00020000
#define BIT18	0x00040000
#define BIT19	0x00080000
#define BIT20	0x00100000
#define BIT21	0x00200000
#define BIT22	0x00400000
#define BIT23	0x00800000
#define BIT24	0x01000000
#define BIT25	0x02000000
#define BIT26	0x04000000
#define BIT27	0x08000000
#define BIT28	0x10000000
#define BIT29	0x20000000
#define BIT30	0x40000000
#define BIT31	0x80000000
#endif

#define		bMaskByte0              0xff	
#define		bMaskByte1              0xff00
#define		bMaskByte2              0xff0000
#define		bMaskByte3              0xff000000
#define		bMaskHWord              0xffff0000
#define		bMaskLWord              0x0000ffff
#define		bMaskDWord              0xffffffff
#define		bMaskH4Bits             0xf0000000	
#define     bMaskOFDM_D             0xffc00000
#define		bMaskCCK                0x3f3f3f3f
#define		bMask12Bits             0xfff	
#define     bRFRegOffsetMask	    0xfffff



#define FIELD_OFFSET(s,field)	((SSIZE_T)&((s*)(0))->field)
#define SIZE_PTR SIZE_T

typedef enum _WLAN_STATUS{
	WLAN_STATUS_FAILURE,
	WLAN_STATUS_SUCCESS
}WLAN_STATUS,*PWLAN_STATUS;



#endif