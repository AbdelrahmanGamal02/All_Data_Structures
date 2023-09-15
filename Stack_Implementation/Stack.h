
#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "platform_type.h"

typedef struct
{
    uint32 **Stack_Array; /* pointer points on array of pointers point on data*/
    uint32 Stack_Max_Size;
    uint32 Number_of_Elements;
    sint32 Stack_Top;

}Stack_Type;

typedef enum{   /* ENUM used to identify the state of stack */
    STACK_NOK = 0,
    STACK_OK ,
    STACK_EMPTY ,
    STACK_FULL ,
    PASSED_NULL_POINTER ,

}Stack_State_Type;

/**
    * @brief create the stack in the heap
    * @param (max_size) max number of elements in stack
    * @param (Stack_State) pointer point to enum to know if function succeeded or not
    * @retval address of the first byte of stack created (address of stack in heap)
  */
Stack_Type *Create_Stack(uint32 Max_Size , Stack_State_Type *Stack_State);

/**
    * @brief push new element in the stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @param (New_Element) element will push into the stack
    * @retval status of function if it succeeded or not
  */
Stack_State_Type Push_Element_In_Stack(Stack_Type *Stack_Object , uint32 *New_Element);

/**
    * @brief remove element from the stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @param (Stack_State) pointer point to enum to know if function succeeded or not
    * @retval element poped from the stack
  */
uint32 *Pop_Element_From_Stack(Stack_Type *Stack_Object , Stack_State_Type *Stack_State);

/**
    * @brief know which element in the top of stack(last element pushed in the stack)
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @param (Stack_State) pointer point to enum to know if function succeeded or not
    * @retval element which on the top of stack
  */
uint32 *Stack_Top(Stack_Type *Stack_Object , Stack_State_Type *Stack_State);

/**
    * @brief number of element in the stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @param (Stack_State) pointer point to enum to know if function succeeded or not
    * @retval Number of Element In the Stack

  */
uint32 Number_of_Element(Stack_Type *Stack_Object , Stack_State_Type *Stack_State);

/**
    * @brief remove stack from heap
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval Nothing (void)
  */
void Destroy_Stack(Stack_Type *Stack_Object);

/**
    * @brief Display the Elements In the Stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval Nothing (void)
  */
void Display_Stack(Stack_Type *Stack_Object);

/**
    * @brief find max number in stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval Max number
  */
uint32 Max_Number_In_Stack(Stack_Type *Stack_Object);

/**
    * @brief find Middle number in stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval Middle number
  */
uint32 The_Middle_of_Stack(Stack_Type *Stack_Object);

/**
    * @brief Delete middle number From stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval status of function if it succeeded or not
  */
Stack_State_Type Delete_Middle_of_Stack(Stack_Type *Stack_Object);

/**
    * @brief Delete max number From stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval status of function if it succeeded or not
  */
Stack_State_Type Delete_Max_Number_In_Stack(Stack_Type *Stack_Object);

/**
    * @brief Sort elements in the stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval status of function if it succeeded or not
  */
Stack_State_Type Sort_The_Stack(Stack_Type *Stack_Object);

/**
    * @brief Find average of elements values in the stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval Average Value
  */
uint32 Average_value_of_elements(Stack_Type *Stack_Object);

/**
    * @brief Reverse Elements In The Stack
    * @param (Stack_Object) pointer point on the stack on heap (the stack)
    * @retval status of function if it succeeded or not
  */
Stack_State_Type Reverse_The_Stack(Stack_Type *Stack_Object);




#endif // _STACK_H
