#include "pch.h"
#include "CppUnitTest.h"
#include "../SRC/ClassList.h"

#include <iostream>
#include <fstream>
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

			// Checks the length of the list to show the object exists
			Assert::AreEqual(0, myList.Count()); 
		} // Creates an empty linked list object to see if there are any issues when creating it

		TEST_METHOD(AddItem)
		{
			LinkedListString myList;
			std::string myString = "Hello";
			myList.Add(myString);

			// Checks the length of the linkedlist to make sure that one item has been added
			Assert::AreEqual(1, myList.Count()); 
		} // Adds a single item to the empty linked list to see if there are any errors when doing so

		TEST_METHOD(RemoveLastItem)
		{
			LinkedListString myList;
			std::string myString = "Hello";

			myList.Add(myString);
			myList.Remove(0);

			// Looks at the length of the list to see if the item has been removed
			Assert::AreEqual(0, myList.Count());
		} // Checks that it can remove the last and only item from the list

		TEST_METHOD(RemoveFirstItem)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "world";

			myList.Add(myString1);
			myList.Add(myString2);

			myList.Remove(0);

			// Checks to see that the second item moves to the first slot
			Assert::AreEqual(myString2, myList.At(0));
		} // Checks that removing the first item shifts the second one to the start

		TEST_METHOD(RemoveMiddleItemListOfThree)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "lovely";
			std::string myString3 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);

			// Removes the second element - "lovely"
			myList.Remove(1);

			// Confirms that "Hello" and "world" are still accessible
			Assert::AreEqual(myString1, myList.At(0));
			Assert::AreEqual(myString3, myList.At(1));
		} // Removes the second item from a list of three and checks that the remaining two items shift and can be accessed

		TEST_METHOD(RemoveMiddleItemListOfFive)
		{
			LinkedListString myList;
			std::string myString1 = "The";
			std::string myString2 = "quick";
			std::string myString3 = "brown";
			std::string myString4 = "fox";
			std::string myString5 = "jumped";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			// Removes the third item from the list
			myList.Remove(2);

			Assert::AreEqual(myString1, myList.At(0));
			Assert::AreEqual(myString2, myList.At(1));
			Assert::AreEqual(myString4, myList.At(2));
			Assert::AreEqual(myString5, myList.At(3));
		} // Removes the second item from a list of three and checks that the remaining two items shift and can be accessed

		TEST_METHOD(RemoveAllItemsReverse)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "lovely";
			std::string myString3 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);

			// Iterates through each item from back to front and removes it
			for (int i = myList.Count(); i >= 0; i--)
			{
				myList.Remove(i);
			}

			// Checks the number of items in the list to confirm they have been removed
			Assert::AreEqual(0, myList.Count());
		} // Removes all three items to check that they are removed correctly

		TEST_METHOD(RemoveAllItemsForwards)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "lovely";
			std::string myString3 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);

			int count = myList.Count();
			// Iterates through each item
			for (int i = 0; i < count; i++)
			{
				myList.Remove(0);
			}

			// Checks the number of items in the list to confirm they have been removed
			Assert::AreEqual(0, myList.Count());
		} // Removes all three items to check that they are removed correctly

		TEST_METHOD(OneHundredItems)
		{
			ifstream myFile("Test Resources/100 Words.txt");
			LinkedListString myList;
			std::string myArray[100];
			if (myFile.is_open())
			{
				for (int i = 0; i < 100; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}
			for (int i = 0; i < 100; i++)
			{
				myList.Add(myArray[i]);
			}
			Assert::AreEqual(100, myList.Count());
		}

		TEST_METHOD(TenThousandItems)
		{
			ifstream myFile("Test Resources/10000 Words.txt");
			LinkedListString myList;
			std::string myArray[10000];
			if (myFile.is_open())
			{
				for (int i = 0; i < 10000; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}
			for (int i = 0; i < 10000; i++)
			{
				myList.Add(myArray[i]);
			}
			Assert::AreEqual(10000, myList.Count());
		}

		// Done with a list of 100 items
		TEST_METHOD(RemoveAndAddHalfItems)
		{
			ifstream myFile("Test Resources/100 Words.txt");
			LinkedListString myList;
			std::string myArray[100];
			std::string myArray2[100];
			if (myFile.is_open())
			{
				for (int i = 0; i < 100; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}
			for (int i = 0; i < 100; i++)
			{
				myList.Add(myArray[i]);
			}
			for (int i = 50; i < 100; i++)
			{
				myArray2[i] = myList.At(0);
				myList.Remove(0);
			}
			for (int i = 50; i < 100; i++)
			{
				myList.Add(myArray2[i]);
			}
			Assert::AreEqual(myArray[75], myArray2[75]);
			Assert::AreEqual(100, myList.Count());
		}

		TEST_METHOD(OutOfRange)
		{
			LinkedListString myList;
			std::string myString = myList.At(5);
			std::string emptyString = "";
			Assert::AreEqual(emptyString, myString);
		}

		TEST_METHOD(AccessDeletedFirstValue)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			myList.Add(myString1);
			myList.Remove(0);
			std::string myString2 = myList.At(0);
			std::string emptyString = "";
			Assert::AreEqual(emptyString, myString2);
		}

		TEST_METHOD(AccessDeletedSecondValue)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Remove(1);

			std::string myString3 = myList.At(1);
			std::string emptyString = "";
			Assert::AreEqual(emptyString, myString3);
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
