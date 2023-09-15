
#include "Stack.h"

Stack_Type *Create_Stack(uint32 Max_Size , Stack_State_Type *Stack_State)
{
    Stack_State_Type State = STACK_NOK;
    Stack_Type *My_Stack = NULL;
    /* validation on passed pointers */
    if(NULL == Stack_State)
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        /* allocate of struct in heap*/
        My_Stack = (Stack_Type *)malloc(sizeof(Stack_Type));
        /* validation if struct allocated or not */
        if(NULL != My_Stack)
        {
            My_Stack->Number_of_Elements = 0;
            My_Stack->Stack_Max_Size = Max_Size;
            My_Stack->Stack_Top = -1;
            /* allocate of array of pointers => elements of array is a integer pointers points on data */
            My_Stack->Stack_Array = (uint32 **)calloc(My_Stack->Stack_Max_Size,sizeof(uint32 *));
            /* validation if array allocated or not */
            if(NULL == My_Stack->Stack_Array)
            {
                printf("Can't Allocated \n");
                /*can't allocate array so we should free the struct */
                free(My_Stack);
                My_Stack = NULL;
                State = STACK_NOK;
            }
            else
            {
                State = STACK_OK;
            }
        }
        else
        {
            printf("Can't Allocated \n");
            State = STACK_NOK;
        }
    }
    *Stack_State = State;

    return My_Stack;
}

/**
    * @brief check if stack is Full or not
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval like a boolean 1 or 0

  */
static uint8 Stack_Is_Full(Stack_Type *Stack_Object)
{
    return (Stack_Object->Stack_Top == ((Stack_Object->Stack_Max_Size) - 1));
}

/**
    * @brief check if stack is empty or not
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval like a boolean 1 or 0

  */
static uint8 Stack_Is_Empty(Stack_Type *Stack_Object)
{
    return (Stack_Object->Stack_Top == -1);
}

Stack_State_Type Push_Element_In_Stack(Stack_Type *Stack_Object , uint32 *New_Element)
{
    Stack_State_Type State = STACK_NOK;
    if((NULL == Stack_Object) || (NULL == New_Element))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Stack_Is_Full(Stack_Object))
        {
            State = STACK_FULL;
        }
        else
        {
            (Stack_Object->Stack_Top)++;
            Stack_Object->Stack_Array[Stack_Object->Stack_Top] = New_Element;

            (Stack_Object->Number_of_Elements)++;
            State = STACK_OK;
        }

    }

    return State;
}

uint32 *Pop_Element_From_Stack(Stack_Type *Stack_Object , Stack_State_Type *Stack_State)
{
    Stack_State_Type State = STACK_NOK;
    uint32 *Deleted_Data = 0;
    if((NULL == Stack_Object) || (NULL == Stack_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Stack_Is_Empty(Stack_Object))
        {
            State = STACK_EMPTY;
            Deleted_Data = 0;
        }
        else
        {
            Deleted_Data = Stack_Object->Stack_Array[Stack_Object->Stack_Top];
            (Stack_Object->Stack_Top)--;

            (Stack_Object->Number_of_Elements)--;
            State = STACK_OK;
        }
    }
    *Stack_State = State;

    return Deleted_Data;
}

uint32 *Stack_Top(Stack_Type *Stack_Object , Stack_State_Type *Stack_State)
{
    Stack_State_Type State = STACK_NOK;
    uint32 *Data_on_Top = 0;
    if((NULL == Stack_Object) || (NULL == Stack_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Stack_Is_Empty(Stack_Object))
        {
            State = STACK_EMPTY;
            Data_on_Top=NULL;
        }
        else
        {
            Data_on_Top = Stack_Object->Stack_Array[Stack_Object->Stack_Top];

            State = STACK_OK;
        }
    }
    *Stack_State = State;

    return Data_on_Top;
}

uint32 Number_of_Element(Stack_Type *Stack_Object , Stack_State_Type *Stack_State)
{
    Stack_State_Type State = STACK_NOK;
    uint32 NumberOfElement = 0;
    if((NULL == Stack_Object) || (NULL == Stack_State))
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {
        if(Stack_Is_Empty(Stack_Object))
        {
            State = STACK_EMPTY;
            NumberOfElement=0;
        }
        else
        {
            NumberOfElement = Stack_Object->Number_of_Elements;

            State = STACK_OK;
        }
    }
    *Stack_State = State;

    return NumberOfElement;
}


