#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back
#define ll long long int
#define pb push_back

using namespace std;

bool dir_edge[101][101];
int inc_count[101];
set <int> deg_0;
vector <int> topsort;
vector<int> conn[101];

void tsort()
{
	if(deg_0.size() == 0)
		return;
	int curr_v = *(deg_0.begin());
	//cout << "Curr_V : " << curr_v << endl;
	topsort.pb(curr_v);
	deg_0.erase(deg_0.begin());
	for(int i = 0; i < conn[curr_v].size(); i++)
	{
		int curr = conn[curr_v][i];
		inc_count[curr]--;
		if(inc_count[curr] == 0)
			deg_0.insert(curr);
	}
	tsort();
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		memset (dir_edge, 0, sizeof(dir_edge));
		memset (inc_count, 0, sizeof(inc_count));
		deg_0.clear();
		topsort.clear();
		int n, k, m;	//no_nodes, no of lines, no of pairs in each line
		cin >> n >> k;
		set<pair<int, int> > X;
		for(int i = 0; i < k; i++)
		{
			cin >> m;
			for(int j = 0; j < m; j++)
			{
				int t1, t2;	cin >> t1 >> t2;
				conn[t1].pb(t2);
				dir_edge[t1][t2] = 1;
				inc_count[t2]++;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(inc_count[i] == 0)
				deg_0.insert(i);
		}
		tsort();
		pf("Test case #%d:\n", t+1);
		if(topsort.size() < n)
			cout << -1 << endl;
		else
		{
			for(int i = 0; i < topsort.size(); i++)
			{
				cout << topsort[i]<<' ';
			}
			cout << endl;
		}
	}
}
