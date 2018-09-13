 ///
 /// @file    1004_top_and_bottom_student_info.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-11 19:00:46
 ///

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace fjd
{ 

}	// namespace fjd
 
#define MAX_LENGTH 10

struct student_info
{
		char name[MAX_LENGTH + 1];
		char num[MAX_LENGTH + 1]; 
		int grade;
};		// struct student_info

int copy(struct student_info *left, const struct student_info * right)
{
		strcpy(left->name, right->name);
		strcpy(left->num, right->num);
		left->grade = right->grade;
		return 0;
}

int main()
{
		int n;
		std::cin >> n;
		struct student_info top, tail, tmp;
		std::cin >> top.name >> top.num >> top.grade;
		copy(&tail, &top);

		for (int i = 1; i < n; i++)
		{
				std::cin >> tmp.name >> tmp.num >> tmp.grade;
				if (tmp.grade > top.grade)
				{
						copy(&top, &tmp);
				}
				if (tmp.grade < tail.grade)
				{
						copy(&tail, &tmp);
				}
		}

		cout << top.name << " " << top.num << endl;
		cout << tail.name << " " << tail.num << endl;

return 0;
}

