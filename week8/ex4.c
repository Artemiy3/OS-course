#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() 
{
	char * x;
	for(int i = 1; i <= 10; i++) {
		if (x == NULL){
      return 1;
    }
		memset(calloc(2024*1024*1024UL, 1), 0, 2024*1024*1024UL);
    struct rusage u;
		getrusage(RUSAGE_SELF, &u);
		printf("------- (%d/\%d) Allocated %d MB\n", i, 10,  2024*1024*1024UL/(1024*1024));
    printf(">>>>>>> system time used: %d\n>>>>>>> maximum resident set size: %d\n>>>>>>> integral shared memory size: %d\n>>>>>>> integral unshared data size: %d\n>>>>>>> integral unshared stack size: %d\n>>>>>>> integral unshared stack size:%d\n", u.ru_stime, u.ru_maxrss, u.ru_ixrss, u.ru_idrss, u.ru_isrss);
		usleep(1*1000000);
	}
	printf("------- Done\n");
	return 0;
}
