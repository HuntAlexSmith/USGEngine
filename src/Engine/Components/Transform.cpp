//*****************************************************************************
//  Filename: Transform.cpp
//  Author:   Hunter Smith
//  Date:     05/24/2023
//  Description:
//      Stub file for creating new modules as needed.
//*****************************************************************************

#include "Transform.h"

Transform::Transform() :
    Component()
    , position(glm::vec4(0))
    , rotation(glm::vec4(0))
    , scale(glm::vec3(0))
{
}
