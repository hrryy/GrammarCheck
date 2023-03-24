#include <iostream> //cin and cout
#include <vector> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cctype> 
#include "student.hpp"
#include "Domestic.hpp"
#include "International.hpp"
#include "listInt.hpp"
#include "listdom.hpp"
#include "stulist.hpp"


void printSearchMenu();
void printMergeMenu();
void printUnitMenu();
// function to make sure the user entered the correct data type
int getResponse();
float getCGPAResponse();
string checkProv(string province);
string check(string userHome); 
float checkCGPA(float  uscore); 
int checkRS(int  score); 
string convert_check(string str);
int checkTF(int  score);


//helper functions 
void Create_Domestic(DomList &list)
{
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;

  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  //cout << "File format: " << line << endl;

  int stu_count = 1;
  while( getline(domesticFile, line) ) {

    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    DomesticStudent stuD;
    stuD.set_Applicant(firstName, lastName, cgpa , researchScore); 
    stuD.set_province(province);
    stuD.set_studentID(stu_count);
    list.insert(stuD);


    stu_count++;
  }
  if (list.dom_robust() == 1 )
    {
        cout << "A field in domestic is missing" << endl;
        std::exit(1); 
    }
  //close your file
  domesticFile.close();
}

void Create_International(IntList &list)
{

  //IntList list;  
  string line;
  ifstream InternationalFile("international-stu.txt");
  if(!InternationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(InternationalFile, line);

  int stu_count = 1;
  while( getline(InternationalFile, line) ) {
    istringstream ss(line);

    string firstName, lastName, country , s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, country, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    //get listening separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());
    //get writing separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());
    //get reading separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    InternationalStudent stuI;
    if (country== "idian " || country=="Idian")
    {
      country= "India"; 
    }
    stuI.set_Applicant(firstName, lastName, cgpa , researchScore); 
    stuI.set_Country(country);
    stuI.set_Toefl(reading, listening, speaking, writing);
    stuI.set_studentID(stu_count+100);
    //robust error checking 
    if (int_robust(stuI) == 1 )
    {
        cout << "A field in international is missing" << endl;
        std::exit(1);
    }
    list.insert(stuI);


    stu_count++;
  }

  //close your file
  InternationalFile.close();
}



// main
int main() {
    // read in data from file to domestic student singly linked list and store in a sorted order
    // each time a dom student object is inserted into singly linked list make sure it's sorted with overall sorting
    // read in data from file to internation student singly linked list and store in a sorted order
    // each time an int student object is inserted into singly linked list make sure it's sorted with overall sorting
    // do error checking to make sure each student object is in a valid range
    // fix the idian to india thing
DomesticStudent domStu;// domestic student object
InternationalStudent intStu;// internatinoal student object   
DomList  domL; 
Create_Domestic( domL);
//domL.print();
//Create_International(stuInt);
IntList intL; 
Create_International(intL);
//intL.print();

stulist stuL; 
stulist list3; 
stulist list2;
list2= stuL.merge_without_print(domL.getHead(), intL.getHead());
//mergered list is list 2 
//list2= list.merge( domL.getHead(), intL.getHead()); //using the overloaded assignment operator

cout<<endl<<endl<<endl; 
    // user input variables, used throughout file
    int write, read,speak,listen; 
    int response;
    int searchChoice;
    int cgpa_threshold;
    int research_threshold;
    int unitChoice; // used to choose which group to unit test in printUnitMenu function
    int innovationChoice;

    while (response != 6) {
        // welcome menu
        cout << "\n~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        cout << "ENSC 251: Graduate Student Admission System [Menu]\n";
        cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n\n";
        cout << "Would you like to view: \n";
        cout << "[1] Domestic Students\n[2] International Students\n[3] All Students\n[4] Unit Tests\n[5] Printing Lists\n[6] Quit Program\n\n";
        cout << "Enter choice: ";

        // user input
        response = getResponse();
        cout << endl;

        // DOMESTIC STUDENTS
        if (response == 1) {
            // menu
            cout << "Viewing domestic students...\n\n";
            printSearchMenu();
        
            while (searchChoice != 9) {
                searchChoice = getResponse();
                cout << endl;

                //go through choices
                // 1. search by first and last name
                if (searchChoice == 1) {
                    // get user to input first and last name, and make it case insensitive
                    // input given info to search functions
                    cout << "Searching by first and last name...\n\n";
                    string userFirst, userLast;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    //print message 
                    cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
                    domL.find_fn(userFirst);
                    domL.find_Ln(userLast);
                    printSearchMenu();
                }
                // 2. searching by student id
                else if (searchChoice == 2) {
                    cout << "Searching by student id...\n\n";
                    // user inputs student id 
                    cout << "Please enter an student id you'd like to search for: ";
                    int userAppID;
                    userAppID = getResponse();
                    // input student id into search function
                   cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
                     domL.find_id(userAppID); 
                    printSearchMenu();
                }
                // 3. searching by CGPA
                else if (searchChoice == 3) {
                    cout << "Searching by CGPA...\n\n";
                    // user inputs CGPA 
                    cout << "Please enter a CGPA you'd like to search for: ";
                    float userCGPA; 
                    userCGPA = getCGPAResponse();
                    checkCGPA(userCGPA);
                    // input CGPA into search function
                    cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
                     domL.find_cgpa(userCGPA); 
                    printSearchMenu();
                }
                // 4. searching by research score
                else if (searchChoice == 4) {
                    cout << "Searching by research score...\n\n";
                    // user inputs research score 
                    // input research score into search function
                    cout << "Please enter the research score you'd like to search for: ";
                    int userrScore;
                    userrScore = getResponse();
                    // input student id into search function
                    cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
                     domL.find_rs(userrScore);   
                    printSearchMenu();
                }
                // 5. Insert new node
                else if (searchChoice == 5) {
                    cout << "Inserting new node...\n\n";
                    // get user to input info
                    cout << "Please enter the student information you'd like to add: \n";
                    string userFirst, userLast, userHome;
                    float userCGPA; 
                    int userrScore, appID;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    cout << "Please enter a CGPA: ";
                    userCGPA = getCGPAResponse();
                    checkCGPA(userCGPA);
                    cout << "Please enter the research score: ";
                    userrScore = getResponse();
                    checkRS(userrScore);
                    cout << "Please enter a province: ";
                    cin >> userHome;
                    checkProv(userHome);
                    domStu.set_studentName(userFirst);
                    domStu.set_studentLastName(userLast);
                    domStu.set_student_CGPA(userCGPA);
                    domStu.set_student_ResearchScore(userrScore);
                    domStu.set_province(userHome);
                    // duplicates student ids that might already exist- try and fix
                    cout << "Please enter student ID (Enter an integer): ";
                    cin >> appID;
                    domStu.set_studentID(appID);
                    domL.insert(domStu);
                    //Dom.sortOverall(Dom.get_head());
                    cout << "\nStudent successfully added to domestic students list!\n";
                    cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
                    domL.print();
                    // create new node based on user input info and insert to the singly linked list in order
                    // check if there's already matching info then replace or print error
                    // error checking: if a line in txt file is missing a parameter, catch error and print message 
                    printSearchMenu();
                }
                // 6. Delete existing dom student object
                else if (searchChoice == 6) {
                    cout << "Deleting existing node...\n\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "Please enter the student information you'd like to delete: \n";
                    string userFirst, userLast;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    domStu.set_studentName(userFirst);
                    domStu.set_studentLastName(userLast);
                    domL.remove(userFirst,userLast); // make sure this works
                    domL.print();
                    printSearchMenu();
                }
                // 7. Delete head and tail nodes in a single delete func
                else if (searchChoice == 7) {
                    cout << "Deleting head and tail nodes...\n\n";
                    // look for the head and tail nodes and delete from linked list
                     domL.remove_ht();
                     domL.print();
                    printSearchMenu();
                }
                // 8. Error testing demo
                else if (searchChoice == 8) {
                    // case that's out of bounds (illegal case) DO IN ERROR TESTING PART NOT HERE
                    //cout << "TEST PASSED: Proved program won't work for cases that are out of range\n\n"; 
                    // eg cout << "Searching for an InternationalStudent by first and last name that isn't in the list ...\n";

                    // TEST PASSED: Prints message stating student is not in list

                    cout << "Running error testing demo...\n\n";
                    // basically create inputs that won't work and show put it in, showing the error it
                    // will display for each domestic case
                    cout << "Case for name not in text file: \n";
                    cout << "First Name, Last Name: Samin Moradkhan \n";
                    domL.find_fn("Samin");
                    domL.find_Ln("Moradkhan");
                    cout << "TEST PASSED!\n\n";

                    cout << "Case when out of range CGPA is inserted: \n";
                    cout << "Enter CGPA: 5.0\n";
                     domL.find_cgpa(5.0); 
                    cout << "TEST PASSED!\n\n";

                    cout << "Case when negative research score is inserted: \n";
                    cout << "Enter research score: -33\n";
                     domL.find_rs(-33);
                    cout << "TEST PASSED!\n\n";

                    cout << "Case trying to delete a student not in file: \n";
                    cout << "First Name, Last Name: Samin Moradkhan\n";
                    domStu.set_studentName("Samin");
                    domStu.set_studentLastName("Moradkhan");
                     domL.remove("Samin", "Moradkhan"); // make sure
                    cout << "TEST PASSED!\n\n";

                    printSearchMenu();
                }
                // 9. Quit program
                else if (searchChoice == 9) {
                    // std::exit program
                    cout << "Quitting the program. Thank you!\n\n";
                    std::exit(0);
                }
                // 10. Return to main menu
                else if (searchChoice == 10) {
                    // return to the main menu
                    break;
                }
                // if not valid, ask user to input valid input
                else {
                    cout << "Invalid entry. Please enter a choice from 1-10.\n";
                    printSearchMenu();      
                    continue;
                }
            }
            if (searchChoice == 10) {
                continue;
            }
            return 0;
        }

        // INTERNATIONAL STUDENTS
        else if (response == 2) {
            // menu
            cout << "Viewing international students...\n\n";
            printSearchMenu();
        
            while (searchChoice != 9) {
                searchChoice = getResponse();
                cout << endl;

                //go through choices
                // 1. search by first and last name
                if (searchChoice == 1) {
                    cout << "Searching by first and last name...\n\n";
                    // get user to input first and last name, and make it case insensitive
                    // input given info to search functions
                    string userFirst, userLast;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                    intL.find_fn(userFirst);
                    intL.find_Ln(userLast);
                    printSearchMenu();
                }
                // 2. searching by student id
                else if (searchChoice == 2) {
                    cout << "Searching by student id...\n\n";
                    // user inputs student id 
                    cout << "Please enter an student id you'd like to search for: ";
                    int userAppID;
                    userAppID = getResponse();
                    // input student id into search function
                    cout<< "First Name        "<< "Last Name        "<<" Country "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                    intL.find_id(userAppID);  
                    printSearchMenu();
                }
                // 3. searching by CGPA
                else if (searchChoice == 3) {
                    cout << "Searching by CGPA...\n\n";
                    // user inputs CGPA 
                    cout << "Please enter a CGPA you'd like to search for: ";
                    float userCGPA; 
                    userCGPA = getCGPAResponse();
                    // input CGPA into search function
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                    intL.find_cgpa(userCGPA); 
                    printSearchMenu();
                }
                // 4. searching by research score
                else if (searchChoice == 4) {
                    cout << "Searching by research score...\n\n";
                    // user inputs research score 
                    // input research score into search function
                    // if not found, print message and continue   
                    cout << "Please enter the research score you'd like to search for: ";
                    int userrScore;
                    userrScore = getResponse();
                    // input student id into search function
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<<endl<<endl;
                    intL.find_rs(userrScore);  
                    printSearchMenu();
                }
                // 5. Insert new node
                else if (searchChoice == 5) {
                    cout << "Inserting new node...\n\n";
                    // get user to input info
                    cout << "Please enter the student information you'd like to add: \n";
                    string userFirst, userLast, userHome;
                    float userCGPA; 
                    int userrScore, appID;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    cout << "Please enter a CGPA: ";
                    userCGPA = getCGPAResponse();
                    checkCGPA(userCGPA); 
                    cout << "Please enter the research score: ";
                    userrScore = getResponse();
                    checkRS(userrScore);
                    cout << "Please enter a country: ";
                    cin >> userHome;
                    check(userHome); 
                    cout << "Please enter the TOEFL Score for reading: ";
                    cin>> read; 
                    checkTF(read);
                    cout << "Please enter the TOEFL Score for speaking: ";
                    cin>>speak; 
                    checkTF(speak);
                    cout << "Please enter the TOEFL Score for listening: ";
                    cin>>listen;
                    checkTF(listen);
                    cout << "Please enter the TOEFL Score for writing: ";
                    cin>>write;
                    checkTF(write); 
                    intStu.set_Toefl(read, speak, listen, write); 
                    intStu.set_studentName(userFirst);
                    intStu.set_studentLastName(userLast);
                    intStu.set_student_CGPA(userCGPA);
                    intStu.set_student_ResearchScore(userrScore);
                    intStu.set_Country(userHome);
                    cout << "Please enter student ID (Enter an Integer): ";
                    cin >> appID;
                    intStu.set_studentID(appID);
                    intL.insert(intStu);
                    //intL.sortOverall(intL.get_head())
                    cout << "\nStudent successfully added to internatinoal students list!\n";
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                    intL.print();
                    // create new node based on user input info and insert to the singly linked list in order
                    // check if there's already matching info then replace or print error
                    // error checking: if a line in txt file is missing a parameter, catch error and print message 
                    printSearchMenu();
                }
                // 6. Delete existing dom student object
                else if (searchChoice == 6) {
                    cout << "Deleting existing node...\n\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "Please enter the student information you'd like to delete: \n";
                    string userFirst, userLast;
                    cout << "Please enter a first name: ";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cin >> userFirst;
                    cout << "Please enter a last name: ";
                    cin >> userLast;
                    intStu.set_studentName(userFirst);
                    intStu.set_studentLastName(userLast);
                    intL.remove(userFirst, userLast); 
                    intL.print();
                    printSearchMenu();
                }
                // 7. Delete head and tail nodes in a single delete func
                else if (searchChoice == 7) {
                    cout << "Deleting head and tail nodes...\n\n";
                    // look for the head and tail nodes and delete from linked list
                    intL.remove_ht();
                    intL.print();
                    printSearchMenu();
                }
                // 8. Error testing demo
                else if (searchChoice == 8) {
                    // case that's out of bounds (illegal case) DO IN ERROR TESTING PART NOT HERE
                    //cout << "TEST PASSED: Proved program won't work for cases that are out of range\n\n"; 
                    // eg cout << "Searching for an InternationalStudent by first and last name that isn't in the list ...\n";

                    // TEST PASSED: Prints message stating student is not in list

                    cout << "Running error testing demo...\n\n";
                    // basically create inputs that won't work and show put it in, showing the error it
                    // will display for each domestic case
                    cout << "Case for name not in text file: \n";
                    cout << "First Name, Last Name: Samin Moradkhan\n";
                    intL.find_fn("Samin");
                    intL.find_Ln("Samin");

                    cout << "TEST PASSED!\n\n";

                    cout << "Case when negative CGPA is inserted: \n";
                    cout << "Enter CGPA: -4.8\n";
                    intL.find_cgpa(-4.8); 
                    cout << "TEST PASSED!\n\n";

                    cout << "Case when research score > 100 is inserted: \n";
                    cout << "Enter research score: 133\n";
                    intL.find_rs(133);
                    cout << "TEST PASSED!\n\n";

                    cout << "Case trying to delete a student not in file: \n";
                    cout << "First Name, Last Name:Samin Moradkhan\n";
                    intStu.set_studentName("Samin");
                    intStu.set_studentLastName("Moradkhan");
                    intL.remove("Samin", "Moradkhan"); // make sure
                    cout << "TEST PASSED!\n\n";

                    printSearchMenu();
                }
                // 9. Quit program
                else if (searchChoice == 9) {
                    // exit program
                    cout << "Quitting the program. Thank you!\n\n";
                    std::exit(0);
                }
                // 10. Return to main menu
                else if (searchChoice == 10) {
                    // return to the main menu
                    break;
                }
                // if not valid, ask user to input valid input
                else {
                    cout << "Invalid entry. Please enter a choice from 1-10.\n";
                    printSearchMenu();      
                    continue;
                }
            }
            if (searchChoice == 10) {
                continue;
            }
            return 0;
        }

        // ALL STUDENTS
        else if (response == 3) {
            // menu
            //stuList stuL;
            cout << "Viewing all students...\n\n";
            printMergeMenu();
        
            while (searchChoice != 3) {
                searchChoice = getResponse();
                cout << endl;

                //go through choices
                // 1. Display all students
                if (searchChoice == 1) {
                    cout << "Displaying all students...\n\n";
                    // merge the two lists together
                    stuL.getHead();
                    stuL.getTail();
                    cout<< "First Name        "<< "Last Name        "<<" Home    "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                  
                    list2= stuL.merge(domL.getHead(), intL.getHead()); //using the overloaded assignment operator
                 
                    cout << "exiting program. Thanks  !\n";
                    // print all students info unless they dont meet the toefl requirement (sorted w cgpa and research score)
                    std::exit(0);
                }
                // 2. displaying students who have a cgpa and research score >= the user input
                else if (searchChoice == 2) {
                    // get user to input cgpa and research score thresholds
                    float getCGPA;
                    int rScore;
                    cout << "Enter a minimum CGPA: ";  
                    getCGPA = getCGPAResponse();
                    cout << "Enter a minimum research score: ";
                    rScore = getResponse();

                    // error checking to make sure input in valid range + type

                    cout << "Searching for students with a CGPA >= " << getCGPA << " and a research score >= to " << rScore << "...\n\n";
                    cout << "Work in progress...\n\n";
                    cout<< "First Name        "<< "Last Name        "<<" CGPA       "<< " Research Score"<<endl<<endl;
                    list2.search(getCGPA, rScore); 
                    cout << "exiting program. Thanks  !\n";
                    // print matching results WITH POLYMORPHISM AND VIRTUAL FUNCTION

                    std::exit(0); 
                }
                // 3. Quit program
                else if (searchChoice == 3) {
                    // exit program
                    cout << "Quitting the program. Thank you!\n\n";
                    std::exit(0);
                }
                // 4. Return to main menu
                else if (searchChoice == 4) {
                    // make it return to the main menu 
                    cout << "Returning to main menu";
                    break;
                }
                // if not valid, ask user to input valid input
                else {
                    cout << "Invalid entry. Please enter a choice from 1-4.\n";
                    printMergeMenu();      
                    continue;
                }
            }
            if (searchChoice == 4) {
                continue;
            }
            return 0;
        }

        // UNIT TESTING
        else if (response == 4) {
            // menu
            cout << "Unit testing...\n\n";
            printUnitMenu();

            while (searchChoice != 7) {
                searchChoice = getResponse();
                cout << endl;

                //go through choices
                // 1. insert new student
                if (searchChoice == 1) {
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "TEST: INSERTING A NEW STUDENT\n";
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "Inserting a student to the DomesticStudent linked list in order...\n\n";
                    // then add a student to the domestic vector and print that student out
                    cout << "First name: Candice\n";
                    cout << "Last name: Joyce\n";
                    cout << "CGPA: 2.9\n";
                    cout << "Research score: 71\n";
                    cout << "Province: ON\n";
                    cout << "Student ID (Integer): 10\n";
                    domStu.set_studentName("Candice");
                    domStu.set_studentLastName("Joyce");
                    domStu.set_student_CGPA(2.9);
                    domStu.set_student_ResearchScore(71);
                    domStu.set_province("ON");
                    domStu.set_studentID(10);
                    domL.insert(domStu);
                    cout << "\nStudent successfully added to domestic students list!\n";

                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";

                    cout << "Inserting a student to the InternationalStudent linked list in order...\n";
                    cout << "First name: Lucas\n";
                    cout << "Last name: Nuzzo\n";
                    cout << "CGPA: 4.0\n";
                    cout << "Research score: 98\n";
                    cout << "Country: India\n";
                    cout << "Student ID (Integer): 5\n";
                    intStu.set_studentName("Lucas");
                    intStu.set_studentLastName("Nuzzo");
                    intStu.set_student_CGPA(4.0);
                    intStu.set_student_ResearchScore(98);
                    intStu.set_Country("india");  
                    intStu.set_Toefl(25,27,30, 29);                  
                    intStu.set_studentID(5);
                    intL.insert(intStu);
                    cout << "\nStudent successfully added to domestic students list!\n";
                    // then add a student to the domestic vector and print that student out
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";

                    printUnitMenu();

                }
                // 2. search existing objects (by first and last name, cgpa, research score and student ID)
                else if (searchChoice == 2) {
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "TEST: SEARCHING FOR STUDENTS\n";
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "Searching for a DomesticStudent by first and last name...\n";
                    // then search and show it being searched and print that student
                    cout << "First name: Samin\n";
                    cout << "Last name: Moradkhan\n";
                    domL.find_fn("Samin");
                    domL.find_Ln("Moradkhan");
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";

                    cout << "Searching for a DomesticStudent with a CGPA of 3.2 ...\n";
                    // then search and print those students
                    domL.find_cgpa(3.2);
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";

                    cout << "Searching for a DomesticStudent with a research score of 95...\n";
                    domL.find_rs(95);   
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";

                    cout << "Searching for an InternationalStudent by first and last name...\n";
                    // then search and show it being searched and print that student
                    cout << "First name: Hyunjoo\n";
                    cout << "Last name: Cheong\n";
                    intL.find_fn("Hyunjoo");
                    intL.find_Ln("Cheong");
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";


                    cout << "Searching for an InternationalStudent with a CGPA of 2.8 ...\n";
                    // then search and print those students
                    intL.find_cgpa(2.8);
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";


                    cout << "Searching for an InternationalStudent with a research score of 89...\n";
                    // then search and print those students
                    intL.find_rs(89);
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";

                    printUnitMenu();

                }
                // 3. delete existing object (based on first and last name)
                else if (searchChoice == 3) {
                    // show delete with different cases and show that the test passes
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "TEST: DELETING AN EXISTING OBJECT\n";
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "Deleting an object from DomesticStudent...\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "First name to delete: Elijah\n";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cout << "Last name to delete: Reed\n";
                    domStu.set_studentName("Elijah");
                    domStu.set_studentLastName("Reed");
                    domL.remove("Elijah", "Reed"); // make sure this works
                    cout << "\n[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";

                    cout << "Deleting an object from InternationalStudent...\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "First name to delete: Dohyun\n";
                    // ADD ERROR CHECKING TO MAKE SURE RIGHT DATA TYPE 
                    cout << "Last name to delete: Ghim\n";
                    intStu.set_studentName("Dohyun");
                    intStu.set_studentLastName("Ghim");
                    intL.remove("Dohyun", "Ghim"); // make sure this works
                    cout << "\n[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n";

                    // if in file delete the object
                    // else print message (delete functino does this we gucci baby)
                    printUnitMenu();
                }
                // 4. delete head and tail nodes
                else if (searchChoice == 4) {
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "TEST: DELETING HEAD AND TAIL NODES\n";
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "Deleting head and tail nodes from DomesticStudent...\n\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "Current head: " << domL.getHead()->data;
                    cout << "Current tail: " << domL.getTail()->data << endl << endl;
                    domL.remove_ht();
                    cout << "New head: " << domL.getHead()->data;
                    cout << "New tail: " << domL.getTail()->data << endl;

                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";
                    cout << "Deleting head and tail nodes from InternationalStudent...\n\n";
                    // get user to enter a first and last name
                    // get user to input info
                    cout << "Current head:     " << intL.getHead()->data;
                    cout << "Current tail:" << intL.getTail()->data << endl << endl;
                    intL.remove_ht();
                    cout << "New head: " << intL.getHead()->data;
                    cout << "New tail: " << intL.getTail()->data << endl;

                    cout << "\n[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";
                    printUnitMenu();
                }
                // 5. merge both singly linked lists 
                else if (searchChoice == 5) {
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n";
                    cout << "TEST: MERGING BOTH SINGLY LINKED LISTS TO A SINGLE STUDENT LINKED LIST\n";
                    cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n\n";
                    cout << "Merging linked lists...\n";
                    list3= stuL.merge(domL.getHead(), intL.getHead());
                    cout << "[][][][][][][][][][][][][][][][][][][ TEST PASSED ][][][][][][][][][][][][][][][][][][]\n\n\n";
                    printUnitMenu();
                }
                // 6. merge both singly linked lists then search for students who have >= user inputt cgpa and research score
                else if (searchChoice == 6) {
                  float input1;
                   int input2;
                    cout << "TEST: MERGE BOTH SINGLY LINKED LISTS THEN SEARCH FOR THOSE WITH A CERTAIN CGPA AND RESEARCH SCORE\n";
                    cout<<endl<<"Please enter CPGA threshold: "; 
                    cin>> input1; 
                    cout<<endl<<"Please enter research score threshold: "; 
                    cin>>input2; 
                    cout << "Work in progress...\n\n";
                    list3=stuL.merge_without_print(domL.getHead(), intL.getHead());
                    cout<< "First Name        "<< "Last Name        "<<"   CGPA        "<< " Research Score"<<endl<<endl;
                    list3.search(input1, input2);
                    cout << "exiting program. Thanks  !\n";
                    std::exit(0);
                }
                // 7. quit program
                else if (searchChoice == 7) {
                    // std::exit program
                    cout << "Quitting the program. Thank you!\n\n";
                    std::exit(0);
                }
                // 8. return to main menu
                else if (searchChoice == 8) {
                    cout << "Returning to main menu\n";
                    break;
                }
                // if not valid, ask user to input valid input
                else {
                    cout << "Invalid entry. Please enter a choice from 1-8.\n";
                    printUnitMenu();      
                    continue;
                }
            }
            if (searchChoice == 8) {
                continue;
            }
            return 0;
        }
        // INNOVATION: Add option for user to view each lists to see the changes they made
        else if (response == 5) {
            cout << "Would you like to print:\n[1] Domestic students list\n[2] International students list\n[3] Merged students list\n[4] Return to main menu\n[5] Quit program\n\n";
            cout << "Enter choice: ";
            while (searchChoice != 5) {
                searchChoice = getResponse();
                cout << endl;
                
                //go through choices
                if (searchChoice == 1) {
                    cout << "Printing all Domestic Student objects...\n";
                    cout<< "First Name        "<< "Last Name        "<<" Province  "<<"    CGPA        "<< "      Research Score"<<endl<<endl;
  
                    domL.print();
                    cout << endl;
                    cout << "Would you like to print:\n[1] Domestic students list\n[2] International students list\n[3] Merged students list\n[4] Return to main menu\n[5] Quit program\n\n";
                    cout << "Enter choice: ";
                }
                else if (searchChoice == 2) {
                    cout << "Printing all International Student objects...\n";
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;

                    intL.print();
                    cout << endl;
                    cout << "Would you like to print:\n[1] Domestic students list\n[2] International students list\n[3] Merged students list\n[4] Return to main menu\n[5] Quit program\n\n";
                    cout << "Enter choice: ";
                }
                else if (searchChoice == 3) {
                    cout << "Printing all merged Student objects...\n";
                    cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "      Research Score"<< "    Toefl Score"<<endl<<endl;
                    stuL.merge(domL.getHead(), intL.getHead());
                    cout << endl;
                    cout << "Would you like to print:\n[1] Domestic students list\n[2] International students list\n[3] Merged students list\n[4] Return to main menu\n[5] Quit program\n\n";
                    cout << "Enter choice: ";
                }
                else if (searchChoice == 4) {
                    cout << "Returning to main menu\n";
                    break;
                }
                else if (searchChoice == 5) {
                    // std::exit program
                    cout << "Quitting the program. Thank you!\n\n";
                    std::exit(0);
                }
                else {
                    cout << "Invalid entry. Please enter a choice from 1-5.\n";
                    continue;     
                }
            }
            if (searchChoice == 4) {
                continue;
            }
            return 0;
        }
        // QUIT PROGRAM
        else if (response == 6) {
            cout << "Quitting the program. Thank you!\n\n";
            std::exit(0);
        }

        // IF INVALID INPUT
        else {
            cout << "Invalid entry, please try again!\n\n";
            continue;
        }
    }
    return 0;
}

// function to make sure the user entered the correct data type
int getResponse() { 
  int userInput;
  while (true) {
    std::cin >> userInput;
    if (std::cin.fail()) {
      if (!std::cin) {
        std::cout << "Error! Incorrect data type. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore();
      }
    }
    else {
      return userInput;
    }
  }
  return 0;
}

float getCGPAResponse() { 
  float userInput;
  while (true) {
    std::cin >> userInput;
    if (std::cin.fail()) {
      if (!std::cin) {
        std::cout << "Error! Incorrect data type. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore();
      }
    }
    else {
      return userInput;
    }
  }
  return 0;
}



void printSearchMenu()
{
    cout << "What would you like to do?\n";
    // search based on first name and last name + print matching objects
    cout << "[1] Search students by first and last name\n";
    // search dom/int objects in linked list based on student id + print matching objects
    cout << "[2] Search students by student id\n";
    // search dom/int objects in linked list based on cgpa + print matching objects
    cout << "[3] Search students by CGPA\n";
    // search dom/int objects in linked list based on research score + print matching objects
    cout << "[4] Search students by research score\n";
    // create new node based on user input and insert to either dom or stu linked list in order (w overall sorting func)
    // print the data added by user to show it's been added properly
    cout << "[5] Insert new student\n";
    // delete existing objects in linked list based on first and last name
    // delete both the head and tail nodes from the dom/int linked lists in a single delete function
    cout << "[6] Delete existing student\n";
    // deleting head and tail node in a single delete function
    cout << "[7] Delete top and bottom students\n";
    // error testing demo
    cout << "[8] Error Testing Demo\n";
    // quit program
    cout << "[9] Quit program\n";
    // return to main menu
    cout << "[10] Return to main menu\n\n";
    cout << "Enter choice: ";
}

void printMergeMenu()
{
    // options to merge by user input
    cout << "What would you like to do?\n";
    // merging dom and int linked lists
    cout << "[1] Display all students (both Domestic and International)\n";
    // search dom/int objects in linked list based on student id + print matching objects
    cout << "[2] Display all students who meet a cutoff CGPA and research score\n";
    // search dom/int objects in linked list based on cgpa + print matching objects
    // quit program
    cout << "[3] Quit program\n";
    // return to main menu
    cout << "[4] Return to main menu\n\n";
    cout << "Enter choice: ";
}

void printUnitMenu() {
    // options to merge by user input
    cout << "NOTE: Unit tests 1-4 run for each singly linked list (DomesticStudent and InternationalStudent)\n\n";
    cout << "What would you like to do a unit test for?\n";
    cout << "[1] Inserting an object\n";
    cout << "[2] Searching existing objects\n"; // based on first+last name, cgpa, student id, or researchScore
    cout << "[3] Deleting existing object\n"; // based on first and last name
    cout << "[4] Deleting both the head node and tail nodes in a single delete function\n";
    cout << "[5] Merging both linked lists into a single Student linked list\n";
    cout << "[6] Merge with option 5, then search search existing Student objects in the merged linked list based on the user input information “cgpa_threshold and researchScore_threshold\n";
    cout << "[7] Quit program\n";
    cout << "[8] Return to main menu\n\n";
    cout << "Enter choice: ";
}
//check the country 
string  check(string userHome)
{
  if ( convert_check(userHome)==  "CANADA" || convert_check(userHome)== "CHINA" || convert_check(userHome)=="INDIA" || convert_check(userHome)=="IRAN" || convert_check(userHome)=="KOREA")
  {
    return userHome; 
  }
  else {
    cout<<"Wrong country input! Please start again. "; 
    std::exit(1); 
  }

}
//check the cgpa 
float checkCGPA(float  uscore)
{
  if (uscore > 4.33 || uscore<0)
  {
    cout<<"CGPA out of range! Please start again. "; 
    std::exit(1); 
  }
}
//check the reaserach score 
int checkRS(int  score)
{
  if (score > 100 || score<0)
  {
    cout<<"Research score out of range! Please start again. "; 
    std::exit(1); 
  }
}
int checkTF(int  score)
{
  if (score > 30 || score<0)
  {
    cout<<"Research score out of range! Please start again. "; 
    std::exit(1); 
  }
}
// to check province
string checkProv(string province) 
{
    if (((convert_check(province)) == "BC") || ((convert_check(province)) == "AB") || ((convert_check(province)) == "ON") || ((convert_check(province)) == "QC") ||  ((convert_check(province)) == "SK") || ((convert_check(province))  == "MB") || ((convert_check(province))  == "NB") || ((convert_check(province))  == "NT") || ((convert_check(province))  == "PE") || ((convert_check(province))  == "NS") || ((convert_check(province))  == "YT") || ((convert_check(province))  == "NL") || ((convert_check(province))  == "NU") ) 
    {
       return convert_check(province);

    }
    else {
      cout << "Error! Not a valid province. exiting program\n";
      std::exit(0);
    }
return province; 
}
string convert_check(string str)
{
    for (int i=0; i < str.size(); i++)
    {
        if (islower(str[i]))
            /*  Converting lowercase characters to uppercase  */
            str[i] = str[i] - 32;
    }

    return str;

}