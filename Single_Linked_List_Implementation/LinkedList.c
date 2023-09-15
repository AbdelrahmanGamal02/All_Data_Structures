
#include "LinkedList.h"

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
    Node_Type *Traverse_ptr = Head_List;
    uint32 Middle = 0;
    uint32 Length_List = Get_Length(Head_List);
    if(NULL == Head_List)
    {
        printf("PASSED_NULL_POINTER \n");
        Middle = 0;
    }
    else
    {
        Middle = ceil((Length_List / 2.0));
        while(--Middle)
        {
            Traverse_ptr = Traverse_ptr->Next_Node;
        }
        Middle = Traverse_ptr->Data;
    }


    return Middle;
}


State_Type Insert_Node_At_Begining (Node_Type **Head_List,uint32 Data)
{
    State_Type State = LINKEDLIST_NOK;
    /*create new node */
    Node_Type *New_Node = NULL;
    New_Node = (Node_Type *)malloc(sizeof(Node_Type));
    if(NULL != New_Node)
    {
        /*initialize element of new node */
        New_Node->Data = Data;
        New_Node->Next_Node = NULL;
        /*Validation if linked list empty or not*/
        if(NULL == *Head_List)
        {
            /* linked list empty */
            *Head_List = New_Node;
        }
        else
        {
            New_Node->Next_Node = *Head_List;
            *Head_List = New_Node;
        }
        State = LINKEDLIST_OK;
    }
    else
    {
        printf("Can't Allocated\n");
        State = LINKEDLIST_NOK;
    }

    return State;

}

State_Type Insert_Node_At_End (Node_Type *Head_List,uint32 Data)
{
    State_Type State = LINKEDLIST_NOK;

    Node_Type *New_Node = NULL;
    Node_Type *Traverse_ptr = NULL;
    /* create new node */
    New_Node = (Node_Type *)malloc(sizeof(Node_Type));
    /* validation that node is created */
    if(NULL != New_Node)
    {
        /*initialize element of new node */
        New_Node->Data = Data;
        New_Node->Next_Node = NULL;
        /*Validation if linked list empty or not*/
        if(NULL == Head_List)
        {
            /* linked list empty */
            State = Insert_Node_At_Begining(&Head_List ,Data);
        }
        else
        {
            Traverse_ptr = Head_List;
            while(Traverse_ptr->Next_Node != NULL)
            {
                Traverse_ptr = Traverse_ptr->Next_Node;
            }
            Traverse_ptr->Next_Node = New_Node;
        }
        State = LINKEDLIST_OK;
    }
    else
    {
        printf("Can't Allocated\n");
        State = LINKEDLIST_NOK;
    }
    /*traverse pointer finish his task  */
    Traverse_ptr = NULL;

    return State;
}

State_Type Insert_Node_After_Node (Node_Type *Head_List, uint32 Data, uint32 postion)
{
    State_Type State = LINKEDLIST_NOK;
    uint32 check_postion = Get_Length(Head_List);
    if(postion > check_postion)
    {
        printf("Position Not Correct \n");
        State = LINKEDLIST_NOK;
    }
    else
    {
        Node_Type *Traverse_ptr = Head_List;
        Node_Type *New_Node = NULL;

        New_Node = (Node_Type *)malloc(sizeof(Node_Type));
        if(NULL != New_Node)
        {
            if(postion == check_postion)
            {
                /* insert node at the end of linked list */
                State = Insert_Node_At_End(Head_List,Data);
                if(State != LINKEDLIST_OK)
                    {return (LINKEDLIST_NOK);}
            }
            /* if Linked list is empty */
            else if(NULL == Head_List)
            {
                State = Insert_Node_At_Begining(&Head_List,Data);
                if(State != LINKEDLIST_OK)
                    {return (LINKEDLIST_NOK);}
            }
            else
            {
                New_Node->Data = Data;
                New_Node->Next_Node = NULL;
                while( --postion )
                {
                    Traverse_ptr = Traverse_ptr->Next_Node;
                }
                New_Node->Next_Node = Traverse_ptr->Next_Node;
                Traverse_ptr->Next_Node = New_Node;
            }
            State = LINKEDLIST_OK;

            /*traverse pointer finish his task  */
            Traverse_ptr = NULL;
        }
        else
        {
            printf("Can't Allocated\n");
            State = LINKEDLIST_NOK;
        }
    }

    return State;
}


