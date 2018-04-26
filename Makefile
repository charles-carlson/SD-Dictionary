#EntryArray: EntryArrayPDriver.o Entry.o
#	g++ 

#EntryArrayPDriver.o: EntryArrayPDriver.cpp
#	g++ -g -Wall -std=c++11 -c  EntryArrayPDriver.cpp  

#EntryArrayP.o: EntryArrayP.cpp	Entry.h
#	g++ -g -Wall -std=c++11 -c EntryArrayP.cpp

#######Entry######
RunEntry: Entry.o EntryDriver.o
	g++ -g -Wall -std=c++11 -o RunEntry Entry.o EntryDriver.o 

EntryDriver.o: EntryDriver.cpp Entry.cpp Entry.h
	g++ -g -Wall -std=c++11 -c EntryDriver.cpp  

Entry.o: Entry.cpp Entry.h
	g++ -g -Wall -std=c++11 -c Entry.cpp 

clean:
	rm -f *.o 
