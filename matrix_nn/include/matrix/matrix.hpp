#ifndef FENK_VECT_MATRIX_CLASS
#define FENK_VECT_MATRIX_CLASS

#include <cassert>
#include <concepts>
#include <initializer_list>
#include <iostream>
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
					_cols{cols}, _data{rows, std::vector<N>(cols)} {}

			Matrix(std::size_t rows, std::size_t cols, N init_value): 
					_rows{rows}, _cols{cols}, 
					_data{rows, std::vector<N>(cols)} {
				for (auto& x: _data) {
					for (auto& y: x) {
						y = init_value;
					}
				}
			}

			Matrix(std::initializer_list<std::vector<N>> lst):
					_rows{lst.size()}, _cols{(*(lst.begin())).size()},
					_data(lst.size()) {
				std::copy(lst.begin(), lst.end(), _data.begin());
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
			Matrix seq_element_add(const Matrix& m) const {
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
			Matrix seq_element_add(const Matrix& m) {
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
			Matrix seq_element_mult(const Matrix& m) const {
				assert(cols() == m.rows());
				Matrix result(rows(), m.cols());

				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						for (std::size_t k=0; k<m.cols(); ++k) {
							result[i][k] = _data[i][j] + m[j][k];
						}
					}
				}
				return result;
			}

			// Think about multi-threading
			Matrix seq_element_mult(const Matrix& m) {
				assert(cols() == m.rows());
				Matrix result(rows(), m.cols());

				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						for (std::size_t k=0; k<m.cols(); ++k) {
							result[i][k] = _data[i][j] + m[j][k];
						}
					}
				}
				return result;
			}

			// Inner product
			Matrix seq_mult(const Matrix& m) const {
				assert(cols() == m.rows());
				Matrix result(rows(), m.cols(), static_cast<N>(0));
				for(std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						for (std::size_t k=0; k<m.cols(); ++k) {
							result[i][k] += _data[i][j] * m[j][k];
						}
					}
				}

				return result;
			}

			Matrix seq_mult(const Matrix& m) {
				assert(cols() == m.rows());
				Matrix result(rows(), m.cols(), static_cast<N>(0));
				for(std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						for (std::size_t k=0; k<m.cols(); ++k) {
							result[i][k] += _data[i][j] * m[j][k];
						}
					}
				}

				return result;
			}

			std::vector<N> seq_vect_mult(const std::vector<N>& v) const {
				assert(v.size() == cols());
				std::vector<N> result(v.size(), 0);
				for (std::size_t i=0; i<cols(); ++i) {
					for (std::size_t j=0; j<rows(); ++j) {
						result[i] += v[j] * _data[i][j];
					}
				}
				return result;
			}

			std::vector<N> seq_vect_mult(const std::vector<N>& v) {
				assert(v.size() == cols());
				std::vector<N> result(v.size(), 0);
				for (std::size_t i=0; i<cols(); ++i) {
					for (std::size_t j=0; j<rows(); ++j) {
						result[i] += v[j] * _data[i][j];
					}
				}
				return result;
			}


			// Think about multi-threading???
			Matrix T() const {
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

			std::vector<N> operator*(const std::vector<N>& v) const {
				return seq_vect_mult(v);
			}

			std::vector<N> operator*(const std::vector<N>& v) {
				return seq_vect_mult(v);
			}

			Matrix operator*(const Matrix& m) const {
				return seq_mult(m);
			}

			Matrix operator*(const Matrix& m) {
				return seq_mult(m);
			}

			const std::vector<N>& operator[](const std::size_t& idx) const {
				return _data[idx];
			}

			std::vector<N>& operator[](std::size_t idx) {
				return _data[idx];
			}

			/*
			const N& operator()(std::size_t idx_x, std::size_t idx_y) const {
				return _data[idx_x][idx_y];
			}

			N& operator()(std::size_t idx_x, std::size_t idx_y) {
				return _data[idx_x][idx_y];
			}
			*/

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

#endif // FENK_VECT_MATRIX_CLASS
