#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    char str[100];
    while(true){
        scanf(str);
        system(str);
    }
    return 0;
}
