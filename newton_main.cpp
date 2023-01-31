#include<iostream>
#include "math.h"

using namespace std;

double f1(const double & x)
{
	return 4*pow(x, 2) - 8*x - 5;
}

double df1(const double & x)
{
	return 8*x - 8;
}

double f2(const double & x)
{
	return exp(-pow(x, 2)) - x;
}

double df2(const double & x)
{
	return -2*x*exp(-pow(x, 2)) - 1;
}

double f3(const double & x)
{
	return log(2*x/M_PI) + sin(x);
}

double df3(const double & x)
{
	return 1./x + cos(x);
}

double (*f[3]) (const double & x) = {f1, f2, f3};
double (*df[3]) (const double & x) = {df1, df2, df3};

double newton_raphson(double (*f) (const double &),
		double (*df) (const double &), double & x0, const double & prec)
{
	double x1 = x0 - f(x0)/df(x0);

	while (abs(x1 - x0) > prec)
	{
		x0 = x1;

		x1 = x0 - f(x0)/df(x0);
	}

	return x1;

}

int main()
{

	int input;
	cout << "Enter a number: ";
	cin >> input;

	while (input >= 1 && input <= 3)
	{
		if (input < 1 || input > 3)
			break;

		double x0 = 1.5;
		double x1 = newton_raphson(f[input-1], df[input-1], x0, pow(10, -4));

		cout << "The root of the function f" << input << "(x) is at x = " << x1 << endl;
		cout << "Enter another number: ";
		cin >> input;
	}
	return 0;
}
