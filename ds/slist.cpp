

#include <iostream>

/**************************************************************************************
 * 
 * 	1. Create a node 
 * 	2. Push to the front of the list
 * 	3. Push to the back of the list
 * 	4. Find and delete a node in the list
 * 	5. Delete the whole list
 * 	6. Print the list 
 * 	7. Check whether a loop is present in the list
 * 	8. Detect and remove the loop in the list
 * 	9. Copy the contents of one list to another
 * 	10. Find the length of the list
 * 	11. Split the list into two.
 *  12. Find median in the list
 * 	13. Reverse a linked list
 *      a. Using recursion
 *	    b. Using the iteration method
 *  14. Find Intersection between 2 linked lists
 *  15. Find whether the length of linked list is Odd or Even	 
 *	16. Sort a linked list
 *  17. pairwise swap 2 nodes
 **************************************************************************************/
#include "slist.h"


link createList( Item data )
{
  link newnode = new struct node();
  newnode->data = data;
  newnode->next = NULL;
  
  return newnode;  
}


void push_front( link* head, int data )
{
    link node = createList( data );
    if( *head == NULL )
    {
      *head = node;
    }
    else
    {     
      node->next = *head;
      *head = node;
    } 
}

void push_back( link* head, Item data )
{
  link node = createList( data );
  if( *head == NULL )
  {
    *head = node;
  }
  else
  {
    link current = *head;
    while( current->next != NULL )
    {      
      current = current->next;
    }    
    current->next = node;    
  }
}

link add(link head, Item data)
{
	link n = 0;
	if (head == NULL)
	{
		return createList(data);
	}
	else
	{
		n = add(head->next,data);
	}
	return n;
}

void recursive_push_back(link* head, Item data)
{
	if (*head == NULL)
	{
		link node = createList(data);
		*head = node;
		return;
	}
	else
	{
		recursive_push_back(&(*head)->next, data);
	}
}


int pop_front(link* head)
{
	link t;
	int data = 0;
	if(!(*head))
		return 0;
	else
	{
		t = (*head)->next;
		data = (*head)->data;
		delete *head;
		*head = t;
		return data;	
	}
		
}


void printList( link head )
{
  link current = head;
  if( !current )
  {
    std::cout << "List is Empty" << std::endl;
    return;
  }
  
  while( current->next != NULL )
  { 
    std::cout << current->data << "->";
    current = current->next;
  }
  std::cout << current->data << std::endl;
}


void deleteNode( link head, Item data )
{
  link current = head;
  link temp = NULL;
  
  if( !current )
  {
    std::cout << "List is Empty" << std::endl;
  }
  else
  {
    while( current->next != NULL )
    { 
      if( current->data == data )
      {
		temp = current->next;
		current->data = temp->data;
		current->next = temp->next;
		delete temp;
		return;
      }	
      else
      {
		current = current->next;
      }
    }
    
  }  
}


void deleteList( link* head )
{
  if( *head == NULL )
  {
    std::cout << "List is Empty" << std::endl;
  }
  else
  {
      link current = *head;
      link temp = NULL;
      
      while( current->next != NULL )
      {
		temp = current;
		*head = current->next;
		current = *head;
		delete temp;	
      }
      if( *head )
      {
		delete *head;
		*head = NULL;
      }
  }  
}

link recursive_delete(link head)
{
	if (head->next == NULL)
	{
		delete head;
		head = 0;
		return head;
	}
	else if (head == NULL)
	{
		return 0;
	}
	else
	{
		return recursive_delete(head->next);
	}
}


int len( link head )
{
    link current = head;
    int count = 0;
    
    if( !head )
    {
      std::cout << "List is Empty" << std::endl;      
      return count;
    }
    
    while( current->next != NULL )
    {
      count++;
      current = current->next;
    }
    
    return count;  
}

void listcopy( link* destList, link* srcList )
{
  int srclen = len(*srcList);
  
  if( !srclen )
  {
    std::cout << "Source List is empty. Copy Operation cannot be permitted" << std::endl;      
    return;
  }
  
  link currSrc = *srcList;
  link currDest = *destList;
  
  while( currSrc->next != NULL )
  {
      push_back( &(*destList), currSrc->data );
      currSrc = currSrc->next;
  }
  push_back( &(*destList), currSrc->data );
}



bool isLoop( link head )
{
  link slow,fast;
  
  slow = fast = head;
  
  while( slow && fast && fast->next )
  {
    slow = slow->next;
    fast = fast->next->next;
    
    if( slow == fast )
    {
		return true;	
    }
    
  }  
  return false;
}


void findAndRemoveLoop( link head )
{
  link slow,fast;
  
  slow = fast = head;
  
  bool is_loop = false;
  
  while( slow && fast && fast->next )
  {
    slow = slow->next;
    fast = fast->next->next;
    
    if( slow == fast )
    {
		is_loop = true;
		break;
    }
    
  }
  
  if( is_loop )
  {
    slow = head;
    
    while( slow->next != fast->next )
    {
      slow = slow->next;
      fast = fast->next;
    }
    
    fast->next = NULL;
  }  
}

void  reverse_recursion(link* head)
{
	link first = *head;

	link end = first->next;
	
	if(first == 0)
		return;
	if(end == 0)
		return;
	reverse_recursion(&end);
	first->next->next = first;
	first->next = 0;
	*head = end;
}

void reverse(link* head)
{
	link prev,curr,next;
	prev = 0;
	curr =  (*head);
	next  =  curr->next;

	while(curr->next)
	{
	  curr->next = prev;
	
	  prev = curr;
	  curr = next;
	  next = curr->next;
	}
	curr->next = prev;
	prev = curr;
	*head = curr;
}


