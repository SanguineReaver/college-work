#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<long long int, long long int>

using namespace std;

string s, p;
int s_siz, p_siz;
int ct = 0;

int main()
{
	cin >> s >> p;
	s_siz = s.size();	p_siz = p.size();
	for(int i = 0; i < s_siz; i++)
	{
		if(i+p.size() <= s_siz)
		{
			string sub = s.substr(i, p_siz);
			if(sub == p)
			{
				s[i+p_siz-1] = '#';
				i += p.size()-1;
				ct++;
			}
		}
	}
	//cout << s << endl;
	cout << ct;
	return 0;
}
