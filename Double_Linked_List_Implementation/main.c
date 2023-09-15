
#include "Double_Linked_List.h"


Node_Type *DLinked_List_1 = NULL;


/*TO print element of enum as a string not a number*/
 char *status[2] = {"LINKEDLIST_NOT_OK","LINKEDLIST_OK"};


int main()
{
    uint32 number_of_Nodes = 0 , Deleted_Data = 0,Data_in_middle = 0;
    State_Type State = LINKEDLIST_NOK;
    /* check insert functions */
    State =  Insert_Node_At_Begining(&DLinked_List_1,1);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    State =  Insert_Node_At_Begining(&DLinked_List_1,22);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    State =  Insert_Node_At_End(DLinked_List_1,13);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    State =  Insert_Node_At_End(DLinked_List_1,44);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    State =  Insert_Node_At_End(DLinked_List_1,55);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    /* verify Number of Nodes */
    number_of_Nodes = Get_Length(DLinked_List_1);printf("Number Of Nodes Is => %i\n",number_of_Nodes);

    /* add Node in Specific Position */
    State =  Insert_Node_After_Node(DLinked_List_1, 30 , 5);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
    State =  Insert_Node_Before_Node(&DLinked_List_1, 70 , 1);printf("State is %s \n",status[State]);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);
     printf("------------------------------------------------------------\n");
    /* Start delete check */
    /* let check function find the middle and delete it */
    Data_in_middle = The_Middle_Of_List(DLinked_List_1);
    printf("Data Stored In The Middle => %i \n",Data_in_middle);
    Deleted_Data = Delete_The_Middle(DLinked_List_1);
    printf("Deleted Data which in The Middle => %i \n",Deleted_Data);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);

    Deleted_Data = Delete_Node_At_Begining(&DLinked_List_1);
    printf("Deleted Data from Beginning => %i \n",Deleted_Data);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);

    Deleted_Data = Delete_node_In_Specific_position(DLinked_List_1,2);
    printf("Deleted Data => %i \n",Deleted_Data);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);

    Deleted_Data = Delete_Node_At_End(DLinked_List_1);
    printf("Deleted Data from End => %i \n",Deleted_Data);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);


    printf("-----------------------------------------\n");
    /* Swap 2 Nodes */
    Swap_2Nodes(DLinked_List_1,1,2);
    Display_Nodes_In_Forward_Direction(DLinked_List_1);

    Display_Nodes_In_Reverse_Direction(DLinked_List_1);
    /*Delete The List*/
    Delete_List(&DLinked_List_1);
    number_of_Nodes = Get_Length(DLinked_List_1);
    printf("Number Of Nodes Is => %i\n",number_of_Nodes);





    return 0;
}
