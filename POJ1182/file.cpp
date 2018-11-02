#include <iostream>
#include <cstdio>
#define MAX_N 151000
#define MAX_K 101000

int par[MAX_N];
int rank[MAX_N];

void init(int x)
{
    for (int i=0;i<x;i++)
        par[i] = i;
}

int find(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x , int y)
{
    x = find(x);
    y = find(y);
    if (x==y)
        return;
    if (rank[x] < rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}

bool same(int x,int y)
{
    return find(x) == find(y);
}

int N,K;
void solve();

int main()
{
    solve();
    return 0;
}

void solve()
{
    scanf("%d %d",&N,&K);
    init(N*3);
    int ans=0;

    int d,x,y;
    for (int i=0;i<K;i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        x--,y--;

        if (x<0 || x>=N || y<0 || y>=N || d==2&&x==y)
        {
            ans++;
            continue;
        }

        if (d==1)
        {
            if (same(x,y+N) || same(x,y+2*N))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x,y);
                unite(x+N,y+N);
                unite(x+2*N,y+2*N);
            }
        }
        else
        {
            if (same(x,y) || same(x,y+2*N))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            }
        }
    }
    printf("%d\n",ans);
}