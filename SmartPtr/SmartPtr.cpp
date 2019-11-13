// SmartPtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

using namespace std;

class Entity
{
public:

	Entity()
	{
		cout << "Created entity!" << endl;
	}

	~Entity()
	{
		cout << "Destroyed entity!" << endl;
	}

	void display()
	{
		cout << "Testing!!" << endl;
	}
};

std::weak_ptr<int> gw;

void observe()
{
	std::cout << "use_count == " << gw.use_count() << ": ";
	if (!gw.expired()) { // Has to be copied into a shared_ptr before usage
		//std::cout << *spt << "\n";
		cout << "Not expired \n";
	}
	else {
		std::cout << "gw is expired\n";
	}
}

int main()
{	
	// Unique_ptr
	//{
	//	unique_ptr<Entity> u_ptr = make_unique<Entity>();
	//	u_ptr->display();
	//}

	// shared_ptr
	//{
	//	shared_ptr<Entity> s_ptr1;
	//	{
	//		shared_ptr<Entity> s_ptr = make_shared<Entity>();
	//		s_ptr1 = s_ptr;
	//	}
	//}

	// weak_ptr
	{
		{
			auto sp = std::make_shared<int>(42);
			gw = sp;
			observe();
		}
		observe();

	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
