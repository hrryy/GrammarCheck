#ifndef stulist_HPP
#define stulist_HPP

#include "student.hpp"
#include "International.hpp"
#include "Domestic.hpp"
#include "listInt.hpp"
#include "listdom.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Node {
  public:
  public: 
  DomesticStudent DomStu;
  InternationalStudent IntStu;
  Student data;
  Node *next; 
};
typedef Node* NodePtr; 

class stulist
{
    public:
    stulist(); 
    ~stulist(); 
    void insert(Student& stud);
    void print();   
    NodePtr getHead(); 
    NodePtr getTail(); 
    void search(float cgpa_threshold , int rscore_threshold);
    friend ostream &operator <<(ostream& outs, Student stu);
    stulist &operator =(const stulist& copy);
    stulist merge(DomStuPtr Dom, IntStuPtr Int);
    stulist merge_without_print(DomStuPtr Dom, IntStuPtr Int);
    private:
    NodePtr head; 
    NodePtr tail; 
    void deepcopy(const stulist& copy);
    void  deleteall();
};

#endif