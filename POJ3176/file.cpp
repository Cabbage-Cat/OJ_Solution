#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 352

using namespace std;
void solve();
int bowl[MAX_N][MAX_N];
int N;
int dp[MAX_N][MAX_N];
int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ3176\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ3176\\file.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=i;j++)
            scanf("%d",&bowl[i][j]);
    
    solve();
    // fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
	for (int i=1;i<=N;i++)
        dp[N][i]=bowl[N][i];
    
    for (int i=N-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]=bowl[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
    
    printf("%d\n",dp[1][1]);
}