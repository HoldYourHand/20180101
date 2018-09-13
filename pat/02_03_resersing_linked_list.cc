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
				int addr_of_left;		//   a 5-digit nonnegative integer
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

		int Linked_list::sort_list()		// remove extra usless node
		{
				if (head_->data == 1)
				{
						return 0;
				}

				ptr_to_node phead = head_;
				ptr_to_node ppre = head_;
				ptr_to_node pcur = head_->pnext;

				int addr = ppre->addr_of_left;

				int real_sum = 0;

				while (phead->pnext != NULL)
				{
						while(pcur != NULL)
						{
								if (pcur->addr_of_left == addr)		// found
								{
										addr = pcur->addr_of_right;
	
										if(pcur == phead->pnext)		// found just next one
										{
												real_sum++;
												break;
										}

										ppre->pnext = pcur->pnext;
										pcur->pnext = phead->pnext;
										phead->pnext = pcur;

										real_sum++;
										break;
								}
								ppre = pcur;
								pcur = pcur->pnext;
						}
		
						phead = phead->pnext;
						ppre = phead;
						pcur = ppre->pnext;
						
				}
				head_->data = real_sum;

				return 0;
		}

		int Linked_list::reverse_list()
		{
				int N = head_->data;				// 0 < N <= 1e5 
				int K = head_->addr_of_right;		// 0 < K <= N
				if (K == 1)
				{
						return 0;
				}

				ptr_to_node previous_node = head_;
				ptr_to_node current_node = previous_node->pnext;
				ptr_to_node next_node = current_node->pnext;

				ptr_to_node head_node = head_;
				ptr_to_node nexthead_node = head_->pnext;

				for (int i = 0; i < N / K; i++)
				{

						if (i > 0)
						{
						//		previous_node = nexthead_node;
								current_node = next_node;
								next_node = next_node->pnext;

								head_node = nexthead_node;
								nexthead_node = current_node;
						}

						for (int j = 0; j < K - 1; j++)		// pass the first one
						{
								previous_node = current_node;
								current_node = next_node;
								next_node = next_node->pnext;

								current_node->addr_of_right = previous_node->addr_of_left;
								current_node->pnext = previous_node;
						}

						if (0 == i)
						{
								head_ ->pnext = current_node;
								head_->addr_of_left = current_node->addr_of_left;
						}
						else
						{
								head_node->pnext = current_node;
								head_node->addr_of_right = current_node->addr_of_left;
						}
				}
			  	
				if (0 == N % K)
				{
						nexthead_node->addr_of_right = -1;
				}
				else
				{
						nexthead_node->pnext = next_node;
						nexthead_node->addr_of_right = next_node->addr_of_left;
				}



				return 0;
		}


		int Linked_list::print_list()
		{
				ptr_to_node pcur = head_->pnext;
				while(-1 != pcur->addr_of_right)
				{
						printf("%05d %d %05d\n", pcur->addr_of_left, pcur->data, pcur->addr_of_right);
						pcur = pcur->pnext;
				}
				printf("%05d %d %d\n", pcur->addr_of_left, pcur->data, pcur->addr_of_right);
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
