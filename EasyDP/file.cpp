// Easy DP
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int dp[50];
int N,V,C[50],W[50];
void solve();
int main()
{
    cin >> N;
    cin >> V;
    for (int i=0;i<N;i++)
    {
        cin >> C[i];
        cin >> W[i];    
    }
    solve();

    return 0;
}

void solve()
{
    for (int i=1;i<=N;i++)
        for (int j=V;j>0;j--)
            if (j>=C[i-1])
                dp[j] = max(dp[j],dp[j-C[i-1]]+W[i-1]);
}