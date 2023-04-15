#include "student.h"

int Student::_idProvider = 0;

void Student::updateInfomation()
{
	int i = 123;
	int flag = 0;
	while (i != 0) {
		std::cout << "Choose which to update: " << std::endl;
		std::cout << "0 to end update process: " << std::endl;
		std::cout << "1 to update name: " << std::endl;
		std::cout << "2 to update Gender: " << std::endl;
		std::cout << "3 to update age: " << std::endl;
		std::cout << "4 to update math: " << std::endl;
		std::cout << "5 to update physic: " << std::endl;
		std::cout << "6 to update chemistry: " << std::endl;
		std::cin >> i;
		switch (i)
		{
		case 1:
		{
			std::string temp;
			std::cout << "Enter name" << std::endl;
			std::cin >> temp;
			this->setName(temp);
		}
			break;
		case 2:
		{
			std::string temp;
			std::cout << "Enter gender" << std::endl;
			std::cin >> temp;
			this->setGender(temp);
		}
		break;
		case 3:
		{
			int temp;
			std::cout << "Enter age" << std::endl;
			std::cin >> temp;
			this->setAge(temp);
		}
		break;
		case 4:
		{
			float temp;
			std::cout << "Enter math score" << std::endl;
			std::cin >> temp;
			this->setMath(temp);
			++flag;
		}
		break;
		case 5:
		{
			float temp;
			std::cout << "Enter physic score" << std::endl;
			std::cin >> temp;
			this->setPhysic(temp);
			++flag;
		}
		break;
		case 6:
		{
			float temp;
			std::cout << "Enter chemistry score" << std::endl;
			std::cin >> temp;
			this->setChemistry(temp);
			++flag;
		}
		break;
		default:
			break;
		}
	}
	if (flag != 0) {
		this->GPA = calculateGPA();
		this->updateAcademic_perform();
	}
}

void Student::createStudent()
{
	std::cout << "Enter name: ";
	std::cin >> this->name;
	std::cout << std::endl;
	std::cout << "Enter gender: ";
	std::cin >> this->Gender;
	std::cout << std::endl;
	std::cout << "Enter Age: ";
	std::cin >> this->age;
	std::cout << std::endl;
	std::cout << "Enter math score: ";
	std::cin >> this->math;
	std::cout << std::endl;
	std::cout << "Enter physic score: ";
	std::cin >> this->physic;
	std::cout << std::endl;
	std::cout << "Enter chemistry score: ";
	std::cin >> this->chemistry;
	std::cout << std::endl;
	this->GPA = calculateGPA();
	this->updateAcademic_perform();
}

void Student::printStudent()
{
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Gender: " << this->Gender << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Math: " << this->math << std::endl;
	std::cout << "Physic: " << this->physic << std::endl;
	std::cout << "Chemistry: " << this->chemistry << std::endl;
	std::cout << "GPA: " << this->GPA << std::endl;
	std::cout << "Academic performance: " << this->academic_perform << std::endl;
}
