/*!
 * @file
 * @brief It is header for test.c
 */


#ifndef TEST_H_
#define TEST_H_

#include <ctype.h>

#include "square.h"

/*!
 * @brief Unit test for solve_quadratic_equation function
 * 
 * This function solve_quadratic_equation results
 * with values written to file UnitTest.
 */
void solve_quadratic_equation_test
(
	const char* filename /*!< [in] file with UNitTest                        */
);

/*!
 * This function compares obtained values with the reference.
 * 
 * @return if comparison failed function returns true, else it returns false.
 */
bool incorrect_answer
(
	const count_of_roots correct_n, /*!< [in] correct number of roots.       */
	const count_of_roots n,         /*!< [in] number of roots obtained.      */
	const double         correct_x1,/*!< [in] correct larger root.           */
	const double         x1,        /*!< [in] x1 larger root obtained.       */
	const double         correct_x2,/*!< [in] correct smaller root.          */
	const double         x2         /*!< [in] x1 smaller root obtained.      */
);


#endif // ifndef TEST_H_
