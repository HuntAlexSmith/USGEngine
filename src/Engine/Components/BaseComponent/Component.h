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
    Component() : IComponent() {}

    // Class ID will be public and static const, as it shouldn't change after assignment
    static const ClassID classID;
private:

};

template<class T>
const ClassID Component<T>::classID = GenClassID<T>();

#endif
