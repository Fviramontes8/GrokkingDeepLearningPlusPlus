#include <iostream>
#include <vector>

float sq(float x) {
	return x * x;
}

int main() {
	float weight = 0.5f;
	float input = 0.5f;
	float goal_pred = 0.8f;

	float step_amount = 0.001f;

	for (int i=0; i<1101; ++i) {
		float pred = input * weight;
		float error = sq(pred - goal_pred);

		std::cout << "Error: " << error << "\tPrediction: " << pred << '\n';

		float pred_up = input * (weight + step_amount);
		float error_up = sq(goal_pred - pred_up);

		float pred_down = input * (weight - step_amount);
		float error_down = sq(goal_pred - pred_down);

		if (error_down < error_up) {
			weight -= step_amount;
		}
		else if (error_up < error_down) {
			weight += step_amount;
		}
	}

	return 0;
}
