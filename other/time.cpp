#include <stdio.h>
#include <sys/time.h>


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
	srand(time(NULL));
	struct timeval    curr_timeval;
    gettimeofday(&curr_timeval, 
                     NULL);

	return 0;
}