#include <cassert>
#include <iostream>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

using fvector = std::vector<float>;

int main() {
	fvector x = {12, 5, 9, 20, 3, 9, 43};
	fvector y = {6, 17, 3.8, 4, 7.1, 12, 0.03};

	fvector x_y_ans = {72, 85, 34.2, 80, 21.3, 108, 1.29};
	assert(FENK::compare_vector(FENK::element_multiply(x, y), x_y_ans));

	fvector z = {7, 3, 4.4, 9.1, 5.2, 1.6, 0.8};
	fvector x_z_ans = {84, 15, 39.6, 182, 15.6, 14.4, 34.4};
	fvector y_z_ans = {42, 51, 16.72, 36.4, 36.92, 19.2, 0.024};
	assert(FENK::compare_vector(FENK::element_multiply(x, z), x_z_ans));
	assert(FENK::compare_vector(FENK::element_multiply(y, z), y_z_ans));

	return 0;
}
