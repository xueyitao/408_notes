// DataStructionSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
using namespace std;
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//希尔排序
/*
希尔排序主要算法思想是:将整个的序列分成以d为间隔的n/d个子序列
然后使用 每次对m个子序列进行插入排序,然后让d不断变小
知道d 变成1 对整个序列进行一次插入排序
*/
void ShellSort(int arr[], int n) {
    int i, j, temp, d, k;
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (i = 0; i < d; i++)//从第一个开始依次处理步长为d的子序列
        {
            for (j = d; j < n; j += d)//开始处理该子序列
            {
                if (arr[j] < arr[j - d]) {//子序列中当前元素比前一个元素小则就将该元素前移 
                    temp = arr[j];
                    for (k = j - d; k >= 0 && temp < arr[j - d]; k = k - d)
                    {
                        arr[k + d] = arr[k];
                    }   
                    arr[k+d] = temp;
                }
            }
        }
    }
    printArr(arr, 8);
}
/**
 * 
 * 有错误版本回头记得修正
void ShellSort(int arr[], int n) {
    int i, j, temp, d, k;
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (i = 0; i < d; i++)//从第一个开始依次处理步长为d的子序列
        {
            for (j = d; j < n; j += d)//开始处理该子序列
            {
                if (arr[d] < arr[j - d]) {//子序列中当前元素比前一个元素小则就将该元素前移 
                    temp = arr[d];
                    for (k = j - d; k >= 0 && temp < arr[j - d]; k = k - d)
                    {
                        arr[k + d] = arr[k];
                    }   
                    arr[k] = temp;
                }
            }
        }
    }
    printArr(arr, 8);
}
 */
int main()
{
    int arr[] = { 49,38,65,97,76,13,27,49 };    
    ShellSort(arr, 8);

}


