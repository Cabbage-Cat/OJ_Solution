#include <cstdio>
#include <iostream>
#include <vector>
#define INF 9999999
#define MAX_N 505

using namespace std;

int h[MAX_N][MAX_N];
void solve();

int F,N,M,W;
int d[MAX_N][MAX_N];
int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\a.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\a.out","w",stdout);

    scanf("%d",&F);
    while (F-->0)
    {
        int from,to,cost;
        
        fill(d[0],d[0]+MAX_N*MAX_N,INF);
        fill(h[0],h[0]+MAX_N*MAX_N,INF);
        scanf("%d%d%d",&N,&M,&W);
        for (int i=0;i<M;i++)
        {
            scanf("%d%d%d",&from,&to,&cost);
            from--;to--;
            d[from][to]=cost;
            d[to][from]=cost;
        }
        
        int flag=0;
        for (int i=0;i<W;i++)
        {
            scanf("%d%d%d",&from,&to,&cost);
            from--;to--;
            h[from][to]=-cost;
        }
        solve();
        printf("\n");

        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");    
    }
    return 0;
}

void solve()
{
    // for (int i=0;i<N;i++)
    //     d[i][i]=0;

    for (int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for (int k=0;k<N;k++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }


    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }

}