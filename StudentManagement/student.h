#pragma once
#include <iostream>
#include <string>
#include <list>
class Student
{
private:
	std::string name;
	std::string academic_perform;
	std::string Gender;
	float math;
	float physic;
	float chemistry;
	float GPA;
	int age;
	int id;
public:
	static int _idProvider;
	Student()
		: name(" "), academic_perform(" "), Gender("F"), math(0), physic(0), chemistry(0), GPA(0), age(0), id(++_idProvider)
	{

	}
	Student(std::string _name, std::string _academic_perform, std::string gender, float _math, float _physic, float _chemistry, float _GPA, int _age)
		:name(_name), academic_perform(_academic_perform), Gender(gender), math(_math), physic(_physic), chemistry(_chemistry), GPA(_GPA), age(_age), id(++_idProvider)
	{
	
	}
	void updateInfomation();
	void createStudent();
	float calculateGPA() {
		return (this->math + this->physic + this->chemistry) / (3);
	}

	float getGPA() {
		return this->GPA;
	}

	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {
		return this->name;
	}

	void updateAcademic_perform() {
		if (this->GPA < 5) {
			this->academic_perform = "Weak";
			return;
		}
		if (this->GPA < 6.5) {
			this->academic_perform = "Average";
			return;
		}
		if (this->GPA < 8) {
			this->academic_perform = "Fair";
			return;
		}
		else {
			this->academic_perform = "Excellent";
		}
	}
	std::string GetAcademic_perform() {
		return this->academic_perform;
	}

	void setGender(std::string Gender) {
		this->Gender = Gender;
	}
	std::string getGender() {
		return this->Gender;
	}

	int getID() {
		return this->id;
	}

	float getMath() {
		return this->math;
	}
	void setMath(float math) {
		this->math = math;
	}

	float getPhysic() {
		return this->physic;
	}
	void setPhysic(float physic) {
		this->physic = physic;
	}

	float getChemistry() {
		return this->chemistry;
	}
	void setChemistry(float chemistry) {
		this->chemistry = chemistry;
	}

	int getAge() {
		return this->age;
	}
	void setAge(int age) {
		this->age = age;
	}
	bool operator <(const Student& student) const
	{
		return id < student.id;
	}
	void printStudent();
	~Student() {
	
	}
};

