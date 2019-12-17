#include "Field.h"

bool Field::check()
{
	for (int i = 0; i < 4; i++)
		if ((a[i].x < 0) || (a[i].x >= N) || (a[i].y >= M)) return 0;
		else if (field[a[i].y][a[i].x]) return 0;
	return 1;
}

void Field::check_lines()
{
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < N) k--;
	}
}