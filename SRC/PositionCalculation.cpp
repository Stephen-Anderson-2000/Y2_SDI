#include <string>
#include "PositionCalculation.h"

namespace PositionCalculation {
	int CalculatePos(int position, int offset, float imageScale) {
		int newPos = floor(float(position) * imageScale + float(offset));
		return newPos;
	}

	int CalculatePosInverse(int position, int offset, float imageScale) {
		int newPos = floor(float(position - float(offset)) / imageScale);
		return newPos;
	}
}