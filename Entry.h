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
  Entry(const Entry &);
  Entry(ifstream &);
  operator =(const Entry &);

  //check syntax of this one below
 
  string getTitle();
  string getDef();
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^
  void display();
};

#endif
