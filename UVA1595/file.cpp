#include <bits/stdc++.h>

using namespace std;

map<int,vector<int>> points;

int main()
{
    int t,n;
    cin >> t;
    int a,b;
    while (t--)
    {
        int res=0;
        cin >> n;
        points.clear();

        while (n--)
        {
            cin >> a >> b;
            points[b].push_back(a*2);
        }

        map<int,vector<int>>::iterator points_it;
        int flag = 1;
        for (points_it = points.begin();points_it!=points.end();points_it++)
        {
            vector<int>& tmp = points_it->second;
            int sum_p = 0;
            for (int i=0;i<tmp.size();i++)
                sum_p+=tmp[i];
            if (res==0)
                res = sum_p / tmp.size();
            else
                if (res != sum_p / tmp.size())
                {
                    cout << "NO\n";
                    flag = 0;
                    break;
                }
        }
        
        if (flag)
            cout <<"YES\n";

        // cout << "END" << endl;
    }
    return 0;
}