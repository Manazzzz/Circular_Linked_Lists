void insert_end()
{
    
    int n;
    printf("Value to be inserted : ");
    scanf("%d",&n);
    struct node* new_node = getNode(n);
    
    
    if(new_node==NULL)
    {
        return;
    }
    if(last==NULL)
    {
        last=new_node;
        last->next=last;
    }
    else
    {
        new_node->next=last->next;
        last->next=new_node;
        last=new_node;
    }
}
