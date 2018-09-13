 ///
 /// @file    1003_pat.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-11 18:17:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
namespace fjd
{ 

}	// namespace fjd
 
#define N 10
#define LENGTH 100

char p[N][LENGTH];

bool isPat(const char * str)
{
		int a = 0, b = 0, c = 0;
		bool P = false, A = false, T = false;

		const char *p = str;
		while (*p != '\0')
		{
				if (!P)
				{
						if (*p == 'A')
						{
								a++;
								p++;
								continue;
						}
						else if (*p == 'P')
						{
								P = true;
								p++;
								continue;
						}
						else
						{
								return false;
						}
				}
				else if(!A)
				{
						if (*p == 'A')
						{
								A = true;
								b++;
								p++;
								continue;
						}
						else if (*p == 'T')		// b == 0;
						{
								return false;
						}
						else
						{
								return false;
						}
				}
				else if (!T)
				{
						if (*p == 'A')
						{
								b++;
								p++;
								continue;
						}
						else if (*p == 'T')
						{
								T = true;
								p++;
								continue;
						}
				}
				else
				{
						if (*p == 'A')
						{
								c++;
								p++;
								continue;
						}
						else
						{
								return false;
						}
				}
		}

		if (P && A && T)
		{
				if (a * b == c)
				{
						return true;
				}
				else
				{
						return false;
				}
		}
		return false;
}

 
int main()
{
		int n;
		std::cin >> n;
		for (int i = 0; i != n; i++)
		{
				std::cin >> p[i];
		}
		for (int i = 0; i != n; i++)
		{
				if (isPat(p[i]))
				{
						cout << "YES" << endl;
				}
				else
				{
						cout << "NO" << endl;
				}
		}

		return 0;
}


