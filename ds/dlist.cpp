

#include "dlist.h"
#include <iostream>

dlink createNode_dlist(int data)
{
	dlink newnode = new dnode();

	newnode->data = data;
	newnode->prev = 0;
	newnode->next = 0;
	return newnode;
}


dlink push_back_dlist(dlink head, int data)
{
	dlink node = createNode_dlist(data);
	if (head == 0)
	{
		head = node;
		return head;
	}

	dlink current = head;
	while (current->next != 0)
	{
		current = current->next;
	}

	current->next = node;
	node->prev = current;
	return head;
}

dlink push_front_dlist(dlink head, int data)
{
	dlink node = createNode_dlist(data);
	if (node == 0)
	{
		head = node;
		return head;
	}
	node->next = head;
	head->prev = node;
	head = node;
	return head;
}

void print_double_linked_list(dlink head)
{
	dlink current = head;
	if (head == 0)
	{
		std::cout << "!!!List is Empty!!!" << std::endl;
		return;
	}

	while (current->next != 0)
	{
		std::cout << current->data << "->";
		current = current->next;
	}
	std::cout << current->data << std::endl;
}


dlink sortedInsert_hacker_rank(dlink head, int data) {

	dlink temp = head;
	dlink node = 0;

	if (!head)
		return 0;

	if (data < head->data)
	{
		head = push_front_dlist(head, data);
		return head;
	}
	else
	{
		while ( (temp->next != 0) && (data > temp->data)) {
		
			temp = temp->next;
		}

		node = createNode_dlist(data);
		if (data > temp->data){
			temp->next = node;
			node->prev = temp;
		}
		else
		{
			node->next = temp;
			node->prev = temp->prev;
			temp->prev->next = node;
		}
	}
	return head;
}

dlink reverse_dlist_hacker_rank(dlink head)
{
	dlink first = head;
	dlink rest = head->next;
	if (!head)
		return 0;

	if (!rest)
		return first;

	rest = reverse_dlist_hacker_rank(rest);
	
	first->next->prev = 0;
	first->next->next = first;
	first->prev = rest;
	first->next = 0;
	
	return rest;
	
}