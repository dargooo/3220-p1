// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw3.cpp
// due date: 09/14/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how many months it will take to pay off the loan.
// how to compile: type in "g++ hw3.cpp" in terminal.

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//FUNCTION PROTOTYPES
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive 
 *        B_alive indicates whether Bob is alive 
 *        C_alive indicates whether Charlie is alive 
 * Return: true if at least two are alive 
 *         otherwise return false 
 */  
void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 *             C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 *             Change C_alive into false if Charlie is killed.
 */
void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *        C_alive indicates whether Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 *         Change C_alive into false if Charlie is killed.
 */
void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *        B_alive indicates whether Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 *         Change B_alive into false if Bob is killed.
 */
void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 *        C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 *         Change C_alive into false if Charlie is killed.
 */
 
void press(void);
/* This is function for press any key to continue */

void test_at_least_two_alive(void);
/* This is a test driver for test_at_least_two_alive() */
void test_Aaron_shoots1(void);
/* This is a test driver for test_Aaron_shoots1 */
void test_Bob_shoots(void);
/* This is a test driver for test_Bob_shoots */
void test_Charlie_shoots(void);
/* This is a test driver for test_Charlie_shoots */
void test_Aaron_shoots2(void);
/* This is a test driver for test_Aaron_shoots2 */


//constants
const int TOTAL_RUN_TIMES = 10000;
const int A_HIT_PERCENT = 33;
const int B_HIT_PERCENT = 50;
const int C_HIT_PERCENT = 100;

int main() {
   bool A_alive = true;
   bool B_alive = true;
   bool C_alive = true;
   srand(time(0));
   
   cout << "*** Welcome to Puzzlevania's Duel Simulator ***" << endl;
   test_at_least_two_alive();
   press();
   test_Aaron_shoots1();
   press();
   test_Bob_shoots();
   press();
   test_Charlie_shoots();
   press();
   test_Aaron_shoots2();
   press();
   
   cout << "Ready to test strategy1 (run 10000 times):" << endl;
   press();
   
   double A_win1 = 0;
   double B_win1 = 0;
   double C_win1 = 0;
   int i;
   for (i = 0; i < 10000; i++) {
      A_alive = true;
      B_alive = true;
      C_alive = true;
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive)
            Aaron_shoots1(B_alive, C_alive);
         if (B_alive)
            Bob_shoots(A_alive, C_alive);
         if (C_alive)
            Charlie_shoots(A_alive, B_alive);
         cout << "...\n";
      }
      if (A_alive)  A_win1++;
      else if (B_alive)   B_win1++;
      else C_win1++;
   }
   
   cout << "Aaron won " << A_win1 << "/10000 duels or " << (A_win1 / 100) << "%" << endl;
   cout << "Bob won " << B_win1 << "/10000 duels or " << (B_win1 / 100) << "%" << endl;
   cout << "Charlie won " << C_win1 << "/10000 duels or " << (C_win1 / 100) << "%" << endl;


   cout << "\nReady to test strategy2 (run 10000 times):" << endl;
   press();
   
   double A_win2 = 0;
   double B_win2 = 0;
   double C_win2 = 0;
   int j;
   for (j = 0; j < 10000; j++) {
      A_alive = true;
      B_alive = true;
      C_alive = true;
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive)
            Aaron_shoots2(B_alive, C_alive);
         if (B_alive)
            Bob_shoots(A_alive, C_alive);
         if (C_alive)
            Charlie_shoots(A_alive, B_alive);
         cout << "...\n";
      }
      if (A_alive)  A_win2++;
      else if (B_alive)   B_win2++;
      else C_win2++;
   }
   
   cout << "Aaron won " << A_win2 << "/10000 duels or " << (A_win2 / 100) << "%" << endl;
   cout << "Bob won " << B_win2 << "/10000 duels or " << (B_win2 / 100) << "%" << endl;
   cout << "Charlie won " << C_win2 << "/10000 duels or " << (C_win2 / 100) << "%" << endl;

   if (A_win1 > A_win2)
      cout << "\nStrategy 1 is better then strategy 2." << endl;
   else
      cout << "\nStrategy 2 is better then strategy 1." << endl;
   return 0;
}


//FUNCTION DEFINITIONS

/* Implementation of press() */
void press() {
   cout << "Press any key to continue...";
   cin.ignore().get();
}

