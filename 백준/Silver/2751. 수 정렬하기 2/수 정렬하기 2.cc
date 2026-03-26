#include <iostream>
#include <cstdlib>
using namespace std;

int a[1000000];

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1;
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid)
    {
        for(i=rIdx; i<=right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        for(i=fIdx; i<=mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for(i=left; i<=right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left+right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    MergeSort(a, 0, N-1);

    for(int i=0; i<N; i++) {
        cout << a[i] << '\n';
    }
}