#ifndef STDTYPES_H
#define STDTYPES_H

#include "compiler.h" /* compiler dependent pragmas etc */

#ifndef REXLIB_CODE
#include "release.h"  /* specific defines for program versions and releases */
#endif

#ifndef PUBLIC_CODE
	#define PRIVATE_CODE
#endif

/* for debugging */
#ifdef PRIVATE_CODE

#ifdef TESTING
	#define TCOOKIE verify_cookies(boxf,__FILE__,__LINE__);
	#define PCOOKIE verify_cookies(printf,__FILE__,__LINE__);
	extern int debug;
	#define dboxf if(debug)boxf
	#define TBOX boxf("%s %d", __FILE__,__LINE__ );
	#define DBOX {if(debug)TBOX}
#else
	#define TCOOKIE
	#define PCOOKIE
	#define debug 0
	#define dboxf
	#define TBOX
	#define DBOX
#endif /* TESTING */

#endif /* PRIVATE_CODE */

#ifdef TESTING
	#define PBOX printf("%s %d\n", __FILE__,__LINE__ );
	#define DPBOX {if(debug)PBOX}
#else
	#define PBOX
	#define DPBOX
#endif /* TESTING */

#include <stddef.h> /* system standard definitions */

#ifndef REXLIB_CODE /***************/

#ifndef INT_MAX
	#include <limits.h> /* compiler dependent data type sizes */
#endif

#if (LONG_MAX == INT_MAX && ULONG_MAX == UINT_MAX)
	#define INT_IS_LONG 1
#else
	#define INT_IS_LONG 0
#endif

#if (SHRT_MAX == INT_MAX && USHRT_MAX == UINT_MAX)
	#define INT_IS_SHORT 1
#else
	#define INT_IS_SHORT 0
#endif

#endif /* REXLIB_CODE */


/* make sure NULL is defined even if we don't want <stdio.h> */

#ifndef NULL
	#define NULL ((void *)0)
#endif

#ifndef NOFUNC
	#define NOFUNC NULL
#endif


typedef int Errcode;	/* >= 0 if ok, < 0 otherwise see errcodes.h */
typedef Errcode ErrCode; /* Just a synonym for above. */
#define Success (0)
#define Failure -1
typedef int Boolean;
#define TRUE 1
#define FALSE 0

/* BYTE, UBYTE, etc is to keep code portable between different compilers
   where especially 'int' can mean different things. */

typedef signed char 	BYTE;
typedef unsigned char	UBYTE;
typedef signed short	SHORT;
typedef unsigned short	USHORT;
typedef signed long 	LONG;
typedef unsigned long	ULONG;
typedef double			FLOAT;

typedef UBYTE		   *PTR;

/* Function pointer declarations are a little hard to type in C, so have
   the following short-cut typedefs. */

typedef int    (*FUNC)();	/* pointer to function returning int */
typedef void  (*VFUNC)();	/* pointer to function returning void */
typedef SHORT (*SFUNC)();	/* pointer to function returning SHORT */
typedef LONG  (*LFUNC)();	/* pointer to function returning LONG */
typedef Errcode (*EFUNC)(); /* pointer to function returning Errcode */

/* For now out graphics run with byte-a-pixel cards.  This typedef is
   used to make code that's concerned with pixels stand out from code
   that's concerned with characters or other bytes. */

typedef UBYTE Pixel; /* type used in pixel buffers by get_hseg etc */

/* these are sometimes handy, put your own here if you like */

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Absval(x) ((x)<0?(-(x)):(x))



#endif /* STDTYPES_H -- leave at end of file */
