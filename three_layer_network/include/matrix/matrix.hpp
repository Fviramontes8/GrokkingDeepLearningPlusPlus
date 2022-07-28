#ifndef FENK_2D_MATRIX_CLASS
#define FENK_2D_MATRIX_CLASS

#include <cassert>			// assert
#include <cstddef>			// std::ptrdiff_t
#include <concepts>			// std::integral, std::floating_point
#include <initializer_list> // std::initializer_list
#include <iostream>			// std::ostream
#include <vector>			// std::vector

#include "../iterator/matrix_iterator.hpp"

namespace FENK {
	template <typename T>
	concept Number = std::integral<T> || std::floating_point<T>;

	template <Number N>
	class Matrix2D {
		private:
			N** _data;
			std::size_t _rows;
			std::size_t _cols;

			void matrix_alloc() {
				_data = new N*[rows()];
				assert(_data != nullptr);
				for (std::size_t i=0; i<rows(); ++i) {
					_data[i] = new N[cols()];
					assert(_data[i] != nullptr);
				}
			}

		public: 
			using iterator = struct FENK::_iterator<N*>;

			// Constructors

			Matrix2D(std::size_t rows, std::size_t cols):
					_rows{rows}, _cols{cols}, _data{nullptr} {
				matrix_alloc();
			}

			Matrix2D(std::size_t rows, std::size_t cols, N init_value):
					_rows{rows}, _cols{cols}, _data{nullptr} {
				_data = new N*[rows];
				assert(_data != nullptr);
				for (std::size_t i=0; i<rows; ++i) {
					_data[i] = new N[cols];
					assert(_data[i] != nullptr);
					for (std::size_t j=0; j<cols; ++j) {
						_data[i][j] = init_value;
					}
				}
			}

			Matrix2D(const std::initializer_list<std::vector<N>>& lst):
					_rows{lst.size()}, _cols{(*(lst.begin())).size()},
					_data{nullptr} {
				matrix_alloc();
				for (auto m_i=begin(), lst_i=lst.begin(); 
						m_i!=end(); ++m_i, ++lst_i) {
					std::copy(lst_i->begin(), lst_i->end(), *m_i);
				}
			}

			Matrix2D(const std::initializer_list<std::initializer_list<N>>& lst):
					_rows{lst.size()}, _cols{(*(lst.begin())).size()},
					_data{nullptr} {
				matrix_alloc();
				for (auto m_i=begin(), lst_i=lst.begin(); 
						m_i!=end(); ++m_i, ++lst_i) {
					std::copy(lst_i->begin(), lst_i->end(), *m_i);
				}
			}

			Matrix2D(const Matrix2D& m): _rows{m._rows}, _cols{m._cols},
					_data{nullptr} {
				matrix_alloc();
				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						_data[i][j] = m._data[i][j];
					}
				}
			}

			Matrix2D(Matrix2D&& m): _rows{std::move(m._rows)},
					_cols{std::move(m._cols)}, _data{nullptr} {
				matrix_alloc();
				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						_data[i][j] = std::move(m._data[i][j]);
					}
				}
			}

			~Matrix2D() {
				for (std::size_t i=0; i<rows(); ++i) {
					delete[] _data[i];
				}
				delete[] _data;
			}


			// Getters

			std::size_t rows() const {
				return _rows;
			}

			std::size_t cols() const {
				return _cols;
			}

			// Consider const iterator class

			iterator begin() const {
				return iterator(&_data[0]);
			}

			iterator begin() {
				return iterator(&_data[0]);
			}

			iterator end() const {
				return iterator(&_data[rows()]);
			}

			iterator end() {
				return iterator(&_data[rows()]);
			}

			// General methods
			Matrix2D seq_dot(const Matrix2D& m) const {
				assert(cols() == m.rows());
				Matrix2D result(rows(), m.cols(), static_cast<N>(0));
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


			// Think about multi-threading???
			Matrix2D T() const {
				Matrix2D result(cols(), rows());
				for (std::size_t i=0; i<rows(); ++i) {
					for (std::size_t j=0; j<cols(); ++j) {
						result[j][i] = _data[i][j];
					}
				}
				return result;
			}

			Matrix2D Transpose() const {
				return T();
			}

			std::vector<N> operator*(const std::vector<N>& v) const {
				return seq_vect_mult(v);
			}

			Matrix2D operator*(const Matrix2D& m) const {
				return seq_dot(m);
			}

			N& operator()(std::size_t idx_x, std::size_t idx_y) {
				return _data[idx_x][idx_y];
			}

			Matrix2D& operator=(const Matrix2D& m) {
				if (this == &m) {  return *this; }
				return *this;
			}

			friend std::ostream& operator<<(
					std::ostream &out, const Matrix2D& m) {
				for (const auto& x: m) {
					for (std::size_t i=0; i<m.cols(); ++i) {
						out << x[i] << ' ';
					}
					out << '\n';
				}
				return out;
			}
	};
}
#endif // FENK_2D_MATRIX_CLASS
