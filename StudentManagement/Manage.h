#pragma once
#include "student.h"
#include <fstream>
#include <sstream>
#include <vector>
class Manage
{
private:
	std::vector<std::vector<std::string>> content;
	std::list<Student> listOfStudent;
public:
	Manage() {}
	Manage(std::string path) {
		this->readCSVFile(path);
		for (int i = 1;i < this->content.size();i++)
		{
			std::string name = this->content[i][1];
			std::string academic_perform = this->content[i][8];
			std::string Gender = this->content[i][2];
			float math = std::stof(this->content[i][4]);
			float physic = std::stof(this->content[i][5]);
			float chemistry = std::stof(this->content[i][6]);
			float GPA = std::stof(this->content[i][7]);
			int age = std::stoi(this->content[i][3]);
			Student student(name,academic_perform,Gender,math,physic,chemistry,GPA,age);
			listOfStudent.push_back(student);
		}
	}
	void Menu();
	void updateByID(int id);
	void deleteByID(int id);
	void searchStudentByName(std::string name);
	void sortStudentByGPA();
	void sortStudentByName();
	void addStudent(Student student);
	void readCSVFile(std::string path);
	void recordStudentToCSV(std::string nameOffile);
	void printContent();
	void printListOfStudent();
	~Manage() {
	}
};

