//*****************************************************************************
//  Filename: IDGen.cpp
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Implementation file for an id generation system
//*****************************************************************************

#include "IDGen.h"

static ID curID = 0; // Static variable for getting the needed id

ID GenID() {
    return curID++;
}
