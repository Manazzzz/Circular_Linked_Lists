void insert_nth()
{
    int n;
    printf("Enter value to be inserted : ");
    scanf("%d",&n);
    int pos;
    printf("Position at which it is to be inserted : ");
    scanf("%d",&pos);
    
    struct node* new_node = getNode(n);
    
    if(new_node==0)
    {
        return;
    }
    else if(last==NULL)
    {
        last=new_node;
        last->next=last;
        return;
    }
    else if(pos==0)
    {
        new_node->next=last->next;
        last->next=new_node;
    }
    else
    {
        struct node* temp=last->next;
        for(int i=0;i<(pos-1);i++)
        {
            if(temp==NULL)
            {
                printf("Out of bounds\n");
                return;
            }
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}
