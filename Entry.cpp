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

Entry::Entry(const char * filename1, const char * filename2){
//read in file
  ifstream g(filename1);
=======
//read in file
Entry::Entry(const char* filename){
  ifstream g(filename);
>>>>>>> 81548dd63927e77db63c6d27cd10ea4feffdacfb
  g >> title;
  g.get();
  cout << title<< endl;
  getline(g, def);
  g.get();
 
  g.close();

//write out to a file 
  ofstream f(filename2);
  f << title << endl;
  f << def << endl;
  f.close(); 

}

void Entry::display(ostream & ostr)const{
  ostr << "Entry: " << title << "\n Definition: " << def << endl;
<<<<<<< HEAD
}
=======
>>>>>>> 81548dd63927e77db63c6d27cd10ea4feffdacfb

}
int Entry::setTitle(string t) {
  title = t; 
  return 1;
}

int Entry::setDef(string d) {
  def = d; 
  return 1; 
}
