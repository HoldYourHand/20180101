 ///
 /// @file    01_02_Maximum_subsequence_sum.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-09 14:58:03
 ///
 
#include <vector>
using std::vector;

#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace fjd
{
		template<typename T>
		int Maximum_subsequence_sum(vector<T> arr)
		{
				int length = arr.size();
				int sum = 0, max_sum = -1;
				int tmp_left = 0, left = 0, right = 0;
		
				for (int i = 0; i < length; i++)
				{
						sum += arr[i];
						if (sum > max_sum)
						{
								if (tmp_left > left)		// IMPORT
								{
										left = tmp_left;
								}
								right = i;
								max_sum = sum;
						}
						if (sum < 0)
						{
								sum = 0;
								tmp_left = i + 1;
						}
				}

				if (max_sum < 0)		// all negative
				{
						max_sum = 0;
						left = 0;
						right = length - 1;
				}

				cout << max_sum << " " << arr[left] << " " << arr[right] << endl;
				return 0;
		}
		
}	// namespace fjd

int main()
{
	int K;

	scanf("%d", &K);
	
	vector<int> arr;

	while(K--)
	{
			int i;
			scanf("%d", &i);
			arr.push_back(i);
	}
	
	fjd::Maximum_subsequence_sum(arr);


}
