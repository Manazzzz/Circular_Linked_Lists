void del_nth()
{
    int pos;
    printf("Position to be deleted : ");
    scanf("%d",&pos);
    
    if(last==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if(pos==1)
    {
        struct node* temp = last->next;
        last->next=temp->next;
        free(temp);
        return;
    }
    else
    {
        struct node* temp = last->next;
        struct node* prev = NULL;
        
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}
