//*****************************************************************************
//  Filename: Entity.h
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Definition of an entity object
//*****************************************************************************

#ifndef ENTITY_H
#define ENTITY_H

#include "../../ID/IDGen.h"
#include <string>
#include <iostream>

class Entity {
public:
    // Ctors
    Entity();
    Entity(const std::string& name);

    // Dtor
    ~Entity();

    // Getters
    [[nodiscard]] inline ID GetID() const { return id_; }
    [[nodiscard]] inline std::string GetName() const { return name_; }

    // Setters
    inline void SetName(const std::string& name) { name_ = name; }

    // Print function
    friend std::ostream& operator<<(std::ostream& os, const Entity& entity) {
        os << "Entity ID: " << entity.id_ << "\nEntity Name: " << entity.name_ << std::endl;
        return os;
    }

private:

    ID id_;            // the actual id of the object for unique identification
    std::string name_; // Name of the object for easy of identity

};

#endif
