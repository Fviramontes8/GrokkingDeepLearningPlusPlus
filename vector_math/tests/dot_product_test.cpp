#include <cassert>
#include <iostream>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

using fvector = std::vector<float>;

float ugly_dot_product(
		const fvector& x,
		const fvector& y
	) {
	float acc = 0.0f;
	auto a = x.begin();
	auto b = y.begin();
	while( (a!=x.end()) && (b!=y.end())) {
		acc += (*a) * (*b);
		++a;
		++b;
	}
	return acc;
}

int main() {
	fvector a = {1, 2, 3, 4, 5};
	fvector b = {5, 4, 3, 2, 1};

	assert(FENK::dot_product(a, b)==ugly_dot_product(a, b));

	fvector c = {12.9, 14.7, 82.1, 77.7, 24.42};
	fvector d = {8.22, 54.36, 0.5, 478.6, 2.19};
	assert(FENK::dot_product(c, d)==ugly_dot_product(c, d));

	return 0;
}
