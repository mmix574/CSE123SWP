#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <math.h>
#include <sys/time.h>

#define MAX_COMMAND_LENGTH 16
#define AUTOMATED_FILENAME 512
typedef unsigned char uchar_t;

//System configuration information
struct SysConfig_t
{
    float drop_prob;
    float corrupt_prob;
    unsigned char automated;
    char automated_file[AUTOMATED_FILENAME];
};
typedef struct SysConfig_t  SysConfig;

//Command line input information
struct Cmd_t
{
    uint16_t src_id;
    uint16_t dst_id;
    char * message;
};
typedef struct Cmd_t Cmd;

//Linked list information
enum LLtype 
{
    llt_string,
    llt_frame,
    llt_integer,
    llt_head
} LLtype;

struct LLnode_t
{
    struct LLnode_t * prev;
    struct LLnode_t * next;
    enum LLtype type;

    void * value;
};
typedef struct LLnode_t LLnode;


//Receiver and sender data structures
struct Receiver_t
{
    //DO NOT CHANGE:
    // 1) buffer_mutex
    // 2) buffer_cv
    // 3) input_framelist_head
    // 4) recv_id
    pthread_mutex_t buffer_mutex;
    pthread_cond_t buffer_cv;
    LLnode * input_framelist_head;

    char seq_num;

    int recv_id;
};



enum SendFrame_DstType 
{
    ReceiverDst,
    SenderDst
} SendFrame_DstType ;

typedef struct Sender_t Sender;
typedef struct Receiver_t Receiver;


#define MAX_FRAME_SIZE 64



//TODO: You should change this!
//Remember, your frame can be AT MOST 64 bytes!
// #define FRAME_PAYLOAD_SIZE 64

//修改成这里
#define FRAME_HEADER_SIZE 15
#define FRAME_PAYLOAD_SIZE 48
#define FRAME_CRC_SIZE 1

struct Frame_t
{
    char header[FRAME_HEADER_SIZE];
    char data[FRAME_PAYLOAD_SIZE];
    char crc[FRAME_CRC_SIZE];
};
typedef struct Frame_t Frame;



#define SWS 8

struct sendQ_slot {
    struct timeval  endtime;
    struct timeval startime;
    Frame *frame;
};


struct Sender_t
{
    //DO NOT CHANGE:
    // 1) buffer_mutex
    // 2) buffer_cv
    // 3) input_cmdlist_head
    // 4) input_framelist_head
    // 5) send_id
    pthread_mutex_t buffer_mutex;
    pthread_cond_t buffer_cv;
    LLnode * input_cmdlist_head;
    LLnode * input_framelist_head;
    int send_id;

    //NFE - Next frame expected
	//LFR - Sequence number of largest consecutive frame received
	//LAF - Sequence number of largest acceptable frame
    //RWS - Max receive window size


    //LFR = NFE - 1
    //LAF = NFE + RWS - 1

    unsigned char RWS;

    unsigned char LAR;//head
    unsigned char LAF;//tail


    unsigned char seq_num;

    struct sendQ_slot sendQ[SWS];

};



//Declare global variables here
//DO NOT CHANGE: 
//   1) glb_senders_array
//   2) glb_receivers_array
//   3) glb_senders_array_length
//   4) glb_receivers_array_length
//   5) glb_sysconfig
//   6) CORRUPTION_BITS
Sender * glb_senders_array;
Receiver * glb_receivers_array;
int glb_senders_array_length;
int glb_receivers_array_length;
SysConfig glb_sysconfig;
int CORRUPTION_BITS;
#endif 
