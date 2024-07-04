#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1; // 여기서 high+1 을 시켜주는 이유는 아래 Do while문이 등장하기 때문이다!
    pivot = list[left];
    do
    {
        do
        {
            low++;
        } while (low <= right && list[low] < pivot);

        do
        {
            high--;
        } while (high >= left && list[high] > pivot);
        if (low < high)
        {
            SWAP(list[low], list[high], temp);
        }
    } while (low < high); // low와 high이 엇갈려 지나는 순간까지 계속 반복한다.

    SWAP(list[left], list[high], temp); // 여기서 pivot 값을 가운데로
    return high;
}
void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
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
    for (i = 0; i < n; i++)
    {
        printf(" %d", list[i]);
    }
    printf("\n");
    
    quick_sort(list, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf(" %d", list[i]);
    }
    printf("\n");
    return 0;
}