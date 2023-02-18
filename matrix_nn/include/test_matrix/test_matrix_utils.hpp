#ifndef FENK_MATRIX_TESTS
#define FENK_MATRIX_TESTS
#include <cassert>

#include "../matrix/matrix.hpp"


namespace FENK {
	#define FENK_DIFF_TOLERANCE 0.1

	template <Number Q>
	bool compare_matrices(const Matrix<Q>& lhs, const Matrix<Q>& rhs) {
		assert(lhs.rows() == rhs.rows());
		assert(lhs.cols() == rhs.cols());

		for (std::size_t i_x=0, j_x=0; i_x<lhs.rows(); ++i_x, ++j_x) {
			for (std::size_t i_y=0, j_y=0; i_y<lhs.cols(); ++i_y, ++j_y) {
				Q diff = std::abs(lhs[i_x][i_y] - rhs[j_x][j_y]);
				if (static_cast<float>(diff) > 0.1f) {
					return false;
				}
			}
		}
		return true;
	}
}

#endif // FENK_MATRIX_TESTS
