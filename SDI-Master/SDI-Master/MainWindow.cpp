#include <string>;
#include "Classes.h"
#include "Globals.h"
#include "LabelDialogue.h"
#include "MainWindow.h"
#include <filesystem>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace SDIMaster;
using namespace Globals;

namespace SDIMaster {
	System::String^ MainWindow::GetFilePath() {
		System::String^ imagePath = nullptr;
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		{
			openFileDialog->InitialDirectory = "c:\\";
			openFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			openFileDialog->FilterIndex = 2;
			openFileDialog->RestoreDirectory = true;
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//Get the path of specified file
				imagePath = openFileDialog->FileName;

			}
			return imagePath;
		}
	}

	System::Void MainWindow::ReloadImageList(MainWindow^ w) {
		w->listBoxImage->Items->Clear();
		for (int i = 0; i < GlobalClass::loadedImages.Count; i++) {
			w->listBoxImage->Items->Add(GlobalClass::loadedImages[i]->fileName);
		}
	}

	System::Void MainWindow::RefreshImageBox(MainWindow^ w) {
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count) {
			w->imageDisplay->BackgroundImage = GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->srcImage;
		}
		else {
			w->imageDisplay->BackgroundImage = nullptr;
		}
	}

	//Loads the image from a given file path into the global array.
	System::Void MainWindow::LoadImage(String^ filePath, MainWindow^ w) {
		if (filePath != nullptr)
		{
			GlobalClass::loadedImages.Add(gcnew imageData);
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->srcImage = gcnew Bitmap(filePath);
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->boxList = gcnew List<List<Point>^>;
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->fileName = filePath;
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->labelList = gcnew List<String^>;
			ReloadImageList(w);
			RefreshImageBox(w);
			w->listBoxImage->SelectedIndex = GlobalClass::loadedImages.Count - 1;

		}
	}


	System::Void MainWindow::ReloadLabelList(MainWindow^ w) {
		w->listBoxLabels->Items->Clear();
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count) {
			for (int i = 0; i < GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList->Count; i++) {
				w->listBoxLabels->Items->Add(GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList[i]);
			}
		}
	}

	System::Void MainWindow::drawBoxTest(MainWindow^ w) {
		Graphics^ boxCanvas = w->imageDisplay->CreateGraphics();
		Pen^ boxPen = gcnew Pen(Color::Red);
		boxCanvas->DrawRectangle(boxPen, 0, 0, 20, 20);
	}

	System::Void MainWindow::AddLabelDialogue(String^ labelName, MainWindow^ w) {
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList->Add(labelName);
	}
}