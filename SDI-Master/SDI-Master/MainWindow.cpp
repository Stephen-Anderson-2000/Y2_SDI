#include "Classes.h"
#include "MainWindow.h"
#include "Globals.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Globals;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SDIMaster::MainWindow form;
	Application::Run(% form);
	List<imageData^>^ loadedImages = gcnew List<imageData^>;
	
}