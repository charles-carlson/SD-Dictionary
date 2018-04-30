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

  //read & write file
  Entry(const char *, const char *);

  Entry & operator =(const Entry &); 
  string getTitle() {return title;}
  string getDef(){return def;}
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^

  void display(ostream & ostr)const; //OpenGL - look at lab10 (file: proto-ui.cpp) - put in driver file

};

#endif
