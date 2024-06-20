import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

def graph(l1,l2,L1):
    res=set()
    visited=[False]*(l2+1)

    def dfs(part,node,count,nodes):
        visited[node]=True
        for neigh in L1[node]:
            if visited[neigh]==False:
                nodes.append(neigh)
                dfs(part,neigh,count+1,nodes)
            elif neigh==part:
                if (count+1)%2!=0:
                    for i in nodes:
                        res.add(i)
                    return
            elif neigh in res:
                res.add(node)

    for i in range(len(L1)):
        dfs(i,i,0,[i])

    return ' '.join(str(x) for x in res), len(res)


tests=input()
for t in range(int(tests)):
    string = input()
    l1,l2= map(int,string.split())
    L1=[[]for _ in range(l2)]
    for i in range(int(l2)):
        string1 = input()
        a,b= map(int,string1.split())
        L1[a].append(b)
        L1[b].append(a)
    res = graph(l1,l2,L1)
    print(res[1])
    print(res[0])
