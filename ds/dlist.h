#pragma once

#include "adt.h"

dlink createNode_dlist(int data);
dlink push_back_dlist(dlink head, int data);
dlink push_front_dlist(dlink head, int data);
void print_double_linked_list(dlink head);

dlink sortedInsert_hacker_rank(dlink head, int data);
dlink reverse_dlist_hacker_rank(dlink head);