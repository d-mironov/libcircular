# libcircular - A static memory ringbuffer library

A static Ringbuffer library for usage in Embedded Systems

## Usage

**Simple example:**
```c
Ringbuffer buffer;
// Init the ringbuffer to 0
ringbuffer_init(&buffer);

// Push data to ringbuffer
ringbuffer_push(&buffer, 10);

// Read data from the ringbuffer
byte buf;
ringbuffer_pop(&buffer, &buf);
```

**Checking for full or empty buffer**
```c
Ringbuffer buffer;
// Init the ringbuffer to 0
ringbuffer_init(&buffer);

// Push data to ringbuffer
if (!ringbuffer_push(&buffer, 10)) {
    printf("[x] Ringbuffer full\n");
}

// Read data from the ringbuffer
byte buf;
if (!ringbuffer_pop(&buffer, &buf)) {
    printf("[x] Ringbuffer empty\n");
}

// Check if the ringbuffer is empty
ringbuffer_empty(buffer);
// Check if the ringbuffer is full
ringbuffer_full(buffer);
```

## Configuration

The size of the ringbuffer can be set with the `RINGBUFFER_SIZE` define inside 
[ringbuffer.h](./ringbuffer.h). Default is set to `16`.
