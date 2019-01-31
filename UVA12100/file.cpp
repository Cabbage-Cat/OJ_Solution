#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> q;
        priority_queue<int> pq;
        int n,m,s;
        cin >> n >> m;
        for (int i=0;i<n;i++)
        {
            cin >> s;
            q.push(s);pq.push(s);
        }

        int x = 0;
        while (true)
        {
            if (q.front() == pq.top())
            {
                if (x == m)
                {
                    cout << n - q.size() + 1 << endl;
                    break;
                }
                else
                {
                    q.pop();pq.pop();
                    x++;
                }
                
            }
            else
            {
                int t = q.front();
                q.pop();q.push(t);

                if (x == m)
                {
                    x = 0;
                    m = q.size() - 1;
                }
                else
                    x++;
                
            }
            
        }
        
    }
    return 0;
}