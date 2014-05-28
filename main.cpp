#include <iostream>
#include <stdio.h>

struct point
{
	int weight;
	bool isVisited = false;
};

int main()
{
	int N;
	std::cin >> N;
	point *length = new point[N];
	int **matrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
		length[i].isVisited = false;
		length[i].weight = -1;

		for (int j = 0; j < N; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	length[0].weight = 0;

	for (int r = 0; r < N; r++)
	{
		int num = -1;
		int min = -1;
		for (int i = 0; i < N; i++)
		{
			if ((!length[i].isVisited) && (((length[i].weight < min) || (min == -1)) && (length[i].weight != -1)))
			{
				num = i;
				min = length[num].weight;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if ((matrix[num][i] != 0) && (!length[i].isVisited))
			{
				if ((length[num].weight + matrix[num][i] < length[i].weight) || (length[i].weight == -1))
				{
					length[i].weight = length[num].weight + matrix[num][i];
				}
			}

		}
		length[num].isVisited = true;
	}
	for (int r = 0; r < N; r++)
	{
		std::cout << length[r].weight << " ";
	}
}