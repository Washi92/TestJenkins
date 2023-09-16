#include<iostream>
#include <api.h>
#include <includeLib/functions.h>

int  main() {
	std::cout << "Main application!\n";
	std::cout << "Calling API...\n";
	print();

	std::cout << "Calling third Library...\n";
	TOOLS::Student s("Shushana");
	s.talk();
	return 0;

}