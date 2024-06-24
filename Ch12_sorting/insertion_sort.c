#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

// 삽입 정렬 3, 5, 8, 1, 2, 7
void insertion_sort(int list[], int n)
{

    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
        list[j + 1] = key;         // why?? 위에 for문이 정상적으로 실행이되면
                                   // j-- 가 실행이 되기 때문에 index위치를 맞춰주기 위해 --연산을 실행한다
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
    insertion_sort(list, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}