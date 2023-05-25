//*****************************************************************************
//  Filename: IComponent.h
//  Author:   Hunter Smith
//  Date:     05/24/2023
//  Description:
//      Interface / Abstract class for defining a component
//*****************************************************************************

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "../../../ID/IDGen.h"

class IComponent {
public:
    // Constructor
    explicit IComponent() : componentID_(GenComponentID()) {}

    // Get Component ID
    inline ID GetID() const { return componentID_; }

private:
    // Stays private, as it should never change, only set on construction
    ID componentID_;

};

#endif