void swap_any_two_nodes(link* head, link* p1, link* p2)
{
	if(!(*head) || !(*p1) || !(*p2))
		return;
		
	link h = *head;
	link p1_temp = *p1;
	link p2_temp = *p2;
	link p1_prev = 0;
	link p2_prev = 0;
	link t;
	
	
	p1_prev = p2_prev = h;
	
	if(p1_temp != p1_prev)	
		while(p1_prev->next != p1_temp){p1_prev = p1_prev->next;}
	else
		p1_prev = 0;
	if(p2_temp != p2_prev)	
		while(p2_prev->next != p2_temp){p2_prev = p2_prev->next;}
	else
		p2_prev = 0;
	
	
	//swap logic
	if(p1_prev)
		p1_prev->next = p2_temp;
	if(p2_prev)	
		p2_prev->next = p1_temp;
	t = p2_temp->next;
	p2_temp->next = p1_temp->next;
	p1_temp->next = t;
	
	if(p1_temp == h)
	{
		*head = p2_temp;
	}
	else if(p2_temp == h)
	{
		*head = p1_temp;
	}
	
}


link find_last_element_of_list(link* head)
{
	link walk = *head;
	
	while(walk->next != 0)
	{
		walk = walk->next;
	}
	
	return walk;
}

link prev_node(link* head, link n)
{
	link prev = 0;
	link walk = *head;
	
	while(walk->next != n)
	{
		walk = walk->next;
		prev = walk;
	}
	
	return prev;	
}

link partition(link* head, link lo, link hi)
{
	
		link low = lo;
		link pivot = *head;
		link high = find_last_element_of_list(&(*head));
	
		std::cout << "pivot:" <<pivot->data << "\n";
		std::cout << "low:" <<low->data << "\n";
		std::cout << "high###:" <<high->data << "\n";
		
		std::cout << "###" << "\t";
		while(low->data < pivot->data)
		{
					
			//low = low->next;
			//std::cout << low->data << "\t";
		}
		std::cout << std::endl;
	
				
		return 0;
}

void do_ascending_quick(link* head)
{	
	partition(&(*head),(*head)->next,find_last_element_of_list(&(*head)));
}


void do_ascending(link* head)
{
		link h = *head;
		
		if(!h || !h->next)
			return;
		
		link min;
		link start;
		link end;
		min = start = end = h;
		
		while(end != 0)
		{
			if(end->data < min->data)
			{
				min = end;
			}
			end = end->next;
		}
		
		swap_any_two_nodes(&(*head),&min,&start);		
		do_ascending(&(*head)->next);	
}



void swap_helper(link* p1, link* c1, link* p2, link* c2)
{
	link temp;

	// This is the case when current node is head
	if(!(*p1))
	{
		temp = (*c1);
		(*c1)->next = (*c2)->next;
		(*c2)->next = temp;		
		
		*c2 = *c1;
		//*c2 = temp;
				
		return;		
	}
	
	// This is the case of adjacent node swap
	if((*c1)->next == (*c2))
	{
		temp = *c1;//(*c1)->next;
		(*c1)->next = (*c2)->next;
		(*c2)->next = temp;
		return;
	}	
	
	//any two nodes of the linked list
	
	temp = (*c1)->next;
	(*c1)->next = (*c2)->next;
	(*c2)->next = temp;

	temp = (*p1)->next;
	(*p1)->next = (*p2)->next;
	(*p2)->next = temp;
	
	return;
}



void pairwise_swap(link* head)
{	
	link prev,curr,next;
	prev = *head;
	curr = (*head)->next;
	
	*head = curr;

	while(1)
	{
		next = curr->next;
		curr->next = prev;
		prev->next = next;
		if(next == 0 || next->next == 0)
			return;
		prev->next = next->next;
		prev = next;
		curr = prev->next;
	}
}


link rev(link h)
{
	link t,y,r;
	y = (h);
	r = 0;
	t = y->next;
	while(y)
	{
		t=y->next; y->next=r; r = y; y = t;	
	}	
	return r;
}

void visitor(link p)
{
	if(!p)
		return;	
	else
		std::cout << p->data << "->";		
}

link del(link head, Item data)
{
	link t;
	if(!head)
		return 0;
	else{
		
		if(head->data == data)
		{
			t = head->next;
			delete head;
			return t;	
		}
		else
		{
			head->next = del(head->next,data);
			return head;	
		}	
	}
			
}

void traverse(link h, void(*visit)(link p))
{
	if(!h)
	{
		std::cout << "(null)" << std::endl;
		return;
	}
	(*visit)(h);	
	traverse(h->next, visit);	
}

void traverseR(link h, void(*visit)(link p))
{
	if(!h)
		return;
		
	traverse(h->next, visit);	
	(*visit)(h);
}

link do_ascending2(link pList)
{	
	// zero or one element in list
	if (pList == NULL || pList->next == NULL)
		return pList;
	// head is the first element of resulting sorted list
	link head = NULL;
	while (pList != NULL) {
		link current = pList;
		pList = pList->next;
		if (head == NULL || current->data < head->data) {
			// insert into the head of the sorted list
			// or as the first element into an empty sorted list
			current->next = head;
			head = current;
		}
		else {
			// insert current element into proper position in non-empty sorted list
			link p = head;
			while (p != NULL) {
				if (p->next == NULL || // last element of the sorted list
					current->data < p->next->data) // middle of the list
				{
					// insert into middle of the sorted list or as the last element
					current->next = p->next;
					p->next = current;
					break; // done
				}
				p = p->next;
			}
		}
	}
	return head;
}