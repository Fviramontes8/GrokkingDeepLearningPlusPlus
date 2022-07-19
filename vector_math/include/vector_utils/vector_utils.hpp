#include <vector>

namespace FENK {
	/*
	 * @brief Will iterate through two vectors and add their elements
	 * 	together into a new vector.
	 *
	 * 	@param x A vector of floating point values
	 * 	@param y Another vector of floating point values
	 *
	 * 	@return A vector representing the element-wise sum of x and y
	 */
	std::vector<float> element_add(
		const std::vector<float>& x, 
		const std::vector<float>& y
	);
	
	/*
	 * @brief Will iterate through two vectors and multiply their elements
	 * 	together into a new vector.
	 *
	 * 	@param x A vector of floating point values
	 * 	@param y Another vector of floating point values
	 *
	 * 	@return A vector representing the element-wise product of x and y
	 */
	std::vector<float> element_multiply(
		const std::vector<float>& x, 
		const std::vector<float>& y
	);
	
	/*
	 * @brief Iterates though the container and accumulates the entire
	 * 	content of the container into a singular value.
	 *
	 * 	@param v A vector of floating point values
	 *
	 * 	@return A float representing the sum of all the elements of v
	 */
	float vector_sum(const std::vector<float>& v);
	
	/*
	 * @brief Iterates though the container and accumulates the entire
	 * 	content of the container into a singular value, then the value
	 * 	is divided by the size of the vector. Raises an error if the size
	 * 	is zero.
	 *
	 * 	@param v A vector of floating point values
	 *
	 * 	@return A float representing the sum of all the elements of v
	 */
	float vector_avg(const std::vector<float>& v);

	/*
	 * @brief Iterates through both x and y, taking the multiple of each 
	 * 	element and adding it to an accumulator, resulting in the dot 
	 * 	product of x and y.
	 *
	 * 	@param x A vector of floating point values
	 * 	@param y Another vector of floating point values
	 *
	 * 	@return The sum of products from vectors x and y
	 */
	float dot_product(
		const std::vector<float>& x, 
		const std::vector<float>& y
	);

	/*
	 * @brief Will print the contents of both vectors along with printing to
	 * 	std::cerr that they are not the same.
	 *
	 * @param x A vector
	 * @param y Another vector
	 */
	void print_vector_error(
		const std::vector<float>& x, 
		const std::vector<float>& y
	);

	/*
	 * @brief Will compare the contents of two versions, if the vectors are 
	 * 	different, the contents of both vectors will be printed in std::err.
	 *
	 * @param x The first float vector to be compared
	 * @param y The second float vector to be compared
	 *
	 * @see print_vector_error
	 *
	 * @return true if bother vectors are the same, false otherwise
	 */
	bool compare_vector(
		const std::vector<float>& x, 
		const std::vector<float>& y
	);
}
