#include<iostream>
#include"entryMap.h"
//#include<algorithim>
using namespace std;

Map::Map(const string fileName)
{
  ifstream g(fileName);
  string title, def;
  while(g.good())
    {
      g >> title;
      g.get();
      getline(g, def);
      g.get();
      const string Title = title;
      const string Def = def;
      entries.insert(StrStrpair(title, def));
    }
  g.close();
}
/*
void Map::display(ostream & ostr, string word) const
{
  findPrefix(map, searchFor);
*/