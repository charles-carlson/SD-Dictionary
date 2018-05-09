#include<iostream>
//#include<algorithm>
#include"entryMap.h"
using namespace std;

int main()
{
  Map map("miniDict.txt");

  map.display(cout);

  return 0;
}
