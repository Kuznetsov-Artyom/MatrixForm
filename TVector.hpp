#ifndef T_VECTOR_HPP
#define T_VECTOR_HPP

#include <iostream>
#include <omp.h>


template<typename T>
class TVector
{
private:
	T* mArr;
	size_t mSize;
	int mStart;

public:
	TVector(size_t size = 0, int start = -1) : mSize{ size }, mStart{ start }
	{
		if (mSize == 0)
		{
			mArr = nullptr;
			return;
		}

		mStart = (mStart > 0) ? mStart : 0;
		mArr = new T[size]();
	}
	TVector(const TVector& other) : mSize{ other.mSize }, mStart{ other.mStart }
	{
		mArr = new T[mSize];

		std::copy(other.mArr, other.mArr + mSize, mArr);
	}


	~TVector() { delete[] mArr; }


	void clear()
	{
		if (mSize == 0) return;

		delete[] mArr;
		mArr = nullptr;
		mSize = 0;
		mStart = -1;
	}
	void resize(size_t newSize, int newStart)
	{
		if (newSize == mSize) return;

		if (newSize == 0)
		{
			this->clear();
			return;
		}

		T* tempArr = new T[newSize]();

		std::copy(mArr, mArr + ((newSize > mSize) ? mSize : newSize), tempArr);
		std::swap(mArr, tempArr);
		mSize = newSize;
		mStart = newStart;

		delete[] tempArr;
	}


	bool empty() const noexcept { return mSize == 0; }

	size_t getSize() const noexcept { return mSize; }
	int getSizeAndStart() const noexcept { return static_cast<int>(mSize) + mStart; }
	int getStartIndex() const noexcept { return mStart; }
	T getValue(int pos)
	{
		if (pos < 0 || pos >= getSizeAndStart())
			throw std::out_of_range{ "going out of range" };

		if (pos < mStart) return T();
		return mArr[pos - mStart];
	}

	void showData()
	{
		for (int i = 0; i < getSizeAndStart(); ++i)
		{
			std::cout << getValue(i) << '\t';
		}
	}


	TVector& operator = (const TVector& other)
	{
		if (this == &other) return *this;

		if (mSize != other.mSize)
		{
			T* tempArr = new T[other.mSize];

			delete[] mArr;

			mArr = tempArr;
			mSize = other.mSize;
		}

		std::copy(other.mArr, other.mArr + mSize, mArr);
		mStart = other.mStart;

		return *this;
	}
	T& operator [] (int pos)
	{
		if (pos < 0 || pos >= getSizeAndStart())
			throw std::out_of_range{ "going out of range" };

		if (pos < mStart)
			throw std::logic_error{ "operator[]. pos < mStart" };

		return mArr[pos - mStart];
	}
	TVector operator + (const TVector& other)
	{
		if (mSize == 0 || other.mSize == 0)
			throw std::logic_error{ "vector is empty" };

		if (mStart != other.mStart || mSize != other.mSize)
			throw std::logic_error{ "vector parameters (size, starting element) must be the same" };

		TVector<T> newVec(mSize, mStart);

		for (int i = 0; i < mSize; ++i)
			newVec.mArr[i] = mArr[i] + other.mArr[i];

		return newVec;
	}
	TVector operator - (const TVector& other)
	{
		if (mSize == 0 || other.mSize == 0)
			throw std::logic_error{ "vector is empty" };

		if (mStart != other.mStart || mSize != other.mSize)
			throw std::logic_error{ "vector parameters (size, starting element) must be the same" };

		TVector<T> newVec(mSize, mStart);

		for (int i = 0; i < mSize; ++i)
			newVec.mArr[i] = mArr[i] - other.mArr[i];

		return newVec;
	}
	T operator * (const TVector& other)
	{
		if (mSize == 0 || other.mSize == 0)
			throw std::logic_error{ "vector is empty" };

		if (mStart != other.mStart || mSize != other.mSize)
			throw std::logic_error{ "vector parameters (size, starting element) must be the same" };

		T value = static_cast<T>(0);

		for (int i = 0; i < mSize; ++i)
			value += mArr[i] * other.mArr[i];

		return value;
	}
	TVector operator * (const int value)
	{
		if (mSize == 0)
			throw std::logic_error{ "vector is empty" };

		TVector<T> newVec(*this);

		for (int i = 0; i < mSize; ++i)
			newVec.mArr[i] *= value;

		return newVec;
	}
	bool operator == (const TVector& other)
	{
		if (mSize != other.mSize || mStart != other.mStart) return false;

		for (int i = 0; i < mSize; ++i)
			if (mArr[i] != other.mArr[i]) return false;

		return true;
	}
	bool operator != (const TVector& other)
	{
		return !(*this == other);
	}
};


#endif // T_VECTOR_HPP
