#include "ImageData.h"
#include "MainWindow.h"
#include "GlobalImageList.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace GlobalList;

/*! \mainpage Annotation Tool
 *
 * This project allows the user to create annotations on an image to assist with image recognition technology.
 * The project is currently in BETA - currently the project uses hardcoded data when creating new labels or annotations.
 * As of present, the program can load multiple images into memory, and display them with the annotations overlayed.
 * \subpage tba "To Be Added"
 *
 */

 /*! \page tba To Be Added
  *
  * As the project is further developed, the following features will be added:
  *
  * - Ability to export annotated images, annotation data, and label lists to a file.
  * - Ability to import annotation data and label lists from files.
  * - Ability to input custom label names.
  * - Ability to create & edit annotations by clicking & dragging on the image.
  * - Ability to edit existing labels and annotations.
  * - Ability to search through & sort images, labels, and annotations.
  * - Custom colours for different annotations.
  *
  */

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SDIMaster::MainWindow form;
	Application::Run(% form);
	List<imageData^>^ loadedImages = gcnew List<imageData^>;

}