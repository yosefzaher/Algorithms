using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main(string[] args)
    {
        // Initialize a graph with vertex names
        Graph g = new Graph(new string[] { "A", "B", "C", "D", "E", "F", "G", "H", "I" });
        
        // Add edges to each vertex by specifying the target vertices
        g.AddEdges(0, new int[] { 1, 2 });
        g.AddEdges(1, new int[] { 0, 3, 4 });
        g.AddEdges(2, new int[] { 0, 3, 5 });
        g.AddEdges(3, new int[] { 1, 2, 4 });
        g.AddEdges(4, new int[] { 1, 5 });
        g.AddEdges(5, new int[] { 2, 3, 4, 7 });
        g.AddEdges(6, new int[] { 7, 8 });
        g.AddEdges(7, new int[] { 5, 6, 8 });
        g.AddEdges(8, new int[] { 6, 7 });

        // Perform Breadth-First Search (BFS) traversal starting from the first vertex
        g.BFS();
    }

    // Class representing a vertex in the graph
    public class Vertex
    {
        public string Name;      // Name of the vertex (e.g., "A", "B", etc.)
        public bool Visited;     // Flag to mark if the vertex has been visited
        public Edge[] VertexLinks; // Array of edges linking to other vertices
    }

    // Class representing an edge between two vertices
    public class Edge
    {
        public double Weight;    // Weight of the edge (default is 0)
        public Vertex Source;    // Source vertex of the edge
        public Vertex Target;    // Target vertex of the edge

        // Constructor to initialize an edge between a source and target vertex with an optional weight
        public Edge(Vertex source, Vertex target, double weight = 0)
        {
            this.Source = source;
            this.Target = target;
            this.Weight = weight;
        }
    }

    // Class representing the graph structure
    public class Graph
    {
        private int last_index = 0; // Counter for vertices as they are added
        public Vertex[] Vertices;   // Array holding all vertices in the graph

        // Constructor to initialize the graph with vertex names
        public Graph(string[] names)
        {
            Vertices = new Vertex[names.Length];
            foreach (string name in names)
            {
                this.Vertices[last_index] = new Vertex();
                this.Vertices[last_index].Name = name;
                last_index++;
            }
        }

        // Method to add edges for a given vertex by specifying target indices
        public void AddEdges(int vertexIndex, int[] targets)
        {
            // Initialize edges for the vertex at vertexIndex
            this.Vertices[vertexIndex].VertexLinks = new Edge[targets.Length];
            for (int i = 0; i < targets.Length; i++)
            {
                // Create a new edge from the current vertex to each target vertex
                this.Vertices[vertexIndex].VertexLinks[i] =
                    new Edge(this.Vertices[vertexIndex], 
                             this.Vertices[targets[i]]);
            }
        }
    
        // Breadth-First Search (BFS) traversal method
        public void BFS()
        {
            Console.WriteLine("BFS From Graph Class;");
            int v = Vertices.Length;

            // Queue to manage BFS traversal, starting with the first vertex
            Queue<Vertex> q = new Queue<Vertex>(v);
            q.Enqueue(this.Vertices[0]);
            this.Vertices[0].Visited = true;

            Vertex current_vertex;
            Edge[] destinations;

            // Loop while there are vertices in the queue
            while (q.Count > 0)
            {
                // Dequeue the current vertex and retrieve its edges
                current_vertex = q.Dequeue();
                destinations = current_vertex.VertexLinks;

                // Iterate over all edges of the current vertex
                for (int i = 0; i < destinations.Length; i++)
                {
                    // If the target vertex of the edge has not been visited
                    if (!destinations[i].Target.Visited)
                    {
                        // Enqueue the target vertex, mark it as visited, and print the edge
                        q.Enqueue(destinations[i].Target);
                        destinations[i].Target.Visited = true;
                        Console.WriteLine(current_vertex.Name + " - "
                                          + destinations[i].Target.Name);
                    }
                }
            }

            // Reset all vertices' visited status after BFS is complete
            RestoreVertices();
        }

        // Method to reset the visited status of all vertices in the graph
        public void RestoreVertices()
        {
            foreach (Vertex v in this.Vertices)
            {
                v.Visited = false;
            }
        }
    }     
}
