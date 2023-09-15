
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "platform_type.h"


typedef struct Node
{
    uint32 Data;
    struct Node *Next_Node; /* Pointer Point On The Next Node */

}Node_Type;

typedef enum{
    LINKEDLIST_NOK = 0,
    LINKEDLIST_OK ,

}State_Type;

/**
    * @brief Insert Node In The Beginning of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *         Double Pointer Because We Would Change Contain of Head (Pass By Reference)
    * @param (Data) Number Will Add To Linked List
    * @retval status of function if it succeeded or not

  */

State_Type Insert_Node_At_Begining (Node_Type **Head_List,uint32 Data);

/**
    * @brief Insert Node In The End of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @param (Data) Number Will Add To Linked List
    * @retval status of function if it succeeded or not

  */

State_Type Insert_Node_At_End (Node_Type *Head_List,uint32 Data);

/**
    * @brief Insert Node After Specific Node of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @param (Data) Number Will Add To Linked List
    * @param (position) position of Node Will Add New Node After This position
    * @retval status of function if it succeeded or not

  */

State_Type Insert_Node_After_Node (Node_Type *Head_List, uint32 Data, uint32 postion);

/**
    * @brief Insert Node After Specific Node of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Double Pointer Because We Would Change Contain of Head (Pass By Reference)
    * @param (Data) Number Will Add To Linked List
    * @param (position) position of Node Will Add New Node Before This position
    * @retval status of function if it succeeded or not

  */

State_Type Insert_Node_Before_Node (Node_Type **Head_List, uint32 Data, uint32 postion);

/**
    * @brief Delete First Node Form Linked List
    * @param (Head_List)pointer point on the First Node oF Linked List
    *        Double Pointer Because We Would Change Contain of Head (Pass By Reference)
    * @retval Data Which Deleted Form Linked List

  */

uint32 Delete_Node_At_Begining (Node_Type **Head_List);

/**
    * @brief Delete Last Node Form Linked List
    * @param (Head_List)pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval Data Which Deleted Form Linked List

  */

uint32 Delete_Node_At_End (Node_Type *Head_List);

/**
    * @brief Delete Specific Node Form Linked List
    * @param (Head_List)pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @param (postion) the position of Node which Will Be Deleted
    * @retval Data Which Deleted Form Linked List

  */

uint32 Delete_node_In_Specific_position (Node_Type *Head_List , uint32 postion);

/**
    * @brief Display Data Which In The Linked List
    * @param (Head_List)pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval Nothing (Void)

  */

void Display_Nodes(Node_Type *Head_List);

/**
    * @brief Count Number Of Nodes In Linked List
    * @param (Head_List)pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval Number Of Nodes In Linked List

  */

uint32 Get_Length (Node_Type *Head_List);

/**
    * @brief Reverse Data In The Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *         Double Pointer Because We Would Change Contain of Head (Pass By Reference)
    * @retval Nothing (Void)

  */

void Reverse_The_List (Node_Type **Head_List);

/**
    * @brief Swap 2 Nodes In THE Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @param (position_Node_1) The Position Of First Node Will Swap
    * @param (position_Node_2) The Position Of Second Node Will Swap
    * @retval Nothing (Void)

  */

void Swap_2Nodes (Node_Type *Head_List , uint32 position_Node_1, uint32 position_Node_2);

/**
    * @brief Sort Nodes In The Linked List In Ascending
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval Nothing (Void)

  */

void Sort_The_Nodes_Ascending (Node_Type *Head_List);

/**
    * @brief Find The Middle Of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval position of The Middle Of Linked List

  */

uint32 The_Middle_Of_List (Node_Type *Head_List);

/**
    * @brief Delete Linked List
    * @param (Head_List)  pointer point on the First Node oF Linked List
    *        Double Pointer Because We Would Change Contain of Head (Pass By Reference)
    * @retval Nothing (Void)

  */

void Delete_List (Node_Type **Head_List);

/**
    * @brief Delete The Middle Of Linked List
    * @param (Head_List) pointer point on the First Node oF Linked List
    *        Single Pointer Because We Wouldn't Change Contain of Head (Pass By Value)
    * @retval Data Of Middle Which Deleted Form Linked List
  */

uint32 Delete_The_Middle (Node_Type *Head_List);


#endif // _LINKED_LIST_H
