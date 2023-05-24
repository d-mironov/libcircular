#include "ringbuffer.h"

/**
 * Initialize the ringbuffer and the pointers with 0
 *
 * @param rb Pointer to the ringbuffer
 */
void ringbuffer_init(struct ringbuffer_t* rb) {
    for (uint i = 0; i < RINGBUFFER_SIZE; i++) {
        rb->buffer[i] = 0;
    }
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}


/**
 * Push data to the ringbuffer if the ringbuffer is not full
 *
 * @param rb Pointer to the ringbuffer to write to
 * @param data Data to push into the ringbuffer
 *
 * @return `true` if write was successsful, if buffer full return `false`
 */
bool ringbuffer_push(struct ringbuffer_t *rb, byte data) {
    // Return `false` if the ringbuffer is full
    if (ringbuffer_is_full(*rb) == true) {
        return false;
    }
    // Put data in the buffer
    rb->buffer[rb->write_ptr] = data;
    // Increment write pointer
    _ptr_inc(&rb->write_ptr);
    return true;
}

/**
 * Read data from the ringbuffer if there is data to read
 * 
 * @param rb Pointer to the ringbuffer to read from
 * @param buf Buffer to store the read value in
 *
 * @return `true` if read was successful, else `false`
 */
bool ringbuffer_pop(struct ringbuffer_t *rb, byte *buf) {
    // Return `false` if the ringbuffer is empty
    if (ringbuffer_is_empty(*rb) == true) {
        return false;
    }
    // Read data from bounty
    *buf = rb->buffer[rb->read_ptr];
    // increment read pointer
    _ptr_inc(&rb->read_ptr);
    return true;
}

/**
 * Check if the ringbuffer is empty
 *
 * @param rb Rinbuffer to check
 *
 * @return `true` if the buffer is empty, else `false`
 */
bool ringbuffer_is_empty(struct ringbuffer_t rb) {
    return rb.read_ptr == rb.write_ptr;
}

/**
 * Check if the ringbuffer is full
 *
 * @param rb Rinbuffer to check
 *
 * @return `true` if the buffer is full, else `false`
 */
bool ringbuffer_is_full(struct ringbuffer_t rb) {
    return ((rb.write_ptr + 1) % RINGBUFFER_SIZE) == rb.read_ptr;
}

/**
 * Increment `pointer` and wrap around the `RINGBUFFER_SIZE`
 */
void _ptr_inc(uint* pointer) {
    *pointer = (*pointer + 1) % RINGBUFFER_SIZE;
}
