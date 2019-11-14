#include "genericDoubleList.h"
#include "hashMap.h"
#include "listStruct.h"
#include "list_itr.h"
#include "mu_test.h"
#include <limits.h>

/************************/
/**functions-under-test**/

void keyDestroy(void* _key)
{
	if(_key == NULL)
	{
		return;
	}
	free(_key);
}

void valDestroy(void* _value)
{
	if(_value == NULL)
	{
		return;
	}
	free(_value);
}

size_t HashFunc(const void* _key)
{
	if(_key == NULL)
	{
		return 0;
	}
	return strlen((char*)_key);
}

int keysEqualFunc (const void* _firstKey, const void* _secondKey)
{
	if(_firstKey == NULL || _secondKey == NULL)
	{
		return FALSE;
	}
	return (_firstKey == _secondKey);
}

void* funcUpdate(void* _value, void* _context)
{
	if (_value == NULL)
	{
		return NULL;
	}
	_value = _context;
	return _value;
}

int	KeyValueAction(const void* _key, void* _value, void* _context)
{
	if (_key == NULL || _value == NULL)
	{
		return 0;
	}
	printf("The key is: %s, the value is: %d\n", (char*)_key, *(int*)_value);
	return 0;
}

/************************/

UNIT(create_hash)	
	HashMap* hash;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	
	free(hash);	
END_UNIT


UNIT(create_null_hash)	
	HashMap* hash;
	hash = HashMap_Create(0, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash == NULL);		
END_UNIT


UNIT(insert_null_hash)	
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};

	ASSERT_THAT(HashMap_Insert(NULL, key, &array[0]) == MAP_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(insert_null_key)	
	HashMap* hash;
	int array[3] = {1,2,3};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);

	ASSERT_THAT(hash != NULL);	
	ASSERT_THAT(HashMap_Insert(hash, NULL, &array[0]) == MAP_KEY_NULL_ERROR);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
END_UNIT


UNIT(insert_key_to_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);

	ASSERT_THAT(hash != NULL);
	
	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(insert_duplicate_key_to_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);

	ASSERT_THAT(hash != NULL);
	
	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Insert(hash, key, &array[2]) == MAP_KEY_DUPLICATE_ERROR);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(insert_after_destroy)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);

	ASSERT_THAT(hash != NULL);
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_UNINITIALIZED_ERROR);	

END_UNIT


UNIT(remove_from_null_hash)	
	int searchKey = 4;
	int* Pvalue;
	int* Pkey;

	ASSERT_THAT(HashMap_Remove(NULL, (void*)&searchKey,(void**)&Pkey, (void**)&Pvalue) == MAP_UNINITIALIZED_ERROR);	

END_UNIT


UNIT(remove_null_key_from_hash)	
	HashMap* hash;
	int* Pvalue;
	int* Pkey;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	
	ASSERT_THAT(HashMap_Remove(hash, NULL, (void**)&Pkey, (void**)&Pvalue) == MAP_KEY_NULL_ERROR);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
END_UNIT


UNIT(remove_key_from_empty_hash)	
	HashMap* hash;
	int searchKey = 4;
	int* Pvalue;
	int* Pkey;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Remove(hash, (void*)&searchKey,(void**)&Pkey, (void**)&Pvalue) == MAP_KEY_NOT_FOUND_ERROR);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
END_UNIT


UNIT(remove_key_that_not_in_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	char key2[16] = {"prego"};
	int array[3] = {1,2,3};
	int* Pvalue;
	int* Pkey;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Remove(hash, key2,(void**)&Pkey, (void**)&Pvalue) == MAP_KEY_NOT_FOUND_ERROR);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(remove_key_from_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};
	int* Pvalue;
	int* Pkey;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Remove(hash, key,(void**)&Pkey, (void**)&Pvalue) == MAP_SUCCESS);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(remove_from_hash_after_destroy)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int* Pvalue;
	int* Pkey;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
	ASSERT_THAT(HashMap_Remove(hash, key, (void**)&Pkey, (void**)&Pvalue) == MAP_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(find_key_in_null_hash)	
	int searchKey = 4;
	int* Pvalue;
	ASSERT_THAT(HashMap_Find(NULL, (void*)&searchKey,(void**)&Pvalue) == MAP_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(find_null_key_in_hash)	
	HashMap* hash;
	int* Pvalue;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	
	ASSERT_THAT(HashMap_Find(hash, NULL, (void**)&Pvalue) == MAP_KEY_NULL_ERROR);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
END_UNIT


UNIT(find_key_in_empty_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int* Pvalue;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	
	ASSERT_THAT(HashMap_Find(hash, key,(void**)&Pvalue) == MAP_KEY_NOT_FOUND_ERROR);	
	HashMap_Destroy(&hash, keyDestroy, valDestroy);
END_UNIT


UNIT(find_key_in_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int array[3] = {1,2,3};
	int* Pvalue;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Find(hash, key,(void**)&Pvalue) == MAP_SUCCESS);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(find_key_that_not_in_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	char key2[16] = {"prego"};
	int array[3] = {1,2,3};
	int* Pvalue;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Find(hash, key2 ,(void**)&Pvalue) == MAP_KEY_NOT_FOUND_ERROR);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(find_key_after_destroy_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	int* Pvalue;
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	HashMap_Destroy(&hash, keyDestroy, valDestroy);
	ASSERT_THAT(HashMap_Find(hash, key,(void**)&Pvalue) == MAP_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(size_of_null_hash)	

	ASSERT_THAT(HashMap_Size(NULL) == 0);	
END_UNIT

UNIT(size_of_hash)	
	HashMap* hash;
	char key[16] = {"nataly"};
	char key2[16] = {"prego"};
	int array[3] = {1,2,3};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash, key, &array[0]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Insert(hash, key2, &array[1]) == MAP_SUCCESS);	
	ASSERT_THAT(HashMap_Size(hash) == 2);	
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT


UNIT(for_each)	
	HashMap* hash;
	char key1[16] = {"nataly"};
	char key2[16] = {"prego"};
	int array[4] = {1,2,3,4};
	hash = HashMap_Create(10, HashFunc, keysEqualFunc);
	ASSERT_THAT(hash != NULL);	

	ASSERT_THAT(HashMap_Insert(hash,key1, &array[0]) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(hash,key2, &array[1]) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_ForEach(hash,KeyValueAction,NULL));
	HashMap_Destroy(&hash, NULL, NULL);
END_UNIT

TEST_SUITE(C Unit Test Demo for mu_test!)
	TEST(create_hash)
	TEST(create_null_hash)
	TEST(insert_null_hash)	
	TEST(insert_null_key)
	TEST(insert_key_to_hash)
	TEST(insert_duplicate_key_to_hash)	
	TEST(insert_after_destroy)
	TEST(remove_from_null_hash)
	TEST(remove_null_key_from_hash)
	TEST(remove_key_from_empty_hash)
	TEST(remove_key_that_not_in_hash)
	TEST(remove_key_from_hash)
	TEST(remove_from_hash_after_destroy)
	TEST(find_key_in_null_hash)
	TEST(find_null_key_in_hash)
	TEST(find_key_in_empty_hash)
	TEST(find_key_in_hash)
	TEST(find_key_that_not_in_hash)
	TEST(find_key_after_destroy_hash)
	TEST(size_of_null_hash)
	TEST(size_of_hash)
	TEST(for_each)
END_SUITE




