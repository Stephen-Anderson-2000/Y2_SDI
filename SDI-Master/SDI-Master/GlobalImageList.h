#pragma once
#include "ImageData.h";
namespace GlobalList
{
	///Global list of all currently loaded image objects.
	public ref class GlobalClass 
	{
		public: static List<imageData^> loadedImages;
	};
	
}