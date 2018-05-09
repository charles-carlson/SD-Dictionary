#!/usr/bin/env python
import string

writeDict = open("newDict.txt", "w")

with open("dictionary.txt") as readDict:
    for line in readDict:
        if line.isupper():
            temp = "\n&" +line.rstrip('\n')+ "& \n"
        else:
            temp = line.replace('\n', ' ')
        writeDict.write(temp)

writeDict.close()
