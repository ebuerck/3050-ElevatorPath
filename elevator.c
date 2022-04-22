#include <stdio.h>
#include <stdlib.h>

#define MAXFLOORS 100
//Keeps Track of connections
int Graph[MAXFLOORS][MAXFLOORS];
void SetupGraph(int floors,int Up, int Down);
void BFS(int start,int goal,int floors);

struct queue
{
   int items[MAXFLOORS];
   int front;
   int rear;
};

struct queue* MakeQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);


int main(void)
{
    int floors,start,goal,up,down;
    printf("Enter Values: <Floors> <Start> <Goal> <Up> <Down>: ");
    fscanf(stdin,"%d %d %d %d %d",&floors,&start,&goal,&up,&down);
    printf("\n");

    //Error Checking on Inputed Values
    if(floors > MAXFLOORS)
    {
        printf("ERROR, floor value too high\n");
        return 1;
    }
    if(start < 0 || start > floors)
    {
        printf("ERROR, start not possible\n");
        return 1;
    }
    if(goal < 0 || goal > floors)
    {
        printf("ERROR, goal not possible\n");
        return 1;
    }
    if(up < 0 || down < 0)
    {
        printf("ERROR, Up or Down not possible\n");
        return 1;
    }

    SetupGraph(floors,up,down);

    BFS(start,goal,floors);


}

void SetupGraph(int floors,int Up, int Down)
{
    int upHold, downHold;
    //Initilize Graph to 0
    for(int i = 0;i < floors; i++)
    {
        for(int j = 0;j < floors; j++)
            Graph[i][j] = 0;
    }

    //Setup all Connections
    for(int i = 0;i < floors; i++)
    {
        upHold = i + Up;
        downHold = i - Down;

        if(upHold < floors)
        {
            Graph[i][upHold] = 1;
        }

        if(downHold >= 0)
        {
            Graph[i][downHold] = 1;
        }
    }
}

void BFS(int start,int goal,int floors)
{
   //Make que and array to keep track of where weve been
    struct queue * Que = MakeQueue();
    int visited[floors];
    int parent[floors];
    for(int i = 0;i<floors;i++)
    {
      parent[i] = 0;
      visited[i] = 0;
    }
    visited[start-1] = 1;
    enqueue(Que,start-1);
    while(isEmpty(Que) != 1)
    {
      int current = dequeue(Que);
      if(current +1 == goal)
      {
         for(int i = current;i != start-1;i = i)
         {
            printf("%d <- ",i+1);
            i = parent[i] ;
         }
         printf("%d\n",start);
         return;
      }

      //enquee the other nodes
      for(int i = 0;i<floors;i++)
      {
         //only que if other hasnt been visited current
         if(visited[i] == 0 && Graph[current][i] == 1)
         {
            parent[i] = current;
            visited[i] = 1;
            enqueue(Que,i);
         }
      }
    }
    printf("Take the Stairs\n");
    free(Que);
}

struct queue* MakeQueue()
{
   struct queue* q = malloc(sizeof(struct queue));
   q->front = -1;
   q->rear = -1;
   return q;
}

int isEmpty(struct queue* q)
{
   //Check to see if rear is -1
   if(q->rear == -1)
      return 1;
   return 0;
}

void enqueue(struct queue* q, int data)
{
   if(q->rear < MAXFLOORS -1)
   {
      //check to see if empty first
      if(q->front == -1)
      {
         q->front = 0;
      }
      q->rear++;
      q->items[q->rear] = data;
   }
}

int dequeue(struct queue* q)
{
   int hold;
   //Check to see if empty first
   if(isEmpty(q))
   {
      printf("error empty que\n");
      return -1;
   }
   else
   {
      hold = q->items[q->front];
      q->front++;
      if(q->front > q->rear)
      {
         q->front = q->rear = -1;
      }
   }
   return hold;
}
