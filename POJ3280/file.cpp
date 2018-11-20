#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 2010
#define INF 999999
using namespace std;
void solve();


int dp[MAX_N][MAX_N];
int M,N;
char str[MAX_N];
int cost[26];
int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ3280\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ3280\\file.out","w",stdout);
    scanf("%d%d",&N,&M);
    getchar();
    scanf("%s",str);
    getchar();
    char tmp;
    for (int i=0;i<N;i++)
    {
        scanf("%c",&tmp);
        int x1,x2;
        scanf("%d%d",&x1,&x2);
        cost[tmp-'a'] = min(x1,x2);
        getchar();
    }
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    for (int i=M-1;i>=0;i--)
        for (int j=i+1;j<M;j++)
        {
            if(str[i]==str[j])
                dp[i][j] = dp[i+1][j-1];
            else
            {
                int char_i=str[i]-'a';
                int char_j=str[j]-'a';

                dp[i][j] = min(dp[i+1][j]+cost[char_i],dp[i][j-1]+cost[char_j]);
            }
        }
    printf("%d\n",dp[0][M-1]);
}