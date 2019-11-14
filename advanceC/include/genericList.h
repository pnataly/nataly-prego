#ifndef __GENERICLIST_H__
#define __GENERICLIST_H__


typedef struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	struct Person* m_next;
}Person;

/* @Description: Insert data to the head of the list. 
 * @Input: _head- pointer to list.
 * @Input: _p- the data we want to insert.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListInsertHead(Person* _head, Person* _p);

/* @Description: Remove data from the head of the list. 
 * @Input: _head- pointer to list.
 * @Input: _item- pointer to the item we remove.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListRemoveHead(Person* _head, Person** _item);

/* @Description: Insert data to list by given key. 
 * @Input: _head- pointer to list.
 * @Input: _p- the data we want to insert.
 * @Input: _key - the key we insert by the data.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListInsertByKey(Person* _head, int _key, Person* _p);

/* @Description: Remove data from the list by given key. 
 * @Input: _head- pointer to list.
 * @Input: _key - the key we remove by the data.
 * @Input: _item- pointer to the item we remove.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListRemoveByKey(Person* _head, int _key, Person** _item);

/* @Description: Insert data to list by key recursively. 
 * @Input: _head- pointer to list.
 * @Input: _p- the data we want to insert.
 * @Input: _key - the key we insert the data.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListInsertByKeyRec(Person* _head, int _key, Person* _p);

/* @Description: Remove data from the list by given key recursively. 
 * @Input: _head- pointer to list.
 * @Input: _key - the key we remove by the data.
 * @Input: _item- pointer to the item we remove.
 * @Return: Person- the pointer to the head of the list.
*/ 
Person* ListRemoveByKeyRec(Person* _head, int _key, Person** _item);

/* @Description: Flip the list. 
 * @Input: _head- pointer to list.
 * @Return: pointer to the reverse list.
*/ 
Person* Flip(Person* _head);

void PrintList(const Person* _head);


#endif /*__GENERICLIST_H__*/ 
