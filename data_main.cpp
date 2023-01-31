#include<iostream>
#include<fstream>
#include "vector_functions.h"

using namespace std;

int main()
{
	ifstream infile("dataVector");
	ofstream outfile("vectorMath");

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

	int dimension = 4;
	double a[dimension][dimension]{};
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			infile >> a[i][j];
		}
	}

	double first_sum [dimension];
	double second_sum [dimension];
	double total_sum [dimension];

	addVectors(a[0], a[1], first_sum, dimension);
	addVectors(a[2], a[3], second_sum, dimension);
	addVectors(first_sum, second_sum, total_sum, dimension);

	outfile << "Sum of vectors: ";
	for (int i = 0; i < dimension; ++i)
	{
		outfile << total_sum[i] << " ";
	}
	outfile << endl << endl;

	for (int i = 0; i < dimension; ++i)
	{
		outfile << "Length of vector " << i+1 << " : " << lenVector(a[i], dimension) << endl;
	}
	outfile << endl;

	for (int i = 0; i < dimension; ++i)
	{
		for (int j = i + 1; j < dimension; ++j)
		{
			outfile << "Dot product of pair " 
				<< "(" << i+1 << ", " << j+1 << "): " 
				<< dotVectors(a[i], a[j], dimension) << endl;
			outfile << "Angle of pair " 
				<< "(" << i+1 << ", " << j+1 << "): " 
				<< angleVectors(a[i], a[j], dimension) << " degrees" << endl << endl;
		}
	}

	infile.close();
	outfile.close();
	return 0;
}
