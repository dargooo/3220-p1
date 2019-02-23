// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw6.cpp
// due date: 10/19/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result
// how to compile: type in "g++ hw6.cpp" in terminal.


/* choose 1 of 2 tesing versions: */
//#define UNIT_TESTING_CONSTRUCTORS
#define UNIT_TESTING_FUNCTIONS

#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>
using namespace std;

//dynamic string array pointer
typedef string* StringPtr;

//Doctor class
class Doctor {
private:
   string name;
   int numPatients;
   StringPtr patientList;
   
public:
   Doctor();
   Doctor(string nameIn, int numIn);
   /* inputs all values from the user */
   void input();
   /* outputs the name and list of all patients */
   void output();
   /* resets the number of patients to 0 and clear patientList */
   void reset();
   /* overloading operator = */
   Doctor& operator =(const Doctor& d);
   /* destrutor */
   ~Doctor() {
      patientList = NULL;
      delete [] patientList;
   }
   /* return the number of patients */
   int getNum() const {
      return numPatients;
   }
   /* return the name of doctor */
   string getName() const {
      return name;
   }
   /* return the list of patients */
   StringPtr getList() const {
      return patientList;
   }
   /* add a patient to the list */
   void addPatient(int pos, string patientName);
};
  
  //prelimitary constructor
Doctor::Doctor() {
   name = "";
   numPatients = 0;
   patientList = new string[100];
}

//constructor with parameters
Doctor::Doctor(string nameIn, int numIn) {
   name = nameIn;
   numPatients = numIn;
   patientList = new string[100];
}

//implementation of input function
void Doctor::input() {
   cout << "Enter doctor's name: ";
   getline(cin, name);
   cout << "Enter number of patients: ";
   cin >> numPatients;
   if (numPatients < 0)   exit(1);
   for (int i = 0; i < numPatients; i++) {
      string patient;
      cout << "Enter a petient name: ";
      cin >> patient;
      *(patientList + i) = patient;
   }
}

//implementation of output function
void Doctor::output() {
   cout << "Doctor: " << name << endl;
   cout << "Patients: ";
   for (int i = 0; i < numPatients - 1; i++) {
      cout << patientList[i] << ", ";
   }
   cout << patientList[numPatients - 1] << endl;
}

//implementation of reset function
void Doctor::reset() {
   name = "";
   numPatients = 0;
   delete [] patientList;
   patientList = new string[100];
}

//implementation of operator = overloading
Doctor& Doctor::operator =(const Doctor& d) {
   numPatients = d.getNum();
   for (int i = 0; i < numPatients; i++) {
      patientList[i] = d.getList()[i];
   }
   return *this;
}

//implementation of addPatient function
void Doctor::addPatient(int pos, string patientName) {
   patientList[pos] = patientName;
}
 
 //main function with 2 testing versions
int main() {
//testing constructors
#ifdef UNIT_TESTING_CONSTRUCTORS
   cout << "*** Dargo Wang's testing version -- constructors ***" << endl;
   Doctor doc1;
   assert(0 == doc1.getNum());
   cout << "      first version passes..." << endl;
   Doctor doc2("Dargo", 3);
   doc2.addPatient(0, "a");
   doc2.addPatient(1, "b");
   doc2.addPatient(2, "c");
   assert(doc2.getName() == "Dargo");
   assert(doc2.getNum() == 3);
   assert(doc2.getList()[0] == "a");
   assert(doc2.getList()[1] == "b");
   assert(doc2.getList()[2] == "c");
   cout << "      second version passes..." << endl; 
   cout << "*** end of testing version -- constructors ***" << endl;
#endif

//tesing all functions
#ifdef UNIT_TESTING_FUNCTIONS
   cout << "*** Dargo Wang's testing version -- functions ***" << endl;
   Doctor doc3;
   doc3.input();
   cout << "*** input() passes..." << endl;
   doc3.output();
   cout << "*** output() passes...if the output is same as your input" << endl;
   doc3.reset();
   assert(doc3.getName() == "");
   assert(doc3.getNum() == 0);
   cout << "*** reset() passes..." << endl;
   cout << "*** getName() passes..." << endl;
   cout << "*** getNum() passes..." << endl;
   
   Doctor doc4("Dargo", 3);
   doc4.addPatient(0, "a");
   doc4.addPatient(1, "b");
   doc4.addPatient(2, "c");
   Doctor doc5 = doc4;
   assert(doc5.getName() == "Dargo");
   assert(doc5.getNum() == 3);
   assert(doc5.getList()[0] == "a");
   assert(doc5.getList()[1] == "b");
   assert(doc5.getList()[2] == "c");
   cout << "*** addPatient() passes..." << endl;
   cout << "*** getList() passes..." << endl;
   cout << "*** operator = overloading passes..." << endl;
   cout << "*** end of testing version -- functions ***" << endl;
#endif
   return 0;
}
