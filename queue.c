#include<stdio.h>
#include<stdlib.h>
#define max 5

int front=-1; //deletion of items happpens at rear//
int rear=-1; //insertion happens at rear//
int q[max]; //the queue is stored in the form of an array//

void insert()
{
    int value;
    printf("ENTER VALUE TO INSERT: \t");
    scanf("%d",&value);
    if(rear==max-1){           //starting from zero is rear = max -1 then the queue is already full//
        printf("OVERFLOW!\n");
        return;
    }
    else{
        rear=rear+1; // rear=-1; after insertion rear=0//
    }
    q[rear]=value;
    printf("INSERTED!");
}

void delete()
{
    int value;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=front+1; //removes the element from fron of the queue//
    }
    printf("VALUE DELETED!");
}

void show()
{
    printf("QUEUE: \n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n\n",q[i]);
    }
}

int main()
{
    int option;
    a:
    printf("CHOOSE:\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n"); // switch case//
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        insert();
        goto a; 
        break;
        case 2:
        delete();
        goto a;
        break;
        case 3:
        show();
        goto a;
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("INVALID INPUT!\n");
    }
}
