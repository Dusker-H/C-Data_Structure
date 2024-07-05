#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode
{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType
{
    int n; //  정점의 개수
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType *g)
{
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        g->adj_list[i] = NULL;
    }
}

// 정점삽입
void insert_vertex(GraphType *g, int n)
{
    if (n + 1 > MAX_VERTICES - 1)
    {
        fprintf(stderr, "정점개수 오류");
        return;
    }

    g->n++;
}

// 간선 삽입
void insert_edge(GraphType *g, int u, int v)
{
    if (u >= g->n || v >= g->n)
    {
        fprintf(stderr, "정점 번호 에러");
        return;
    }
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u]; // 인접리스트 맨 처음에 값이 추가 된다.
    g->adj_list[u] = node;
}

void print_adj_list(GraphType *g)
{
    for (int i = 0; i < g->n; i++)
    {
        GraphNode *p = g->adj_list[i];
        printf("정점 %d의 인접리스트", i);
        while (p != NULL)
        {
            printf("-> %d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, 1);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    print_adj_list(g);

    free(g);

    return 0;
}