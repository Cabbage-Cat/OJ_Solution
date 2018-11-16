#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX_N 1005
#define INF 999999
using namespace std;
typedef pair<int,int> P;
P island[MAX_N];

void solve();
int N,D,t;
int x,y;
int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ1328\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ1328\\file.out","w",stdout);
    while (~scanf("%d %d",&N,&D) && !(N==0&&D==0))
    {
        for (int i=0;i<N;i++)
        {
            scanf("%d %d",&x,&y);
            int dis = D*D - y*y;
            if (dis < 0)
            {
                printf("Case %d: -1\n",++t);
                break;
            }

            island[i].first = x-(int)sqrt(dis+0.5);island[i].second=x+(int)sqrt(dis+0.5);
        }
        
        sort(island,island+N);
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void solve()
{
    P tmp;tmp.first=island[0].first;tmp.second=island[0].second;
    int res=1;
    for (int i=1;i<N;i++)
    {
        if (island[i].first <= tmp.second)
        {
            tmp.first=island[i].first;
            if (island[i].second<tmp.second)
                tmp.second = island[i].second;
        }
        else
        {
            res++;
            tmp.first=island[i].first;tmp.second=island[i].second;
        }
    }

    printf("Case %d: %d\n",++t,res);
}