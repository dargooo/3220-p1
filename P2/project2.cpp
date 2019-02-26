// name: Dargo Wang, yzw0060
// partner: NONE
// filename: project2.cpp
// due date: 12/7/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result
// how to compile: type in "g++ project2.cpp" in terminal.
   
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <iomanip>
#include <ctime>
using namespace std;

void press(); 
static bool exiting;
void readClient(ifstream& ins);
void readAccount(ifstream& ins);

/* class Account */
struct Account {
   int number;
   string name;
   string type;
   int balance;
};


/* class Client */
struct Client {
   string name;
   string address;
   string ssn;
   string employer;
   int income;
   Account account;
   Client *next;
};

typedef Client* ClPtr;
static ClPtr clHead;
int clNum;

/* class Staff */
class Staff {
private:
   string name;
   string password;
   string role;
   Staff *next;
public:
   Staff() {
      name = "";
      password = "";
      role = "Branch Staff";
      next = NULL;
   }
   Staff(string nameIn, string passwordIn) {
      name = nameIn;
      password = passwordIn;
      role = "Branch Staff";
      next = NULL;
   }
   string getName() const { 
      return name; }
   Staff* getNext() const { 
      return next; }
   void staffMenu();
   void changePassword();
   static void clientMenu();
   static void addClient();
   static void addAccount();
   static void editClient();
   static void editAccount();
   static void save();
   friend class System;
   friend class Administrator;
   static void displayClient(Client &c);
};

typedef Staff* StPtr;
static StPtr stHead;
int stNum;

void Staff::staffMenu() {
   cout << "      =======================================================" << endl
        << "      |        Teller Terminal System - Branch Staff        |" << endl
        << "      =======================================================" << endl 
        << "1) Client and Account Management" << endl 
        << "2) Change password" << endl 
        << "3) Exit" << endl 
        << "      Please choose an option: ";   
   int option;
   cin >> option;
   switch(option) {
      case 1:
         clientMenu();
         break;
      case 2:
         changePassword();
         break;
      default:
         exiting = true;
         break;
   }
}

void Staff::changePassword() {
   cout << "New Password: ";
   string p;
   cin >> p;
   while (p == password) {
      cout << "Error - Your new password must be different from the old one!" << endl;
      cout << "New Password: ";
      cin >> p;
   }
   password = p;
   cout << "Password was changed!" << endl;
   press();
}

void Staff::clientMenu() {
   bool back = false;
   while (!back) {
      cout << "      =======================================================" << endl
         << "      | Teller Terminal System - Client & Account Management|" << endl
         << "      =======================================================" << endl 
         << "1) Add a client" << endl
         << "2) Add an account" << endl  
         << "3) Edit client information" << endl 
         << "4) Manage an account" << endl 
         << "5) Save client and account information" << endl 
         << "6) Exit" << endl 
         << "      Please choose an option: ";
      int option;
      cin >> option;
      switch(option) {   
         case 1:
            addClient();
            break;
         case 2:
            addAccount();
            break;
         case 3:
            editClient();
            break;
         case 4:
            editAccount();
            break;
         case 5:
            save();
            break;
         default:
            back = true;
            break;
      }
   }
}

//option 1
void Staff::addClient() {
   cout << "A new client will be added: " << endl;
   
   ClPtr tempCl;
   if (clHead == NULL) {
      clHead = new Client;
      tempCl = clHead;
   }
   else {
      tempCl = clHead;
      while (tempCl->next != NULL)   tempCl = tempCl->next;
      tempCl->next = new Client;
      tempCl = tempCl->next;
   }
   
   cout << "Client name: ";
   cin >> tempCl->name;
   cout << "Address: ";
   cin >> tempCl->address;
   cout << "Social Security Number: ";
   cin >> tempCl->ssn;
   cout << "Employer: ";
   cin >> tempCl->employer;
   cout << "Annual income: ";
   cin >> tempCl->income;
      
   cout << "A new client was added!" << endl;
   press();
}

