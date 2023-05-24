//*****************************************************************************
//  Filename: IAllocator.h
//  Author:   Hunter Smith
//  Date:     05/23/2023
//  Description:
//      Abstract class for defining what a memory allocator needs to do
//*****************************************************************************

#ifndef IALLOCATOR_H
#define IALLOCATOR_H

class IAllocator {
public:

    // Define pure virtual functions that need to be defined (Allocate and Free mostly)
    virtual void* Allocate() = 0;
    virtual void Free(void*) = 0;

private:
};

#endif
