

#ifndef LIFE_H_
#define LIFE_H_

#include <iostream>
#include <fstream>

#include <string>

using namespace std;

//declarations for functions

/* FUNCTION - void populateWorld

  Reads a text file into an array of string.
  Will allocate more memory as necessary.
  Assumes each line is same length

   input parms - none

   output parms - none
*/
void populateWorld(string fileName);


/* FUNCTION void showWorld

   Prints out structure as if it were 2D array of characters.

   input parms - string fileName

   output parms - none
*/
void showWorld();


/* FUNCION int numNeighbors

   Calculates the number of neighbors from a specific cell in array

   input parms - int row, int col

   output parms - int number of neighbors of the cell
*/
int numNeighbors(int row, int col);


/*FUNCTION bool applyRules

   Figures out whether next generation cell will be alive or dead.

   input parms - int row, int col, int neighbors

   output parms - true or false

*/
bool applyRules(int row, int col, int neighbors);


/* FUNCTION void iterateGeneration

   Creates next generation of cells after applying rules

   input parms - none

   output parms - none
*/
void iterateGeneration();






#endif /* LIFE_H_ */
