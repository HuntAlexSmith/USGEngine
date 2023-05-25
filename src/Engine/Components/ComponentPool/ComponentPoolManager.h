//*****************************************************************************
//  Filename: ComponentPoolManager.h
//  Author:   Hunter Smith
//  Date:     05/24/2023
//  Description:
//      Definition of component pool manager
//*****************************************************************************

#ifndef COMPONENTPOOLMANAGER_H
#define COMPONENTPOOLMANAGER_H

#include "IComponentPool.h"
#include "ComponentPool.h"

typedef std::unordered_map<ClassID, IComponentPool*> ComponentPoolMap;

class ComponentPoolManager {
public:
    // Destructor
    ~ComponentPoolManager() {
        if(compPoolMap_.empty())
            return;
        for(auto itr : compPoolMap_) {
            delete itr.second;
        }
    }

    // Member functions
    template <class T>
    IComponent* CreateComponent(ID entityID) {
        ComponentPool<T>* pool = GetComponentPool<T>();
        return pool->CreateComponent(entityID);
    }

    template <class T>
    IComponent* GetComponent(ID entityID) {
        ComponentPool<T>* pool = GetComponentPool<T>();
        return pool->GetComponent(entityID);
    }

    template <class T>
    void DeleteComponent(ID entityID) {
        ComponentPool<T>* pool = GetComponentPool<T>();
        pool->DeleteComponent(entityID);
    }

private:
    // Templated function for getting the desired pool
    template <class T>
    ComponentPool<T>* GetComponentPool() {
        auto itr = compPoolMap_.find(T::classID);
        ComponentPool<T>* pool = nullptr;
        if(itr == compPoolMap_.end()) {
            // Pool wasn't found, time to make it
            pool = new ComponentPool<T>();
            compPoolMap_[T::classID] = pool;
        }
        else {
            pool = static_cast<ComponentPool<T>*>(itr->second);
        }

        return pool;
    }

    ComponentPoolMap compPoolMap_;

};

#endif //USGENGINE_STUB_H
