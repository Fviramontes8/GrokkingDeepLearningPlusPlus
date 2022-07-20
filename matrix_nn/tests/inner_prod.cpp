#include <cassert>
#include <iostream>

#include "../include/matrix/matrix.hpp"
#include "../include/test_matrix/test_matrix_utils.hpp"

int main() {
	FENK::Matrix<int> a = {
		{1, 2, 3},
		{4, 5, 6}
	};

	FENK::Matrix<int> b = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	FENK::Matrix<int> ans = {
		{38, 44, 50, 56},
		{83, 98, 113, 128}
	};

	FENK::Matrix<int> c = a * b;
	
	assert(FENK::compare_matrices(ans, c));

	return 0;
}
