#include <array>
#include <iostream>

float linear_nn_forward(float  input, float weight) {
	return input * weight;
}

int main() {
	float weight = 0.1f;
	std::array<float, 4> number_of_toes = {8.5, 9.5, 10, 9};

	for (const auto &x : number_of_toes) {
		float nn_pred = linear_nn_forward(x, weight);
		std::cout << "Linear NN prediction for value " << x;
		std::cout << ": " << nn_pred << '\n';
	}

	return 0;
}
