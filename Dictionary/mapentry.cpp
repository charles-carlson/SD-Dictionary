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
    cout << p.first<<':'<<'\n'<<p.second<< "\n\n\n";
  cout << "}\n";
}
void MainWindow::create_map()
{
  ifstream g("/home/users/carlso13/Dictionary/Dictionary/dict.txt");
  if(!g){
      cerr << "Not found"<<endl;
  }
  string title, def;

  while(g.good())
    {
      getline(g,title, '#');
      getline(g,def,'#');
      map1.insert(pair<string, string>(title, def));
    }
  g.close();

}

std::string MainWindow::search_map(const std::string intake){
  map<std::string,std::string>::iterator iter= map1.begin();

  iter=map1.find(intake);
  if(iter!=map1.end() ){

    return iter->second;
  }
  else{

   std::string error = "entry not found, check spelling.\n";
   return error;
  }
}
