#include<iostream>
#include <api.h>
#include <includeLib/functions.h>

void main() {
	std::cout << "Main application!\n";
	std::cout << "Calling API...\n";
	print();

	std::cout << "Calling third Library...\n";
	TOOLS::Student s("Shushana");
	s.talk();


}