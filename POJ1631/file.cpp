// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_N 40005
#define INF 1e9
typedef long long i64;

using namespace std;
void solve();

int roads[MAX_N];
int dp[MAX_N];
int t,n;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        fill(dp,dp+MAX_N,INF);
        for (int i=0;i<n;i++)
            cin >> roads[i];
        solve();
    }
    return 0;
}

void solve()
{
	for (int i=0;i<n;i++)
        *lower_bound(dp,dp+n,roads[i]) = roads[i];
    cout << lower_bound(dp,dp+n,INF) - dp << endl;
}