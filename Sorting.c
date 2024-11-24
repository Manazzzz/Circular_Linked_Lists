void sort()
{
    if(last==NULL|| last->next==last)
    {
        printf("Not possible");
    }
    else
    {
        struct node* temp1= last->next;
        struct node* temp2 = NULL;
        int x;
        do
        {
            temp2=temp1->next;
            do
            {
                if(temp1->info>temp2->info)
                {
                    x=temp1->info;
                    temp1->info=temp2->info;
                    temp2->info=x;
                }
                temp2=temp2->next;
            }while(temp2!=last->next);
            temp1=temp1->next;
        }while(temp1!=last);
    }
}
