
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "platform_type.h"

typedef struct{

    uint32 **Queue_Array;
    uint32 Queue_Max_Size;
    uint32 Number_Of_Elements;
    sint32 Queue_Front;
    sint32 Queue_Rear;

}Queue_type;

typedef enum
{
    QUEUE_NOK =0,
    QUEUE_OK ,
    QUEUE_EMPTY ,
    QUEUE_FULL ,
    PASSED_NULL_POINTER ,

}Queue_State_Type;

/**
    * @brief Create New Queue In Heap
    * @param (Max_Size) Max Number Of Elements In Queue
    * @param (Queue_State) State of Function if Succeed or Not
    * @retval pointer Point On the First Byte Allocated in Heap of Struct

  */
Queue_type *Create_Queue(uint32 Max_Size ,Queue_State_Type *Queue_State);

/**
    * @brief Insert New Number In Queue
    * @param (Queue_Object) Queue Allocated In Heap
    * @param (New_Element) New Element will Enqueue in Queue
    * @retval status of function if it's succeeded or not

  */
Queue_State_Type Enqueue(Queue_type *Queue_Object ,uint32 *New_Element);

/**
    * @brief Delete Number From Queue
    * @param (Queue_Object) Queue Allocated In Heap
    * @param (Queue_State) State of Function if Succeed or Not
    * @retval Deleted Data From Queue

  */
uint32 *Dequeue(Queue_type *Queue_Object , Queue_State_Type *Queue_State);

/**
    * @brief Find Number Which Front Point on it
    * @param (Queue_Object) Queue Allocated In Heap
    * @param (Queue_State) State of Function if Succeed or Not
    * @retval Deleted Data From Queue

  */
uint32 *Queue_Front(Queue_type *Queue_Object , Queue_State_Type *Queue_State);

/**
    * @brief Find Number Which Rear Point on it
    * @param (Queue_Object) Queue Allocated In Heap
    * @param (Queue_State) State of Function if Succeed or Not
    * @retval Deleted Data From Queue

  */
uint32 *Queue_Rear(Queue_type *Queue_Object , Queue_State_Type *Queue_State);

/**
    * @brief Find Number Of Element In Queue
    * @param (Queue_Object) Queue Allocated In Heap
    * @param (Queue_State) State of Function if Succeed or Not
    * @retval Number of Element In Queue

  */
uint32 Number_Of_Element(Queue_type *Queue_Object , Queue_State_Type *Queue_State);

/**
    * @brief Remove Queue From Heap
    * @param (Queue_Object) Queue Allocated In Heap
    * @retval Nothing (void)

  */
void Destroy_Queue(Queue_type *Queue_Object);

/**
    * @brief Display Elements In Queue
    * @param (Queue_Object) Queue Allocated In Heap
    * @retval Nothing (void)

  */
void Display_Queue(Queue_type *Queue_Object);

#endif // _QUEUE_H
