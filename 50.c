//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* buffer;
    int capacity;
    int size;
    int head;
    int tail;
} CircularBuffer;

// Initialize the circular buffer
CircularBuffer* createBuffer(int initial_capacity) {
    CircularBuffer* cb = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    if (!cb) return NULL;
    
    cb->buffer = (int*)calloc(initial_capacity, sizeof(int));
    if (!cb->buffer) {
        free(cb);
        return NULL;
    }
    
    cb->capacity = initial_capacity;
    cb->size = 0;
    cb->head = 0;
    cb->tail = 0;
    return cb;
}

// Check if buffer is full
int isFull(CircularBuffer* cb) {
    return cb->size == cb->capacity;
}

// Check if buffer is empty
int isEmpty(CircularBuffer* cb) {
    return cb->size == 0;
}

// Resize the buffer to new capacity
int resizeBuffer(CircularBuffer* cb, int new_capacity) {
    if (new_capacity < cb->size) return 0;  // Can't resize smaller than current size
    
    int* new_buffer = (int*)calloc(new_capacity, sizeof(int));
    if (!new_buffer) return 0;
    
    // Copy elements to new buffer in order
    int count = 0;
    int curr = cb->head;
    for (int i = 0; i < cb->size; i++) {
        new_buffer[count++] = cb->buffer[curr];
        curr = (curr + 1) % cb->capacity;
    }
    
    free(cb->buffer);
    cb->buffer = new_buffer;
    cb->capacity = new_capacity;
    cb->head = 0;
    cb->tail = count;
    return 1;
}

// Add element to buffer
int addElement(CircularBuffer* cb, int value) {
    if (isFull(cb)) {
        // Auto-resize by doubling capacity when full
        if (!resizeBuffer(cb, cb->capacity * 2)) return 0;
    }
    
    cb->buffer[cb->tail] = value;
    cb->tail = (cb->tail + 1) % cb->capacity;
    cb->size++;
    return 1;
}

// Remove element from buffer
int removeElement(CircularBuffer* cb) {
    if (isEmpty(cb)) return -1;
    
    int value = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->capacity;
    cb->size--;
    
    // Optional: Shrink buffer if it's too empty (less than 25% utilized)
    if (cb->size > 0 && cb->size < cb->capacity / 4) {
        resizeBuffer(cb, cb->capacity / 2);
    }
    
    return value;
}

// Print current buffer contents
void printBuffer(CircularBuffer* cb) {
    if (isEmpty(cb)) {
        printf("Empty\n");
        return;
    }
    
    int curr = cb->head;
    for (int i = 0; i < cb->size; i++) {
        printf("%d ", cb->buffer[curr]);
        curr = (curr + 1) % cb->capacity;
    }
    printf("\n");
}

// Free buffer memory
void freeBuffer(CircularBuffer* cb) {
    if (cb) {
        free(cb->buffer);
        free(cb);
    }
}

// Main function to handle operations
int main() {
    int n;
    scanf("%d", &n);
    
    CircularBuffer* cb = createBuffer(2);  // Start with small initial capacity
    if (!cb) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    char operation[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "ADD") == 0) {
            int value;
            scanf("%d", &value);
            if (!addElement(cb, value)) {
                printf("Failed to add element\n");
                continue;
            }
        }
        else if (strcmp(operation, "REMOVE") == 0) {
            int removed = removeElement(cb);
            if (removed == -1) {
                printf("Buffer is empty\n");
                continue;
            }
        }
        else if (strcmp(operation, "RESIZE") == 0) {
            int new_size;
            scanf("%d", &new_size);
            if (!resizeBuffer(cb, new_size)) {
                printf("Resize failed\n");
                continue;
            }
        }
        
        printBuffer(cb);
    }
    
    freeBuffer(cb);
    return 0;
}
