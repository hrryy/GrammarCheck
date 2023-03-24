//student.cpp to implement your classes
#include "student.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <cctype> 


Student :: Student()
{

}
//get functions for Domestic Students 
string Student ::get_studentName()
{
    return this->FirstName;
} 
string Student ::get_studentLastName()
{
    return this->LastName; 
} 

float Student ::get_student_CGPA()
{
    return this->CGPA; 
} 
int Student ::get_student_ResearchScore()
{
    return this->researchScore;
} 
int Student :: get_studentID()
{
    return this->ID; 
}
//set functions for Domestic Students 
void Student ::set_studentName(string Name)
{
    this->FirstName= Name;
} 
void Student ::set_studentLastName(string lastname)
{
    this->LastName= lastname; 
} 

void Student ::set_student_CGPA(float cgpa)
{
    this->CGPA=cgpa;
} 
void Student ::set_student_ResearchScore(int Score)
{
    this->researchScore= Score;
}

//setting the applicant
void Student ::set_Applicant(string Name, string lastName, float cgpa, int score)
{
    this->FirstName= Name; 
    this->LastName=lastName; 
    this->CGPA= cgpa; 
    this->researchScore=score; 
}
void Student ::set_studentID(int stuID)
{
    ID= stuID+ 20220000; 
}

//compares two objects by the criteria 
const int compareCGPA(const Student & stu1, const Student & stu2) 
{
    // return 0: student1 after student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger cgpas come sooner
    if(stu1.CGPA == stu2.CGPA)
    {
        return 2;
    }

    else if (stu1.CGPA< stu2.CGPA) 
    { 
        return 1; // student 2 comes before student 2
    }

    
    else if (stu2.CGPA < stu1.CGPA)
    {
        return 0; // student 1 comes before student 2
    }

}

const int compareResearchScore(const Student & stu1, const Student & stu2) 
{
    // return 0: student1 before student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger scores come earlier  
    if(stu1.researchScore == stu2.researchScore)
    {
        return 2;
    }

    else if (stu1.researchScore < stu2.researchScore) 
    { 
        return 1; // student 2 comes before student 2
    }

    
    else if (stu2.researchScore < stu1.researchScore)
    {
        return 0; // student 1 comes before student 2
    }

}
const int compareFirstName( Student stu1,  Student stu2)
{
    // return 0: student1 after student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger alphabets comes later
    if(convert(stu1.FirstName )== convert(stu2.FirstName))
    {
        return 2;
    }

    else if (convert(stu1.FirstName) <convert (stu2.FirstName)) 
    { 
        return 1; // student 2 comes after student 2
    }

    
    else if (convert(stu2.FirstName)< convert(stu1.FirstName))
    {
        return 0; // student 1 comes after student 2
    }

} 
const int compareLastName( Student  stu1,  Student  stu2)
{
    // return 0: student1 after  student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger alphabets comes later
    if(convert(stu1.get_studentLastName()) == convert(stu2.get_studentLastName()))
    {
        return 2;
    }

    else if (convert (stu1.get_studentLastName())  < convert(stu2.get_studentLastName()) )
    { 
        return 1; // student 2 comes after student 2
    }

    
    else if (convert (stu2.get_studentLastName())< convert(stu1.get_studentLastName()))
    {
        return 0; // student 1 comes after student 2
    }

}
ostream &operator <<(ostream&  outs, Student& stu)
{   
    outs << std::left << setw(18) << stu.get_studentName() <<std::fixed << std::left << setw(18) << stu.get_studentLastName() << std::left<< setw(14) ;
    outs << setw(12) <<std::fixed << setprecision(2) << stu.get_student_CGPA() <<std::fixed << std::left<<setw(18) << stu.get_student_ResearchScore() <<endl;
}


string convert(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;

}