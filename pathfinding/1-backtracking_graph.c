nclude "pathfinding.h"

/**
 * recursive_backtrack_graph - Recursive backtracking function for graphs.
 * @path: Pointer to the current path queue.
 * @visited: Array of vertices already visited.
 * @current: Pointer to the current vertex.
 * @target: Pointer to the target vertex.
 * author: Pascal Onuoha
 * Return: 1 on success, 0 on failure.
 */
int recursive_backtrack_graph(queue_t **path, int *visited,
vertex_t const *current, vertex_t const *target)
{
	char *city;
	edge_t *edges;

	if (current == NULL || visited[current->index] == 1)
		return (0);

	printf("Checking %s\n", current->content);

	if (strcmp(current->content, target->content) == 0)
	{
		city = strdup(current->content);
		queue_push_front(*path, city);
		return (1);
	}

	visited[current->index] = 1;

	for (edges = current->edges; edges; edges = edges->next)
	{
		if (recursive_backtrack_graph(path, visited, edges->dest, target))
		{
			city = strdup(current->content);
			queue_push_front(*path, city);
			return (1);
		}
	}

	visited[current->index] = 0;
	return (0);
}

/**
 * backtracking_graph - Searches for the first path
 * from a starting point to a target point in a graph.
 * @graph: Pointer to the graph to traverse.
 * @start: Pointer to the starting vertex.
 * @target: Pointer to the target vertex.
 *
 * Return: Queue in which each node is a char *
 * corresponding to a vertex, forming a path from start to target.
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
vertex_t const *target)
{
	int *visited = NULL;
	int success;
	queue_t *path;

	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	if (!path)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
	{
		queue_delete(path);
		return (NULL);
	}

	success = recursive_backtrack_graph(&path, visited, start, target);
	free(visited);

	if (success)
		return (path);

	queue_delete(path);
	return (NULL);
}
