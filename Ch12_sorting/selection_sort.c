#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
// SWAP매크로 다음에 띄어쓰기하면 오류가 발생함 주의
int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (j = i + 1; j < n; j++) // 최소 값 탐색
        {
            if (list[j] < list[least])
            {
                least = j;
            }
        }
        if (i != least) // 이미 정렬된 자료의 경우 자신과의 이동을 막기 위해
        {
            SWAP(list[i], list[least], temp);
        }
    }
}

int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 100;
    }
    selection_sort(list, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}