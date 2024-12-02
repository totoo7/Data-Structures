# Data Structures Library in C++

This repository contains a collection of fundamental data structures implemented in C++ with a focus on efficiency, flexibility, and clear understanding. The project is structured as a CMake-based library, making it easy to integrate into other C++ projects or build and test independently.

## Data Structures Included

This library provides implementations of the following data structures:

### 1. **Vector**
   - A dynamic array-like container, implemented with templates to support any data type.
   - Includes functionalities like `push_back`, `pop_back`, `operator[]`, and iterators for easy traversal.
   - Dynamically resizes itself when the capacity is exceeded.
   - Supports copy constructor, assignment operator, and deep copying to manage memory safely.

### 2. **LinkedList**
   - A basic linked list implementation supporting insertion and removal of nodes from both ends.
   - Includes functionalities like `push_back`, `push_front`, `pop_back`, `pop_front`, and iteration support via custom iterators.
   - Memory management is handled with dynamic allocation/deallocation.

### 3. **DoublyLinkedList**
   - An enhanced version of the `LinkedList` where each node has pointers to both the next and previous elements.
   - Provides efficient access to both ends of the list and supports operations like `insert_after`, `insert_before`, and deletion from any position in the list.

### 4. **Queue (Implemented with `std::vector`)**
   - A queue implemented using a `std::vector` to store elements.
   - Supports `enqueue` and `dequeue` operations.
   - Efficient resizing and management of the underlying container.
   
### 5. **StaticQueue (Static Circular Queue)**
   - A queue with a fixed size, implemented as a circular buffer.
   - Operations like `enqueue` and `dequeue` are efficiently handled, with no resizing needed.
   - A perfect choice for memory-constrained environments.

### 6. **LinkedQueue**
   - A queue implemented using linked nodes, where each node points to the next one.
   - Supports `enqueue` and `dequeue` operations, with dynamic resizing of the structure.
   - Ensures that the queue operations are efficient, with no need for resizing.

### 7. **Stack (Implemented with `std::vector`)**
   - A stack data structure that uses `std::vector` as the underlying container.
   - Provides standard stack operations: `push`, `pop`, and `top`.
   - Dynamically resizes itself as needed, with efficient memory usage.
   
### 8. **StaticStack**
   - A stack with a fixed size, implemented using a static array.
   - Supports `push`, `pop`, and `top` operations.
   - Suitable for cases where the stack size is known ahead of time.

### 9. **LinkedStack**
   - A stack implemented using linked nodes, where each node points to the next one.
   - Allows for dynamic memory allocation and supports `push`, `pop`, and `top` operations.

## Key Features

- **CMake-based Project**: The library is designed to be used with CMake, making it easy to integrate into larger projects.
- **Template-based Implementations**: All data structures are implemented as templates, allowing them to work with any data type.
- **Memory Management**: Uses dynamic memory allocation/deallocation where appropriate to ensure efficient memory use and prevent memory leaks.
- **Iterators**: Some data structures (like `Vector`, `LinkedList`, and `DoublyLinkedList`) include iterators to facilitate easy traversal and element access.
- **Clear and Modular Design**: Each data structure is encapsulated in its own header file for clarity, and the library can be expanded with additional data structures as needed.
- **Comprehensive Testing with Catch2**: The library includes extensive tests for all data structures using the Catch2 testing framework, ensuring reliability and correctness.