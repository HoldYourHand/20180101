 ///
 /// @file    02_04_Pop_sequence.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-10 20:54:38
 ///

#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;
 
using std::cin;
 
int main()
{
		stack<int> new_stack;
		int M, N, K;

		cin >> M >> N >> K;

		int array_num, check_num;
		bool is_false;

		for (int i = 0; i != K; i++)
		{
				is_false = false;
				array_num = 1;

				for (int j = 0; j != N; j++)
				{
						cin >> check_num;
						while(new_stack.size() <= (unsigned long)M && !is_false)
						{
								if (new_stack.empty() || check_num != new_stack.top())
								{
										new_stack.push(array_num++);
								}
								else
								{
										new_stack.pop();
										break;
								}
						}
						if (new_stack.size() > (unsigned long)M)
						{
								is_false = true;
						}
				}	
				if (is_false)
				{
						cout << "NO" << endl;
				}
				else
				{
						cout << "YES" << endl;
				}
				while(new_stack.size())
				{
						new_stack.pop();
				}
		}

		return 0;
}

