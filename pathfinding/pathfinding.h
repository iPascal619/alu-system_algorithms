fndef __PATHFINDING_H__
#define __PATHFINDING_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graphs.h"
#include "queues.h"

#define NUM_DIRECTIONS 4
#define h(x1, y1, x2, y2)  (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))

/**
 * enum direction_s - Defines directions to move
 * @RIGHT: Move to the right (east)
 * @BOTTOM: Move downwards (south)
 * @LEFT: Move to the left (west)
 * @TOP: Move upwards (north)
 * author: Pascal Onuoha
 */
enum direction_s
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

/**
 * struct point_s - Structure to store coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x; /**< X coordinate */
	int y; /**< Y coordinate */
} point_t;


/**
 * backtracking_array - Finds a path from start ---
 * to target in a 2D array using backtracking.
 * @map: 2D array representing the map (0 is walkable, 1 is blocked)
 * @rows: Number of rows in the map
 * @cols: Number of columns in the map
 * @start: Starting coordinates
 * @target: Target coordinates
 * Return: Queue representing the path, or NULL if no path is found
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);

/**
 * backtracking_graph - Finds a path from start----
 * to target in a graph using backtracking.
 * @graph: Graph representing the map
 * @start: Starting vertex
 * @target: Target vertex
 * Return: Queue representing the path, or NULL if no path is found
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);

/**
 * dijkstra_graph - Finds a path from start----
 * to target in a graph using Dijkstra's algorithm.
 * @graph: Graph representing the map
 * @start: Starting vertex
 * @target: Target vertex
 * Return: Queue representing the path, or NULL if no path is found
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

/**
 * a_star_graph - Finds a path from start----
 * to target in a graph using A* algorithm.
 * @graph: Graph representing the map
 * @start: Starting vertex
 * @target: Target vertex
 * Return: Queue representing the path, or NULL if no path is found
 */
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
					  vertex_t const *target);

#endif /* __PATHFINDING_H__ */
