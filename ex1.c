#include <stdio.h>

void input(int *p, int N);
void output(int *p, int N);

int main()
{
	int M, N, k;
	int x[100], y[100];
        int i;
	
	scanf("%d %d", &M, &N);
	input(x, M);
	input(y, N);
	
	scanf("%d", &k);	
	
	if (M < N)
	{
		for (i = 0; i < M; i += k)
	    {		
			output((x + i), k);
			output((y + i), k);		
		}
	
		for (i = M; i < N; i += k)
			output((y+i), k);
	}
	else
	{
		for (i = 0; i < N; i += k)
		{		
			output((x + i), k);
			output((y + i), k);	
		}	
		
		for (i = N; i < M; i += k)
			output((x+i), k);
	}	
	return 0;
}

void input(int *p, int N)
{
	int *tmp;
	
	for (tmp = p; tmp < p + N; tmp++)
		scanf("%d", tmp);
}

void output(int *p, int N)
{
	int *tmp;
	
	for (tmp = p; tmp < p + N; tmp++)
		printf(" %d", *tmp);
}
