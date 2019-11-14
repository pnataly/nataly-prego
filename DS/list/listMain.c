#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"


int main()
{

	Person *_newPerson;
	Person *_revPerson;
	Person *_head;
	Person* _item = 0;
	int choice = 0;
	_head = NULL;

	while (choice != 7)
	{
		printf("*Please choose an option:\n");
		printf("1) Insert to head list\n");
		printf("2) Insert to list by key\n");
		printf("3) Insert to list by key Rec\n");
		printf("4) Remove from head list\n");	
		printf("5) Remove from list by key\n");
		printf("6) Remove from list by key Rec\n");
		printf("7) Flip list\n");
		printf("8) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					_newPerson =(Person*)malloc(sizeof(Person));
					
					printf("Enter you name:\n");
					scanf("%s", _newPerson->m_name);
					printf("Enter you Id:\n");
					scanf("%d", &_newPerson->m_id);
					printf("Enter you age:\n");
					scanf("%d", &_newPerson->m_age);

					_head = ListInsertHead(_head,_newPerson);
					PrintList(_head);
					printf("\n");
					break;

			case 2:
					_newPerson =(Person*)malloc(sizeof(Person));
					
					printf("Enter you name:\n");
					scanf("%s", _newPerson->m_name);
					printf("Enter you Id:\n");
					scanf("%d", &_newPerson->m_id);
					printf("Enter you age:\n");
					scanf("%d", &_newPerson->m_age);

					_head = ListInsertByKey(_head, _newPerson->m_id, _newPerson); 
					PrintList(_head);
					printf("\n");
					break;

			case 3:
					_newPerson =(Person*)malloc(sizeof(Person));
					printf("Enter you name:\n");
					scanf("%s", _newPerson->m_name);
					printf("Enter you Id:\n");
					scanf("%d", &_newPerson->m_id);
					printf("Enter you age:\n");
					scanf("%d", &_newPerson->m_age);
					_head=ListInsertByKeyRec(_head, _newPerson->m_id, _newPerson);
					PrintList(_head);
					printf("\n");
					break;

	
			case 4:		
					_head = ListRemoveHead(_head, &_item);
					printf("The ID: %d removed.\n", _item->m_id);
					PrintList(_head);
					break;

			case 5:		_head = ListRemoveByKey(_head, _newPerson->m_id, &_item);
					PrintList(_head);
					break;

			case 6:		/*_head = ListRemoveByKeyRec(_head, _newPerson->m_id, &_item);
					PrintList(_head);
					break;*/

			case 7:
					_revPerson = Flip(_head);
					PrintList(_revPerson);
					printf("\n");
					break;

			case 8:
					printf("* Exit *\n");
					return 0;
			
			default:
				printf("Please enter a number between 1-8.\n");
				printf("\n");	
				choice = 0;
				break;
		}
	}
return 0;
}
