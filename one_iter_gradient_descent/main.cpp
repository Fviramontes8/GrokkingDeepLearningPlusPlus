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
	float alpha = 0.1f;

	float number_of_toes = 8.5f;
	float win_lose = 1.0f;

	float input = number_of_toes;
	float goal_pred = win_lose;

	float pred = neural_network(input, weight);
	float delta = pred - goal_pred;
	float error = sq(delta);

	float weight_delta = input * delta;
	weight -= weight_delta * alpha;

	return 0;
}
