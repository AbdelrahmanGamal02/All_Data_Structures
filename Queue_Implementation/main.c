
#include "Queue.h"

Queue_type *Queue_1 = NULL;

/* To Print Enum As a String Not A Number */
char *State_Of_Queue[5] = {"QUEUE_NOT_OK","QUEUE_OK","QUEUE_EMPTY","QUEUE_FULL","PASSED_NULL_POINTER"};

uint32 Var_1 = 66;
uint32 Var_2 = 4;
uint32 Var_3 = 90;
uint32 Var_4 = 1;
uint32 Var_5 = 0;

uint32 *Data_Returned = NULL;

int main()
{
    Queue_State_Type Queue_State = QUEUE_NOK;
    uint32 Max_size = 0;
    printf("Please Enter Max Size Of Element : ");
    scanf("%i",&Max_size);

    Queue_1 = Create_Queue(Max_size,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    if(NULL != Queue_1)
    {
        printf("Queue Created Successfully \n");
    }

    /*check insertion in the queue */
    Queue_State = Enqueue(Queue_1,&Var_1);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    Queue_State = Enqueue(Queue_1,&Var_2);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    Queue_State = Enqueue(Queue_1,&Var_3);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    Queue_State = Enqueue(Queue_1,&Var_4);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("--------------------------------------------\n");
    /*Number Of Elements*/
    Var_5 = Number_Of_Element(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Number of Elements = %i\n",Var_5);

    Data_Returned = Queue_Front(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Number in the Front = %i\n",*Data_Returned);

    Data_Returned = Queue_Rear(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Number in the Rear = %i\n",*Data_Returned);

    Display_Queue(Queue_1);
    printf("--------------------------------------------\n");
    /* Check Delete Function */
    Data_Returned = Dequeue(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Deleted Data = %i\n",*Data_Returned);

    Data_Returned = Dequeue(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Deleted Data = %i\n",*Data_Returned);

    Data_Returned = Dequeue(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Deleted Data = %i\n",*Data_Returned);

    Data_Returned = Dequeue(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Deleted Data = %i\n",*Data_Returned);

    Var_5 = Number_Of_Element(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Number of Elements = %i\n",Var_5);

    Data_Returned = Dequeue(Queue_1,&Queue_State);
    printf("State Of Queue is %s \n",State_Of_Queue[Queue_State]);
    printf("Deleted Data = %i\n",Data_Returned);


    return 0;
}
