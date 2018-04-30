#ifndef _ENTRY_H_
#define _ENTRY_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Entry{
 protected:
  string title;
  string def; //definition

 public:
  Entry();
  Entry(string, string);
  Entry(const Entry &);

<<<<<<< HEAD
  //read & write file
  Entry(const char *, const char *);
=======
  Entry(const char *);
  //up(const char *);
>>>>>>> 81548dd63927e77db63c6d27cd10ea4feffdacfb

  Entry & operator =(const Entry &); 
  string getTitle() {return title;}
  string getDef(){return def;}
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^

  void display(ostream & ostr)const; //OpenGL - look at lab10 (file: proto-ui.cpp) - put in driver file
<<<<<<< HEAD

=======
>>>>>>> 81548dd63927e77db63c6d27cd10ea4feffdacfb
};

#endif
