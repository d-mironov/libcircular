#include "ringbuffer.h"

/**
 * Initialize the ringbuffer and the pointers with 0
 *
 * @param rb Pointer to the ringbuffer
 */
void ringbuffer_init(ringbuffer_t* rb) {
    for (uint i = 0; i < rb->size; i++) {
        rb->buffer[i] = 0;
    }
    rb->head = 0;
    rb->tail = 0;
}




/**
 * Push data to the ringbuffer if the ringbuffer is not full
 *
 * @param rb Pointer to the ringbuffer to write to
 * @param data Data to push into the ringbuffer
 *
 * @return `true` if write was successsful, if buffer full return `false`
 */
bool ringbuffer_push(ringbuffer_t *rb, byte data) {
    if (ringbuffer_is_full(rb)) {
        return false;
    }
    rb->buffer[rb->head] = data;
    rb->head = _ptr_inc(rb->head, rb->size);
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
bool ringbuffer_pop(ringbuffer_t *rb, byte *buf) {
    // Return `false` if the ringbuffer is empty
    if (ringbuffer_is_empty(rb) == true) {
        return false;
    }
    // Read data from bounty
    *buf = rb->buffer[rb->tail];
    // increment read pointer
    rb->tail = _ptr_inc(rb->tail, rb->size);
    return true;
}
