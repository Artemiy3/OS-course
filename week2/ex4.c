#include <stdio.h>
#include <malloc.h>

int main(){
    char *sa = malloc(sizeof(char) * 11);
    char *sb = malloc(sizeof(char) * 11);
    fgets(sa, 10, stdin);
    fgets(sb, 10, stdin);
    int *a = malloc(sizeof(int)), *b = malloc(sizeof(int));
    sscanf(sa, "%d", a);
    sscanf(sb, "%d", b);
    int *t;
    t = a;
    a = b;
    b = t;
    printf("%d %d", *a, *b);
    return 0;
}
