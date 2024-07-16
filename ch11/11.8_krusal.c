#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 10000

int parent[MAX_VERTICES];

void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}

// curr가 속하는 집합을 반환
int set_find(int curr)
{
    if (parent[curr] == -1)
    {
        return curr;
    }
    while (parent[curr] != -1)
    {
        curr = parent[curr];
    }
    return curr;
}

void set_union(int a, int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2)
        parent[root1] = root2;
}
// 간선을 나타내는 구조체
struct Edge
{
    int start, end, weight
};

typedef struct GraphType
{
    int n; // 간선의 개수
    int nvertex; // 노드의 개수 추가
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// 그래프 초기화
void graph_init(GraphType *g)
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++)
    {
        g->edges[i].end = 0;
        g->edges[i].start = 0;
        g->edges[i].weight = INF;
    }
}

// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end, int w)
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

// qsort()에 사용되는 함수
int compare(const void *a, const void *b)
{
    struct Edge *x = (struct Edge *)a; // 강제 형변환
    struct Edge *y = (struct Edge *)b;
    return (x->weight - y->weight); // 양수가 나오면 x가중치가 크고 음수는 x가중치가 작다. 동일하면 같다.
}

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g){
    int edge_accepted = 0; // 현재까지 선택된 간선 수
    int uset, vset;
    struct Edge e;

    set_init(g->n); // 집합 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("크루스칼 최소 신장 트리 알고리즘 \n");
    int i = 0;
    while (edge_accepted < (g->nvertex-1)) // 간선의 수 < (n-1)
    {
        e=g->edges[i];
        uset = set_find(e.start); // 정점 u의 집합 번호
        vset = set_find(e.end); // 정점 v의 집합 번호
        if(uset != vset){
            printf(" 간선 (%d %d) %d 선택\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset); // 두개의 집합을 합친다.
        }

        i++;
    }
}