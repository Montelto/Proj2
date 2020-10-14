#include "threads.h"

int main(int argc, char* argv[]) {

    pthread_t  read_thread_id;
    pthread_t  munch1_thread_id;
    pthread_t  munch2_thread_id;
    pthread_t  write_thread_id;

    Queue *rm = CreateStringQueue(10);
    Queue *mm = CreateStringQueue(10);
    Queue *mw = CreateStringQueue(10);

    Queue munchArgs1[2] = {(pthread_mutex_t *) &rm, (pthread_cond_t *) &mm};
    Queue munchArgs2[2] = {(pthread_mutex_t *) &mm, (pthread_cond_t *) &mw};

    pthread_create(&read_thread_id,
            NULL,
            &Reader,
            (void *)&rm);
    pthread_create(&munch1_thread_id,
            NULL,
            &Munch1,
            (void*)&munchArgs1);
    pthread_create(&munch2_thread_id,
            NULL,
            &Munch2,
            (void*)&munchArgs2);
    pthread_create(&write_thread_id,
            NULL,
            &Writer,
            (void *)&mw);

    pthread_exit(NULL);
}
