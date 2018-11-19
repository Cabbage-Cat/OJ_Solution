#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 101000
using namespace std;
typedef pair<int,int> P;

P x[MAX_N];

void solve();
bool cmp(const P &p1, const P &p2);
int N;
long long r;
int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ3262\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ3262\\file.out","w",stdout);
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d %d",&x[i].first,&x[i].second);
    sort(x,x+N,cmp);
    solve();
    printf("%lld\n",r);
    // fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    long long cost=0;
    long long res=0;
	for (int i=0;i<N;i++)
        cost+=x[i].second;
    for (int i=0;i<N;i++)
    {
        cost-=x[i].second;
        res+=2*x[i].first*cost;
    }
    r = res;
}

bool cmp(const P &p1, const P &p2)
{
    return p1.first*p2.second < p2.first*p1.second;
}