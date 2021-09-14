#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int pid = fork();
    if(pid == 0){
        printf("Hello from parent %d", pid - n);
    }else{
        printf("Hello from child %d", pid - n);
    }
    return 0;
}
