#include <array>
#include <cassert>
#include <iostream>
#include <ranges>

using farray3 = std::array<float, 3>;

float weight_sum(const farray3& inputs, const farray3& weights) {
	float output = 0.0f;
	for(int i = 0; i<inputs.size(); ++i) {
		output += (inputs[i] * weights[i]);
	}
	return output;
}

float neural_network_forward(const farray3& inputs, const farray3& weights) {
	return weight_sum(inputs, weights);
}

int main() {
	farray3 weights = {0.1, 0.2, 0};

	std::array<float, 4> number_of_toes = {8.5, 9.5, 9.9, 9.0};
	std::array<float, 4> win_loss_ratio = {0.65, 0.8, 0.8, 0.9};
	std::array<float, 4> number_of_fans = {1.2, 1.3, 0.5, 1.0};

	for (int i: std::ranges::iota_view{0, 4}) {
		float pred = neural_network_forward(
			{number_of_toes[i], win_loss_ratio[i], number_of_fans[i]},
			weights
		);
		std::cout << pred << '\n';
	}

	return 0;
}