//option 2
void Staff::addAccount() {
   string name;
   ClPtr tempCl;
   while (true) {
      cout << "Choose a client: ";
      cin >> name;
      tempCl = clHead;
      while (tempCl != NULL && tempCl->name != name)  tempCl = tempCl->next;
      if(tempCl == NULL)
         cout << "Error - The client is not in the system!" << endl;
      else  
         break;
   }
   cout << "A new account will be created for " << name << " ..." << endl;
   Account a;
   a.name = name;
   cout << "Account Number: ";
   cin >> a.number;
   cout << "Acount Type: ";
   cin >> a.type;
   cout << "Balance: ";
   cin >> a.balance;
   cout << "A new account was created for " << name << "!" << endl;
   tempCl->account = a;
   press();
}

//display client info
void Staff::displayClient(Client &c) {
   cout << "Display " << c.name << "'s information" << endl
      << "     Address: " << c.address << endl
      << "     Social security number: " << c.ssn << endl
      << "     Employer: " << c.employer << endl
      << "     Annual income: " << c.income << endl;
}

//option 3
void Staff::editClient() {
   string name;
   ClPtr tempCl;
   while (true) {
      cout << "Choose a client: ";
      cin >> name;
      tempCl = clHead;
      while (tempCl != NULL && tempCl->name != name)  tempCl = tempCl->next;
      if(tempCl == NULL)
         cout << "Error - The client is not in the system!" << endl;
      else  
         break;
   }      
   displayClient(*tempCl);
   cout << "Client " << name << "'s information will be updated ..." << endl
      << "1) Confirm " << endl << "2) Cancel" << endl;
   cout << "Please choose an option: ";
   int option;
   cin >> option;
   if (option == 1) {
      cout << "Address: ";
      cin >> tempCl->address;
      cout << "Social Security Number: ";
      cin >> tempCl->ssn;
      cout << "Employer: ";
      cin >> tempCl->employer;
      cout << "Annual income: ";
      cin >> tempCl->income;
      cout << name << "'s information was updated!" << endl;
      press();
   }
}

//option 4
void Staff::editAccount() {
   int number, option, amount;
   ClPtr tempCl;
   while (true) {
      cout << "Which account will be managed? ";
      cin >> number;
      tempCl = clHead;
      while (tempCl != NULL && tempCl->account.number != number) {
         tempCl = tempCl->next;
      }
      if (tempCl != NULL)  
         break;
      cout << "Error - Account " << number << " is not in the system!" << endl
         << "1) Manage an account" << endl << "2) Cancel" << endl;
      cin >> option;
      if (option != 1)  
         return;
         
   }
   
   cout << "Manage account " << number << " for " << tempCl->name << " ..." << endl;
   while (true) {
      cout << "1) Deposit" << endl << "2) Withdraw" << endl << "3) Cancel" << endl;
      cout << "Please choose an option: ";
      cin >> option;
      if (option == 3)  
         break;
      if (option == 1) {
         cout << "Deposit Amount: ";
         cin >> amount;
         tempCl->account.balance += amount;
      }
      else if (option == 2) {
         cout << "Withdraw Amount: ";
         cin >> amount;
         tempCl->account.balance -= amount;
      }
      cout << "Balance of account " << number << " is: " << tempCl->account.balance << endl;
   }
}

