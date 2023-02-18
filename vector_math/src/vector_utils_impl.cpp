#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

#include "../include/vector_utils/vector_utils.hpp"

#define DIFF_TOLERANCE 0.3

namespace FENK {
	std::vector<float> element_add(
			const std::vector<float>& x, 
			const std::vector<float>& y
		) {
		assert(x.size()==y.size());
		std::vector<float> result(x.size(), 0);
		for (int i=0; i<x.size(); ++i) {
			result[i] = x[i] + y[i];
		}
		return result;
	}
		
	
	std::vector<float> element_multiply(
			const std::vector<float>& x, 
			const std::vector<float>& y
		) {
		assert(x.size()==y.size());
		std::vector<float> result(x.size(), 0);
		for (int i=0; i<x.size(); ++i) {
			result[i] = x[i] * y[i];
		}
		return result; }
	
	float vector_sum(const std::vector<float>& v) {
		assert(v.size()!=0);
		return std::accumulate(v.begin(), v.end(), 0.0f);
	}

	float vector_avg(const std::vector<float>& v) {
		return vector_sum(v) / (float) v.size();
	}

	float dot_product(
			const std::vector<float>& x, 
			const std::vector<float>& y
		) {
		return vector_sum(element_multiply(x, y));
	}

	void print_vector_error(
			const std::vector<float>& x,
			const std::vector<float>& y
		){
		std::cerr << "Difference between vectors is greater than ";
		std::cerr << DIFF_TOLERANCE << '\n';
		std::cerr << "Got:\t\t";
		for (const auto& z: x) {
			std::cout << z << ' ';
		}
		std::cerr << '\n';
		std::cerr << "Expected:\t";
		for (const auto& z: y) {
			std::cerr << z << ' ';
		}
		std::cerr << '\n';
	}

	bool compare_vector(
			const std::vector<float>& x, 
			const std::vector<float>& y
		) {
		auto a = x.begin();
		auto b = y.begin();
		while((a!=x.end()) && (b!=y.end())) {
			const float diff = std::abs((*a) - (*b));
			if (diff > DIFF_TOLERANCE) {
				print_vector_error(x, y);
				return false;
			}
			++a;
			++b;
		}
		return true;
	}
}
