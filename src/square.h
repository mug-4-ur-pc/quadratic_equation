/*
 * @file
 * @brief It is header for square.c
 */


#ifndef SQUARE_H_

#define SQUARE_H_

#include <stdbool.h>


/*! The number of possible roots of a quadratic equation.                    */
typedef enum count_of_roots_
{
	INF_ROOTS = -1,
	ZERO_ROOTS = 0,
	ONE_ROOT = 1,
	TWO_ROOTS = 2
}
count_of_roots;

/*! Presicion of real numbers comparison.                                    */
#define ACCURACY 1.0e-4

/*! Number of data entry attempts.                                           */
#define N_ATTEMPTS 5

/*!
 * This function solves quadratic equation with given
 *  coefficients.
 *
 * @return Number of roots.
 * @note If equation has one root x1 and x2 get the same values.
 */
count_of_roots solve_quadratic_equation
(
	const double a, /*!< [in]  coefficient at x squared of quadratic
	                 *         equation.                                     */
	const double b, /*!< [in]  coefficient at x of quadratic equation.       */
	const double c, /*!< [in]  free coefficient of quadratic equation.       */
	double*      x1,/*!< [out] pointer to variable to which this function
	                 *         will assign larger root values.               */
	double*      x2 /*!< [out] pointer to variable to which this function
	                 *         will assign smaller root values.              */
);

/*!
 * This function solves linear equation with given coefficients.
 *
 * @return number of roots.
 * @note IF equation haven't roots x doesn't get value
 */
count_of_roots solve_linear_equation
(
	const double k,/*!< [in] coefficient at x of linear equation,            */
	const double b,/*!< [in]  free coefficient  of linear equation,          */
	double*      x /*!< [out] pointer to variable to which this function
	                          will assign root value.                        */
);

/*! This function reads three double values from stdin.
 *
 * @return function returns true if values are read successfuly else it returns false
 */
bool get_input
(
	double* a,/*!< [out] Pointer to variable that will be assigned value
	                     obtained from stdin.                                */
	double* b,/*!< [out] Pointer to variable that will be assigned value
	                     obtained from stdin.                                */
	double* c/*!< [out] Pointer to variable that will be assigned value
	                     obtained from stdin.                                */
);

/*!
 * This function cleans input buffer.
 * @note This function uses getchar()
 */
void clean_buffer (void);

/*!
 * This function outputs roots of quadratic equation to stdout.
 */
void print_results
(
	const count_of_roots n_roots,/*!< [in] number of roots.                  */
	const double         x1,     /*!< [in] root of quadratic equation.       */
	const double         x2      /*!< [in] root of quadratic equation.       */
);

/*!
 * This function compares two double numbers with accurancy.
 *
 * @return if numbers equals function returns true, else it returns false.
 */
int equals_for_doubles
(
	const double a,/*!< [in] number to compare.                              */
	const double b /*!< [in] number to compare.                              */
);

#endif // ifndef SQUARE_H_
