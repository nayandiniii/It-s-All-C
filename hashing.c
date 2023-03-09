#include<stdio.h>
#define size 8
int arr[size];

void initialize()
{
    for (int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
}

void insert(int value)
{
    int key;
    key=value%size;
    for(int i=0;i<size;i++)
    {
        arr[key]=value;
    }
}

void delete(int value)
{
    int key=value%size;
    if(arr[key]==value)
    {
        arr[key]=-1;
    }
    else{
        printf("\n CANNOT DELETE THE VALUE :%d!\n\n",value);
    }
}

void search(int value)
{
    int key=value%size;
    for(int i=0;i<8;i++)
    {
       if(arr[key]==value)
    {
        printf("\nVALUE %d FOUND AT %d\n\n",value,key);
    }
    else{
        printf("\n %d IS NOT PRESENT!\n\n",value);

    }
    }

}

void display()
{
    for (int i=0;i<size;i++)
    {
        printf("%d,",arr[i]);
        printf("\t");
    }
    printf("\n\n");

}

int main()
{
    initialize();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    search(4);
    display();
    delete(2);
    search(2);
    insert(6);
    display();
}
