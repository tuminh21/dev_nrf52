#include "queue.h"

QUEUE_t queue[QUEUE_NUMBER];
uint8_t writeIndex;
uint8_t readIndex;

/*********** queue init ***********/
void queueInit()
{
    uint8_t l_index;
    writeIndex = 0;
    readIndex = 0;
    for(l_index=0;l_index<QUEUE_NUMBER;l_index++)
    {
        memset(&queue[l_index],0x00,sizeof(queue[l_index]));
    }
}

/************ write data to queue *************/
uint8_t writeData2Queue(uint16_t *l_data, uint8_t l_len)
{
    uint8_t l_result = QUEUE_ERROR;
    if((uint8_t)QUEUE_SIZE == l_len)
    {
        if(NULL != l_data)
        {
            if(QUEUE_EMPTY == queue[writeIndex].status)
            {
                //memcpy(queue[writeIndex].buffer,l_data,sizeof(queue[writeIndex].buffer));
                for(uint8_t index=0;index<l_len*sizeof(uint16_t);index++)
                {
                    queue[writeIndex].buffer[index] = l_data[index];
                }
                queue[writeIndex].status = QUEUE_FULL;
                writeIndex ++; 
                if(writeIndex >= QUEUE_NUMBER) writeIndex = 0;
                l_result = QUEUE_OK;
            }
        }    
    }
    return l_result;
}

/************* read data from queue **************/
uint8_t readDataFromQueue(uint16_t *l_data, uint8_t l_len)
{
    uint8_t l_result = QUEUE_ERROR;
    if((uint8_t)QUEUE_SIZE == l_len)
    {
        if(NULL != l_data)
        {
            if(QUEUE_FULL == queue[readIndex].status)
            {
                //memcpy(l_data,queue[readIndex].buffer,sizeof(queue[readIndex].buffer));
                for(uint8_t index=0;index<l_len*sizeof(uint16_t);index++)
                {
                      l_data[index] = queue[writeIndex].buffer[index];
                }
                queue[readIndex].status = QUEUE_EMPTY;
                readIndex ++;
                if(readIndex >= QUEUE_NUMBER) readIndex = 0;                
                l_result = QUEUE_OK;
            }
        }
    }
    return l_result;
}