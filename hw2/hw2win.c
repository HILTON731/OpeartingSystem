#include <windows.h>
#include <stdio.h>
DWORD WINAPI T_prime(LPVOID Param){
    DWORD thread_num = *(DWORD *)Param;

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
    return 0;
}
int main(int argc, char *argv[]){
    DWORD ThreadId;
    HANDLE ThreadHandle;
    int Param;

    if(argc != 2){
        fprintf(stderr, "An integer parameter is required\n");
        return -1;
    }
    ;
    if((Param = atoi(argv[1])) < 0){
        fprintf(stderr, "Error: Can't implement negative\n");
        return -1;
    }

    if((ThreadHandle = CreateThread(NULL, 0, T_prime, &Param, 0, &ThreadId)) != NULL){
        WaitForSingleObject(ThreadHandle, INFINITE);

        CloseHandle(ThreadHandle);
    }
}