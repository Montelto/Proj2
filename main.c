#include "threads.h"

int main() {
    printf("1");

    pthread_t read_thread_id, munch1_thread_id, munch2_thread_id,
    write_thread_id;

    Queue *rm = CreateStringQueue(10);
    Queue *mm = CreateStringQueue(10);
    Queue *mw = CreateStringQueue(10);

    Queue munchArgs1[2] = {*rm, *mm};
    Queue munchArgs2[2] = {*mm, *mw};

    printf("a");
    pthread_create(&read_thread_id,
                   NULL,
                   &Reader,
                   (void *)&rm);
    printf("b");
    pthread_create(&munch1_thread_id,
                   NULL,
                   &Munch1,
                   (void *)munchArgs1);
    printf("c");
    pthread_create(&munch2_thread_id,
                   NULL,
                   &Munch2,
                   (void *)munchArgs2);
    printf("d");
    pthread_create(&write_thread_id,
                   NULL,
                   &Writer,
                   (void *)&mw);
    printf("e");

    pthread_join(read_thread_id, NULL);
    pthread_join(munch1_thread_id, NULL);
    pthread_join(munch2_thread_id, NULL);
    pthread_join(write_thread_id, NULL);
}
