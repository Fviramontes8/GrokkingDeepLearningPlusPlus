#include <cassert>
#include <iostream>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

using fvector = std::vector<float>;

int main() {
	fvector a = {1, 2, 3, 4, 5};
	fvector b = {5, 4, 3, 2, 1};
	fvector a_b_ans = {6, 6, 6, 6, 6};
	assert(FENK::compare_vector(FENK::element_add(a, b), a_b_ans));

	fvector c = {12.9, 14.7, 82.1, 77.7, 24.42};
	fvector d = {8.22, 54.36, 0.5, 478.6, 2.19};
	fvector c_d_ans = {21.12, 69.06, 82.6, 556.3, 26.61};
	assert(FENK::compare_vector(FENK::element_add(c, d), c_d_ans));

	fvector a_c_ans = {13.9, 16.7, 85.1, 81.7, 29.42};
	assert(FENK::compare_vector(FENK::element_add(a, c), a_c_ans));

	fvector b_d_ans = {13.22, 58.36, 3.5, 480.6, 3.19};
	assert(FENK::compare_vector(FENK::element_add(b, d), b_d_ans));

	return 0;
}
