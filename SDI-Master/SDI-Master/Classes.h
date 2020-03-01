#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class imageData {
		public:
			Bitmap^ srcImage;
			List<List<int>^>^ boxList;
			List<String^>^ boxNameList;
			List<String^>^ labelList;
			String^ fileName;
	};