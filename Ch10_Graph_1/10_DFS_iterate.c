#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top=-1;

// 공백 상태 검출 함수
int is_empty()
{
    return (top==-1);
}

// 포화 상태 검출 함수
int is_full()
{
    return (top==(MAX_STACK_SIZE -1));
}

// 삽입 함수
void push(element item)
{
    if(is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

element pop()
{
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

typedef struct GraphType
{
    int n; // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// 그래프 초기화
void init(GraphType *g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간섭 삽입 연산
void insert_edge(GraphType *g, int start, int end)
{
    if (start >= g->n || end >= g->n){
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;   
}

// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType * g, int v)
{
    int w;
    visited[v]=TRUE;
    printf("정점 %d -> ", v);
    for (w=0; w<g->n; w++)
        if(g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w); // 정점 w에서 DFS 새로 시작
}

void dfs_iterate(GraphType * g, int v)
{
    int w;
    push(v);

    while (!is_empty())
    {
        v = pop();

        if (!visited[v])
        {
            visited[v] = TRUE;
            printf("정점 %d -> ", v);

            for (w = g->n - 1; w >= 0; w--)
            {
                if (g->adj_mat[v][w] && !visited[w])
                {
                    push(w);
                }
            }
        }
    }
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i=0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색 (mat)\n");
    dfs_mat(g, 0);
    printf("\n\n");

    for (int i = 0; i < MAX_VERTICES; i++)
        visited[i] = FALSE;

    printf("깊이 우선 탐색 (iterate)\n");
    dfs_iterate(g, 0);
    printf("\n");

    free(g);
    return 0;
}
