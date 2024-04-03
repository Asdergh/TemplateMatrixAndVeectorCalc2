#pragma once
#include<math.h>
#include<iostream>

template <typename T>
class MatrixCalculator
{
private:

	int tensor_cols;
	int tensor_rows;
	T** curent_tensor = new T * [tensor_rows];

	friend std::ostream& operator << <T>(std::ostream&, const MatrixCalculator<T>&);

public:

	MatrixCalculator()
	{
		tensor_cols = 3;
		tensor_rows = 3;
		curent_tensor = new T * [tensor_rows];

		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			T* row_vector = new T[tensor_cols];
			for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
			{
				if (iter_i == iter_j)
				{
					row_vector[iter_j] = (T)1.0;
				}

				row_vector[iter_j] = (T)0.0;

			}
			curent_tensor[iter_i] = row_vector;
		}
	}

	MatrixCalculator(T value, int _tensor_rows, int _tensor_cols)
	{
		tensor_rows = _tensor_rows;
		tensor_cols = _tensor_cols;
		curent_tensor = new T * [tensor_rows];

		if (tensor_rows == tensor_cols)
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				T row_vector = new T[tensor_rows];
				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					if (iter_i == iter_j)
					{
						row_vector[iter_j] = value;
					}

					row_vector[iter_j] = (T)0.0;
				}
				curent_tensor[iter_i] = row_vector;
			}
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				T row_vector = new T[tensor_rows];
				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					row_vector[iter_j] = value;
				}
				curent_tensor[iter_i] = row_vector;
			}
		}
	}

	MatrixCalculator(const MatrixCalculator& other)
	{
		tensor_rows = other.tensor_rows;
		tensor_cols = other.tensor_cols;
		curent_tensor = other.curent_tensor;
	}

	~MatrixCalculator()
	{
		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			delete[] curent_tensor[iter_i];
		}
		delete[] curent_tensor;
	}


	template<typename T>
	MatrixCalculator<T> operator + (const MatrixCalculator<T>& other)
	{
		MatrixCalculator result_object(1, other.tensor_rows, other.tensor_cols);

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < other.tensor_rows; iter_i++)
			{
				for (int iter_j{ 0 }; iter_j < other.tensor_cols; iter_j++)
				{
					result_object.curent_tensor[iter_i][iter_j] = curent_tensor[iter_i][iter_j] + other.curent_tensor[iter_i][iter_j];
				}
			}
		}

		return result_object;
	}

	template<typename T>
	MatrixCalculator<T> operator - (const MatrixCalculator<T>& other)
	{
		MatrixCalculator result_object(1, other.tensor_rows, other.tensor_cols);

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < other.tensor_rows; iter_i++)
			{
				for (int iter_j{ 0 }; iter_j < other.tensor_cols; iter_j++)
				{
					result_object.curent_tensor[iter_i][iter_j] = curent_tensor[iter_i][iter_j] - other.curent_tensor[iter_i][iter_j];
				}
			}
		}

		return result_object;
	}

	template<typename T>
	MatrixCalculator<T> operator * (const MatrixCalculator<T>& other)
	{
		MatrixCalculator result_object(1, tensor_rows, other.tensor_cols);

		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			for (int iter_j{ 0 }; iter_j < other.tensor_cols; iter_j++)
			{
				for (int iter_k{ 0 }; iter_k < other.tensor_rows; iter_k++)
				{
					result_object.curent_tensor[iter_i][iter_j] += curent_tensor[iter_i][iter_k] * curent_tensor[iter_k][iter_j];
				}
			}
		}

		return result_object;
	}

	template<typename T>
	int operator < (const MatrixCalculator<T>& other)
	{
		int bool_gate{ 0 };

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				if (bool_gate == 1)
				{
					break;
				}

				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					if (curent_tensor[iter_i][iter_j] > other.curent_tensor[iter_i][iter_j])
					{
						bool_gate = 1;
						break;
					}
				}
			}
		}

		return bool_gate;
	}

	template<typename T>
	int operator > (const MatrixCalculator<T>& other)
	{
		int bool_gate{ 0 };

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				if (bool_gate == 1)
				{
					break;
				}

				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					if (curent_tensor[iter_i][iter_j] < other.curent_tensor[iter_i][iter_j])
					{
						bool_gate = 1;
						break;
					}
				}
			}
		}

		return bool_gate;
	}

	template<typename T>
	int operator == (const MatrixCalculator<T>& other)
	{
		int bool_gate{ 0 };

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				if (bool_gate == 1)
				{
					break;
				}

				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					if (curent_tensor[iter_i][iter_j] != other.curent_tensor[iter_i][iter_j])
					{
						bool_gate = 1;
						break;
					}
				}
			}
		}

		return bool_gate;
	}

	template<typename T>
	int operator != (const MatrixCalculator<T>& other)
	{
		int bool_gate{ 0 };

		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		else
		{
			for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
			{
				if (bool_gate == 0)
				{
					break;
				}

				for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
				{
					if (curent_tensor[iter_i][iter_j] != other.curent_tensor[iter_i][iter_j])
					{
						bool_gate = 0;
						break;
					}
				}
			}
		}

		return bool_gate;
	}

	template<typename T>
	MatrixCalculator<T>& operator += (const MatrixCalculator<T>& other)
	{
		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
			{
				curent_tensor[iter_i][iter_j] += other.curent_tensor[iter_i][iter_j];
			}
		}

		return *this;
	}

	template<typename T>
	MatrixCalculator<T>& operator -= (const MatrixCalculator<T>& other)
	{
		if (tensor_rows != other.tnesor_rows && tensor_cols != other.tensor_cols)
		{
			std::cout << "cannot broadcast shape: (" << other.tensor_rows << ", " << other.tensor_cols << ") with shape: (" << tensor_rows << ", " << tensor_cols << ")";
		}

		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
			{
				curent_tensor[iter_i][iter_j] -= other.curent_tensor[iter_i][iter_j];
			}
		}

		return *this;
	}

	template<typename T>
	std::ostream operator << (std::ostream& os, const MatrixCalculator<T>& other)
	{
		for (int iter_i{ 0 }; iter_i < tensor_rows; iter_i++)
		{
			for (int iter_j{ 0 }; iter_j < tensor_cols; iter_j++)
			{
				os << curent_tensor[iter_i][iter_j] << "\t";
			}
			os < "\n\n";
		}

		return os;
	}
};

