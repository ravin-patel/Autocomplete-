#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	void loadFile(Node* root, char* fileName)
    {//
		FILE *fp = fopen(fileName,"r");
		if( fp == NULL )
        {
			exit(EXIT_FAILURE);
        }
        char readLine[30];
		while(fscanf(fp,"%s",readLine) == 1)
        {
            add(root, readLine);
        }
        fclose(fp);
	}

	int main(void)
	{
		//Make the node
	         Node* headNode  = (Node*) malloc(sizeof(Node));
		init(headNode);
		loadFile(headNode,"american-english-no-accents"); // load the file and fill the tree
		char list[30]; //list size
		int op;
		printf("--------------------SIMULATION--------------------\n");
		while(1)
		{ //loop untill they either exit for do eof
			printf("Enter a word or ctrl c to end: "); 
			op = fscanf(stdin,"%s",list);
			if(op == EOF || op != 1) 
			{
				return 0;
			}
			print(headNode,list);
            printf("--------------------------------------------------\n");
		}
		return 0;
	}
