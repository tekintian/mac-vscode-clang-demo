#include <stdio.h>
#include <stdlib.h>
/**
 * @brief 定义一个Range类型的结构体
 * 
 */
typedef struct _Range{
    int start,end;
} Range;

Range new_range(int s, int e){
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
/** 交换变量 */
void swap(int *x,int *y){
    int t=*x;
    *x = *y;
    *y =t;
}
/**
 * @brief 在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
 * 
 * @param arr 
 * @param len 
 */
void sort_quick(int arr[], const int len){
     if (len <= 0)
        return; // 避免len等於負值時引發段錯誤（Segment Fault）
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[len];
    int p = 0;
    r[p++] = new_range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
            while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
 
            if (left <= right)
            {
                swap(&arr[left],&arr[right]);
                left++;right--;               // 移動指針以繼續
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_range(range.start, right);
        if (range.end > left) r[p++] = new_range(left, range.end);
    }
}

/* 入口函数 */
int main (int argc, char *argv[]) {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    unsigned int len = (int) sizeof(arr)/sizeof(*arr);
    sort_quick(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
   return 0;
}