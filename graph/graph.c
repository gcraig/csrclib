#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _vertex vertex_t;
typedef struct _edge edge_t;
typedef struct _graph graph_t;
typedef struct _node node_t;
typedef struct _queue queue_t;

struct _vertex {
        edge_t **edge;
        int conexions;
        int data;
        int dist;
        bool visited;
};

struct _edge {
        vertex_t *vertex;
        int weight;
};

struct _graph {
        vertex_t **vertex;
        vertex_t *curr;
};

struct _node {
        vertex_t* content;
        node_t* next;
        node_t* father;
};

struct _queue {
        unsigned int size;
        node_t *head;
        node_t *tail;
};

vertex_t* (addVertex)(int size, int data) {
        vertex_t *tmp = calloc(1, sizeof(vertex_t));

        tmp->edge = calloc(size, sizeof(edge_t));
        tmp->conexions = 0;
        tmp->data = data;
        tmp->dist = INT_MAX;
        tmp->visited = false;

        return tmp;
}

edge_t* (addEdge)(vertex_t *vertex, int weight) {
        edge_t *tmp = calloc(1, sizeof(edge_t));

        tmp->vertex = vertex;
        tmp->weight = weight;

        return tmp;
}

graph_t* (createGraph)(int size) {
        graph_t *tmp = calloc(1, sizeof(graph_t));

        tmp->vertex = calloc(size, sizeof(vertex_t));
        tmp->curr = tmp->vertex[0];

        return tmp;
}

node_t* (addNode)(vertex_t* vertex) {
        node_t *tmp = calloc(1, sizeof(node_t));

        tmp->content = vertex;
        tmp->father = tmp->next = NULL;

        return tmp;
}

queue_t* (createQueue)() {
        queue_t* tmp = calloc(1, sizeof(queue_t));

        tmp->size = 0;
        tmp->head = tmp->tail = NULL;

        return tmp;
}

void push(queue_t *queue, node_t *node) {
        if(!queue->size) {
                queue->tail = queue->head = node;
        } else {
                queue->tail->next = node;
                queue->tail = node;
        }

        ++queue->size;
}

void pop(queue_t *queue) {
        node_t *tmp = queue->head;

        if(!queue->size)
                return;
        else if(queue->size > 1)
                queue->head = queue->head->next;
        else
                queue->head = NULL;

        free(tmp);
        --queue->size;
}

node_t* (front)(queue_t *queue) {
        node_t *tmp = queue->head;
        return tmp;
}

void setEdge(vertex_t *from, vertex_t *to, int weight) {
        from->edge[from->conexions++] = addEdge(to, weight);
}

void printWeight(graph_t *graph, int size) {
        printf("From\tTo\tWeight\n");
        for(int i = 0; i < size; ++i) {
                for(int j = 0; j < graph->vertex[i]->conexions; ++j) {
                        printf("%d\t%d\t%d\n",
                        graph->vertex[i]->data,
                        graph->vertex[i]->edge[j]->vertex->data,
                        graph->vertex[i]->edge[j]->weight);
                }
        }
}

void printDistance(graph_t *graph, int size) {
        for(int count = 0; count < size; ++count)
                printf("%d %d\n", count+1, graph->vertex[count]->dist);
}

void bfs(graph_t *graph) {
        
}

int main(void) {
        int vertex, edge;
        scanf("%d%d", &vertex, &edge);

        graph_t *graph = createGraph(vertex);
        for(int count = 0; count < vertex; ++count)
                graph->vertex[count] = addVertex(edge, count+1);

        for(int count = 0; count < edge; ++count) {
                int from, to, weight;
                scanf("%d%d%d", &from, &to, &weight);
                --from;
                --to;
                setEdge(graph->vertex[from], graph->vertex[to], weight);
                setEdge(graph->vertex[to], graph->vertex[from], weight);
        }

        printWeight(graph, vertex);
        printDistance(graph, vertex);

        return 0;
}
