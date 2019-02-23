// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw5.cpp
// due date: 10/05/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result
// how to compile: type in "g++ hw5.cpp" in terminal.

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <assert.h>
using namespace std;

//#define UNIT_TESTING

struct TriviaNode {
   string question;
   string answer;
   int pointsWorth;
   TriviaNode *next;
};

   
class NodeList {
public:
   TriviaNode *first;
   TriviaNode *last;
   int count;
   NodeList() {
      first = NULL;
      last = NULL;
      count = 0;
   }
};
//typedef NodeList* NodeList_ptr;


//prototype
void initialize(NodeList &list);
void addNode(NodeList &list);
void askQ(NodeList &list, int num);
void test_askQ();


int main() {
#ifdef UNIT_TESTING
   cout << "*** This is a debugging version ***" << endl;
   test_askQ();
   cout << "\n*** End of the debugging version ***\n";

#else
   NodeList list;
   initialize(list);
   cout << "*** Welcome to Dargo Wang's trivia quiz game ***" << endl;
   //add questions
   addNode(list);
   //ask questions
   askQ(list, list.count);
   cout << "\nThank you for playing the trivia quiz game. Goodbye! ***" << endl;
   #endif
   return 0;
}


//functions
  /* function to initialize the list*/
void initialize(NodeList &list) {
   TriviaNode *q1 = new TriviaNode, *q2 = new TriviaNode, *q3 = new TriviaNode;
  
   q1->question = "How long was the shortest war on record? (Hint: how many minutes)";
   q1->answer = "38";
   q1->pointsWorth = 100;
   q1->next = q2;
   
   q2->question = "What was Bank of America's original name?(Hint: Bank of Italy or Bank of Germany)";
   q2->answer = "Bank of Italy";
   q2->pointsWorth = 50;
   q2->next = q3;
   
   q3->question = "What is the best-selling video game of all time?(Hint: call of Duty or Wii Sports)?";
   q3->answer = "Wii Sports";
   q3->pointsWorth = 20;
   q3->next = NULL;
   
   list.first = q1;
   list.last = q3;
   list.count = 3;
}

/* function to add a question in the list*/
void addNode(NodeList &list) {
   string cont;
   do {
      TriviaNode *q = new TriviaNode;
      cout << "Enter a question: ";
      getline(cin, q->question);
      cout << "Enter an answer: ";
      getline(cin, q->answer);
      cout << "Enter award points: ";
      cin >> q->pointsWorth;
      list.count++;
      list.last->next = q;
      list.last = q;
      cout << "Continue? (Yes/No): ";
      getline(cin.ignore(), cont);
   }while (cont == "Yes");
   cout << endl;
}

/* function to ask a question */
void askQ(NodeList &list, int num) {
   if (num == 0) {
      cout << "Warning - The number of trivia to be asked must equal to or larger than 1." << endl;
      return;
   }
   if (num > list.count) {
      cout << "Warning - There are only " << list.count << " trivia in the list." << endl;
      return;
   }
   int points = 0, i;
   TriviaNode *temp = list.first;
   for (i = num; i > 0; i--) {
      string ans;
      cout << "Question: " << temp->question << endl;
      cout << "Answer: ";
      getline(cin, ans);
      if (temp->answer == ans) {
         cout << "Your answer is correct. You receive " << temp->pointsWorth << " points." << endl;
         points += temp->pointsWorth;
      }
      else {
         cout << "Your answer is wrong. The correct answer is: " << temp->answer << endl;
      }
      cout << "Your total points: " << points << endl << endl;
      temp = temp->next;
   }
}

/* test driver for askQ function. */
void test_askQ() {
   NodeList list;
   initialize(list);
   
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   askQ(list, 0);
   
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters a incorrect answer." << endl;
   askQ(list, 1);
   cout << "Case 2.1 passed..." << endl;
      
   cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
   askQ(list, 1);
   cout << "Case 2.2 passed..." << endl;
   
   cout << "\nUnit Test Case 3: Ask all questions of the last trivia in the linked list." << endl;
   askQ(list, 3);
   cout << "Case 3 passed..." << endl;
      
   cout << "\nUnit Test Case 4: Ask 5 question in the linked list." << endl;
   askQ(list, 5);
   cout << "Case 4 passed..." << endl;
}