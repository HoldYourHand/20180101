 ///
 /// @file    01_01_MaxSubsequence.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-07 20:53:43
 ///

#include <stdlib.h>		// void *calloc(size_t nmemb, size_t size);
#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;


namespace fjd
{

int Max3(int a, int b, int c)
{/* 返回3个整数中的最大值 */
		return (a > b) ? (a > c)? a : c : (b > c) ? b : c;
}


int DivideConquer(int * arr, int left, int right);

int GetMaxSubsequence_ByDivide(int arr[], int length)
{/* 保持与前2种算法相同的函数接口 */
		return DivideConquer(arr, 0, length - 1);
}

int DivideConquer(int * arr, int left, int right)
{ /* 分治法求List[left]到List[right]的最大子列和 */
		int max_left_sum, max_right_sum;/* 存放左右子问题的解 */
		int max_left_border_sum, max_right_border_sum;/*存放跨分界线的结果*/
		
		int left_border_sum, right_border_sum;
		int center, i;

		if(left == right) /* 递归的终止条件，子列只有1个数字 */
		{
				return arr[left] > 0 ? arr[left] : 0;
		}

		/* 下面是"分"的过程 */
		center = (left + right) / 2;/* 找到中分点 */

		/* 递归求得两边子列的最大和 */
		max_left_sum = DivideConquer(arr, left, center);
		max_right_sum = DivideConquer(arr, center + 1, right);

		/* 下面求跨分界线的最大子列和 */
		max_left_border_sum = 0;
		left_border_sum = 0;
		for (i = center; i >= left; i--) /* 从中线向左扫描 */
		{
				left_border_sum += arr[i];
				if (left_border_sum > max_left_border_sum)
				{
						max_left_border_sum = left_border_sum;
				}
		}/* 左边扫描结束 */

		/* 下面求跨分界线的最大子列和 */
		max_right_border_sum = 0;
		right_border_sum = 0;
		for (i = center + 1; i <= right; i++) /* 从中线向右扫描 */
		{
				right_border_sum += arr[i];
				if (right_border_sum > max_right_border_sum)
				{
						max_right_border_sum = right_border_sum;
				}
		}/* 右边扫描结束 */


		/* 下面返回"治"的结果 */
		return Max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

}	// namespace fjd

namespace fjd1
{
		int GetMaxSubsequence_ByOnline(int arr[], int length)
		{
				int max_sum = 0, sum = 0;
				for(int i = 0; i != length; i++)
				{
						scanf("%d", &arr[i]);
						sum += arr[i];
						if (sum > max_sum)
						{
								max_sum = sum;
						}
						if (sum < 0)
						{
								sum = 0;
						}
				}
				return max_sum;
		}
		
}	// namespace fjd1

int main()
{
	int K;
	scanf("%d", &K);

	int *arr = (int *)calloc(K, sizeof(int));
//	for (int i = 0; i < K; i++)
//	{
//			scanf("%d", &arr[i]);
//	}
//		
//	printf("%d\n", fjd::GetMaxSubsequence_ByDivide(arr, K));

	printf("%d\n", fjd1::GetMaxSubsequence_ByOnline(arr, K));

	free(arr);

	return 0;
}

