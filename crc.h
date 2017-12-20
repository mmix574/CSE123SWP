//
// Created by mmix on 12/14/17.
//

#ifndef CSE123SWP_CRC_H
#define CSE123SWP_CRC_H



char get_bit (char byte, int pos); // return a char with a value of 0 or 1 depending on whether // the bit in the pos is 0 or 1
char crc8 (char* array, int byte_len); // or crc16, crc32 etc.
void append_crc (char* array, int array_len); // append crc remainder to the char array
int is_corrupted (char* array, int array_len); // return 1 if a frame is corrupted, otherwise
void print_char(char A);


#endif //CSE123SWP_CRC_H
