#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

#define STUDENTS_COUNT 10

class Student {
	public:
		string studentNo;
		string studentSurname;
		string studentName;
		bool studentStatus;
			
		void setStudentNo(string studentNo) {
			this->studentNo = studentNo;
		}
		string getStudentNo() {	
			return this->studentNo;
		}
		
		void setStudentSurname(string studentSurname) {
			this->studentSurname = studentSurname;
		}
		string getStudentSurname() {	
			return this->studentSurname;
		}
		
		void setStudentName(string studentName) {
			this->studentName = studentName;
		}
		string getStudentName() {	
			return this->studentName;
		}
		
		void setStudentStatus(bool studentStatus) {
			this->studentStatus = studentStatus;
		}
		bool getStudentStatus() {	
			return this->studentStatus;
		}
};

string getRandomStudentNumber() {
	ostringstream ss;
	int randomNumber = rand() % 100 + 42000;
	ss << randomNumber;
	return ss.str();
}
string getRandomStudentSurname() {
	ostringstream ss;
	string Surnames[]= {"Nowak","Kowalski","Wiœniewski","Wójcik","Kolwaczyk","Kamiñski","Lewandowski","Zieliñski","Szymañski","WoŸniak"};
	int randomSurname = rand() % sizeof(string);
 	ss << Surnames[randomSurname];
	return ss.str();
}
string getRandomStudentName() {
	ostringstream ss;
	string Names[]= {"Antoni","Jan","Aleksander","Franciszek","Nikodem","Jakub","Leon","Stanis³aw","Miko³aj","Szymon"};
	int randomName = rand() % sizeof(string);
 	ss << Names[randomName];
	return ss.str();
}
bool getRandomStudentStatus(){
	int randomStatus = rand() % 2;
	if(randomStatus == 1){
		return true;
	}
	else{
		return false;
	}	
}

int main() {
	setlocale(LC_CTYPE, "Polish");
	vector<Student> students;
	srand(time(0));
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		Student student;
		student.setStudentNo(getRandomStudentNumber());
		student.setStudentSurname(getRandomStudentSurname());
		student.setStudentName(getRandomStudentName());
		student.setStudentStatus(getRandomStudentStatus());
		students.push_back(student);
	}
	
	cout  << "Students group have been filled." << endl << endl;
	
	for(int i = 0; i < students.size(); i++) {
		Student student = students.at(i);
		if(student.getStudentStatus() == true){
		cout << student.getStudentSurname() <<" "<< student.getStudentName() <<" ("<<student.getStudentNo()<< ")"<< endl;
	 }
	}
	
	return 0;
}
