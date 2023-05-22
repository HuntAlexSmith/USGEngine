//*****************************************************************************
//  Filename: Entity.cpp
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Implementation file for an Entity
//*****************************************************************************

#include "Entity.h"

Entity::Entity() :
    id_(GenID())
    , name_()
{
}

Entity::Entity(const std::string& name) :
    id_(GenID())
    , name_(name)
{
}

Entity::~Entity() {
    // If ID generation is changed and want to give id back, do it here
}
