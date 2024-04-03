#include"TemplateMatrixCalc.h"


int main()
{
	MatrixCalculator<double> matrix_one(1, 3, 3);
	MatrixCalculator<double> matrix_two(1, 3, 3);

	MatrixCalculator<double> matrix_sum = matrix_one + matrix_two;
	MatrixCalculator<double> matrix_min = matrix_one - matrix_two;
	MatrixCalculator<double> matrix_mul = matrix_one * matrix_two;

	//std::cout << matrix_sum;
	//std::cout << matrix_min;
	//std::cout << matrix_mul;

	return 0;
}