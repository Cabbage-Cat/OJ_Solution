#include <bits/stdc++.h>
#define MAX_N 100009
using namespace std;

char num[MAX_N];
int t;

int main()
{
    int l;
    int tmp=0;
    scanf("%d",&t);
    while (t-->0)
    {
        tmp=0;
        getchar();
        scanf("%s",num);
        l = strlen(num);
        if (l >= 7)
            cout << "0.000000" << endl;
        else
            for (int i=0;i<l;i++)
            {
                tmp += pow(10,l-1-i)*(num[i]-'0');
            }
        double res;
        res = 1.0/tmp;
        if (res < -0.0000005)
            cout << "0.000000" << endl;
        else
            printf("%.6lf\n",res);
        // printf("%.6ld",res);
    }
    return 0;
}