 ///
 /// @file    Maximum_Subsequence_Sum_1.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-07-22 14:39:04
 ///

#include <vector>

#include <iostream>
using std::cout;
using std::endl;

namespace fjd
{

using std::vector;

template<typename T>
int Maximum_Subsequence_Sum(vector<T> array, int num)
{
		T maxsum = -1;
		T thissum = 0;
		int front = 0, end = 0;
		int front_tmp = 0;
		bool allNegtive = true;
		for (int i = 0; i != num; i++)
		{
				if (allNegtive && array[i] >= 0)
				{
						allNegtive = false;
				}
				thissum += array[i];
				if(thissum > maxsum)
				{
						maxsum = thissum;
						end = i;
						front = front_tmp;
				}
				else if (thissum < 0)
				{
						thissum = 0;
						front_tmp = i + 1;
				}
		}

		if (allNegtive)
		{
			maxsum = 0;
			front = 0;
			end = num - 1;
		}

	    cout << maxsum << " " << array[front] << " " << array[end];
		return 0;

}

}//fjd

using namespace fjd;

int main(int argc, char** argv)
{
//		for(int i = 0; i < argc; i++)
//		{
//				cout << argv[i] << " ";
//		}
//		cout << endl;

		int sum;
// 	while((std::cin >> sum))
//	{
		std::cin >> sum;
		vector<int> arr(sum);
		if (sum <= 0)
		{
				return -1;
		}

		int mem;
		arr.clear();
		for (int j = 0; j < sum; j++)
		{
				std::cin >> mem;
				arr.push_back(mem);
//				arr[j] = mem;
		}

		Maximum_Subsequence_Sum<int>(arr, arr.size());

//	}

		return 0;
}





