#include <stdio.h>
#include <stdlib.h>

int check_row(int **p, int M, int N);
int check_col(int **p, int M, int N);

int main()
{
	int M, N;
	int **p = NULL;
	int i, j;
	int x, y, z;
	int max_row, max_col;
	
	scanf("%d %d", &M, &N);
	p = (int **)malloc(M * sizeof(int *));

	
	for (i = 0; i < M; i++)
		p[i] = (int *)malloc(N * sizeof(int));
		
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			p[i][j] = 0;
		
	do {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0)
			break;
		
		p[x][y] = z;
		
	}while(1);
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
	
	max_row = check_row(p, M, N);
	max_col = check_col(p, M, N);
	
	if (max_row < max_col)
		printf("%d", max_col);
	else
		printf("%d", max_row); 
	
	for (i=0; i<M; i++)
		free(p[i]);
	free(p);
	
	return 0;
}

int check_row(int **p, int M, int N)
{
	int i, j, cnt, max = 0;

	for (i = 0; i < M; i++)
	{
		cnt=0;
		for (j = 0; j < N; j++)
		{
			if (p[i][j]==0)
				cnt++;
			else
			{
				if (max < cnt)
					max = cnt;
				cnt=0;
			}
		}
		if (max < cnt)
			max = cnt;
	}
	return max;
}

int check_col(int **p, int M, int N)
{
	int i, j, cnt, max = 0;

	for (i = 0; i < N; i++)
	{
		cnt = 0;
		for (j = 0; j < M; j++)
		{
			if (p[j][i] == 0)
				cnt++;
			else
			{
				if (max < cnt)
					max = cnt;
				cnt=0;
			}
		}
		if (max < cnt)
			max = cnt;
	}
	return max;
}
