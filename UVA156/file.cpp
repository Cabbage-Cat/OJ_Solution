#include <bits/stdc++.h>

#define MAX_N 10100
typedef long long i64;

using namespace std;

map<string,int> cnt;
vector<string> words;

string repr(const string& s)
{
    string r = s;
    for (int i=0;i<r.size();i++)
        r[i] = tolower(r[i]);
    sort(r.begin(),r.end());
    return r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    while (cin >> s)
    {
        if (s[0]=='#')
            break;
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r))
            cnt[r] = 0;
        cnt[r]++;
    }

    vector<string> res;

    for (int i=0;i<words.size();i++)
    {
        if (cnt[repr(words[i])]==1)
            res.push_back(words[i]);
    }

    sort(res.begin(),res.end());

    for (int i=0;i<res.size();i++)
        cout << res[i] << "\n";

    return 0;
}

