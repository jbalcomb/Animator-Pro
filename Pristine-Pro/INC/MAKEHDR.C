/* include file used only for code generating .c files to open output file
 */

#include <stdio.h>
#include <stdarg.h>
#include "ptrmacro.h"

FILE *ofile;

outf(char *fmt,...)
{
va_list args;

	va_start(args,fmt);
	vfprintf(ofile,fmt,args);
	va_end(args);
}

#define openit(argc,argv) open_outfile(argc,argv,__FILE__)

open_outfile(int argc, char **argv,char *file)
{
char *outname = "no file name";

	if(argc > 1)
		outname = argv[1];
	if(NULL == (ofile = fopen(outname, "w")))
	{
		printf("can't open \"%s\" for output.\n", outname);
		exit(1);
	}
	outf("; generated by %s \n\n\n",file);
}


#define closeit()\
	outf("\n; end %s generated code\n",__FILE__);fclose(ofile)

char _fmtequ[] = "%s equ +0%xh\n";

#define name_equ(name) outf(_fmtequ,#name,name)
#define soset(struc,name,f) outf(_fmtequ,#name,OFFSET(struc,f))

#define sfoset(fmt,struc,name,f) outf(fmt,#name,OFFSET(struc,f))


