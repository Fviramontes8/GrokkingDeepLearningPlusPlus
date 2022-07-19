#include <cassert>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

int main() {
	std::vector<float> a = {1, 2, 3, 4, 5};
	assert(FENK::vector_avg(a) == 3);

	std::vector<float> b = {
		12.6f, 8.1f, 16.41f, 
		75.8f, 92.9f, 4.72f,
		64.04f, 9.99f, 376.94f
	};
	assert(FENK::vector_avg(b) == 73.5);

	return 0;
}