//option 5
void Staff::save() {
   ofstream outs;

//write clients
   outs.open("client-info.txt");
   if (outs.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   ClPtr temp = clHead;
   while(temp != NULL) {
      outs << temp->name << endl;
      outs << temp->address << endl;
      outs << temp->ssn << endl;
      outs << temp->employer << endl;
      outs << temp->income << endl;
      temp = temp->next;
   }
   outs.close();
   cout << "Client information has been saved in the client-info file;" << endl;
   
//write accounts
   outs.open("account-info.txt");
   if (outs.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   temp = clHead;
   while(temp != NULL) {
      outs << temp->account.number << endl;
      outs << temp->account.type << endl;
      outs << temp->account.balance << endl;
      temp = temp->next;
   }
   outs.close();
   cout << "account information has been saved in the account-info file!" << endl;
   press();
}


/* class Administrator */
class Administrator {
private:
   string name;
   string password;
   string role;
   Administrator *next;
public:
   Administrator() {
      name = "";
      password = "";
      role = "System Administrator";
      next = NULL;
   }
   Administrator(string nameIn, string passwordIn) {
      name = nameIn;
      password = passwordIn;
      role = "System Administrator";
      next = NULL;
   }
   string getName() { 
      return name; }
   Administrator* getNext() const { 
      return next; }
   void adMenu();
   void client();
   void addStaff();
   void deleteStaff();
   void displayStaff();
   void changePassword();
   friend class System;
};

typedef Administrator* AdPtr;
static AdPtr adHead;
int adNum;

void Administrator::adMenu() {
   cout << "      =======================================================" << endl
        << "      |    Teller Terminal System - System Administration   |" << endl
        << "      =======================================================" << endl 
        << "1) Client and Account Management" << endl
        << "2) Add a branch staff member" << endl  
        << "3) Delete a branch staff" << endl 
        << "4) Display branch staff" << endl 
        << "5) Change password" << endl 
        << "6) Exit" << endl 
        << "      Please choose an option: ";
   int option;
   cin >> option;
   switch(option) {
      case 1:
         client();
         break;
      case 2:
         addStaff();
         break;
      case 3:
         deleteStaff();
         break;
      case 4:
         displayStaff();
         break;
      case 5:
         changePassword();
         break;
      default:
         exiting = true;
         break;
   }
}

//option 1
void Administrator::client() {
   Staff::clientMenu();
}

//option 2
void Administrator::addStaff() {
   string name, password;
   cout << "User name: ";
   cin >> name;
   cout << "Password: ";
   cin >> password;
   cout << "Role (1 - Administrator; 2 - Staff): ";
   int r;
   cin >> r;
   
   cout << "1) Confirm" << endl << "2) Cancel" << endl
      << "please choose an option: ";
   int option;
   cin >> option;
   if (option == 1) {
      //add ad
      if(r == 1) {
         AdPtr tempAd = adHead;
         while (tempAd->next != NULL)   tempAd = tempAd->next;
         tempAd->next = new Administrator;
         tempAd = tempAd->next;
         tempAd->name = name;
         tempAd->password = password;
         adNum++;
      }
      //add staff
      else {
         StPtr tempSt = stHead;
         if (stHead == NULL) {
            stHead = new Staff;
            stHead->name = name;
            stHead->password = password;
         }
         else {
            while (tempSt->next != NULL)   tempSt = tempSt->next;
            tempSt->next = new Staff;
            tempSt = tempSt->next;
            tempSt->name = name;
            tempSt->password = password;
         }
         stNum++;
      }
   
      cout << "A new branch staff member is added!" << endl
         << "User name: " << name << "    Role: ";
      if (r == 1) cout << "System Adminictrator" << endl;
      else  cout << "Branch Staff" << endl;
      press();
   }
}

//option 3
void Administrator::deleteStaff() {
   string name;
   cout << "Delete a user - User name: ";
   cin >> name;
   cout << "1) Confirm" << endl << "2) Cancel" << endl
        << "Please choose an option: ";
   int option;
   cin >> option;
   if (option == 1) {
      StPtr tempSt = new Staff("", "");
      tempSt->next = stHead;   
      while (tempSt->next != NULL) {
         if (tempSt->next->name == name)  
            break;;
         tempSt = tempSt->next;
      }
      if (tempSt->next == NULL)
         cout << "Warning - User " << name << " is not in the system. No user is deleted!" << endl;
      else {
         stNum--;
         if (tempSt->next == stHead)   stHead = stHead->next;
         else tempSt->next = tempSt->next->next;
         cout << "User " << name << " was deleted!" << endl;
      }
      press();
   }
}

//option 4
void Administrator::displayStaff() {
   int total = stNum + adNum;
   cout << "There are " << total << " users in the system." << endl;
   int i = 1;
   AdPtr tempAd = adHead;
   StPtr tempSt = stHead;
   while (tempAd != NULL) {
      cout << i++ << ". User Name: " << tempAd->name << "     Role: System Administrator" << endl;
      tempAd = tempAd->next;
   }
   while (tempSt != NULL) {
      cout << i++ << ". User Name: " << tempSt->name << "     Role: Branch Staff" << endl;
      tempSt = tempSt->next;
   }
   press();
}

//option 5
void Administrator::changePassword() {
   cout << "New Password: ";
   string p;
   cin >> p;
   while (p == password) {
      cout << "Error - Your new password must be different from the old one!" << endl;
      cout << "New Password: ";
      cin >> p;
   }
   password = p;
   cout << "Password was changed!" << endl;
   press();
}


 /* class System */
class System {
private:
   string name;
   string password;
public:
   System() {
      name = "";
      password = "";
   }
   int welcome();
   int login();
   void quit();
   friend class Administrator;
   friend class Staff;
   string getName() { 
      return name;}
   string getPassword() { 
      return password; }
};

int System::welcome() {
   cout << "      =======================================================" << endl
        << "      |     Welcome to the Auburn Branch of Tiger Bank!     |" << endl
        << "      =======================================================" << endl
        << "1) Login" << endl
        << "2) Quit" << endl
        << "      Please choose an option: ";
   int option;
   cin >> option;
   if (option == 1)  
      return 1;
   else  
      return 2;
}

int System::login() {
   cout << "      =======================================================" << endl
        << "      |     Login to Access the Teller Terminal System      |" << endl
        << "      =======================================================" << endl
        << "User name: ";
   cin >> name;
   cout << "password: ";
   cin >> password;
   
   AdPtr tempAd;
   StPtr tempSt;   
    
   while (true) {
      tempAd = adHead;
      tempSt = stHead;
      while (tempAd != NULL) {
         if (name == tempAd->name && password == tempAd->password)  
            return 1;
         tempAd = tempAd->next;
      }
      while (tempSt != NULL) {
         if (name == tempSt->name && password == tempSt->password)  
            return 2;
         tempSt = tempSt->next;
      }
      cout << "The user name or password is incorrect. Try again!" << endl;
      cout << "User name: ";
      cin >> name;
      cout << "password: ";
      cin >> password;
   }
   
   return 0;
}


int main() {
   System system = System();
   AdPtr administrator;
   StPtr staff;
   adHead = new Administrator("admin", "0000");
   stHead = NULL;
   clHead = NULL;
   adNum = 1;
   stNum = 0;
   clNum = 0;
   //read files
   ifstream ins;
   ins.open("client-info.txt");
   if (ins.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   readClient(ins);
   ins.close();
   ins.open("account-info.txt");
   if (ins.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   readAccount(ins);
   ins.close();
   //read over
   int w, id;
   while (true) {
      w = system.welcome();
      if (w != 1) 
         return 0;
      exiting = false;
      id = system.login();
      if (id == 1) {
         administrator = adHead;
         while (administrator->getName() != system.getName())   administrator = administrator->getNext();
         while (!exiting)  administrator->adMenu();
      }
      else {
         staff = stHead;
         while (staff->getName() != system.getName())   staff = staff->getNext();
         while (!exiting)  staff->staffMenu();
      }
   }
   
   return 0;
}

void press() {
   cout << "Press any key to continue... ";
   cin.ignore().get();
}

void readClient(ifstream& ins) {
   ClPtr temp = new Client;
   clHead = new Client;
   temp->next = clHead;
   while (! ins.eof()) {
      if (temp->next != clHead)
         temp->next = new Client;
      temp = temp->next;
      ins >> temp->name >> temp->address >> temp->ssn >> temp->employer >> temp->income;
   }
}

void readAccount(ifstream& ins) {
   ClPtr temp = clHead;
   while (! ins.eof()) {
      ins >> temp->account.number;
      ins >> temp->account.type;
      ins >> temp->account.balance;
      temp = temp->next;
   }
}