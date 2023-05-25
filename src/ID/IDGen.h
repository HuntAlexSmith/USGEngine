//*****************************************************************************
//  Filename: IDGen.h
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Defined a base for an id generation system
//*****************************************************************************

#ifndef IDGEN_H
#define IDGEN_H

#include <cstdint> // uint64_t

typedef uint64_t ID; // Typedef unsigned long long as ID
typedef unsigned ClassID;

ID GenEntityID(); // Function for generating an id
ID GenComponentID(); // Function for generating a component id

template <class T>
ClassID GenClassID() {
    extern ClassID curClassID;
    static ClassID nextID = curClassID++;
    return nextID;
}

#endif
