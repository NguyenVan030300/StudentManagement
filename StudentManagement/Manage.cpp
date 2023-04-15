#include "Manage.h"

void Manage::Menu()
{
	int i = 123;
	while (i != 0) {
		std::cout << "Choose which to update: " << std::endl;
		std::cout << "0 to end: " << std::endl;
		std::cout << "1 to add student: " << std::endl;
		std::cout << "2 to update student info by ID: " << std::endl;
		std::cout << "3 to delete student by ID: " << std::endl;
		std::cout << "4 to search student by Name: " << std::endl;
		std::cout << "5 to sort student by GPA: " << std::endl;
		std::cout << "6 to sort student by Name: " << std::endl;
		std::cout << "7 to display list of Student: " << std::endl;
		std::cout << "8 to record list of student to csv file: " << std::endl;
		std::cin >> i;
		switch (i)
		{
		case 1:
		{
			std::cout << "add students" << std::endl;
			Student s;
			s.createStudent();
			this->addStudent(s);
		}
		break;
		case 2:
		{
			std::cout << "Enter student id" << std::endl;
			int temp;
			std::cin >> temp;
			this->updateByID(temp);
		}
		break;
		case 3:
		{
			std::cout << "Enter student id" << std::endl;
			int temp;
			std::cin >> temp;
			this->deleteByID(temp);
		}
		break;
		case 4:
		{
			std::cout << "Enter student name:" << std::endl;
			std::string temp;
			std::cin >> temp;
			this->searchStudentByName(temp);
		}
		break;
		case 5:
		{
			std::cout << "Sort student by GPA" << std::endl;
			this->sortStudentByGPA();
		}
		break;
		case 6:
		{
			std::cout << "Sort student by Name" << std::endl;
			this->sortStudentByName();
		}
		break;
		case 7:
		{
			std::cout << "List of student" << std::endl;
			this->printListOfStudent();
		}
		break;
		case 8:
		{
			std::cout << "Enter the file name" << std::endl;
			std::string temp;
			std::cin >> temp;
			this->recordStudentToCSV(temp);
		}
		break;
		default:
			break;
		}
	}
}

void Manage::updateByID(int id)
{
	for (auto& values : this->listOfStudent) {
		if (values.getID() == id) {
			values.updateInfomation();
			return;
		}
	}
	std::cout << "The current ID does not exist" << std::endl;
}

void Manage::deleteByID(int id)
{
	listOfStudent.remove_if([id](Student& s) {return s.getID() == id; });
}

void Manage::searchStudentByName(std::string name)
{
	for (auto& values : this->listOfStudent) {
		if (values.getName() == name) {
			values.printStudent();
			return;
		}
	}
}

void Manage::sortStudentByGPA()
{
	listOfStudent.sort([](Student& student1, Student& student2) {
		if (student1.getGPA() == student2.getGPA()) {
			return student1 < student2;
		}
		return student1.getGPA() < student2.getGPA();
		});
}

void Manage::sortStudentByName()
{
	listOfStudent.sort([](Student& student1, Student& student2) {
		if (student1.getName() == student2.getName()) {
			return student1 < student2;
		}
		return student1.getName() < student2.getName();
		});
}

void Manage::addStudent(Student student)
{
	this->listOfStudent.push_back(student);
}

void Manage::readCSVFile(std::string path)
{
	std::fstream file;
	file.open(path, std::ios::in);
	std::vector<std::string> row;
	std::string line, word;

	if (file.is_open()) {
		while (getline(file, line)) {
			row.clear();
			std::stringstream str(line);
			while (getline(str, word, ',')) {
				row.push_back(word);
			}
			this->content.push_back(row);
		}
	}
	else {
		std::cout << "Could not open file" << std::endl;
		return;
	}
}

void Manage::recordStudentToCSV(std::string nameOffile)
{
	std::fstream file;
	file.open(nameOffile, std::ios::out);
	for (auto& values : this->listOfStudent) {
		file << values.getID() << ", "
			<< values.getName() << ", "
			<< values.getGender() << ", "
			<< values.getAge() << ", "
			<< values.getMath() << ", "
			<< values.getPhysic() << ", "
			<< values.getChemistry() << ", "
			<< values.getGPA() << ", "
			<< values.GetAcademic_perform()
			<< std::endl;
	}
}


void Manage::printContent()
{
	for (auto& value : this->content)
	{
		int i = 0;
		for (auto& value2 : value)
		{
			std::cout << "Position: " << i << " " << value2 << std::endl;
			++i;
		}
		std::cout << "\n";
	}
}

void Manage::printListOfStudent()
{
	for (auto& students : this->listOfStudent) {
		students.printStudent();
		std::cout << std::endl;
	}
}
