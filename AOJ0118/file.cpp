#include <iostream>
#include <cstdio>
#define MAX_N 110

char maze[MAX_N][MAX_N];
int X,Y;
int vis[MAX_N][MAX_N];
int mv_x[4] = {0,0,-1,1},mv_y[4] = {1,-1,0,0};

void dfs(int x,int y);
int main()
{
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    while (~scanf("%d %d ",&X,&Y) && X!=0 && Y!=0)
    {
        int res = 0;
        for (int i=0;i<MAX_N;i++)
            for(int j=0;j<MAX_N;j++)
                vis[i][j] = 0;

        for (int i=0;i<X;i++)
            for(int j=0;j<Y;j++)
                scanf("%c ",&maze[i][j]);
        for (int i=0;i<X;i++)
            for (int j=0;j<Y;j++)
            {
                if (!vis[i][j])
                {
                    dfs(i,j);
                    res++;
                }
            }

        printf("%d\n",res);
    }
    // fclose(stdin);fclose(stdout);
    return 0;
}

void dfs(int x,int y)
{
    if (!vis[x][y])
    {
        char t = maze[x][y];
        vis[x][y] = 1;
        for (int i=0;i<4;i++)
        {
            int dx = x+mv_x[i],dy = y+mv_y[i];
            if (dx>=0 && dx<X && dy >=0 && dy<Y && maze[dx][dy]==t
             && !vis[dx][dy])
                dfs(dx,dy);
        }
    }

}
