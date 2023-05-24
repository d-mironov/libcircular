#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include <stdint.h>
#include <stdbool.h>

#ifndef RINGBUFFER_SIZE
    #define RINGBUFFER_SIZE 16
#endif // RINGBUFFER_SIZE

typedef uint8_t byte;

typedef unsigned int uint;

typedef struct ringbuffer_t {
    byte buffer[RINGBUFFER_SIZE];
    uint write_ptr;
    uint read_ptr;
} Ringbuffer;


// Initialize ringbuffer with default values
void ringbuffer_init(struct ringbuffer_t* rb);
// Push data to ringbuffer
bool ringbuffer_push(struct ringbuffer_t* rb, byte data);
// Read from ringbuffer
bool ringbuffer_pop(struct ringbuffer_t* rb, byte *buf);

// Check if the ringbuffer is empty
bool ringbuffer_is_empty(struct ringbuffer_t rb);
// Check if the ringbuffer is full
bool ringbuffer_is_full(struct ringbuffer_t rb);

void _ptr_inc(uint* pointer);

#endif
