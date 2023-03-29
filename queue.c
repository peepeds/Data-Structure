#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ; 
    struct node *next ;
};

struct node *head , *tail , *del , *newNode , *cur; 

void push(int data){
    if(!head){
        head = (struct node*) malloc(sizeof(struct node)) ; 
        head->data = data ; 
        head->next = NULL ;
        tail = head ;
    } else {
        newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data ; 
        newNode->next = NULL ;
        tail->next = newNode ;
        tail = newNode ; 
    }
}

int top(){
    if(!head){
        printf("Queue Kosong!\n");
        return 0 ;
    } else {
        return head->data ; 
    }
}

void pop(){
    if(!head){
        printf("Queue Kosong!\n");
    }else {
        del = head ; 
        head = head->next ; 
        free(del);
    }
}

void display(){
    cur = head ; 
    while(cur != NULL){
        printf("Data : %d\n",cur->data);
        cur = cur->next ; 
    }
}

int main(){
   
    int choice , data ; 
    do{  
        printf("\n+--------------+\n");
        printf("|     Menu     |\n"); 
        printf("+--------------+\n");
        printf("|1. Push       |\n");
        printf("|2. Pop        |\n");
        printf("|3. Top        |\n");
        printf("|4. Display    |\n");
        printf("|5. Exit       |\n");
        printf("+--------------+\n\n");
        printf("Masukkan pilihan : ") ;
        scanf("%d",&choice); 

        switch (choice){
            case 1 : 
                printf("Masukkan data : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2 : 
                pop();
                break;
            case 3 : 
                printf("%d",top());
                break;
            case 4 :
                display();
                break;
            case 5 :
                return 0 ; 
                break;
            default : 
                printf("Wrong Input....\n");
                getchar();
                break;
        }
    } while (choice != 5) ;

}