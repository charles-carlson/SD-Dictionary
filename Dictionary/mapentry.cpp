#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include <iostream>
#include<algorithm>
#include "mainwindow.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


#include <QString>
#include <QDebug>

using namespace std;

//function to test if Dictionary is reading in, prints to cerr
void print_map(std::multimap<std::string,std::string>& m)
{

  cout << '{';
  for(auto& p: m)
    cout << p.first<<':'<<'\n'<<"DEFINITION"<<p.second<< "\n\n\n";
  cout << "}\n";

}
//fills the dictionary multimap from the .txt file
void MainWindow::create_map()
{
    //These two lines get the home directory, so the program is more portable
  std::string homedir;
  (homedir = getenv("HOME"));
  //adding the path relative to home for the Dictionary file
  std::string dict_path=homedir+"/Dictionary/Dictionary/dict.txt";
  QString Qdict_path= QString::fromStdString(dict_path);
  ifstream g(dict_path);
  if(!g){
      cerr << " Dict Not found"<<endl;
  }
  string title, def;
//reading in, then pairing key and value, then inserting into the multimap
  while(g.good())
    {
      getline(g,title, '#');

      getline(g,def,'#');
      map1.insert(pair<string, string>(title, def));
    }
  g.close();

}

//fills the thesis multimap from its .txt
void MainWindow::create_thes()
{
    //Two lines to find the home directory, then appending the relative path and opening the file
  std::string homedir;
  (homedir = getenv("HOME"));
  std::string dict_path=homedir+"/Dictionary/Dictionary/newthes.txt";
  QString Qdict_path= QString::fromStdString(dict_path);
  ifstream g(dict_path);
  if(!g){
      cerr << "thes Not found"<<endl;
  }
  string title, def;
//reading in the file, pairing the key and value, and inserting into the multimap
  while(g.good())
    {
      getline(g,title, '&');

      getline(g,def,'&');
      thes.insert(pair<string, string>(title, def));
    }

  g.close();

}

//searches the dictionary multimap for an input, returns the definitions or returns some suggestions if the entry isn't found
std::string MainWindow::search_multimap(std::string intake){
    //converts the first letter to upper case if it isnt already
    intake[0]=toupper(intake[0]);
    string defn;
    //finds the first and last occurances of the word in the dictionary
    multimap<string,string>::const_iterator it = map1.lower_bound(intake);
    multimap<string,string>::const_iterator it2 = map1.upper_bound(intake);
    //checks if the word was found in the multimap, and suggests alternatives if it wast't
    if(map1.find(intake)==map1.end())
    {

        string str = hamming_sug(intake);
        std::string error = intake;
        error.append(" not found, check spelling\n"
                        "did you mean: \n");
        error.append(str);
        return error;

    } else if(it==it2 )
    {
        //checks if there is only one definition, and returns it if true
        return it->second;
    }else if(it!=it2)
    {
        //checks for multiple definitions, and returns all of them, with an index
        int i =1;
        while(it !=it2)
        {
            defn.append(to_string(i));
            defn.append(it->second);
            it++;
            //it++;
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
        //just in case the above conditions fail, it will suggest alternatives
         string str = hamming_sug(intake);
         string error = intake;
         error.append(" not found, check spelling\n"
                     "did you mean: \n"
                      "");
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
//searhes the thesaurus multimap for an input, returns the definitions or returns some suggestions if the entry isn't found
std::string MainWindow::search_thes(std::string intake){
    intake[0]=tolower(intake[0]);
    string defn;
    multimap<string,string>::const_iterator it = thes.lower_bound(intake);
    multimap<string,string>::const_iterator it2 = thes.upper_bound(intake);
    if(thes.find(intake)==thes.end())
    {
        string str = hamming_sug(intake);
        std::string error = intake;
        error.append(" No synonyms for the word searched.\n");
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
            //it++;
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
                     "did you mean: \n"
                      "");
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
//left over from the origional simple map, searches for a word in map1 and returns the definiton, only returns one definiton from a multimap
std::string MainWindow::search_map(const std::string intake){
  std::multimap<std::string,std::string>::iterator iter= map1.begin();
  iter=map1.find(intake);
  if(iter!=map1.end() ){

    return iter->second;
  }
  else{
   //std::string error = "entry not found, check spelling.\n";

   std::string str = hamming_sug(intake);
   std::string error = intake;
   error.append(" not found, check spelling\n"
                       "did you mean: ");
   error.append(str);
   return error;
  }
}
//Suggestion function for dictionary, returns words similar to the input that are in the dictionary, based on hamming codes
std::string MainWindow::hamming_sug(const string intake){
    string str;
    string oldWord;
    int oldDistance=100;
    for(auto& p : map1)
    {
        int distance=100;
        if(p.first.length())//==intake.length())
        {
            for(unsigned int i=0; i<intake.length(); i++)
            {
                if(intake[i]==p.first[i])
                    distance--;
            }
            if(p.first.length()>intake.length())
                distance+=p.first.length()-intake.length();

        }
        //checks if the new word is the closest match to what the user input, and clears the string if it is
        if(distance<oldDistance)//-(intake.length()-1))
        {
            str.clear();
            str=p.first;
            oldWord=p.first;
            oldDistance=distance;
            /*
                for(int i=0;i<100-oldDistance;i++)
                {
                    if(strap)
                }
                */
        }
        //checks that it is not the same as the previous word and adds the new word to the end of the string
        if(oldDistance==distance)
        {
            if(p.first!=oldWord)
            {
                str.append(", ");
                str.append(p.first);
                oldWord=p.first;
            }
        }
    }
    return str;
}
//Suggestion function for thesaurus, returns words similar to the input that are in the thesaurus, based on hamming codes
std::string MainWindow::hammingThes_sug(const string intake){
    string str;
    string oldWord;
    int oldDistance=100;
    for(auto& p : thes)
    {
        int distance=100;
        if(p.first.length())//==intake.length())
        {
            for(unsigned int i=0; i<intake.length(); i++)
            {
                if(intake[i]==p.first[i])
                    distance--;
            }
            if(p.first.length()>intake.length())
                distance+=p.first.length()-intake.length();

        }
        if(distance<oldDistance)//-(intake.length()-1))
        {
            str.clear();
            str=p.first;
            oldWord=p.first;
            oldDistance=distance;
            /*
                for(int i=0;i<100-oldDistance;i++)
                {
                    if(strap)
                }
                */
        }
        if(oldDistance==distance)
        {
            if(p.first!=oldWord)
            {
                str.append(", ");
                str.append(p.first);
                oldWord=p.first;
            }
        }
    }
    return str;
}

