#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 25

using namespace std;

int X,Y,begin_x,begin_y;
char maze[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int mov_x[4]={0,0,-1,1},mov_y[4]={1,-1,0,0};
int res;
void dfs(int x,int y);

int main()
{
    
    // freopen("F:\\github\\OJ_Solution\\POJ1979\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ1979\\file.out","w",stdout);
    while (~scanf("%d %d ",&Y,&X) && X!=0 && Y!=0)
    {
        res=0;
        for (int i=0;i<MAX_N;i++)
            for (int j=0;j<MAX_N;j++)
                vis[i][j] = 0;
        for (int i=0;i<X;i++)
            for (int j=0;j<Y;j++)
            {
                scanf(" %c",&maze[i][j]);
                if (maze[i][j] == '@')
                    begin_x = i,begin_y=j;
            }
        dfs(begin_x,begin_y);
        printf("%d\n",res);
        
    }
    // fclose(stdin);fclose(stdout);
	return 0;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    res+=1;
    for (int i=0;i<4;i++)
    {
        int dx=x+mov_x[i],dy=y+mov_y[i];
        if (dx>=0 && dx<X && dy>=0 && dy<Y && maze[dx][dy]=='.' && !vis[dx][dy])
            dfs(dx,dy);
    }
}
