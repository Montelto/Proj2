//
// Created by Joseph McFarland on 07-Oct-20.
//

#include "threads.h"

void Reader(Queue *out)
{
    // Unsure how to check line size and skip line as well as read whole line.
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    lineSize = getline(&line, &len, stdin);
    printf("%s",line);
    if (lineSize <= bufferSize) {
        EnqueueString(out, line);
    }
}

void Munch1(Queue *q[])
{
    const char space = ' ';
    const char asterisk = '*';
    char *line;
    line = DequeueString(q[0]);

    // reads "line" char by char detecting for spaces and end of line
    for (int i = 0; i < bufferSize; i++)
    {
        if (*(line + i) == newLine || (line + i) == NULL)
            break;
        else if (*(line + i) == space)
            *(line + i) = asterisk;
    }

    EnqueueString(q[1], line);
}

void Munch2(Queue *q[])
{
    const int asciiDiff = 32;
    const int a = 97;
    const int z = 122;
    char *line;
    line = DequeueString(q[0]);

    // reads "line" char by char detecting for lowercase and end of line
    for (int i = 0; i < bufferSize; i++)
    {
        if (*(line + i) == newLine || (line + i) == NULL)
            break;
        else if (*(line + i) >= a && (*line + i) <= z)
            *(line + i) = (char)(*(line + i) - asciiDiff);
    }

    EnqueueString(q[1], line);
}

void Writer(Queue *in)
{
    char *line;
    line = DequeueString(in);

    // reads "line" char by char printing out
    for (int i = 0; i < bufferSize; i++)
    {
        if (*(line + i) == newLine || (line + i) == NULL)
            break;
        else
            printf("%c", *(line + i));
    }

    printf("%c", newLine);
    free(line);
}