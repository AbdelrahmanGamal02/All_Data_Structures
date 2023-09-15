
#include "Double_Linked_List.h"

/**
    * @brief Swap Two Numbers
    * @param (number_1) First Number
    * @param (number_2) Second Number
    * @retval Nothing (Void)
  */

static void swap(uint32 *number_1,uint32 *number_2)
{
    uint32 temp = 0;
    temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

uint32 Get_Length (Node_Type *Head_List)
{
    Node_Type *Traverse_ptr = Head_List;
    uint32 counter = 0;
    if(NULL == Head_List)
    {
        printf("PASSED_NULL_POINTER \n");
        counter = 0;
    }
    else
    {
        while(Traverse_ptr != NULL)
        {
            Traverse_ptr = Traverse_ptr->Next_Node;
            counter++;
        }
    }

    return counter;
}

uint32 The_Middle_Of_List (Node_Type *Head_List)
{
    uint32 Middle = 0 , Length = Get_Length(Head_List);
    Node_Type *Traverse_ptr = Head_List;

    if(NULL == Head_List)
    {
        printf("PASSED_NULL_POINTER \n");
        Middle = 0;
    }
    else
    {
        Middle = ceil((Length / 2.0));
        while(--Middle)
        {
            Traverse_ptr = Traverse_ptr->Next_Node;
        }
        Middle = Traverse_ptr->Data;

        /* Traverse pointer finish his task */
        Traverse_ptr = NULL;
    }

    return Middle;
}

State_Type Insert_Node_At_Begining (Node_Type **Head_List,uint32 Data)
{
    State_Type State = LINKEDLIST_NOK;
    Node_Type *New_Node = NULL;
    /* Create New Node */
    New_Node = (Node_Type *)malloc(sizeof(Node_Type));
    if(NULL != New_Node)
    {
        /* initialize element of New Node */
        New_Node->Data = Data;
        New_Node->Next_Node = NULL;
        New_Node->Prev_Node = NULL;
        /*Validate that Linked list Empty or not*/
        if(NULL == *Head_List)
        {
            *Head_List = New_Node;

        }else
        {
            New_Node->Next_Node = *Head_List;
            (*Head_List)->Prev_Node = New_Node;
            *Head_List = New_Node;
        }
        State = LINKEDLIST_OK;

    }else
    {
        printf("Can't Allocated \n");
        State = LINKEDLIST_NOK;
    }

    return State;
}

State_Type Insert_Node_At_End (Node_Type *Head_List,uint32 Data)
{
    State_Type State = LINKEDLIST_NOK;
    /* pointer to traverse on the linked list */
    Node_Type *Traverse_ptr = Head_List;
    Node_Type *New_Node = NULL;
    /* Create New Node */
    New_Node = (Node_Type *)malloc(sizeof(Node_Type));
    if(NULL != New_Node)
    {
        /* initialize element of New Node */
        New_Node->Data = Data;
        New_Node->Next_Node = NULL;
        New_Node->Prev_Node = NULL;
        /*Validate that Linked list Empty or not*/
        if(NULL == Head_List)
        {
            State = Insert_Node_At_Begining(&Head_List,Data);
            if(LINKEDLIST_OK != State)
            { return LINKEDLIST_NOK;}

        }else
        {
            while(NULL != Traverse_ptr->Next_Node)
            {
                Traverse_ptr = Traverse_ptr->Next_Node;
            }
            Traverse_ptr->Next_Node = New_Node;
            New_Node->Prev_Node = Traverse_ptr;

            /*Traverse pointer finish his task */
            Traverse_ptr = NULL;
        }
        State = LINKEDLIST_OK;

    }else
    {
        printf("Can't Allocated \n");
        State = LINKEDLIST_NOK;
    }

    return State;
}



State_Type Insert_Node_After_Node (Node_Type *Head_List, uint32 Data, uint32 postion)
{
    State_Type State = LINKEDLIST_NOK;
    /* to check if position entered correct or not */
    uint32 check_position = Get_Length(Head_List);
    if(postion > check_position)
    {
        printf("Position is Incorrect \n");
        State = LINKEDLIST_NOK;
    }else
    {
        /* pointer to traverse on the linked list */
        Node_Type *Traverse_ptr = Head_List;
        Node_Type *New_Node = NULL;
        /* Create New Node */
        New_Node = (Node_Type *)malloc(sizeof(Node_Type));
        if(NULL != New_Node)
        {
            /* initialize element of New Node */
            New_Node->Data = Data;
            New_Node->Next_Node = NULL;
            New_Node->Prev_Node = NULL;

            if(check_position == postion)
            {
                State = Insert_Node_At_End(Head_List,Data);
                if(LINKEDLIST_OK != State)
                    { return LINKEDLIST_NOK;}
            }else
            {
            while( --postion )
            {
                Traverse_ptr = Traverse_ptr->Next_Node;
            }
            /* set pointers of new node */
            New_Node->Next_Node = Traverse_ptr->Next_Node;
            Traverse_ptr->Next_Node = New_Node;
            New_Node->Prev_Node = Traverse_ptr;
            /*set prev_ptr of next node of new node */
            New_Node->Next_Node->Prev_Node = New_Node;

            /*Traverse pointer finish his task */
            Traverse_ptr = NULL;

            State = LINKEDLIST_OK;
            }

        }else
        {
            printf("Can't Allocated \n");
            State = LINKEDLIST_NOK;
        }
    }

    return State;
}

State_Type Insert_Node_Before_Node (Node_Type **Head_List, uint32 Data, uint32 postion)
{
    State_Type State = LINKEDLIST_NOK;
    /* to check if position entered correct or not */
    uint32 check_position = Get_Length(*Head_List);
    if(postion > check_position)
    {
        printf("Position is Incorrect \n");
        State = LINKEDLIST_NOK;
    }else
    {
        /* pointer to traverse on the linked list */
        Node_Type *Traverse_ptr = *Head_List;
        Node_Type *New_Node = NULL;
        /* Create New Node */
        New_Node = (Node_Type *)malloc(sizeof(Node_Type));
        if(NULL != New_Node)
        {
            /* initialize element of New Node */
            New_Node->Data = Data;
            New_Node->Next_Node = NULL;
            New_Node->Prev_Node = NULL;

            if(1 == postion)
            {
                State = Insert_Node_At_Begining(Head_List,Data);
                if(LINKEDLIST_OK != State)
                    { return LINKEDLIST_NOK;}
            }else
            {
                while( --postion )
                {
                    Traverse_ptr = Traverse_ptr->Next_Node;
                }
                /* set pointers of new node */
                New_Node->Next_Node = Traverse_ptr;
                New_Node->Prev_Node = Traverse_ptr->Prev_Node;
                Traverse_ptr->Prev_Node = New_Node;
                /*set next_ptr of prev node of new node */
                New_Node->Prev_Node->Next_Node = New_Node;

                /*Traverse pointer finish his task */
                Traverse_ptr = NULL;

                State = LINKEDLIST_OK;
            }

        }else
        {
            printf("Can't Allocated \n");
            State = LINKEDLIST_NOK;
        }
    }

    return State;
}

void Display_Nodes_In_Forward_Direction(Node_Type *Head_List)
{
    Node_Type *Traverse_ptr = Head_List;
    if(NULL == Head_List)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        printf("Data In The Linked List In Forward Direction => ");
        while(NULL != Traverse_ptr)
        {
            printf("%i \t",Traverse_ptr->Data);
            Traverse_ptr = Traverse_ptr->Next_Node;
        }
        printf("\n");
    }
}

