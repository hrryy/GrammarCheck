//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <vector>
#include <iomanip>
#include <cctype> 


#ifndef student_hpp
#define student_hpp

class Student
{
public:

Student();
//get functions for Domestic Students 
string get_studentName(); 
string get_studentLastName(); 
float get_student_CGPA(); 
int get_student_ResearchScore(); 
int get_studentID();

//set functions for Domestic Students 
void set_studentName(string Name ); 
void set_studentLastName(string LastName); 
void set_student_CGPA(float CGPA); 
void set_student_ResearchScore(int Score); 
void set_studentID(int stuID);

//setting the applicant 
void set_Applicant(string Name, string lastName, float cgpa, int score);

//friend functions to compare objects by some criteria
friend const int compareCGPA(const Student & student_1, const Student & student_2); 
friend const int compareResearchScore(const Student & student_1, const Student & student_2); 
friend const int compareFirstName( Student  student_1, Student student_2); 
friend const int compareLastName(  Student  stu1, Student stu2);
friend ostream &operator <<(ostream&  outs, Student& stu);
//private variables 
private:
string FirstName; 
string LastName;
float CGPA; 
int researchScore; 
int ID;


};
string convert(string str);
#endif