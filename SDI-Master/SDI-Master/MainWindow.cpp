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

		for (int i = 0; i < fileArray->Length; i++) {
			if (fileArray[i]->EndsWith(".jpg") || fileArray[i]->EndsWith(".png") || fileArray[i]->EndsWith(".bmp"))
			{
				AddImage(fileArray[i]);
			}
		}
	}

	System::Void MainWindow::AddImage(String^ filePath)
	{
		FileInfo^ tempFileInfo = gcnew FileInfo(filePath);
		ImageFile^ tempImage = gcnew ImageFile;
		tempImage->displayFileName = filePath;
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
	}

	System::Void MainWindow::WriteClass(String^ className) {
		GUI::labelNames->Add(className);
	}

	System::Void MainWindow::RemoveClass(int classIndex) {

	}

	System::Void MainWindow::SortImageByName(String^ order) {
		GUI::imageIndices->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {

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
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {

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
		Graphics^ boxCanvas = imageDisplay->CreateGraphics();
		boxCanvas->Clear(Color::Black);
		float imageScale;
		int xOffset;
		int yOffset;

		//Calculate scaling of image
		imageScale = float(imageDisplay->Width) / float(imageDisplay->BackgroundImage->Width);
		if (imageDisplay->Height / imageDisplay->BackgroundImage->Height < imageScale)
		{
			imageScale = float(imageDisplay->Height) / float(imageDisplay->BackgroundImage->Height);
			yOffset = 0;
			xOffset = floor((imageDisplay->Width - float(imageDisplay->BackgroundImage->Width) * imageScale) / 2);
		}
		else
		{
			yOffset = floor((imageDisplay->Height - float(imageDisplay->BackgroundImage->Height) * imageScale) / 2);
			xOffset = 0;
		}
		boxCanvas->DrawImage(imageDisplay->BackgroundImage, float(xOffset), float(yOffset), float(imageDisplay->BackgroundImage->Width) * imageScale, float(imageDisplay->BackgroundImage->Height) * imageScale);
		
		//Draw boxes
		Color boxColour = Color::FromArgb(128, 255, 0, 0);
		Pen^ boxBrush = gcnew Pen(boxColour, 2);
		for (int i = 0; i < GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal->Count; i++)
		{
			List<int>^ coordinates = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices;
			Rectangle polygonalAnnotation = Rectangle(CalculatePos(coordinates[0], xOffset, imageScale), CalculatePos(coordinates[1], yOffset, imageScale), CalculatePos(coordinates[2], xOffset, imageScale) - CalculatePos(coordinates[0], xOffset, imageScale), CalculatePos(coordinates[3], yOffset, imageScale) - CalculatePos(coordinates[1], yOffset, imageScale));
			boxCanvas->DrawRectangle(boxBrush, polygonalAnnotation);
		}

	}

	int MainWindow::CalculatePos(int position, int offset, float imageScale) {
		int newPos = floor(float(position) * imageScale + float(offset));
		return newPos;
	}

}