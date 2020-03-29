#include <string>;
#include "ImageData.h"
#include "GlobalImageList.h"
#include "MainWindow.h"
#include <filesystem>
#include "Annotation.h"
#include "AnnotationFile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace SDIMaster;
using namespace GlobalList;

namespace SDIMaster
{

	System::String^ MainWindow::GetFilePath()
	{
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

	System::Void MainWindow::LoadImage(String^ filePath, MainWindow^ w)
	{
		if (filePath != nullptr)
		{
			GlobalClass::loadedImages.Add(gcnew imageData);
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->srcImage = gcnew Bitmap(filePath);
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->boxList = gcnew List<List<int>^>;
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->fileName = filePath;
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->labelList = gcnew List<String^>;
			GlobalClass::loadedImages[GlobalClass::loadedImages.Count - 1]->boxNameList = gcnew List<String^>;
			ReloadImageList(w);
			RefreshImageBox(w);
			w->listBoxImage->SelectedIndex = GlobalClass::loadedImages.Count - 1;

		}
	}

	System::Void MainWindow::ReloadImageList(MainWindow^ w)
	{
		w->listBoxImage->Items->Clear();
		for (int i = 0; i < GlobalClass::loadedImages.Count; i++) {
			w->listBoxImage->Items->Add(GlobalClass::loadedImages[i]->fileName);
		}
	}

	System::Void MainWindow::ReloadLabelList(MainWindow^ w)
	{
		w->listBoxLabels->Items->Clear();
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count) {
			for (int i = 0; i < GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList->Count; i++) {
				w->listBoxLabels->Items->Add(GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList[i]);
			}
		}
	}

	System::Void MainWindow::RefreshImageBox(MainWindow^ w)
	{
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count)
		{
			w->imageDisplay->BackgroundImage = GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->srcImage;
		}
		else
		{
			w->imageDisplay->BackgroundImage = nullptr;
		}
	}

	System::Void MainWindow::AddLabelDialogue(String^ labelName, MainWindow^ w)
	{
		//TBA
	}

	System::Void MainWindow::AddLabel(String^ labelName, MainWindow^ w)
	{
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList->Add(labelName);
	}

	System::Void MainWindow::RemoveLabel(MainWindow^ w)
	{
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count)
		{
			if (-1 < w->listBoxLabels->SelectedIndex && w->listBoxLabels->SelectedIndex < GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->labelList->Count)
			{
				GlobalClass::loadedImages[listBoxImage->SelectedIndex]->labelList->RemoveAt(listBoxLabels->SelectedIndex);
				ReloadLabelList(w);
			}
		}
	}

	System::Void MainWindow::AddAnnotation(String^ Name, Point^ lCorner, Point^ rCorner, MainWindow^ w)
	{
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList->Add(gcnew List<int>);
		int index = GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList->Count - 1;
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList[index]->Add(lCorner->X);
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList[index]->Add(lCorner->Y);
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList[index]->Add(rCorner->X);
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList[index]->Add(rCorner->Y);
		GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxNameList->Add(Name);
	}

	System::Void MainWindow::RemoveAnnotation(int index, MainWindow^ w)
	{
		if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count)
		{
			int index = w->listBoxAnnotations->SelectedIndex;
			if (-1 < index && index < GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxNameList->Count)
			{
				GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxNameList->RemoveAt(index);
				GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList->RemoveAt(index);
			}
		}
	}

	System::Void MainWindow::ReloadAnnotationList(MainWindow^ w) {
		listBoxAnnotations->Items->Clear();
		try {
			if (-1 < w->listBoxImage->SelectedIndex && w->listBoxImage->SelectedIndex < GlobalClass::loadedImages.Count)
			{
				for (int i = 0; i < GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxNameList->Count; i++)
				{
					List<int>^ tempList = GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxList[i];
					int posX1 = tempList[0];
					int posY1 = tempList[1];
					int posX2 = tempList[2];
					int posY2 = tempList[3];
					String^ name = GlobalClass::loadedImages[w->listBoxImage->SelectedIndex]->boxNameList[i];
					//Format: [name] (X1-X2, Y1-Y2)
					listBoxAnnotations->Items->Add("[" + name + "] (" + posX1.ToString() + "-" + posX2.ToString() + ", " + posY1.ToString() + "-" + posY2.ToString() + ")");
				}
			}
		}
		catch (...) {
			//oop
		}

	}

	int MainWindow::CalculatePos(int position, int offset, float imageScale) {
		int newPos = floor(float(position) * imageScale + float(offset));
		return newPos;
	}

	System::Void MainWindow::DrawAnnotations(MainWindow^ w)
	{
		Graphics^ boxCanvas = w->imageDisplay->CreateGraphics();
		boxCanvas->Clear(Color::Black);
		float imageScale;
		int xOffset;
		int yOffset;
		imageScale = float(w->imageDisplay->Width) / float(w->imageDisplay->BackgroundImage->Width);
		if (w->imageDisplay->Height / imageDisplay->BackgroundImage->Height < imageScale)
		{
			imageScale = float(w->imageDisplay->Height) / float(w->imageDisplay->BackgroundImage->Height);
			yOffset = 0;
			xOffset = floor((imageDisplay->Width - float(imageDisplay->BackgroundImage->Width) * imageScale) / 2);
		}
		else
		{
			yOffset = floor((imageDisplay->Height - float(imageDisplay->BackgroundImage->Height) * imageScale) / 2);
			xOffset = 0;
		}
		boxCanvas->DrawImage(imageDisplay->BackgroundImage, float(xOffset), float(yOffset), float(imageDisplay->BackgroundImage->Width) * imageScale, float(imageDisplay->BackgroundImage->Height) * imageScale);
		Color boxColour = Color::FromArgb(128, 255, 0, 0);
		SolidBrush^ boxBrush = gcnew SolidBrush(boxColour);
		int imageIndex = w->listBoxImage->SelectedIndex;
		for (int i = 0; i < GlobalClass::loadedImages[imageIndex]->boxList->Count; i++)
		{
			List<int>^ coordinates = GlobalClass::loadedImages[imageIndex]->boxList[i];
			boxCanvas->FillRectangle(boxBrush, CalculatePos(coordinates[0], xOffset, imageScale), CalculatePos(coordinates[1], yOffset, imageScale), CalculatePos(coordinates[2], xOffset, imageScale) - CalculatePos(coordinates[0], xOffset, imageScale), CalculatePos(coordinates[3], yOffset, imageScale) - CalculatePos(coordinates[1], yOffset, imageScale));
		}

	}
}