#pragma once
#include<math.h>
#include<iostream>

template <typename T>
class VectorCalculator
{
private:

	int vector_dim;
	T* curent_vector = new T[vector_dim];

public:

	VectorCalculator()
	{
		vector_dim = 3;
		curent_vector = new T[vector_dim];

		for (int iter_i{ 0 }; iter_i < vector_dim; iter_i++)
		{
			curent_vector[iter_i] = (T)rand() % 40;
		}
	}

	template<typename T>
	VectorCalculator(T value, int _vector_dim)
	{
		vector_dim = _vector_dim;
		curent_vector = new T[vector_dim];

		for (int iter_i{ 0 }; iter_i < vector_dim; iter_i++)
		{
			curent_vector[iter_i] = value;
		}
	}

	VectorCalculator(const VectorCalculator<T>& other)
	{

		vector_dim = other.vector_dim;
		curent_vector = other.curent_vector;
	}

	template<typename T>
	VectorCalculator<T> operator + (const VectorCalculator<T>& other)
	{
		if (vector_dim != other.vector_dim)
		{
			std::cout << "cant broadcast from shape: (" << vector_dim << ", " << other.vector_dim << ")\n";
		}

		else
		{
			VectorCalculator <T> result_object;
			for (int iter_i{ 0 }; iter_i < other.vector_dim; iter_i++)
			{
				result_object.curent_vector[iter_i] = curent_vector[iter_i] + other.curent_vector[iter_i];
			}

			return result_object;
		}

	}

	template<typename T>
	VectorCalculator<T> operator - (const VectorCalculator<T>& other)
	{
		if (vector_dim != other.vector_dim)
		{
			std::cout << "cant broadcast from shape: (" << vector_dim << ", " << other.vector_dim << ")\n";
		}

		else
		{
			VectorCalculator <T> result_object;
			for (int iter_i{ 0 }; iter_i < other.vector_dim; iter_i++)
			{
				result_object.curent_vector[iter_i] = curent_vector[iter_i] - other.curent_vector[iter_i];
			}

			return result_object;
		}
	}

	template<typename T>
	VectorCalculator<T> operator * (const VectorCalculator<T>& other)
	{
		if (vector_dim != other.vector_dim)
		{
			std::cout << "cant broadcast from shape: (" << vector_dim << ", " << other.vector_dim << ")\n";
		}

		else
		{
			VectorCalculator <T> result_object(1, 1);
			for (int iter_i{ 0 }; iter_i < other.vector_dim; iter_i++)
			{
				result_object.curent_vector[0] += curent_vector[iter_i] * other.curent_vector[iter_i];
			}

			return result_object;
		}

	}

	template<typename T>
	VectorCalculator<T> cross(const VectorCalculator<T>& other)
	{
		if (vector_dim != other.vector_dim)
		{
			std::cout << "cant broadcast from shape: (" << vector_dim << ", " << other.vector_dim << ")\n";
		}

		else
		{
			if (vector_dim != 3)
			{
				std::cout << "cant treate curent vector dim!!!\n";
			}

			else
			{
				VectorCalculator<T> result_object(1, 3);

				result_object.curent_vector[0] = curent_vector[1] * other.curent_vector[2] - curent_vector[2] * other.curent_vector[1];
				result_object.curent_vector[1] = curent_vector[2] * other.curent_vector[0] - curent_vector[0] * other.curent_vector[2];
				result_object.curent_vector[2] = curent_vector[0] * other.curent_vector[1] - curent_vector[1] * other.curent_vector[0];

				return result_object;
			}

		}
	}

	template<typename T>
	VectorCalculator<T> operator

};