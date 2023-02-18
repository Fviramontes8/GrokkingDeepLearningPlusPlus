#include <iostream>
#include <numeric>
#include <vector>

float sq(float x) {
	return x * x;
}

int main() {
	std::vector<int> iter_range(20);
	std::iota(iter_range.begin(), iter_range.end(), 0);
	float weight = 0.0f, goal_pred = 0.8f, input = 2.0f;
	const float alpha = 0.1f;

	for (const auto& x: iter_range) {
		std::cout << "-----\nWeight: " << weight << '\n';
		const float pred = input * weight;
		const float delta = pred - goal_pred;
		const float error = sq(delta);
		const float weight_delta = delta * input;
		weight -= (weight_delta * alpha);
		std::cout << "Error: " << error << "\t\tPrediction: " << pred << '\n';
		std::cout << "Delta: " << delta << "\t\tWeight Delta: " << weight_delta;
		std::cout << '\n';
	}

	return 0;
}
