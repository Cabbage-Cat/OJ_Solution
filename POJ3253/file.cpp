#include <cstdio>
#include <cstring>

int N,L[21000];

void solve();
void swap(int*,int*);

int main()
{
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&L[i]);
	solve();

	return 0;
}

void solve()
{
	long long int ans = 0;

	while (N>1)
	{
		int min1 = 0,min2 = 1;
		if (L[min1] > L[min2])
			swap(&L[min1],&L[min2]);
		
		for (int i=2;i<N;i++)
		{
			if (L[i] < L[min1])
			{
				min2 = min1;
				min1 = i;
			}
			else if (L[i] < L[min2])
				min2 = i;
		}

		// glue the two smallest board together.
		
		int tmp = L[min1] + L[min2];
		ans+=tmp;

		if (min1 == N-1)
			swap(&L[min1],&L[min2]);
		L[min1] = tmp;
		L[min2] = L[N-1];
		N--;
	}

	printf("%lld\n",ans);
}

void swap(int *a1,int *a2)
{
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}