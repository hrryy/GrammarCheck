#ifndef DOMLIST_HPP
#define DOMLIST_HPP

#include "Domestic.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
//node for domestic linked list class 
class DomNode  {
  public:
    DomNode *next; 
    DomesticStudent data;
};
typedef DomNode* DomStuPtr; 

class DomList
{
    public:
    DomList(); 
    ~DomList(); 
    void insert(DomesticStudent& stud);
    void remove(string fn, string ls); 
    void remove(DomStuPtr stud);
    bool find_rs(int RS);
    bool find_id(int id);
    bool find_cgpa(float CGPA);
    bool find_fn(string NAME);
    bool find_Ln(string last_name);
    void remove_head();
    void remove_tail();
    void remove_ht();//removes both head and tail 
    void print(); 
    DomStuPtr getHead(); 
    DomStuPtr getTail(); 
    bool dom_robust();
    private:
    DomStuPtr head; 
    DomStuPtr tail; 
};
string convert_named(string str);
#endif