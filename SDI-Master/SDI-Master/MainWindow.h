#pragma once
#include <string>;
#include "Classes.h"
#include "Globals.h"
#include "LabelDialogue.h"
#include <filesystem>

namespace SDIMaster 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Globals;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:

	private: System::Windows::Forms::GroupBox^ groupBox4;
	public: System::Windows::Forms::PictureBox^ imageDisplay;


	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonRemoveImage;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ buttonImportImage;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ searchBoxImage;

	public: System::Windows::Forms::ListBox^ listBoxImage;

	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ buttonRemoveLabel;

	private: System::Windows::Forms::Button^ buttonAddLabel;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ searchBoxLabels;
	public: System::Windows::Forms::ListBox^ listBoxLabels;


	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ buttonRemoveAnnotation;
	private: System::Windows::Forms::Button^ buttonAddAnnotation;


	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ searchBoxAnnotations;
	public: System::Windows::Forms::ListBox^ listBoxAnnotations;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonRemoveImage = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->buttonImportImage = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->searchBoxImage = (gcnew System::Windows::Forms::TextBox());
			this->listBoxImage = (gcnew System::Windows::Forms::ListBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonRemoveLabel = (gcnew System::Windows::Forms::Button());
			this->buttonAddLabel = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->searchBoxLabels = (gcnew System::Windows::Forms::TextBox());
			this->listBoxLabels = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonRemoveAnnotation = (gcnew System::Windows::Forms::Button());
			this->buttonAddAnnotation = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->searchBoxAnnotations = (gcnew System::Windows::Forms::TextBox());
			this->listBoxAnnotations = (gcnew System::Windows::Forms::ListBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->imageDisplay = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageDisplay))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox4);
			this->splitContainer1->Panel2->Controls->Add(this->imageDisplay);
			this->splitContainer1->Size = System::Drawing::Size(802, 565);
			this->splitContainer1->SplitterDistance = 274;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 0;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->tableLayoutPanel2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(274, 565);
			this->splitContainer2->SplitterDistance = 168;
			this->splitContainer2->SplitterWidth = 3;
			this->splitContainer2->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(274, 168);
			this->tableLayoutPanel2->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonRemoveImage);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->buttonImportImage);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->searchBoxImage);
			this->groupBox1->Controls->Add(this->listBoxImage);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(2, 2);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(270, 164);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Images";
			// 
			// buttonRemoveImage
			// 
			this->buttonRemoveImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveImage->Location = System::Drawing::Point(4, 132);
			this->buttonRemoveImage->Margin = System::Windows::Forms::Padding(2);
			this->buttonRemoveImage->Name = L"buttonRemoveImage";
			this->buttonRemoveImage->Size = System::Drawing::Size(262, 21);
			this->buttonRemoveImage->TabIndex = 5;
			this->buttonRemoveImage->Text = L"Remove Image";
			this->buttonRemoveImage->UseVisualStyleBackColor = true;
			this->buttonRemoveImage->Click += gcnew System::EventHandler(this, &MainWindow::buttonRemoveImage_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->AutoSize = true;
			this->button2->Location = System::Drawing::Point(154, 99);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Export Image";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// buttonImportImage
			// 
			this->buttonImportImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonImportImage->AutoSize = true;
			this->buttonImportImage->Location = System::Drawing::Point(5, 100);
			this->buttonImportImage->Margin = System::Windows::Forms::Padding(2);
			this->buttonImportImage->Name = L"buttonImportImage";
			this->buttonImportImage->Size = System::Drawing::Size(103, 23);
			this->buttonImportImage->TabIndex = 3;
			this->buttonImportImage->Text = L"Import Image";
			this->buttonImportImage->UseVisualStyleBackColor = true;
			this->buttonImportImage->Click += gcnew System::EventHandler(this, &MainWindow::buttonImportImage_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 20);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search:";
			// 
			// searchBoxImage
			// 
			this->searchBoxImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchBoxImage->Location = System::Drawing::Point(51, 18);
			this->searchBoxImage->Margin = System::Windows::Forms::Padding(2);
			this->searchBoxImage->Name = L"searchBoxImage";
			this->searchBoxImage->Size = System::Drawing::Size(216, 20);
			this->searchBoxImage->TabIndex = 1;
			// 
			// listBoxImage
			// 
			this->listBoxImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxImage->FormattingEnabled = true;
			this->listBoxImage->Location = System::Drawing::Point(4, 44);
			this->listBoxImage->Margin = System::Windows::Forms::Padding(2);
			this->listBoxImage->Name = L"listBoxImage";
			this->listBoxImage->Size = System::Drawing::Size(262, 43);
			this->listBoxImage->TabIndex = 0;
			this->listBoxImage->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::listBoxImage_SelectedIndexChanged);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->tableLayoutPanel1);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->tableLayoutPanel3);
			this->splitContainer3->Size = System::Drawing::Size(274, 394);
			this->splitContainer3->SplitterDistance = 181;
			this->splitContainer3->SplitterWidth = 3;
			this->splitContainer3->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 181)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(274, 181);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonRemoveLabel);
			this->groupBox2->Controls->Add(this->buttonAddLabel);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->searchBoxLabels);
			this->groupBox2->Controls->Add(this->listBoxLabels);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Location = System::Drawing::Point(2, 2);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(270, 177);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Labels";
			// 
			// buttonRemoveLabel
			// 
			this->buttonRemoveLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveLabel->AutoSize = true;
			this->buttonRemoveLabel->Location = System::Drawing::Point(153, 144);
			this->buttonRemoveLabel->Margin = System::Windows::Forms::Padding(2);
			this->buttonRemoveLabel->Name = L"buttonRemoveLabel";
			this->buttonRemoveLabel->Size = System::Drawing::Size(112, 23);
			this->buttonRemoveLabel->TabIndex = 6;
			this->buttonRemoveLabel->Text = L"Remove Label";
			this->buttonRemoveLabel->UseVisualStyleBackColor = true;
			this->buttonRemoveLabel->Click += gcnew System::EventHandler(this, &MainWindow::buttonRemoveLabel_Click);
			// 
			// buttonAddLabel
			// 
			this->buttonAddLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonAddLabel->AutoSize = true;
			this->buttonAddLabel->Location = System::Drawing::Point(4, 145);
			this->buttonAddLabel->Margin = System::Windows::Forms::Padding(2);
			this->buttonAddLabel->Name = L"buttonAddLabel";
			this->buttonAddLabel->Size = System::Drawing::Size(103, 23);
			this->buttonAddLabel->TabIndex = 5;
			this->buttonAddLabel->Text = L"Add Label";
			this->buttonAddLabel->UseVisualStyleBackColor = true;
			this->buttonAddLabel->Click += gcnew System::EventHandler(this, &MainWindow::buttonAddLabel_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button5->AutoSize = true;
			this->button5->Location = System::Drawing::Point(154, 112);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Export Labels";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button6->AutoSize = true;
			this->button6->Location = System::Drawing::Point(5, 113);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(103, 23);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Import Labels";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 20);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Search:";
			// 
			// searchBoxLabels
			// 
			this->searchBoxLabels->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchBoxLabels->Location = System::Drawing::Point(51, 18);
			this->searchBoxLabels->Margin = System::Windows::Forms::Padding(2);
			this->searchBoxLabels->Name = L"searchBoxLabels";
			this->searchBoxLabels->Size = System::Drawing::Size(218, 20);
			this->searchBoxLabels->TabIndex = 1;
			// 
			// listBoxLabels
			// 
			this->listBoxLabels->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxLabels->FormattingEnabled = true;
			this->listBoxLabels->Location = System::Drawing::Point(4, 44);
			this->listBoxLabels->Margin = System::Windows::Forms::Padding(2);
			this->listBoxLabels->Name = L"listBoxLabels";
			this->listBoxLabels->Size = System::Drawing::Size(264, 56);
			this->listBoxLabels->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(274, 210);
			this->tableLayoutPanel3->TabIndex = 9;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->buttonRemoveAnnotation);
			this->groupBox3->Controls->Add(this->buttonAddAnnotation);
			this->groupBox3->Controls->Add(this->button10);
			this->groupBox3->Controls->Add(this->button11);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->searchBoxAnnotations);
			this->groupBox3->Controls->Add(this->listBoxAnnotations);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(2, 2);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(270, 206);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Annotations";
			// 
			// buttonRemoveAnnotation
			// 
			this->buttonRemoveAnnotation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveAnnotation->AutoSize = true;
			this->buttonRemoveAnnotation->Location = System::Drawing::Point(153, 172);
			this->buttonRemoveAnnotation->Margin = System::Windows::Forms::Padding(2);
			this->buttonRemoveAnnotation->Name = L"buttonRemoveAnnotation";
			this->buttonRemoveAnnotation->Size = System::Drawing::Size(112, 23);
			this->buttonRemoveAnnotation->TabIndex = 6;
			this->buttonRemoveAnnotation->Text = L"Remove Annotation";
			this->buttonRemoveAnnotation->UseVisualStyleBackColor = true;
			this->buttonRemoveAnnotation->Click += gcnew System::EventHandler(this, &MainWindow::buttonRemoveAnnotation_Click);
			// 
			// buttonAddAnnotation
			// 
			this->buttonAddAnnotation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonAddAnnotation->AutoSize = true;
			this->buttonAddAnnotation->Location = System::Drawing::Point(4, 173);
			this->buttonAddAnnotation->Margin = System::Windows::Forms::Padding(2);
			this->buttonAddAnnotation->Name = L"buttonAddAnnotation";
			this->buttonAddAnnotation->Size = System::Drawing::Size(103, 23);
			this->buttonAddAnnotation->TabIndex = 5;
			this->buttonAddAnnotation->Text = L"Add Annotation";
			this->buttonAddAnnotation->UseVisualStyleBackColor = true;
			this->buttonAddAnnotation->Click += gcnew System::EventHandler(this, &MainWindow::buttonAddAnnotation_Click);
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button10->AutoSize = true;
			this->button10->Location = System::Drawing::Point(154, 140);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(112, 23);
			this->button10->TabIndex = 4;
			this->button10->Text = L"Export Labels";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button11->AutoSize = true;
			this->button11->Location = System::Drawing::Point(5, 141);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(103, 23);
			this->button11->TabIndex = 3;
			this->button11->Text = L"Import Labels";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 20);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Search:";
			// 
			// searchBoxAnnotations
			// 
			this->searchBoxAnnotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchBoxAnnotations->Location = System::Drawing::Point(51, 18);
			this->searchBoxAnnotations->Margin = System::Windows::Forms::Padding(2);
			this->searchBoxAnnotations->Name = L"searchBoxAnnotations";
			this->searchBoxAnnotations->Size = System::Drawing::Size(218, 20);
			this->searchBoxAnnotations->TabIndex = 1;
			// 
			// listBoxAnnotations
			// 
			this->listBoxAnnotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxAnnotations->FormattingEnabled = true;
			this->listBoxAnnotations->Location = System::Drawing::Point(4, 44);
			this->listBoxAnnotations->Margin = System::Windows::Forms::Padding(2);
			this->listBoxAnnotations->Name = L"listBoxAnnotations";
			this->listBoxAnnotations->Size = System::Drawing::Size(264, 82);
			this->listBoxAnnotations->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox4->Location = System::Drawing::Point(3, 452);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(533, 102);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Shortcuts";
			// 
			// imageDisplay
			// 
			this->imageDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->imageDisplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->imageDisplay->Location = System::Drawing::Point(2, 2);
			this->imageDisplay->Margin = System::Windows::Forms::Padding(2);
			this->imageDisplay->Name = L"imageDisplay";
			this->imageDisplay->Size = System::Drawing::Size(534, 447);
			this->imageDisplay->TabIndex = 6;
			this->imageDisplay->TabStop = false;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 565);
			this->Controls->Add(this->splitContainer1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageDisplay))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//Get path of a file from the file opening dialogue.
		System::String^ GetFilePath();

		//Loads the image from a given file path into the global array.
		System::Void LoadImage(String^, MainWindow^);

		//Refreshes the list of images in the ImageList component - this is NOT the actual list of files, as windows forms components handle this in their own way.
		System::Void ReloadImageList(MainWindow^);

		//Refreshes the list of labels in the LabelList component
		System::Void ReloadLabelList(MainWindow^);

		//Refreshes the PictureBox component to display the currently selected image.
		System::Void RefreshImageBox(MainWindow^);

		//Open the dialogue for adding a new label (currently has no functionality)
		System::Void AddLabelDialogue(String^, MainWindow^);

		//Add label to list (currently uses hardcoded "test" name)
		System::Void AddLabel(String^, MainWindow^);

		//Remove label from list
		System::Void RemoveLabel(MainWindow^);

		//Add Annotation to image
		System::Void AddAnnotation(String^, Point^, Point^, MainWindow^);

		//Remove Annotation from image
		System::Void RemoveAnnotation(int, MainWindow^);

		//Refresh list of annotations in the component
		System::Void ReloadAnnotationList(MainWindow^);

		//Draws a red rectangle - test function, to be removed
		System::Void drawBoxTest(MainWindow^);

		//!! Functions below cannot currently be moved out of header - cannot add more arguments (ie the MainWindow) as they use eventhandlers

		//Refresh components when selecting a new image
		System::Void listBoxImage_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			RefreshImageBox(this);
			ReloadLabelList(this);
			drawBoxTest(this);
		}

		//Removing images from list
		System::Void buttonRemoveImage_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (this->listBoxImage->SelectedIndex != -1) {
				GlobalClass::loadedImages.RemoveAt(this->listBoxImage->SelectedIndex);
				ReloadImageList(this);
				ReloadLabelList(this);
				RefreshImageBox(this);
			}
		}

		//Importing image
		System::Void buttonImportImage_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			LoadImage(GetFilePath(), this);
		}

		//Add new label
		System::Void buttonAddLabel_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			AddLabel("test", this);
			ReloadLabelList(this);
		}

		//Remove label
		System::Void buttonRemoveLabel_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			RemoveLabel(this);
		}

		//Add Annotation
		System::Void buttonAddAnnotation_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Point^ pointA = gcnew Point(10, 10);
			Point^ pointB = gcnew Point(100, 100);
			AddAnnotation(GlobalClass::loadedImages[listBoxImage->SelectedIndex]->labelList[listBoxLabels->SelectedIndex], pointA, pointB, this);
			ReloadAnnotationList(this);
		}

		//Remove Annotation
		System::Void buttonRemoveAnnotation_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			RemoveAnnotation(listBoxAnnotations->SelectedIndex, this);
			ReloadAnnotationList(this);
		}
};
}
