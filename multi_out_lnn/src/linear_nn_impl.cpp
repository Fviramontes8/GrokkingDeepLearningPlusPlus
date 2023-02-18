#include "../include/linear_nn/linear_nn.hpp"

std::array<float, 3> linear_neural_network(
		float input, 
		std::array<float, 3>& weights
	) {
	std::array<float, 3> output;
	for(int i=0; i<weights.size(); ++i) {
		output[i] = input * weights[i];
	}
	return output;
}
