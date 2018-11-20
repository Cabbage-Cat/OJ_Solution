#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 1010

using namespace std;
void solve();

int apple[MAX_N];
int dp[MAX_N][MAX_N];
int N,W;
int main()
{
    // freopen("C:\\Users\\admin\\Desktop\\OJ_Solution\\POJ2385\\file.in","r",stdin);
    // freopen("C:\\Users\\admin\\Desktop\\OJ_Solution\\POJ2385\\file.out","w",stdout);
    scanf("%d %d",&N,&W);
    for (int i=0;i<N;i++)
        scanf("%d",&apple[i]);
    solve();
    // fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    for (int i=1;i<=N;i++)
        for (int j=0;j<=W;j++)
        {   
            if (j==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]); 
            if (j%2+1==apple[i-1])
                dp[i][j]++;
        }
    printf("%d\n",dp[N][W]);
}