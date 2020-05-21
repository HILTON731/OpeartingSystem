#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

err_sys(char *p){ perror(p); exit(-1);}
int fib(int n);
int main(int argc, char*argv[]){
	pid_t pid;
	printf("argc = %d\n",argc);
	printf("argv = %s\n",argv[1]);
	if(argc<2)
		err_sys("No parameter");
	else if(argc==2){
		int num=atoi(argv[1]);
		printf("num = %d\n",num);
		if((pid = fork())<0) err_sys("fork");
		else if(pid == 0){
			int i;
			printf("pid = %d\n",getpid());
			for(i=0;i<num;i++)
				printf("%d ",fib(i));
			printf("\n");
		}
		else{
			wait();
			return 0;
		}
	}
}

int fib(int n){
	if(n==0)return 0;
	else if(n==1)return 1;
	else{
		return fib(n-1) + fib(n-2);
	}
}

