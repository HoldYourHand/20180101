#ifndef __MYQUICKSORT_H__
#define __MYQUICKSORT_H__

namespace fjd
{
    template <typename T>
    int myQuickSort(T *arr, int start, int end)
    {
        //
        T mid = arr[start];
        int left = start, right = end;

        while(left < right)
        {
            while(left < right&& mid <= arr[right])
            {
                --right;
            }
            if (left < right)
            {
                arr[left++] = arr[right];
            }
            while(left < right&& mid >= arr[left])
            {
                ++left;
            }
            if (left < right)
            {
                arr[right--] = a[left];
            }
        }

        arr[left] = mid;
        myQuickSort(arr, start, left - 1);
        myQuickSort(arr, left + 1, end);

  
        return 0;
    }
}

#endif