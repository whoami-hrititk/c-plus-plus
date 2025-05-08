#include <iostream>
#include <string>
#include <vector>
#include <map>

int A = 10, B = 8, C = 6, D = 4, E = 2, F = 0;


class Student{
private:
	std::string name;
	int total_course;
	int rollNo;
	std::map<std::string, char> Courses;
	float cgpa = 0;

public:

	void updateCgpa(int total){
		for(auto c:Courses){
			switch (c.second){
			case 'A':
				cgpa += 10;
				break;
			case 'B':
				cgpa += 8;
				break;
			case 'C':
				cgpa += 6;
				break;
			case 'D':
				cgpa += 4;
				break;
			case 'E':
				cgpa += 2;
				break;
			case 'F':
				cgpa += 0;
				break;
			default:
				break;
			}
		}
		cgpa = cgpa/total;
		return;
	}

	Student(std::string name, int total, int rollNo): name(name), total_course(total), rollNo(rollNo) {
		for(int i = 0; i < total; i++){
			std::string subject;
			char grade;
			std::cout<<"Enter your subject "<<i+1<<" name: ";
			std::cin>>subject;
			std::cout<<"Enter "<<subject<<"'s Garde (A-F): ";
			std::cin>>grade;
			Courses[subject] = grade;
		}
		updateCgpa(total);
		std::cout<<"Data Updated Successfully!"<<std::endl;
	}

	void printData(){
		std::cout<<"Student: "<<name<<std::endl;
		std::cout<<"Total Courses taken: "<<total_course<<std::endl;
		for(auto c:Courses){
			std::cout<<"Subject: "<<c.first<<" &"<<" Grade: "<<c.second<<std::endl;
		}
		std::cout<<"CGPA: "<<cgpa;
		return;
	}

	std::string showName(){
		return name;
	}
	void updateName(std::string name){
		this->name = name;
		std::cout<<"Name updated Successfully!"<<std::endl;
		return;
	}

	int showRoll(){
		return rollNo;
	}

	void updateRoll(int rollNo){
		this->rollNo = rollNo;
		std::cout<<"Roll No updated Successfully!"<<std::endl;
		return;
	}
};

std::vector<Student> stu;

bool isStudent(int roll){
	for(auto s : stu){
		if(s.showRoll() == roll) return true;
	}
	return false;
}

void updateData(int roll, std::string new_name){
	for(auto &s : stu){
		if(roll = s.showRoll()){
			s.updateName(new_name);
			break; 
		}
	}
	return;
}

void updateData(int roll, int new_roll){
	for(auto &s : stu){
		if(roll = s.showRoll()){
			s.updateRoll(new_roll);
			break; 
		}
	}
	return;
}

void deleteStudent(){

}

void addStudent(){
	std::cout<<"Enter Student's name: ";
	std::string name;
	int roll;
	std::cout<<"Enter his roll number: ";
	std::cin>>roll;
	int total;
	getline(std::cin, name);
	std::cout<<"Enter his total courses/subjects: ";
	std::cin>>total;
	Student s(name, total, roll);
	stu.push_back(s);
	return;
}

void editStudent(){
	int current_roll;
	std::cout<<"Enter Studen's roll no: ";
	std::cin>>current_roll;
	if(isStudent(current_roll)){
		std::string choice;
		std::cout<<"Enter in words to change the data (eg. name | rollno, etc: ";
		std::cin>>choice;
		std::string new_name;
		int new_roll;
		if((choice == "name") ||(choice == "Name") ||(choice == "NAME")){
			std::cout<<"Enter new name for the student: ";
			getline(std::cin, new_name);
			updateData(current_roll, new_name);
		}else if((choice == "rollNo") || (choice == "ROLLNO" ) || (choice == "RollNo")|| (choice == "roll" ) || (choice == "Roll")){
			std::cout<<"Enter student's new roll number: ";
			std::cin>>new_roll;
			updateData(current_roll, new_roll);
		}else if((choice == "courses") || (choice == "course")|| (choice == "total") || (choice == "Course") || (choice == "Courses") ){
			std::cout<<"To change the course you need to delet this Existing student and create new student with the right details."<<std::endl;
		}else
			std::cout<<"Please enter choice correctly! Going Back.."<<std::endl;
		
	}else{
		std::cout<<"No student found with rollno "<<current_roll<<std::endl;
	}
	return;
}

int main(){
	std::cout<<"Welcome to CGPA Database):"<<std::endl;
	while(true){
		int choice;
		std::cout<<"Select an option:-"<<std::endl
				 <<"1-> Update new student"<<std::endl
				 <<"2-> Edit Existing Student data"<<std::endl
				 <<"3-> Remove Existing Student"<<std::endl
				 <<"Choice: ";
		std::cin>>choice;
		std::cin.ignore();
		if (choice == 0){
			std::cout<<"Exiting.."<<std::endl;
			return 0;
		}
		if (choice == 1){
			addStudent();
		}else if(choice == 2){
			editStudent();
		}else if(choice == 3){
			deleteStudent();
		}else std::cout<<"Please select a valid option."<<std::endl;
	}
	return 0;
}
