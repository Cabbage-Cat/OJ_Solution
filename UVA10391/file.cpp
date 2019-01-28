#include <bits/stdc++.h>
using namespace std;
string s[150000];
int main()
{

    map<string,bool> words;
    set<string> res;
    int cnt = 0;
    while (cin >> s[cnt])
        words[s[cnt++]] = true;
    
    map<string,bool>::iterator iter;
    for (int i = 0;i<cnt;i++)
    {
        string ss = s[i];
        // cout << ss << '\n';
        for (int j=0;j<ss.size();j++)
        {
            string s1 = ss.substr(0,j);
            string s2 = ss.substr(j);
            if (words[s1] && words[s2])
                res.insert(ss);
        }
    }

    set<string>::iterator it;
    for (it = res.begin();it != res.end();it++)
        cout << *it << '\n';
    return 0;
}