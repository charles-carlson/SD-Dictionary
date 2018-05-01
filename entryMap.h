#ifndef _entryMap_
#define _entryMap_
#include<iostream>
#include<fstream>
#include<string>
#include<map>
//#include<algorithim>
using namespace std;

typedef std::map<std::string, std::string> StrStrMap;
typedef std::pair<std::string, std::string> StrStrpair;

class Map
{
 protected:
  StrStrMap entries;
 public:
  Map(string fileName);

  //user enters word, this spits the word and def back to the ostream
  /*
  void display(ostream & ostr, string word)const;
  void add (
  */
  

};

#endif
