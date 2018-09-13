///
/// @file    02_01_Merge_two_sorted_linked_list.cc
/// @author  fjd(clamfjd@gmail.com)
/// @date    2018-09-09 16:08:52
///

#include <iostream>
using std::cout;
using std::endl;

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
		ElementType Data;
		PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
		List L1, L2, L;
		L1 = Read();
		L2 = Read();
		L = Merge(L1, L2);
		Print(L);
		Print(L1);
		Print(L2);
		return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
		PtrToNode ptr_to_L1 = L1->Next;
		PtrToNode ptr_to_L2 = L2->Next;
		PtrToNode L = (PtrToNode)calloc(1, sizeof(struct Node));
		PtrToNode ptr_to_L = L;

		ElementType n1, n2;
		while (ptr_to_L1 != NULL && ptr_to_L2 != NULL)
		{
				n1 = ptr_to_L1->Data;
				n2 = ptr_to_L2->Data;
				if (n1 <= n2)
				{
						ptr_to_L->Next = ptr_to_L1;	
						
						L1->Next = ptr_to_L1->Next;
						ptr_to_L1->Next = NULL;
						ptr_to_L1 = L1->Next;

						ptr_to_L = ptr_to_L->Next;

				}
				else if (n1 > n2)
				{
						ptr_to_L->Next = ptr_to_L2;

						L2->Next = ptr_to_L2->Next;
						ptr_to_L2->Next = NULL;
						ptr_to_L2 = L2->Next;

						ptr_to_L = ptr_to_L->Next;
				}
		}

		if (L1->Next != NULL)
		{
				ptr_to_L->Next = L1->Next;
				L1->Next = NULL;
		}

		if (L2->Next != NULL)
		{
				ptr_to_L->Next = L2->Next;
				L2->Next = NULL;
		}

		return L;
}
