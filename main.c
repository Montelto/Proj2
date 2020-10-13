#include "threads.h"

int main() {
    printf("I");
    Queue *q = CreateStringQueue(10);
    printf("\n2\n");
    Reader(q);
}