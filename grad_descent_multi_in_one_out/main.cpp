#include <cassert>
#include <cstddef>
#include <iostream>
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
		const std::vector<float>& x,
		float scalar) {
	std::vector<float> result(x.size(), 0.0f);
	for (std::size_t i=0u; i<x.size(); ++i) {
		result[i] = x[i] * scalar;
	}
	return result;
}

float sq(float x) {
	return x * x;
}

float neural_network(const std::vector<float>& inputs,
		const std::vector<float>& weights) {
	return vector_dot(inputs, weights);
}

int main() {
	std::vector<float> weights = {0.1f, 0.2f, -0.1f};
//	const std::vector<std::vector<float>> input = {
//		{8.5f, 0.65f, 1.2f},
//		{9.5f, 0.8f, 1.3f},
//		{9.9f, 0.8f, 0.5},
//		{9.0f, 0.9f, 1.0f}
//	};
	const std::vector<float> input = {8.5f, 0.65f, 1.2f};

	//std::vector<float> win_lose_binary = {1.0f, 1.0f, 0.0f, 1.0f};
	const float alpha = 0.3;
	const float actual = 1.0f;

	for (std::size_t i=0; i<3; ++i) {
		const float pred = neural_network(input, weights);
		const float delta = pred - actual;
		const float error = sq(delta);
	
		std::vector<float> weight_deltas = vector_element_multiply(input, delta);
		weight_deltas[0] = 0;
		for (std::size_t i=0u; i<weights.size(); ++i) {
			weights[i] -= (alpha * weight_deltas[i]);
		}
		std::cout << "Weights:\n";
		for (const auto& x: weights) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	
		std::cout << "\tWeight deltas:\n\t";
		for (const auto& x: weight_deltas) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
