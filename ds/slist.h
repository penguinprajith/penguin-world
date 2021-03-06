
#ifndef SLIST_H
#define SLIST_H

#include "adt.h"

link createList( Item data );
void push_front( link* head, Item data );
void push_back( link* head, Item data );
link add(link, Item data);

void recursive_push_back(link* head, Item data);
int pop_front(link* head);
void printList( link head );
void deleteNode( link head, Item data );
void deleteList( link* head );
link recursive_delete(link head);
int len( link head );
void listcopy( link* destList, link* srcList );
bool isLoop( link head );
void findAndRemoveLoop( link head );
void  reverse_recursion(link* head);
void reverse(link* head);
void swap_any_two_nodes(link* head, link* p1, link* p2);
link find_last_element_of_list(link* head);
link prev_node(link* head, link n);
link partition(link* head, link lo, link hi);
void do_ascending_quick(link* head);
void do_ascending(link* head);
link do_ascending2(link head);
void swap_helper(link* p1, link* c1, link* p2, link* c2);
void pairwise_swap(link* head);
link rev(link h);
void visitor(link p);
void traverse(link h, void(*visit)(link p));
void traverseR(link h, void(*visit)(link p));
link del(link head, Item data);

//hacker_rank problems
link insertAtPos_hacker_rank(link* ptrToHead, int data, int pos);
link insertNodeAtPosition_hacker_rank(link head, int data, int position);
link del_hacker_rank(link* ptrToHead, int pos);
link deleteNode_hacker_rank(link head, int position);
void reverse_print_hacker_rank(link head);
link reverse_hacker_rank(link head);
bool compare_lists_hacker_rank(link head1, link head2);
link mergeLists_hacker_rank(link head1, link head2);
int getNodefromTail_hacker_rank(link head, int positionFromTail);
link removeDuplicates_hacker_rank(link head);
int findMergeNode_hacker_rank(link head1, link head2);
#endif
