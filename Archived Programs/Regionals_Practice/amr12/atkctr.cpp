#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define n_max 1000001

using namespace std;

vector<int> Anom[n_max+1];
vector<int> Anom_rev[n_max+1];

int main()
{
	int T;	sf("%d", &T);
	
	for(int t = 0; t < T; t++)
	{
		int N, M;	sf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++)
		{
			Anom[i].clear();
			Anom_rev[i].clear();
		}
		for(int m = 0; m < M; m++)
		{
			int x, y;	sf("%d%d", &x, &y);
			Anom[x].pb(y);
			Anom_rev[y].pb(x);
		}
		
		int flag = 1;
		int prim = 0;
		for(int i = 1; i <= N; i++)
		{
			if(Anom[i].size() == N-i && Anom_rev[i].size() == 0)
			{
				flag = 2;
				prim = i;
				break;
			}
		}
		
		if(flag == 2)
			pf("%d %d\n", flag, prim);
		else
			pf("%d\n", flag);
	}
	return 0;
}
