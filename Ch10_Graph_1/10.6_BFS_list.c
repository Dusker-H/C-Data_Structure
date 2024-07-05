#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct
{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define MAX_VERTICES 50
int visited[MAX_VERTICES];

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

void bfs_list(GraphType *g, int v)
{
    GraphNode *w;
    QueueType q;
    queue_init(&q);

    visited[v] = TRUE;
    printf("%d 방문 -> ", v);
    enqueue(&q, v);

    while (!is_empty(&q))
    {
        v = dequeue(&q);
        for (w = g->adj_list[v]; w; w = w->link)
        {
            if (!visited[w->vertex])
            {
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);
    printf("너비 우선 탐색\n");
    bfs_list(g, 0);
    printf("\n");
    free(g);
    return 0;
}