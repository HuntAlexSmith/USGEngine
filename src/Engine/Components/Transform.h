//*****************************************************************************
//  Filename: Transform.h
//  Author:   Hunter Smith
//  Date:     05/24/2023
//  Description:
//      Definition of Transform component, which will handle position,
//      rotation, and scale mostly
//*****************************************************************************

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "BaseComponent/Component.h"
#include <glm/glm.hpp>

class Transform : public Component<Transform> {
public:
    // Ctor
    Transform();

    // Member functions (Any special transformations that may be useful)


    // Variable fields
    glm::vec4 position; // 4*4 bytes 16
    glm::vec4 rotation; // 4*4 bytes 16
    glm::vec3 scale;    // 3*4 bytes 12

private:
    // Component is purely just data, so leave most fields public unless desired otherwise
};

#endif
