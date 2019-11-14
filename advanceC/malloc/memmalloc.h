/*
 *  @file memmalloc.h
 * 		a framework for malloc.
 * 		Version 0.01
 *  @author Nataly Prego.
 */

#ifndef __MEMMALLOC_H__
#define __MEMMALLOC_H__


void* memInit(void* _mem, size_t _size);

void* memMalloc(void* _buffStart, size_t _size);

void memFree(void* _buff);

void mallocForEach(void* _bufStart);


#endif /*__MEMMALLOC_H__*/
