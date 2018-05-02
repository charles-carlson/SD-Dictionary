#include<iostream>
#include"entryMap.h"
//#include<algorithim>
using namespace std;

Map::Map(const string fileName)
{
  
  ifstream g(fileName);
  string title, def, oldTitle;
  int i=0;
  while(g.good())
    {
      bool done;
      getline(g, title);
      if(std::any_of(std::begin(title), std::end(title), [](char c)
		{return (islower(c));}))
	{
	  done=true;
	}
      else// if(!all caps)
	{
	  def.append(oldTitle);
	  oldTitle=title;
	  done=false;
	}
      if(done)
	entries.insert(StrStrpair(title, def));
      i++;
      if(i<10)
	cout << title << '&'<< endl <<  def << endl<<endl;
    }
	  
  /*
  int i=0;
  string temp( (istreambuf_iterator<char>(g) ),
	       (istreambuf_iterator<char>() ) );
  //read(g,temp);
  string delimiter = "Defn:";
  string token;
  size_t pos = 0;
  while ((pos=temp.find(delimiter))!= string::npos)
    {
      title = temp.substr(0,10);
      def = temp.substr(0,pos);
      temp.erase(0, pos+delimiter.length());
      entries.insert(StrStrpair(title, def));
    }
  /*
  for(int i=0;i<100;i++)
    {
      string token=temp.substr(0,temp.find(delimiter));
    }
  */
  /*
  while(g.good())
    {
      g >> title;
      //getline(g, temp);
      //getline(g, temp);
      //g.get();
      while (g.good())
	{
	  g>>temp;
	  cout <<"hi";
	  if(temp.compare("Defn:")==1)
	    {
	      cout<< "bye";
	      break;
	    }
	}
      
      getline(g, def);
      g.get();
  */
    //entries.insert(StrStrpair(title, def));
  g.close();
}



/*
void Map::display(ostream & ostr, string word) const
{
  findPrefix(map, searchFor);
*/
