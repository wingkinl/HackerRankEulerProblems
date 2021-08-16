#include "P011_LargestProductInAGrid.h"
#include <iostream>


long P011_LargestProductInAGrid::Solve(const int (&grid)[20][20])
{
	const size_t kGridSize = 20;
	long max_product = 0;
	for (size_t ii = 0; ii < kGridSize; ++ii)
	{
		for (size_t jj = 0; jj < kGridSize - 3; ++jj)
		{
			long product1 = grid[ii][jj] * grid[ii][jj + 1] * grid[ii][jj + 2] * grid[ii][jj + 3];
			if (product1 > max_product)
				max_product = product1;
			long product2 = grid[jj][ii] * grid[jj + 1][ii] * grid[jj + 2][ii] * grid[jj + 3][ii];
			if (product2 > max_product)
				max_product = product2;
		}
	}
	for (size_t ii = 0; ii < kGridSize - 3; ++ii)
	{
		for (size_t jj = 0; jj < kGridSize - 3; ++jj)
		{
			long product1 = grid[ii][jj] * grid[ii + 1][jj + 1] * grid[ii + 2][jj + 2] * grid[ii + 3][jj + 3];
			if (product1 > max_product)
				max_product = product1;
			long product2 = grid[ii][jj + 3] * grid[ii + 1][jj + 2] * grid[ii + 2][jj + 1] * grid[ii + 3][jj];
			if (product2 > max_product)
				max_product = product2;
		}
	}
	return max_product;
}

void P011_LargestProductInAGrid::main()
{
	std::ios_base::sync_with_stdio(false);
	int grid[20][20];
	for (int grid_i = 0; grid_i < 20; grid_i++) {
		for (int grid_j = 0; grid_j < 20; grid_j++) {
			std::cin >> grid[grid_i][grid_j];
		}
	}
	std::cout << Solve(grid) << "\n";
}
