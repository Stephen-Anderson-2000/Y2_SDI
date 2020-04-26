#include <string>
#include "PositionCalculation.h"

using namespace System;
using namespace System::Collections::Generic;

namespace PositionCalculation {
	int CalculatePos(int position, int offset, float imageScale) {
		int newPos = floor(float(position) * imageScale + float(offset));
		return newPos;
	}

	int CalculatePosInverse(int position, int offset, float imageScale) {
		int newPos = floor(float(position - float(offset)) / imageScale);
		return newPos;
	}

	List<int>^ ReorderVertices(List<int>^ vertices)
	{
		int tempValue;

		if (vertices[2] < vertices[0]) {
			tempValue = vertices[0];
			vertices[0] = vertices[2];
			vertices[2] = tempValue;
		}

		if (vertices[3] <= vertices[1]) {
			tempValue = vertices[1];
			vertices[1] = vertices[3];
			vertices[3] = tempValue;
		}

		return vertices;
	}
}