#include <iostream>
#include <vector>

float sq(float x) {
	return x * x;
}

int main() {
	float weight = 0.5f;
	float goal_pred = 0.8f;
	float input = 0.5f;

	for (int i=0; i<20; ++i) {
		float pred = input * weight;
		float error = sq(pred - goal_pred);
		float dir_and_amt = (pred - goal_pred) * input;

		std::cout << "Direction and magnitude: " << dir_and_amt << '\n';
		weight -= dir_and_amt;

		std::cout << "Error: " << error << "\tPrediction: " << pred << '\n';

	}
	return 0;
}
