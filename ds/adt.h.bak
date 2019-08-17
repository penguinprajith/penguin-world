#ifndef ADT_H
#define ADT_H


typedef int Item;

typedef struct node* link;
struct node{

    Item data;
    //void* data;
    struct node* next;
};



typedef struct btnode* btree;
struct btnode{
	
	Item data;
	//struct btnode* parent;
	struct btnode* left;
	struct btnode* right;	
};


#define MAX_CHARS	26
typedef struct trienode*  trie;

struct trienode{
	
	int isLeaf;
	trie characters[MAX_CHARS];
	
	int (*getcharindex)(char c);
	trie (*getnode)(char c,trie t);
	void (*setnode)(char c,trie t);
	void (*add)(char* str,trie t);
	void (*remove)(char* str, trie t);
	int (*find)(char* str, trie t);
};
 


typedef struct edge Edge;
typedef struct graph* Graph;

struct edge{
	
	int v;
	int w;
};

struct graph{
	
	
};





#endif
