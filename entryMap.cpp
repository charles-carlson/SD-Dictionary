#include<iostream>
#include"entryMap.h"
//#include<algorithim>
using namespace std;
bool all_caps(string str)
{
  int len= str.length();
  for(int i=0; i<len; i++)
    {
    if(islower(str[i]))
      return 0;
    }
  return 1;
}

Map::Map(const string fileName)
{
  
  ifstream g(fileName);
  string title, def, oldTitle;
  int i=0;
  while(g.good())
    {
      bool done;
      getline(g, title);
      if(all_caps(title))
	{
	  done=false;
	}
      else// if(!all caps)
	{
	  def.append(oldTitle);
	  oldTitle=title;
	  done=true;
	}
      if(done)
	entries.insert(StrStrpair(title, def));
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




void Map::display(ostream & ostr) const
{
  for(auto it = entries.cbegin(); it != entries.cend();++it)
    {
      ostr<< it->first<<endl<< '&' << endl
	  <<it->second<< endl<< endl;
    }
}
  //findPrefix(map, searchFor);
