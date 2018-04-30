#include<iostream>
#include<string>
#include"EntryArrayP.h"

int main()
{
  EntryArrayP first;
  EntryArrayP second("Entries.txt");
  EntryArrayP third(second);
  first.display(cout);
  second.display(cout);
  third.display(cout);
  second[1].display(cout);
  first=second;
  first[0].setTitle("hello");
  second.display(cout);
  first.display(cout);  
  
  return 0;
}
