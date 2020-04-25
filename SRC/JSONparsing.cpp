#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "GUI.h"
#include "Classlist.h"
#include "JSONparsing.h"

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
	int imageCount = 0;
	file["annotatedImages"] = json::array();
	std::string tempString;
	for (int i = 0; i < GUI::loadedImages->Count; i++) {
		if (GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count != 0) {
			
			tempString = SystemToStdString(GUI::loadedImages[i]->displayFileName);
			file["annotatedImages"][imageCount] = json::object();
			file["annotatedImages"][imageCount]["filename"] = tempString;
			file["annotatedImages"][imageCount]["shapeCount"] = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count;
			file["annotatedImages"][imageCount]["shapes"] = json::array();
			for (int j = 0; j < GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count; j++) {
				tempString = SystemToStdString(GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->label);
				int Point1X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[0];
				int Point1Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[1];
				int Point2X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[2];
				int Point2Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[3];
				file["annotatedImages"][imageCount]["shapes"][j] = json::object();
				file["annotatedImages"][file["imageCount"] - 1]["shapes"].push_back({ {"label", tempString}, {"point1", {Point1X, Point1Y}}, {"point2", {Point2X, Point2Y}} });
			}
			imageCount += 1;
		}
	}
	file["imageCount"] = imageCount;
	ofstream writeFile("file.json");
	writeFile << file << endl;
	writeFile.close();
}