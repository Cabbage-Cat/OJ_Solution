#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAX_N 11000
using namespace std;

void solve();

int A[MAX_N],B[MAX_N],N,L,P;
int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        scanf("%d%d",&A[i],&B[i]);
    scanf("%d%d",&L,&P);
    
    solve();

    return 0;
}

void solve()
{
    priority_queue<int> pq;
    int pos=L,tank = P,ans = 0;
    for (int i=N;i>0;i--)
    {
        int d = pos - A[i];  //Need to go.
        
        while(tank < d)
        {
            if (pq.empty())
            {
                printf("-1\n");
                return;
            }

            tank += pq.top(),pq.pop(),ans++;
        }
        tank -= d;
        pos = A[i];
        pq.push(B[i]);
    }

    printf("%d\n",ans);
}