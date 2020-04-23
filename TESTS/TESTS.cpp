#include "pch.h"
#include "CppUnitTest.h"
//#include "../SRC/MainWindow.h"
//#include "../SRC/SortAndSearch.h"
//#include "../SRC/Annotation.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTS
{
	TEST_CLASS(LinkedList)
	{
	public:
		TEST_METHOD(EmptyList)
		{

		}

		TEST_METHOD(OneItem)
		{

		}

		TEST_METHOD(AddItem)
		{

		}

		TEST_METHOD(RemoveItem)
		{

		}

		TEST_METHOD(OneHundredItems)
		{

		}

		TEST_METHOD(RemoveAllItems)
		{

		}

		TEST_METHOD(RemoveAddAllItems)
		{

		}
	};

	TEST_CLASS(Searching)
	{
	public:
		TEST_METHOD(EmptyList)
		{

		}

		TEST_METHOD(OnlyItem)
		{

		}

		// Next tests require >= 5 items in their list
		TEST_METHOD(CompleteMatch)
		{

		}

		TEST_METHOD(PartialMatch)
		{

		}

		TEST_METHOD(MultipleMatches)
		{

		}

		// Tests when the *input* is all capital letters
		TEST_METHOD(AllUpperCaseLetters)
		{

		}

		TEST_METHOD(AllLowerCaseLetters)
		{

		}

		TEST_METHOD(IncludesNumbers)
		{

		}
	};

	TEST_CLASS(SortingByName)
	{
	public:
		TEST_METHOD(EmptyList)
		{

		}

		TEST_METHOD(OneItem)
		{

		}

		// The next tests require a list of 10 items
		TEST_METHOD(AToZ)
		{

		}

		TEST_METHOD(ZToA)
		{

		}

		TEST_METHOD(ZeroToNine)
		{

		}

		TEST_METHOD(NineToZero)
		{

		}

		TEST_METHOD(CharactersSeparatedBySpaces)
		{

		}

		TEST_METHOD(NamesIncludeSymbols)
		{

		}
	};

	TEST_CLASS(SortingByDate)
	{
	public:
		TEST_METHOD(EmptyList)
		{

		}

		TEST_METHOD(OneItem)
		{

		}
	};
}
