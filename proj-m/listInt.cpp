#include "listInt.hpp"
#include "student.hpp"
#include <vector> 
#include <iostream>
#include <string>
#include <iomanip>

//constructor 
IntList:: IntList() 
{
    head=NULL; 
    tail=NULL; 
}
//destructor 
IntList:: ~IntList()
{
    IntStuPtr temp= head;
    while (head != NULL)
        {
        head = head->next;
        delete temp;
        temp = head;
        }
    head=NULL;
    tail= NULL;
} 
//inserting student objects in a sorted order 
void IntList:: insert(InternationalStudent& stud)
{
    IntStuPtr current=head; 
    IntStuPtr end=head;
    IntStuPtr temp;
    try 
    {
        temp = new IntNode;
    }
    catch (std::bad_alloc&) 
    {
        cout << "Warning! Caught bad_alloc exception.\n"; 
    }
    temp->data= stud; 
    temp-> next= NULL; 
    if( head==NULL || compareResearchScore(head->data, temp->data)==0 )
    {
        temp->next= head; 
        head= temp; 
        tail=temp; 
        return;
    }
    //inserting with keeping the overall sorting order
    while (current->next != NULL &&(compareResearchScore(current->next->data,temp->data)==1 || (compareResearchScore(current->next->data,temp->data)==2  && (compareCGPA(current->next->data,temp->data)==1)) || (compareResearchScore(current->next->data,temp->data)==2) && (compareCGPA(current->next->data,temp->data)==2 ) && (compareCountry(current->next->data, temp->data)==1)))
    {
        current= current->next;   
    }

    temp->next = current->next;
    current->next =temp;
    //keepin track of the tail 
    if (temp->next== NULL)
    {
        tail= temp; 
    }
}

//removing students with the input parameters for the name and last name 
void IntList:: remove(string fn, string ln)
{
    IntStuPtr temp= head;
    IntStuPtr temp1= head;
    if (find_fn(fn) && find_Ln(ln))
    {       
            //comparing the uppercase word for both 
            if (convert_name(head->data.get_studentName())==convert_name(fn) && convert_name(head->data.get_studentLastName())==convert_name(ln))
            {
                head= head->next; 
                delete temp1; 
            }
        while (temp->next!= NULL)
        {
            //finding the IntNode before the one to be deleted 
            if (convert_name(temp->next->data.get_studentLastName())== convert_name(ln) && convert_name(temp->next->data.get_studentName())==convert_name(fn))
            {
                remove(temp); 
            }
            temp= temp->next; 
        }
          cout << "Successfully deleted student from list!"<<endl;       
    }
    else 
    {
        cout<<"No students with this first and last name is in the list."<<endl;
    }

} 
void IntList::remove(IntStuPtr stud_before)//passing the student before the one we need to delete 
{
    IntStuPtr temp; 
    temp= stud_before->next; 
    stud_before-> next= temp->next; 
    delete temp; 
}
//finding the objects with the input reserach score 
bool IntList:: find_rs(int RS)
{
    int count=0; 
    IntStuPtr temp= head; 
    while (temp -> next!= NULL)
    {

     if (temp->data.get_student_ResearchScore()==RS)
        {
            cout<<temp->data;
            count++; 
        }

        temp= temp-> next; 
    }
    if (count==0)
    {
        cout<<"There is no students with this research score."<<endl;
        return false; 
    }
    if (count!=0)
    {
        return true; 
    }
} 
//find the students with the input cgpa 
bool IntList:: find_cgpa( float CGPA)
{
    int count=0; 
    IntStuPtr temp= head; 
    while (temp!= NULL)
    {
        if (temp->data.get_student_CGPA()==CGPA)
        {
           cout<<temp->data;  
           count++; 
        }
        temp= temp-> next; 
    }
    if (count==0)
    {
        cout<<"There is no students with this CGPA."<<endl;
        return false; 
    }
    if (count!=0)
    {
        return true; 
    }
} 
//find the students with the input student id 
bool IntList:: find_id(int ID)
{
    IntStuPtr temp= head; 
    int count=0; 
    while (temp -> next!= NULL)
    {
        if (temp->data.get_studentID()==ID)
        {
           cout<<temp->data; 
           count++; 
        }
        temp= temp-> next; 
    }
    if (count==0)
    {
        cout<<"There is no students with this ID."<<endl;
        return false; 
    }
    if (count!=0)
    {
        return true; 
    }

}
//finding the students with the input first name 
bool IntList:: find_fn(string NAME)
{
    IntStuPtr temp= head; 
    int count=0; 
    while (temp != NULL)
    {
        if (convert_name(temp->data.get_studentName())==convert(NAME))
        {
           cout<<temp->data; 
           count++; 
        }
        temp= temp-> next; 
    }
    if (count==0)
    {
        cout<<"There is no students with this name ."<<endl;
        return false; 
    }
    if (count!=0)
    {
        return true; 
    }

} 
//finding the students with the input last name  
bool IntList:: find_Ln(string LNAME)
{
    IntStuPtr temp= head; 
    int count=0; 
    while (temp != NULL)
    {
        if (convert_name(temp->data.get_studentLastName())==convert_name(LNAME))
        {
           cout<<temp->data; 
           count++; 
        }
        temp= temp-> next; 
    }
    if (count==0)
    {
        cout<<"There is no students with this last name ."<<endl;
        return false; 
    }
    if (count!=0)
    {
        return true; 
    }

} 

void IntList:: remove_ht()
{
    remove_head(); 
    remove_tail(); 
}
//removing the head of the list  
void IntList:: remove_head()
{
    if(head == NULL)
    {
        cout << "ERROR: the list is empty!"<<endl;
        return;
    }
    else 
    {
        IntStuPtr temp=head; 
        head = head->next;  
        delete temp; 
    }
}
//removing the tail of the list 
void IntList:: remove_tail()
{
    if (head == NULL)
    {
        cout << "ERROR: the list is empty!"<<endl;
        return; 
    }
    //only one element in the list
    if (head->next == NULL) 
    {
        delete head;
        return;
    }
  
    // Find the second last IntNode
    IntStuPtr second_last = head;
    while (second_last->next->next != NULL)
    {
         second_last = second_last->next;
    }
    // Delete last IntNode
    delete (second_last->next);
    tail= second_last; 
    // Change next of second last
    tail->next = NULL;
} 
void IntList:: print()
{
    IntStuPtr temp=head;
    
    while (temp!= NULL)
    {
        cout<< temp->data;
        temp=temp->next;
    }

} 
IntStuPtr IntList::getHead()
{
    return head; 
}
IntStuPtr IntList::getTail()
{
    return tail; 
}
//converting to upper case
string convert_name(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;

}