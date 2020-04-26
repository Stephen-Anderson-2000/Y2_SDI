#pragma once
#include "GUI.h"
#include "PositionCalculation.h"

using namespace System;
using namespace System::Drawing;


int FindSelectedAnnotation(Point mousePosition) {
	for (int i = 0; i < GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal->Count; i++) {
		//int 
	}
}