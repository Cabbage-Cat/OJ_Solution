#include <cstdio>
#include <iostream>
using namespace std;

int N;
long long int a,b,k;
long long int solve();
int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++)
    {
        cin >> a >> b >> k;
        long long int res=solve();
        cout << res << endl;
    }
    return 0;
}

long long int solve()
{
    long long int res=0;
    int i=k/2;
    res=i*(a-b);
    if (k%2==1)
        res+=a;
    return res;
}