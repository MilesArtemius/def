#include "defence.h"

void initStackL(ListStack** stack) {
    *stack = (ListStack*) malloc(sizeof(ListStack));
    (*stack)->self = NULL;
    (*stack)->len = 0;
}

int isEmptyL(ListStack* stack) {
    return stack->len == 0;
}

int sizeL(ListStack *stack) {
    return stack->len;
}

void pushL(ListStack* stack, void* data, size_t dataSize) {
    Part* temp = (Part*) malloc(1 * sizeof(Part));
    temp->data = malloc(dataSize);
    temp->dataLen = dataSize;
    memcpy(temp->data, data, dataSize);

    temp->prev = stack->self;
    stack->self = temp;

    stack->len++;
}

void popL(ListStack* stack) {
    Part* tmp = stack->self;
    stack->self = stack->self->prev;
    stack->len--;
    free(tmp);
}

size_t topL(ListStack* stack, void** data) { //returns size, passes pointer through data.
    *data = malloc(stack->self->dataLen);
    memcpy(*data, stack->self->data, stack->self->dataLen);
    return stack->self->dataLen;
}



void initStackA(ArrayStack** stack) {
    *stack = (ArrayStack*) malloc(sizeof(ArrayStack));
    (*stack)->self = NULL;
    (*stack)->len = 0;
    (*stack)->capability = 0;
}

int isEmptyA(ArrayStack* stack) {
    return stack->len == 0;
}

int countA(ArrayStack* stack) {
    return stack->len;
}

void pushA(ArrayStack* stack, void* data, size_t dataSize) {
    Part* temp = (Part*) malloc(1 * sizeof(Part));
    temp->data = malloc(dataSize);
    temp->dataLen = dataSize;
    memcpy(temp->data, data, dataSize);

    if (stack->capability <= stack->len) {
        stack->self = realloc(stack->self, (++(stack->len)) * sizeof(Part *));
        stack->self[stack->len - 1] = temp;

        stack->capability++;
    } else {
        stack->self[(++stack->len)-1] = temp;
    }
}

void popA(ArrayStack* stack) {
    Part* tmp = stack->self[stack->len-1];
    stack->self[stack->len-1] = NULL;
    stack->len--;
    free(tmp);
}

size_t topA(ArrayStack* stack, void** data) {
    *data = malloc(stack->self[stack->len-1]->dataLen);
    memcpy(*data, stack->self[stack->len-1]->data, stack->self[stack->len-1]->dataLen);
    return stack->self[stack->len-1]->dataLen;
}



void testPushL(ListStack* stack) {
    int test = 87;
    int* dataTest = &test;
    pushL(stack, dataTest, sizeof(int*));
}

void testTopL(ListStack* stack) {
    int* value = NULL;
    topL(stack, (void**) &value);
    printf("Top: %i\n", *value);
}

void testSizeL(ListStack* stack) {
    printf("Size: %i\n", sizeL(stack));
}