uint32 Delete_Node_At_Begining (Node_Type **Head_List)
{
    uint32 Deleted_Data = 0;
    Node_Type *Deleted_ptr = NULL;

    if(NULL == *Head_List)
    {
        printf("LINKED LIST IS EMPTY \n");
        Deleted_Data = 0;
    }
    else
    {
        /* move head without losing the first node */
        Deleted_ptr = *Head_List;
        *Head_List = (*Head_List)->Next_Node;
        /* adjust pointers and Data */
        (*Head_List)->Prev_Node = NULL;
        Deleted_Data = Deleted_ptr->Data;
        /* delete node */
        Deleted_ptr->Next_Node = NULL;
        free(Deleted_ptr);
        Deleted_ptr = NULL;
    }

    return Deleted_Data;
}

uint32 Delete_Node_At_End (Node_Type *Head_List)
{
    uint32 Deleted_Data = 0;

    Node_Type *Traverse_ptr = NULL;
    Node_Type *Deleted_Ptr = Head_List;

    if(NULL == Head_List)
    {
        printf("Linked List Is Empty \n");
    }
    else
    {
        while(NULL != Deleted_Ptr->Next_Node)
        {
            Deleted_Ptr = Deleted_Ptr->Next_Node;
        }
        Traverse_ptr = Deleted_Ptr->Prev_Node;
        Traverse_ptr->Next_Node = NULL;

        /* Delete Node */
        Deleted_Ptr->Prev_Node = NULL;
        Deleted_Data = Deleted_Ptr->Data;
        free(Deleted_Ptr);
        Deleted_Ptr = NULL;

        /*Traverse Pointer finish his task */
        Traverse_ptr = NULL;
    }

    return Deleted_Data;
}

