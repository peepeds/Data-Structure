#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32
    #define CLS system("cls")
#else
    #define CLS system("clear")
#endif
struct node {
    int data ;
    struct node *next ;
}; 

struct node *head , *tail , *cur , *del , *before , *newNode ; 

void pushHead(int data){
    if(!head){
        head = (struct node*) malloc(sizeof(struct node));
        head->data = data ;
        tail = head ; 
        tail->next = head ; 
    } else {
        newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data ; 
        newNode->next = head ; 
        head = newNode ;
    }
}

void pushTail(int data){
    if(!head){
        pushHead(data);
    } else {
        newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data ; 
        tail->next = newNode ; 
        tail = newNode ;
        tail->next = head ; 
    }
}

void pushMid(int data){
    if(!head){
        pushHead(data);
    } else {
        if(data < head->data){
            pushHead(data);
        } else if (data > tail->data){
            pushTail(data);
        } else {
            cur = head ; 
            newNode = (struct node*) malloc(sizeof(struct node));
            newNode->data = data ; 
            while(cur->next->data < newNode->data){
                cur = cur->next ;
            }
            newNode->next = cur->next ; 
            cur->next = newNode ; 
        }
    }
}

void popHead(){
    if(!head){
        printf("Linked List Kosong!\n");
    } else {
        del = head  ;
        head = head->next ;
        tail->next = head ; 
        free(del);
    }
}

void popTail(){
    if(!head){
        printf("Linked List Kosong!\n");
    } else {
        del = tail ; 
        cur = head ; 
        while(cur->next != tail){
            cur = cur->next ;
        }
        before = cur ; 
        tail = before ;
        tail->next = head ; 
        free(del);
    }
}

void popMid(int data){
    if(!head){
        printf("Linked List Kosong!\n");
    } else {
        if(head->data == data){
            popHead();
        } else if (tail->data == data){
            popTail();
        } else if (data < head->data || data > tail->data){
            printf("Data %d tidak ditemukan !\n",data);
            getchar();
        } else {
            cur = head ; 
            while(cur->next->data != data){
                cur = cur->next  ;
                if(cur == tail) {
                    printf("Data tidak ditemukan!\n");  getchar();
                    break ;
                }
            }
            if(cur != tail){
                del = cur->next ; 
                before = cur ; 
                before->next = del->next ; 
                free(del);
            }
        }
    }
}

void print(){
    cur = head ;
    printf("Keseluruhan Data!\n");
    printf("    Data = %d ",cur->data);
    while(cur->next != head){
        cur = cur->next;
        printf("    Data = %d ",cur->data);
       
    }
   
    printf("\n");
    //getchar();
}
int main(){
   
    
    int choice  , data ; 
    do{    CLS ;
        printf("\n+--------------+\n");
        printf("|     Menu     |\n"); 
        printf("+--------------+\n");
        printf("|1. Push Head  |\n");
        printf("|2. Push Mid   |\n");
        printf("|3. Push Tail  |\n");
        printf("|4. Pop Head   |\n");
        printf("|5. Pop Mid    |\n");
        printf("|6. Pop Tail   |\n");
        printf("|7. Display    |\n");
        printf("|8. Exit       |\n");
        printf("+--------------+\n\n");
        printf("Masukkan pilihan : ") ;
        scanf("%d",&choice); 

        switch (choice){
            case 1 : 
                printf("Masukkan data : ");
                scanf("%d",&data);
                pushHead(data);
                getchar();
                break;
            case 2 : 
                printf("Masukkan data : ");
                scanf("%d",&data);
                pushMid(data);
                getchar();
                break;
            case 3 : 
                printf("Masukkan data : ");
                scanf("%d",&data);
                pushTail(data);
                getchar();
                break;
            case 4 :
                popHead();
                getchar();
                break;
            case 5 :
                printf("Masukkan data : ");
                scanf("%d",&data);
                popMid(data);
                getchar();
                break;
            case 6 :
                popTail();
                getchar();
                break;
            case 7 : 
                print();
                getchar();
                break ;
            case 8 :
                return 0 ;
                break;
            default :
                printf("Wrong Input....\n");
                getchar();
                getchar();
                break;
        }
    } while (choice != 8) ;

}