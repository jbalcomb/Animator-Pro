
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>

#define TRUE    1
#define FALSE   0
typedef char Boolean;

	/* Watcom at least is lacking this... */
#ifndef M_PI
#define M_PI        3.14159265358979323846
#endif

#define EOS     '\0'

typedef double point[2];

#define X   0
#define Y   1

/*  Charstring commands.  */

enum cscommand {
	Unused_0,
	Hstem,
	Unused_2,
	Vstem,
	Vmoveto,
	Rlineto,
	Hlineto,
	Vlineto,
	Rrcurveto,
	Closepath,
    Callsubr,
    Return,
    Escape,
    Hsbw,
    Endchar,
    Unused_15,
    Unused_16,
    Unused_17,
    Unused_18,
    Unused_19,
    Unused_20,
    Rmoveto,
    Hmoveto,
    Unused_23,
    Unused_24,
    Unused_25,
    Unused_26,
    Unused_27,
    Unused_28,
    Unused_29,
    Vhcurveto,
    Hvcurveto,

    /* 12 x commands */

    Dotsection,
    Vstem3,
    Hstem3,
    Unused_12_3,
    Unused_12_4,
    Unused_12_5,
    Seac,
    Sbw,
    Unused_12_8,
    Unused_12_9,
    Unused_12_10,
    Unused_12_11,
    Div,
    Unused_12_13,
    Unused_12_14,
    Unused_12_15,
    Callothersubr,
    Pop,
    Unused_12_18,
    Unused_12_19,
    Unused_12_20,
    Unused_12_21,
    Unused_12_22,
    Unused_12_23,
    Unused_12_24,
    Unused_12_25,
    Unused_12_26,
    Unused_12_27,
    Unused_12_28,
    Unused_12_29,
    Unused_12_30,
    Unused_12_31,
    Unused_12_32,
    Setcurrentpoint
};

/*  Sections of the font file.  */

typedef enum { Header, FontInfo, OtherSubrs, Subrs, CharStrings } file_section;
extern file_section section;

#define ELEMENTS(array) (sizeof(array)/sizeof((array)[0]))

#ifndef abs
#define abs(x)   ((x) < 0    ? -(x) : (x))
#endif
#ifndef max
#define max(a,b) ((a) >  (b) ?  (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a) <= (b) ?  (a) : (b))
#endif

#define NCdefs  300                   /* Number of Charstring definitions */

extern void *alloc();                 /* Memory allocator */
extern void ucase();                  /* String to upper case */
extern char *strsave();               /* Duplicate string */
extern int ncdefs;                    /* Number of character definitions */
extern unsigned char *chardefs[NCdefs][2]; /* Character definitions */
extern int chardl[NCdefs];            /* Character definition lengths */
extern int nsubrs;                    /* Number of subroutines */
extern unsigned char **subrs;         /* Subroutine definitions */
extern int *subrl;                    /* Subroutine lengths */
extern void exchars();                /* Execute character string */
extern char *csnames[];               /* Charstring operator names */
extern int ncsnames;                  /* Number of Charstring operator names */
extern char fullname[];               /* Font name */
extern int bnum;                      /* Line segments per Bezier curve */
extern int shapedoc;                  /* PostScript comments in shape file ? */
extern double skewsin;                /* Sine of -ItalicAngle */
extern int noflex;                    /* Disable Flex if true */
extern char **charmap;                /* Character mapping vector */
extern char *usermap[];               /* User-defined mapping vector */
