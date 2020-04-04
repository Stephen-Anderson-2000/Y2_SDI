#pragma once
#include <string>;
#include "ImageData.h"
#include "GlobalImageList.h"
#include <filesystem>
#include "Annotation.h"
#include "AnnotationFile.h"
#include "ImageFile.h"
#include "GUI.h"


namespace SDIMaster 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace GlobalList;

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
	public: System::Windows::Forms::ListBox^ GroupBox_Images;
	private:










	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::GroupBox^ classescontainer;

	private: System::Windows::Forms::Button^ Button_RemoveClass;


	private: System::Windows::Forms::Button^ Button_AddClass;


	private: System::Windows::Forms::Button^ Button_LoadClasses;
	public: System::Windows::Forms::ListBox^ GroupBox_Classes;
	private:








	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ buttonRemoveAnnotation;







	public: System::Windows::Forms::ListBox^ listBoxAnnotations;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ Combobox_SortImages;
	private: System::Windows::Forms::Label^ Label_FolderPath;
	private: System::Windows::Forms::Button^ Button_ChangeDir;



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
			this->Button_ChangeDir = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Combobox_SortImages = (gcnew System::Windows::Forms::ComboBox());
			this->Label_FolderPath = (gcnew System::Windows::Forms::Label());
			this->GroupBox_Images = (gcnew System::Windows::Forms::ListBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->classescontainer = (gcnew System::Windows::Forms::GroupBox());
			this->Button_RemoveClass = (gcnew System::Windows::Forms::Button());
			this->Button_AddClass = (gcnew System::Windows::Forms::Button());
			this->Button_LoadClasses = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Classes = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonRemoveAnnotation = (gcnew System::Windows::Forms::Button());
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
			this->classescontainer->SuspendLayout();
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
			this->groupBox1->Controls->Add(this->Button_ChangeDir);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->Combobox_SortImages);
			this->groupBox1->Controls->Add(this->Label_FolderPath);
			this->groupBox1->Controls->Add(this->GroupBox_Images);
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
			// Button_ChangeDir
			// 
			this->Button_ChangeDir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Button_ChangeDir->Location = System::Drawing::Point(154, 14);
			this->Button_ChangeDir->Name = L"Button_ChangeDir";
			this->Button_ChangeDir->Size = System::Drawing::Size(111, 23);
			this->Button_ChangeDir->TabIndex = 4;
			this->Button_ChangeDir->Text = L"Change Directory";
			this->Button_ChangeDir->UseVisualStyleBackColor = true;
			this->Button_ChangeDir->Click += gcnew System::EventHandler(this, &MainWindow::Button_ChangeDir_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Sort:";
			// 
			// Combobox_SortImages
			// 
			this->Combobox_SortImages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Combobox_SortImages->FormattingEnabled = true;
			this->Combobox_SortImages->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Name ⯅", L"Name ⯆", L"Date ⯅", L"Date ⯆" });
			this->Combobox_SortImages->Location = System::Drawing::Point(173, 138);
			this->Combobox_SortImages->Name = L"Combobox_SortImages";
			this->Combobox_SortImages->Size = System::Drawing::Size(94, 21);
			this->Combobox_SortImages->TabIndex = 2;
			// 
			// Label_FolderPath
			// 
			this->Label_FolderPath->AutoSize = true;
			this->Label_FolderPath->Location = System::Drawing::Point(5, 19);
			this->Label_FolderPath->Name = L"Label_FolderPath";
			this->Label_FolderPath->Size = System::Drawing::Size(32, 13);
			this->Label_FolderPath->TabIndex = 1;
			this->Label_FolderPath->Text = L"Path:";
			// 
			// GroupBox_Images
			// 
			this->GroupBox_Images->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBox_Images->FormattingEnabled = true;
			this->GroupBox_Images->Location = System::Drawing::Point(5, 52);
			this->GroupBox_Images->Margin = System::Windows::Forms::Padding(2);
			this->GroupBox_Images->Name = L"GroupBox_Images";
			this->GroupBox_Images->Size = System::Drawing::Size(262, 82);
			this->GroupBox_Images->TabIndex = 0;
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
			this->tableLayoutPanel1->Controls->Add(this->classescontainer, 0, 0);
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
			// classescontainer
			// 
			this->classescontainer->Controls->Add(this->Button_RemoveClass);
			this->classescontainer->Controls->Add(this->Button_AddClass);
			this->classescontainer->Controls->Add(this->Button_LoadClasses);
			this->classescontainer->Controls->Add(this->GroupBox_Classes);
			this->classescontainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->classescontainer->Location = System::Drawing::Point(2, 2);
			this->classescontainer->Margin = System::Windows::Forms::Padding(2);
			this->classescontainer->Name = L"classescontainer";
			this->classescontainer->Padding = System::Windows::Forms::Padding(2);
			this->classescontainer->Size = System::Drawing::Size(270, 177);
			this->classescontainer->TabIndex = 6;
			this->classescontainer->TabStop = false;
			this->classescontainer->Text = L"Classes";
			// 
			// Button_RemoveClass
			// 
			this->Button_RemoveClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Button_RemoveClass->AutoSize = true;
			this->Button_RemoveClass->Location = System::Drawing::Point(153, 144);
			this->Button_RemoveClass->Margin = System::Windows::Forms::Padding(2);
			this->Button_RemoveClass->Name = L"Button_RemoveClass";
			this->Button_RemoveClass->Size = System::Drawing::Size(112, 23);
			this->Button_RemoveClass->TabIndex = 6;
			this->Button_RemoveClass->Text = L"Remove Class";
			this->Button_RemoveClass->UseVisualStyleBackColor = true;
			// 
			// Button_AddClass
			// 
			this->Button_AddClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_AddClass->AutoSize = true;
			this->Button_AddClass->Location = System::Drawing::Point(4, 145);
			this->Button_AddClass->Margin = System::Windows::Forms::Padding(2);
			this->Button_AddClass->Name = L"Button_AddClass";
			this->Button_AddClass->Size = System::Drawing::Size(103, 23);
			this->Button_AddClass->TabIndex = 5;
			this->Button_AddClass->Text = L"Add Class";
			this->Button_AddClass->UseVisualStyleBackColor = true;
			// 
			// Button_LoadClasses
			// 
			this->Button_LoadClasses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Button_LoadClasses->AutoSize = true;
			this->Button_LoadClasses->Location = System::Drawing::Point(5, 113);
			this->Button_LoadClasses->Margin = System::Windows::Forms::Padding(2);
			this->Button_LoadClasses->Name = L"Button_LoadClasses";
			this->Button_LoadClasses->Size = System::Drawing::Size(260, 23);
			this->Button_LoadClasses->TabIndex = 3;
			this->Button_LoadClasses->Text = L"Change .names File";
			this->Button_LoadClasses->UseVisualStyleBackColor = true;
			this->Button_LoadClasses->Click += gcnew System::EventHandler(this, &MainWindow::Button_LoadClasses_Click);
			// 
			// GroupBox_Classes
			// 
			this->GroupBox_Classes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBox_Classes->FormattingEnabled = true;
			this->GroupBox_Classes->Location = System::Drawing::Point(4, 18);
			this->GroupBox_Classes->Margin = System::Windows::Forms::Padding(2);
			this->GroupBox_Classes->Name = L"GroupBox_Classes";
			this->GroupBox_Classes->Size = System::Drawing::Size(264, 82);
			this->GroupBox_Classes->TabIndex = 0;
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
			this->buttonRemoveAnnotation->Location = System::Drawing::Point(155, 174);
			this->buttonRemoveAnnotation->Margin = System::Windows::Forms::Padding(2);
			this->buttonRemoveAnnotation->Name = L"buttonRemoveAnnotation";
			this->buttonRemoveAnnotation->Size = System::Drawing::Size(112, 23);
			this->buttonRemoveAnnotation->TabIndex = 6;
			this->buttonRemoveAnnotation->Text = L"Remove Annotation";
			this->buttonRemoveAnnotation->UseVisualStyleBackColor = true;
			// 
			// listBoxAnnotations
			// 
			this->listBoxAnnotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBoxAnnotations->FormattingEnabled = true;
			this->listBoxAnnotations->Location = System::Drawing::Point(2, 17);
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
			this->groupBox4->Size = System::Drawing::Size(539, 102);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Shortcuts";
			// 
			// imageDisplay
			// 
			this->imageDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->imageDisplay->BackColor = System::Drawing::SystemColors::WindowText;
			this->imageDisplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->imageDisplay->Location = System::Drawing::Point(2, 2);
			this->imageDisplay->Margin = System::Windows::Forms::Padding(2);
			this->imageDisplay->Name = L"imageDisplay";
			this->imageDisplay->Size = System::Drawing::Size(526, 446);
			this->imageDisplay->TabIndex = 6;
			this->imageDisplay->TabStop = false;
			this->imageDisplay->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::imageDisplay_MouseDown);
			this->imageDisplay->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::imageDisplay_MouseUp);
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
			this->classescontainer->ResumeLayout(false);
			this->classescontainer->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageDisplay))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		protected: System::Void BrowseFolder();
		//Browse for a folder of images

		protected: System::Void LoadFolder(String^);
		//Loop through the contents of a folder and load supported image files

		protected: System::Void AddImage(String^);
		//Create a new image object and add it to the list

		protected: System::Void BrowseFile();
		//Browse for a single file (classes only)

		protected: System::Void ClearImages();
		//Clear image list

		protected: System::Void ClearClasses();
		//Clear class list

		protected: System::Void LoadClasses(String^);
		//Load classes from a file

		protected: System::Void AddClass(String^);
		//Add a class to the list

		protected: System::Void RemoveClass(int);
		//Remove a class from the list

		protected: System::Void WriteClass(String^);
		//Append a class to the file

		protected: System::Void AddPolygonalAnnotation(int, List<int>^, String^);
		//Create a square annotation

		protected: System::Void RemovePolygonalAnnotation(int, int);
		//Remove a square annotation

		protected: System::Void ResizePolygonalAnnotation(int, int, List<int>^);
		//Resize a square annotation

		protected: System::Void RenamePolygonalAnnotation(int, int, String^);
		//Change the label of a polygonal annotation

		protected: System::Void SortImageByName(String^);
		//Sort the files in the image pane by their name (ascending or descending)

		protected: System::Void SortImageByDate(String^);
		//Sort the files in the image pane by their date modified (ascending or descending)

		protected: System::Void SortClassPane(String^);
		//Sort the items in the class pane by their name (ascending or descending)

		protected: System::Void RenderAnnotations(int);
		//Render currently loaded image and annotation


		///Calculate point relative to image
		protected: int CalculatePos(int, int, float);

		// Functions below cannot currently be moved out of header - cannot add more arguments (ie the MainWindow) as they use eventhandlers

		

		private: System::Void imageDisplay_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			GUI::mouseDownLocation = System::Windows::Forms::Cursor::Position;

			if (GUI::loadedImages->Count == 0)
			{
				GUI::loadedImages->Add(gcnew ImageFile);
			}

			if (GUI::loadedImages[GUI::drawnImage]->annotationFiles->Count == 0) 
			{
				GUI::loadedImages[GUI::drawnImage]->annotationFiles->Add(gcnew AnnotationFile);
			}
		}

		private: System::Void imageDisplay_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			List<int>^ tempVertices = gcnew List<int>;
			Point mouseUpLocation = System::Windows::Forms::Cursor::Position;
			Point^ mouseDownLocation = GUI::mouseDownLocation;
			int mouseUpX = mouseDownLocation->X;
			int mouseUpY = mouseDownLocation->Y;
			PolygonalAnnotation^ tempAnnotation = gcnew PolygonalAnnotation;
			tempVertices->Add(mouseUpX);
			tempVertices->Add(mouseUpY);
			tempVertices->Add(mouseUpLocation.X);
			tempVertices->Add(mouseUpLocation.Y);
			tempAnnotation->vertices = tempVertices;
			GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal->Add(tempAnnotation);
		}
		
		private: System::Void Button_ChangeDir_Click(System::Object^ sender, System::EventArgs^ e) {
			BrowseFolder();
			SortImageByName("A");
			Label_FolderPath->Text = "Path: " + GUI::workingFolderPath;
		}

		private: System::Void Button_LoadClasses_Click(System::Object^ sender, System::EventArgs^ e) {
			BrowseFile();
			SortClassPane("B");
		}
};
}
