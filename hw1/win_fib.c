#include<stdio.h>
#include<windows.h>

int main(int argc, char*argv[]){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    int num=atoi(argv[1]);
    char command[32]="fib.exe ";
    strcat(command,argv[1]);
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    printf("%s\n",command);

    if(!CreateProcess(NULL,command,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
    {
        fprintf(stderr, "Create Process Failed");
        return -1;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}