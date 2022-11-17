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




// Изменяет размерности матриц
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


		readOnlyA();
		readOnlyB();
		

		showMatrixA();
		showMatrixB();
		showMatrixC();

	}
}




// Складывает матрицы
System::Void MatrixForm::MyForm::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrC->operator=(*matrA + *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}
// Вычитает матрицы
System::Void MatrixForm::MyForm::buttonDif_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrC->operator=(*matrA - *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}
// Перемноженает матрицы
System::Void MatrixForm::MyForm::buttonMult_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrC->operator=(*matrA * *matrB);

	showMatrixA();
	showMatrixB();
	showMatrixC();
}
// Генерирует для матриц A и B случайные числа
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
// Очищает все матрицы
System::Void MatrixForm::MyForm::buttonClearMatrix_Click(System::Object^ sender, System::EventArgs^ e)
{
	matrA->clear();
	matrB->clear();
	matrC->clear();

	showMatrixA();
	showMatrixB();
	showMatrixC();
}




// Выводит матрицы
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




// Ограничивает ввод в ячейки ниже главной диагонали
System::Void MatrixForm::MyForm::readOnlyA()
{
	int size = static_cast<int>(matrA->getSize());

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (i > j) dataGridViewMatrixA->Rows[i]->Cells[j]->ReadOnly = true;
}
System::Void MatrixForm::MyForm::readOnlyB()
{
	int size = static_cast<int>(matrA->getSize());

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			if (i > j) dataGridViewMatrixB->Rows[i]->Cells[j]->ReadOnly = true;
}




// Обрабатывает ввод с клавиатуры
System::Void MatrixForm::MyForm::tb_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!(Char::IsDigit(e->KeyChar) || e->KeyChar == (char)Keys::Back || e->KeyChar == '-'))
		e->Handled = true;
}

// Контролирует ячейки матриц при их изменении (задействуется tb_KeyPress)
System::Void MatrixForm::MyForm::dataGridViewMatrixA_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{

	TextBox^ tb = (TextBox^)e->Control;
	tb->MaxLength = 5;
	tb->KeyPress += gcnew KeyPressEventHandler(this, &MatrixForm::MyForm::tb_KeyPress);

}
System::Void MatrixForm::MyForm::dataGridViewMatrixB_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{
	TextBox^ tb = (TextBox^)e->Control;
	tb->MaxLength = 5;
	tb->KeyPress += gcnew KeyPressEventHandler(this, &MatrixForm::MyForm::tb_KeyPress);
}

// Сохраняет результат ввода
System::Void MatrixForm::MyForm::dataGridViewMatrixA_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	int indRow = Convert::ToInt32(e->RowIndex);
	int indCol = Convert::ToInt32(e->ColumnIndex);

	if (Convert::ToString(dataGridViewMatrixA->Rows[indRow]->Cells[indCol]->Value) == "-")
		dataGridViewMatrixA->Rows[indRow]->Cells[indCol]->Value = -1;

	(*matrA)(indRow, indCol) = Convert::ToInt32(dataGridViewMatrixA->Rows[indRow]->Cells[indCol]->Value);
}
System::Void MatrixForm::MyForm::dataGridViewMatrixB_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	int indRow = Convert::ToInt32(e->RowIndex);
	int indCol = Convert::ToInt32(e->ColumnIndex);

	if (Convert::ToString(dataGridViewMatrixB->Rows[indRow]->Cells[indCol]->Value) == "-")
		dataGridViewMatrixB->Rows[indRow]->Cells[indCol]->Value = -1;

	(*matrB)(indRow, indCol) = Convert::ToInt32(dataGridViewMatrixB->Rows[indRow]->Cells[indCol]->Value);
}


