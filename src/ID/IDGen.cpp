//*****************************************************************************
//  Filename: IDGen.cpp
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Implementation file for an id generation system
//*****************************************************************************

#include "IDGen.h"

static ID curEntityID = 0; // Static variable for getting the needed id
static ID curComponentID = 0;
ClassID curClassID = 0;

ID GenEntityID() {
    return curEntityID++;
}

ID GenComponentID() {
    return curComponentID++;
}
