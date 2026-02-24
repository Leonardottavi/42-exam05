#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int W,H,*B,*T;

int	n(int x,int y) {
	int c=0,dx,dy,nx,ny;
	for(dy=-1;dy<2;dy++) for(dx=-1;dx<2;dx++)
		if((dx||dy)&&(nx=x+dx)>=0&&nx<W&&(ny=y+dy)>=0&&ny<H) c+=B[ny*W+nx];
	return c;
}

int	main(int ac,char**av) {
	if(ac!=4) return 1;
	W=atoi(av[1]); H=atoi(av[2]); int it=atoi(av[3]),px=0,py=0,p=0,k,*s; char c;
	if(W<=0||H<=0||it<0) return 1;
	B=calloc(W*H,4); T=calloc(W*H,4);
	while(read(0,&c,1)==1) {
		if     (c=='x'){p=!p;if(p)B[py*W+px]=1;}
		else if(c=='w'){if(py>0)py--;if(p)B[py*W+px]=1;}
		else if(c=='s'){if(py<H-1)py++;if(p)B[py*W+px]=1;}
		else if(c=='a'){if(px>0)px--;if(p)B[py*W+px]=1;}
		else if(c=='d'){if(px<W-1)px++;if(p)B[py*W+px]=1;}
	}
	while(it--) {
		for(int y=0;y<H;y++) for(int x=0;x<W;x++)
			{k=n(x,y);T[y*W+x]=B[y*W+x]?k==2||k==3:k==3;}
		s=B;B=T;T=s;
	}
	for(int y=0;y<H;y++){for(int x=0;x<W;x++)putchar(B[y*W+x]?'0':' ');putchar('\n');}
}