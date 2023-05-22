//*****************************************************************************
//  Filename: IDGen.h
//  Author:   Hunter Smith
//  Date:     05/22/2023
//  Description:
//      Defined a base for an id generation system
//*****************************************************************************

#ifndef IDGEN_H
#define IDGEN_H

#include <stdint.h> // uint64_t

typedef uint64_t ID; // Typedef unsigned long long as ID

ID GenID(); // Function for generating an id

#endif
