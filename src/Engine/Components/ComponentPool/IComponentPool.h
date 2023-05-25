//*****************************************************************************
//  Filename: Stub.h
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      Stub file for creating new modules as needed.
//*****************************************************************************

#ifndef ICOMPONENTPOOL_H
#define ICOMPONENTPOOL_H

#include "../../../Memory/PoolAlloc.h"
#include "../../../ID/IDGen.h"
#include "../BaseComponent/IComponent.h"
#include <unordered_map>

typedef std::unordered_map<ID, IComponent*> EntityComponentMap;

class IComponentPool {
public:
    // Constructor for pool
    IComponentPool(size_t objSize, size_t objPerPage) : allocator_(objSize, objPerPage), entityComponentMap_() {}

    // Destructor for pool
    ~IComponentPool() {
        if(entityComponentMap_.empty()) return;
        for(auto itr : entityComponentMap_) {
            allocator_.Free(itr.second);
        }
    }

protected:

    PoolAlloc allocator_;
    EntityComponentMap entityComponentMap_;

private:

};

#endif
