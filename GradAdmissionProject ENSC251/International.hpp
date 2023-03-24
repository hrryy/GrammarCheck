//international.hpp to implement InternationalStudent class
#ifndef INTERNATIONAL_HPP
#define INTERNATIONAL_HPP

#include "student.hpp"
#include "TOFEL.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

class InternationalStudent : public Student 
{
public:
    // constructor
    InternationalStudent(); 
    // setters
    // sets the international student country
    void set_Country(string count);
    //sets international student tofel total score
    void set_Toefl(int reading, int listening, int speaking, int writing);
    // getters
    // returns international students country
    string get_Country();
    // returns international students total tofel score
    int get_Toefl();
    int get_Toefl_writing();
    int get_Toefl_listening();
    int get_Toefl_speaking();
    int get_Toefl_reading();
    // output
    // prints the information in the international class 
    friend ostream &operator <<(ostream&  outs, InternationalStudent& stu);
    //comparing countries of international students 
    friend int compareCountry(InternationalStudent stu1,  InternationalStudent stu2);
    //compare the tofelscore- this can be redundant 
    friend int compareTofel(const InternationalStudent& stu1, const InternationalStudent& stu2);
    friend int compareOverall(const InternationalStudent& stu1, const InternationalStudent& stu2);
    //check the validity of the tofel score, to be printed 
    bool valid_Toefl(InternationalStudent& stu);
    
    //private variables 
    private:
    string country; 
    ToeflScore toefl;
};
string convert_Country(string str);
bool int_robust(InternationalStudent data);
#endif