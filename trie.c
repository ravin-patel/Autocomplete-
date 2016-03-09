#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	void init(Node* node){
		node->next = (Node**) malloc(sizeof(Node*) * 53);
	}
	int getPos(char c){
		int wordPos = (int)(c - 'A'); //shift the index by 63 which is 'A'
		if(c == '\'')
			return 0;
		if((wordPos > 25 && wordPos < 32) || wordPos > 57)
			return -1;
		if(wordPos > 25) wordPos-=6; 
		return 1+wordPos; //return index +1 since ' is 0
	}
	//Print the matches
	void print(Node* node, char* base)
	{
		NodeCounter* list = (NodeCounter*) malloc(sizeof(NodeCounter) * 24);
		Node* temp = node;
		int i = 0;
		//Skip throught the base in the node where node is the root.
		if(base != NULL)
		{ //prints the tree if base is null
			while(base[0] != '\0')
			{
				i = getPos(base[0]); 
				if(i < 0)
					continue;
				temp = temp->next[getPos(base[0])]; // next node = this node
				if(temp == NULL) return;
				base++;
					
			}
		}
		i = 0; 
		list[0].node = temp;
		list[0].index = 0;
		int count=1;
		while(1)
		{ //if the node have a sub node push on the stack and pop once that node have no more sub node.
			if(list[i].index < 53) //lower + upper case letters + ' = 53 characters
			{
				temp = (list[i].node)->next[list[i].index];
				list[i].index++;
				if(temp != NULL)
				{ 
					if(temp->word != NULL)
					{
						printf("Match %d: %s\n", count,temp->word);
						count++;
					}
					list[++i].node = temp; //push to the list
					list[i].index = 0; // set the node index to 0
				}
			}
			else 
			{
				if(i ==0) return; //no more sub node to check
				else i--; //pop from the stack
			}

		}
	}
	//Add the word to the node
	//start==root
	int add(Node* start, char* add){
		int size = strlen(add); 
		int wordPos = 0;
		//loop through each node
		for(int i=0; i<size; i++)
		{ 
			wordPos = getPos(add[i]); 
			if(wordPos < 0) //validity of input
				continue;
			if(start->next[wordPos] == NULL)
			{ 
				start->next[wordPos] = (Node*) malloc(sizeof(Node));
				init(start->next[wordPos]);
			}
			start = start->next[wordPos]; // start=next node 
		}
		start->word = (char*) malloc(sizeof(char)*size);
		strcpy(start->word, add); 
		return 0;
	}
