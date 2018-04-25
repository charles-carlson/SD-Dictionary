#include<iostream>

EntryArrayP::EntryArrayP()
{
  numEntries=0;
  Arr=0;
}

EntryArrayP::EntryArrayP(EntryArrayP & source)
{
  source.open("dictSave.txt");
  source>>numEntries;
  Arr=new Entry[numEntries];
  for (int i =0; i< numEntries; i++)
  {
    Arr[i]=new Entry(source);
  }
}

Entry EntryArrayP::operator[](int index)
{
  return Arr[i];
}
