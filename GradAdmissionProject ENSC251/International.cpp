//header file international.cpp to declare InternationalStudent classes
#include "International.hpp"
#include "TOFEL.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>


//default constructor 
//left blank on purpose
InternationalStudent::InternationalStudent()
{

} 

// setters
void InternationalStudent::set_Country(string count)
{
    this-> country= count; 
}

// getters
// returns international studen't country
std:: string InternationalStudent::get_Country()
{
    return this->country; 
}

// returns international student's total toefl score
int InternationalStudent::get_Toefl()
{
    return toefl.get_TotalScore(); 
}

int InternationalStudent:: get_Toefl_writing()
{
    return toefl.get_Writing(); 
}
int InternationalStudent::get_Toefl_listening()
{
    return toefl.get_Listening();
}
int InternationalStudent::get_Toefl_speaking()
{
    return toefl.get_Speaking();

}
int InternationalStudent::get_Toefl_reading()
{
    return toefl.get_Reading();
}
// validating Tofel functions
bool  InternationalStudent::valid_Toefl(InternationalStudent& stu)
{
    if (stu.toefl.get_Listening()<20 || stu.toefl.get_Reading()<20 ||stu.toefl.get_Writing()<20||stu.toefl.get_Speaking()<20|| stu.toefl.get_TotalScore()<93)
    {
        return false; 
    }

    return true;   
}

//set the tofel score for the international students
void  InternationalStudent::set_Toefl(int reading_score, int listening_score, int speaking_score, int writing_score)
{
    toefl.set_Reading( reading_score); 
    toefl.set_Listening(listening_score);
    toefl.set_Speaking(speaking_score); 
    toefl.set_Writing(writing_score); 
}
// output
// overloads the insertion operator to print out international students in organized fashion.
ostream &operator <<(ostream&  outs, InternationalStudent& stu)
{   
    outs << std::left << setw(18) << stu.get_studentName() <<std::fixed << std::left << setw(18) << stu.get_studentLastName() << std::left<< setw(14) << stu.get_Country();
    outs << std::left << setw(18) <<std::fixed << setprecision(2) << stu.get_student_CGPA() <<std::fixed << std::left<<setw(18) << stu.get_student_ResearchScore() << std::fixed << std::left << setw(18)<< stu.get_Toefl() << std::left << setw(18) <<endl;
}


// comparing countries of international students for sorting
int compareCountry( InternationalStudent stu1,  InternationalStudent stu2)
{
    // return 0: student1 after student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger alphabets come later 
    if(convert_Country(stu1.get_Country()) == convert_Country(stu2.get_Country()))
    {
        return 2;
    }

    else if (convert_Country(stu1.get_Country()) < convert_Country(stu2.get_Country())) 
    { 
        return 1; // student 2 comes sfter student 1
    }

    
    else if (convert_Country(stu2.get_Country()) < convert_Country(stu1.get_Country()))
    {
        return 0; // student 1 comes sfter student 2
    }

}

int compareTofel(const InternationalStudent& stu1, const InternationalStudent& stu2)
{
    // return 0: student1 after student2
    // return 1:student 2 comes before student 1
    // return 2: student 1 comes before student 2
    if(stu1.toefl.get_TotalScore() == stu2.toefl.get_TotalScore())
    {
        return 2;
    }

    else if (stu1.toefl.get_TotalScore() < stu2.toefl.get_TotalScore()) 
    { 
        return 1; // student 2 comes before student 1
    }

    
    else if (stu2.toefl.get_TotalScore() < stu1.toefl.get_TotalScore())
    {
        return 0; // student 1 comes before student 2
    }
}

int compareOverall(const InternationalStudent& stu1, const InternationalStudent& stu2)
{
    //stu1<stu2
    if (compareResearchScore(stu1, stu2) == 1)//|| compareResearchScore(stu1, stu2) == 0)
    {
        return 0; 
    }
    //stu1=stu2
    else if (compareResearchScore(stu1, stu2) == 2) //same research score 
    {
        //stu1<stu2
        if (compareCGPA(stu1, stu2) == 1)// || compareCGPA(stu1, stu2) == 0) 
        { 
             return 1;     
        }
        // if cgpas are equal 
        else if (compareCGPA(stu1, stu2) == 2) 
        { 
            if (compareCountry(stu1, stu2) == 1) 
            {
                 return 2;           
            }
        }
    }
}
string convert_Country(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;
}

bool  int_robust(InternationalStudent data)
{
        if (data.get_Toefl_writing() == 0 ||data.get_Toefl_reading() == 0  ||data.get_Toefl_listening() == 0 || data.get_Toefl_speaking() == 0 )
        {
            return true;
        }
       else
       {
           return false;
       }  
    
}