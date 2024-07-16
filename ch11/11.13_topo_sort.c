#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    int n; // 정점의 개수
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int topo_sort(GraphType *g)
{
    int i;
    StackType s;
    GraphNode *node;

    // 모든 정점의 진입 차수를 계산
    int *in_degree = (int *)malloc(g->n * sizeof(int));
    for (i = 0; i < g->n; i++) // 초기화
        in_degree[i] = 0;
    for (i = 0; i < g->n; i++)
    {
        GraphNode *node = g->adj_list[i]; // 정점 1에서 나오는 간선들
        while (node != NULL)
        {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    // 진입 차수가 0인 정점을 스택에 삽입
    init(&s);
    for (i=0; i<g->n; i++){
        if(in_degree[i] == 0) push(&s, i);
    }
    // 위상 순서를 생성
    while(!is_empty(&s)) {
        int w;
        w = pop(&s);
        printf("정점 %d ->", w);    // 정점 출력
        node = g->adj_list[w]; // 각 정점의 진입 차수를 변경
        while (node !=NULL) {
            int u=node->vertex;
            in_degree[u]--; // 진입 차수를 감소
            if (in_degree[u] ==0) push(&s, u);
            node = node->link;

        }

    }
    free(in_degree);
    printf("\n");
    return (i==g->n); // 반환값이 1이면 성공, 0이면 실패   
}