#ifndef dictionary_H_ 
#define dictionary_H_ 

#include "EntryArrayP.h" 
#include "Entry.h" 
#include "Interface.h" 

class Dictionary: public Entry {
 protected: 
  int numEntries; 

 public: 

  Dictionary(); 

  Entry& search(); 
}; 

#endif 
