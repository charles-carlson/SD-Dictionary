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
<<<<<<< HEAD
//read in file
Entry::Entry(const char * filename){
  ifstream g(filename);
  g >> title;
  g.get();
  cout << title<< endl;
  getline(g, def);
  g.get();
 
  g.close();
}
/*
//write out to a file
Entry::up(const char * filename){
  ofstream f(filename);
  f << title << endl;
  f << def << endl;

}
*/
void Entry::display(ostream & ostr)const{
  ostr << "Entry: " << title << "\n Definition: " << def << endl;
=======

Entry::Entry(ifstream & filename){ //help
}

void Entry::display(){
  cout << "Entry: " << title << "\t Definition: " << def << endl;
>>>>>>> 532e54fdf50abd51157cd5819a3a499d371c9fa7
}

int Entry::setTitle(string t) {
  title = t; 
  return 1;
}

int Entry::setDef(string d) {
  def = d; 
  return 1; 
}
