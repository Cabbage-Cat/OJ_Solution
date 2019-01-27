#include <bits/stdc++.h>
#define MAX_N 10100
typedef long long i64;
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<vector<int>> ducci; 
    while (n--)
    {
        int l;
        int num;
        vector<int> d_one;
        cin >> l;
        for (int i=0;i<l;i++)
        {
            cin >> num;
            d_one.push_back(num);
        }
        ducci.clear();
        // ducci.insert(d_one);
        for (int i=0;i<1000;i++)
        {
            int first = d_one[0];
            for (int j=0;j<d_one.size() - 1;j++)
                d_one[j] = abs(d_one[j] - d_one[j+1]);
            d_one[d_one.size() - 1] = abs(d_one[d_one.size() - 1]  - first);
            if (ducci.count(d_one))
            {
                cout << "LOOP\n";
                break; 
            }
            int zero_flag = 1;
            for (int j=0;j<d_one.size();j++)
                if (d_one[j] != 0)
                {
                    zero_flag = 0;
                    break;
                }
            if (zero_flag)
            {
                cout << "ZERO\n";
                break;
            }

            ducci.insert(d_one);
        }
    }
    return 0;
}

