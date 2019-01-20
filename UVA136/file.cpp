#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;
const int coeff[3] = {2,3,5};


int main()
{
    priority_queue<i64,vector<i64>,greater<i64>> pq;
    set<i64> s;
    pq.push(1);
    s.insert(1);

    for (int i=1;;i++)
    {
        i64 x = pq.top();pq.pop();
        if (i==1500)
        {
            printf("The 1500'th ugly number is %d.\n",x);
            break;
        }
        for (int j=0;j<3;j++)
        {
            i64 x2 = x * coeff[j];
            if (!s.count(x2))
            {
                pq.push(x2);
                s.insert(x2);
            }
        }
    }
    return 0;
}

