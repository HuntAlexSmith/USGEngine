//*****************************************************************************
//  Filename: PoolAlloc.h
//  Author:   Hunter Smith
//  Date:     05/23/2023
//  Description:
//      Header for defining what a Pool Allocator is
//*****************************************************************************

#ifndef POOLALLOC_H
#define POOLALLOC_H

#include "IAllocator.h"
#include <iostream>
#include <iomanip>
#include <list>

class PoolAlloc : public IAllocator {
public:

    // Ctor and dtor
    PoolAlloc();
    PoolAlloc(size_t objSize, size_t objPerPage, bool debug=false);
    ~PoolAlloc();

    // Overrides
    void* Allocate() override;
    void Free(void*) override;

    // Function for initializing a pool allocator
    void Init(size_t objSize, size_t objPerPage, bool debug=false);

    // Print function
    friend std::ostream& operator<<(std::ostream& os, const PoolAlloc& allocator) {
        for(void* page : allocator.pageList_) {
            auto pageCast = reinterpret_cast<unsigned char*>(page);
            os << "Page 0x" << page << ":\n";
            for(int i = 0; i < allocator.objPerPage_; ++i) {
                auto memoryLoc = pageCast + (i * allocator.objSize_);
                os << "0x" << std::hex << reinterpret_cast<void*>(memoryLoc) << "  ";
                for(int j = 0; j < allocator.objSize_; ++j) {
                    os << std::setw(2) << std::setfill('0') << std::hex << (int)*(memoryLoc + j) << "  ";
                }
                os << "\n";
            }
            os << "\n";
        }
        return os;
    }

private:

    // Helper functions
    void AllocatePage();
    bool VerifyFree(void* addr);

    // Basic config info
    size_t objSize_;
    size_t objPerPage_;
    size_t pageSize_;
    bool debugFlag_;
    bool needInit_;

    // Keep track of how many times Allocate and Free were called and successful
    unsigned numAllocs_;
    unsigned numFrees_;

    // Pointer to pages
    std::list<void*> pageList_;

    // Free List
    std::list<void*> freeList_;

};

#endif
