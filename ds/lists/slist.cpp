

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

typedef struct node* nodeptr_t;

struct node{
  
    int data;
    struct node* next;
};


nodeptr_t createList( int data )
{
  nodeptr_t newnode = new struct node();
  newnode->data = data;
  newnode->next = NULL;
  
  return newnode;  
}


void push_front( nodeptr_t* head, int data )
{
    nodeptr_t node = createList( data );
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

void push_back( nodeptr_t* head, int data )
{
  nodeptr_t node = createList( data );
  if( *head == NULL )
  {
    *head = node;
  }
  else
  {
    nodeptr_t current = *head;
    while( current->next != NULL )
    {      
      current = current->next;
    }    
    current->next = node;    
  }
}


void printList( nodeptr_t head )
{
  nodeptr_t current = head;
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


void deleteNode( nodeptr_t head, int data )
{
  nodeptr_t current = head;
  nodeptr_t temp = NULL;
  
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


void deleteList( nodeptr_t* head )
{
  if( *head == NULL )
  {
    std::cout << "List is Empty" << std::endl;
  }
  else
  {
      nodeptr_t current = *head;
      nodeptr_t temp = NULL;
      
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


int len( nodeptr_t head )
{
    nodeptr_t current = head;
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

void listcopy( nodeptr_t* destList, nodeptr_t* srcList )
{
  int srclen = len(*srcList);
  
  if( !srclen )
  {
    std::cout << "Source List is empty. Copy Operation cannot be permitted" << std::endl;      
    return;
  }
  
  nodeptr_t currSrc = *srcList;
  nodeptr_t currDest = *destList;
  
  while( currSrc->next != NULL )
  {
      push_back( &(*destList), currSrc->data );
      currSrc = currSrc->next;
  }
  push_back( &(*destList), currSrc->data );
}



bool isLoop( nodeptr_t head )
{
  nodeptr_t slow,fast;
  
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


void findAndRemoveLoop( nodeptr_t head )
{
  nodeptr_t slow,fast;
  
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

void  reverse_recursion(nodeptr_t* head)
{
	nodeptr_t first = *head;

	nodeptr_t end = first->next;
	
	if(first == 0)
		return;
	if(end == 0)
		return;
	reverse_recursion(&end);
	first->next->next = first;
	first->next = 0;
	*head = end;
}

void reverse(nodeptr_t* head)
{
	nodeptr_t prev,curr,next;
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


void swap_any_two_nodes(nodeptr_t* head, nodeptr_t* p1, nodeptr_t* p2)
{
	if(!(*head) || !(*p1) || !(*p2))
		return;
		
	nodeptr_t h = *head;
	nodeptr_t p1_temp = *p1;
	nodeptr_t p2_temp = *p2;
	nodeptr_t p1_prev = 0;
	nodeptr_t p2_prev = 0;
	nodeptr_t t;
	
	
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


nodeptr_t find_last_element_of_list(nodeptr_t* head)
{
	nodeptr_t walk = *head;
	
	while(walk->next != 0)
	{
			walk = walk->next;
	}
	
	return walk;
}

nodeptr_t prev_node(nodeptr_t* head, nodeptr_t n)
{
	nodeptr_t prev = 0;
	nodeptr_t walk = *head;
	
	while(walk->next != 0)
	{
			walk = walk->next;
			prev = walk;
	}
	
	return prev;	
}

nodeptr_t partition(nodeptr_t* head, nodeptr_t lo, nodeptr_t hi)
{
	
		nodeptr_t low = lo;
		nodeptr_t pivot = *head;
		nodeptr_t high = find_last_element_of_list(&(*head));
	
		std::cout << "pivot:" <<pivot->data << "\n";
		std::cout << "low:" <<low->data << "\n";
		std::cout << "high###:" <<high->data << "\n";
		//while(true)
		//{		
				std::cout << "###" << "\t";
				while(low->data < pivot->data)
				{
					
					//low = low->next;
					//std::cout << low->data << "\t";
				}
				std::cout << std::endl;
	
				/*while(high->data > pivot->data)
				{
					high = prev_node(&(*head),high);
					std::cout << high->data << "\t";
				}
				
				if(low >= high)
				{
					std::cout << "brk" <<std::endl;
					//break;
				}
					
				swap_any_two_nodes(&(*head),&low,&hi);
				std::cout << "===" << "\n";
				printList(*head);
				std::cout << "===" << "\n";		
		//}
		
		//swap_any_two_nodes(&(*head),&lo,&high);
		return high;
		*/
}

void do_ascending_quick(nodeptr_t* head)
{	
	partition(&(*head),(*head)->next,find_last_element_of_list(&(*head)));
}


void do_ascending(nodeptr_t* head)
{
		nodeptr_t h = *head;
		
		if(!h || !h->next)
			return;
		
		nodeptr_t min;
		nodeptr_t start;
		nodeptr_t end;
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



void swap_helper(nodeptr_t* p1, nodeptr_t* c1, nodeptr_t* p2, nodeptr_t* c2)
{
	nodeptr_t temp;

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



void pairwise_swap(nodeptr_t* head)
{
	
	nodeptr_t prev,curr,next;
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

int main()
{

  nodeptr_t head = NULL;
  
  push_front( &head, 10 );
  push_front( &head, 20 );
  push_front( &head, 30 );
  push_front( &head, 40 );
  push_front( &head, 50 );
  push_back( &head, 0 );
  push_back( &head, -10 );
  push_back( &head, -20 );
  push_back( &head, -30 );
  push_back( &head, -40 );
  push_back( &head, -50 );
  
  printList( head ); 
  
  deleteNode( head, -20 );
  deleteNode( head, 30 );
  
  std::cout << "Length of the list = " << len( head ) << std::endl;
  std::cout << "Is Loop present in Linked list = " << isLoop( head ) << std::endl;
  
  printList( head );
  //deleteList( &head );
  //printList( head );  
  
  
  nodeptr_t copyList = NULL;
  
  listcopy( &copyList, &head );
  printList( copyList );
  
  reverse_recursion(&head);
  printList(head);

  reverse(&head);
  printList(head);
 
  //pairwise_swap(&head);

  //swap_helper(0,&head,&head,&(head->next));	
  printList(head);

  swap_any_two_nodes(&head, &head->next,&head->next->next->next->next->next->next->next->next);	
  printList(head);    
  
 //do_ascending(&head);
 do_ascending_quick(&head);
  //printList(head);
  	
  return 0;
}
