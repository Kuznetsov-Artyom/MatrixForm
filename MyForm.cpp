#include "MyForm.h"
#include "TMatrix.hpp"
#include <random>



using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MatrixForm::MyForm form;
	Application::Run(% form);

	return 0;
}


TMatrix<int>* matrA = nullptr;
TMatrix<int>* matrB = nullptr;
TMatrix<int>* matrC = nullptr;




// Изменение размерности матриц
System::Void MatrixForm::MyForm::numericUpDownSizeMatrix_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	int size = Convert::ToInt32(numericUpDownSizeMatrix->Value);

	if (matrA != nullptr)
	{
		delete matrA;
		matrA = nullptr;

		delete matrB;
		matrB = nullptr;

		delete matrC;
		matrC = nullptr;
	}

	if (size == 0)
	{
		groupBoxWorkingSpace->Hide();
	}
	else
	{
		groupBoxWorkingSpace->Show();

		// Создаем матрицы с новой размерностью
		matrA = new TMatrix<int>(size);
		matrB = new TMatrix<int>(size);
		matrC = new TMatrix<int>(size);


		dataGridViewMatrixA->RowCount = size;
		dataGridViewMatrixA->ColumnCount = size;

		dataGridViewMatrixB->RowCount = size;
		dataGridViewMatrixB->ColumnCount = size;

		dataGridViewMatrixC->RowCount = size;
		dataGridViewMatrixC->ColumnCount = size;

		

		showMatrixA();
		showMatrixB();
		showMatrixC();

	}
}

System::Void MatrixForm::MyForm::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*delete matrC;
	matrC = new TMatrix<int>(*matrA + *matrB);*/

	matrC->operator=(*matrA + *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}

System::Void MatrixForm::MyForm::buttonDif_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrC->operator=(*matrA - *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}

System::Void MatrixForm::MyForm::buttonMult_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrC->operator=(*matrA * *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}

System::Void MatrixForm::MyForm::buttonRandValue_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = static_cast<int>(matrA->getSize());

	std::random_device rd;
	std::mt19937 mersenne(rd());
	int minValue = -100;
	int maxValue = 100;

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (j >= i)
			{
				(*matrA)(i, j) = minValue + mersenne() % (maxValue - minValue + 1);
				(*matrB)(i, j) = minValue + mersenne() % (maxValue - minValue + 1);
			}

	showMatrixA();
	showMatrixB();

	matrC->clear();
	showMatrixC();
}

System::Void MatrixForm::MyForm::buttonClearMatrix_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrA->clear();
	matrB->clear();
	matrC->clear();

	showMatrixA();
	showMatrixB();
	showMatrixC();
}





System::Void MatrixForm::MyForm::showMatrixA()
{
	int size = static_cast<int>(matrA->getSize());

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
		{
			dataGridViewMatrixA->Columns[j]->Width = Convert::ToDouble(dataGridViewMatrixA->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixA->Rows[i]->Height = Convert::ToDouble(dataGridViewMatrixA->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixA->Rows[i]->Cells[j]->Value = matrA->getValue(i, j);
		}
}

System::Void MatrixForm::MyForm::showMatrixB()
{
	int size = static_cast<int>(matrB->getSize());

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
		{
			dataGridViewMatrixB->Columns[j]->Width = Convert::ToDouble(dataGridViewMatrixB->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixB->Rows[i]->Height = Convert::ToDouble(dataGridViewMatrixB->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixB->Rows[i]->Cells[j]->Value = matrB->getValue(i, j);
		}
}

System::Void MatrixForm::MyForm::showMatrixC()
{
	int size = static_cast<int>(matrC->getSize());

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
		{
			dataGridViewMatrixC->Columns[j]->Width = Convert::ToDouble(dataGridViewMatrixC->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixC->Rows[i]->Height = Convert::ToDouble(dataGridViewMatrixC->Width) / Convert::ToDouble(numericUpDownSizeMatrix->Value);
			dataGridViewMatrixC->Rows[i]->Cells[j]->Value = matrC->getValue(i, j);
		}
}



