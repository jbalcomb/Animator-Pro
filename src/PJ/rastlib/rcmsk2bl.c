#include "rastcall.ih"

void pj_mask2blit(UBYTE *mbytes, Coor mbpr, Coor mx, Coor my,
			   Raster *r, Coor rx, Coor ry, Ucoor width, Ucoor height,
			   Pixel oncolor, Pixel offcolor )

/* sets rectangle of raster rectangle of mask 
	(mask on = oncolor, off = noaction ) */
{
	if ((Coor)(width = pj_lclipdim2(&mx,&rx,width,r->width)) <= 0)
		return;
	if ((Coor)(height = pj_lclipdim2(&my,&ry,height,r->height)) <= 0)
		return;
	MASK2BLIT(mbytes,mbpr,mx,my,r,rx,ry,width,height,oncolor,offcolor);
}
