#ifndef INTLIST_HPP
#define INTLIST_HPP
#include "TOFEL.hpp"
#include "International.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
//node for domestic linked list class 
class IntNode{
  public:
    IntNode *next; 
    InternationalStudent data;
};
typedef IntNode* IntStuPtr; 

class IntList
{
    public:
    IntList(); 
    ~IntList(); 
    void insert(InternationalStudent& stud);
    void remove(string fn, string ls); 
    void remove(IntStuPtr stud);
    bool find_rs(int RS);
    bool find_id(int id);
    bool find_cgpa(float CGPA);
    bool find_fn(string NAME);
    bool find_Ln(string last_name);
    void remove_head();
    void remove_tail();
    void remove_ht();//removes both head and tail 
    void print(); 
    IntStuPtr getHead(); 
    IntStuPtr getTail();
    private:
    IntStuPtr head; 
    IntStuPtr tail; 
};
string convert_name(string str);
#endif