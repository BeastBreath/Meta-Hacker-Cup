

from optparse import Values



def creatCombinations(i, output):
    i: int
    if len(output) >= 8:
        print('\"' + output + '\", ', end="")
        #output = output[:-1]
        return
    output = output + '.'
    creatCombinations(i + 1, output)
    output = output[:-1]
    output = output + '-'
    creatCombinations(i + 1, output)

    
creatCombinations(1, "")