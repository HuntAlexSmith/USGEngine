//*****************************************************************************
//  Filename: Scene.cpp
//  Author:   Hunter Smith
//  Date:     05/23/2023
//  Description:
//      Implementation of the scene class
//*****************************************************************************

#include "Scene.h"

// Ctor and dtor
Scene::Scene() :
    entityContainer_()
{
}

Scene::~Scene() {

}

// Function for creating entities
ID Scene::CreateEntity(const std::string& name) {
    Entity newEntity(name);
    entityContainer_.insert(std::make_pair(newEntity.GetID(), newEntity));
    return newEntity.GetID();
}

// Function for destroying entities
void Scene::DestroyEntity(ID id) {
    // Try to find the entity
    auto findResult = entityContainer_.find(id);

    // Couldn't find it, just return
    if(findResult == entityContainer_.end())
        return;

    // Found the entity, remove it from the container
    entityContainer_.erase(findResult);
}

// Function for getting the name of an entity
std::pair<bool, std::string> Scene::GetEntityName(ID id) {
    // Try to find entity with given id
    auto findResult = entityContainer_.find(id);

    // ID wasn't found, return false with empty string
    if(findResult == entityContainer_.end())
        return std::make_pair(false, "");

    // Otherwise entity was found
    return std::make_pair(true, findResult->second.GetName());
}

// Function for setting the name of an entity
bool Scene::SetEntityName(ID id, const std::string& name) {
    // Try to find entity with given id
    auto findResult = entityContainer_.find(id);

    // ID wasn't found, return false
    if(findResult == entityContainer_.end())
        return false;

    // Set the entity name and return true
    findResult->second.SetName(name);
    return true;
}

// Get entity by name function
std::pair<bool, ID> Scene::GetEntityByName(const std::string& name) {
    // Check if container is empty
    if(entityContainer_.empty())
        return std::make_pair(false, 0);

    // Iterate over entity container to find first entity with given name
    for(auto& itr : entityContainer_) {
        if(itr.second.GetName().compare(name) == 0)
            return std::make_pair(true, itr.second.GetID());
    }

    // No entity found
    return std::make_pair(false, 0);
}
