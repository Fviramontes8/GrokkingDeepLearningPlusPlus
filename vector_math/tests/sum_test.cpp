#include <cassert>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

int main() {
	std::vector<float> a = {1, 2, 3, 4};
	assert(FENK::vector_sum(a) == 10);

	std::vector<float> b = {1, 2, 3, 4, 5};
	assert(FENK::vector_sum(b) == 15);

	return 0;
}
