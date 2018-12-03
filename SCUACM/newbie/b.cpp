#include <bits/stdc++.h>

#define MAX_N 100007
typedef long long i64;
typedef struct
{
    int index;
    int cost;
} Block;

Block b[MAX_N];
int cost[MAX_N];

int a_vis_left,a_vis_right;
int left,right;
using namespace std;
bool cmp (const Block &b1,const Block &b2);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T,N;
    cin >> T;
    while (T-->0)
    {
        cin >> N;
        Block tmp;
        for (int i=1;i<=N;i++)
        {
            cin >> tmp.cost;
            cost[i]=tmp.cost;
            tmp.index=i;
            b[i]=tmp;
        }

        sort(b+1,b+1+N,cmp);
        

        int m=1,res=0;
        res+=b[N].cost;

        a_vis_left=a_vis_right=b[N].index;
        


    }
    return 0;
}

bool cmp(const Block &b1,const Block &b2)
{
    return b1.cost < b2.cost;
}

