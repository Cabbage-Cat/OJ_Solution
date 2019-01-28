
#include<bits/stdc++.h>
using namespace std;
 
map<pair<int, int>, int> m;
map<pair<int, int>, int>::iterator it;
 
bool ok()
{
	for (it = m.begin(); it != m.end(); ++it)
		if (it->second) return false;
	return true;
}
 
int main()
{
	int n, a, b;
	while (scanf("%d", &n), n)
	{
		m.clear();
		while (n--)
		{
			scanf("%d%d", &a, &b);
			a < b ? ++m[make_pair(a, b)] : --m[make_pair(b, a)];
		}
		puts(ok() ? "YES" : "NO");
	}
	return 0;
}
