#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#ifndef RINGBUFFER_SIZE
    #define RINGBUFFER_SIZE 16
#endif // RINGBUFFER_SIZE

typedef uint8_t byte;

typedef unsigned int uint;

typedef struct {
    byte *buffer;
    size_t size;
    volatile size_t head;
    volatile size_t tail;
} ringbuffer_t;

#define RINGBUFFER_DEFINE(name, n)                                                  \
    static_assert((n & (n - 1)) == 0, "Size of Ringbuffer needs to be power of 2"); \
    static uint8_t name##_buffer[n];                                                \
    static ringbuffer_t name = {                                                    \
        .buffer = name##_buffer,                                                    \
        .size = n,                                                                  \
        .head = 0,                                                                  \
        .tail = 0                                                                   \
    }                                          


/**
 * Check if the ringbuffer is empty
 *
 * @param rb Ringbuffer to check
 *
 * @return `true` if the buffer is empty, else `false`
 */
static inline bool ringbuffer_is_empty(const ringbuffer_t *rb) {
    return rb->head == rb->tail;
}

/**
 * Check if the ringbuffer is full
 *
 * @param rb Ringbuffer to check
 *
 * @return `true` if the buffer is full, else `false`
 */
static inline bool ringbuffer_is_full(const ringbuffer_t *rb) {
    return ((rb->head + 1) & (rb->size - 1)) == rb->tail;
}


static inline size_t _ptr_inc(size_t index, size_t size) {
    return (index + 1) & (size - 1);
}


// Initialize ringbuffer with default values
void ringbuffer_init(ringbuffer_t* rb);
// Push data to ringbuffer
bool ringbuffer_push(ringbuffer_t* rb, byte data);
// Read from ringbuffer
bool ringbuffer_pop(ringbuffer_t* rb, byte *buf);

#endif
