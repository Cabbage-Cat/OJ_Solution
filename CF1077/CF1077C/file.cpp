#include <cstdio>
#include <iostream>
#define MAX_N 205000

long long int X[MAX_N];
long long int res[MAX_N];
using namespace std;
int N;
int main()
{
    freopen("F:\\github\\OJ_Solution\\CF1077C\\file.in","r",stdin);
    freopen("F:\\github\\OJ_Solution\\CF1077C\\file.out","w",stdout);
    int rr=0;
    scanf("%d",&N);
    for (int i=0;i<N;i++)
    {
        cin >> X[i];
        rr += X[i];
    }
    
    for (int i=0;i<N;i++)
    {
        if (rr-X[i] == X[i])
            cout << i << endl;
    }
    cout << rr;
    fclose(stdin);fclose(stdout);
    return 0;
}