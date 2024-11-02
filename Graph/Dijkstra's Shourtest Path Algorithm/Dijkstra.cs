using System;
using System.Collections.Generic;

class Program
{
    public static void Main(string[] args)
    {
        // Initialize a new graph with vertices labeled A to J
        Graph g = new Graph(new string[] { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" });

        // Add edges from vertex 0 (A) to vertices 1 (B), 2 (C), and 3 (D) with respective weights
        g.AddEdges(0, new int[] { 1, 2, 3 }, new double[] { 2, 4, 3 });

        // Add edges from vertex 1 (B) to vertices 4 (E), 5 (F), and 6 (G) with respective weights
        g.AddEdges(1, new int[] { 4, 5, 6 }, new double[] { 7, 4, 6 });
        g.AddEdges(2, new int[] { 4, 5, 6 }, new double[] { 3, 2, 4 });
        g.AddEdges(3, new int[] { 4, 5, 6 }, new double[] { 4, 1, 5 });

        // Add edges from vertices 4, 5, and 6 to vertices 7 (H) and 8 (I) with respective weights
        g.AddEdges(4, new int[] { 7, 8 }, new double[] { 1, 4 });
        g.AddEdges(5, new int[] { 7, 8 }, new double[] { 6, 3 });
        g.AddEdges(6, new int[] { 7, 8 }, new double[] { 3, 3 });

        // Add edges from vertices 7 and 8 to vertex 9 (J) with respective weights
        g.AddEdges(7, new int[] { 9 }, new double[] { 3 });
        g.AddEdges(8, new int[] { 9 }, new double[] { 4 });

        // Run Dijkstra's algorithm to find the shortest path from A to J
        g.Dijkstra();
    }

    public class Graph
    {
        private int last_index = 0;  // Index to keep track of added vertices
        public Vertex[] Vertices;    // Array to store all vertices

        // Constructor to initialize vertices based on given names
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

        // Method to add unweighted edges from a given vertex to target vertices
        public void AddEdges(int vertexIndex, int[] targets)
        {
            this.Vertices[vertexIndex].VertexLinks = new Edge[targets.Length];
            for (int i = 0; i < targets.Length; i++)
            {
                this.Vertices[vertexIndex].VertexLinks[i] =
                  new Edge(this.Vertices[vertexIndex], this.Vertices[targets[i]]);
            }
        }

        // Method to add weighted edges from a given vertex to target vertices
        public void AddEdges(int vertexIndex, int[] targets, double[] weights)
        {
            this.Vertices[vertexIndex].VertexLinks = new Edge[targets.Length];
            for (int i = 0; i < targets.Length; i++)
            {
                this.Vertices[vertexIndex].VertexLinks[i] =
                  new Edge(this.Vertices[vertexIndex], this.Vertices[targets[i]], weights[i]);
            }
        }

        // Implementation of Dijkstra's algorithm for shortest path
        public void Dijkstra()
        {
            Console.WriteLine("Dijkstra From Graph Class;");

            // Set initial distance of each vertex (except the starting vertex) to infinity
            for (int i = 1; i < this.Vertices.Length; i++)
            {
                this.Vertices[i].TotalLength = double.MaxValue;
            }

            Vertex current_vertex;
            for (int i = 0; i < this.Vertices.Length; i++)
            {
                current_vertex = this.Vertices[i];
                Edge[] destinations = current_vertex.VertexLinks;
                if (destinations == null) continue;

                Edge current_edge;
                // Update the distance to each adjacent vertex if a shorter path is found
                for (int j = 0; j < destinations.Length; j++)
                {
                    current_edge = destinations[j];
                    double new_length = current_vertex.TotalLength + current_edge.Weight;
                    if (new_length < current_edge.Target.TotalLength)
                    {
                        current_edge.Target.TotalLength = new_length;
                        current_edge.Target.SourceOfTotalLength = current_vertex;
                    }
                }
            }

            // Construct the path from start to the last vertex
            string path = this.Vertices[this.Vertices.Length - 1].Name;
            Vertex v = this.Vertices[this.Vertices.Length - 1];
            while (v.SourceOfTotalLength != null)
            {
                path = v.SourceOfTotalLength.Name + " - " + path;
                v = v.SourceOfTotalLength;
            }
            Console.WriteLine(this.Vertices[this.Vertices.Length - 1].TotalLength);
            Console.WriteLine(path);

            this.RestoreVertices();  // Reset vertex states
        }

        // BFS traversal starting from the first vertex
        public void BFS()
        {
            Console.WriteLine("BFS From Graph Class;");
            int v = Vertices.Length;
            Queue<Vertex> q = new Queue<Vertex>(v);
            q.Enqueue(this.Vertices[0]);
            this.Vertices[0].Visited = true;

            Vertex current_vertex;
            Edge[] destinations;
            while (q.Count > 0)
            {
                current_vertex = q.Dequeue();
                destinations = current_vertex.VertexLinks;
                for (int i = 0; i < destinations.Length; i++)
                {
                    if (destinations[i].Target.Visited == false)
                    {
                        q.Enqueue(destinations[i].Target);
                        destinations[i].Target.Visited = true;
                        Console.WriteLine(current_vertex.Name + " - " + destinations[i].Target.Name);
                    }
                }
            }
            RestoreVertices();  // Reset vertex states
        }

        // Method to restore vertex states after a traversal or search
        public void RestoreVertices()
        {
            foreach (Vertex v in this.Vertices)
            {
                v.Visited = false;
                v.TotalLength = 0;
                v.SourceOfTotalLength = null;
            }
        }

        // DFS traversal starting from the first vertex
        public void DFS()
        {
            Console.WriteLine("DFS From Graph Class;");
            DFSRecursion(this.Vertices[0]);
            RestoreVertices();  // Reset vertex states
        }

        // Helper function for DFS using recursion
        private void DFSRecursion(Vertex current_vertex)
        {
            current_vertex.Visited = true;
            Edge[] destinations = current_vertex.VertexLinks;
            for (int i = 0; i < destinations.Length; i++)
            {
                if (destinations[i].Target.Visited == false)
                {
                    Console.WriteLine(current_vertex.Name + " - " + destinations[i].Target.Name);
                    DFSRecursion(destinations[i].Target);
                }
            }
        }
    }

    // Vertex class representing each node in the graph
    public class Vertex
    {
        public string Name;                  // Name of the vertex
        public bool Visited;                 // Boolean flag for visitation status
        public double TotalLength;           // Total distance from source (for Dijkstra)
        public Vertex SourceOfTotalLength;   // Previous vertex in the shortest path
        public Edge[] VertexLinks;           // Array of edges (connections) to other vertices
    }

    // Edge class representing a weighted connection between vertices
    public class Edge
    {
        public double Weight;    // Weight of the edge
        public Vertex Source;    // Starting vertex of the edge
        public Vertex Target;    // Target vertex of the edge

        // Constructor to initialize an edge with an optional weight
        public Edge(Vertex source, Vertex target, double weight = 0)
        {
            this.Source = source;
            this.Target = target;
            this.Weight = weight;
        }
    }
}
