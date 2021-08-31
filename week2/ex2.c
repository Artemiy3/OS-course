#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void) {
    char *s = malloc(sizeof(char) * 1000);
    scanf("%s", s);
    char *s_rev = malloc(sizeof(char) * 1000);
    for(int i = 0; i < strlen(s); i++){
        s_rev[i] = s[strlen(s) - i - 1];
    }
    printf("%s", s_rev);
    return 0;
}
