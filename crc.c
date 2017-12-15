//
// Created by mmix on 12/14/17.
//

#include "crc.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char get_bit (char byte, int pos); // return a char with a value of 0 or 1 depending on whether // the bit in the pos is 0 or 1
char crc8 (char* array, int byte_len); // or crc16, crc32 etc.
void append_crc (char* array, int array_len); // append crc remainder to the char array
int is_corrupted (char* array, int array_len); // return 1 if a frame is corrupted, otherwise
void print_char(char A);


char get_bit(char byte, int pos){
    return (byte >> pos) & 1;
}

void print_char(char A){
    for(int i =7 ;i>=0;i--){
        if ((A>>i) &1)
        {
            printf("%s", "1");
        }else{
            printf("%s", "0");
        }
    }
    printf("\n");
}

void append_crc (char* array, int array_len){
    array[array_len] = 0x00;
    array[array_len] = crc8(array,array_len+1);
    array[array_len+1] = '\0';
}

int is_corrupted (char* array, int array_len){
    int crc = crc8(array,array_len);
    return crc?1:0;
}

//Function returns the remainder from a CRC calculation on a char* array of length byte_len
char crc8(char* array, int array_len){
    // The most significant bit of the polynomial can be discarded in the computation, because:
    // (1) it is always 1
    // (2) it aligns with the next '1' of the dividend; the XOR result for this bit is always 0
    char poly =0x07; //00000111
    char crc = array[0];
    int i, j;
    for(i = 1; i < array_len; i++){
        char next_byte = array[i];
        for(j = 7; j >= 0; j--){
            if((crc & 0x80) == 0)
            {
                crc =  crc << 1;
                crc = crc | get_bit(next_byte, j);
            }
            else
            {
                crc =  crc << 1;
                crc = crc | get_bit(next_byte, j);
                crc = crc ^ poly;
            }
        }
    }
    return crc;
}
