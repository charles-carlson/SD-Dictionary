import string

#open new file to write in 
writeThes = open("newthes.txt", "w")

with open("betterThes.txt") as readThes:
    for line in readThes:
        #to remove numbers in the beginning of the line
        line = ''.join([i for i in line if not i.isdigit()])
        #remove the headers of each letter
        if not line.isupper():
            #remove empty lines
            if line[0] != ' ':
                entry = line
                #write in the terms on one line
                writeThes.write("\n&" + entry.strip('\n') + "&\n")
            else:
                syn = line
                #write in the synonyms on another line 
                writeThes.write(syn.strip(' ').strip('\n')+' ')
    
writeThes.close()
readThes.close()


