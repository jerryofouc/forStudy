#include"apue.h"
#include<dirent.h>
#include<limits.h>
typedef int Myfunc(const char*, const struct stat*,int );
static Myfunc myfunc;
static int myftw(char*,Myfunc *);
static int dopath(Myfunc *);
static long nreg,ndir,nblk,nchr,nfifo,nslink,nsock,ntot;
int main(int argc,char* argv[]){
	int ret;
	if(argc != 2){
		err_quit("usage: ftw <starting-pathname>");
	}
	ret = myftw(argv[1],myfunc);
	ntot = nreg + ndir + nblk + nchr + nfifo+ nslink + nsock;
	if(ntot==0){
		ntot = l
	}
	
	printf("regular files %7ld, %5.2f %%\n",nreg,nreg*100/ntot);
	printf("regular files %7ld, %5.2f %%\n",nreg,nreg*100/ntot);


}
