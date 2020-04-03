#include <iostream>
#include "operator.h"
#include "sum.h"
#include "differ.h"
#include "multi.h"
#include "ratio.h"
#include "remain.h"
#include "big_divider.h"
#include "multiple.h"
#include <vector>
#include <libutils/io.h>
#include <time.h>
#include <algorithm>
#include <memory>

void mainMenu() noexcept {
	std::cout << "==================================" << std::endl;
	std::cout << "            MAIN MENU             " << std::endl;
	std::cout << "==================================" << std::endl << std::endl;
	std::cout << "1. Create object and paste in collection" << std::endl;
	std::cout << "2. Create some objects and paste in end of collection" << std::endl;
	std::cout << "3. Remove object from collection by index" << std::endl;
	std::cout << "4. Clear collection" << std::endl;
	std::cout << "5. Equal two objects by indexes" << std::endl;
	std::cout << "6. Print collection" << std::endl;
	std::cout << "7. Calculate minimal result" << std::endl;
	std::cout << "0. Exit" << std::endl << std::endl;
}

void paste_element(std::vector<std::unique_ptr<Operator>>& collection, const int& index) {

	// Using iterator for paste element in collection by this iterator
	auto p = collection.begin();

	// Counter for cycles. Will increment while "i != index"
	unsigned int i = 0;

	int lhs, rhs;

	std::cout << "How do you want to create an operation?" << std::endl << std::endl << "1. Create random operation with random parameters" << std::endl << "2. Choose type of operation and insert parameters by yourself" << std::endl << std::endl;
	switch (utils::read_int("Your choice: ", 1, 2)) {
	case 1: {
		system("cls");
		std::cout << "Please wait, your operation is creating..." << std::endl << std::endl;
		switch (rand() % 7)
		{

		case 1: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Sum>(Sum(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 2: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Differ>(Differ(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 3: {
			system("cls");


			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Multi>(Multi(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());
			break;
		}
		case 4: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Ratio>(Ratio(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 5: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Remain>(Remain(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 6: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<bigDivider>(bigDivider(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 7: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Multiple>(Multiple(rand(), rand())));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 0: {
			break;
		}

		}
		break;
	}
	case 2: {
		system("cls");
		lhs = utils::read_int("Enter first operand: ", INT_MIN, INT_MAX);
		rhs = utils::read_int("Enter second operand: ", INT_MIN, INT_MAX);

		// Choose type of function
		switch (utils::read_int("\nWhat operation do you want to make?\n1 - Sum\n2 - Differ\n3 - Multi\n4 - Ratio\n5 - Find remain\n6 - Find the biggest common divider\n7 - Find the least common multiple\n\n0 - Cancel\n\nChoose: ", 0, 7))
		{

		case 1: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Sum>(Sum(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 2: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Differ>(Differ(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 3: {
			system("cls");


			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Multi>(Multi(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());
			break;
		}
		case 4: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Ratio>(Ratio(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 5: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Remain>(Remain(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 6: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<bigDivider>(bigDivider(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 7: {
			system("cls");

			do {
				if (i == index) {
					collection.insert(p, std::make_unique<Multiple>(Multiple(lhs, rhs)));
					break;
				}
				++i;
				++p;
			} while (p != collection.end());

			break;
		}
		case 0: {
			break;
		}

		}
		break;
	}
	}


}

void creatingElements(std::vector<std::unique_ptr<Operator>>& collection, const int& count) {

	// Choose type of function
	std::cout << "How do you want to create new operators?" << std::endl << "1. Create random operations with random elements" << std::endl << "2. Create elements by yourself" << std::endl;

	switch (utils::read_int("Your choice: ", 1, 2)) {
	case 1: {
		system("cls");
		std::cout << "ACTION: Please, wait. Your objects is creating. It can takes some time..." << std::endl;
		for (auto i = 0; i < count; ++i) {
			switch (rand() % 7)
			{

			case 0: {

				collection.push_back(std::make_unique<Sum>(Sum(rand(), rand())));

				break;
			}
			case 1: {

				collection.push_back(std::make_unique<Differ>(Differ(rand(), rand())));

				break;
			}
			case 2: {

				collection.push_back(std::make_unique<Multi>(Multi(rand(), rand())));

				break;
			}
			case 3: {

				collection.push_back(std::make_unique<Ratio>(Ratio(rand(), rand())));

				break;
			}
			case 4: {

				collection.push_back(std::make_unique<Remain>(Remain(rand(), rand())));

				break;
			}
			case 5: {

				collection.push_back(std::make_unique<bigDivider>(bigDivider(rand(), rand())));

				break;
			}
			case 6: {

				collection.push_back(std::make_unique<Multiple>(Multiple(rand(), rand())));

				break;
			}

			}
		}
		break;
	}
	case 2: {
		system("cls");
		int lhs;
		int rhs;
		for (auto i = 0; i < count; ++i) {
			system("cls");
			std::cout << "Creating operation #" << i + 1 << std::endl << std::endl;
			lhs = utils::read_int("Enter first operand: ", INT_MIN, INT_MAX);
			rhs = utils::read_int("Enter second operand: ", INT_MIN, INT_MAX);
			system("cls");
			std::cout << "Creating operation #" << i + 1 << std::endl << std::endl;
			std::cout << "1. Sum" << std::endl << "2. Differ" << std::endl << "3. Multi" << std::endl << "4. Ratio" << std::endl << "5. Find remain by dividing" << std::endl << "6. Find the biggest common divider" << std::endl << "7. Find the least common multiple" << std::endl << std::endl;
			std::cout << "Your operands: " << lhs << ", " << rhs << std::endl << std::endl;
			switch (utils::read_int("Which type of operation do you want to do with your operands?\n Your choice: ", 1, 7))
			{

			case 1: {

				collection.push_back(std::make_unique<Sum>(Sum(lhs, rhs)));

				break;
			}
			case 2: {

				collection.push_back(std::make_unique<Differ>(Differ(lhs, rhs)));

				break;
			}
			case 3: {

				collection.push_back(std::make_unique<Multi>(Multi(lhs, rhs)));

				break;
			}
			case 4: {

				collection.push_back(std::make_unique<Ratio>(Ratio(lhs, rhs)));

				break;
			}
			case 5: {

				collection.push_back(std::make_unique<Remain>(Remain(lhs, rhs)));

				break;
			}
			case 6: {

				collection.push_back(std::make_unique<bigDivider>(bigDivider(lhs, rhs)));

				break;
			}
			case 7: {

				collection.push_back(std::make_unique<Multiple>(Multiple(lhs, rhs)));

				break;
			}

			}
		}
		break;
	}
	}
}

void equal_elements(const std::vector<std::unique_ptr<Operator>>& collection, const int& index1, const int& index2) {

	// Compare by indexes
	if (collection.at(index1).get()->equals(*(collection.at(index2).get())))
		std::cout << "RESULT: Objects are equals" << std::endl;
	else
		std::cout << "RESULT: Objects are not equals" << std::endl;
}

void remove_element(std::vector<std::unique_ptr<Operator>>& collection, const int& index) {

	// Counter for cycle. Will be increment while "i != index"
	unsigned int i = 0;

	for (auto p = collection.begin(); p != collection.end(); ++p, ++i)
	{
		if (i == index) {
			collection.erase(p);
			break;
		}
	}
}

void print_collection(const std::vector<std::unique_ptr<Operator>>& collection, const int& maxPrintElement) noexcept {

	// If there more function than 10 in collection
	bool usingDots = false;

	// Count of elements for printing
	size_t printCount = collection.size();

	// If collection bigger than max count of printing element
	if (collection.size() > maxPrintElement)
	{
		printCount = maxPrintElement;
		usingDots = true;
	}

	// Printing
	for (size_t i = 0; i < printCount; ++i) {
		std::cout << "[" << i << "] ";
		collection[i].get()->print(std::cout);
		std::cout << std::endl;
	}

	if (usingDots)
		std::cout << "..." << std::endl;
}

void searchMin(const std::vector<std::unique_ptr<Operator>>& collection) {

	// Set min of values of derivative functions
	double min = collection.at(0).get()->getResult();

	// Search "min"
	for (auto i = 0; i < collection.size(); ++i) {
		if (collection.at(i).get()->getResult() < min)
			min = collection.at(i).get()->getResult();
	}

	// Search first min
	for (auto i = 0; i < collection.size(); ++i) {
		if (collection.at(i).get()->getResult() == min)
		{
			std::cout << "RESULT: " << collection.at(i).get()->getResult() << std::endl;

			std::cout << "RESULT(string format): ";

			collection.at(i).get()->print(std::cout);

			std::cout << "; ";

			break;
		}
	}
	std::cout << std::endl << std::endl << "Press Enter to continue...";
	getchar();
	system("cls");
}

struct Comparator {
	const int lhs;
	const int rhs;

	Comparator(int lhs, int rhs) :lhs(lhs), rhs(rhs) {	}

	bool operator()(const std::unique_ptr<Operator>& lhsOp, const std::unique_ptr<Operator>& rhsOp, ) {
		return lhsOp->getResult(lhs, rhs) < rhsOp->getResult(lhs, rhs);
	}
}

void searchMinStd(const std::vector<std::unique_ptr<Operator>>& collection) {

	Comparator c(3, 5);
	auto r = std::min_element(collection.begin(), collection.end(), c);

	std::cout << (r-collection.begin());
	collection.at(position).get()->print(std::cout);

	//std::cout << "; " << results[position] << std::endl;
	std::cout << std::endl << std::endl << "Press Enter to continue...";
	getchar();
	system("cls");
}

int main() {
	// ==============================================
	//					  OPTIONS
	// ==============================================

	// Create collection with uniquePtr's
	std::vector<std::unique_ptr<Operator>> collection;

	// Max count of objects
	unsigned int maxCountObjects = 100;

	// Max printed elements in console
	size_t maxPrintElement = 10;

	// ==============================================
	//					 PROGRAM
	// ==============================================

	while (true)
	{
		// In this block memory not allocating
		try {
			//system("cls");
			// Printing main menu
			mainMenu();

			switch (utils::read_int("Choose action: ", 0, 10))
			{

			case 1: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty\n\nNOTE: You must create collection for pasting by index";

				print_collection(collection, static_cast<int>(maxPrintElement));

				// Set index for paste element
				std::cout << "----------------------------" << std::endl;
				unsigned int index = utils::read_int("Choose index for pasting: ", 0, static_cast<int>(collection.size() - 1));
				std::cout << "----------------------------" << std::endl;

				// Algorithm
				paste_element(collection, index);

				std::cout << "----------------------------" << std::endl;
				std::cout << "SYSTEM: Element pasted!" << std::endl;
				std::cout << "----------------------------" << std::endl;

				break;
			}
			case 2: {
				system("cls");

				// Set count of objects which will be created
				std::cout << "----------------------------" << std::endl;
				unsigned int count = utils::read_int("Enter count of objects: ", 0, maxCountObjects);
				std::cout << "----------------------------" << std::endl;

				// Algorithm
				creatingElements(collection, count);

				std::cout << "----------------------------" << std::endl;
				std::cout << "SYSTEM: Element created!" << std::endl;
				std::cout << "----------------------------" << std::endl;

				break;
			}
			case 3: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty";

				print_collection(collection, static_cast<int>(maxPrintElement));

				std::cout << "----------------------------" << std::endl;
				unsigned int index = utils::read_int("Enter index for removing: ", 0, static_cast<int>(collection.size()));
				std::cout << "----------------------------" << std::endl;

				// Algorithm
				remove_element(collection, index);

				std::cout << "==================================" << std::endl;
				std::cout << "SYSTEM: Element removed!" << std::endl;
				std::cout << "==================================" << std::endl;

				break;
			}
			case 4: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty";

				// Clear collection
				collection.clear();

				std::cout << "----------------------------" << std::endl;
				std::cout << "SYSTEM: Collection cleared" << std::endl;
				std::cout << "----------------------------" << std::endl;

				break;
			}
			case 5: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty";

				// Collection must consists two or more elements
				if (collection.size() < 2)
					throw "ERROR: There only one object in the collection";

				print_collection(collection, static_cast<int>(maxPrintElement));

				// Get indexes of objects in collection for compare
				std::cout << "----------------------------" << std::endl;
				unsigned int index1 = utils::read_int("Enter first index: ", 0, static_cast<int>(collection.size() - 1));

				unsigned int index2 = utils::read_int("Enter second index: ", 0, static_cast<int>(collection.size() - 1));
				std::cout << "----------------------------" << std::endl;

				// Algorithm
				equal_elements(collection, index1, index2);

				break;
			}
			case 6: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty";

				// Algorithm
				print_collection(collection, static_cast<int>(maxPrintElement));

				break;
			}
			case 7: {
				system("cls");

				// Collection must be exist
				if (collection.empty())
					throw "ERROR: Collection is empty";

				print_collection(collection, static_cast<int>(maxPrintElement));

				// For task. Using my algorithm and algorithm from <algorithm> library
				switch (utils::read_int("Choose algorithm: 1 - Student's algorithm, 2 - Standart algorithm: ", 1, 2))
				{

				case 1: {
					searchMin(collection);
					break;
				}
				case 2: {
					searchMinStd(collection);
					break;
				}

				}

				break;
			}
			case 0: {
				return 0;
			}

			}

		}
		// Print message about error
		catch (const char* errorMsg) {
			std::cout << "----------------------------" << std::endl;
			std::cerr << errorMsg << std::endl;
			std::cout << "----------------------------" << std::endl << std::endl;
		}
	}
}

