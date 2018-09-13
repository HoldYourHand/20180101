 ///
 /// @file    02_02_unary_polynomials.cc
 /// @author  fjd(clamfjd@gmail.com)
 /// @date    2018-09-09 19:19:49
 ///

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

namespace fjd
{

		typedef struct PolyNode * Ptr_to_PolyNode;
		struct PolyNode
		{
				int coef;
				int expon;		// |x|	<= 1000
				Ptr_to_PolyNode pnext;
		};

		class Unary_Polynomial
		{
		public:
				Unary_Polynomial()
				: Head_((Ptr_to_PolyNode)calloc(1, sizeof(struct PolyNode)))
				{}		

				~Unary_Polynomial()		// TODO
				{
//						Ptr_to_PolyNode p;
//						while(Head_->pnext != NULL)
//						{
//								p = Head_->pnext;
//								Head_->pnext = p->pnext;
//								free(p);
//						}
//						free(Head_);
				}

				int Read_Poly()
				{
						int N, coef, expon;
						scanf("%d", &N);
						Ptr_to_PolyNode p = Head_;
						for(int i = 0; i != N; i++)
						{
								scanf("%d %d", &coef, &expon);
								Ptr_to_PolyNode new_polynode = (Ptr_to_PolyNode)calloc(1, sizeof(struct PolyNode));
								new_polynode->coef = coef;
								new_polynode->expon = expon;
	
								p->pnext = new_polynode;
								p = p->pnext;
								Head_->coef++;
						}
						return 0;
				}
				
				int Print_Poly()
				{
						if (0 == Head_->coef)
						{
								printf("0 0\n");
								return 0;
						}

						Ptr_to_PolyNode p = Head_->pnext;
						int first = 0;
						while(p != NULL)
						{
								if (first)
								{
										printf(" ");
								}
								first = 1;
								printf("%d %d", p->coef, p->expon);
								p = p->pnext;
						}
						printf("\n");
						return 0;
				}

				int Insert_by_descend_not_delete(int coef, int expon)
				{
						Ptr_to_PolyNode p = Head_->pnext;
						Ptr_to_PolyNode ppre = Head_;
						while(p != NULL)
						{
								if (p->expon == expon)
								{
										p->coef += coef;
										return 0;
								}
								else if (p->expon > expon)		// descread
								{
										p = p->pnext;
										ppre = ppre->pnext;
								}
								else
								{
										break;
								}

						}

						Ptr_to_PolyNode new_polynode = (Ptr_to_PolyNode)calloc(1, sizeof(struct PolyNode));
						new_polynode->coef = coef;
						new_polynode->expon = expon;

						ppre->pnext = new_polynode;
						new_polynode->pnext = p;
						Head_->coef++;
				
						return 0;
				}

				int Check_And_delete()
				{
						Ptr_to_PolyNode p = Head_->pnext;
						Ptr_to_PolyNode ppre = Head_;
						int zeros = 0;
						while(p != NULL)
						{
								if(p->coef == 0)		// coef == 0
								{
										ppre->pnext = p->pnext;
										free(p);
										Head_->coef--;
										p = ppre->pnext;
										++zeros;
								}
								else
								{
									ppre = ppre->pnext;
									p = p->pnext;
								}
						}
						return zeros;
				}

				friend int Addtion(const class Unary_Polynomial p1, const class Unary_Polynomial p2, class Unary_Polynomial *p_result);
				friend int Multiplication(const class Unary_Polynomial p1, const class Unary_Polynomial p2, class Unary_Polynomial *p_result);

		private:
				int length_;
				Ptr_to_PolyNode Head_;
				

			//	Ptr_to_PolyNode Tail_;		// TODO
		};		// class Unary_Polynomial

		int Addtion(const class Unary_Polynomial p_1, const class Unary_Polynomial p_2, class Unary_Polynomial * p_result)
		{
				Ptr_to_PolyNode p1 = p_1.Head_->pnext, p2 = p_2.Head_->pnext;

				while(p1 != NULL && p2 != NULL)
				{
						if (p1->expon > p2->expon)
						{
								p_result->Insert_by_descend_not_delete(p1->coef, p1->expon);
								p1 = p1->pnext;
						}
						else if (p1->expon < p2->expon)
						{
								p_result->Insert_by_descend_not_delete(p2->coef, p2->expon);
								p2 = p2->pnext;
						}
						else
						{
								if (p1->coef + p2->coef ==0)
								{
										p1 = p1->pnext;
										p2 = p2->pnext;
										continue;
								}
								
								p_result->Insert_by_descend_not_delete(p1->coef + p2->coef, p1->expon);
								p1 = p1->pnext;
								p2 = p2->pnext;

						}
				}
				
				while (p1 != NULL)
				{
								p_result->Insert_by_descend_not_delete(p1->coef, p1->expon);
								p1 = p1->pnext;
				}
				while (p2 != NULL)
				{
								p_result->Insert_by_descend_not_delete(p2->coef, p2->expon);
								p2 = p2->pnext;
				}

				return 0;
		}

		int Multiplication(const class Unary_Polynomial p_1, const class Unary_Polynomial p_2, class Unary_Polynomial *p_result)
		{
				Ptr_to_PolyNode p1 = p_1.Head_->pnext, p2 = p_2.Head_->pnext;
				
				while (p1 != NULL)
				{
						while(p2 != NULL)
						{
								p_result->Insert_by_descend_not_delete(p1->coef * p2->coef, p1->expon + p2->expon);
								p2 = p2->pnext;
						}
						p1 = p1->pnext;
						p2 = p_2.Head_->pnext;
				}

				return 0;
		}


}		// namespace fjd

using namespace fjd;

int main()
{
		class Unary_Polynomial Unary_Polynomial_1;
		class Unary_Polynomial Unary_Polynomial_2;
		class Unary_Polynomial Unary_Polynomial_addition;
		class Unary_Polynomial Unary_Polynomial_multiplication;
		
		Unary_Polynomial_1.Read_Poly();
//		Unary_Polynomial_1.Print_Poly();

		Unary_Polynomial_2.Read_Poly();
//		Unary_Polynomial_2.Print_Poly();

		Multiplication(Unary_Polynomial_1, Unary_Polynomial_2, &Unary_Polynomial_multiplication);
		Unary_Polynomial_multiplication.Check_And_delete();
		Unary_Polynomial_multiplication.Print_Poly();

		Addtion(Unary_Polynomial_1, Unary_Polynomial_2, &Unary_Polynomial_addition);
		Unary_Polynomial_addition.Print_Poly();


		return 0;
}

