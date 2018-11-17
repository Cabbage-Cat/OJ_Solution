#include <cstdio>
#include <algorithm>
#include <queue>

#define MAX_N 51000

using namespace std;
typedef pair<int,int> P;

P cow[MAX_N];
int stalls[MAX_N];
int N;
void solve();


int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ3190\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ3190\\file.out","w",stdout);
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d %d",&cow[i].first,&cow[i].second);
    
    sort(cow,cow+N);
    // solve();
    for (int i=0;i<N;i++)
        printf("%d %d\n",&cow[i].first,&cow[i].second);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void solve()
{
    int res=1;
    priority_queue<P> pq;
    stalls[0] = 1;
    pq.push(P(cow[0].second,1));
    for (int i=1;i<N;i++)
    {
        if (cow[i].first > pq.top().first)
        {
            stalls[i]=pq.top().second;
            pq.pop();
        }
        else
        {
            stalls[i]=pq.top().second+1;
            res++;
        }
        pq.push(P(cow[i].second,stalls[i]));
    }
    printf("%d\n",res);
    for (int i=0;i<N;i++)
        printf("%d\n",stalls[i]);
        
}