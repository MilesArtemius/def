#ifndef UNTITLED_DEFENCE_H
#define UNTITLED_DEFENCE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>

struct Part {
    void* data;
    size_t dataLen;
    struct Part *prev;
};

typedef struct Part Part;



typedef struct {
    int len;
    Part* self;
} ListStack;

typedef struct {
    Part** self;
    int len;
    int capability;
} ArrayStack;



void initStackL(ListStack** stack);
int isEmptyL(ListStack* stack);
int sizeL(ListStack *stack);
void pushL(ListStack* stack, void* data, size_t dataSize);
void popL(ListStack* stack);
size_t topL(ListStack* stack, void** data);

void initStackA(ArrayStack** stack);
int isEmptyA(ArrayStack* stack);
int countA(ArrayStack* stack);
void pushA(ArrayStack* stack, void* data, size_t dataSize);
void popA(ArrayStack* stack);
size_t topA(ArrayStack* stack, void** data);

void testPushL(ListStack* stack);
void testTopL(ListStack* stack);
void testSizeL(ListStack* stack);

#endif //UNTITLED_DEFENCE_H
