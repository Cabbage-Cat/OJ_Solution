#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

set<string> dict;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    string s,buf;
    while (cin >> s)
    {
        for (int i=0;i<s.size();i++)
        {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while (ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin();it!=dict.end();it++)
        cout << *it << endl;
    return 0;
}

