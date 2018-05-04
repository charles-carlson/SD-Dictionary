#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
using namespace std;

template<typename Map>
void print_map(Map& m)
{
  cout << '{';
  for(auto& p: m)
    cout << p.first<<':'<<'\n'<<p.second<< "\n\n\n";
  cout << "}\n";
}
int main()
{
  typedef map<string,string>MapType;
  map<string,string> map1;
  string intake;
  ifstream g("newDict.txt");
  string title, def;
 
  while(g.good())
    {
      getline(g,title, '&');
      
      getline(g,def,'&');
      map1.insert(pair<string, string>(title, def));
    }
  g.close();
  print_map(map1);

  cin>>intake;
  MapType::iterator iter= map1.begin();
  iter=map1.find(intake);
  if(iter!=map1.end() )
    cout<< iter->second<<'\n';
  else
    cout <<"entry not found, check spelling\n";
  map1.clear();

  return 0;
}
