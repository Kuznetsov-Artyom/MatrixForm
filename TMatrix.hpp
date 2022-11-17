#ifndef T_MATRIX_HPP
#define T_MATRIX_HPP

#include <iostream>
#include "TVector.hpp"
#include <omp.h>



template<typename T>
class TMatrix
{
private:
	TVector<TVector<T>> mMatr;
	size_t mSize;

public:
	TMatrix(size_t size = 0) : mSize{ size }
	{
		if (mSize == 0) return;

		mMatr.resize(mSize, 0);

		for (size_t i = 0; i < mSize; ++i)
			mMatr[i].resize(mSize - i, i);
	}
	TMatrix(const TMatrix& other)
	{
		mSize = other.mSize;
		mMatr = other.mMatr;
	}


	size_t getSize() const noexcept { return mSize; }
	T getValue(int i, int j)
	{
		return mMatr.getValue(i).getValue(j);
	}

	void clear()
	{
		for (int i = 0; i < mSize; ++i)
			for (int j = 0; j < mSize; ++j)
				if (j >= i) mMatr[i][j] = 0;
	}
	void showData()
	{
		for (int i = 0; i < mSize; ++i)
		{
			mMatr[i].showData();
			std::cout << '\n';
		}
	}

	TMatrix& operator = (const TMatrix<int>& other)
	{
		mSize = other.mSize;
		mMatr = other.mMatr;

		return *this;
	}
	TMatrix operator + (TMatrix<T>& other)
	{
		if (mSize != other.mSize)
			throw std::logic_error{ "different dimension of matrices" };

		TMatrix<T> newMatr(mSize);

		for (int i = 0; i < mSize; ++i)
			newMatr.mMatr[i] = mMatr[i] + other.mMatr[i];

		return newMatr;
	}
	TMatrix operator - (TMatrix<T>& other)
	{
		if (mSize != other.mSize)
			throw std::logic_error{ "different dimension of matrices" };

		TMatrix<T> newMatr(mSize);

		for (int i = 0; i < mSize; ++i)
			newMatr.mMatr[i] = mMatr[i] - other.mMatr[i];

		return newMatr;
	}
	TMatrix operator * (TMatrix& other)
	{
		if (mSize != other.mSize)
			throw std::logic_error{ "different dimension of matrices" };

		TMatrix<T> newMatr(mSize);


#pragma omp parallel for shared(newMatr)
		for (int i = 0; i < mSize; ++i)
			for (int j = 0; j < mSize; ++j)
				for (int k = 0; k < mSize; ++k)
				{
					try
					{
						newMatr.mMatr[i][j] += mMatr.getValue(i).getValue(k) * other.mMatr.getValue(k).getValue(j);
					}
					catch (...) {}
				}

		return newMatr;
	}
	TMatrix operator * (int value)
	{
		if (mSize == 0)
			throw std::logic_error{ "matrix is empty" };

		TMatrix<T> newMatr(*this);

		for (int i = 0; i < mSize; ++i)
			newMatr.mMatr[i] = newMatr.mMatr[i] * value;

		return newMatr;
	}
	T& operator () (int i, int j)
	{
		return mMatr[i][j];
	}


	friend void fillMatrix(TMatrix<int>& matr);
};


void fillMatrix(TMatrix<int>& matr)
{
	size_t size = matr.mSize;

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (j >= i)
			{
				std::cout << "matr[" << i << "][" << j << "] = ";
				std::cin >> matr.mMatr[i][j];
			}
}






#endif // T_MATRIX_HPP
