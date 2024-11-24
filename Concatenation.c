#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* getNode(int n) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    p->info = n;
    p->next = NULL;
    return p;
}


struct node* concatenate(struct node* l1, struct node* l2) {
    
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    
    
    struct node* last1 = l1;
    while (last1->next != l1) {
        last1 = last1->next;
    }
    
    
    struct node* last2 = l2;
    while (last2->next != l2) {
        last2 = last2->next;
    }
    
    
    last1->next = l2;
    
    
    last2->next = l1;
    
    
    return l1;
}


void print(struct node* last) {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = last->next;
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    
    struct node* l1 = getNode(0);
    l1->next = getNode(1);
    l1->next->next = getNode(2);
    l1->next->next->next = l1;  

   
    struct node* l2 = getNode(3);
    l2->next = getNode(4);
    l2->next->next = getNode(5);
    l2->next->next->next = l2; 

   
    struct node* c = concatenate(l1, l2);

   
    printf("List after concatenation:\n");
    print(c);

    return 0;
}
