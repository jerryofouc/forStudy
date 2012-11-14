#include"include/apue.h"

void pr_stdio(const char*,FILE *);

int main(void){
	FILE *fp;
	fputs("enter any character\n",stdout);
	if(getchar()==EOF){
		err_sys("getchar error");
	}
	pr_stdio("stdio",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderror",stderr);

	if((fp=fopen("/etc/motd","r")) == NULL){
		err_sys("fopen error");	
	}
	if(getc(fp) == EOF){
		err_sys("getc error");
	}
	pr_stdio("/etc/motd",fp);
}

void pr_stdio(const char *name,FILE *fp){
	printf("stream = %s ",name);
	
	if(fp->_IO_file_flags & _IO_UNBUFFERED){
		printf("unbuffered\n");
	}else if(fp->_IO_file_flags&_IO_LINE_BUF){
		printf("line buffered\n");
	}else{
		printf("full buffered\n");
	}
	printf(", buffer size = %d\n",fp->_IO_buf_end - fp->_IO_buf_base);
}
