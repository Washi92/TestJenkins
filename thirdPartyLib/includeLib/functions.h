#pragma once
#include<string>
#include<iostream>

#define SWITCH_FOR_MY_APP 0


namespace TOOLS
{
	struct Clothes
	{
		std::string color;
		double size;
	};

	class Student {
	public:
		Student(std::string n): name(n), id(10){}
		std::string name;
		unsigned int id;
		Clothes clothes;

		void talk() {
			std::cout << "Hello my name is "<<name<<std::endl;
		}
		Student getStudent() { return *this; }
	};
}