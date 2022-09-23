"""
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 10:59:45.533096
"""
"""
Author: Davide Camponogara
InputStructure: mode, elements number, drops consentiti,
    sequence
"""

def readInput():
    file_reader=open("input.txt","r")
    file_writer=open("output.txt","w")
    
    line = file_reader.readline()
    T, N, M = map(int,line.split())
    edges=[]
    print(T, N, M)
    line = file_reader.readline().split()
    for i in range(0,N):
        edges.append(int(line[i]))
    print(edges)
    file_reader.close()
    file_writer.close()
    return T, N, M, edges

def build_dependence_chain(sequence, column):
    column[0].append([0, sequence[0],None])
    column_reached = 1
    for i in range(1,len(sequence)):
        for col in range(0,100):
            if len(column[col]) > 0:
                if(sequence[i] <= column[col][-1:][0][1]):
                    if(col!=0):
                        column[col].append([i, sequence[i], column[col-1][-1:][0][0]])
                    else:
                        column[col].append([i, sequence[i], None])
                    break
            else:
                column_reached+=1
                column[col].append([i, sequence[i], column[col-1][-1:][0][0]])
                break
    return column_reached

def find_number_of_max_sequences():
    count=0
    sequenceTemp= sequence.copy()
    columnTemp = [ [] for x in range(0,100)]
    for i in range(0,len(sequence)):
        columnTemp = [ [] for x in range(0,100)]
        sequenceTemp = sequence.copy()
        sequenceTemp.remove(sequence[i])
        colReach = build_dependence_chain(sequenceTemp, columnTemp)
        print(colReach, find_max_sequence())
        if(colReach + possible_drops != find_max_sequence()):
            count+=1
    return count

def find_max_sequence():
    if (columnReached + possible_drops)<len(sequence):
        return columnReached + possible_drops
    else:
        return len(sequence)
        
        

mode, elements_number , possible_drops, sequence = readInput()
column=[ [] for x in range(0,100)]
columnReached = build_dependence_chain(sequence, column)




if __name__ == "__main__":
    if mode==0:
        with open("output.txt","w") as fout:
            print(find_max_sequence(), file=fout)
    elif mode==1:
        with open("output.txt","w") as fout:
            print(find_number_of_max_sequences(), file=fout)
