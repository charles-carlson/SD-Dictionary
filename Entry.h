#ifndef _ENTRY_H_
#define _ENTRY_H_
#include <iostream>
#include <fstream>
#include <string>

class Entry{
 protected:
  string title;
  string def; //definition

 public:
  Entry();
  Entry(string, string);
  Entry(const Entry &);

  //check syntax of this one below
  Entry(ifstream &); 

  Entry & operator =(const Entry &); 
  string getTitle() {return title;}
  string getDef(){return def;}
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^

  //testing on terminal - take out later 
  void display(); //OpenGL - look at lab10 (file: proto-ui.cpp) - put in driver file
};

#endif
