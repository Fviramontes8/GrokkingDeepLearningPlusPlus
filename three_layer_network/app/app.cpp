#include <iostream>
#include <vector>

#include "../include/matrix/matrix.hpp"

FENK::Matrix2D<float> neural_network(
		const FENK::Matrix2D<float>& input, 
		const std::vector<FENK::Matrix2D<float>>& weights) {
	FENK::Matrix2D<float> hidden_result = weights[0] * input;
	return weights[1] * hidden_result;
}

// Prediciting on predictions
int main() {
	FENK::Matrix2D<float> input_data = {
		{8.5, 9.5, 9.9, 9.0},
		{0.65, 0.8, 0.8, 0.9},
		{1.2, 1.3, 0.5, 1.0}
	};

	FENK::Matrix2D<float> input_weights = {
		{0.1, 0.2, -0.1},
		{-0.1, 0.1, 0.9},
		{0.1, 0.4, 0.1}
	};

	FENK::Matrix2D<float> hidden_layer_weights = {
		{0.3, 1.1, -0.3},
		{0.1, 0.2, 0.0},
		{0.0, 1.3, 0.1}
	};

	std::vector<FENK::Matrix2D<float>> weights = {
		input_weights,
		hidden_layer_weights
	};

	FENK::Matrix2D<float> pred = neural_network(input_data, weights);
	std::cout << pred << '\n';

	return 0;
}
