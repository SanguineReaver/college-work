#include <bits/stdc++.h>

using namespace std;

int arr[10];

int compare(int N)
{
	int tmp = N;
	int ans = 0;
	while(N != 0)
	{
		ans += arr[N%10];
		N/= 10;
	}
//	cout << ans << '\n';
	if(ans == tmp)
		return 1;
	return 0;
}
int main()
{
	int ans = 0;
	for(int i = 1; i< 10; i++)
	{
		arr[i] = pow(i,5);
		printf("%d\t----\t%d\n", i, arr[i]);
	}
	for(int i = 10; i < 1000000; i++)
		if(compare(i))
			ans += i;
	printf("Answer is - %d\n", ans);
	return 0;
}
