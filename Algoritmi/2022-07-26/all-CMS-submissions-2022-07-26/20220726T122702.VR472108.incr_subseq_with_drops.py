"""
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 12:27:02.103411
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
    line = file_reader.readline().split()
    for i in range(0,N):
        edges.append(int(line[i]))
    file_reader.close()
    file_writer.close()
    return T, N, M, edges

def count_max_sequences(index_elem):
    count=0
    for i in range(0,100):
        inTab=search(i, index_elem)
        if inTab!=None:
            if(i!=0):
                for e in column[i-1]:
                    if e[1] < inTab[1] and e[3]+1 == i:
                        count+=1
            break
    return count
    

def build_dependence_chain(sequence, column):
    column[0].append([0, sequence[0],None, 0])
    column_reached = 1
    max_sequence=-1
    temp_sequence=0
    count_max=0
    for i in range(1,len(sequence)):
        for col in range(0,100):
            if len(column[col]) > 0:
                if(sequence[i] <= column[col][-1:][0][1]):
                    if(col!=0):
                        column[col].append([i, sequence[i], column[col-1][-1:][0][0], column[col-1][-1:][0][3]+1])
                    else:
                        column[col].append([i, sequence[i], None,0])
                    break
            else:
                column_reached+=1
                column[col].append([i, sequence[i], column[col-1][-1:][0][0], column[col-1][-1:][0][3]+1])
                prec=column[col-1][-1:][0]
                anchestor=column[col-1][-1:][0][0]
                temp_sequence=0
                anchCol=col
                while(anchestor != None):
                    if(anchCol <= 0):
                        break
                    prec = search(anchCol-1, prec[0])
                    if prec!=None:
                        anchestor = search(anchCol-1, prec[0])[2]
                    else:
                        anchestor=None
                    
                    temp_sequence += 1
                    anchCol-=1

                    print(temp_sequence)
                if(temp_sequence>max_sequence):
                    max_sequence = temp_sequence;
                    count_max= count_max_sequences(i)
                break
    return column_reached, max_sequence, count_max

def search(column_n, index):
    for i in range(0, len(column[column_n])):
        if column[column_n][i][0] == index:
            return column[column_n][i]
    return None
    

def find_number_of_max_sequences():
    count=0
    sequenceTemp= sequence.copy()
    columnTemp = [ [] for x in range(0,100)]
    for i in range(0,len(sequence)):
        columnTemp = [ [] for x in range(0,100)]
        sequenceTemp = sequence.copy()
        sequenceTemp.remove(sequence[i])
        colReach, _, _ = build_dependence_chain(sequenceTemp, columnTemp)
        if(colReach + possible_drops != find_max_sequence()):
            count+=1
    return count

def find_max_sequence():
    if (columnReached + possible_drops) < len(sequence):
        return columnReached + possible_drops
    else:
        return len(sequence)
        
mode, elements_number , possible_drops, sequence = readInput()
column=[ [] for x in range(0,100)]
columnReached, max_sequence, count_max = build_dependence_chain(sequence, column)


if __name__ == "__main__":
    if mode==1:
            print(find_max_sequence())
    elif mode==2:
            print(count_max)
