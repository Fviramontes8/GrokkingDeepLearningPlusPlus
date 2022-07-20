#include <iostream>
#include <vector>

#include "../include/matrix/matrix.hpp"

using fvector = std::vector<float>;

// Chapter 3, Predicting with multiple inputs and outputs
fvector neural_network(
		const fvector& input, 
		const FENK::Matrix<float>& weights
	) {
	fvector pred = weights * input;

	return pred;
}

int main() {
	FENK::Matrix<float> weights = { 
		{0.1, 0.1, -0.3},
		{0.1, 0.2, 0.0 },
		{0.0, 1.3, 0.1}
	};

	std::cout << weights << '\n';

	fvector toes = {8.5, 9.5, 9.9, 9.0};
	fvector win_loss = {0.65, 0.8, 0.8, 0.9};
	fvector nfans = {1.2, 1.3, 0.5, 1.0};

	FENK::Matrix<float> input = {
		toes,
		win_loss,
		nfans
	};

	for (std::size_t i=0; i<toes.size(); ++i) {
		fvector result = neural_network(
			{input[0][i], input[1][i], input[2][i]},
			weights
		);
		for (const auto& x: result) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
