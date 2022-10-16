/*!
 * @file
 * @brief This file include unit tests.
 */

#include "test.h"

#include <stdio.h>
#include <math.h>


void solve_quadratic_equation_test (const char* filename)
{
	double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
	double correct_result_1 = NAN, correct_result_2 = NAN;

	count_of_roots n_roots         = ZERO_ROOTS;
	count_of_roots correct_n_roots = ZERO_ROOTS;
	
	FILE* test_file = fopen(filename, "r");

	if (!test_file)
	{
		puts("File \"UnitTest\" is not found.\n");
		return;
	}

	while (fscanf(test_file, "%lg %lg %lg %d %lg %lg", &a, &b, &c,
	              &correct_n_roots, &correct_result_1, &correct_result_2) == 6)
	{
		n_roots = solve_quadratic_equation(a, b, c, &x1, &x2);

		if (incorrect_answer(n_roots, correct_n_roots,
		                     x1, correct_result_1,
		                     x2, correct_result_2))
		{
			printf("For a = %.4f, b = %.4f, c = %.4f you must"
			       "have %d roots, x1 = %.4f,"
			       "x2 = %.4f.\n",
			       a, b, c, correct_n_roots,
			       correct_result_1,
			       correct_result_2);
			
			printf("But you have %d roots, your x1 = %.4f,"
			       "x2 = %.4f\n", n_roots, x1, x2);
		}
	}

	puts("Unit test completed.\n\n");
	fclose(test_file);
}


bool incorrect_answer (const count_of_roots n,
                       const count_of_roots correct_n,
                       const double x1, const double correct_x1,
                       const double x2, const double correct_x2)
{
	if (correct_n == n)
	{
		if (n == INF_ROOTS || n == ZERO_ROOTS)
		{
			return false;
		}	
		else
		{
			if (equals_for_doubles(correct_x1, x1)
                && (n == ONE_ROOT 
                    || equals_for_doubles(correct_x2, x2)))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		return true;
	}
}


