#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAX_N 10100

using namespace std;
void solve();
typedef pair<long long , int> P;
P coin[20];
int N;long long C;
long long r;
int main()
{
    freopen("F:\\github\\OJ_Solution\\POJ3040\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\POJ3040\\file.out","w",stdout);

    scanf("%d %lld",&N,&C);
    for (int i=0;i<N;i++)
        scanf("%lld %d",&coin[i].first,&coin[i].second);
    sort(coin,coin+N);
    solve();

    printf("%lld\n",r);
    fclose(stdin);fclose(stdout);
    return 0;
}

void solve()
{
    long long res=0;
	for (int i=N-1;i>=0;i--)
    {
        if (coin[i].first >= C)
        {
            res += coin[i].second*(coin[i].first/C);
            coin[i].second=0;
        }
        else
            break;
    }

    for (int i=N-1;i>=0;i--)
    {
        int tmp = C/coin[i].first;

        if (coin[i].second==0)
            continue;
        while(true)
        {
            if (coin[i].second<=0)
                break;
            int cost = min(coin[i].second,tmp);
            coin[i].second-=cost;
            long long rest=C-cost*coin[i].first;
            
            for (int j=0;j<N;j++)
            {
                if (rest<=0)
                    break;
                if (coin[j].second==0)
                    continue;
                int c = min(coin[j].second,(int)(rest/coin[j].first));
                if (rest%coin[j].first==0 && coin[j].second>=c)
                {
                    coin[j].second-=c;
                    rest=0;
                    res++;
                    break;
                }
                else if (coin[j].second>c)
                {
                    coin[j].second-=(c+1);
                    rest-=(c+1)*coin[j].first;
                    res++;
                    break;
                }
                else
                {
                    coin[j].second=0;
                    rest-=c*coin[j].first;
                }
            }
        }
    }
    r=res;
}