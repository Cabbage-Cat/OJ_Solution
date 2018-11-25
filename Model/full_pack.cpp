#include <bits/stdc++.h>

#define MAX_N 10100
#define MAX_V 10100
typedef long long i64;

using namespace std;

// int W[MAX_N];
int C[MAX_N];
int M[MAX_N];
int dp[MAX_N][MAX_V];
void fullPack(int **dp);

int N,V;


int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ2393\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ2393\\file.out","w",stdout);


    fclose(stdin);fclose(stdout);
    return 0;
}


void fullPack(int **dp)
{
    memset(dp[0],sizeof(dp[0]),-1);
    dp[0][0]=0;
    //dp[i][j] stands uses ith things later,the maxium last M_i.
    for (int i=1;i<=N;i++)
    {
        for (int j=0;j<=V;j++) //the j pack is full.
        {
            if (dp[i-1][j]>=0)
                dp[i][j] = M[i];
            else
                dp[i][j] = -1;
        }

        for (int j=0;j<=V-C[i];j++)
        {
            if (dp[i][j] > 0)
                dp[i][j+C[i]] = max(dp[i][j+C[i]],dp[i][j]-1);
        }
    }
}