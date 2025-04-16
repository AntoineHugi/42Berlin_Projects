#include "main.h"

void	print_board(int size, int board[size][size])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (board[i][j] == 'x')
				printf("%i,", j);
			j++;
		}
		j = 0;
		i++;
	}
	printf("\n");
}

void	init_board(int size, int (*board)[size])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			board[i][j] = 'o';
			j++;
		}
		j = 0;
		i++;
	}
}

int		safe_to_place(int size, int row, int column, int board[size][size])
{
	int	i;

	i = 0;
	while (i < size)
	{
			if (board[row][i] == 'x' || board[i][column] == 'x')
				return (0);
			if (row + i < size && column + i < size)
			{
				if (board[row + i][column + i] == 'x')
					return (0);
			}
			if (row + i < size && column - i >= 0)
			{
				if (board[row + i][column - i] == 'x')
					return (0);
			}
			if (row - i >= 0 && column - i >= 0)
			{
				if (board[row - i][column - i] == 'x')
					return (0);
			}
			if (row - i >= 0 && column + i < size)
			{
				if (board[row - i][column + i] == 'x')
					return (0);
			}
			i++;
	}
	return (1);
}

void	solve_queens(int size, int start, int board[size][size])
{
	int	row;
	int	column;

	if (start == size)
	{
		print_board(size, board);
		return ;
	}
	else
	{
		row = 0;
		column = start;
		while (row < size)
		{
			if (safe_to_place(size, row, column, board))
			{
				board[row][column] = 'x';
				solve_queens(size, start + 1, board);
				board[row][column] = 'o';
			}
			row++;
		}
	}
}

void	queens(int size)
{
	int	board[size][size];

	init_board(size, board);
	solve_queens(size, 0, board);
}