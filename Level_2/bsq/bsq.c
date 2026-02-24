#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	e(char **m, int n) { while (n-->0) free(m[n]); free(m); return fprintf(stderr,"map error\n"),0; }

int	s(FILE *f) {
	int n,w=-1,i,j,B=0,bi=0,bj=0,a,b,c; char E,O,F,buf[4096]; char**m; int**d;
	if (!fgets(buf,sizeof buf,f)||sscanf(buf,"%d %c %c %c",&n,&E,&O,&F)!=4||n<=0||E==O||E==F||O==F) return e(NULL,0);
	m=calloc(n,sizeof*m); d=calloc(n,sizeof*d);
	for (i=0;i<n;i++) {
		if (!fgets(buf,sizeof buf,f)) return e(m,i);
		int l=strlen(buf);
		if (l&&buf[l-1]=='\n') buf[--l]=0;
		if (w<0) w=l;
		if (!l||l!=w) return e(m,i);
		for (j=0;j<l;j++) if (buf[j]!=E&&buf[j]!=O) return e(m,i);
		m[i]=strdup(buf); d[i]=calloc(w,sizeof**d);
	}
	for (i=0;i<n;i++) { for (j=0;j<w;j++) {
		if (m[i][j]==O){d[i][j]=0;continue;}
		d[i][j]=(!i||!j)?1:(a=d[i-1][j],b=d[i][j-1],c=d[i-1][j-1],(a<b?(a<c?a:c):(b<c?b:c))+1);
		if (d[i][j]>B){B=d[i][j];bi=i-B+1;bj=j-B+1;}
	} }
	for (i=0;i<n;i++) free(d[i]);
	free(d);
	for (i=bi;i<bi+B;i++) for (j=bj;j<bj+B;j++) m[i][j]=F;
	for (i=0;i<n;i++){puts(m[i]);free(m[i]);} return free(m),1;
}

int	main(int ac, char**av) {
	int p=0; FILE *f;
	if (ac==1) return s(stdin),0;
	for (int i=1;i<ac;i++) {
		if (!(f=fopen(av[i],"r"))) { fprintf(stderr,"map error\n"); continue; }
		if (p) puts("");
		p=s(f); fclose(f);
	}
}