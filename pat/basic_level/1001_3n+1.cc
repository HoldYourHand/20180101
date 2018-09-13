///
/// @file    1001_3n+1.cc
/// @author  fjd(clamfjd@gmail.com)
/// @date    2018-09-11 16:35:57
///

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace fjd
{ 

}	// namespace fjd


int callatz(int num)
{
		int times = 0;
		while (num > 1)
		{
				if (num % 2 == 0)
				{
						num /= 2;
						times++;
				}
				else
				{
						num = num * 3 + 1;
						num /= 2;
						times++;
				}
		}

		return times;
}

int main()
{

		int num;
		cin >> num;
		cout << callatz(num) << endl;

		return 0;
}