uint32 Delete_node_In_Specific_position (Node_Type *Head_List , uint32 postion)
{
    uint32 Deleted_Data = 0 , Check_Position = Get_Length(Head_List);

    Node_Type *Traverse_ptr = NULL;
    Node_Type *Deleted_ptr = Head_List;
    /* check if position valued or not*/
    if(Check_Position < postion)
    {
        printf("Position Is Incorrect \n");
    }
    else
    {
        if(NULL == Head_List)
        {
            printf("Linked List Is Empty \n");
        }else{
        if(1 == postion)
        {
            Deleted_Data = Delete_Node_At_Begining(&Head_List);

        }else if(postion == Check_Position)
        {
            Deleted_Data = Delete_Node_At_End(Head_List);

        }else{

        while(--postion)
        {
            Deleted_ptr = Deleted_ptr->Next_Node;
        }
        /*Adjust pointers */
        Traverse_ptr = Deleted_ptr->Prev_Node;
        Traverse_ptr->Next_Node = Deleted_ptr->Next_Node;
        Deleted_ptr->Next_Node->Prev_Node = Traverse_ptr;

        /*Delete Node*/
        Deleted_ptr->Next_Node = NULL;
        Deleted_ptr->Prev_Node = NULL;
        Deleted_Data = Deleted_ptr->Data;
        free(Deleted_ptr);
        Deleted_ptr = NULL;

        /*Traverse pointer Finish his Task */
        Traverse_ptr = NULL;

        }
    }
    }

    return Deleted_Data;
}

void Display_Nodes_In_Reverse_Direction(Node_Type *Head_List)
{
    Node_Type *Traverse_ptr = Head_List;
    if(NULL == Head_List)
    {
        printf("PASSED NULL POINTER \n");
    }
    else
    {
        while(NULL != Traverse_ptr->Next_Node)
        {
            Traverse_ptr = Traverse_ptr->Next_Node;
        }
        printf("Data In The Linked List In Reverse Direction => ");
        while(NULL != Traverse_ptr)
        {
            printf("%i \t",Traverse_ptr->Data);
            Traverse_ptr = Traverse_ptr->Prev_Node;
        }
        printf("\n");
    }
}

uint32 Delete_The_Middle (Node_Type *Head_List)
{
    uint32 Delete_Middle = The_Middle_Of_List(Head_List);
    Node_Type *Delete_Middle_ptr = Head_List;
    Node_Type *Traverse_ptr = NULL;

    while(Delete_Middle != Delete_Middle_ptr->Data)
    {
        Delete_Middle_ptr = Delete_Middle_ptr->Next_Node;
    }
    Traverse_ptr = Delete_Middle_ptr->Prev_Node;
    Traverse_ptr->Next_Node = Delete_Middle_ptr->Next_Node;
    Delete_Middle_ptr->Next_Node->Prev_Node = Traverse_ptr;
    /*Delete Node*/
    Delete_Middle_ptr->Next_Node = NULL;
    Delete_Middle_ptr->Prev_Node = NULL;
    free(Delete_Middle_ptr);
    Delete_Middle_ptr = NULL;

    return Delete_Middle;
}


void Delete_List (Node_Type **Head_List)
{
    Node_Type *Traverse_ptr = NULL;
    while(NULL != (*Head_List)->Next_Node)
    {
        Traverse_ptr = *Head_List;
        *Head_List = (*Head_List)->Next_Node;
        (*Head_List)->Prev_Node = NULL;

        Traverse_ptr->Next_Node = NULL;
        free(Traverse_ptr);
        Traverse_ptr = NULL;
    }
    /* Delete Head */
    free(*Head_List);
    *Head_List = NULL;
}

void Swap_2Nodes (Node_Type *Head_List , uint32 position_Node_1, uint32 position_Node_2)
{
    uint32 check_position = Get_Length(Head_List);

    Node_Type *Traverse_Node_1 = Head_List;
    Node_Type *Traverse_Node_2 = Head_List;

    if(position_Node_1 > check_position || position_Node_2 > check_position)
    {
        printf("Position Not Correct \n");
    }
    else
    {
        /* Traverse first pointer */
        while( --position_Node_1 )
        {
            Traverse_Node_1 = Traverse_Node_1->Next_Node;
        }

        /* Traverse second pointer */
        while( --position_Node_2 )
        {
            Traverse_Node_2 = Traverse_Node_2->Next_Node;
        }

        swap((&Traverse_Node_1->Data),(&Traverse_Node_2->Data));
    }
}


