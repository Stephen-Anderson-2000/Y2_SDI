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
			Assert::AreEqual(myString, myList.At(0)); 
		} // Adds a single item to the empty linked list to see if there are any errors when doing so

		TEST_METHOD(RemoveOnlyItem)
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
			std::string myString2 = "beautiful";
			std::string myString3 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);

			// Removes the first item ("Hello") from the list
			myList.Remove(0);

			// Checks to see that the second item moves to the first slot
			// and that the third item moves to the second slot
			Assert::AreEqual(myString2, myList.At(0));
			Assert::AreEqual(myString3, myList.At(1));
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

		TEST_METHOD(RemoveSecondItemListOfFour)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "there";
			std::string myString3 = "lovely";
			std::string myString4 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);

			myList.Remove(1);

			Assert::AreEqual(myString1, myList.At(0));
			Assert::AreEqual(myString3, myList.At(1));
			Assert::AreEqual(myString4, myList.At(2));
		}

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

			// Confirms that "The", "quick", "fox" and "jumped" are still accessible
			Assert::AreEqual(myString1, myList.At(0));
			Assert::AreEqual(myString2, myList.At(1));
			Assert::AreEqual(myString4, myList.At(2));
			Assert::AreEqual(myString5, myList.At(3));
		} // Removes the second item from a list of three and checks that the remaining two items shift and can be accessed

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
			// Iterates through each item and removes it, making the next shift to the head each time
			for (int i = 0; i < count; i++)
			{
				myList.Remove(0);
			}

			// Checks the number of items in the list to confirm they have been removed
			Assert::AreEqual(0, myList.Count());
		} // Removes all three items to check that they are removed correctly

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

		TEST_METHOD(OneHundredItems)
		{
			ifstream myFile("Test Resources/100 Words.txt");
			LinkedListString myList;
			std::string myArray[100];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 100; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			// Adds the loaded text items to the list
			for (int i = 0; i < 100; i++)
			{
				myList.Add(myArray[i]);
			}

			// Checks that there are 100 items in the list
			Assert::AreEqual(100, myList.Count());

			// Iterates through each item and checks that the order is kept and no data is corrupted
			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(myArray[i], myList.At(i));
			}
		} // Checks to see if the object can store 100 items without issue

		TEST_METHOD(TenThousandItems)
		{
			ifstream myFile("Test Resources/10000 Words.txt");
			LinkedListString myList;
			std::string myArray[10000];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10000; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			// Adds the loaded items to the list
			for (int i = 0; i < 10000; i++)
			{
				myList.Add(myArray[i]);
			}

			// Checks that there are 10000 items in the list
			Assert::AreEqual(10000, myList.Count());

			// Iterates through each item and checks that the order is kept and no data is corrupted
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(myArray[i], myList.At(i));
			}
		} // Checks to see if the object can store 10000 items without issue

		TEST_METHOD(RemoveAndAddHalfItems)
		{
			ifstream myFile("Test Resources/100 Words.txt");
			LinkedListString myList;
			std::string myArray[100];
			std::string myArray2[50];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 100; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			// Adds the loaded items to the list
			for (int i = 0; i < 100; i++)
			{
				myList.Add(myArray[i]);
			}

			// Copies the last 50 items from the list into an array then removes them from the list
			for (int i = 0; i < 50; i++)
			{
				myArray2[i] = myList.At(50);
				myList.Remove(0);
			}

			// Loops through the secondary array and adds the values back to the list
			for (int i = 0; i < 50; i++)
			{
				myList.Add(myArray2[i]);
			}

			// Compares the items at the same index to check if the order is kept
			// then checks that there are still exactly 100 items in the list
			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(myArray[i], myList.At(i));
			}
			Assert::AreEqual(100, myList.Count());
		} // Checks to see what happens if items are removed and added back to the list

		TEST_METHOD(OutOfRange)
		{
			LinkedListString myList;
			std::string myString = myList.At(5);
			std::string emptyString = "";

			Assert::AreEqual(emptyString, myString);
		} // Attempts to access an invalid entry

		TEST_METHOD(AccessDeletedOnlyValue)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			
			// Adds then removes the first item
			myList.Add(myString1);
			myList.Remove(0);

			// Attempts to fetch data from the now deleted value
			std::string myString2 = myList.At(0);

			// Checks to see if the exception is handled properly
			std::string emptyString = "";
			Assert::AreEqual(emptyString, myString2);
		} // Attempts to access a single item after it has been deleted

		TEST_METHOD(AccessDeletedLastValue)
		{
			LinkedListString myList;
			std::string myString1 = "Hello";
			std::string myString2 = "lovely";
			std::string myString3 = "world";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);

			// Removes the second item from the list
			myList.Remove(2);

			// Attempts to fetch data from the now deleted value
			std::string myString4 = myList.At(2);

			// Checks to see if the exception is handled properly
			std::string emptyString = "";
			Assert::AreEqual(emptyString, myString4);
		}

	};

	TEST_CLASS(SearchingTests)
	{
	public:
		TEST_METHOD(EmptyList)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string searchTerm = "test";

			searchedList = myList.Search(searchTerm);

			for (int i = 0; i < 1; i++)
			{
				Assert::AreEqual(myList.At(i), searchedList.At(i));
			}

		}

		TEST_METHOD(OnlyItem)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string searchTerm = "test";

			myList.Add(searchTerm);

			searchedList = myList.Search(searchTerm);

			for (int i = 0; i < 1; i++)
			{
				Assert::AreEqual(myList.At(i), searchedList.At(i));
			}

		}

		// Next tests require >= 5 items in their list
		TEST_METHOD(CompleteMatch)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beautiful";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "beautiful";
		}

		TEST_METHOD(PartialMatch)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beautiful";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "ut";
		}

		TEST_METHOD(MultipleMatches)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "lovely";
			std::string myString4 = "lovely";
			std::string myString5 = "day";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "lovely";
		}

		TEST_METHOD(AllUppercaseLetters)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beautiful";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "WHAT";
		}

		TEST_METHOD(AllLowercaseLetters)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beautiful";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "what";
		}

		TEST_METHOD(IncludesNumbers)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beaut1ful";
			std::string myString4 = "day";
			std::string myString5 = "2day";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "2day";
		}

		TEST_METHOD(PartialMatchIncludesNumbers)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "What";
			std::string myString2 = "a";
			std::string myString3 = "beaut1ful";
			std::string myString4 = "day";
			std::string myString5 = "2day";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "1";
		}

		TEST_METHOD(IncludesSpecialCharacters)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "It's";
			std::string myString2 = "a";
			std::string myString3 = "very *nice*";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "very *nice*";
		}

		TEST_METHOD(PartialMatchIncludesSpecialCharacters)
		{
			LinkedListString myList;
			LinkedListString searchedList;
			std::string myString1 = "It's";
			std::string myString2 = "a";
			std::string myString3 = "very *nice*";
			std::string myString4 = "day";
			std::string myString5 = "today";

			myList.Add(myString1);
			myList.Add(myString2);
			myList.Add(myString3);
			myList.Add(myString4);
			myList.Add(myString5);

			std::string searchTerm = "nice";
		}

		TEST_METHOD(Search100Items)
		{
			ifstream myFile("Test Resources/Unsorted Lists/100 Words.txt");
			LinkedListString searchedList;
			LinkedListString myList;
			std::string myArray[100];

			// Loads a list of strings from a text file
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

			std::string searchTerm = "passion";
		}
	};

	TEST_CLASS(SortingByNameTests)
	{
	public:
		TEST_METHOD(EmptyList)
		{
			LinkedListString myList;
		}

		TEST_METHOD(OneItem)
		{
			LinkedListString myList;
			std::string myString1 = "testing";
		}

		// The next tests require a list of 10 items
		TEST_METHOD(AToZ)
		{
			ifstream myFile("Test Resources/Unsorted Lists/10 Words.txt");
			LinkedListString myList;
			std::string myArray[10];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			for (int i = 0; i < 10; i++)
			{
				myList.Add(myArray[i]);
			}

		}

		TEST_METHOD(ZToA)
		{
			ifstream myFile("Test Resources/Unsorted Lists/10 Words.txt");
			LinkedListString myList;
			std::string myArray[10];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			for (int i = 0; i < 10; i++)
			{
				myList.Add(myArray[i]);
			}
		}

		TEST_METHOD(ZeroToNine)
		{
			ifstream myFile("Test Resources/Unsorted Lists/10 Numbers.txt");
			LinkedListString myList;
			std::string myArray[10];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			for (int i = 0; i < 10; i++)
			{
				myList.Add(myArray[i]);
			}
		}

		TEST_METHOD(NineToZero)
		{
			ifstream myFile("Test Resources/Unsorted Lists/10 Numbers.txt");
			LinkedListString myList;
			std::string myArray[10];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			for (int i = 0; i < 10; i++)
			{
				myList.Add(myArray[i]);
			}
		}

		TEST_METHOD(CharactersSeparatedBySpaces)
		{
			ifstream myFile("Test Resources/Unsorted Lists/10 Words Separated By Spaces.txt");
			LinkedListString myList;
			std::string myArray[10];

			// Loads a list of strings from a text file
			if (myFile.is_open())
			{
				for (int i = 0; i < 10; i++)
				{
					myFile >> myArray[i];
				}
				myFile.close();
			}

			for (int i = 0; i < 10; i++)
			{
				myList.Add(myArray[i]);
			}
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
