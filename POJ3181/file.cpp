// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#define MAX_V 1005
#define MAX_N 105
typedef long long i64;
typedef unsigned long long ui64;
using namespace std;

ui64 dp[2][MAX_V];
int N,V;
void solve();

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("F:\\github\\OJ_Solution\\POJ3181\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ3181\\file.out","w",stdout);
    cin >> V >> N;
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // count dp[N][i] >=0 num to solve the problem.
    dp[0][0] = dp[1][0] = 1;
    
    for (int i=1;i<=N;i++)
    {
        int cur = i%2;
        int last = (i-1)%2;
        for (int j=1;j<=V;j++)
        {
            if (j>=i)
                dp[cur][j] = dp[last][j] + dp[cur][j-i];
            else
                dp[cur][j] = dp[last][j];
        }
    }

    cout << dp[N%2][V] << endl;
}