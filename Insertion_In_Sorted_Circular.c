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


struct node* insertSorted(struct node* last, int value) {
    struct node* newNode = getNode(value);
    if (!newNode) return last;

    
    if (!last) {
        newNode->next = newNode;  
        return newNode;
    }

    struct node* current = last->next;  
    struct node* prev = last;

   
    if (value <= current->info) {
        newNode->next = current;
        prev->next = newNode;
        return last;
    }

    
    do {
        if (current->info >= value) {
            prev->next = newNode;
            newNode->next = current;
            return last;
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    
    prev->next = newNode;
    newNode->next = current;
    
    return last;
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
    
    struct node* last = getNode(6);
    last->next = getNode(2);
    last->next->next = getNode(4);
    last->next->next->next = last; 

    
    printf("List before insertion:\n");
    print(last);

    
    last = insertSorted(last, 3);


    printf("List after insertion:\n");
    print(last);

    return 0;
}
