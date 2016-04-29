#ifndef COMMON_H_
#define COMMON_H_

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef uint8_t bool;

#pragma pack (push, 1)
typedef struct {
	uint32_t t1;
	char c;
	int8_t t2;
} content_t;
#pragma pack (pop)

#endif
