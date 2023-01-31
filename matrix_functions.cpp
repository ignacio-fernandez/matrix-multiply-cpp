#include "vector_functions.h"

void matTranspose(double const *M, const int &r, const int &c, double *Mt)
{
	int n = r * c;
	int row = 0;
	int col = 0;
	for (int i = 0; i < n; ++i)
	{
		row = i % r;
		col += (i > 0 && row % r == 0) ? 1 : 0;
		*(Mt + i) = *(M + i*c % n + col);
	}
}

void matMult(double const *M1,
		double const *M2,
		int const &r1,
		int const &c1,
		int const &r2,
		int const &c2,
		double *M
	    )
{
	if (c1 != r2)
		return;

	double M2_T[r2*c2];
	matTranspose(M2, r2, c2, M2_T);
	int row1 = 0;
	int col2 = 0;
	for (int i = 0; i < r1*c2; ++i)
	{
		col2 = i % c2;
		row1 += (i >= c2 && (i % c2 == 0)) ? 1 : 0;
		M[i] = dotVectors(M1 +  row1 * c1, M2_T + col2 * r2, c1);
	}
}
