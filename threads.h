//
// Created by Joseph McFarland on 07-Oct-20.
//

#ifndef PROJ2_THREADS_H
#define PROJ2_THREADS_H

#include "queue.h"
#include <endian.h>
#include <string.h>
#include <errno.h>

static int bufferSize = 4096; // maximum line read size

static char newLine = '\n';

// receives a Queue of char* that Reader reads a line of input from standard
// input
// into, this Queue will be used by Munch1
void Reader(Queue *out);

// Receives a Queue of char* changes ' ' to '*' and writes to a Queue for
// use by Munch2
void Munch1(Queue *in, Queue *out);

// Receives a Queue of char*, changes lower case letters to uppercase and
// writes to a Queue for use by Writer
void Munch2(Queue *in, Queue *out);

// Receives a Queue of char*, of mutated strings then writes the strings
void Writer(Queue *in);



#endif //PROJ2_THREADS_H
