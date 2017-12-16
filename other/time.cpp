#include <stdio.h>
#include <sys/time.h>


// struct timeval {
//    time_t      tv_sec;     /* seconds */
//    suseconds_t tv_usec;    /* microseconds */
// };
// long type variable

int main(void){
	// srand(time(NULL));
	struct timeval    curr_timeval;
    gettimeofday(&curr_timeval, 
                     NULL);

    printf("%ld\n", curr_timeval.tv_sec);
    printf("%ld\n", curr_timeval.tv_usec);


	return 0;
}