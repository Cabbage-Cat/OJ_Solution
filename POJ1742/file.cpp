#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

#define MAX_N 105
#define MAX_V 100005
typedef long long i64;

using namespace std;

int dp[MAX_V];
int C[MAX_N];
int M[MAX_N];

int n,V;
void solve();

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("F:\\github\\OJ_Solution\\POJ1742\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ1742\\file.out","w",stdout);

    while (cin >> n >> V && !(n==0 && V==0))
    {
        fill(dp,dp+MAX_V,-1);
        for (int i=1;i<=n;i++)
            cin >> C[i];
        for (int i=1;i<=n;i++)
            cin >> M[i];
        solve();
    }

    // fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{

    dp[0]=0;

	for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=V;j++)
        {
            if(dp[j]>=0)
                dp[j]=M[i];
            else
                dp[j]=-1;
        }

        // for (int j=0;j<=V;j++)
        // {
        //     if (dp[i-1][j]>=0)
        //         dp[i][j] = M[i];
        //     else
        //         dp[i][j] = -1;
        // }

        // for (int j=0;j<=V-C[i];j++)
        // {
        //     if (dp[i][j] > 0)
        //         dp[i][j+C[i]] = max(dp[i][j+C[i]],dp[i][j]-1);
        // }

        for (int j=0;j<=V-C[i];j++)
        {
            if(dp[j]>0)
                dp[j+C[i]]=max(dp[j+C[i]],dp[j]-1);
        }
    }

    int res=0;
    for (int i=1;i<=V;i++)
    {
        if (dp[i]!=-1)
        {
            res++;
        }
        else
            continue;
    }

    cout << res << endl;
    
}