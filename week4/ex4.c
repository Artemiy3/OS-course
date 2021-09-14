#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int main(void) {
    char str[100], *par[100];
    while(true) {
        fgets(str, 100, stdin);
        int i = 0;
        par[i] = strtok(str, " ");
        while (par[i] != NULL) {
            i++;
            par[i] = strtok(NULL, " ");
        }
        int pid = getpid();
        int another_pid = fork();
        if (another_pid != pid)
            execvp(par[0], par);
    }
}
