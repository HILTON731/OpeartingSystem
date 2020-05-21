#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void err_sys(char *p){ perror(p); exit(-1);}
int fib(int n){
	if(n==0)return 0;
	else if(n==1)return 1;
	else{
		return fib(n-1) + fib(n-2);
	}
}
int main(int argc, char*argv[]){
	if(argc==2){
		int num=atoi(argv[1]);
		printf("num = %d\n",num);
		int i;
        for(i=0;i<num;i++)
            printf("%d ",fib(i));
        printf("\n");
		}
    else{
        err_sys("uncorrect parameter");
    }
    
}