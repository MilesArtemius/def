#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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



void initStack(ListStack** stack) {
    *stack = (ListStack*) malloc(sizeof(ListStack));
    (*stack)->self = NULL;
    (*stack)->len = 0;
}

int isEmpty(ListStack* stack) {
    return stack->len == 0;
}

int size(ListStack *stack) {
    return stack->len;
}

void push(ListStack* stack, void* data, size_t dataSize) {
    Part* temp = (Part*) malloc(1 * sizeof(Part));
    temp->data = malloc(dataSize);
    temp->dataLen = dataSize;
    memcpy(temp->data, data, dataSize);

    temp->prev = stack->self;
    stack->self = temp;

    stack->len++;
}

void pop(ListStack* stack) {
    Part* tmp = stack->self;
    stack->self = stack->self->prev;
    stack->len--;
    free(tmp);
}

size_t top(ListStack* stack, void** data) { //returns size, passes pointer through data.
    *data = malloc(stack->self->dataLen);
    memcpy(*data, stack->self->data, stack->self->dataLen);
    return stack->self->dataLen;
}



int main(){
    ListStack* stack = NULL;
    initStack(&stack);
    char* command = NULL;
    command = (char*) malloc(10000 * sizeof(char));
    int data = 0;

    scanf("%s", command);
    while (strcmp(command, "exit") != 0) {
        if (strcmp(command, "push") == 0) {
            scanf("%i", &data);
            push(stack, &data, sizeof(int));
            printf("ok\n");
        } else if (strcmp(command, "pop") == 0){
            if (size(stack) == 0) {
                printf("error\n");
                return 0;
            } else {
                int* value = NULL;
                top(stack, (void**) &value);
                printf("%i\n", *value);
                pop(stack);
            }
        } else if (strcmp(command, "top") == 0){
            if (size(stack) == 0) {
                printf("error\n");
                return 0;
            }
            else {
                int* value = NULL;
                top(stack, (void**) &value);
                printf("%i\n", *value);
            }
        } else if (strcmp(command, "size") == 0){
            printf("%i\n", size(stack));
        }

        scanf("%s", command);
    }

    printf("bye\n");
    return 0;
}