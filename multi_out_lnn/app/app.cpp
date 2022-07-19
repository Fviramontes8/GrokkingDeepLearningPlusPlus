#include <array>
#include <iostream>

#include "../include/linear_nn/linear_nn.hpp"

int main () {
	std::array<float, 3> weights = {0.3, 0.2, 0.9};
	std::array<float, 4> win_loss = {0.65, 0.8, 0.8, 0.9};

	for (const auto& x : win_loss) {
		const std::array<float, 3> pred = linear_neural_network(x, weights);
		for (const auto& y: pred) {
			std::cout << y << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