State_Type Insert_Node_Before_Node (Node_Type **Head_List, uint32 Data, uint32 postion)
{
    State_Type State = LINKEDLIST_NOK;
    uint32 check_postion = Get_Length(*Head_List);
    if(postion > check_postion)
    {
        printf("Position Not Correct \n");
        State = LINKEDLIST_NOK;
    }
    else
    {
        Node_Type *Traverse_ptr = *Head_List;
        Node_Type *New_Node = NULL;

        New_Node = (Node_Type *)malloc(sizeof(Node_Type));
        if(NULL != New_Node)
        {
            /* let first node is 1 so he want to insert node at Begining*/
            if(1 == postion || NULL == Head_List)
            {
                /* insert node at the end of linked list */
                State = Insert_Node_At_Begining(Head_List,Data);
                if(State != LINKEDLIST_OK)
                    {return (LINKEDLIST_NOK);}
            }
            else
            {
                New_Node->Data = Data;
                New_Node->Next_Node = NULL;
                /* to make Traverse ptr point on the node before position */
                postion-- ;
                while( --postion )
                {
                    Traverse_ptr = Traverse_ptr->Next_Node;
                }
                New_Node->Next_Node = Traverse_ptr->Next_Node;
                Traverse_ptr->Next_Node = New_Node;
            }
            State = LINKEDLIST_OK;

            /*traverse pointer finish his task  */
            Traverse_ptr = NULL;
        }
        else
        {
            printf("Can't Allocated\n");
            State = LINKEDLIST_NOK;
        }
    }

    return State;
}


uint32 Delete_Node_At_Begining (Node_Type **Head_List)
{
    uint32 Deleted_Data = 0;
    Node_Type *Delete_ptr = NULL;
    if(NULL == *Head_List)
    {
        printf("LINKEDLIST_EMPTY \n");
    }
    else
    {
        Delete_ptr = *Head_List;
        *Head_List = (*Head_List)->Next_Node;
        Deleted_Data = Delete_ptr->Data;
        /* free node */
        free(Delete_ptr);
        Delete_ptr = NULL;
    }

    return Deleted_Data;
}

uint32 Delete_Node_At_End (Node_Type *Head_List)
{
    uint32 Deleted_Data = 0;
    Node_Type *Deleted_Node_ptr = NULL;
    Node_Type *Last_Node_ptr = NULL;
    if(NULL == Head_List)
    {
        printf("LINKEDLIST_EMPTY \n");
    }
    else
    {
        Last_Node_ptr = Head_List;
        /* traverse until reach to the node before last node */
        while(Last_Node_ptr->Next_Node->Next_Node != NULL)
        {
            Last_Node_ptr = Last_Node_ptr->Next_Node;
        }
        Deleted_Node_ptr = Last_Node_ptr->Next_Node;
        Last_Node_ptr->Next_Node = NULL;
        /* deleted data*/
        Deleted_Data = Deleted_Node_ptr->Data;
        /* free node */
        free(Deleted_Node_ptr);
        Deleted_Node_ptr = NULL;
    }

    return Deleted_Data;
}


uint32 Delete_node_In_Specific_position (Node_Type *Head_List , uint32 position)
{
    uint32 Deleted_Data = 0;
    Node_Type *Deleted_Node_ptr = NULL;
    Node_Type *Traverse_ptr = NULL;
    uint32 check_position = Get_Length(Head_List);
    if(position > check_position)
    {
        printf("Position Not Correct \n");
    }
    else
    {
        /* if position is the first node */
        if(1 == position)
        {
            Delete_Node_At_Begining(&Head_List);
        }
        /* if position is the last node */
        else if(position == check_position)
        {
            Delete_Node_At_End(Head_List);
        }
        else
        {
            Traverse_ptr = Head_List;
            /* to make Traverse ptr point on the node before position */
            position-- ;
            while(--position)
            {
                Traverse_ptr = Traverse_ptr->Next_Node;
            }

            Deleted_Node_ptr = Traverse_ptr->Next_Node;
            Traverse_ptr->Next_Node = Deleted_Node_ptr->Next_Node;

            Deleted_Data = Deleted_Node_ptr->Data;
            Deleted_Node_ptr->Next_Node = NULL;
            free(Deleted_Node_ptr);
            Deleted_Node_ptr = NULL;
        }
    }

    return Deleted_Data;
}


