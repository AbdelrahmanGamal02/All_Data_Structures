
#include "Stack.h"

Stack_Type *Stack_1 = NULL;

/* To Print Enum As a String Not A Number */
char *State_Of_Stack[5] = {"STACK_NOT_OK","STACK_OK","STACK_EMPTY","STACK_FULL","PASSED_NULL_POINTER"};

uint32 Var_1 = 5;
uint32 Var_2 = 2;
uint32 Var_3 = 6;
uint32 Var_4 = 3;
uint32 Var_6 = 9;
uint32 Var_5 = 7;

uint32 *Data_Returned = NULL;


int main()
{
    Stack_State_Type Stack_State = STACK_NOK;
    uint32 Max_size = 0 , Max_Number =0, Middle = 0 , Average = 0;
    printf("Please Enter Max Size Of Element : ");
    scanf("%i",&Max_size);

    Stack_1 = Create_Stack(Max_size , &Stack_State);
    printf("State Of stack is %s \n",State_Of_Stack[Stack_State]);
    if(NULL != Stack_1)
    {
        printf("Stack Created Successfully \n");
    }

    /*check insertion in the queue */
    Stack_State = Push_Element_In_Stack(Stack_1,&Var_1);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    Stack_State = Push_Element_In_Stack(Stack_1,&Var_2);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    Stack_State = Push_Element_In_Stack(Stack_1,&Var_3);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    Stack_State = Push_Element_In_Stack(Stack_1,&Var_6);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    Stack_State = Push_Element_In_Stack(Stack_1,&Var_4);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    printf("--------------------------------------------\n");
    /*Number Of Elements*/
    Var_5 = Number_of_Element(Stack_1,&Stack_State);
    printf("State Of stack is %s \n",State_Of_Stack[Stack_State]);
    printf("Number of Elements = %i\n",Var_5);


    Data_Returned = Stack_Top(Stack_1,&Stack_State);
    printf("State Of stack is %s \n",State_Of_Stack[Stack_State]);
    printf("Number on the top of stack = %i\n",*Data_Returned);

    Display_Stack(Stack_1);
    printf("--------------------------------------------\n");
    /* Max Number in Stack */
    Max_Number = Max_Number_In_Stack(Stack_1);
    printf("Max Number In Stack  = %i \n",Max_Number);
    /* Middle of Stack */
    Middle = The_Middle_of_Stack(Stack_1);
    printf("Middle of Stack  = %i \n",Middle);

    /* Delete The Middle */
    Stack_State = Delete_Middle_of_Stack(Stack_1);
    printf("State Of Stack is %s after Delete Middle \n",State_Of_Stack[Stack_State]);
    Display_Stack(Stack_1);

    /* Delete Max NUMBER */
    Stack_State = Delete_Max_Number_In_Stack(Stack_1);
    printf("State Of Stack is %s after Delete Max Number \n",State_Of_Stack[Stack_State]);
    Display_Stack(Stack_1);

    /* Average of elements in the stack */
    Average = Average_value_of_elements(Stack_1);
    printf("Average of Elements In The Stack  = %i \n",Average);

    /* Sort The Stack */
    Stack_State = Sort_The_Stack(Stack_1);
    printf("State Of Stack is %s after Sorting Stack \n",State_Of_Stack[Stack_State]);
    Display_Stack(Stack_1);

    /*Reverse Stack*/
    Stack_State = Reverse_The_Stack(Stack_1);
    printf("State Of Stack is %s after Reversing Stack \n",State_Of_Stack[Stack_State]);
    Display_Stack(Stack_1);


    printf("--------------------------------------------\n");
    /* Check Delete Function */
    while(1)
    {
        Data_Returned = Pop_Element_From_Stack(Stack_1,&Stack_State);
        printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);

        if(Stack_State == STACK_EMPTY)
        {break;}

        printf("Deleted Data = %i\n",*Data_Returned);
    }

    Var_5 = Number_of_Element(Stack_1,&Stack_State);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    printf("Number of Elements = %i\n",Var_5);

    Data_Returned = Pop_Element_From_Stack(Stack_1,&Stack_State);
    printf("State Of Stack is %s \n",State_Of_Stack[Stack_State]);
    printf("Deleted Data = %i\n",Data_Returned);
    return 0;
}
