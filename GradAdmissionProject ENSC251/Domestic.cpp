//header file domestic.cpp to declare DomesticStudent classes
#include "Domestic.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

//left blank on purpose 
DomesticStudent:: DomesticStudent()
{

}
    

//get functions for Domestic Students 
string DomesticStudent:: get_province()
{
    return this->province;
} 


//set functions for Domestic Students 
void DomesticStudent::set_province(string Province)
{
    province= Province;
} 
            
// output
// output Domestic Student
ostream &operator <<(ostream&  outs, DomesticStudent& stu) 
{

    outs << std::left << setw(18) << std::left << setw(18) << stu.get_studentName() <<std::fixed << std::left << setw(18) << stu.get_studentLastName() << std::left<< setw(14) << stu.get_province();
    outs << std::left << setw(18) <<std::fixed << setprecision(2) << stu.get_student_CGPA() <<std::fixed << std::left << stu.get_student_ResearchScore()<<endl;
    return outs;
}

 
int compareProv( DomesticStudent stu1, DomesticStudent stu2)
{
    // return 0: student1 after student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger alphabets come later 
    if((convert_province(stu1.get_province())) == (convert_province(stu2.get_province())))
    {
        return 2;
    }

    else if (convert_province(stu1.get_province()) < convert_province(stu2.get_province())) 
    { 
        return 1; // student 2 comes sfter student 2
    }

    
    else if (convert_province(stu1.get_province()) < convert_province(stu2.get_province()))
    {
        return 0; // student 1 comes sfter student 2
    }
    return 0;
}

string convert_province(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;

}