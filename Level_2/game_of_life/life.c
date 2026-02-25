#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 4) return 1;
	int w=atoi(av[1]),h=atoi(av[2]),it=atoi(av[3]),x=0,y=0,p=0,n,di,dj;
	if (w<=0||h<=0||it<0) return 1;
	int b[h][w],nx[h][w]; char c;
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) b[i][j]=0;
	while(read(0,&c,1)==1)
	{
		if     (c=='w'&&y>0)   y--;
		else if(c=='s'&&y<h-1) y++;
		else if(c=='a'&&x>0)   x--;
		else if(c=='d'&&x<w-1) x++;
		else if(c=='x')        p=!p;
		if(p) b[y][x]=1;
	}
	while(it--)
	{
		for(int i=0;i<h;i++) for(int j=0;j<w;j++)
		{
			for(n=0,di=-1;di<2;di++) for(dj=-1;dj<2;dj++)
				n+=(di||dj)&&i+di>=0&&i+di<h&&j+dj>=0&&j+dj<w?b[i+di][j+dj]:0;
			nx[i][j]=(b[i][j]&&(n==2||n==3))||(!b[i][j]&&n==3);
		}
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) b[i][j]=nx[i][j];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)putchar(b[i][j]?'0':' ');putchar('\n');
	}
}
a
/*
 * VARIABILI:
 * w  = larghezza (width) della griglia
 * h  = altezza (height) della griglia
 * it = numero di iterazioni del Game of Life
 * x  = posizione X della penna (colonna)
 * y  = posizione Y della penna (riga)
 * p  = stato della penna (0 = alzata, 1 = abbassata/disegna)
 * c  = comando corrente letto dallo stdin (w/a/s/d/x)
 * b  = griglia/board corrente (0 = cella morta, 1 = cella viva)
 * nx = griglia della prossima generazione (next board)
 * n  = numero di vicini vivi per una cella
 * di = delta i, offset verticale (-1, 0, 1) per controllare i vicini
 * dj = delta j, offset orizzontale (-1, 0, 1) per controllare i vicini
 * i, j = indici per scorrere la griglia (i=riga, j=colonna)
 */
