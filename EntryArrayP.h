#ifndef _EntryArrayP_
#define _EntryArrayP_
#include<iostream>
#include <fstream>
#include <string>
#include "Entry.h"
#include "EntryArrayP.h"
using namespace std;


class EntryArrayP
{
private:
  int numEntries;
  Entry ** Arr;
public:
  //default constructor
  EntryArrayP();
  //copy constructor
  EntryArrayP(const EntryArrayP & source);
  //file constructor
  EntryArrayP(string fileName);
  //index operator, returns the Entry of the index
  Entry & operator[](int index);
  //assignment operator
  EntryArrayP & operator=(const EntryArrayP & source);
  //copy entry function, the assignment operator in entry should perform this function
  //Entry copyEntry(Entry & source);
  int get_size();
  void display(ostream & ostr)const;
};

#endif
