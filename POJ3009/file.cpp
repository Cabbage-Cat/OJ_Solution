#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAX_N 25

using namespace std;
int mov_x[4]={0,0,-1,1},mov_y[4]={1,-1,0,0};

int maze[MAX_N][MAX_N];
int begin_x,begin_y;
int X,Y;
int flag;
void dfs(int x,int y,int s);

int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ3009\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ3009\\file.out","w",stdout);

    while (~scanf("%d %d ",&Y,&X) && X!=0 && Y!=0)
    {
        flag=0;
        for (int i=0;i<X;i++)
            for (int j=0;j<Y;j++)
            {
                scanf("%d ",&maze[i][j]);
                if (maze[i][j] == 2)
                {
                    begin_x=i;begin_y=j;
                }
            }
        dfs(begin_x,begin_y,1);
        if (flag==0)
            printf("-1\n");
        else
            printf("%d\n",flag);
    }

    // fclose(stdin);fclose(stdout);
    return 0;
}

void dfs(int x,int y,int s)
{
    if (s>10)
        return;
    for (int i=0;i<4;i++)
    {
        int dx=x+mov_x[i],dy=y+mov_y[i];
        while(dx>=0 && dx<X && dy>=0 && dy<Y &&maze[dx][dy]!=1)
        {
            if (maze[dx][dy] == 3)
            {
                if (flag==0)
                    flag=s;
                else
                {
                    if (flag>s)
                        flag=s;
                }
                return;
            }
            dx+=mov_x[i],dy+=mov_y[i];
        }
        if (dx>=0 && dx<X && dy>=0 && dy<Y)
        {
            if (!((abs(dx-x)==1 && dy==y) || (dx==x && abs(dy-y)==1)))
            {
                maze[dx][dy] = 0;
                dx-=mov_x[i],dy-=mov_y[i];
                dfs(dx,dy,s+1);
                maze[dx+mov_x[i]][dy+mov_y[i]]=1;
            }
        }
    }
}
