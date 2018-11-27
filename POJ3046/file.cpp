// #include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_N 100009
#define MAX_ANT_FAMILY 1005
#define MOD 1000000
typedef long long i64;

using namespace std;
void solve();

int ant_num[MAX_ANT_FAMILY];
int dp[2][MAX_N];
// A:ant number T ant family S,B minum and maxium
int T,A,S,B;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    freopen("C:\\Users\\admin\\Desktop\\OJ_Solution\\POJ3046\\file.in","r",stdin);
    freopen("C:\\Users\\admin\\Desktop\\OJ_Solution\\POJ3046\\file.out","w",stdout);
    int tmp;
    cin >> T >> A >> S >> B;
    for (int i=0;i<A;i++)
    {
        cin >> tmp;
        ant_num[tmp]++;
    }

    // dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1-ant_num[i]]
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    dp[0][0] = dp[1][0] = 1;
	for (int i=1;i<=T;i++)
        for (int j=1;j<=B;j++)
        {
            int cur = i&1;
            int last = (i-1)&1;
            if (j-1-ant_num[i]>=0)
                dp[cur][j] = (dp[last][j] + dp[cur][j-1] - dp[last][j-1-ant_num[i]] + MOD)%MOD;
            else
                dp[cur][j] = (dp[last][j] + dp[cur][j-1]+MOD)%MOD;
        
        }
    
    int res=0;
    for (int i=S;i<=B;i++)
        res = (res + dp[T%2][i])%MOD;
    
    cout << res;

}