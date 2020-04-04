#include <string>;
#include "ImageData.h"
#include "GlobalImageList.h"
#include "MainWindow.h"
#include <filesystem>
#include "Annotation.h"
#include "AnnotationFile.h"
#include "ImageFile.h"
#include "GUI.h"
#include <fstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace SDIMaster;
using namespace GlobalList;
using namespace std;

namespace SDIMaster
{

	System::Void MainWindow::BrowseFolder() {
		System::String^ folderPath;
		FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog;
		{
			if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				folderPath = folderBrowserDialog->SelectedPath;
				GUI::workingFolderPath = folderPath;
				LoadFolder(folderPath);
			}
		}
	}

	System::Void MainWindow::LoadFolder(String^ folderPath)
	{
		cli::array<System::String^>^ fileArray = System::IO::Directory::GetFiles(folderPath);
		ClearImages();
		for (int i = 0; i < fileArray->Length; i++) {
			if (fileArray[i]->EndsWith(".jpg") || fileArray[i]->EndsWith(".png") || fileArray[i]->EndsWith(".jpeg") || fileArray[i]->EndsWith(".bmp"))
			{
				AddImage(fileArray[i]);
			}
		}
	}

	System::Void MainWindow::AddImage(String^ filePath)
	{
		FileInfo^ tempFileInfo = gcnew FileInfo(filePath);
		ImageFile^ tempImage = gcnew ImageFile;
		tempImage->displayFileName = Path::GetFileName(filePath);
		tempImage->imageID = gcnew Bitmap(filePath);
		tempImage->dimensions = gcnew Point(tempImage->imageID->Width, tempImage->imageID->Height);
		tempImage->annotationFiles->Add(gcnew AnnotationFile);
		tempImage->creationDate = tempFileInfo->LastWriteTime;
		GUI::LoadImageToList(tempImage);
	}

	System::Void MainWindow::ClearImages()
	{
		GUI::loadedImages->Clear();
	}

	System::Void MainWindow::BrowseFile() {
		System::String^ namesPath;
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		{
			openFileDialog->InitialDirectory = "c:\\";
			openFileDialog->Filter = ".names file (*.names)|*.names";
			openFileDialog->FilterIndex = 0;
			openFileDialog->RestoreDirectory = true;
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//Get the path of specified file
				namesPath = openFileDialog->FileName;
				GUI::labelFile = namesPath;
				ClearClasses();
				LoadClasses(namesPath);
			}
		}
	}

	System::Void MainWindow::LoadClasses(String^ filePath) {
		StreamReader^ nameFile = gcnew StreamReader(filePath);
		String^ line;
		while (!nameFile->EndOfStream) {
			line = nameFile->ReadLine();
			GUI::labelNames->Add(line);
		}
		nameFile->Close();
	}

	System::Void MainWindow::ClearClasses()
	{
		GUI::labelNames->Clear();
		GUI::labelIndices->Clear();
	}

	System::Void MainWindow::AddClass(String^ className) {
		GUI::labelNames->Add(className);
		WriteClass(className);
	}

	System::Void MainWindow::WriteClass(String^ className) {
		StreamWriter^ nameFile = gcnew StreamWriter(GUI::labelFile, true);
		nameFile->WriteLine(className);
		nameFile->Close();
	}

	System::Void MainWindow::RemoveClass(int classIndex) {
		StreamWriter^ nameFile = gcnew StreamWriter(GUI::labelFile);
		GUI::labelNames->RemoveAt(classIndex);
		for (int i = 0; i < GUI::labelNames->Count; i++) {
			nameFile->WriteLine(GUI::labelNames[i]);
		}
		nameFile->Close();
	}

	System::Void MainWindow::SortImageByName(String^ order) {
		GUI::imageIndices->Clear();
		GroupBox_Images->Items->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {
			GUI::imageIndices->Add(i);
			GroupBox_Images->Items->Add(GUI::loadedImages[i]->displayFileName);
		}
	}

	System::Void MainWindow::SortImageByDate(String^ order) {
		GUI::imageIndices->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {

		}
	}

	System::Void MainWindow::SortClassPane(String^ order) {
		GUI::imageIndices->Clear();
		GroupBox_Classes->Items->Clear();
		//sort
		for (int i = 0; i < GUI::labelNames->Count; i++) {
			GUI::labelIndices->Add(i);
			GroupBox_Classes->Items->Add(GUI::labelNames[i]);
		}
	}

	System::Void MainWindow::AddPolygonalAnnotation(int imageIndex, List<int>^ vertices, String^ label) {
		GUI::loadedImages[imageIndex]->annotationFiles[0]->createPolygonalAnnotation(label, vertices);
	}

	System::Void MainWindow::ResizePolygonalAnnotation(int imageIndex, int annotationIndex, List<int>^ vertices) {
		GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal[annotationIndex]->vertices = vertices;
	}

	System::Void MainWindow::RenamePolygonalAnnotation(int imageIndex, int annotationIndex, String^ name) {
		GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal[annotationIndex]->label = name;
	}

	System::Void MainWindow::RemovePolygonalAnnotation(int imageIndex, int annotationIndex) {
		GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal->RemoveAt(annotationIndex);
	}

	System::Void MainWindow::RenderAnnotations(int imageIndex)
	{
		imageDisplay->BackgroundImage = GUI::loadedImages[GUI::drawnImage]->imageID;
		GUI::boxCanvas->Clear(Color::Black);

		//Calculate scaling of image
		GUI::imageScale = float(imageDisplay->Width) / float(imageDisplay->BackgroundImage->Width);
		if (float(imageDisplay->Height) / float(imageDisplay->BackgroundImage->Height) < GUI::imageScale)
		{
			GUI::imageScale = float(imageDisplay->Height) / float(imageDisplay->BackgroundImage->Height);
			GUI::yOffset = 0;
			GUI::xOffset = floor((imageDisplay->Width - float(imageDisplay->BackgroundImage->Width) * GUI::imageScale) / 2);
		}
		else
		{
			GUI::yOffset = floor((imageDisplay->Height - float(imageDisplay->BackgroundImage->Height) * GUI::imageScale) / 2);
			GUI::xOffset = 0;
		}
		GUI::boxCanvas->DrawImage(imageDisplay->BackgroundImage, float(GUI::xOffset), float(GUI::yOffset), float(imageDisplay->BackgroundImage->Width) * GUI::imageScale, float(imageDisplay->BackgroundImage->Height) * GUI::imageScale);
		//Draw boxes
		Color boxColour = Color::FromArgb(128, 255, 0, 0);
		Pen^ boxBrush = gcnew Pen(boxColour, 2);
		for (int i = 0; i < GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal->Count; i++)
		{
			List<int>^ coordinates = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices;
			Rectangle polygonalAnnotation = Rectangle(CalculatePos(coordinates[0], GUI::xOffset, GUI::imageScale), CalculatePos(coordinates[1], GUI::yOffset, GUI::imageScale), CalculatePos(coordinates[2], GUI::xOffset, GUI::imageScale) - CalculatePos(coordinates[0], GUI::xOffset, GUI::imageScale), CalculatePos(coordinates[3], GUI::yOffset, GUI::imageScale) - CalculatePos(coordinates[1], GUI::yOffset, GUI::imageScale));
			GUI::boxCanvas->DrawRectangle(boxBrush, polygonalAnnotation);
		}

	}

	int MainWindow::CalculatePos(int position, int offset, float imageScale) {
		int newPos = floor(float(position) * imageScale + float(offset));
		return newPos;
	}

	int MainWindow::CalculatePosInverse(int position, int offset, float imageScale) {
		int newPos = floor(float(position - float(offset)) / imageScale);
		return newPos;
	}

}