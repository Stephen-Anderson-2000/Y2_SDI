#pragma once

#include "ImageFile.h"
#include "Annotation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

	public ref class GUI 
	{
	public :
		static int drawnImage;
		static List<ImageFile^>^ loadedImages;
		static List<Annotation^>^ annotations;
		static Point^ mouseDownLocation;
		
		static void LoadImageToList(ImageFile^ file) {
			loadedImages->Add(file);
		}

		static void LoadImageToCanvas(int imageIndex) {
			drawnImage = imageIndex;
		}

		static void DrawImage() {

		}

		ImageFile^ GetImage(int index) {

		}

	};