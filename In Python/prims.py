import numpy as np
def minpath(distance,visited,n):
    size = np.inf
    index = 0
    for i in range(0,n):
        if(size>distance[i] and visited[i]==False):
            size = distance[i]
            index = i
    return index
def prims(n,graph):
    visited = [False]*n
    distance = [np.inf]*n
    distance[0] = 0
    parent = [None]*n
    parent[0] = -1 
    for i in range(n):
        min = minpath(distance,visited,n)
        visited[min] = True
        for j in range(0,n):
            if(graph[min][j]>0 and visited[j]==False and distance[j]>graph[min][j]):
                distance[j] = graph[min][j]
                parent[j] = min
    print("  Edge   =  Distance")
    for i in range(1,n):
        print(parent[i]," - ",i," =    ",graph[i][parent[i]])
n = int(input("Enter no of nodes : "))
print("enter the Adjancency Matrix")
graph = np.zeros([n,n],dtype=int)
for i in range(n):
    l = list(map(int,input().split()))
    for j in range(n):
        graph[i][j] = l[j]
prims(n,graph)
