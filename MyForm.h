#pragma once

namespace MatrixForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelSizeMatrix;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSizeMatrix;
	private: System::Windows::Forms::GroupBox^ groupBoxWorkingSpace;
	private: System::Windows::Forms::GroupBox^ groupBoxOperations;

	private: System::Windows::Forms::Button^ buttonMult;

	private: System::Windows::Forms::Button^ buttonDif;
	private: System::Windows::Forms::Button^ buttonAdd;






	private: System::Windows::Forms::DataGridView^ dataGridViewMatrixA;

	private: System::Windows::Forms::Label^ labelMatrixC;

	private: System::Windows::Forms::Label^ labelMatrixB;

	private: System::Windows::Forms::Label^ labelMatrixA;
	private: System::Windows::Forms::GroupBox^ groupBoxRandGenMatr;
	private: System::Windows::Forms::Button^ buttonRandValue;




	private: System::Windows::Forms::GroupBox^ groupBoxClearMatr;
	private: System::Windows::Forms::Button^ buttonClearMatrix;


	private: System::Windows::Forms::DataGridView^ dataGridViewMatrixC;
	private: System::Windows::Forms::DataGridView^ dataGridViewMatrixB;

	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelSizeMatrix = (gcnew System::Windows::Forms::Label());
			this->numericUpDownSizeMatrix = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBoxWorkingSpace = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridViewMatrixC = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewMatrixB = (gcnew System::Windows::Forms::DataGridView());
			this->groupBoxClearMatr = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClearMatrix = (gcnew System::Windows::Forms::Button());
			this->groupBoxRandGenMatr = (gcnew System::Windows::Forms::GroupBox());
			this->buttonRandValue = (gcnew System::Windows::Forms::Button());
			this->groupBoxOperations = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDif = (gcnew System::Windows::Forms::Button());
			this->buttonMult = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridViewMatrixA = (gcnew System::Windows::Forms::DataGridView());
			this->labelMatrixC = (gcnew System::Windows::Forms::Label());
			this->labelMatrixB = (gcnew System::Windows::Forms::Label());
			this->labelMatrixA = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizeMatrix))->BeginInit();
			this->groupBoxWorkingSpace->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixB))->BeginInit();
			this->groupBoxClearMatr->SuspendLayout();
			this->groupBoxRandGenMatr->SuspendLayout();
			this->groupBoxOperations->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixA))->BeginInit();
			this->SuspendLayout();
			// 
			// labelSizeMatrix
			// 
			this->labelSizeMatrix->AutoSize = true;
			this->labelSizeMatrix->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSizeMatrix->Location = System::Drawing::Point(30, 30);
			this->labelSizeMatrix->Name = L"labelSizeMatrix";
			this->labelSizeMatrix->Size = System::Drawing::Size(190, 36);
			this->labelSizeMatrix->TabIndex = 0;
			this->labelSizeMatrix->Text = L"Размерность";
			// 
			// numericUpDownSizeMatrix
			// 
			this->numericUpDownSizeMatrix->Cursor = System::Windows::Forms::Cursors::Hand;
			this->numericUpDownSizeMatrix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownSizeMatrix->Location = System::Drawing::Point(230, 35);
			this->numericUpDownSizeMatrix->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownSizeMatrix->Name = L"numericUpDownSizeMatrix";
			this->numericUpDownSizeMatrix->Size = System::Drawing::Size(102, 30);
			this->numericUpDownSizeMatrix->TabIndex = 1;
			this->numericUpDownSizeMatrix->TabStop = false;
			this->numericUpDownSizeMatrix->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDownSizeMatrix->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownSizeMatrix_ValueChanged);
			// 
			// groupBoxWorkingSpace
			// 
			this->groupBoxWorkingSpace->Controls->Add(this->dataGridViewMatrixC);
			this->groupBoxWorkingSpace->Controls->Add(this->dataGridViewMatrixB);
			this->groupBoxWorkingSpace->Controls->Add(this->groupBoxClearMatr);
			this->groupBoxWorkingSpace->Controls->Add(this->groupBoxRandGenMatr);
			this->groupBoxWorkingSpace->Controls->Add(this->groupBoxOperations);
			this->groupBoxWorkingSpace->Controls->Add(this->dataGridViewMatrixA);
			this->groupBoxWorkingSpace->Controls->Add(this->labelMatrixC);
			this->groupBoxWorkingSpace->Controls->Add(this->labelMatrixB);
			this->groupBoxWorkingSpace->Controls->Add(this->labelMatrixA);
			this->groupBoxWorkingSpace->Location = System::Drawing::Point(36, 71);
			this->groupBoxWorkingSpace->Name = L"groupBoxWorkingSpace";
			this->groupBoxWorkingSpace->Size = System::Drawing::Size(1337, 660);
			this->groupBoxWorkingSpace->TabIndex = 2;
			this->groupBoxWorkingSpace->TabStop = false;
			this->groupBoxWorkingSpace->Visible = false;
			// 
			// dataGridViewMatrixC
			// 
			this->dataGridViewMatrixC->AllowUserToAddRows = false;
			this->dataGridViewMatrixC->AllowUserToDeleteRows = false;
			this->dataGridViewMatrixC->AllowUserToResizeColumns = false;
			this->dataGridViewMatrixC->AllowUserToResizeRows = false;
			this->dataGridViewMatrixC->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMatrixC->ColumnHeadersVisible = false;
			this->dataGridViewMatrixC->Cursor = System::Windows::Forms::Cursors::No;
			this->dataGridViewMatrixC->Location = System::Drawing::Point(944, 108);
			this->dataGridViewMatrixC->Name = L"dataGridViewMatrixC";
			this->dataGridViewMatrixC->ReadOnly = true;
			this->dataGridViewMatrixC->RowHeadersVisible = false;
			this->dataGridViewMatrixC->RowHeadersWidth = 51;
			this->dataGridViewMatrixC->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridViewMatrixC->Size = System::Drawing::Size(364, 336);
			this->dataGridViewMatrixC->TabIndex = 14;
			this->dataGridViewMatrixC->TabStop = false;
			// 
			// dataGridViewMatrixB
			// 
			this->dataGridViewMatrixB->AllowUserToAddRows = false;
			this->dataGridViewMatrixB->AllowUserToDeleteRows = false;
			this->dataGridViewMatrixB->AllowUserToResizeColumns = false;
			this->dataGridViewMatrixB->AllowUserToResizeRows = false;
			this->dataGridViewMatrixB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMatrixB->ColumnHeadersVisible = false;
			this->dataGridViewMatrixB->Location = System::Drawing::Point(493, 108);
			this->dataGridViewMatrixB->Name = L"dataGridViewMatrixB";
			this->dataGridViewMatrixB->RowHeadersVisible = false;
			this->dataGridViewMatrixB->RowHeadersWidth = 51;
			this->dataGridViewMatrixB->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridViewMatrixB->Size = System::Drawing::Size(364, 336);
			this->dataGridViewMatrixB->TabIndex = 13;
			this->dataGridViewMatrixB->TabStop = false;
			this->dataGridViewMatrixB->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridViewMatrixB_CellEndEdit);
			this->dataGridViewMatrixB->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::dataGridViewMatrixB_EditingControlShowing);
			// 
			// groupBoxClearMatr
			// 
			this->groupBoxClearMatr->Controls->Add(this->buttonClearMatrix);
			this->groupBoxClearMatr->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxClearMatr->Location = System::Drawing::Point(944, 474);
			this->groupBoxClearMatr->Name = L"groupBoxClearMatr";
			this->groupBoxClearMatr->Size = System::Drawing::Size(364, 157);
			this->groupBoxClearMatr->TabIndex = 12;
			this->groupBoxClearMatr->TabStop = false;
			this->groupBoxClearMatr->Text = L"Очистка";
			// 
			// buttonClearMatrix
			// 
			this->buttonClearMatrix->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonClearMatrix->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClearMatrix->Location = System::Drawing::Point(6, 48);
			this->buttonClearMatrix->Name = L"buttonClearMatrix";
			this->buttonClearMatrix->Size = System::Drawing::Size(352, 75);
			this->buttonClearMatrix->TabIndex = 0;
			this->buttonClearMatrix->Text = L"Очистить матрицы";
			this->buttonClearMatrix->UseVisualStyleBackColor = true;
			this->buttonClearMatrix->Click += gcnew System::EventHandler(this, &MyForm::buttonClearMatrix_Click);
			// 
			// groupBoxRandGenMatr
			// 
			this->groupBoxRandGenMatr->Controls->Add(this->buttonRandValue);
			this->groupBoxRandGenMatr->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxRandGenMatr->Location = System::Drawing::Point(42, 474);
			this->groupBoxRandGenMatr->Name = L"groupBoxRandGenMatr";
			this->groupBoxRandGenMatr->Size = System::Drawing::Size(364, 157);
			this->groupBoxRandGenMatr->TabIndex = 11;
			this->groupBoxRandGenMatr->TabStop = false;
			this->groupBoxRandGenMatr->Text = L"Прочее";
			// 
			// buttonRandValue
			// 
			this->buttonRandValue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonRandValue->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRandValue->Location = System::Drawing::Point(6, 48);
			this->buttonRandValue->Name = L"buttonRandValue";
			this->buttonRandValue->Size = System::Drawing::Size(352, 75);
			this->buttonRandValue->TabIndex = 0;
			this->buttonRandValue->Text = L"Заполнить случайными числами";
			this->buttonRandValue->UseVisualStyleBackColor = true;
			this->buttonRandValue->Click += gcnew System::EventHandler(this, &MyForm::buttonRandValue_Click);
			// 
			// groupBoxOperations
			// 
			this->groupBoxOperations->Controls->Add(this->buttonDif);
			this->groupBoxOperations->Controls->Add(this->buttonMult);
			this->groupBoxOperations->Controls->Add(this->buttonAdd);
			this->groupBoxOperations->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxOperations->Location = System::Drawing::Point(493, 474);
			this->groupBoxOperations->Name = L"groupBoxOperations";
			this->groupBoxOperations->Size = System::Drawing::Size(364, 157);
			this->groupBoxOperations->TabIndex = 10;
			this->groupBoxOperations->TabStop = false;
			this->groupBoxOperations->Text = L"Операции";
			// 
			// buttonDif
			// 
			this->buttonDif->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDif->Location = System::Drawing::Point(146, 48);
			this->buttonDif->Name = L"buttonDif";
			this->buttonDif->Size = System::Drawing::Size(75, 75);
			this->buttonDif->TabIndex = 8;
			this->buttonDif->Text = L"-";
			this->buttonDif->UseVisualStyleBackColor = true;
			this->buttonDif->Click += gcnew System::EventHandler(this, &MyForm::buttonDif_Click);
			// 
			// buttonMult
			// 
			this->buttonMult->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonMult->Location = System::Drawing::Point(261, 48);
			this->buttonMult->Name = L"buttonMult";
			this->buttonMult->Size = System::Drawing::Size(75, 75);
			this->buttonMult->TabIndex = 9;
			this->buttonMult->Text = L"х";
			this->buttonMult->UseVisualStyleBackColor = true;
			this->buttonMult->Click += gcnew System::EventHandler(this, &MyForm::buttonMult_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonAdd->Location = System::Drawing::Point(34, 48);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 75);
			this->buttonAdd->TabIndex = 7;
			this->buttonAdd->Text = L"+";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// dataGridViewMatrixA
			// 
			this->dataGridViewMatrixA->AllowUserToAddRows = false;
			this->dataGridViewMatrixA->AllowUserToDeleteRows = false;
			this->dataGridViewMatrixA->AllowUserToResizeColumns = false;
			this->dataGridViewMatrixA->AllowUserToResizeRows = false;
			this->dataGridViewMatrixA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewMatrixA->ColumnHeadersVisible = false;
			this->dataGridViewMatrixA->Location = System::Drawing::Point(42, 108);
			this->dataGridViewMatrixA->Name = L"dataGridViewMatrixA";
			this->dataGridViewMatrixA->RowHeadersVisible = false;
			this->dataGridViewMatrixA->RowHeadersWidth = 51;
			this->dataGridViewMatrixA->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridViewMatrixA->Size = System::Drawing::Size(364, 336);
			this->dataGridViewMatrixA->TabIndex = 4;
			this->dataGridViewMatrixA->TabStop = false;
			this->dataGridViewMatrixA->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridViewMatrixA_CellEndEdit);
			this->dataGridViewMatrixA->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::dataGridViewMatrixA_EditingControlShowing);
			// 
			// labelMatrixC
			// 
			this->labelMatrixC->AutoSize = true;
			this->labelMatrixC->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMatrixC->Location = System::Drawing::Point(1044, 44);
			this->labelMatrixC->Name = L"labelMatrixC";
			this->labelMatrixC->Size = System::Drawing::Size(162, 36);
			this->labelMatrixC->TabIndex = 3;
			this->labelMatrixC->Text = L"Матрица С";
			// 
			// labelMatrixB
			// 
			this->labelMatrixB->AutoSize = true;
			this->labelMatrixB->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMatrixB->Location = System::Drawing::Point(594, 44);
			this->labelMatrixB->Name = L"labelMatrixB";
			this->labelMatrixB->Size = System::Drawing::Size(162, 36);
			this->labelMatrixB->TabIndex = 2;
			this->labelMatrixB->Text = L"Матрица В";
			// 
			// labelMatrixA
			// 
			this->labelMatrixA->AutoSize = true;
			this->labelMatrixA->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMatrixA->Location = System::Drawing::Point(144, 44);
			this->labelMatrixA->Name = L"labelMatrixA";
			this->labelMatrixA->Size = System::Drawing::Size(162, 36);
			this->labelMatrixA->TabIndex = 1;
			this->labelMatrixA->Text = L"Матрица А";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1416, 756);
			this->Controls->Add(this->groupBoxWorkingSpace);
			this->Controls->Add(this->numericUpDownSizeMatrix);
			this->Controls->Add(this->labelSizeMatrix);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Матрицы";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizeMatrix))->EndInit();
			this->groupBoxWorkingSpace->ResumeLayout(false);
			this->groupBoxWorkingSpace->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixB))->EndInit();
			this->groupBoxClearMatr->ResumeLayout(false);
			this->groupBoxRandGenMatr->ResumeLayout(false);
			this->groupBoxOperations->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrixA))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Изменение размерности матриц
private: System::Void numericUpDownSizeMatrix_ValueChanged(System::Object^ sender, System::EventArgs^ e);

// Кнопка сложения двух матриц
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
// Кнопка разности двух матриц
private: System::Void buttonDif_Click(System::Object^ sender, System::EventArgs^ e);
// Кнопка перемножения двух матриц
private: System::Void buttonMult_Click(System::Object^ sender, System::EventArgs^ e);
// Кнопка для заполнения матриц сучайными числами
private: System::Void buttonRandValue_Click(System::Object^ sender, System::EventArgs^ e);
// Кнопка очистки всех матриц
private: System::Void buttonClearMatrix_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void showMatrixA();
private: System::Void showMatrixB();
private: System::Void showMatrixC();


private: System::Void readOnlyA();
private: System::Void readOnlyB();




private: void tb_KeyPress(Object^ sender, KeyPressEventArgs^ e);

private: System::Void dataGridViewMatrixA_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);
private: System::Void dataGridViewMatrixB_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);

private: System::Void dataGridViewMatrixA_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void dataGridViewMatrixB_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

};
}