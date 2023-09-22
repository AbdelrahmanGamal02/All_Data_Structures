
#include "LinkedList.h"

Node_Type *Linked_List_1 = NULL;

/*TO print element of enum as a string not a number*/
 char *status[2] = {"LINKEDLIST_NOT_OK","LINKEDLIST_OK"};

int main()
{
    uint32 number_of_Nodes = 0, Data_in_middle = 0 , Deleted_Data =0 ;
    State_Type State = LINKEDLIST_NOK;
    /* check insert functions */
    State =  Insert_Node_At_Begining(&Linked_List_1,1);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    State =  Insert_Node_At_Begining(&Linked_List_1,22);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    State =  Insert_Node_At_End(Linked_List_1,13);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    State =  Insert_Node_At_End(Linked_List_1,44);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    State =  Insert_Node_At_End(Linked_List_1,55);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    /* verify Number of Nodes */
    number_of_Nodes = Get_Length(Linked_List_1);printf("Number Of Nodes Is => %i\n",number_of_Nodes);
    /* add Node in Specific Position */
    State =  Insert_Node_After_Node(Linked_List_1, 30 , 1);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    State =  Insert_Node_Before_Node(&Linked_List_1, 70 , 3);printf("State is %s \n",status[State]);
    Display_Nodes(Linked_List_1);
    printf("------------------------------------------------------------\n");
    /* Start delete check */
    /* let check function find the middle and delete it */
    Data_in_middle = The_Middle_Of_List(Linked_List_1);
    printf("Data Stored In The Middle => %i \n",Data_in_middle);
    Deleted_Data = Delete_The_Middle(Linked_List_1);
    printf("Deleted Data which in The Middle => %i \n",Deleted_Data);
    Display_Nodes(Linked_List_1);

    Deleted_Data = Delete_Node_At_Begining(&Linked_List_1);
    printf("Deleted Data => %i \n",Deleted_Data);
    Display_Nodes(Linked_List_1);

    Deleted_Data = Delete_Node_At_End(Linked_List_1);
    printf("Deleted Data => %i \n",Deleted_Data);
    Display_Nodes(Linked_List_1);

    Deleted_Data = Delete_node_In_Specific_position(Linked_List_1, 2);
    printf("Deleted Data => %i \n",Deleted_Data);
    Display_Nodes(Linked_List_1);
    printf("----------------------------------------------------\n");
    /* reverse Linked List */
    Reverse_The_List(&Linked_List_1);
    Display_Nodes(Linked_List_1);
    /* Swap Two Nodes */
    Swap_2Nodes(Linked_List_1, 2 , 3);
    Display_Nodes(Linked_List_1);
    /* Sort the linked list*/
    Sort_The_Nodes_Ascending(Linked_List_1);
    Display_Nodes(Linked_List_1);
    /* Search about a number on the linked list */
    Postion_Number = Search_on_Linked_List(Linked_List_1, 44);
    if(-1 == Postion_Number)
    {
        printf("Number Not Founded\n");

    }else
    {
        printf("Position Of number founded is %i \n",Postion_Number);
    }
 
    /* Delete the linked list */
    Delete_List(&Linked_List_1);
    number_of_Nodes = Get_Length(Linked_List_1);printf("Number Of Nodes Is => %i\n",number_of_Nodes);




    return 0;
}
