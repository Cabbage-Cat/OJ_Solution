#include <cstdio>
#include <vector>
#include <queue>
#define INF 250000
#define MAX_R 100000
#define MAX_N 5005

using namespace std;
struct edge
{
    int to,cost;
};
typedef pair<int,int> P;

vector<edge> G[MAX_N];
int d[MAX_N];
int d2[MAX_N];
void solve();

int N,R;
int main()
{
    while(~scanf("%d %d",&N,&R))
    {
        for (int i=0;i<N;i++)
            G[i].clear();
        
        int A,B,D;
        edge e;
        for (int i=0;i<R;i++)
        {
            scanf("%d %d %d",&A,&B,&D);
            --A;--B;
            e.to = B,e.cost = D;
            G[A].push_back(e);
            swap(e.to,A);
            G[A].push_back(e);
        }
        solve();
    }
    return 0;
}

void solve()
{
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+MAX_N,INF);
    fill(d2,d2+MAX_N,INF);

    d[0] = 0;
    que.push(P(0,0));

    while (!que.empty())
    {
        P p=que.top();que.pop();
    
        if (p.first>d2[p.second])
            continue;
        for (int i=0;i<G[p.second].size();i++)
        {
            edge e = G[p.second][i];
            int l = p.first + e.cost;
            if (l < d[e.to])
            {
                swap(d[e.to],l);
                que.push(P(d[e.to],e.to));
            }

            if (l<d2[e.to] && l>d[e.to])
            {
                d2[e.to] = l;
                que.push(P(d2[e.to],e.to));
            }
        }
    }

    printf("%d\n",d2[N-1]);
    
}