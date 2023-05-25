//*****************************************************************************
//  Filename: PoolAlloc.cpp
//  Author:   Hunter Smith
//  Date:     05/23/2023
//  Description:
//      Stub file for creating new modules as needed.
//*****************************************************************************

#include "PoolAlloc.h"

static const unsigned char AllocPattern = 0xAA;
static const unsigned char FreePattern = 0xFF;

// Ctor and dtor
PoolAlloc::PoolAlloc() :
    objSize_(0)
    , objPerPage_(0)
    , pageSize_(0)
    , debugFlag_(false)
    , needInit_(true)
    , numAllocs_(0)
    , numFrees_(0)
    , pageList_()
    , freeList_()
{
}

PoolAlloc::PoolAlloc(size_t objSize, size_t objPerPage, bool debug) :
    objSize_(objSize)
    , objPerPage_(objPerPage)
    , pageSize_(objSize * objPerPage)
    , debugFlag_(debug)
    , needInit_(false)
    , numAllocs_(0)
    , numFrees_(0)
    , pageList_()
    , freeList_()
{
    // For construction, allocate a page
    AllocatePage();
}

PoolAlloc::~PoolAlloc() {
    // When the allocator is destroyed, check that the number of allocations is equal to the number of frees
    if(numAllocs_ != numFrees_) {
        std::cout << "Memory Leak Detected!\n";
        std::cout << "Number of Objects not freed: " << numAllocs_ - numFrees_ << "\n\n";
    }

    // Free all the pages on the page list
    while(!pageList_.empty()) {
        void* pageToFree = pageList_.back();
        pageList_.pop_back();
        free(pageToFree); // Used malloc to allocate page
    }
}

// Allocate memory from the allocator
void* PoolAlloc::Allocate() {
    // Hasn't been initialized yet
    if(needInit_)
        return nullptr;

    // If free list is empty, need to allocate another page
    if(freeList_.empty())
        AllocatePage();

    // Have guaranteed free list isn't empty, take from front and give addr
    void* addrToGive = freeList_.front();
    freeList_.pop_front();

    // Assign alloc pattern for debug
    if(debugFlag_)
        memset(addrToGive, AllocPattern, objSize_);

    // Remember to increment number allocations
    numAllocs_++;
    return addrToGive;
}

// Return memory to the allocator
void PoolAlloc::Free(void* addr) {
    // Verify the free of given addr
    bool isValid = VerifyFree(addr);
    if(!isValid) {
        // Free is not valid, early return
        // TODO: Have better error handling when a free is not valid
        return;
    }

    // Address is valid, return it to free list and increment free count
    numFrees_++;
    freeList_.push_front(addr);

    // Fill that portion of memory with the freed pattern for debug
    if(debugFlag_)
        memset(addr, FreePattern, objSize_);
}

// Function for initialize
void PoolAlloc::Init(size_t objSize, size_t objPerPage, bool debug) {
    if(needInit_) {
        needInit_ = false;
        debugFlag_ = debug;
        objSize_ = objSize;
        objPerPage_ = objPerPage;
        pageSize_ = objSize_ * objPerPage_;
        AllocatePage();
    }
}

void PoolAlloc::AllocatePage() {
    // Allocate a new page and add it to page list
    void* newPage = calloc(1, pageSize_);
    pageList_.push_back(newPage);

    // Now get all free spaces for the free list
    for(int i = 0; i < objPerPage_; ++i) {
        // Sizes are in bytes, so reinterpret as char*
        auto freeAddr = reinterpret_cast<unsigned char*>(newPage) + (i * objSize_);

        // Put the addr on the free list
        freeList_.push_back(reinterpret_cast<void*>(freeAddr));
    }
}

bool PoolAlloc::VerifyFree(void* addr) {
    // Cast the address given
    auto addrCast = reinterpret_cast<unsigned char*>(addr);

    // Check that the address fits within any of the allocated pages
    for(void* page : pageList_) {
        // Cast the page pointer
        auto pageCast = reinterpret_cast<unsigned char*>(page);

        // Calculate memory locations
        long long memResult = addrCast - pageCast;

        // If result is negative or greater than page size, ignore it, not on this page
        if(memResult < 0 || memResult > pageSize_)
            continue;

        // Memory is on this page, verify that it is on the bounds
        if(memResult % objSize_ == 0)
            return true;
    }

    // Will also want to check for a double free on the free list
    if(!freeList_.empty()) { // Need to be careful if free list is empty
        for(void* freeAddr : freeList_) {
            if(freeAddr == addr) {
                std::cout << "Double Free Detected!\n";
                std::cout << "Attempted to free address: " << addr << "\n\n";
                return false;
            }
        }
    }

    // Checked all pages, this free is not valid
    return false;
}
