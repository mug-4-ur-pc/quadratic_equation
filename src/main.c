/*!
 * @file
 * @brief Main file.
 */

#include "square.h"

#ifdef TEST
#include "test.h"
#endif

#include <stdio.h>
#include <math.h>

/*!
 * Solves quadratic equation with coefficients
 * entered from stdin. In debug mode this function runs unit tests.
 */
int main (void)
{
	#ifdef TEST
	 	solve_quadratic_equation_test("UnitTest");
	
	#else
		count_of_roots n_roots = ZERO_ROOTS;
		double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
	
		if (!get_input(&a, &b, &c))
		{
			puts("The program ended ahead of shedule.\n");
			return 1;
		}

		n_roots = solve_quadratic_equation(a, b, c, &x1, &x2);

		print_results(n_roots, x1, x2);

	#endif // ifdef TEST

	return 0;
}
