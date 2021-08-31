#include <stdio.h>
#include <malloc.h>

int main(){
    char *s = malloc(sizeof(char) * 1000);
    fgets(s, 10, stdin);
    int n;
    sscanf(s, "%d", &n);
    for(int i = 1; i < n * 2 - 1; i += 2){
        for(int j = 0; j < (n * 2 - 1 - i) / 2; j++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
