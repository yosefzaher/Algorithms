def Prim_Minimum_Spanning_Tree() :

    Vertices = ['1' ,'2' ,'3' ,'4' ,'5' ,'6']

    Selected_Edges_Count = 0  

    V = 6 

    Selected = [False] * V
    Selected[0] = True

    
    graph = [
        [0, 6.7, 5.2, 2.8, 5.6, 3.6],
        [6.7, 0, 5.7, 7.3, 5.1, 3.2],
        [5.2, 5.7, 0, 3.4, 8.5, 4.0],
        [2.8, 7.3, 3.4, 0, 8, 4.4],
        [5.6, 5.1, 8.5, 8, 0, 4.6],
        [3.6, 3.2, 4, 4.4, 4.6, 0]
    ]

    while Selected_Edges_Count < V - 1 :
        
        Min = float('inf') 
        Temp_From = -1 
        Temp_To = -1 

        for i in range(V) :
            if Selected[i]  :
                for j in range(V) :
                    if not Selected[j] and graph[i][j] > 0 and graph[i][j] < Min :
                        Min = graph[i][j]
                        Temp_From = i 
                        Temp_To = j 
        
        Selected[Temp_To] = True
        Selected_Edges_Count += 1

        print(f"{Vertices[Temp_From]} - {Vertices[Temp_To]} : {graph[Temp_From][Temp_To]}")    


if __name__ == "__main__" :

    Prim_Minimum_Spanning_Tree() 

