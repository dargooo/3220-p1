// name: Dargo Wang, yzw0060
// partner: NONE
// filename: hw4.cpp
// due date: 09/21/2018
// collaboration: I did not use any enternal sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result
// how to compile: type in "g++ hw4.cpp" in terminal.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>
using namespace std;

//FUNCTION PROTOTYPES
int readFile(int inputArray[], ifstream& instream);
/* Input:  inputArray[] - the input array get from the file
 *         instream - ifstream instance
 * Return: size of the input array 
 */
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
/* Input:  inputArray1[] - the first input array
 *         inputArray1_size - size of first input array
 *         inputArray2[] - the second input array
 *         inputArray2_size - size of second input array
 *         outputArray[] - sorted output array from 2 input arrays
 * Return: size of the output array 
 */
void writeFile(int outputArray[], int outputArray_size, ofstream& outstream);
/* Input:  outputArray[] - the output sorted array
 *         outputArray_size - size of output array
 *         outstream - ofstream instance
 */
void sort_test();
/* This is a test driver for sort() */

const int MAX_SIZE = 1000;

int main() {
   ifstream instream;
   ofstream outstream;

   cout << "*** Unit Test Cases ***" << endl;
   sort_test();


   string fileName_1, fileName_2, outputFileName;
   int array_1[MAX_SIZE], array_2[MAX_SIZE], outputArray[MAX_SIZE];

   cout << "*** Welcome to Dargo Wang's sorting program ***" << endl;
   //FISRT
   cout << "Enter the first input file name: ";
   cin >> fileName_1;
   instream.open((char*)fileName_1.c_str());
   if (instream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   int arraySize_1 = readFile(array_1, instream);
   cout << "The list of " << arraySize_1 << " numbers in file " << fileName_1 << " is:" << endl;
   for (int i = 0; i < arraySize_1; i++)
      cout << array_1[i] << endl;
   cout << endl;
   instream.close();
   
   //SECOND
   cout << "Enter the second input file name: ";
   cin >> fileName_2;
   instream.open((char*)fileName_2.c_str());
   if (instream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   int arraySize_2 = readFile(array_2, instream);
   cout << "The list of " << arraySize_2 << " numbers in file " << fileName_2 << " is:" << endl;
   for (int j = 0; j < arraySize_2; j++)
      cout << array_2[j] << endl;
   cout << endl;
   instream.close();

   //OUTPUT
   int outputArray_size = sort(array_1, arraySize_1, array_2, arraySize_2, outputArray);
   cout << "The sorted list of " << outputArray_size << " numbers is: ";
   for (int k = 0; k < outputArray_size; k++)
      cout << outputArray[k] << " ";
   cout << endl;

   cout << "Enter the output file name: ";
   cin >> outputFileName;
   outstream.open((char*)outputFileName.c_str());
   writeFile(outputArray, outputArray_size, outstream);
   cout << "*** Please check the new file - " << outputFileName << " ***" << endl
      << "*** Goodbye. ***" << endl;
   outstream.close();
   return 0;
}


//FUNCTIONS
/* Implementation of readFile() */
int readFile(int inputArray[], ifstream& instream) {
   int i = 0;
   instream >> (inputArray[i]);
   while (! instream.eof()) {
      i++;
      instream >> inputArray[i];
   }
   return i;
}

/* Implementation of sort() */
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int i = 0, j = 0, k = 0;
   while (i < inputArray1_size && j < inputArray2_size) {
      if (inputArray1[i] < inputArray2[j]) 
         outputArray[k++] = inputArray1[i++];
      else
         outputArray[k++] = inputArray2[j++];
   }
   if (i != inputArray1_size) {
      for (int a = i; a < inputArray1_size; a++) 
         outputArray[k++] = inputArray1[a];
   }
   else if (j != inputArray2_size) {
      for (int a = j; a < inputArray2_size; a++) 
         outputArray[k++] = inputArray2[a];
   }
   return k;
}

 /* Implementation of test driver for sort() */
void sort_test() {
   cout << "Unit Test Case 1: Function Name - sort." << endl;
   int array1[MAX_SIZE] = {1, 3, 5, 7};
   int array2[MAX_SIZE] = {2, 4, 10};
   int array3[MAX_SIZE];
   int output[MAX_SIZE];

   cout << "      Case 1.1: array_1 is normal; array_2 is normal." << endl;
   assert(sort(array1, 4, array2, 3, output) == 7);
   assert(output[0] == 1);
   assert(output[1] == 2);
   assert(output[2] == 3);
   assert(output[3] == 4);
   assert(output[4] == 5);
   assert(output[5] == 7);
   assert(output[6] == 10);
   cout << "      Case 1.1 passes." << endl;

   cout << "      Case 1.2: array_1 is normal; array_2 is empty." << endl;
   assert(sort(array1, 4, array3, 0, output) == 4);
   assert(output[0] == 1);
   assert(output[1] == 3);
   assert(output[2] == 5);
   assert(output[3] == 7);
   cout << "      Case 1.2 passes." << endl;

   cout << "      Case 1.3: array_1 is empty; array_2 is normal." << endl;
   assert(sort(array3, 0, array2, 3, output) == 3);
   assert(output[0] == 2);
   assert(output[1] == 4);
   assert(output[2] == 10);
   cout << "      Case 1.3 passes." << endl;
   
   cout << "      Case 1.4: array_1 is empty; array_2 is empty." << endl;
   assert(sort(array3, 0, array3, 0, output) == 0);
   cout << "      Case 1.4 passes." << endl;

   cout << "Press any key to continue...";
   cin.ignore().get();
  
}

/* Implementation of writeFile() */
void writeFile(int outputArray[], int outputArray_size, ofstream& outstream) {
   for (int i = 0; i < outputArray_size; i++) {
      outstream << outputArray[i] << endl;
   }
}



