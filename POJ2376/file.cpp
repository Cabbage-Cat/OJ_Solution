#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 30000

typedef pair<int,int> P;
P X[MAX_N];
int N,T;
void solve();


int main()
{
    // freopen("F:\\github\\OJ_Solution\\POJ2376\\file.in","r",stdin);
    // freopen("F:\\github\\OJ_Solution\\POJ2376\\file.out","w",stdout);
    scanf("%d %d",&N,&T);
    for (int i=1;i<=N;i++)
        scanf("%d %d",&X[i].first,&X[i].second);
    sort(X+1,X+N+1);
    X[0].first=0;X[0].second=0;
    solve();
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

void solve()
{
    int pos=0,res=0;

    while (X[pos].second<T)
    {
        int max_p=pos;
        int flag=0;
        for (int i=pos+1;i<=N&&X[i].first<=X[pos].second+1;i++)
        {
            if (X[i].second >= X[max_p].second)
            {
                max_p = i;
                flag=1;
            }
        }

        if (!flag)
        {
            printf("-1\n");
            return;
        }
        
        else
        {
            pos=max_p;
            res++;
        }
    }
   printf("%d\n",res);
}

