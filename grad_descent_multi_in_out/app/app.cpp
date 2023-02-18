#include <iostream>
#include <vector>

#include "../include/matrix/matrix.hpp"

using fvector = std::vector<float>;

// Chapter 5, Predicting with multiple inputs and outputs with gradient descent
fenk::Matrix<float> neural_network(
		const fenk::Matrix<float>& input, 
		const fenk::Matrix<float>& weights
	) {
	fenk::Matrix<float> pred = weights * input;

	return pred;
}


int main() {
	fenk::Matrix<float> weights = { 
		{ 0.1, 0.1, -0.3 },
		{ 0.1, 0.2, 0.0 },
		{ 0.0, 1.3, 0.1 }
	};

	std::cout << "Weights:\n" << weights << '\n';

	fvector toes = { 8.5, 9.5, 9.9, 9.0 };
	fvector win_loss = { 0.65, 0.8, 0.8, 0.9 };
	fvector nfans = { 1.2, 1.3, 0.5, 1.0 };

	fvector hurt = { 0.1f, 0.0f, 0.0f, 0.1f };
	fvector win = { 1.0f, 1.0f, 0.0f, 1.0f };
	fvector sad = { 0.1f, 0.0f, 0.1f, 0.2f };

	fenk::Matrix<float> input = { toes, win_loss, nfans };
	fenk::Matrix<float> actual = { hurt, win, sad };

	float alpha = 0.01f;

	fenk::Matrix<float> pred = neural_network(input, weights);
	std::cout << "Pred:\n" << pred << '\n';

	fenk::Matrix<float> error = pred - actual;
	fenk::Matrix<float> delta{error};
	error.for_each([](float& x){ x = x * x; });

	std::cout << "Delta:\n" << delta << '\n';
	std::cout << "Error:\n" << error << '\n';

	// The chapter has some arithmetic failure. I hope this is the correct 
	//	implementation
	fenk::Matrix<float> delta_weights = input.seq_element_mult(delta.T());
	delta_weights.for_each([alpha](float& x) { x = alpha * x; }); 

	weights = weights - delta_weights;
	std::cout << "Updated weights:\n" << weights << '\n';
	return 0;
}
