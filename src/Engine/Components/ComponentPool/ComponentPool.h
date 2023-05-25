//*****************************************************************************
//  Filename: Stub.h
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      Stub file for creating new modules as needed.
//*****************************************************************************

#ifndef COMPONENTPOOL_H
#define COMPONENTPOOL_H

#include "IComponentPool.h"

const size_t objectsPerPage = 512;

template <class T>
class ComponentPool : public IComponentPool {
public:
    // Constructor for typed component pool
    ComponentPool() : IComponentPool(sizeof(T), objectsPerPage) {}

    // Member functions for adding, getting, and removing components
    IComponent* CreateComponent(ID entityID) {
        // Component already exists, just give it back
        if(entityComponentMap_.find(entityID) != entityComponentMap_.end())
            return entityComponentMap_[entityID];

        // Otherwise, create a new component
        T* component = new (allocator_.Allocate()) T(); // Placement new
        entityComponentMap_[entityID] = component;
        return component;
    }

    IComponent* GetComponent(ID entityID) {
        // If the component is never found, just return null
        if(entityComponentMap_.find(entityID) == entityComponentMap_.end())
            return nullptr;

        // Otherwise, return what was found
        return entityComponentMap_[entityID];
    }

    void DeleteComponent(ID entityID) {
        // If the component isn't found, just delete
        if(entityComponentMap_.find(entityID) == entityComponentMap_.end())
            return;

        // Get the component and return it to memory, remember to invoke destructor
        T* component = static_cast<T*>(GetComponent(entityID));
        entityComponentMap_.erase(entityID);
        component->~T();
        allocator_.Free(component);
    }

private:



};

#endif
