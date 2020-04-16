#include "ImageData.h"
#include "MainWindow.h"
#include "GlobalImageList.h"

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SDIMaster::MainWindow form;
	Application::Run(% form);
	List<imageData^>^ loadedImages = gcnew List<imageData^>;
}