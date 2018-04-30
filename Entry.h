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

<<<<<<< HEAD
  Entry(const char *);
  //up(const char *);
=======
  //check syntax of this one below
  Entry(ifstream &); //read in file - correct way? 
>>>>>>> 532e54fdf50abd51157cd5819a3a499d371c9fa7

  Entry & operator =(const Entry &); 
  string getTitle() {return title;}
  string getDef(){return def;}
  int setTitle(string); //to see if the change is successful 
  int setDef(string);  // ^^

  //testing on terminal - take out later 
<<<<<<< HEAD
  void display(ostream & ostr)const; //OpenGL - look at lab10 (file: proto-ui.cpp) - put in driver file
=======
  void display(); //not displaying in terminal, displaying GUI - diff way?
>>>>>>> 532e54fdf50abd51157cd5819a3a499d371c9fa7
};

#endif
