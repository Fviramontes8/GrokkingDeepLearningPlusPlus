#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ranges>
#include <vector>

float vector_dot(const std::vector<float>& input, 
		const std::vector<float>& weights) {
	assert(input.size() == weights.size());
	float result = 0.0f;
	for (std::size_t i=0u; i<input.size(); ++i) {
		result += input[i] * weights[i];
	}
	return result;
}

std::vector<float> vector_element_multiply(
		float scalar,
		const std::vector<float>& x) {
	std::vector<float> result(x.size(), 0.0f);
	for (std::size_t i=0u; i<x.size(); ++i) {
		result[i] = x[i] * scalar;
	}
	return result;
}

float sq(float x) {
	return x * x;
}

std::vector<float> neural_network(float inputs, const std::vector<float>& weights) {
	return vector_element_multiply(inputs, weights);
}

std::vector<float> operator-(const std::vector<float>& a, 
		const std::vector<float>& b) {
	assert(a.size() == b.size());
	std::vector<float> result(a.size());
	for (int i=0; i<a.size(); ++i) {
		result[i] = a[i] - b[i];
	}
	return result;
}


int main() {
	std::vector<float> weights = {0.3f, 0.2f, 0.9f};
	float input = 0.65;

	std::vector<float> actual = {0.1f, 1.0f, 0.1f};

	const std::vector<float> pred = neural_network(input, weights);
	const std::vector<float> delta = pred - actual;
	std::vector<float> error{delta};
	std::ranges::for_each(error, [](float& x) { x = x * x; });
	
	std::ranges::for_each(delta, [](float x) { std::cout << x << ' ';});
	std::cout << '\n';
	
	std::ranges::for_each(error, [](float x) { std::cout << x << ' ';});
	std::cout << '\n';

	std::vector<float> weight_deltas = vector_element_multiply(input, weights);

	float alpha = 0.1f;

	for (int i=0; i<weights.size(); ++i) {
		weights[i] -= (weight_deltas[i] * alpha);
	}
	
	std::ranges::for_each(weights, [](float x) { std::cout << x << ' ';});
	std::cout << '\n';

	std::ranges::for_each(weight_deltas, [](float x) { std::cout << x << ' ';});
	std::cout << '\n';

	return 0;
}
