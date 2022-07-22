#include <iostream>

#include "../include/matrix/matrix.hpp"

int main() {
	FENK::Matrix2D<int> x(2, 2, 1);

	FENK::Matrix2D<int> y(2, 2, 7);

	std::cout << x << '\n';
	std::cout << y << '\n';

	FENK::Matrix2D z = {
		{1, 2, 3},
		{4, 5, 6}
	};

	std::cout << z << '\n';

	return 0;
}
