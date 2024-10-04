
r: PAscal Onuoha
*/
#ifndef GRAPHS_H
#define GRAPHS_H

#include <stddef.h>

/**
 * enum edge_type_e - Enumerates the different types of connections between two vertices
 * @UNIDIRECTIONAL: The connection is made only in one direction
 * @BIDIRECTIONAL: The connection is made in both directions
 */
typedef enum edge_type_e
{
    UNIDIRECTIONAL = 0,
    BIDIRECTIONAL
} edge_type_t;

/* Forward declaration of vertex_t for use in edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 * @weight: Weight of the edge (for weighted graphs)
 */
typedef struct edge_s
{
    vertex_t *dest;
    struct edge_s *next;
    int weight;
} edge_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 * @index: Index of the vertex in the adjacency list
 * @content: Custom data stored in the vertex (a string)
 * @x: Vertex X coordinate
 * @y: Vertex Y coordinate
 * @nb_edges: Number of connections with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 */
struct vertex_s
{
    size_t index;
    char *content;
    int x;
    int y;
    size_t nb_edges;
    edge_t *edges;
    vertex_t *next;
};

/**
 * struct graph_s - Representation of a graph using an adjacency linked list
 * @nb_vertices: Number of vertices in the graph
 * @vertices: Pointer to the head node of the adjacency linked list
 *
 * Description:
 * All the vertices of the graph are stored in a singly linked list of vertex_t,
 * with the head pointer stored in @vertices. Each vertex has a pointer @next
 * that points to the next vertex in the list. The @next pointer does not represent
 * a connection between the two vertices. Connections between vertices are represented
 * by each vertex's singly linked list of edge_t. Each edge represents a connection
 * between the vertex and the @dest member of the edge structure. The @next member
 * of an edge points to the next edge in the linked list of edges for a given vertex.
 * Edges are unidirectional. To create a bidirectional connection between two vertices
 * A and B, create two edges: one in vertex A's edges list pointing to vertex B, and
 * another in vertex B's edges list pointing to vertex A.
 */
typedef struct graph_s
{
    size_t nb_vertices;
    vertex_t *vertices;
} graph_t;

/*
 * FUNCTIONS
 */

/**
 * graph_create - Initializes a graph structure
 * 
 * Return: A pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void);

/**
 * graph_add_vertex - Adds a vertex to a graph
 * @graph: Pointer to the graph data structure
 * @str: String representing the new vertex
 * @x: X coordinate of the vertex
 * @y: Y coordinate of the vertex
 * 
 * Return: A pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str, int x, int y);

/**
 * graph_add_edge - Adds an edge between two vertices
 * @graph: Pointer to the graph data structure
 * @src: String representing the vertex to make the connection from
 * @dest: String representing the vertex to connect to
 * @weight: Weight of the edge
 * @type: Connection type (unidirectional or bidirectional)
 * 
 * Return: 1 on success, 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, int weight, edge_type_t type);

/**
 * graph_delete - Deallocates a graph
 * @graph: Pointer to the graph to be deleted
 */
void graph_delete(graph_t *graph);

/**
 * graph_display - Utility function to display the adjacency linked list
 * @graph: Pointer to the graph structure to be displayed
 */
void graph_display(const graph_t *graph);

#endif /* GRAPHS_H */
