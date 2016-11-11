#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int arr[10];
int n = 10;
void arr_recover();
void arr_print();
void swap(int& a, int& b);
void quick_sort(int left, int right);
void merge_sort(int left, int right);
void merge(int left, int mid, int right);;
void heap_sort();
void bubble_sort();
void select_sort();
void insert_sort();

int main()
{
    arr_recover();
    printf("ORIGIN ");
    arr_print();
    
    arr_recover();
    quick_sort(0, n-1);
    printf("QUICK  ");
    arr_print();
    
    arr_recover();
    merge_sort(0, n-1);
    printf("MERGE  ");
    arr_print();
    
    arr_recover();
    heap_sort();
    printf("HEAP   ");
    arr_print();
    
    arr_recover();
    bubble_sort();
    printf("BUBBLE ");
    arr_print();
    
    arr_recover();
    select_sort();
    printf("SELECT ");
    arr_print();
    
    arr_recover();
    insert_sort();
    printf("INSERT ");
    arr_print();
    
    return 0;
}

void arr_recover()
{
    arr[0] = 5; arr[1] = 2; arr[2] = 3; arr[3] = 1; arr[4] = 4;
    arr[5] = 2; arr[6] = 3; arr[7] = 5; arr[8] = 1; arr[9] = 1;
}

void arr_print()
{
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void quick_sort(int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left+right)/2];
    
    // partition
    while(i<=j) {
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    if(left < j) quick_sort(left, j);
    if(right > i) quick_sort(i, right);
}

void merge_sort(int left, int right)
{
    if(left < right) {
        int mid = (left+right)/2;
        
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}

void merge(int left, int mid, int right) 
{
    int i = left;
    int j = mid+1;
    int k = left;
    
    int tmp[n];
    while(i <= mid && j <= right) {
        if(arr[i] > arr[j]) {
            tmp[k] = arr[j];
            j++;
        } else {
            tmp[k] = arr[i];
            i++;
        }
        k++;
    }
    if(i > mid) {
        for(int l=j; l<=right; l++) {
            tmp[k] = arr[l];
            k++;
        }
    } else {
        for(int l=i; l<=mid; l++) {
            tmp[k] = arr[l];
            k++;
        }
    }
    
    for(int l=left; l<=right; l++) {
        arr[l] = tmp[l];
    }
}

// 우선순위큐(minHeap)을 이용한다
void heap_sort()
{
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        pq.push(-arr[i]);
    }
    for(int i=0; i<n; i++) {
        arr[i] = -pq.top();
        pq.pop();
    }
}

// 인접한 원소들끼리 바꾸는걸 n*n번 한다.
void bubble_sort()
{
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// i보다 큰 구간을 탐색하면서 가장 작은 index를 구하고 i와 swap 한다.
void select_sort()
{
    for(int i=0; i<n; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// i번째 원소가 0부터 i-1 까지 중 어디에 들어갈지 결정한다.
void insert_sort()
{
    for(int i=0; i<n; i++) {
        int j = i;
        while(j>0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

