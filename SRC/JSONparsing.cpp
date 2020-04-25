#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "GUI.h"
#include "Classlist.h"

using namespace std;
using json = nlohmann::json;

string SystemToStdString(String^ inputString) {
	char* cstr = (char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(inputString)).ToPointer();
	string convertedString = cstr;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)cstr));
	return convertedString;
}

void SaveJson() {
	json file;
	file["imageCount"] = 0;
	file["annotatedImages"] = {};
	std::string tempString;
	for (int i = 0; i < GUI::loadedImages->Count; i++) {
		if (GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count != 0) {
			file["imageCount"] += 1;
			file["annotatedImages"].push_back({ {"filename", SystemToStdString(GUI::loadedImages[i]->displayFileName)}, {"shapeCount", GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count}, {"shapes", {}} });
			for (int j = 0; j < GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count; j++) {
				tempString = SystemToStdString(GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->label);
				int Point1X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[0];
				int Point1Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[1];
				int Point2X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[2];
				int Point2Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[3];
				file["annotatedImages"][file["imageCount"] - 1]["shapes"].push_back({ {"label", tempString}, {"point1", {Point1X, Point1Y}}, {"point2", {Point2X, Point2Y}} });
			}
		}
		ofstream writeFile("file.json");
		writeFile << file << endl;
	}
}