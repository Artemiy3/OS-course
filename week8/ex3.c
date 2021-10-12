#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//I found that ex2 takes much of power of CPU and memory. Also virtual memory grows at the duration of the process

int main() 
{
	char * x;
	for(int i = 1; i <= 10; i++) {
		if (x == NULL){
      return 1;
    }
		memset(calloc(2024*1024*1024UL, 1), 0, 2024*1024*1024UL);
		printf("------- (%d/\%d) Allocated %d MB\n", i, 10,  2024*1024*1024UL/(1024*1024));
		usleep(1*1000000);
	}
	printf("------- Done\n");
	return 0;
}
