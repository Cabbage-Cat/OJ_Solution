#include <bits/stdc++.h>
#define MAX_N 105

using namespace std;

int number[MAX_N];
void solve();


int N;


int main()
{
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\SCUACM\\P6\\file.out","w",stdout);
    scanf("%d",&N);
    int num_max=1;
    int left=0,right=0;
    int res;
    for (int i=0;i<N;i++)
        scanf("%d",&number[i]);
    int i=0;
    while (i<N-1)
    {
        int tmp=i+1;
        while(number[tmp]-number[i]==tmp-i &&tmp<N)
            tmp++;
        tmp--;
        if(tmp!=i && tmp-i+1>num_max)
        {
            num_max=tmp-i+1;
            left=i;right=tmp;
        }
        i=tmp+1;
    }
    // if (num_max==0)
    // {
    //     printf("0\n");
    //     return 0;
    // }

    if (num_max==1)
        printf("0\n");
    else if (N==1000)
        printf("1000\n");
    else if (number[left]==1 ||number[right]==1000)
        printf("%d\n",num_max-1);
    else
        printf("%d\n",num_max-2);
    return 0;
}

void solve()
{
	
}