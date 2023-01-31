#include <iostream>
#include<fstream>
#include "matrix_functions.h"

using namespace std;

void printMatrix(ofstream& out, const double * M, const int & r, const int & c, string name)
{
	out << name << endl;
	for (int i = 0; i < r*c; ++i)
	{
		if (i % c == 0)
			out << endl;
		out << M[i] << " ";
	}
	out << endl << endl;
}

int main()
{
	ifstream infile("dataVector");
	ofstream outfile("matrixMath");

	if (!infile)
	{
		cout << "no infile";
		exit(1);
	}
	if (!outfile)
	{
		cout << "no outfile";
		exit(2);
	}

	int i = 0;
	int d = 4;
	double M1[d*d];
	while(!infile.eof())
	{
		infile >> M1[i];
		++i;
	}

	printMatrix(outfile, M1, d, d, "Original Matrix");

	double M[d*d];
	matTranspose(M1, d, d, M);

	printMatrix(outfile, M, d, d, "Transpose Matrix");

	matMult(M1, M1, d, d, d, d, M);

	printMatrix(outfile, M, d, d, "M1xM1 Matrix");

	infile.close();
	outfile.close();
	return 0;
}
