#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define pb push_back
#define LIM 5000001
using namespace std;

typedef struct pair<int, int> PII;

int prime[LIM+1] = {0};
int numb[LIM+1] = {0};
//vector<int> Primes;
int main()
{
	//int srt = sqrt(5000001);
	for (int i = 2; i < LIM; i++)
	{
		if (!prime[i])
		{
			int lm = LIM/i;
			for (int j = 2; j <= lm; j++)
			{
				int curr = i*j;
				int tmp = curr;
				prime[curr] = 1;
				int ct = 0;
				while(curr%i == 0)
				{
					curr/= i;
					ct++;
				}
				numb[tmp] += ct;
			}
			numb[i]++;
		}
	}
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		int score = 0;
		for (int j = b+1; j <= a; j++)
			score += numb[j];
		cout << score << "\n";
	}
	return 0;
}