void del_last()
{
    if(last==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if(last->next==last)
    {
        free(last);
        last=NULL;
        return;
    }
    else
    {
        struct node* temp = last->next;
        struct node* prev =NULL;
        while(temp->next!=last->next)
        {
            prev=temp;
            temp=temp->next;
        }
            prev->next=last->next;
            free(temp);
            last=prev;
            
            return;
    }
}
