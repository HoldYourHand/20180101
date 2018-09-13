 ///
 /// @file    02_03_resersing_linked_list.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-10 07:47:42
 ///

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace fjd
{
		typedef struct Node * ptr_to_node;
		struct Node
		{
				int addr_of_left;		//  a 5-digit nonnegative integer
				int addr_of_right;		//	 a 5-digit nonnegative integer
				int data;
				ptr_to_node pnext;
		};		// struct Node

		class Linked_list
		{
				public:
						Linked_list()
						: head_((ptr_to_node)calloc(1, sizeof(struct Node)))
						{}

						~Linked_list()
						{
								ptr_to_node p = head_->pnext;
								while(p != NULL)
								{
										head_->pnext = p->pnext;
										free(p);
										p = head_->pnext;
								}
								free(head_);
						}

						int read_list();
						int sort_list();
						int reverse_list();
						int print_list();


				private:
						ptr_to_node head_;

		};		// class Linket_list

		int Linked_list::read_list()
		{
				scanf("%d %d %d", &head_->addr_of_left, &head_->data, &head_->addr_of_right);
				ptr_to_node pcur = head_;
				for (int i = 0; i != head_->data; i++)
				{
						ptr_to_node new_node = (ptr_to_node)calloc(1, sizeof(struct Node));
						scanf("%d %d %d", &new_node->addr_of_left, &new_node->data, &new_node->addr_of_right);
						pcur ->pnext = new_node;
						pcur = new_node;
				}
				return 0;
		}

		int Linked_list::sort_list()
		{
				if (head_->data == 1)
				{
						return 0;
				}

				ptr_to_node phead = head_;
				ptr_to_node ppre = head_;
				ptr_to_node pcur = head_->pnext;

				int addr = ppre->addr_of_left;

				while (phead->pnext != NULL)
				{
						while(pcur != NULL)
						{
								if (pcur->addr_of_left == addr)		// found
								{
										addr = pcur->addr_of_right;
	
										if(pcur == phead->pnext)		// found just next one
										{
												break;
										}

										ppre->pnext = pcur->pnext;
										pcur->pnext = phead->pnext;
										phead->pnext = pcur;

										break;
								}
								ppre = pcur;
								pcur = pcur->pnext;
						}
		
						phead = phead->pnext;
						ppre = phead;
						pcur = ppre->pnext;
						
				}

				return 0;
		}

		int Linked_list::reverse_list()
		{
				int N = head_->data;				// 0 < N <= 1e5 
				int K = head_->addr_of_right;		// 0 < K <= N
				if (N == K && K == 1)
				{
						return 0;
				}

				int times = N / K;
				int rest = N % K;

				ptr_to_node phead = head_;
			    ptr_to_node pfirst = head_->pnext;
				ptr_to_node ppre = head_;
				ptr_to_node pcur = head_->pnext;
				ptr_to_node ptmp = pcur;

				for (int i = 0; i != times; i++)
				{
						for (int j = 0; j != K; j++)
						{
								if (j == 0)
								{
										pfirst = pcur;
										ppre = ppre->pnext;
										pcur = pcur->pnext;
										continue;
								}
								ptmp = pcur->pnext;			// reverse
								pcur->pnext = ppre;
								pcur->addr_of_right = ppre->addr_of_left;
								ppre = pcur;
								pcur = ptmp;

						}
						phead->pnext = ppre;
						if (i == 0)		// head_
						{
								phead->addr_of_left = ppre->addr_of_left;
						}		
						else
						{
								phead->addr_of_right = ppre->addr_of_left;
						}

						pfirst->pnext = pcur;
						pfirst->addr_of_right = pcur->addr_of_left;

						phead = pfirst;		// for next loop
						ppre = phead;
						pcur = phead->pnext;
				}
				if (rest > 0)
				{
						return 0;
				}
				else
				{
						phead->addr_of_right = -1;
				}

				return 0;
		}

		int Linked_list::print_list()
		{
				ptr_to_node pcur = head_->pnext;
				while(NULL != pcur)
				{
						if (pcur->pnext == NULL)		// deal with -1
						{
								printf("%05d %d %d\n", pcur->addr_of_left, pcur->data, pcur->addr_of_right);
						}
						else
						{
								printf("%05d %d %05d\n", pcur->addr_of_left, pcur->data, pcur->addr_of_right);
						}
						pcur = pcur->pnext;
				}
				return 0;
		}


}		// namespace fjd

using namespace fjd;

int main()
{
//		int first_addr, N, K;		// 0 < N <= 1e5, 0 < K <= N

//		scanf("%d %d %d", &first_addr, &N, &K);

		class Linked_list list;
		
		list.read_list();
//		printf("-----  readed  ----\n");
//		list.print_list();
		
		list.sort_list();
//		printf("-----  sorted  ----\n");
//		list.print_list();

		list.reverse_list();
//		printf("-----  reversed  ----\n");
		list.print_list();


}
