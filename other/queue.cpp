#include <stdio.h>

//NFE - Next frame expected


//LFR - Sequence number of largest consecutive frame received
//LAF - Sequence number of largest acceptable frame
//
//
//RWS - Max receive window size


//LFR = NFE - 1
//LAF = NFE + RWS - 1

/* code */

struct sender_status{
    int NFE;
    int LFR;
    int LAF;
    int RWS;
};
#define MAX 3



int main(int argc, char const *argv[])
{
    int A[MAX];

    int front = 0;
    int rear = 0;

    if((rear+1)%MAX!=0){
        A[rear] = 1;
        rear+=1;
    }

    if((rear+1)%MAX!=0){
        A[rear] = 1;
        rear+=1;
    }

    if((rear+1)%MAX!=0){
        A[rear] = 1;
        rear+=1;
    }

    if(front!=rear){
        int c = A[front];
        printf("%d\n",c);
        front+=1;
    }
    if(front!=rear){
        int c = A[front];
        printf("%d\n",c);
        front+=1;
    }
    if(front!=rear){
        int c = A[front];
        printf("%d\n",c);
        front+=1;
    }

	printf("%s\n", "hello world");
	return 0;
}