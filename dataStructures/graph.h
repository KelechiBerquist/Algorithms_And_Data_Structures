#ifndef GRAPH_H
#define GRAPH_H



class Graph
{
	public:
		Graph(int V);
		void addEdge(int src, int dest, double weight);
		

	private:
		struct Vertex
		{
			std::unordered_map <int, double> adjList;
		};
		std::vector<Vertex> vertices;
		
};
// 
// 
//
Graph::Graph(int V)
{
	vertices.resize(V);
}
// 
// 
// 
//********* Create New Edge ******************//
void Graph::addEdge(int src, int dest, double weight)
{
	vertices[src].adjList[dest] = weight;
}

#endif
