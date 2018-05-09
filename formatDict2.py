#!/usr/bin/env python
import string

writeDict = open("newDict2.txt", "w")

with open("sqldict.txt") as readDict:
    for line in readDict:
        if not line.isspace():
            line = line
        m = len(line)
        n1 = 0
        n2 = 0
        #print(line + ' ' + ":)")
        if m > 1:
            while line[n1] != '(':
                n1 = n1+1
            theWord = line[0:(n1-1)]
        
            while line[n2] != ')':
                n2 = n2+1
            theMid = line[(n1):(n2+1)]
            
            theDef = line[(n2+2):m]
            for aword in line.split(' '):
                if aword == "()":
                    theMid = ''
            writeDict.write('#' + theWord + '#\n' + theMid + theDef)
    
writeDict.close()
readDict.close()
