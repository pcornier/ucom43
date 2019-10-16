// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _Vmcu__Syms_H_
#define _Vmcu__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmcu.h"

// SYMS CLASS
class Vmcu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmcu*                          TOPp;
    
    // CREATORS
    Vmcu__Syms(Vmcu* topp, const char* namep);
    ~Vmcu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
