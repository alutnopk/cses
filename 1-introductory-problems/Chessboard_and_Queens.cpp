#include <iostream>
#include <string>
#include <vector>
#include <bitset>

std::vector<std::string> grid{};
long long int count{0};
std::bitset<8> col_used{0};
std::bitset<15> diag_used_1{0}, diag_used_2{0};

void eight_queens(int row = 0)
{
	if (row == 8) // "loop" termination
	{
		count++;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		// for each valid position at row
		if (grid[row][i] == '*' || col_used[i] || diag_used_1[i - row + 7] || diag_used_2[i + row])
			continue;

		col_used.set(i);
		diag_used_1.set(i - row + 7);
		diag_used_2.set(i + row);

		eight_queens(row + 1); // end-of-"loop" jump

		diag_used_2.reset(i + row);
		diag_used_1.reset(i - row + 7);
		col_used.reset(i);
	}
}

int main()
{
	// collect input
	for (std::string line{}; std::getline(std::cin, line);)
	{
		grid.push_back(std::move(line));
	}

	eight_queens();
	std::cout << count << std::endl;
	return 0;
}
