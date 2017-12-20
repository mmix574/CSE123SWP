#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// struct timeval {
//    time_t      tv_sec;     /* seconds */
//    suseconds_t tv_usec;    /* microseconds */
// };
// long type variable


// struct timespec
//   {
//     __time_t tv_sec;		 Seconds.  
//     __syscall_slong_t tv_nsec;	/* Nanoseconds.  */
//   };


//Compute the difference in usec for two timeval objects
long timeval_usecdiff(struct timeval *start_time, 
                      struct timeval *finish_time)
{
  long usec;
  usec=(finish_time->tv_sec - start_time->tv_sec)*1000000;
  usec+=(finish_time->tv_usec- start_time->tv_usec);
  return usec;
}



int main(void){

	// srand(time(NULL));


	struct timeval    timeval_start;
	struct timeval    timeval_end;

    gettimeofday(&timeval_start, 
                     NULL);

	// sleep(1);
	usleep(1000000);

    gettimeofday(&timeval_end, 
                     NULL);

    printf("%ld\n",timeval_usecdiff(&timeval_start,&timeval_end));

	return 0;
}