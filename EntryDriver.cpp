//atm: test file for Entry
//later: use ONLY for OpenGL 

//Dictionary controls EntryArrayP & Entry files
//Interface controls OpenGL file  
//create new file to hold ALL files - Main Driver 

#include <iostream>
using namespace std;

#include "Entry.h"

int main(){
  Entry roger ("Roger", "RIP existing shooting skills");
  roger.display();

  cout <<"this is test" << endl;
  Entry test;
  test.setTitle("something");
  test.setDef("idk");
  test.display();
}
