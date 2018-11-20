#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 1010
using namespace std;
void solve();
int N,M,R;
typedef struct
{
    int begin;
    int end;
    int eff;
}Cow;
bool cmp(const Cow &c1,const Cow &c2);

Cow cows[MAX_N];
int dp[MAX_N];

int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ3616\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ3616\\file.out","w",stdout);
    scanf("%d %d %d",&N,&M,&R);
    for (int i=0;i<M;i++)
    {
        scanf("%d %d %d",&cows[i].begin,&cows[i].end,&cows[i].eff);
        cows[i].end+=R;
    }
    solve();
    // fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	sort(cows,cows+M,cmp);
    for (int i=0;i<M;i++)
        dp[i]=cows[i].eff;
    int res=0;
    for (int i=0;i<M;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (cows[i].begin >= cows[j].end)
                dp[i] = max(dp[i],dp[j]+cows[i].eff);
        }
        res = max(res,dp[i]);
    }
    printf("%d\n",res);
}

bool cmp(const Cow &c1,const Cow &c2)
{
    if (c1.end==c2.end)
        return c1.eff > c2.eff;
    return c1.end < c2.end;
}