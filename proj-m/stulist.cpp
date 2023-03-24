#include "stulist.hpp"
#include "student.hpp"
#include <vector> 
#include <iostream>
#include <string>
#include <iomanip>

//constructor 
stulist ::stulist()
{
    head= NULL; 
    tail=NULL; 
}
//destrcutor 
stulist ::~stulist()
{//deleting all the nodes 
    NodePtr temp= head;
    while (head != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    head=NULL;
    tail= NULL;
} 
//overloaded assignemnet operator used for merge in main 
stulist &stulist :: operator =(const stulist& copy)
{
     if (this != &copy) 
    {
        
        deleteall();
        deepcopy(copy);
        
    }
    return *this;
}

stulist stulist ::merge(DomStuPtr Dom, IntStuPtr Int)
{
    int count=0; 
    stulist list; 
    DomStuPtr temp= Dom;
    IntStuPtr temp2= Int;
    DomStuPtr temp4= Dom;
    IntStuPtr temp5= Int;
    while (temp!=NULL)//inserting all domestic students to the list
    {
        list. insert(temp->data);
        temp= temp->next;    
    }
    while (temp2!=NULL)//inserting all international students
    {
      
        list. insert(temp2->data);
        temp2= temp2->next; 
      
    }


    NodePtr temp3= list.getHead(); 
    while (temp3!= NULL && temp4!= NULL && temp5!= NULL)
    {
        //using the student ID to differntiate between the international and domestic students 
        if (temp3->data.get_studentID()>=20220101  )
        {
            if (temp5->data.valid_Toefl(temp5->data))
            {
                //printing international 
                cout<<temp5->data;
            }
            
            temp5=temp5-> next;  
        }
        else if (temp3->data.get_studentID()<20220101)
        {
            //printing domestic 
            cout<<temp4->data;
            temp4= temp4->next;  
        }
        temp3= temp3->next; 
        count ++; 
    }
  
    return list; 
}
//returns a pointer to the head 
NodePtr stulist ::getHead()
{
    return head; 
} 
//returns a pointer to the tail 
NodePtr stulist ::getTail()
{
    return tail; 
} 

void stulist ::insert(Student& stud)
{
    NodePtr current=head; 
    NodePtr end=head;
    NodePtr temp;
    try 
    {
        temp = new Node;
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
    while (current->next != NULL &&(compareResearchScore(current->next->data,temp->data)==1 || (compareResearchScore(current->next->data,temp->data)==2  && (compareCGPA(current->next->data,temp->data)==1))|| ((compareCGPA(current->next->data,temp->data)==2 )&&(compareResearchScore(current->next->data,temp->data)==2 ) && temp->data.get_studentID()>20220100 )))
    {
        current= current->next;   
    }

    temp->next = current->next;
    current->next =temp;
    //keepin track of the tail 
    if (temp->next== NULL)
    {
        tail=temp; 
    }

}
//seartching for students with a certain cgpa and research score threshold in the merged list 
void  stulist ::search(float cgpa_threshold , int rscore_threshold)
{
    NodePtr temp = head; 
    while (temp!= NULL)
    {
        if (temp->data.get_student_ResearchScore()>= rscore_threshold && temp->data.get_student_CGPA()>= cgpa_threshold)
        {
        
           cout<<temp->data; 
        }
        temp=temp->next; 
    }

}
//merging without printing the students/ used in main file 
stulist stulist::  merge_without_print(DomStuPtr Dom, IntStuPtr Int)
{
    stulist list; 
    DomStuPtr temp= Dom;
    IntStuPtr temp2= Int;
    DomStuPtr temp4= Dom;
    IntStuPtr temp5= Int;
    while (temp!=NULL)//inserting all domestic students to the list
    {
        list. insert(temp->data);
        temp= temp->next;    
    }
    while (temp2!=NULL)//inserting all international students
    {
      
        list. insert(temp2->data);
        temp2= temp2->next; 

    }

    return list; 
}


//////////////////////Private Helper Methods for the overloaded assignement operator/////////////
void stulist::deepcopy(const stulist& copy)
{   
    //create a node to copy the parameter to it  
    head=NULL;
    NodePtr newNode= NULL; 
    NodePtr dq= copy.head; 
    
    //if the object is not empty traverse through it 
    if (dq!= NULL)
    {
        try 
        {
            head = new Node; 
        }
        catch (std::bad_alloc&) 
        {
            cout << "Warning! Caught bad_alloc exception.\n"; 
        }
        head->data=dq->data;
        dq= dq-> next; 
        NodePtr cpy= head; 
        //while we have not reached the end of the object copy them to the new node 
        while (dq != NULL)
        {
            try
            {
               newNode = new Node;
            }
            catch (std::bad_alloc&) 
            {
                cout << "Warning! Caught bad_alloc exception.\n"; 
            }
            newNode->data= dq->data;
            cpy -> next = newNode; 
            cpy = cpy -> next; 
            dq = dq -> next; 
            
        }
        //assign the last element to the tail
        tail=cpy; 
    }
}
//DEALLOCATES THE MEMORY ASSOCIATED WITH THE list AND DELETES IT//
//This is a private helper method 

void stulist :: deleteall()
{
    NodePtr temp = head;
    while (head != NULL)
        {
        head = head->next;
        delete temp;
        temp = head;
        }
    head= NULL;
    tail=NULL; 

}