void Destroy_Stack(Stack_Type *Stack_Object)
{
    if(NULL == Stack_Object)
    {
        printf("Passed NULL Pointer\n");
    }
    else
    {
        /* free array of pointers first */
        free(Stack_Object->Stack_Array);
        Stack_Object->Stack_Array = NULL;

        free(Stack_Object);
        Stack_Object = NULL;
    }
}
void Display_Stack(Stack_Type *Stack_Object)
{
    uint32 counter = 0;
    printf("Data In The Stack : ");
    for(counter = (Stack_Object->Stack_Top) ;counter >0;counter--)
    {
        printf("%i \t",*(Stack_Object->Stack_Array[counter]));
    }
    printf("%i \n",*(Stack_Object->Stack_Array[0]));
}

uint32 Max_Number_In_Stack(Stack_Type *Stack_Object)
{
    uint32 Max_Number = *(Stack_Object->Stack_Array[Stack_Object->Stack_Top]);
    uint32 counter = 0, Number = 0;
    if(NULL == Stack_Object)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        for(counter = (Stack_Object->Stack_Top) ; counter > 0; counter--)
        {
            Number = *(Stack_Object->Stack_Array[counter]);
            if(Max_Number < Number)
            {
                Max_Number = Number;
            }
        }
        if(Max_Number < *(Stack_Object->Stack_Array[0]))
        {
            Max_Number = *(Stack_Object->Stack_Array[0]);
        }
        else
        {
            /* Nothing */
        }
    }
    return Max_Number;
}

uint32 The_Middle_of_Stack(Stack_Type *Stack_Object)
{
    uint32 Middle = 0, Position_Middle = 0;
    if(NULL == Stack_Object)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        Position_Middle = floor((Stack_Object->Stack_Max_Size / 2.0));
        Middle = *(Stack_Object->Stack_Array[Position_Middle]);
    }

    return Middle;
}

Stack_State_Type Delete_Middle_of_Stack(Stack_Type *Stack_Object)
{
    Stack_State_Type State = STACK_NOK;
    /* to push element above middle until reach middle */
    Stack_Type *Temp_Stack = NULL;
    uint32 Middle = The_Middle_of_Stack(Stack_Object) , counter = 0;
    uint32 *Deleted_Data = NULL;

    if(NULL == Stack_Object)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        /*  Create temp Stack*/
        Temp_Stack = Create_Stack(Stack_Object->Stack_Max_Size,&State);
        if((NULL != Temp_Stack) && (State == STACK_OK))
        {
            /* Delete elements above middle and push it in temp stack*/
            while(1)
            {
                counter = *(Stack_Object->Stack_Array[Stack_Object->Stack_Top]);
                if(counter == Middle)
                {break;}

                Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);
                State = Push_Element_In_Stack(Temp_Stack,Deleted_Data);
            }
            /*after while top point on the Middle */
            /* Delete Middle */
            Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);
            /* Return Data Stored in temp stack to original stack */
            while(!(Stack_Is_Empty(Temp_Stack)))
            {
                Deleted_Data = Pop_Element_From_Stack(Temp_Stack,&State);
                State = Push_Element_In_Stack(Stack_Object,Deleted_Data);
            }
            /* Delete temp Stack*/
            Destroy_Stack(Temp_Stack);
            Temp_Stack = NULL;
        }
        else{
            printf("ERROR \n");
            State = STACK_NOK;
        }
        }

        return State;
}

Stack_State_Type Delete_Max_Number_In_Stack(Stack_Type *Stack_Object)
{
    Stack_State_Type State = STACK_NOK;
    /* to push element above Max_number until reach middle */
    Stack_Type *Temp_Stack = NULL;
    uint32 Max_Number = Max_Number_In_Stack(Stack_Object) , counter = 0;
    uint32 *Deleted_Data = NULL;

    if(NULL == Stack_Object)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        /*  Create temp Stack*/
        Temp_Stack = Create_Stack(Stack_Object->Stack_Max_Size,&State);
        if((NULL != Temp_Stack) && (State == STACK_OK))
        {
            /* check if the top is the max number */
            if(Max_Number == *(Stack_Object->Stack_Array[Stack_Object->Stack_Top]))
            {
                Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);
                Destroy_Stack(Temp_Stack);
                Temp_Stack = NULL;
            }
            else
            {
                /* Delete elements above Max_Number and push it in temp stack*/
                while(1)
                {
                    counter = *(Stack_Object->Stack_Array[Stack_Object->Stack_Top]);
                    if(counter == Max_Number)
                        {break;}

                    Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);
                    State = Push_Element_In_Stack(Temp_Stack,Deleted_Data);
                }
                /*after while top point on the Middle */
                /* Delete Middle */
                Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);
                /* Return Data Stored in temp stack to original stack */
                while(!(Stack_Is_Empty(Temp_Stack)))
                {
                    Deleted_Data = Pop_Element_From_Stack(Temp_Stack,&State);
                    State = Push_Element_In_Stack(Stack_Object,Deleted_Data);
                }
                /* Delete temp Stack*/
                Destroy_Stack(Temp_Stack);
                Temp_Stack = NULL;

            }
        }
        else
        {
            printf("ERROR \n");
            State = STACK_NOK;
        }
    }

    return State;
}

