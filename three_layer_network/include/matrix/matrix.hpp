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

			N& operator()(std::size_t idx_x, std::size_t idx_y) {
				return _data[idx_x][idx_y];
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
