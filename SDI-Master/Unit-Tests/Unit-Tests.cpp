#include "pch.h"
#include "CppUnitTest.h"
#include "../SDI-Master/MainWindow.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SDIMaster;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int myInt = 11;
			Assert::AreEqual(myInt, 11);	
		}
	};
}
