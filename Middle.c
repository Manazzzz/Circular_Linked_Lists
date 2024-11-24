void middle()
{
    struct node* slow = last->next;
    struct node* fast = last->next;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }while(fast->next!=last->next && fast!=last->next);
    printf("Middle node : %d\n",slow->info);
}
