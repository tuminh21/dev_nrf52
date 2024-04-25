#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdint.h>
#include <string.h>

#define QUEUE_NUMBER (10)
#define QUEUE_SIZE   (100)
#define QUEUE_ERROR (0)
#define QUEUE_OK (1)


/**************** queue status *****************/
typedef  enum Status_t{
    QUEUE_EMPTY = 0,
    QUEUE_FULL
}QUEUE_Status_t;

/**************** queue struct*******************/
typedef  struct QUEUE
{
    uint16_t buffer[QUEUE_SIZE];
    QUEUE_Status_t status;
}QUEUE_t;

/*********** queue init ***********/
void queueInit();
/************ write data to queue *************/
uint8_t writeData2Queue(uint16_t *l_data, uint8_t l_len);
/************* read data from queue **************/
uint8_t readDataFromQueue(uint16_t *l_data, uint8_t l_len);

extern QUEUE_t queue[QUEUE_NUMBER];
extern uint8_t writeIndex;
extern uint8_t readIndex;

#endif