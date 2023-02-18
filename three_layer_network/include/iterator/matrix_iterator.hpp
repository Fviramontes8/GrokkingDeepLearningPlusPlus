#ifndef FENK_MATRIX_ITERATOR
#define FENK_MATRIX_ITERATOR

#include <iterator>

namespace FENK {
	template <typename T>
	struct _iterator {
		// Iterator tags
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = value_type*;
		using reference = value_type&;
	
		// Constructor
		_iterator(pointer ptr): _ptr{ptr} {}
	
		reference operator*() const {
			return *_ptr;
		}
	
		pointer operator->() {
			return _ptr;
		}

		pointer operator+(int i) {
			return _ptr + i;
		}

		pointer operator-(int i) {
			return _ptr - i;
		}
	
		// Pre --
		_iterator& operator--() {
			_ptr--;
			return *this;
		}
	
		// Pre ++
		_iterator& operator++() {
			_ptr++;
			return *this;
		}
	
		// Post --
		_iterator operator--(int) {
			_iterator tmp{*this};
			--(*this);
			return tmp;
		}
	
		// Post ++
		_iterator operator++(int) {
			_iterator tmp{*this};
			++(*this);
			return tmp;
		}
	
		friend bool operator==(
				const _iterator& lhs, const _iterator& rhs) {
			return lhs._ptr == rhs._ptr;
		}
	
		friend bool operator!=(
				const _iterator& lhs, const _iterator& rhs) {
			return !(lhs==rhs);
		}
	
		private:
			pointer _ptr;
	};
}
#endif // FENK_MATRIX_ITERATOR
