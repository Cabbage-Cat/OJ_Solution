#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 10100

using namespace std;
typedef pair<int,int> P;
P cost_need[MAX_N];

long long solve();
int N,S;

int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ2393\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ2393\\file.out","w",stdout);
    scanf("%d %d",&N,&S);
    for (int i=0;i<N;i++)
        scanf("%d %d",&cost_need[i].first,&cost_need[i].second);
    long long res=solve();
    printf("%lld\n",res);

    fclose(stdin);fclose(stdout);
    return 0;
}

long long solve()
{
    long long res=0;
    for (int i=0;i<N;i++)
    {
        int cost=cost_need[i].first;
        for (int j=i-1;j>=0;j--)
        {
            int tmp=cost_need[j].first + S*(i-j);
            if(tmp<cost)
                cost=tmp;
        }
        res+=cost*cost_need[i].second;
    }
    return res;
}