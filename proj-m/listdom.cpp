#include "listdom.hpp"
#include "student.hpp"
#include <vector> 
#include <iostream>
#include <string>
#include <iomanip>


//constructor 
DomList:: DomList() 
{
    head=NULL; 
    tail=NULL; 
}
//destructor 
DomList:: ~DomList()
{
    DomStuPtr temp= head;
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
void DomList:: insert(DomesticStudent& stud)
{
    DomStuPtr current=head; 
    DomStuPtr end=head;
    DomStuPtr temp;
    try 
    {
        temp = new DomNode;
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
        tail= temp->next;
        return;
    }
    //inserting with keeping the overall sorting order
    while (current->next != NULL &&(compareResearchScore(current->next->data,temp->data)==1 || (compareResearchScore(current->next->data,temp->data)==2  && (compareCGPA(current->next->data,temp->data)==1)) || (compareResearchScore(current->next->data,temp->data)==2) && (compareCGPA(current->next->data,temp->data)==2 ) && (compareProv(current->next->data, temp->data)==1)))
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

void DomList:: remove(string fn, string ln)
{
    DomStuPtr temp= head;
    DomStuPtr temp1= head;
    if (find_fn(fn) && find_Ln(ln))
    {
        //comparing the uppercase word for both 
        if (convert_named(head->data.get_studentName())==convert_named(fn) && convert_named(head->data.get_studentLastName())==convert_named(ln))
            {
                head= head->next; 
                delete temp1; 
            }
        while (temp->next!= NULL)
        {
            //finding the node before the one to be deleted 

            if (convert_named(temp->next->data.get_studentLastName())== convert_named(ln) && convert_named(temp->next->data.get_studentName())==convert_named(fn))
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
void DomList::remove(DomStuPtr stud_before)//passing the student before the one we need to delete 
{
    DomStuPtr temp; 
    temp= stud_before->next; 
    stud_before-> next= temp->next; 
    delete temp; 
}
//finding the objects with the input reserach score 
bool DomList:: find_rs(int RS)
{
    int count=0; 
    DomStuPtr temp= head; 
    while (temp != NULL)
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
bool DomList:: find_cgpa( float CGPA)
{
    int count=0; 
    DomStuPtr temp= head; 
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
bool DomList:: find_id(int ID)
{
    DomStuPtr temp= head; 
    int count=0; 
    while (temp != NULL)
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
bool DomList:: find_fn(string NAME)
{
    DomStuPtr temp= head; 
    int count=0; 
    while (temp != NULL)
    {
        if (convert_named(temp->data.get_studentName())==convert_named(NAME))
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
bool DomList:: find_Ln(string LNAME)
{
    DomStuPtr temp= head; 
    int count=0; 
    while (temp != NULL)
    {
        if (convert_named(temp->data.get_studentLastName())==convert_named(LNAME))
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

void DomList:: remove_ht()
{
    remove_head(); 
    remove_tail(); 
}
//removing the head of the list  
void DomList:: remove_head()
{
    if(head == NULL)
    {
        cout << "ERROR: the list is empty!"<<endl;
        return;
    }
    else 
    {
        DomStuPtr temp=head; 
        head = head->next;  
        delete temp; 
    }
}
//removing the tail of the list 
void DomList:: remove_tail()
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
  
    // Find the second last node
    DomStuPtr second_last = head;
    while (second_last->next->next != NULL)
    {
         second_last = second_last->next;
    }
    // Delete last node
    delete (second_last->next);
    tail= second_last; 
    // Change next of second last
    tail->next = NULL;
} 
void DomList:: print()
{
    DomStuPtr temp=head;
    
    while (temp!= NULL)
    {
        cout<< temp->data;
        temp=temp->next;
    }

} 
DomStuPtr DomList:: getHead()
{
    return head; 
}
DomStuPtr DomList:: getTail()
{
    return tail; 
} 
bool DomList:: dom_robust()
{
    DomStuPtr temp = head;

   while ( temp->next != NULL)
   {
        if ( temp->data.get_student_ResearchScore() == 0 )
        {
            return true;
        }
       else
       {
           return false;
       }
       temp = temp->next;
    }
}
string convert_named(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;

}