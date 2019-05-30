#include "defence.h"

double printTime() {
    struct timeval  tv;
    gettimeofday(&tv, NULL);

    double time_in_mill =
            (tv.tv_sec) * 1000.0 + (tv.tv_usec) / 1000.0 ;
    return time_in_mill;
}

void speedTestL(char* str) {
    double time, newTime;

    ListStack* stack = NULL;
    initStackL(&stack);

    char* command = NULL;
    char* com2 = NULL;
    command = (char*) malloc(1000 * sizeof(char));
    com2 = (char*) malloc(1000 * sizeof(char));
    strcpy(command, str);
    strcpy(com2, str);

    time = printTime();

    char* tok = strtok(command, " ");
    while (tok != NULL) {
        pushL(stack, tok, strlen(tok) * sizeof(char));
        tok = strtok(NULL, " ");
    }
    int hs = stack->len / 2;
    for (int i = 0; i < hs; i++) {
        popL(stack);
    }
    tok = strtok(com2, " ");
    while (tok != NULL) {
        pushL(stack, tok, strlen(tok) * sizeof(char));
        tok = strtok(NULL, " ");
    }

    newTime = printTime();

    printf("Total time is: %lf\n", (newTime - time));
}

void speedTestA(char* str) {
    double time, newTime;

    ArrayStack* stack = NULL;
    initStackA(&stack);

    char* command = NULL;
    char* com2 = NULL;
    command = (char*) malloc(1000 * sizeof(char));
    com2 = (char*) malloc(1000 * sizeof(char));
    strcpy(command, str);
    strcpy(com2, command);

    time = printTime();

    char* tok = strtok(command, " ");
    while (tok != NULL) {
        pushA(stack, tok, strlen(tok) * sizeof(char));
        tok = strtok(NULL, " ");
    }
    int hs = stack->len / 2;
    for (int i = 0; i < hs; i++) {
        popA(stack);
    }
    tok = strtok(com2, " ");
    while (tok != NULL) {
        pushA(stack, tok, strlen(tok) * sizeof(char));
        tok = strtok(NULL, " ");
    }

    newTime = printTime();

    printf("Total time is: %lf\n", (newTime - time));
}

void stackTester(ListStack* stack, void (*proc[3])(ListStack*), int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        proc[i](stack);
    }
}

void testStackTester() {
    ListStack* stack = NULL;
    initStackL(&stack);

    void (*p[3]) (ListStack*) = {testPushL, testSizeL, testTopL};

    stackTester(stack, p, 3);
}

int main() {
    char* string = (char*) malloc(1000 * sizeof(char));
    scanf("%s", string);

    printf("For LIST stack:\n");
    speedTestL(string);
    printf("\nFor ARRAY stack:\n");
    speedTestA(string);

    return 0;
}

// Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
