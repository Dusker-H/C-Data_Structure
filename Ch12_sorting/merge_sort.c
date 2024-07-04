#include <stdio.h>

#define MAX_SIZE 10

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    // 분할 정렬된 list의 합병
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            sorted[k++] = list[i++];
        }
        else
        {
            sorted[k++] = list[j++];
        }
    }
    if (i > mid) //남아 있는 레코드의 일괄복사
    {
        for (l = j; j <= right; j++)
        {
            sorted[k++]=list[l];
        }
    }
    else // 남아 있는 레코드의 일괄복사
    {
        for (l=i; i<=mid; i++)
        {
            sorted[k++]=list[l];
        }
    }
    // 배열 sorted[]의 리스트를 배열 list[]로 재복사
    for (l=left; l<=right; l++){ // l은 0으로 둬도 상관없음!
        list[l]=sorted[l];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;         // 리스트의 균등 분할
        merge_sort(list, left, mid);      // 부분 리스트 정렬
        merge_sort(list, mid + 1, right); // 부분 리스트 정렬
        merge(list, left, mid, right);    // 합병
    }
}