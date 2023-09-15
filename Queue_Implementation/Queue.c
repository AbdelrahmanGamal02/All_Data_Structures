
#include "Queue.h"


Queue_type *Create_Queue(uint32 Max_Size ,Queue_State_Type *Queue_State)
{
    Queue_State_Type State = QUEUE_NOK;
    Queue_type *Queue_Object = NULL;
    if(NULL == Queue_State)
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        /*Create Struct in heap*/
        Queue_Object = (Queue_type *)malloc(sizeof(Queue_type));
        if(NULL != Queue_Object)
        {
            Queue_Object->Number_Of_Elements = 0;
            Queue_Object->Queue_Front = -1;
            Queue_Object->Queue_Rear = -1;
            Queue_Object->Queue_Max_Size = Max_Size;
            Queue_Object->Queue_Array = (uint32 **)calloc(Queue_Object->Queue_Max_Size,sizeof(uint32 *));
            if(NULL == Queue_Object->Queue_Array)
            {
                printf("Can't Allocated Array \n");
                /* Free Struct */
                free(Queue_Object);
                Queue_Object = NULL;
                State = QUEUE_NOK;
            }else
            {
                State = QUEUE_OK;
            }
        }
        else
        {
            printf("Can't Allocated\n");
            State = QUEUE_NOK;
        }
    }
    *Queue_State = State;

    return Queue_Object;
}

/**
    * @brief Check iF Queue Is Full or not
    * @param (Queue_Object) Queue Allocated In Heap
    * @retval Nothing (void)

  */
static uint32 Queue_Is_Full(Queue_type *Queue_Object)
{
    return(Queue_Object->Queue_Rear == ((Queue_Object->Queue_Max_Size) - 1));
}

/**
    * @brief Check iF Queue Is Empty or not
    * @param (Queue_Object) Queue Allocated In Heap
    * @retval Nothing (void)

  */
static uint8 Queue_Is_Empty(Queue_type *Queue_Object)
{
    return(Queue_Object->Number_Of_Elements == 0);
}


Queue_State_Type Enqueue(Queue_type *Queue_Object ,uint32 *New_Element)
{
    Queue_State_Type State = QUEUE_NOK;
    if((NULL == Queue_Object) || (NULL == New_Element))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Queue_Is_Full(Queue_Object))
        {
            State = QUEUE_FULL;

        }else{
        (Queue_Object->Queue_Rear)++;
        if(Queue_Object->Queue_Rear > Queue_Object->Queue_Max_Size)
        {
            Queue_Object->Queue_Rear = 0;
        }
        Queue_Object->Queue_Array[Queue_Object->Queue_Rear] = New_Element;
        if(-1 == Queue_Object->Queue_Front)
            (Queue_Object->Queue_Front)++;


        (Queue_Object->Number_Of_Elements)++;

        State = QUEUE_OK;
        }
    }

    return State;
}

uint32 *Dequeue(Queue_type *Queue_Object , Queue_State_Type *Queue_State)
{
    Queue_State_Type State = QUEUE_NOK;
    uint32 *Deleted_Data = NULL;
    if((NULL == Queue_Object) || (NULL == Queue_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Queue_Is_Empty(Queue_Object))
        {
            State = QUEUE_EMPTY;
            Deleted_Data = NULL;
        }
        else
        {
            Deleted_Data = Queue_Object->Queue_Array[Queue_Object->Queue_Front];
            (Queue_Object->Queue_Front)++;
            if(Queue_Object->Queue_Front > Queue_Object->Queue_Max_Size)
            {
                Queue_Object->Queue_Front = 0;
            }
            (Queue_Object->Number_Of_Elements)--;
            State = QUEUE_OK;
        }
    }
    *Queue_State = State;

    return Deleted_Data;
}

uint32 *Queue_Front(Queue_type *Queue_Object , Queue_State_Type *Queue_State)
{
    Queue_State_Type State = QUEUE_NOK;
    uint32 *Queue_Front_value = NULL;
    if((NULL == Queue_Object) || (NULL == Queue_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Queue_Is_Empty(Queue_Object))
        {
            State = QUEUE_EMPTY;
            Queue_Front_value = NULL;
        }
        else
    {
        Queue_Front_value = Queue_Object->Queue_Array[Queue_Object->Queue_Front];
        State = QUEUE_OK;
    }
    }
    *Queue_State = State;

    return Queue_Front_value;
}

uint32 *Queue_Rear(Queue_type *Queue_Object , Queue_State_Type *Queue_State)
{
    Queue_State_Type State = QUEUE_NOK;
    uint32 *Queue_Rear_value= NULL;
    if((NULL == Queue_Object) || (NULL == Queue_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Queue_Is_Empty(Queue_Object))
        {
            State = QUEUE_EMPTY;
            Queue_Rear_value = NULL;
        }
        else
    {
        Queue_Rear_value = Queue_Object->Queue_Array[Queue_Object->Queue_Rear];
        State = QUEUE_OK;
    }
    }
    *Queue_State = State;

    return Queue_Rear_value;
}

uint32 Number_Of_Element(Queue_type *Queue_Object , Queue_State_Type *Queue_State)
{
    Queue_State_Type State = QUEUE_NOK;
    uint32 Number_Of_Elements = 0;
    if((NULL == Queue_Object) || (NULL == Queue_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        Number_Of_Elements = Queue_Object->Number_Of_Elements;
        State = QUEUE_OK;
    }
    *Queue_State = State;

    return Number_Of_Elements;
}

void Destroy_Queue(Queue_type *Queue_Object)
{
    if(Queue_Object == NULL)
    {
        printf("Passed NULL pointer \n");
    }
    else
    {
        free(Queue_Object->Queue_Array);
        Queue_Object->Queue_Array = NULL;
        free(Queue_Object);
        Queue_Object = NULL;
    }
}

void Display_Queue(Queue_type *Queue_Object)
{
    uint32 counter = 0;
    printf("Data In Queue Is : ");
    for(counter = (Queue_Object->Queue_Front); counter < (Queue_Object->Queue_Rear);counter = ((counter+1) % Queue_Object->Queue_Max_Size))
    {
        printf("%i\t",*(Queue_Object->Queue_Array[counter]));
    }
    printf("%i\n",*(Queue_Object->Queue_Array[Queue_Object->Queue_Rear]));
}


