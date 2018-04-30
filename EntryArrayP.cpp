#include<iostream>
#include"Entry.h"
#include"EntryArrayP.h"
//default constructor
EntryArrayP::EntryArrayP()
{
  numEntries=0;
  Arr=0;
}
//copy constructor
EntryArrayP::EntryArrayP(const EntryArrayP & source)
{  
  numEntries=source.numEntries;
  Arr = new Entry * [numEntries];
  for(int i = 0; i<numEntries; i++)
    {
      Arr[i]=new Entry;
      Arr[i]=source.Arr[i];
    }
}

//file constructor
EntryArrayP::EntryArrayP(string fileName)
{
  ifstream g;
  g.open(fileName);
  g>>numEntries;
  Arr=new Entry*[numEntries];
  for (int i =0; i< numEntries; i++)
  {
    Arr[i]=new Entry((fileName.c_str()));
  }
}

Entry & EntryArrayP::operator[](int index)
{
  return *Arr[index];
}

EntryArrayP & EntryArrayP::operator=(const EntryArrayP & source)
{
  for(int i=0;i<numEntries;i++)
    {
      delete Arr[i];
      Arr[i]=NULL;
    }
  
  if (Arr)
    delete Arr;
  numEntries=source.numEntries;
  Arr = new Entry * [numEntries];
  for(int i = 0; i<numEntries; i++)
    {
      Arr[i]=new Entry;
      Arr[i]=source.Arr[i];
    }
  return *this;
}

int EntryArrayP::get_size()
{
  return numEntries;
}  

void EntryArrayP::display(ostream & ostr)const
{
  for(int i=0; i<numEntries; i++)
    {
      ostr<< i << "\t";
      Arr[i]->display(ostr);
      ostr <<endl;
    }
  return;
}
