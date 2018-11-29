#include <bits/stdc++.h>
#define MAX_N 2005
#define INF 100005
typedef long long i64;

using namespace std;
void solve();

int road[MAX_N];
int dp[MAX_N];
int dp_num[MAX_N];
int N;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> road[i];
    
    solve();
    return 0;
}

void solve()
{
	fill(dp,dp+N,INF);
    fill(dp_num,dp_num+MAX_N,-1);
    int p=0;
    int res1=0;
    for (int i=0;i<N;i++)
    {
        int *tmp;
        tmp = lower_bound(dp,dp+N,road[i]);
        if (*tmp == INF)
            dp_num[p++] = i;
        *tmp = road[i];    
    }

    for (int i=0;i<p-1;i++)
    {
        int left = dp_num[i],right = dp_num[i+1];
        for (int i=1+left;i<right;i++)
        {
            int d1 = abs(road[i] - road[left]);
            int d2 = abs(road[i] - road[right]);
            res1 += min(d1,d2);
        }
    }
    cout << res1 << endl;
}