#include <stdio.h>
#include <stdlib.h>

#define MAXFLOORS 100
//Keeps Track of connections
int Graph[MAXFLOORS][MAXFLOORS];
void SetupGraph(int floors,int Up, int Down);
int* BST(int start,int goal,int floors);



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

    /*
    for(int i = 0;i < floors;i++)
    {
        printf("Graph[%d] connections: ",i);
        for(int j = 0; j<floors;j++)
        {
            if(Graph[i][j] == 1)
                printf("%d ,",j);
        }
            

        printf("\n");
    }
    */

    int * hold = BST(start,goal,floors);
    

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

int* BST(int start,int goal,int floors)
{
    int queue[floors], visited[floors];
    int rear = -1;
    int front = 0;
    int queueCount = 0;
    int visitedcount = 0;

    visited[visitedcount] = start;

    for(int i = 0; i<floors ;i++)
    {
        if(Graph[start][i] == 1)
        {
            printf("adding %d to queue and the start is %d\n",i, start);
            queue[front] = i;
            front++;
        }
    }



}
