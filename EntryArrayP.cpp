#include<iostream>
//default constructor
EntryArrayP::EntryArrayP()
{
  numEntries=0;
  Arr=0;
}
//copy constructor
EntryArrayP::EntryArrayP(EntryArrayP & source)
{
  if(Arr)
    {
      for(int i=0; i<numEntries; i++)
	{
	  delete Arr[i];
	}
    }
  
  numEntries=source.numEntries;
  for(int i = 0; i<numEntries; i++)
    {
      Arr*[i]=source.Arr[i];
    }
}

}
//file constructor
EntryArrayP::EntryArrayP(string fileName)
{
  ifstream g;
  g.open(fileName);
  g>>numEntries;
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
