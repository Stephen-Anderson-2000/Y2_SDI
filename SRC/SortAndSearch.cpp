#include <string>;
#include "GUI.h"
#include "ImageFile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;

List<String^>^ FilterList(List<String^>^ stringList, String^ filterTerm) {
	List<String^>^ returnList = gcnew List<String^>;
	for (int i = 0; i < stringList->Count; i++) {
		if (stringList[i]->Contains(filterTerm))
		{
			returnList->Add(stringList[i]);
		}
	}
	return returnList;
}

List<String^>^ SortList(List<String^>^ stringList, int order) {
	int n = stringList->Count;
	bool swap = true;
	String^ tempString;
	while (swap) {
		swap = false;
		for (int i = 1; i < n; i++) {
			if (System::String::Compare(stringList[i - 1], stringList[i]) > 0) {
				tempString = stringList[i - 1];
				stringList[i - 1] = stringList[i];
				stringList[i] = tempString;
				swap = true;
			}
		}
	}
	if (order < 0) {
		stringList->Reverse();
	}
	return stringList;
}

List<String^>^ FilterAndSort(List<String^>^ stringList, String^ filterTerm, int order) {
	stringList = FilterList(stringList, filterTerm);
	stringList = SortList(stringList, order);
	return stringList;
}