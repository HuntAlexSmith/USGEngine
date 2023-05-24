//*****************************************************************************
//  Filename: Scene.h
//  Author:   Hunter Smith
//  Date:     05/23/2023
//  Description:
//      Definition of a Scene class, which will manage all entities.
//*****************************************************************************

#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include "Entity/Entity.h"

typedef std::unordered_map<ID, Entity> EntityMap;

class Scene {
public:
    // Ctor and dtor
    Scene();
    ~Scene();

    // Entity functions
    ID CreateEntity(const std::string& name = "");
    void DestroyEntity(ID id);
    std::pair<bool, std::string> GetEntityName(ID id);
    bool SetEntityName(ID id, const std::string& name);
    std::pair<bool, ID> GetEntityByName(const std::string& name);

    // Friend function for testing
    friend std::ostream& operator<<(std::ostream& os, const Scene& scene) {
        // Print out scene
        std::cout << "Current Scene:" << std::endl;

        // Check for empty container
        if(scene.entityContainer_.empty()) return os;

        for(auto itr : scene.entityContainer_) {
            os << itr.second;
        }

        return os;
    }

private:

    // Entity Container
    EntityMap entityContainer_;

    // Component Pool Container

};

#endif
