
/**********************************
File Name: life.cpp

Authors: L. Provvidente and V. Robertson
Date: March 3, 2015
Problem Number: 4
CS 2308 Spring 2015
Instructor: R. Priebe

This is the source file for the game of life.
In conjunction with the header and the driver files,
it will print to the screen subsequent generations
following certain survival rules.
**********************************/

#include <iostream>
#include <fstream>
#include <unistd.h>

#include "life.h"

using namespace std;

string *world;

int numRows;
int numCols;

void populateWorld(string fileName){

   const int SIZE_INCREMENT = 3;
   char line[80];
   numRows = 1;
   numCols = 1;

   ifstream inFile;
   inFile.open(fileName.data());

   world = new string[SIZE_INCREMENT];

   while (inFile.getline(line, 80)) {
      world[numRows] = line;
      numCols = (world[numRows].length())+1;

      numRows++;

      if (numRows % SIZE_INCREMENT == 0) {
         string *tempWorld = new string[numRows + SIZE_INCREMENT];

         for (int i = 0; i < numRows; i++) {
            tempWorld[i] = world[i];
         }
      delete [] world;

      world = tempWorld;
      for (int  row = 0; row < numRows; row++) {
         world[row][0] = '0';
         world[row][numCols+1] = '0';
      }
      for (int col = 0; col < numCols; col++) {
         world[numRows+1][col] = '0';
         world[0][col] ='0'; }
      }
   }
}

void showWorld() {

   sleep(1);

   for (int row = 1; row < numRows; row++) {
      for (int col = 1; col < numCols; col++) {
         cout << world[row][col];
      }
      cout << endl;
   }
   cout << endl;
}

int numNeighbors(int row, int col) {

   int sum = 0;

   if (world[row+1][col-1] == '1')
      sum ++;
   if (world[row+1][col] == '1')
      sum ++;
   if (world[row+1][col+1] == '1')
      sum ++;
   if (world[row][col-1] == '1')
      sum ++;
   if (world[row][col+1] == '1')
      sum ++;
   if (world[row-1][col-1] == '1')
      sum ++;
   if (world[row-1][col] == '1')
      sum ++;
   if (world[row-1][col+1] == '1')
      sum ++;

   return sum;
}

bool applyRules(int row, int col, int neighbors) {

   bool newCell = false;

   if (world[row][col] == '0') { // cell is dead
      if (neighbors == 3)
         newCell = true;
   }
   else { // cell is alive
      if (neighbors == 2 || neighbors == 3)
         newCell = true;
   }

   return newCell;
}

void iterateGeneration() {

   string *newWorld = new string[numRows];

   for (int row = 1; row < numRows; row++) {
      string temp = "";

   for (int col = 1; col < numCols; col++) {

   if (world[row][col] == '0')       temp += '1';

   else
      temp += '0';
   }

   newWorld[row] = temp;
   }

   delete [] world;

   world = newWorld;

   return;
}



