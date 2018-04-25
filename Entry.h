#ifndef _ENTRY_H_
#define _ENTRY_H_
#include <iostream>
#include <fstream>
#include <string>

class Entry{
 protected:
  int num; //maybe? to keep track of something?
  string title;
  string def; //definition

 public:
  Entry();
  Entry(const Entry &);
  operator =(const Entry &);
  ~Entry();
  //check syntax of this one below
  Entry(ifstream &);
  string getTitle();
  string getDef();
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^
  void display();
};

#endif