uint32 Average_value_of_elements(Stack_Type *Stack_Object)
{
    float32 Average = 0.0 ,Sum = 0.0 ;
    uint32 counter = 0 ;
    for(counter = (Stack_Object->Stack_Top) ;counter > 0;counter--)
    {
        Sum += *(Stack_Object->Stack_Array[counter]);
    }
        Sum += *(Stack_Object->Stack_Array[0]);


        Average = Sum / (Stack_Object->Number_of_Elements);

    return Average;
}

Stack_State_Type Sort_The_Stack(Stack_Type *Stack_Object)
{
    uint32 *Deleted_Data_1 = NULL ,*Deleted_Data_2 = NULL , *TopStack = NULL;
    Stack_State_Type State = STACK_NOK;
    Stack_Type *Temp_Stack = NULL;

    if(NULL == Stack_Object)
    {
        printf("PASSED NULL POINTRE \n");
    }
    else
    {
        Temp_Stack = Create_Stack(Stack_Object->Stack_Max_Size,&State);

        if((NULL != Temp_Stack) && (State == STACK_OK))
        {
            while(!(Stack_Is_Empty(Stack_Object)))
            {
                Deleted_Data_1 = Pop_Element_From_Stack(Stack_Object,&State);
                while(!(Stack_Is_Empty(Temp_Stack)))
                {
                    TopStack = Stack_Top(Temp_Stack,&State);
                    if(*(TopStack) > *(Deleted_Data_1))
                    {
                        Deleted_Data_2 = Pop_Element_From_Stack(Temp_Stack,&State);
                        State = Push_Element_In_Stack(Stack_Object,Deleted_Data_2);
                    }
                    else
                    {
                        break;
                    }
                }

                State = Push_Element_In_Stack(Temp_Stack , Deleted_Data_1);
            }
            while(!(Stack_Is_Empty(Temp_Stack)))
            {
                Deleted_Data_1 = Pop_Element_From_Stack(Temp_Stack,&State);
                State = Push_Element_In_Stack(Stack_Object,Deleted_Data_1);
            }
            /* Destroy Temp Stack */
            Destroy_Stack(Temp_Stack);
        }
        else
        {
            printf("ERROR \n");
            State = STACK_NOK;
        }

    }

    return State ;
}



Stack_State_Type Reverse_The_Stack(Stack_Type *Stack_Object)
{
    /* temporary Array to Store Stack Elements and return them again*/
    uint32 *Temp_Array = NULL, *Deleted_Data = NULL;
    Stack_State_Type State = STACK_NOK;
    uint32 counter =0;
    uint32 Element_Number =(Stack_Object->Number_of_Elements);
    if(NULL == Stack_Object)
    {
        State = PASSED_NULL_POINTER;
    }
    else
    {

        /* Create Array*/
        Temp_Array = (uint32 *)calloc(Element_Number , sizeof(uint32));
        while(Stack_Object->Stack_Top != -1)
        {
            /* Pop elements from Stack in Array*/
            Deleted_Data = Pop_Element_From_Stack(Stack_Object,&State);

            Temp_Array[counter] = *Deleted_Data;
            counter++;
        }


        for(counter = 0 ; counter < (Element_Number);counter++)
        {
          /*   return elements again to stack but reversed*/
            State = Push_Element_In_Stack(Stack_Object,(&(Temp_Array[counter])));
        }

    }
        /*free Temp Array
        free(Temp_Array);
        Temp_Array = NULL;*/

    return State;
}



















