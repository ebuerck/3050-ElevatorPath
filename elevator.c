#include <stdio.h>
#include <stdlib.h>

#define MAXFLOORS 100
//Keeps Track of connections
int Graph[MAXFLOORS][MAXFLOORS];\
void SetupGraph(int Up, int Down);

int main(void)
{
    SetupGraph(12,2);
    

}

void SetupGraph(int Up, int Down)
{
    int upHold, downHold;
    //Initilize Graph to 0
    for(int i = 0;i < MAXFLOORS; i++)
    {
        for(int j = 0;j < MAXFLOORS; j++)
            Graph[i][j] = 0;
    }

    //Setup all Connections
    for(int i = 0;i < MAXFLOORS; i++)
    {
        upHold = i + Up;
        downHold = i - Down;

        //printf("uphold is %d and downhold is %d\n",upHold,downHold);

        if(upHold < MAXFLOORS)
        {
            Graph[i][upHold] = 1;
        }

        if(downHold >= 0)
        {
            Graph[i][downHold] = 1;
        } 
    }

    
}