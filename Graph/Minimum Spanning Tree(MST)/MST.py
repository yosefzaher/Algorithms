def Prim_Minimum_Spanning_Tree():
    # List of vertices in the graph, labeled as '1' through '6'
    Vertices = ['1', '2', '3', '4', '5', '6']

    # Counter to keep track of the number of edges selected for the MST
    Selected_Edges_Count = 0

    # Number of vertices in the graph
    V = 6

    # List to track whether a vertex has been included in the MST (initialized to False)
    Selected = [False] * V
    # Start by selecting the first vertex (index 0) for the MST
    Selected[0] = True

    # Adjacency matrix representation of the graph with weights for each edge
    graph = [
        [0, 6.7, 5.2, 2.8, 5.6, 3.6],
        [6.7, 0, 5.7, 7.3, 5.1, 3.2],
        [5.2, 5.7, 0, 3.4, 8.5, 4.0],
        [2.8, 7.3, 3.4, 0, 8, 4.4],
        [5.6, 5.1, 8.5, 8, 0, 4.6],
        [3.6, 3.2, 4, 4.4, 4.6, 0]
    ]

    # Loop until we have selected V - 1 edges for the MST
    while Selected_Edges_Count < V - 1:
        # Initialize minimum edge weight to infinity for each loop iteration
        Min = float('inf')
        # Temporary variables to store the source and destination vertices of the minimum edge
        Temp_From = -1
        Temp_To = -1

        # Iterate through all vertices to find the minimum edge
        for i in range(V):
            # Only consider vertices that are already in the MST
            if Selected[i]:
                # Check edges from the selected vertex i to unselected vertices
                for j in range(V):
                    # If vertex j is not selected, and the edge weight is positive and the smallest found
                    if not Selected[j] and graph[i][j] > 0 and graph[i][j] < Min:
                        # Update minimum weight and vertices for this edge
                        Min = graph[i][j]
                        Temp_From = i
                        Temp_To = j

        # Mark the destination vertex of the minimum edge as selected
        Selected[Temp_To] = True
        # Increment the count of selected edges
        Selected_Edges_Count += 1

        # Print the selected edge and its weight
        print(f"{Vertices[Temp_From]} - {Vertices[Temp_To]} : {graph[Temp_From][Temp_To]}")

# Execute the function if this script is run directly
if __name__ == "__main__":
    Prim_Minimum_Spanning_Tree()
