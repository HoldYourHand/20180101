 ///
 /// @file    1002_write_the_number.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-11 16:49:44
 ///
 
#include <string>
using std::string;

#include <stack>
using std::stack;

#define MAXLENGTH 100

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
namespace fjd
{ 

}	// namespace fjd


string hanyu[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int receive_and_deal()
{
		string num;
		cin >> num;
		auto c = num.begin();
		int sum = 0;
		while (c != num.end())
		{
				sum += *c - '0';
				c++;
		}

//		cout << sum << endl;

		int i;
		stack<int> out;
		while(sum)
		{
			i = sum % 10;
			out.push(i);
			sum = sum / 10;
		}

		bool first = true;
		while (!out.empty())
		{
				i = out.top();
				if (first)
				{
						first = false;
				}
				else
				{
						cout << " ";
				}
				cout << hanyu[i];
				out.pop();
		}		
		cout << endl;

		return 0;
}
 
int main()
{
receive_and_deal();

return 0;
}

