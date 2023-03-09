/*
         2 2 4 7 1 5 3
         DSC - LAB 4
         LINEAR AND BINARY SEARCH
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n=6;
int a[];
int value;

//LINEAR SEARCH IS ONE OF THE SIMPLEST SEARCHING TECHNQIUES IN WHICH WE TRAVERSE THE LIST AND MATCH THE NUMBER// 
void linear()
{

    for(int i=0;i<n;i++)
    {
        if(a[i]==value) ///IF THE NUMBER TO BE FOUND MATCHES WITH THAT IN THE LIST//
        {
            printf("\nIT'S PRESENT IN THE LIST!\n\n\nINDEX: %d",i);
        }
        else{
            return;
        }
        
    }

}
 //FOR THE BINARY SEARCH WE INITIALIZE MERGE SORT//
int swap(int x,int y)
{
    int temp=x;//ASSIGNING TEMPORARY VARIABLE THE VALUE OF X//
    x=y;
    y=temp; //Y GETS THE VALUE OF X//
}


//WE FOLLOW SORTING IN ASCENDING ORDER TO FOLLOW UP WITH THE BINARY SEARCH//
void sort()
{
    int i,j;
    for(i=0;i<n-1;i++) //LOOPING TO CHECK A NUMBER WITH THE FOLLOWING VALUES//
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]); //SWAPPING IF THE NUMEBRS ARE NOT SORTED//
            }
        }
    }
}

//BINARY SEARCH BEGINS//
//IN BINARY SEARCH WE FOLLOW DIVIDE AND CONQUER TECHNIQUE//
int binary(int a[],int l,int r,int value)
{
    printf("\n\nTHIS IS THE BINARY SEARCH PROGRAM\n\n");
    sort();
    if(r>=l)
    {
        int mid=l+(r-l)/2; //FINDIN THE MID VALUE USING THE LEFT INDEX AND THE RIGHT INDEX OF THE ARRAY//

        if(a[mid]==value) //IF THE VALUE MATCHES WITH THE MID VALUE//
        {
            return mid;
        }

        if(a[mid]>value) //IF THE ARRAY IS GREATER THAN VALUE TO BE FOUND THEN DIVIDE THE LEFT SUB-ARRAY//
        {
            return binary(a,l,mid-1,value);
        }
        // ELSE DIVIDE THE RIGHT SUB-ARRAY AND OCNTINUE THE SAME DUVUDE AND CONQUER TECHNIQUE//
        return binary(a,l,mid+1,value);
    }
    return -1;
}

//MENU DRIVEN MAIN PORGRAM//
int main()
{
    int choice; //CHOICE FOR THE MENU//
    int answer;
    printf("RANDOM LIST OF NUMBERS :\n\n"); //GENERATING A RANDOM LIST OF NUMEBRS SAME FOR BOTH THE BIANRY AND LINEAR SEARCH//
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100; //NUMBERS RANGING BETWEEN 0-100//
        printf("%d\t\t",a[i]);
    }
    value=41;
    printf("\n\nNUMBER TO BE SEARCHED: %d\n",value);
    a: //RETURN TO A//
    printf("\nCHOOSE: \n\n1.LINEAR SEARCH\t\t2.BINARY SEARCH\t\t3.EXIT\n\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        linear();
        goto a;
        break;

        case 2:
       answer= binary(a,0,n-1,value);
        (answer == -1) ? printf("Element is not present"
                            " in array")
                   : printf("Element is present at "
                            "index %d",
                            answer);

        case 3:
        exit(0);
        break;

        case 4:
        printf("INVALID!");
        goto a;
        break;

        default: 
        printf("INVALID!");
    }
    
}
