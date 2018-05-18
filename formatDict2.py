#this program was written to parse our dictionary file...take 2

import string

#create a new file to write in the output
writeDict = open("newDict2.txt", "w")

#created a variable named readDict in place of file name
with open("sqldict.txt") as readDict:
    #read in each line of the file
    for line in readDict:
        #to ignore blank lines
        if not line.isspace():
            line = line
        #m = number of characters in a line
        m = len(line)
        #n1 keeps track of the position of the term before the first left parenthesis 
        n1 = 0
        #n2 keeps track of the position of the part of speech before the right parenthesis
        n2 = 0
        
        if m > 1:
            while line[n1] != '(':
                n1 = n1+1
            #from the first letter to letter right before the left parenthesis is stored into a variable
            theWord = line[0:(n1-1)]
        
            while line[n2] != ')':
                n2 = n2+1
            #part of speech
            theMid = line[(n1):(n2+1)]
            
            #everything else is the definition 
            theDef = line[(n2+2):m]
            #splitting words in a line
            for aword in line.split(' '):
                #delete empty parentheses scattered in the doc
                if aword == "()":
                    theMid = ''
            #write out in this format 
            writeDict.write('#' + theWord + '#\n' + theMid + theDef)

#closing the files opened in the beginning of the program
writeDict.close()
readDict.close()
