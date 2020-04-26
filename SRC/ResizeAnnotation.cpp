#pragma once
#include "GUI.h"
#include "PositionCalculation.h"

using namespace System;
using namespace System::Drawing;
using namespace PositionCalculation;

bool CheckInRange(int range, int targetPos, int mousePos)
{
	int leftBoundary = targetPos - range;
	int rightBoundary = targetPos + range;
	if (mousePos >= leftBoundary && mousePos <= rightBoundary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FindSelectedAnnotation(Point^ mousePosition) {
	const int selectionRange = 5;
	for (int i = 0; i < GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal->Count; i++) {
		for (int x = 0; x <= 2; x += 2) {
			for (int y = 1; y <= 3; y += 2) {
				int xTarget = CalculatePos(GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices[x], GUI::xOffset, GUI::imageScale);
				int yTarget = CalculatePos(GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices[y], GUI::yOffset, GUI::imageScale);
				int xMouse = mousePosition->X;
				int yMouse = mousePosition->Y;
				if (CheckInRange(selectionRange, xTarget, xMouse) && CheckInRange(selectionRange, yTarget, yMouse))
				{
					GUI::xCornerSelected = x;
					GUI::yCornerSelected = y;
					GUI::annotationToResize = i;
				}
			}
		}

	}
}

void ResizeAnnotation(Point^ mousePosition)
{
	GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GUI::annotationToResize]->vertices[GUI::xCornerSelected] = CalculatePosInverse(mousePosition->X, GUI::xOffset, GUI::imageScale);
	GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GUI::annotationToResize]->vertices[GUI::yCornerSelected] = CalculatePosInverse(mousePosition->Y, GUI::yOffset, GUI::imageScale);
	GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GUI::annotationToResize]->vertices = ReorderVertices(GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GUI::annotationToResize]->vertices);
}

void QuickResizeAnnotation(int annotationIndex, int cornerIndex, int newSize) {
	GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[annotationIndex]->vertices[cornerIndex] = newSize;
	GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[annotationIndex]->vertices = ReorderVertices(GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[annotationIndex]->vertices);
}
