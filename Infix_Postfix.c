/*
COURSE : DATA STRUCTURES IN C
LAB 1: INFIX TO POSTFIX CONVERSION

*/


#include<stdio.h>
#include<stdlib.h> /*declares various utility functions for type 
conversions, memory allocation, algorithms, and other similar use cases.*/
#include<string.h>

#define MAX 100 /* used to create a name for a numerical, character, or string constant,
 whereas a const object of any type can be declared. */
int count=0;//to count the total charcaters in the stack//

// 1. CREATE A STRUCTURE AND NAME IT//

struct stack{
    char items[MAX];
    int top;
};
typedef struct stack st;

// 2. CREATING STACK//
void createstack(st*s){
    s->top = -1; //starting at -1//
}

//2. TO CHECK IF STACK I ALREADY EMPTY//
int isempty(st*s){
    if(s->top== -1){ 
        return 1; //-1 says it is empty so it will return true else false//
    }
    return 0;
}

//3. TO CHECK IF THE STACK IS ALREADY FULL//
int isfull(st*s){
    if(s->top==MAX-1){ //values start from 0 to the MAX value hence MAX-1//
        return 1;
    }
    return 0;
}

//4. TO PUSH (ADD) VALUES INTO THE STACK//
void pushvalue(st*s,char ch){ //the value will be character type//
     if(isfull(s)){
        printf("STACK OVERFLOW: STACK IS ALREADY FULL!\n");
        exit(0);
     }
     else{
        s->top++; // top goes from -1 to 0 and adds the value//
        s->items[s->top]=ch;
     }
     count++;
}

//5. TO PUSH (REMOVE) THE VALUES FROM THE STACK//
void popvalue(st*s){
    if(isempty(s)){
        printf("STACK UNDERFLOW:  STACK IS EMPTY! \n");
        exit(0);
    }
    else{
        s->top--; //stack values decreements by 1//
    }
    count--;
}

//6. TO GET THE PRECEDENCE //
int getprecedence(char ch){
    //giving priority values using conditions //
    if(ch=='^') 
    return 3; //top priority//
    else if(ch=='*' || ch=='/')
    return 2; // second priority |  both have same //
    else if(ch=='+' || ch=='-')
    return 1; // third priority |  both have same //
    else
    return 0;
}

//7. TO PRINT THE STACK VALUES //
int printstack(st*s){
    int i=0;
    for(i=0;i<count-1;i++){
        printf("%c",s->items[i]);
    }
}

//8. THE MAIN FUNCTION TO MAKE PROGRAM WORKING//
int main(){
    st*s=(st*)malloc(sizeof(st)); //dynamic memory allocation//
    createstack(s);
    char infix[]="(A+B)*C+(D-E)/F+G"; //given infix expression to be converted//
    int j=0;
    int i=0;
    char postfix[sizeof(infix)]; 
    for( i=0;i<strlen(infix);i++){
        if(infix[i]=='('){ //when opening prantheses is encountered ,add it to postfix expression//
            pushvalue(s,infix[i]);
        }
        else if(infix[i]=='^' || infix[i]=='*' || infix[i]=='/' || infix[i]=='+' || infix[i]=='-'){
            if(getprecedence(infix[i])<=getprecedence(s->items[s->top])){ //comparing priority values//
                postfix[j]=s->items[s->top];
                j++;
                popvalue(s); //remove the value from the stack with higher priority//
                pushvalue(s,infix[i]); //push the lower priority precendence to the stack//
            }
            else{
                pushvalue(s,infix[i]);
            }
        }
            else if(infix[i]==')'){ //when closing parantheses is encountered, keep on adding values until opening is there//
                while(s->items[s->top]!='('){
                    postfix[j]=s->items[s->top];
                    j++;
                    popvalue(s);
                }
                popvalue(s);
            }
            else{
                postfix[j]=infix[i];
                j++;
            }

        }
        while(!isempty(s)){ //until the stack is empty keep adding values to postfix//
            postfix[j]=s->items[s->top];
            j++;
            popvalue(s);
        }
        postfix[j]='\0';
        printf("EXPRESSION |  INFIX: %s \n\n",infix); //print infix expression//
        printf("ANSWER | POSTFIX: %s\n\n",postfix); //print postfix expression//
    }
