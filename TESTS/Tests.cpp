#include "pch.h"
#include "CppUnitTest.h"
#include "../SRC/ClassList.h"


#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTS
{
	TEST_CLASS(LinkedListTests)
	{
	public:
		TEST_METHOD(EmptyList)
		{
			LinkedListString myList;
			Assert::AreEqual(myList.Count(), 0);
		} // Creates an empty linked list object to see if there are any issues when creating it

		TEST_METHOD(AddItem)
		{
			LinkedListString myList;
			std::string myString = "Hello";
			myList.Add(myString);
			Assert::AreEqual(myList.Count(), 1);
		} // Adds a single item to the empty linked list to see if there are any errors when doing so

		TEST_METHOD(RemoveLastItem)
		{
			LinkedListString myList;
			std::string myString = "Hello";
			myList.Add(myString);
			// get count
			myList.Remove(1);
			// assert that the count is not equal here
		} 

		// Remove the second item from a list of three
		TEST_METHOD(RemoveMiddleItem)
		{
			LinkedListString myList;
			std::string myString = "Hello";
			myList.Add(myString);
			myString = "lovely";
			myList.Add(myString);
			myString = "world";
			myList.Add(myString);
		}

		TEST_METHOD(RemoveFirstItem)
		{

		}

		// Remove the only item that is in the list
		TEST_METHOD(RemoveAllItems)
		{

		}

		TEST_METHOD(OneHundredItems)
		{

		}

		TEST_METHOD(OneThousandItems)
		{

		}

		// Done with a list of 100 items
		TEST_METHOD(RemoveAndAddAllItems)
		{

		}

		TEST_METHOD(AddingInvalidType)
		{

		}
	};

	TEST_CLASS(SearchingTests)
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
		TEST_METHOD(AllUppercaseLetters)
		{

		}

		TEST_METHOD(AllLowercaseLetters)
		{

		}

		TEST_METHOD(IncludesNumbers)
		{

		}

		TEST_METHOD(IncludesSpecialCharacters)
		{

		}
	};

	TEST_CLASS(SortingByNameTests)
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

		TEST_METHOD(OneHundredItems)
		{

		}
	};

	TEST_CLASS(SortingByDateTests)
	{
	public:
		TEST_METHOD(EmptyList)
		{

		}

		TEST_METHOD(OneItem)
		{

		}

		TEST_METHOD(NewestFirst)
		{

		}

		TEST_METHOD(OldestFirst)
		{

		}

		TEST_METHOD(OneHundredItems)
		{

		}
	};
}
