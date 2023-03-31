#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int adjMatrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int n;

typedef struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;


typedef struct Stack
{
    int items[MAX_SIZE];
    int top;
} Stack;


void enqueue(Queue *q, int);
int dequeue(Queue *q);
bool isQueueEmpty(Queue *q);


void push(Stack *s, int);
int pop(Stack *s);
bool isStackEmpty(Stack *s);

void BFS(int start);
void DFS(int start);


void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow.\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int value;
    if (isQueueEmpty(q))
    {
        printf("Queue underflow.\n");
        value = -1;
    }
    else
    {
        value = q->items[q->front];
        q->front++;
    }
    return value;
}

bool isQueueEmpty(Queue *q)
{
    return q->front > q->rear;
}


void push(Stack *s, int value)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s)
{
    int value;
    if (isStackEmpty(s))
    {
        printf("Stack underflow.\n");
        value = -1;
    }
    else
    {
        value = s->items[s->top];
        s->top--;
    }
    return value;
}


bool isStackEmpty(Stack *s)
{
    return s->top == -1;
}

void BFS(int start)
{
    int i;
    Queue q;
    q.front = 0;
    q.rear = -1;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS traversal: ");
    while (!isQueueEmpty(&q))
    {
        int curr = dequeue(&q);
        printf("%c ", curr + 'A');

        for (i = 0; i < n; i++)
        {
            if (adjMatrix[curr][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void DFS(int start)
{
    int i;

    Stack s;
    s.top = -1;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    push(&s, start);

    printf("DFS traversal: ");
    while (!isStackEmpty(&s))
    {
        int curr = pop(&s);
        printf("%c ", curr + 'A');

        for (i = n - 1; i >= 0; i--)
        {
            if (adjMatrix[curr][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                push(&s, i);
            }
        }
    }
    printf("\n");
}

void printAdj(){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    while (1)
    {
        int input;
        printf("\nBFS using Queue & DFS using Stack:\n");
        printf("Press 1 for Adjacency Matrix\n");
        printf("Press 2 for BFS\n");
        printf("Press 3 for DFS\n");
        printf("Press 4 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("ADJACENCY MATRIX\n");
                printAdj();
                break;
            case 2:
                printf("ENTER THE STARTING VERTEX\n");
                printf("A = 0\nB = 1\nC = 2.....\n");
                printf("VERTEX: ");
                scanf("%d", &input);
                BFS(input);
                break;
            case 3:
                printf("ENTER THE STARTING VERTEX\n");
                printf("A = 0\nB = 1\nC = 2.....\n");
                printf("VERTEX: ");
                scanf("%d", &input);
                DFS(input);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
