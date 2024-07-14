#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode
{
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct
{
    TreeNode *ptree;
    char ch;
    int key;
} element;

typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성 함수
HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제함수
element delete_min_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        // 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        // child 와 h->heap_size와 같으면 child ++ 연산하면 빈인덱스를 참조
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
        {
            child++;
        }
        if (temp.key < h->heap[child].key)
            break;
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    return node;
}

// 이진트리 제거 함수
void destroy_tree(TreeNode *root)
{
    if (root == NULL)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

int is_leaf(TreeNode *root)
{
    return !(root->left) && !(root->right);
}

void print_array(int codes[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", codes[i]);
    printf("\n");
}

void print_codes(TreeNode *root, int codes[], int top)
{

    // 1을 저장하고 순환호출한다.
    if (root->left)
    {
        codes[top] = 1;
        print_codes(root->left, codes, top + 1);
    }

    // 0을 저장하고 순환호출한다.
    if (root->left)
    {
        codes[top] = 0;
        print_codes(root->left, codes, top + 1);
    }

    // 단말노드이면 코드를 출력한다.
    if (is_leaf(root))
    {
        printf("%c: ", root->ch);
        print_array(codes, top);
    }
}

// 허프만 코드 생성 함수
void huffman_tree(int freq[], char ch_list[], int n)
{
    int i;
    TreeNode * node, *x;
    HeapType * heap;
    element e, e1, e2;
    int codes[100];
    int top=0;

    heap-create();
    init(heap);
    for(i=0; i<n; i++){
        // 최소값을 가지는 두개의 노드를 삭제
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        // 두개의 노드를 합친다.
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d + %d -> %d \n", e1.key, e2.key, e.key) ;
        insert_min_heap(heap,e);
    }
}
