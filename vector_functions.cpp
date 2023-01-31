#include "math.h"

void addVectors(double const * a, double const * b, double * c, const int & n)
{
	for (int i = 0; i < n; ++i)
		*(c + i) = *(a + i) + *(b + i);
}

double lenVector(double const * v, int const & n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += pow(*(v + i), 2);

	sum = sqrt(sum);

	return sum;
}

double dotVectors(double const * a, double const * b, int const & n)
{
	double dotProduct = 0;
	for (int i = 0; i < n; ++i)
		dotProduct += *(a + i) * *(b + i);

	return dotProduct;
}

double angleVectors(double const * a, double const * b, int const & n)
{
	return acos(dotVectors(a, b, n)/(lenVector(a, n) * lenVector(b, n))) * 180. / M_PI;
}
