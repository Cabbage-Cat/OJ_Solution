#include <bits/stdc++.h>
#define MAX_N 100007
typedef long long i64;
using namespace std;


int T;
int N;
int num[MAX_N];
int dp[MAX_N];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> T;
    while (T-- > 0)
    {
        cin >> N;
        int res=0;
        for (int i=1;i<=N;i++)
        {
            cin >> num[i];
            res+=num[i];
        }
        dp[1] = res-num[1];
        for (int i=2;i<=N;i++)
            dp[i] = dp[i-1] - num[i];
        i64 r=0;
        for (int i=1;i<N;i++)
            r+=num[i]*dp[i];
        cout << r << endl;
    }

    return 0;
}
