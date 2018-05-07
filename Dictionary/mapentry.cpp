#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include <iostream>
#include "mainwindow.h"

using namespace std;

void print_map(std::map<std::string,std::string>& m)
{
  cout << '{';
  for(auto& p: m)
    cout << p.first<<':'<<'\n'<<"DEFINITION"<<p.second<< "\n\n\n";
  cout << "}\n";
}
void MainWindow::create_map()
{
  ifstream g("/home/users/daly2/Dictionary/newDict.txt");
  if(!g){
      cerr << "Not found"<<endl;
  }
  string title, def;

  while(g.good())
    {
      getline(g,title, '&');
      cerr << title<<endl;
      getline(g,def,'&');
      map1.insert(pair<string, string>(title, def));
    }
  g.close();
  //print_map(map1);
}

std::string MainWindow::search_map(const std::string intake){
  map<std::string,std::string>::iterator iter= map1.begin();

  iter=map1.find(intake);
  if(iter!=map1.end() ){

    return iter->second;
  }
  else{
      string str;
      int oldDistance=0;
      for(auto& p : map1)
      {
          int distance=0;
          if(p.first.length()==intake.length())
          {
              for(unsigned int i=0; i<intake.length(); i++)
              {
                  if(intake[i]!=p.first[i])
                      distance++;
              }

          }
          if(distance<=oldDistance)
          {
              oldDistance=distance;
              str=p.first;
          }
      }

   std::string error = intake;
   error.append(" not found, check spelling\n"
                       "did you mean:");
   error.append(str);
   return error;
  }
}
