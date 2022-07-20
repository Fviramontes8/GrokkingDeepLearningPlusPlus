#include <cassert>
#include <concepts>
#include <initializer_list>
#include <ostream>
#include <type_traits>
#include <vector>

namespace FENK {
	template <typename T>
	concept Number = std::integral<T> || std::floating_point<T>;
	
	template <Number N>
	class Matrix {
		private:
			std::vector<std::vector<N>> _data;
			std::size_t _rows;
			std::size_t _cols;
	
		public:
			Matrix(std::size_t rows, std::size_t cols): _rows{rows}, 
					_cols{cols}, _data{rows, std::vector<N>{cols}} {}

			Matrix(std::size_t rows, std::size_t cols, N init_value): 
					_rows{rows}, _cols{cols}, 
					_data{rows, std::vector<N>{cols}} {
				for (auto& x: _data) {
					for (auto& y: x) {
						y = init_value;
					}
				}
			}

			Matrix(std::initializer_list<std::initializer_list<N>> lst):
					_rows{lst.size()}, _cols{(*(lst.begin())).size()},
					_data(lst.size()) {
				std::copy(lst.begin(), lst.end(), _data.begin());
			}

			Matrix(const Matrix& mat): _rows{mat._rows}, _cols{mat._cols},
				_data{mat._data} {}

			Matrix(Matrix&& mat): _rows{std::move(mat._rows)}, 
					_cols{std::move(mat._cols)},
					_data{std::move(mat._data)} {}
	
			std::size_t rows() const {
				return _rows;
			}

			std::size_t cols() const {
				return _cols;
			}

			// Think about multi-threading
			Matrix seq_add(const Matrix& m) {
				assert(rows() == m.rows());
				assert(cols() == m.cols());
				Matrix result(rows(), cols());

				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						result[i][j] = _data[i][j] + m[i][j];
					}
				}
				return result;
			}

			// Think about multi-threading
			Matrix seq_mult(const Matrix& m) {
				assert(cols() == m.rows());
				Matrix result(rows(), m.cols());

				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						for (std::size_t k=0; m.cols(); ++k) {
							result[i][k] = _data[i][j] + m[j][k];
						}
					}
				}
				return result;
			}

			// Think about multi-threading???
			Matrix T() {
				Matrix result(cols(), rows());

				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						result[j][i] = _data[i][j];
					}
				}
				return result;
			}

			Matrix Transpose() {
				return T();
			}

			const N& operator[](const std::size_t idx) {
				return _data[idx];
			}

			Matrix& operator=(const Matrix& mat) {
				if (this == &mat) { return *this; }

				for (auto& x: _data) {
					x.clear();
				}
				_data.clear();

				_data.reserve(mat.rows);
				for (auto& x: _data) {
					x.reserve(mat.cols());
				}
				_rows = mat.rows();
				_cols = mat.cols();

				return *this;
			}

			template <Number M>
			friend std::ostream& operator<<(
				std::ostream& out, 
				const Matrix<M>& m
			);
	};

	template <Number M>
		std::ostream& operator<<(std::ostream& out, const Matrix<M>& m) {
			for(const auto& x: m._data) {
				for(const auto& y: x) {
					out << y << ' ';
				}
				out << '\n';
			}
			return out;
		}
}
