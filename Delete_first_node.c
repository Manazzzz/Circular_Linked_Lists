void del_first()
{
    if(last==NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
    else if(last->next==last)
    {
        free(last);
        last = NULL;
        return;
    }
    else
    {
        struct node* temp = last->next;
        last->next=temp->next;
        free(temp);
        return;
    }
}
