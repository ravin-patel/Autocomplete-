#ifndef TRIE_H
#define TRIE_H
//The make node for the tree. each node can hold a string but it does not need to.
//but each node without word there will be a subnode. Node with word can still have a list.
typedef struct nodeTag{
      char* word;
	  struct nodeTag** next;
     } Node;
//Just a simple counter to check to pop once it push on.
typedef struct {
      Node* node;
	  int index;
     } NodeCounter;
	 
	void init(Node* node);
	int add(Node* start, char* word);
	void print(Node* node, char* base);
	
#endif
