#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>

void *t_prime(void *data){
    int thread_num = atoi(data);
    if(thread_num < 0){
		fprintf(stderr, "Error: Can't implement negative\n");
		exit(0);
	}
    int i = 1;
    int j;
	int check = 0,count = 0;
    for(i;i <= thread_num;i++){
		check = 0;
        for(j = i;j>0;j--){
            if(i % j == 0){
				check++;
			}
		}
		if(check == 2){
            printf("%d ", i);
            count++;
        }
    }
    if(count == 0)
        printf("No value of %d",thread_num);
	printf("\n");
	pthread_exit(NULL);
}
int main(int argc, char *argv[]){
    pthread_t p_thread;

    if(argc != 2){
        fprintf(stderr, "An integer parameter is required\n");
        return -1;
    }
    
    if(pthread_create(&p_thread, NULL, t_prime,(void *)argv[1]) < 0){
        perror("thread create error : ");
        exit(0);
    }

    pthread_join(p_thread,NULL);

    return 0;
}
