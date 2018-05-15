import string

writeThes = open("newthes.txt", "w")

with open("betterThes.txt") as readThes:
    for line in readThes:
        line = ''.join([i for i in line if not i.isdigit()])
        if not line.isupper():
            if line[0] != ' ':
                entry = line
                writeThes.write("\n&" + entry.strip('\n') + "&\n")
            else:
                syn = line
                writeThes.write(syn.strip(' ').strip('\n')+' ')
    
writeThes.close()
readThes.close()


