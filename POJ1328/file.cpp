#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 1005

using namespace std;
typedef pair<int,int> P;
P island[MAX_N];

void solve();
int N,D,t;

int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ1328\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ1328\\file.out","w",stdout);
    while (~scanf("%d %d",&N,&D) && !(N==0&&D==0))
    {
        for (int i=0;i<N;i++)
            scanf("%d %d",&island[i].first,&island[i].second);
        
        sort(island,island+N);
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void solve()
{
    int res=0,pos=0;
    while (pos<N)
    {
        int tmp=pos;
        int dx = island[tmp].first - island[pos].first;
        int dy = island[tmp].second;
        while (dx*dx+dy*dy <= D*D)
        {
            tmp++;
            dx = island[tmp].first - island[pos].first;
            dy = island[tmp].second;
        }
        if (pos==tmp)
        {
            printf("Case %d: -1\n",++t);
            return;
        }
        pos = tmp;
        res++;
    }
    printf("Case %d: %d\n",++t,res);
}