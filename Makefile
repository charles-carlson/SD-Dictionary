entryMapDriver: entryMapDriver.o entryMap.o
	g++ -ggdb -Wall -std=c++11 -o entryMapDriver entryMapDriver.o entryMap.o

entryMapDriver.o: entryMapDriver.cpp entryMap.h
	g++ -ggdb -Wall -std=c++11 -c entryMapDriver.cpp

entryMap.o: entryMap.cpp entryMap.h
	g++  -ggdb -Wall -std=c++11 -c entryMap.cpp

########EntryArrayP##############
EntryArrayP: EntryArrayPDriver.o EntryArrayP.o Entry.o
	g++ -ggdb -Wall -std=c++11 -o EntryArrayP EntryArrayPDriver.o EntryArrayP.o Entry.o

EntryArrayPDriver.o: EntryArrayPDriver.cpp EntryArrayP.h
	g++ -ggdb -Wall -std=c++11 -c  EntryArrayPDriver.cpp  

EntryArrayP.o: EntryArrayP.cpp EntryArrayP.h Entry.h
	g++ -ggdb -Wall -std=c++11 -c EntryArrayP.cpp

#######Entry######
RunEntry: Entry.o EntryDriver.o
	g++ -ggdb -Wall -std=c++11 -o RunEntry Entry.o EntryDriver.o 

EntryDriver.o: EntryDriver.cpp Entry.cpp Entry.h
	g++ -ggdb -Wall -std=c++11 -c EntryDriver.cpp  

Entry.o: Entry.cpp Entry.h
	g++ -ggdb -Wall -std=c++11 -c Entry.cpp 

clean:
	rm -f *.o 
