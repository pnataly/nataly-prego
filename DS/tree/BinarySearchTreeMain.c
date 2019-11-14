#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{

	Tree* newTree;
	int data;
	int result;
	int choice = 0;
	int traverseMode = 0;

	while (choice != 9)
	{
		printf("*Please choose an option:\n");
		printf("1) Create Binary Search Tree\n");
		printf("2) Destroy Binary Search Tree\n");
		printf("3) Tree insert\n");
		printf("4) Is data found\n");
		printf("5) Print Tree\n");
		printf("6) Is full Tree\n");
		printf("7) Is perfect Tree\n");
		printf("8) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					newTree = TreeCreate();
					if(newTree == NULL)
					{
						printf("ERROR- the Tree not created\n");
						printf("\n");	
						break;
					}
					printf("The Tree is created.\n");
					printf("\n");	
					break;

			case 2:
					if(newTree == NULL)
					{
						printf("ERROR- the Tree not created\n");
						printf("\n");	
						break;
					}
					TreeDestroy(newTree);
					newTree = NULL;
					printf("The Tree has been Destroyed.\n");
					printf("\n");		
					break;

			case 3:
					printf("Please enter a data to insert to the Tree:\n");
					scanf("%d",&data);
					result = TreeInsert(newTree, data);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("Please create a Tree first\n");
						break;
					}
					if(result == ERR_ALLOC_FAIL)
					{
						printf("Error- allocation fail\n");
						break;
					}
					printf("The data is added.\n");
					printf("\n");		
					break;

			case 4:
					printf("Please enter a data to search in the Tree:\n");
					scanf("%d",&data);
					result = TreeIsDataFound(newTree, data);
					if(result)
					{
						printf("The data is found\n");
						printf("\n");		
						break;
					}
					printf("The data not found\n");
					printf("\n");		
					break;

			case 5:
					if(newTree == NULL)
					{
						printf("ERROR- the Tree not created\n");
						break;
					}
					printf("*Please choose an option:\n");
					printf("Press 0 - print PreOrder:\n");
					printf("Press 1 - print InOrder:\n");
					printf("Press 2 - print PostOrder:\n");
					scanf("%d", &traverseMode);
					TreePrint(newTree, traverseMode);
					break;					

			case 6:
					if(newTree == NULL)
					{
						printf("ERROR- the Tree not created\n");
						break;
					}
					result = isFullTree(newTree);
					if(result)
					{
						printf("The Tree is full\n");
						break;
					}
					printf("The Tree is not full\n");
					break;

			case 7:
					if(newTree == NULL)
					{
						printf("ERROR- the Tree not created\n");
						break;
					}
					result = isPerfectTree(newTree);
					if(result)
					{
						printf("The Tree is perfect\n");
						break;
					}
					printf("The Tree is not perfect\n");
					break;

			case 8:
					printf("* Exit *\n");
					return 0;
		
			default:
					printf("Please enter a number between 1-8.\n");
					printf("\n");	
					choice = 0;
					printf("\n");
					break;
		}
	}

	return 0;
}
