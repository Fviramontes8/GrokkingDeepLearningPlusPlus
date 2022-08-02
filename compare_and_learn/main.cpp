#include <iostream>
#include <vector>

float sq(float x) {
	return x * x;
}

float neural_network(float input, float weight) {
	return input * weight;
}

int main() {
	float weight = 0.1f;
	float lr = 0.01f;
	float number_of_toes = 8.5f;
	float win_lose_ratio = 1.0f;

	float input = number_of_toes;
	float actual = win_lose_ratio;

	float pred = neural_network(input, weight);
	float error = sq(pred - actual);
	std::cout << "Error: " << error << '\n';

	float pred_up = neural_network(input, weight + lr);
	float error_up = sq(pred_up - actual);
	std::cout << "Error + learning rate: " << error_up << '\n';

	float pred_down = neural_network(input, weight - lr);
	float error_down = sq(pred_down - actual);
	std::cout << "Error + learning rate: " << error_down << '\n';

	/*
	 * if ((error > error_down) || (error > error_up)) {
	 * 	if (error_down < error_up) {
	 * 		weight -= lr;
	 * 	}
	 * 	if (error_up < error_down) {
	 * 		weight += lr;
	 * 	}
	 * }
	 */
		
	return 0;
}
