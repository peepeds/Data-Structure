#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define size 3

int arr[size],rear=-1,front=0, tmp = 0 ; 

void enQueue(){
    if(tmp == size){
        printf("Queue penuh!\n");
    } else {
        int data ;
        printf("Masukkan data: ");
        scanf("%d",&data);
        rear = (rear+1)%size ; 
        arr[rear] = data ;
        tmp++;
    }
    printf("tekan enter untuk kembali ke menu awal\n");
    getchar();
}

void deQueue(){
    if(tmp==0){
        printf("Queue kosong!\n");
        
    } else {
        printf("Data yang akan dihapus adalah : %d\n",arr[front]);
        front = (front+1)%size ;
        tmp--;
    }
    printf("tekan enter untuk kembali ke menu awal\n");
    getchar();
}

void display(){
    if(tmp==0){
        printf("Queue kosong!\n");
    } else {
        int x = front ; 
        for(int i =0 ; i < tmp ;i++){
            printf("%d\n",arr[x]);
            x=(x+1)%size;
        }
    }
    printf("tekan enter untuk kembali ke menu awal\n");
    getchar();
}
int main(){
    int ch, data , counter = 0 ;; 
    do{
        if (counter !=0) getchar();
        counter++;
        system("clear");		
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                enQueue();
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong Choice");
                getchar();	// pause the loop to see the message
        }
    } while(ch!=4);
    return 0;
}