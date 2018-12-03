#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

int N,Q;
int mable[MAX_N];
int main()
{
    int t=0;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (~scanf("%d%d",&N,&Q) && !(N==0 && Q==0))
    {
        t++;
        int tmp;
        for (int i=0;i<N;i++)
            scanf("%d",&mable[i]);
        sort(mable,mable+N);
        cout << "CASE# "<<t<<':'<< endl;
        for (int i=0;i<Q;i++)
        {
            scanf("%d",&tmp);
            if (*lower_bound(mable,mable+N,tmp) == tmp)
                cout << tmp << " found at " << 1+lower_bound(mable,mable+N,tmp)-mable << endl;
            else
                cout << tmp << " not found" << endl;
        }
        
    }

    return 0;
}

