#include <iostream>

#include "../include/matrix/matrix.hpp"

int main() {
	FENK::Matrix<int> m = { 
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	std::cout << m << '\n';

	return 0;
}