/* Implementation of at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (B_alive && C_alive) || (A_alive && C_alive))
      return true;
   else
      return false;
}

/* Implementation of Aaron_shoots1() */
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   int shoot_result = rand()%100;
   assert(B_alive || C_alive);
   if (C_alive) {
      cout << "\t\t\t\t\t\tAaron is shooting at Charlie\n";
      if (shoot_result <= A_HIT_PERCENT) {
         C_alive = false;
         cout << "\t\t\t\t\t\tCharlie is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tAaron misses.\n";
   }
   else {
      cout << "\t\t\t\t\t\tAaron is shooting at Bob\n";
      if (shoot_result <= A_HIT_PERCENT) {
         B_alive = false;
         cout << "\t\t\t\t\t\tBob is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tAaron misses.\n";
   }
}

   
/* Implementation of Bob_shoots() */
void Bob_shoots(bool& A_alive, bool& C_alive) {
   int shoot_result = rand()%100;
   assert(A_alive || C_alive);
   if (C_alive) {
      cout << "\t\t\t\t\t\tBob is shooting at Charlie\n";
      if (shoot_result <= B_HIT_PERCENT) {
         C_alive = false;
         cout << "\t\t\t\t\t\tCharlie is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tBob misses.\n";
   }
   else {
      cout << "\t\t\t\t\t\tBob is shooting at Aaron\n";
      if (shoot_result <= B_HIT_PERCENT) {
         A_alive = false;
         cout << "\t\t\t\t\t\tAaron is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tBob misses.\n";
   }
}

 /* Implementation of Charlie_shoots() */
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   int shoot_result = rand()%100;
   assert(A_alive || B_alive);
   if (B_alive) {
      cout << "\t\t\t\t\t\tCharlie is shooting at Bob\n";
      if (shoot_result <= C_HIT_PERCENT) {
         B_alive = false;
         cout << "\t\t\t\t\t\tBob is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tCharlie misses.\n";
   }
   else {
      cout << "\t\t\t\t\t\tCharlie is shooting at Aaron\n";
      if (shoot_result <= C_HIT_PERCENT) {
         A_alive = false;
         cout << "\t\t\t\t\t\tAaron is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tCharlie misses.\n";
   }
}

 /* Implementation of Aaron_shoots2() */
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   if (B_alive && C_alive) {
      cout << "\t\t\t\t\t\tAaron intentionally misses his first shot\n"
         << "\t\t\t\t\t\tBoth Bob and Charlie are alive.\n";
      return;
   }
   int shoot_result = rand()%100;
   assert(B_alive || C_alive);
   if (C_alive) {
      cout << "\t\t\t\t\t\tAaron is shooting at Charlie\n";
      if (shoot_result <= A_HIT_PERCENT) {
         C_alive = false;
         cout << "\t\t\t\t\t\tCharlie is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tAaron misses.\n";
   }
   else {
      cout << "\t\t\t\t\t\tAaron is shooting at Bob\n";
      if (shoot_result <= A_HIT_PERCENT) {
         B_alive = false;
         cout << "\t\t\t\t\t\tBob is dead.\n";
      }
      else  cout << "\t\t\t\t\t\tAaron misses.\n";
   }
}


/* Implementation of test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";

   cout << "\t\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false)); 
   cout << "\t\tCase passed ...\n";

   cout << "\t\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false)); 
   cout << "\t\tCase passed ...\n";
}

 /* Implementation of test driver for Aaron_shoots1() */
void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function – Aaron_shoots1(B_alive, C_alive)\n";
   bool bAlive, cAlive;
   
   cout << "\t\tCase 1: Bob alive, Charlie alive\n";
   bAlive = true;
   cAlive = true;
   Aaron_shoots1(bAlive, cAlive);
   assert(true == bAlive);
      
   cout << "\t\tCase 2: Bob dead, Charlie alive\n";
   bAlive = false;
   cAlive = true;
   Aaron_shoots1(bAlive, cAlive);
   assert(false == bAlive);
      
   cout << "\t\tCase 3: Bob alive, Charlie dead\n";
   bAlive = true;
   cAlive = false;
   Aaron_shoots1(bAlive, cAlive);
   assert(false == cAlive);
}

/* Implementation of test driver for Bob_shoots() */
void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function – Bob_shoots(A_alive, C_alive)\n";
   bool aAlive, cAlive;
   
   cout << "\t\tCase 1: Aaron alive, Charlie alive\n";
   aAlive = true;
   cAlive = true;
   Bob_shoots(aAlive, cAlive);
   assert(true == aAlive);
      
   cout << "\t\tCase 2: Aaron dead, Charlie alive\n";
   aAlive = false;
   cAlive = true;
   Bob_shoots(aAlive, cAlive);
   assert(false == aAlive);
      
   cout << "\t\tCase 3: Aaron alive, Charlie dead\n";
   aAlive = true;
   cAlive = false;
   Bob_shoots(aAlive, cAlive);
   assert(false == cAlive);
}

 /* Implementation of test driver for Charlie_shoots() */
void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function – Charlie_shoots(A_alive, B_alive)\n";
   bool aAlive, bAlive;
   
   cout << "\t\tCase 1: Aaron alive, Bob alive\n";
   aAlive = true;
   bAlive = true;
   Charlie_shoots(aAlive, bAlive);
   assert(true == aAlive);
      
   cout << "\t\tCase 2: Aaron dead, Bob alive\n";
   aAlive = false;
   bAlive = true;
   Charlie_shoots(aAlive, bAlive);
   assert(false == aAlive);
      
   cout << "\t\tCase 3: Aaron alive, Bob dead\n";
   aAlive = true;
   bAlive = false;
   Charlie_shoots(aAlive, bAlive);
   assert(false == bAlive);
}

 /* Implementation of test driver for Aaron_shoots2() */
void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function – Aaron_shoots2(B_alive, C_alive)\n";
   bool bAlive, cAlive;
   
   cout << "\t\tCase 1: Bob alive, Charlie alive\n";
   bAlive = true;
   cAlive = true;
   Aaron_shoots2(bAlive, cAlive);
   assert(true == (bAlive && cAlive));

   cout << "\t\tCase 2: Bob dead, Charlie alive\n";
   bAlive = false;
   cAlive = true;
   Aaron_shoots1(bAlive, cAlive);
   assert(false == bAlive);
      
   cout << "\t\tCase 3: Bob alive, Charlie dead\n";
   bAlive = true;
   cAlive = false;
   Aaron_shoots1(bAlive, cAlive);
   assert(false == cAlive); 
}
