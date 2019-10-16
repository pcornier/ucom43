// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmcu_H_
#define _Vmcu_H_

#include "verilated.h"

class Vmcu__Syms;

//----------

VL_MODULE(Vmcu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(_INT,0,0);
    VL_IN8(prtAI,3,0);
    VL_IN8(prtBI,3,0);
    VL_IN8(prtCI,3,0);
    VL_IN8(prtDI,3,0);
    VL_OUT8(prtC,3,0);
    VL_OUT8(prtD,3,0);
    VL_OUT8(prtE,3,0);
    VL_OUT8(prtF,3,0);
    VL_OUT8(prtG,3,0);
    VL_OUT8(prtH,3,0);
    VL_OUT8(prtI,2,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(mcu__DOT__clk_cnt,1,0);
    VL_SIG8(mcu__DOT__pcf,2,0);
    VL_SIG8(mcu__DOT__pcc,7,0);
    VL_SIG8(mcu__DOT__dph,2,0);
    VL_SIG8(mcu__DOT__dpl,3,0);
    VL_SIG8(mcu__DOT__rdat,7,0);
    VL_SIG8(mcu__DOT__c,0,0);
    VL_SIG8(mcu__DOT__cs,0,0);
    VL_SIG8(mcu__DOT__acc,3,0);
    VL_SIG8(mcu__DOT__state,1,0);
    VL_SIG8(mcu__DOT__opc,7,0);
    VL_SIG8(mcu__DOT__sp,1,0);
    VL_SIG8(mcu__DOT__bcount,5,0);
    VL_SIG8(mcu__DOT__pcount,5,0);
    VL_SIG8(mcu__DOT__tm,0,0);
    VL_SIG8(mcu__DOT__irq,0,0);
    VL_SIG8(mcu__DOT__ien,0,0);
    VL_SIG8(mcu__DOT__dp,6,0);
    VL_SIG8(mcu__DOT__mdat,3,0);
    VL_SIG8(mcu__DOT__din,3,0);
    VL_SIG8(mcu__DOT__waddr,6,0);
    VL_SIG8(mcu__DOT__we,0,0);
    VL_SIG8(mcu__DOT__bset,1,0);
    VL_SIG8(mcu__DOT__daddr,6,0);
    VL_SIG8(mcu__DOT__alu_op,2,0);
    VL_SIG8(mcu__DOT__alu_a,3,0);
    VL_SIG8(mcu__DOT__alu_b,3,0);
    VL_SIG8(mcu__DOT__alu_r,3,0);
    VL_SIG8(mcu__DOT__alu_c,0,0);
    VL_SIG16(mcu__DOT__pc,10,0);
    VL_SIG8(mcu__DOT__i_ports[4],3,0);
    VL_SIG8(mcu__DOT__o_ports[9],3,0);
    VL_SIG16(mcu__DOT__stack[3],10,0);
    VL_SIG8(mcu__DOT__rom[2048],7,0);
    VL_SIG8(mcu__DOT__wr[7],3,0);
    VL_SIG8(mcu__DOT__ram[96],3,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(mcu__DOT____Vlvbound1,0,0);
    VL_SIG8(mcu__DOT____Vlvbound2,3,0);
    VL_SIG8(mcu__DOT____Vlvbound3,0,0);
    VL_SIG8(mcu__DOT____Vlvbound4,3,0);
    VL_SIG8(mcu__DOT____Vlvbound8,0,0);
    VL_SIG8(mcu__DOT____Vlvbound9,0,0);
    VL_SIG8(mcu__DOT____Vlvbound10,3,0);
    VL_SIG8(__Vtableidx1,7,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG16(mcu__DOT____Vlvbound5,10,0);
    VL_SIG16(mcu__DOT____Vlvbound6,10,0);
    VL_SIG16(mcu__DOT____Vlvbound7,10,0);
    static VL_ST_SIG8(__Vtable1_mcu__DOT__alu_op[256],2,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmcu__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmcu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmcu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmcu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmcu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmcu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmcu__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vmcu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmcu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmcu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmcu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vmcu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vmcu__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmcu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
