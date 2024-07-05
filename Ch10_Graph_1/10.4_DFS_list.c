#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
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
    if (u > g->n || v > g->n)
    {
        fprintf(stderr, "정점 번호 에러");
        return;
    }

    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = NULL;

    // 10.2_adj_list.c 에서 수정된 간섭 삽입 연산
    // DFS_list를 수행하려면, 인접리스트 맨 마지막에 값을 추가하도록 해야함
    GraphNode *current = g->adj_list[u];
    if (current == NULL)
    {
        g->adj_list[u] = node;
    }
    else
    {
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = node;
    }
}

int visited[MAX_VERTICES];

// 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_list(GraphType *g, int v)
{
    GraphNode *w;
    visited[v] = TRUE;                       // 정점 v의 방문 표시
    printf("정점 %d -> ", v);                // 방문한 정점 출력
    for (w = g->adj_list[v]; w; w = w->link) // 인접 정점 탐색
        if (!visited[w->vertex])
            dfs_list(g, w->vertex); // 정점 w에서 DFS 새로 시작
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");
    dfs_list(g, 0);
    printf("\n");
    free(g);
    return 0;
}