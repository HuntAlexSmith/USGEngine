//*****************************************************************************
//  Filename: Entity.cpp
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Implementation file for an Entity
//*****************************************************************************

#include "Entity.h"

Entity::Entity() :
    id_(GenEntityID())
    , name_("Entity")
{
}

Entity::Entity(const std::string& name) :
    id_(GenEntityID())
    , name_(name)
{
}

Entity::~Entity() {
    // If ID generation is changed and want to give id back, do it here
}
