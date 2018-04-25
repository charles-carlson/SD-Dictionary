using namespace std;
#include "Entry.h"

Entry::Entry(){
  title = "";
  def = "";
}

Entry::Entry(string name, string meaning){
  title = name;
  def = meaning;
}

Entry::Entry(const Entry & arg){
  title = arg.title;
  def = arg.def;
}

Entry::Entry(ifstream & filename){ //help
}

void Entry::display(){
  cout << "Entry: " << title << "\t Definition: " << def << endl;
}

int Entry::setTitle(string t) {
  title = t; 
  return 1;
}

int Entry::setDef(string d) {
  def = d; 
  return 1; 
}