void Display_Nodes(Node_Type *Head_List)
{
    Node_Type *Traverse_ptr = Head_List;
    printf("Data In The Linked List : ");
    while(Traverse_ptr != NULL)
    {
        printf("%i\t",Traverse_ptr->Data);
        Traverse_ptr = Traverse_ptr->Next_Node;
    }
    printf("\n");
}

void Delete_List (Node_Type **Head_List)
{
    Node_Type *Deleted_Node_Ptr = NULL;
    while(NULL != *Head_List)
    {
        Deleted_Node_Ptr = *Head_List;
        *Head_List = (*Head_List)->Next_Node;

        Deleted_Node_Ptr->Next_Node = NULL;
        free(Deleted_Node_Ptr);
        Deleted_Node_Ptr = NULL;
    }
    free(*Head_List);
}

uint32 Delete_The_Middle (Node_Type *Head_List)
{
    uint32 Deleted_Data = 0 , Length = Get_Length(Head_List);
    uint32 Middle_position = ceil((Length / 2.0));
    Node_Type *Deleted_Middle_Node_Ptr = NULL;
    Node_Type *Traverse_Ptr = Head_List;
    /* to make Traverse ptr point on the node before position */
            Middle_position-- ;
    while( --Middle_position )
    {
        Traverse_Ptr = Traverse_Ptr->Next_Node;
    }
    Deleted_Middle_Node_Ptr = Traverse_Ptr->Next_Node;
    Traverse_Ptr->Next_Node = Deleted_Middle_Node_Ptr->Next_Node;

    /* free node */
    Deleted_Middle_Node_Ptr->Next_Node = NULL;
    Deleted_Data = Deleted_Middle_Node_Ptr->Data;
    free(Deleted_Middle_Node_Ptr);
    Deleted_Middle_Node_Ptr = NULL;

    return Deleted_Data;
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
  //11    22      2       10      3       66
void Sort_The_Nodes_Ascending (Node_Type *Head_List)
{
    Node_Type *Traverse_Node_1 = Head_List;
    Node_Type *Traverse_Node_2 = NULL;
    while(NULL != Traverse_Node_1)
    {
        Traverse_Node_2 = Head_List;
        while((Traverse_Node_1->Data >= Traverse_Node_2->Data) && (NULL != Traverse_Node_2->Next_Node))
        {
            Traverse_Node_2 = Traverse_Node_2->Next_Node;
        }

        if(Traverse_Node_2->Data > Traverse_Node_1->Data)
        {
            swap((&Traverse_Node_2->Data),(&Traverse_Node_1->Data));
        }
        else{ /* nothing */}

        Traverse_Node_1 = Traverse_Node_1->Next_Node;
    }
}

void Reverse_The_List (Node_Type **Head_List)
{
    Node_Type *Next_Node_Ptr = NULL;
    Node_Type *Current_Node_Ptr = *Head_List;
    Node_Type *Pre_Node_Ptr = NULL;

    while(Current_Node_Ptr != NULL)
    {
        /* store next */
        Next_Node_Ptr = Current_Node_Ptr->Next_Node;
        /* reverse the pointer of current node */
        Current_Node_Ptr->Next_Node = Pre_Node_Ptr;
        /* adjust the positions of pointers */
        Pre_Node_Ptr = Current_Node_Ptr;
        Current_Node_Ptr = Next_Node_Ptr;

    }

    *Head_List = Pre_Node_Ptr;
}






