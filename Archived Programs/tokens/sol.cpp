#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define forn(i, l, r) for(int i = l; i < r; i++)

using namespace std;

int n;			// no of tokens
ll val[101][101], sum[101], token[101];
/* 	val[i][j] is the value if the values available are from token[i] to token[j]
	sum[i] is the sum of tokens from 0 to i (including i)
	token[i] is the value of token @ ith position
*/

/* 	dp(i, j) gives the maximum answer if the tokens available are from i to (including) j (j may be < i)
	It works as follows:-
	1> if (i == j), only one token, that's the answer.
	2> Otherwise, if i < j, this means that no "wrapping back", then sum of available tokens = sum[j] - sum[i].
	3> if i > j, then sum of available tokens = sum[n-1] - sum[(i-1)%n] + sum[j].
	4> now, we take token from either left end, in which case, 	ans_l = sum_val - dp((i+1)%n, j).
	5> or, we take from right side, in which case				ans_r = sum_val - dp(i, (j+1)%n);
	6> val[i][j] is the ans = max(ans_l, ans_r).
	*/
	
ll dp(int st, int en)
{
	if(st == en)
		return token[st];
	if(val[st][en] != -1)
		return val[st][en];
	//pf("(%d, %d)\n", st, en);
	ll sum_val = 0;
	if(en < st)
		sum_val = sum[n-1] - sum[(st-1)%n] + sum[en];
	else if (st != 0)
		sum_val = sum[en] - sum[st-1];
	else
		sum_val = sum[en];
	ll ans_l = sum_val - dp((st+1)%n, en);
	int en_val = (en-1)%n;
	if(en_val < 0)
		en_val += n;
	ll ans_r = sum_val - dp(st, en_val);
	val[st][en] = max(ans_l, ans_r);
	return val[st][en];
}
		
int main()
{
	int T;	cin >> T;						// number of test cases
	for(int t = 0; t < T; t++)
	{
		cin >> n;							// number of tokens
		ll ans = 0;
		int cut_pos = 0;
		memset(token, 0, sizeof(token));	// clearing all data
		memset(val, -1, sizeof(val));
		memset(sum, 0, sizeof(sum));
		forn(i, 0, n)
		{
			cin >> token[i];
			val[i][i] = token[i];
			if(i > 0)
				sum[i] = sum[i-1]+token[i];
			else
				sum[i] = token[i];
		}
		forn(i, 0, n)						// decide to cut after any position.
		{
			ll tmp_ans = dp(i, (n-1+i)%n);	// if cut before i, then answer given by dp(i, (n-1 + i)%n)
			if(tmp_ans > ans)
			{
				cut_pos = i;
				ans = tmp_ans;
			}
		}
		pf("Test Case #%d :\n", t+1);
		pf("%d %lld\n", cut_pos, ans);
	}
	return 0;
}
