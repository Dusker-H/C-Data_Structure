#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int key;
    struct element *left;
    struct element *right;
} element;

typedef struct HeapType
{
    element *heap;
    int heap_size;
} HeapType;

// 생성 함수
HeapType *create_heap()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

// 초기화 함수
void init_heap(HeapType *h)
{
    h->heap = NULL;
    h->heap_size = 0;
}

// 노드 동적 생성
element *new_element(int key)
{
    element *new_node = (element *)malloc(sizeof(element));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 최소 힙이 비어있는지 검사
int is_empty(HeapType *h)
{
    return (h->heap == NULL);
}

// 특정 위치의 부모 노드를 찾는 함수
// GPT 도움
element *find_parent(element *heap, int heap_size)
{

    element *parent = heap;
    int path = heap_size;
    int bits[32];
    int i = 0;

    if (heap_size <= 3)
    {
        return parent;
    }

    // 2진수로 변환하여 저장
    while (path > 1)
    {
        bits[i++] = path % 2;
        path /= 2;
    }

    // 루트부터 경로를 따라 이동
    for (int j = i-1; j > 0; j--)
    {
        if (bits[j] == 0)
        {
            parent = parent->left;
        }
        else
        {
            parent = parent->right;
        }
    }

    return parent;
}

// 최소 힙에 아이템 추가
void insert_min_heap(HeapType *h, int key)
{
    element *new_node = new_element(key);
    if (is_empty(h))
    {
        h->heap = new_node;
        h->heap_size++;
    }
    else
    {
        int i = ++(h->heap_size);
        element *parent = find_parent(h->heap, i);

        // 새로운 노드 추가
        if (parent->left == NULL)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }

        // Min_heap 조정
        element *current = new_node;
        while (parent != NULL && parent->key > current->key)
        {
            int temp = parent->key;
            parent->key = current->key;
            current->key = temp;
            current = parent;
            if (current == h->heap)
                break;
            i /= 2;
            parent = find_parent(h->heap, i);
        }
    }
}

// 최소 힙에서 루트 아이템을 제거
// GPT 도움
int delete_min_heap(HeapType *h)
{
    int item = h->heap->key;
    if (is_empty(h))
    {
        return 0;
    }

    if (h->heap_size == 1)
    {
        h->heap = NULL;
        h->heap_size--;
        return item;
    }

    // 마지막 노드를 루트로 이동
    int i = h->heap_size;
    element *parent = find_parent(h->heap, i);
    element *last_node;
    if (i % 2 == 0)
    {
        last_node = parent->left;
        parent->left = NULL;
    }
    else
    {
        last_node = parent->right;
        parent->right = NULL;
    }
    h->heap->key = last_node->key;
    free(last_node);
    h->heap_size--;

    // heap의 특성을 유지하기 위해 조정
    element *current = h->heap;
    while (current->left != NULL)
    {
        element *child = current->left;
        if (current->right != NULL && current->right->key < current->left->key)
        {
            child = current->right;
        }
        if (current->key > child->key)
        {
            int temp = current->key;
            current->key = child->key;
            child->key = temp;
            current = child;
        }
        else
        {
            break;
        }
    }
    return item;
}

// 현재 최소 힙의 루트 아이템을 반환하는 함수
int find(HeapType *h)
{
    if (is_empty(h))
    {
        return -1;
    }
    return h->heap->key;
}

int main()
{
    HeapType *heap = create_heap();
    init_heap(heap);

    insert_min_heap(heap, 30);
    printf(" < %d >\n", heap->heap->key);
    insert_min_heap(heap, 50);
    printf(" < %d >\n", heap->heap->key);
    insert_min_heap(heap, 10);
    printf(" < %d >\n", heap->heap->key);
    insert_min_heap(heap, 20);
    printf(" < %d >\n", heap->heap->key);
    insert_min_heap(heap, 5);
    printf(" < %d >\n", heap->heap->key);

    int key = delete_min_heap(heap);
    printf("Deleted root : %d\n", key);

    key = delete_min_heap(heap);
    printf("Deleted root : %d\n", key);
    key = delete_min_heap(heap);
    printf("Deleted root : %d\n", key);
    key = delete_min_heap(heap);
    printf("Deleted root : %d\n", key);
    key = delete_min_heap(heap);
    printf("Deleted root : %d\n", key);
    return 0;
}
