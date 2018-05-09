#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include <iostream>
#include<algorithm>
#include "mainwindow.h"

using namespace std;

void print_map(std::multimap<std::string,std::string>& m)
{

  cout << '{';
  for(auto& p: m)
    cout << p.first<<':'<<'\n'<<"DEFINITION"<<p.second<< "\n\n\n";
  cout << "}\n";

}
void MainWindow::create_map()
{
  ifstream g("/home/users/daly2/Dictionary/newDict2.txt");
  if(!g){
      cerr << "Not found"<<endl;
  }
  string title, def;

  while(g.good())
    {
      getline(g,title, '#');
      //cerr << title<<endl;
      getline(g,def,'#');
      map1.insert(pair<string, string>(title, def));
    }
  g.close();
  //print_map(map1);
}


std::string MainWindow::search_multimap(const std::string intake){
    toupper(intake[0]);
    string defn;
    multimap<string,string>::const_iterator it = map1.lower_bound(intake);
    multimap<string,string>::const_iterator it2 = map1.upper_bound(intake);
    if(map1.find(intake)==map1.end())
    {
        string str = hamming_sug(intake);
        std::string error = intake;
        error.append(" not found, check spelling\n"
                        "did you mean: ");
        error.append(str);
        return error;

    } else if(it==it2 )
    {
        return it->second;
    }else if(it!=it2)
    {
        int i =1;
        while(it !=it2)
        {
            defn.append(to_string(i));
            defn.append(it->second);
            it++;
            it++;
            /*
             * The second it++ returns the correct definions, but out of order,
             * with only one it returns the definitions in the correct order,
             * but repeats the list
             */
            i++;
        }
        return defn;
    }else
    {
         string str = hamming_sug(intake);
         string error = intake;
         error.append(" not found, check spelling\n"
                     "did you mean: ");
         error.append(str);
         return error;
    }
     /*
       std::pair<(std::multimap<std::string,std::string>::iterator),
               (std::multimap<std::string,std::string>::iterator)>
               result = map1.equal_range(intake);
       return result->first;
     */

}


std::string MainWindow::search_map(const std::string intake){
  std::multimap<std::string,std::string>::iterator iter= map1.begin();
  iter=map1.find(intake);
  if(iter!=map1.end() ){

    return iter->second;
  }
  else{
   //std::string error = "entry not found, check spelling.\n";

      string str = hamming_sug(intake);
   std::string error = intake;
   error.append(" not found, check spelling\n"
                       "did you mean: ");
   error.append(str);
   return error;
  }
}

std::string MainWindow::hamming_sug(const string intake){
    string str;
    int oldDistance=100;
    for(auto& p : map1)
    {
        int distance=100;
        if(p.first.length()==intake.length())
        {
            for(unsigned int i=0; i<intake.length(); i++)
            {
                if(intake[i]==p.first[i])
                    distance--;
            }

        }
        if(distance<=oldDistance-(intake.length()-1))
        {
            //oldDistance=distance;
            str.append(p.first);
            str.append(", ");
        }
    }
    return str;
}
