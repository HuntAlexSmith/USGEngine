//*****************************************************************************
//  Filename: Component.h
//  Author:   Hunter Smith
//  Date:     05/17/2023
//  Description:
//      Typed abstraction of an IComponent, allowing for unique types
//*****************************************************************************

#ifndef COMPONENT_H
#define COMPONENT_H

#include "IComponent.h"

template <class T>
class Component : public IComponent {
public:
    // Ctor
    Component() : IComponent(), classId_(GenClassID<T>()) {}

    // Member functions
    inline ClassID GetClassID() { return classId_; }

private:
    // Class id for typing purposes
    ClassID classId_;

};

#endif //USGENGINE_STUB_H
