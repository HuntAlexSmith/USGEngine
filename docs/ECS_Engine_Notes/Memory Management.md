[Here](https://github.com/talhacali/ECS/tree/master) is a repo that has some decent source code for understanding how to handle memory for components in ECS. They use a similar idea with having a free list as well as a general linear allocator. Personally, I like the idea of having a PoolAllocator, which can allow for re-use of previous memory better.

## May 23rd
Started out with the memory management for component pools. Currently have a base allocator and working on a pool allocator. The base allocator class is purely just an Allocate and Free pure virtual function, so simple to define a new allocator. Blanking, so going to take a break. Need to figure out how I want to handle allocations. If components take up small amounts of data, the allocations are easy to understand, but also want to take into account page sizes.

## May 24th
Something I have considered while working on this: it may be a good idea to have a debug setting that enables tracking bad memory issues, because checking for memory issues is very expensive, especially when validating freeing an address.