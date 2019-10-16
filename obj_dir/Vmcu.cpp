// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmcu.h for the primary calling header

#include "Vmcu.h"
#include "Vmcu__Syms.h"


//--------------------
// STATIC VARIABLES

// Begin mtask footprint  all: 
VL_ST_SIG8(Vmcu::__Vtable1_mcu__DOT__alu_op[256],2,0);

//--------------------

VL_CTOR_IMP(Vmcu) {
    Vmcu__Syms* __restrict vlSymsp = __VlSymsp = new Vmcu__Syms(this, name());
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmcu::__Vconfigure(Vmcu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmcu::~Vmcu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmcu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmcu::eval\n"); );
    Vmcu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vmcu::_eval_initial_loop(Vmcu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vmcu::_sequent__TOP__1(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_sequent__TOP__1\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__mcu__DOT__clk_cnt,1,0);
    VL_SIG8(__Vdly__mcu__DOT__pcount,5,0);
    VL_SIG8(__Vdly__mcu__DOT__bcount,5,0);
    VL_SIG8(__Vdly__mcu__DOT__tm,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__wr__v0,2,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__wr__v0,1,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__wr__v0,0,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__wr__v0,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__wr__v1,2,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__wr__v1,3,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__wr__v1,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__ram__v0,6,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__ram__v0,1,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__ram__v1,6,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__ram__v1,3,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__ram__v1,0,0);
    VL_SIG8(__Vdly__mcu__DOT__dph,2,0);
    VL_SIG8(__Vdly__mcu__DOT__c,0,0);
    VL_SIG8(__Vdly__mcu__DOT__acc,3,0);
    VL_SIG8(__Vdly__mcu__DOT__cs,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__stack__v0,1,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__stack__v0,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__stack__v1,1,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__stack__v1,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__stack__v2,1,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__stack__v2,0,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v0,3,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v0,0,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v1,3,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__o_ports__v2,1,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v2,0,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__o_ports__v3,1,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v3,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__o_ports__v4,3,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__o_ports__v4,1,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v4,0,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v4,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__o_ports__v5,3,0);
    VL_SIG8(__Vdlyvlsb__mcu__DOT__o_ports__v5,1,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v5,0,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v5,0,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v6,3,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v6,0,0);
    VL_SIG8(__Vdlyvdim0__mcu__DOT__o_ports__v7,3,0);
    VL_SIG8(__Vdlyvval__mcu__DOT__o_ports__v7,3,0);
    VL_SIG8(__Vdlyvset__mcu__DOT__o_ports__v7,0,0);
    VL_SIG8(__Vdly__mcu__DOT__state,1,0);
    VL_SIG8(__Vdly__mcu__DOT__sp,1,0);
    VL_SIG8(__Vdly__mcu__DOT__irq,0,0);
    VL_SIG8(__Vdly__mcu__DOT__pcc,7,0);
    VL_SIG16(__Vdlyvval__mcu__DOT__stack__v0,10,0);
    VL_SIG16(__Vdlyvval__mcu__DOT__stack__v1,10,0);
    VL_SIG16(__Vdlyvval__mcu__DOT__stack__v2,10,0);
    // Body
    __Vdly__mcu__DOT__clk_cnt = vlTOPp->mcu__DOT__clk_cnt;
    __Vdly__mcu__DOT__irq = vlTOPp->mcu__DOT__irq;
    __Vdly__mcu__DOT__tm = vlTOPp->mcu__DOT__tm;
    __Vdly__mcu__DOT__bcount = vlTOPp->mcu__DOT__bcount;
    __Vdly__mcu__DOT__pcount = vlTOPp->mcu__DOT__pcount;
    __Vdly__mcu__DOT__dph = vlTOPp->mcu__DOT__dph;
    __Vdly__mcu__DOT__sp = vlTOPp->mcu__DOT__sp;
    __Vdly__mcu__DOT__pcc = vlTOPp->mcu__DOT__pcc;
    __Vdly__mcu__DOT__state = vlTOPp->mcu__DOT__state;
    __Vdlyvset__mcu__DOT__stack__v0 = 0U;
    __Vdlyvset__mcu__DOT__stack__v1 = 0U;
    __Vdlyvset__mcu__DOT__stack__v2 = 0U;
    __Vdly__mcu__DOT__cs = vlTOPp->mcu__DOT__cs;
    __Vdly__mcu__DOT__c = vlTOPp->mcu__DOT__c;
    __Vdly__mcu__DOT__acc = vlTOPp->mcu__DOT__acc;
    __Vdlyvset__mcu__DOT__ram__v0 = 0U;
    __Vdlyvset__mcu__DOT__ram__v1 = 0U;
    __Vdlyvset__mcu__DOT__wr__v0 = 0U;
    __Vdlyvset__mcu__DOT__wr__v1 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v0 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v2 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v3 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v4 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v5 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v6 = 0U;
    __Vdlyvset__mcu__DOT__o_ports__v7 = 0U;
    // ALWAYS at mcu.v:57
    __Vdly__mcu__DOT__clk_cnt = (3U & ((IData)(1U) 
				       + (IData)(vlTOPp->mcu__DOT__clk_cnt)));
    // ALWAYS at mcu.v:506
    if (vlTOPp->_INT) {
	__Vdly__mcu__DOT__irq = 1U;
    }
    if ((((~ (IData)(vlTOPp->_INT)) & (IData)(vlTOPp->mcu__DOT__ien)) 
	 & (IData)(vlTOPp->mcu__DOT__irq))) {
	__Vdly__mcu__DOT__irq = 0U;
    }
    if (((0U == (IData)(vlTOPp->mcu__DOT__state)) & 
	 (3U == (IData)(vlTOPp->mcu__DOT__rdat)))) {
	__Vdly__mcu__DOT__irq = 0U;
    }
    // ALWAYS at mcu.v:93
    if ((((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt)) 
	  & (0x14U == (IData)(vlTOPp->mcu__DOT__opc))) 
	 & (1U == (IData)(vlTOPp->mcu__DOT__state)))) {
	__Vdly__mcu__DOT__pcount = 0U;
	__Vdly__mcu__DOT__bcount = (0x3fU & (IData)(vlTOPp->mcu__DOT__rdat));
	__Vdly__mcu__DOT__tm = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->mcu__DOT__tm)))) {
	    if ((0x3fU == (IData)(vlTOPp->mcu__DOT__pcount))) {
		if ((0U == (IData)(vlTOPp->mcu__DOT__bcount))) {
		    __Vdly__mcu__DOT__tm = 1U;
		}
		__Vdly__mcu__DOT__bcount = (0x3fU & 
					    ((IData)(vlTOPp->mcu__DOT__bcount) 
					     - (IData)(1U)));
	    }
	    __Vdly__mcu__DOT__pcount = (0x3fU & ((IData)(1U) 
						 + (IData)(vlTOPp->mcu__DOT__pcount)));
	}
    }
    // ALWAYS at mcu.v:308
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if ((0x15U == (IData)(vlTOPp->mcu__DOT__opc))) {
		__Vdly__mcu__DOT__dph = (7U & ((IData)(vlTOPp->mcu__DOT__rdat) 
					       >> 4U));
	    }
	} else {
	    if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		if ((0x28U == (0xe8U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
		    __Vdly__mcu__DOT__dph = ((4U & (IData)(__Vdly__mcu__DOT__dph)) 
					     | (3U 
						& ((IData)(vlTOPp->mcu__DOT__dph) 
						   ^ (IData)(vlTOPp->mcu__DOT__rdat))));
		} else {
		    if ((0x80U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			__Vdly__mcu__DOT__dph = 0U;
		    } else {
			if ((0x4fU == (IData)(vlTOPp->mcu__DOT__rdat))) {
			    __Vdly__mcu__DOT__dph = 
				(7U & vlTOPp->mcu__DOT__wr
				 [6U]);
			} else {
			    if ((0x4dU == (IData)(vlTOPp->mcu__DOT__rdat))) {
				__Vdly__mcu__DOT__dph 
				    = (7U & vlTOPp->mcu__DOT__wr
				       [4U]);
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at mcu.v:462
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if (((0x49U == (IData)(vlTOPp->mcu__DOT__opc)) 
		 | (0x48U == (IData)(vlTOPp->mcu__DOT__opc)))) {
		if ((0U == (IData)(vlTOPp->mcu__DOT__sp))) {
		    __Vdly__mcu__DOT__sp = 2U;
		} else {
		    if ((1U == (IData)(vlTOPp->mcu__DOT__sp))) {
			__Vdly__mcu__DOT__sp = 0U;
		    } else {
			if ((2U == (IData)(vlTOPp->mcu__DOT__sp))) {
			    __Vdly__mcu__DOT__sp = 1U;
			}
		    }
		}
	    }
	} else {
	    if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		if (((0xb0U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat))) 
		     | (0xa8U == (0xf8U & (IData)(vlTOPp->mcu__DOT__rdat))))) {
		    if ((0U == (IData)(vlTOPp->mcu__DOT__sp))) {
			__Vdly__mcu__DOT__sp = 1U;
		    } else {
			if ((1U == (IData)(vlTOPp->mcu__DOT__sp))) {
			    __Vdly__mcu__DOT__sp = 2U;
			} else {
			    if ((2U == (IData)(vlTOPp->mcu__DOT__sp))) {
				__Vdly__mcu__DOT__sp = 0U;
			    }
			}
		    }
		}
	    }
	}
	if ((((~ (IData)(vlTOPp->_INT)) & (IData)(vlTOPp->mcu__DOT__ien)) 
	     & (IData)(vlTOPp->mcu__DOT__irq))) {
	    __Vdly__mcu__DOT__sp = (3U & ((IData)(1U) 
					  + (IData)(vlTOPp->mcu__DOT__sp)));
	}
    }
    // ALWAYS at mcu.v:514
    if (((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt)) 
	 & (~ (IData)(vlTOPp->reset)))) {
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if (((0x49U == (IData)(vlTOPp->mcu__DOT__opc)) 
		 | (0x48U == (IData)(vlTOPp->mcu__DOT__opc)))) {
		vlTOPp->mcu__DOT__pcf = (7U & (((2U 
						 >= 
						 (3U 
						  & ((0U 
						      == (IData)(vlTOPp->mcu__DOT__sp))
						      ? 2U
						      : 
						     ((IData)(vlTOPp->mcu__DOT__sp) 
						      - (IData)(1U)))))
						 ? 
						vlTOPp->mcu__DOT__stack
						[(3U 
						  & ((0U 
						      == (IData)(vlTOPp->mcu__DOT__sp))
						      ? 2U
						      : 
						     ((IData)(vlTOPp->mcu__DOT__sp) 
						      - (IData)(1U))))]
						 : 0U) 
					       >> 8U));
	    } else {
		if (((0xa8U == (0xf8U & (IData)(vlTOPp->mcu__DOT__opc))) 
		     | (0xa0U == (0xf8U & (IData)(vlTOPp->mcu__DOT__opc))))) {
		    vlTOPp->mcu__DOT__pcf = (7U & (IData)(vlTOPp->mcu__DOT__opc));
		}
	    }
	} else {
	    if ((2U != (IData)(vlTOPp->mcu__DOT__state))) {
		if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		    if ((1U & (~ ((((0x42U == (0xf6U 
					       & (IData)(vlTOPp->mcu__DOT__rdat))) 
				    | (0x46U == (0xfeU 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				   | (0x4cU == (0xfcU 
						& (IData)(vlTOPp->mcu__DOT__rdat)))) 
				  | (0x48U == (0xfeU 
					       & (IData)(vlTOPp->mcu__DOT__rdat))))))) {
			if ((0xc0U != (0xc0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			    if ((0xb0U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
				vlTOPp->mcu__DOT__pcf = 0U;
			    }
			}
		    }
		}
	    }
	}
	if ((((~ (IData)(vlTOPp->_INT)) & (IData)(vlTOPp->mcu__DOT__ien)) 
	     & (IData)(vlTOPp->mcu__DOT__irq))) {
	    vlTOPp->mcu__DOT__pcf = 0U;
	}
    } else {
	if (vlTOPp->reset) {
	    vlTOPp->mcu__DOT__pcf = 0U;
	}
    }
    // ALWAYS at mcu.v:514
    if (((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt)) 
	 & (~ (IData)(vlTOPp->reset)))) {
	__Vdly__mcu__DOT__pcc = (0xffU & ((IData)(1U) 
					  + (IData)(vlTOPp->mcu__DOT__pcc)));
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if (((0x49U == (IData)(vlTOPp->mcu__DOT__opc)) 
		 | (0x48U == (IData)(vlTOPp->mcu__DOT__opc)))) {
		__Vdly__mcu__DOT__pcc = (0xffU & ((2U 
						   >= 
						   (3U 
						    & ((0U 
							== (IData)(vlTOPp->mcu__DOT__sp))
						        ? 2U
						        : 
						       ((IData)(vlTOPp->mcu__DOT__sp) 
							- (IData)(1U)))))
						   ? 
						  vlTOPp->mcu__DOT__stack
						  [
						  (3U 
						   & ((0U 
						       == (IData)(vlTOPp->mcu__DOT__sp))
						       ? 2U
						       : 
						      ((IData)(vlTOPp->mcu__DOT__sp) 
						       - (IData)(1U))))]
						   : 0U));
	    } else {
		if (((0xa8U == (0xf8U & (IData)(vlTOPp->mcu__DOT__opc))) 
		     | (0xa0U == (0xf8U & (IData)(vlTOPp->mcu__DOT__opc))))) {
		    __Vdly__mcu__DOT__pcc = vlTOPp->mcu__DOT__rdat;
		} else {
		    if ((0x41U == (IData)(vlTOPp->mcu__DOT__opc))) {
			__Vdly__mcu__DOT__pcc = ((0xc0U 
						  & (IData)(__Vdly__mcu__DOT__pcc)) 
						 | ((IData)(vlTOPp->mcu__DOT__acc) 
						    << 2U));
		    }
		}
	    }
	} else {
	    if ((2U == (IData)(vlTOPp->mcu__DOT__state))) {
		__Vdly__mcu__DOT__pcc = (0xffU & ((0x80U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((0x40U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((IData)(1U) 
						    + (IData)(vlTOPp->mcu__DOT__pcc))
						    : 
						   ((0x20U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((0x10U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((IData)(1U) 
						      + (IData)(vlTOPp->mcu__DOT__pcc))
						      : 
						     ((IData)(2U) 
						      + (IData)(vlTOPp->mcu__DOT__pcc)))
						     : 
						    ((IData)(1U) 
						     + (IData)(vlTOPp->mcu__DOT__pcc))))
						   : 
						  ((0x40U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((IData)(1U) 
						    + (IData)(vlTOPp->mcu__DOT__pcc))
						    : 
						   ((0x20U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((IData)(1U) 
						     + (IData)(vlTOPp->mcu__DOT__pcc))
						     : 
						    ((0x10U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((8U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((4U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 
						       ((2U 
							 & (IData)(vlTOPp->mcu__DOT__rdat))
							 ? 
							((1U 
							  & (IData)(vlTOPp->mcu__DOT__rdat))
							  ? 
							 ((IData)(1U) 
							  + (IData)(vlTOPp->mcu__DOT__pcc))
							  : 
							 ((IData)(2U) 
							  + (IData)(vlTOPp->mcu__DOT__pcc)))
							 : 
							((IData)(1U) 
							 + (IData)(vlTOPp->mcu__DOT__pcc)))
						        : 
						       ((IData)(1U) 
							+ (IData)(vlTOPp->mcu__DOT__pcc)))
						       : 
						      ((4U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 
						       ((IData)(2U) 
							+ (IData)(vlTOPp->mcu__DOT__pcc))
						        : 
						       ((IData)(1U) 
							+ (IData)(vlTOPp->mcu__DOT__pcc))))
						      : 
						     ((IData)(1U) 
						      + (IData)(vlTOPp->mcu__DOT__pcc)))))));
	    } else {
		if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		    if (((((0x42U == (0xf6U & (IData)(vlTOPp->mcu__DOT__rdat))) 
			   | (0x46U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			  | (0x4cU == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			 | (0x48U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat))))) {
			__Vdly__mcu__DOT__pcc = vlTOPp->mcu__DOT__pcc;
		    } else {
			if ((0xc0U == (0xc0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			    __Vdly__mcu__DOT__pcc = 
				((0xc0U & (IData)(__Vdly__mcu__DOT__pcc)) 
				 | (0x3fU & (IData)(vlTOPp->mcu__DOT__rdat)));
			} else {
			    if ((0xb0U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
				__Vdly__mcu__DOT__pcc 
				    = (0x3cU & ((IData)(vlTOPp->mcu__DOT__rdat) 
						<< 2U));
			    }
			}
		    }
		}
	    }
	}
	if ((((~ (IData)(vlTOPp->_INT)) & (IData)(vlTOPp->mcu__DOT__ien)) 
	     & (IData)(vlTOPp->mcu__DOT__irq))) {
	    __Vdly__mcu__DOT__pcc = 0x3cU;
	}
    } else {
	if (vlTOPp->reset) {
	    __Vdly__mcu__DOT__pcc = 0U;
	}
    }
    // ALWAYS at mcu.v:411
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	__Vdly__mcu__DOT__state = 0U;
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if ((0x17U == (IData)(vlTOPp->mcu__DOT__opc))) {
		if (((IData)(vlTOPp->mcu__DOT__acc) 
		     == (0xfU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
		    __Vdly__mcu__DOT__state = 2U;
		}
	    } else {
		if ((0x16U == (IData)(vlTOPp->mcu__DOT__opc))) {
		    if (((IData)(vlTOPp->mcu__DOT__dpl) 
			 == (0xfU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			__Vdly__mcu__DOT__state = 2U;
		    }
		} else {
		    if ((0x49U == (IData)(vlTOPp->mcu__DOT__opc))) {
			__Vdly__mcu__DOT__state = 2U;
		    }
		}
	    }
	} else {
	    if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		if ((((((((((((((((((0xdU == (0xfdU 
					      & (IData)(vlTOPp->mcu__DOT__rdat))) 
				    | (0x1dU == (0xfdU 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				   | (8U == (0xfeU 
					     & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				  | (0x13U == (0xdfU 
					       & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				 | (0x2cU == (0xecU 
					      & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				| (0x58U == (0xfcU 
					     & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			       | (0x54U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			      | (0x24U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			     | (0x50U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			    | (0x5cU == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			   | (0x20U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			  | (((((0x4cU == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat))) 
				| (0x42U == (0xfeU 
					     & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			       | (0x4aU == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			      | (0x46U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			     | (0x4eU == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat))))) 
			 | (0x34U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			| (0xcU == (IData)(vlTOPp->mcu__DOT__rdat))) 
		       | (4U == (IData)(vlTOPp->mcu__DOT__rdat))) 
		      | (5U == (IData)(vlTOPp->mcu__DOT__rdat))) 
		     | (3U == (IData)(vlTOPp->mcu__DOT__rdat)))) {
		    if (((((((((((0xdU == (0xfdU & (IData)(vlTOPp->mcu__DOT__rdat))) 
				 | (0x1dU == (0xfdU 
					      & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				| (8U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			       | (0x13U == (0xdfU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			      | (0x2cU == (0xecU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			     | (0x58U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			    | (0x54U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			   | (0x24U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			  | (0x50U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			 | (0x5cU == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat))))) {
			if (vlTOPp->mcu__DOT__alu_c) {
			    __Vdly__mcu__DOT__state = 2U;
			}
		    } else {
			if ((0x20U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			    if ((1U & (~ (IData)(vlTOPp->mcu__DOT__alu_c)))) {
				__Vdly__mcu__DOT__state = 2U;
			    }
			} else {
			    if ((((((0x4cU == (0xfeU 
					       & (IData)(vlTOPp->mcu__DOT__rdat))) 
				    | (0x42U == (0xfeU 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				   | (0x4aU == (0xfeU 
						& (IData)(vlTOPp->mcu__DOT__rdat)))) 
				  | (0x46U == (0xfeU 
					       & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				 | (0x4eU == (0xfeU 
					      & (IData)(vlTOPp->mcu__DOT__rdat))))) {
				__Vdly__mcu__DOT__state = 3U;
			    } else {
				if ((0x34U == (0xfcU 
					       & (IData)(vlTOPp->mcu__DOT__rdat)))) {
				    if (((1U & ((IData)(vlTOPp->mcu__DOT__mdat) 
						>> 
						(3U 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))) 
					 == (1U & ((IData)(vlTOPp->mcu__DOT__acc) 
						   >> 
						   (3U 
						    & (IData)(vlTOPp->mcu__DOT__rdat)))))) {
					__Vdly__mcu__DOT__state = 2U;
				    }
				} else {
				    if ((0xcU == (IData)(vlTOPp->mcu__DOT__rdat))) {
					if (((IData)(vlTOPp->mcu__DOT__acc) 
					     == (IData)(vlTOPp->mcu__DOT__mdat))) {
					    __Vdly__mcu__DOT__state = 2U;
					}
				    } else {
					if ((4U == (IData)(vlTOPp->mcu__DOT__rdat))) {
					    if (vlTOPp->mcu__DOT__c) {
						__Vdly__mcu__DOT__state = 2U;
					    }
					} else {
					    if ((5U 
						 == (IData)(vlTOPp->mcu__DOT__rdat))) {
						if (vlTOPp->mcu__DOT__tm) {
						    __Vdly__mcu__DOT__state = 2U;
						}
					    } else {
						if (vlTOPp->mcu__DOT__irq) {
						    __Vdly__mcu__DOT__state = 2U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		} else {
		    if (((((((((0xa8U == (0xf8U & (IData)(vlTOPp->mcu__DOT__rdat))) 
			       | (0x48U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			      | (0x41U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			     | (0xa0U == (0xf8U & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			    | (0x16U == (0xfeU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			   | (0x1eU == (IData)(vlTOPp->mcu__DOT__rdat))) 
			  | (0x14U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			 | (0x15U == (IData)(vlTOPp->mcu__DOT__rdat)))) {
			__Vdly__mcu__DOT__state = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at mcu.v:380
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if ((0xb0U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
		vlTOPp->mcu__DOT____Vlvbound5 = (0x7ffU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->mcu__DOT__pc)));
		if (VL_LIKELY((2U >= (IData)(vlTOPp->mcu__DOT__sp)))) {
		    __Vdlyvval__mcu__DOT__stack__v0 
			= vlTOPp->mcu__DOT____Vlvbound5;
		    __Vdlyvset__mcu__DOT__stack__v0 = 1U;
		    __Vdlyvdim0__mcu__DOT__stack__v0 
			= vlTOPp->mcu__DOT__sp;
		}
	    } else {
		if ((0xa8U == (0xf8U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
		    vlTOPp->mcu__DOT____Vlvbound6 = 
			(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->mcu__DOT__pc)));
		    if (VL_LIKELY((2U >= (IData)(vlTOPp->mcu__DOT__sp)))) {
			__Vdlyvval__mcu__DOT__stack__v1 
			    = vlTOPp->mcu__DOT____Vlvbound6;
			__Vdlyvset__mcu__DOT__stack__v1 = 1U;
			__Vdlyvdim0__mcu__DOT__stack__v1 
			    = vlTOPp->mcu__DOT__sp;
		    }
		}
	    }
	}
	if ((((~ (IData)(vlTOPp->_INT)) & (IData)(vlTOPp->mcu__DOT__ien)) 
	     & (IData)(vlTOPp->mcu__DOT__irq))) {
	    vlTOPp->mcu__DOT____Vlvbound7 = (0x7ffU 
					     & ((IData)(1U) 
						+ (IData)(vlTOPp->mcu__DOT__pc)));
	    if (VL_LIKELY((2U >= (IData)(vlTOPp->mcu__DOT__sp)))) {
		__Vdlyvval__mcu__DOT__stack__v2 = vlTOPp->mcu__DOT____Vlvbound7;
		__Vdlyvset__mcu__DOT__stack__v2 = 1U;
		__Vdlyvdim0__mcu__DOT__stack__v2 = vlTOPp->mcu__DOT__sp;
	    }
	}
    }
    // ALWAYS at mcu.v:343
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if (((((((((0xbU == (IData)(vlTOPp->mcu__DOT__rdat)) 
		       | (0x1bU == (IData)(vlTOPp->mcu__DOT__rdat))) 
		      | (((((((0x10U == (IData)(vlTOPp->mcu__DOT__rdat)) 
			      | (0x11U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			     | (0xdU == (0xfdU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
			    | (6U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			   | (0xaU == (IData)(vlTOPp->mcu__DOT__rdat))) 
			  | (8U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			 | (0x18U == (IData)(vlTOPp->mcu__DOT__rdat)))) 
		     | (0x1aU == (IData)(vlTOPp->mcu__DOT__rdat))) 
		    | (0x30U == (IData)(vlTOPp->mcu__DOT__rdat))) 
		   | (9U == (0xefU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
		  | (0x90U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) 
		 | ((((0x38U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat))) 
		      | (0x28U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
		     | (0x2cU == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) 
		    | (0x3cU == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))))) {
		if ((0xbU == (IData)(vlTOPp->mcu__DOT__rdat))) {
		    __Vdly__mcu__DOT__c = 0U;
		} else {
		    if ((0x1bU == (IData)(vlTOPp->mcu__DOT__rdat))) {
			__Vdly__mcu__DOT__c = 1U;
		    } else {
			if ((((((((0x10U == (IData)(vlTOPp->mcu__DOT__rdat)) 
				  | (0x11U == (IData)(vlTOPp->mcu__DOT__rdat))) 
				 | (0xdU == (0xfdU 
					     & (IData)(vlTOPp->mcu__DOT__rdat)))) 
				| (6U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			       | (0xaU == (IData)(vlTOPp->mcu__DOT__rdat))) 
			      | (8U == (IData)(vlTOPp->mcu__DOT__rdat))) 
			     | (0x18U == (IData)(vlTOPp->mcu__DOT__rdat)))) {
			    __Vdly__mcu__DOT__acc = vlTOPp->mcu__DOT__alu_r;
			} else {
			    if ((0x1aU == (IData)(vlTOPp->mcu__DOT__rdat))) {
				__Vdly__mcu__DOT__cs 
				    = vlTOPp->mcu__DOT__c;
				__Vdly__mcu__DOT__c 
				    = vlTOPp->mcu__DOT__cs;
			    } else {
				if ((0x30U == (IData)(vlTOPp->mcu__DOT__rdat))) {
				    __Vdly__mcu__DOT__acc 
					= (((IData)(vlTOPp->mcu__DOT__c) 
					    << 3U) 
					   | (7U & 
					      ((IData)(vlTOPp->mcu__DOT__acc) 
					       >> 1U)));
				    __Vdly__mcu__DOT__c 
					= (1U & (IData)(vlTOPp->mcu__DOT__acc));
				} else {
				    if ((9U == (0xefU 
						& (IData)(vlTOPp->mcu__DOT__rdat)))) {
					__Vdly__mcu__DOT__c 
					    = vlTOPp->mcu__DOT__alu_c;
					__Vdly__mcu__DOT__acc 
					    = vlTOPp->mcu__DOT__alu_r;
				    } else {
					if ((0x90U 
					     == (0xf0U 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))) {
					    if (((0xfU 
						  & ((IData)(vlTOPp->mcu__DOT__opc) 
						     >> 4U)) 
						 != 
						 (0xfU 
						  & ((IData)(vlTOPp->mcu__DOT__rdat) 
						     >> 4U)))) {
						__Vdly__mcu__DOT__acc 
						    = 
						    (0xfU 
						     & (IData)(vlTOPp->mcu__DOT__rdat));
					    }
					} else {
					    __Vdly__mcu__DOT__acc 
						= vlTOPp->mcu__DOT__mdat;
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x12U == (IData)(vlTOPp->mcu__DOT__rdat))) {
		    __Vdly__mcu__DOT__acc = vlTOPp->mcu__DOT__dpl;
		} else {
		    if ((0x4aU == (IData)(vlTOPp->mcu__DOT__rdat))) {
			__Vdly__mcu__DOT__acc = vlTOPp->mcu__DOT__wr
			    [1U];
		    } else {
			if ((0x4bU == (IData)(vlTOPp->mcu__DOT__rdat))) {
			    __Vdly__mcu__DOT__acc = 
				vlTOPp->mcu__DOT__wr
				[2U];
			} else {
			    if ((0x40U == (IData)(vlTOPp->mcu__DOT__rdat))) {
				__Vdly__mcu__DOT__acc 
				    = vlTOPp->prtAI;
			    } else {
				if ((0x32U == (IData)(vlTOPp->mcu__DOT__rdat))) {
				    __Vdly__mcu__DOT__acc 
					= ((0U == (3U 
						   & ((IData)(vlTOPp->mcu__DOT__dpl) 
						      >> 2U)))
					    ? vlTOPp->mcu__DOT__i_ports
					   [(3U & (IData)(vlTOPp->mcu__DOT__dpl))]
					    : ((8U 
						>= (IData)(vlTOPp->mcu__DOT__dpl))
					        ? vlTOPp->mcu__DOT__o_ports
					       [vlTOPp->mcu__DOT__dpl]
					        : 0U));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at mcu.v:148
    if ((1U & (~ (IData)(vlTOPp->mcu__DOT__we)))) {
	if ((0x79U > (IData)(vlTOPp->mcu__DOT__waddr))) {
	    if ((2U & (IData)(vlTOPp->mcu__DOT__bset))) {
		vlTOPp->mcu__DOT____Vlvbound3 = (1U 
						 & (IData)(vlTOPp->mcu__DOT__bset));
		if ((0x5fU >= (IData)(vlTOPp->mcu__DOT__daddr))) {
		    __Vdlyvval__mcu__DOT__ram__v0 = vlTOPp->mcu__DOT____Vlvbound3;
		    __Vdlyvset__mcu__DOT__ram__v0 = 1U;
		    __Vdlyvlsb__mcu__DOT__ram__v0 = 
			(3U & (IData)(vlTOPp->mcu__DOT__din));
		    __Vdlyvdim0__mcu__DOT__ram__v0 
			= vlTOPp->mcu__DOT__daddr;
		}
	    } else {
		vlTOPp->mcu__DOT____Vlvbound4 = vlTOPp->mcu__DOT__din;
		if ((0x5fU >= (IData)(vlTOPp->mcu__DOT__daddr))) {
		    __Vdlyvval__mcu__DOT__ram__v1 = vlTOPp->mcu__DOT____Vlvbound4;
		    __Vdlyvset__mcu__DOT__ram__v1 = 1U;
		    __Vdlyvdim0__mcu__DOT__ram__v1 
			= vlTOPp->mcu__DOT__daddr;
		}
	    }
	}
    }
    // ALWAYS at mcu.v:148
    if ((1U & (~ (IData)(vlTOPp->mcu__DOT__we)))) {
	if ((0x79U <= (IData)(vlTOPp->mcu__DOT__waddr))) {
	    if ((2U & (IData)(vlTOPp->mcu__DOT__bset))) {
		vlTOPp->mcu__DOT____Vlvbound1 = (1U 
						 & (IData)(vlTOPp->mcu__DOT__bset));
		if ((6U >= (7U & ((IData)(vlTOPp->mcu__DOT__daddr) 
				  - (IData)(1U))))) {
		    __Vdlyvval__mcu__DOT__wr__v0 = vlTOPp->mcu__DOT____Vlvbound1;
		    __Vdlyvset__mcu__DOT__wr__v0 = 1U;
		    __Vdlyvlsb__mcu__DOT__wr__v0 = 
			(3U & (IData)(vlTOPp->mcu__DOT__din));
		    __Vdlyvdim0__mcu__DOT__wr__v0 = 
			(7U & ((IData)(vlTOPp->mcu__DOT__daddr) 
			       - (IData)(1U)));
		}
	    } else {
		vlTOPp->mcu__DOT____Vlvbound2 = vlTOPp->mcu__DOT__din;
		if ((6U >= (7U & ((IData)(vlTOPp->mcu__DOT__daddr) 
				  - (IData)(1U))))) {
		    __Vdlyvval__mcu__DOT__wr__v1 = vlTOPp->mcu__DOT____Vlvbound2;
		    __Vdlyvset__mcu__DOT__wr__v1 = 1U;
		    __Vdlyvdim0__mcu__DOT__wr__v1 = 
			(7U & ((IData)(vlTOPp->mcu__DOT__daddr) 
			       - (IData)(1U)));
		}
	    }
	}
    }
    // ALWAYS at mcu.v:395
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if (((1U == (IData)(vlTOPp->mcu__DOT__state)) 
	     & (0x1eU == (IData)(vlTOPp->mcu__DOT__opc)))) {
	    __Vdlyvval__mcu__DOT__o_ports__v0 = (0xfU 
						 & ((IData)(vlTOPp->mcu__DOT__rdat) 
						    >> 4U));
	    __Vdlyvset__mcu__DOT__o_ports__v0 = 1U;
	    __Vdlyvval__mcu__DOT__o_ports__v1 = (0xfU 
						 & (IData)(vlTOPp->mcu__DOT__rdat));
	} else {
	    if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		if ((0x74U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
		    __Vdlyvset__mcu__DOT__o_ports__v2 = 1U;
		    __Vdlyvlsb__mcu__DOT__o_ports__v2 
			= (3U & (IData)(vlTOPp->mcu__DOT__rdat));
		} else {
		    if ((0x64U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			__Vdlyvset__mcu__DOT__o_ports__v3 = 1U;
			__Vdlyvlsb__mcu__DOT__o_ports__v3 
			    = (3U & (IData)(vlTOPp->mcu__DOT__rdat));
		    } else {
			if ((0x70U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			    vlTOPp->mcu__DOT____Vlvbound8 = 1U;
			    if (VL_LIKELY((8U >= (IData)(vlTOPp->mcu__DOT__dpl)))) {
				__Vdlyvval__mcu__DOT__o_ports__v4 
				    = vlTOPp->mcu__DOT____Vlvbound8;
				__Vdlyvset__mcu__DOT__o_ports__v4 = 1U;
				__Vdlyvlsb__mcu__DOT__o_ports__v4 
				    = (3U & (IData)(vlTOPp->mcu__DOT__rdat));
				__Vdlyvdim0__mcu__DOT__o_ports__v4 
				    = vlTOPp->mcu__DOT__dpl;
			    }
			} else {
			    if ((0x60U == (0xfcU & (IData)(vlTOPp->mcu__DOT__rdat)))) {
				vlTOPp->mcu__DOT____Vlvbound9 = 0U;
				if (VL_LIKELY((8U >= (IData)(vlTOPp->mcu__DOT__dpl)))) {
				    __Vdlyvval__mcu__DOT__o_ports__v5 
					= vlTOPp->mcu__DOT____Vlvbound9;
				    __Vdlyvset__mcu__DOT__o_ports__v5 = 1U;
				    __Vdlyvlsb__mcu__DOT__o_ports__v5 
					= (3U & (IData)(vlTOPp->mcu__DOT__rdat));
				    __Vdlyvdim0__mcu__DOT__o_ports__v5 
					= vlTOPp->mcu__DOT__dpl;
				}
			    } else {
				if ((0x44U == (IData)(vlTOPp->mcu__DOT__rdat))) {
				    __Vdlyvval__mcu__DOT__o_ports__v6 
					= vlTOPp->mcu__DOT__acc;
				    __Vdlyvset__mcu__DOT__o_ports__v6 = 1U;
				} else {
				    if ((0xeU == (IData)(vlTOPp->mcu__DOT__rdat))) {
					vlTOPp->mcu__DOT____Vlvbound10 
					    = vlTOPp->mcu__DOT__acc;
					if (VL_LIKELY(
						      (8U 
						       >= (IData)(vlTOPp->mcu__DOT__dpl)))) {
					    __Vdlyvval__mcu__DOT__o_ports__v7 
						= vlTOPp->mcu__DOT____Vlvbound10;
					    __Vdlyvset__mcu__DOT__o_ports__v7 = 1U;
					    __Vdlyvdim0__mcu__DOT__o_ports__v7 
						= vlTOPp->mcu__DOT__dpl;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->mcu__DOT__pcount = __Vdly__mcu__DOT__pcount;
    vlTOPp->mcu__DOT__bcount = __Vdly__mcu__DOT__bcount;
    vlTOPp->mcu__DOT__pcc = __Vdly__mcu__DOT__pcc;
    vlTOPp->mcu__DOT__tm = __Vdly__mcu__DOT__tm;
    vlTOPp->mcu__DOT__sp = __Vdly__mcu__DOT__sp;
    vlTOPp->mcu__DOT__irq = __Vdly__mcu__DOT__irq;
    // ALWAYSPOST at mcu.v:385
    if (__Vdlyvset__mcu__DOT__stack__v0) {
	vlTOPp->mcu__DOT__stack[__Vdlyvdim0__mcu__DOT__stack__v0] 
	    = __Vdlyvval__mcu__DOT__stack__v0;
    }
    if (__Vdlyvset__mcu__DOT__stack__v1) {
	vlTOPp->mcu__DOT__stack[__Vdlyvdim0__mcu__DOT__stack__v1] 
	    = __Vdlyvval__mcu__DOT__stack__v1;
    }
    if (__Vdlyvset__mcu__DOT__stack__v2) {
	vlTOPp->mcu__DOT__stack[__Vdlyvdim0__mcu__DOT__stack__v2] 
	    = __Vdlyvval__mcu__DOT__stack__v2;
    }
    vlTOPp->mcu__DOT__cs = __Vdly__mcu__DOT__cs;
    vlTOPp->mcu__DOT__c = __Vdly__mcu__DOT__c;
    // ALWAYSPOST at mcu.v:399
    if (__Vdlyvset__mcu__DOT__o_ports__v0) {
	vlTOPp->mcu__DOT__o_ports[2U] = __Vdlyvval__mcu__DOT__o_ports__v0;
	vlTOPp->mcu__DOT__o_ports[3U] = __Vdlyvval__mcu__DOT__o_ports__v1;
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v2) {
	vlTOPp->mcu__DOT__o_ports[4U] = (vlTOPp->mcu__DOT__o_ports
					 [4U] | ((IData)(1U) 
						 << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v2)));
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v3) {
	vlTOPp->mcu__DOT__o_ports[4U] = ((~ ((IData)(1U) 
					     << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v3))) 
					 & vlTOPp->mcu__DOT__o_ports
					 [4U]);
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v4) {
	vlTOPp->mcu__DOT__o_ports[__Vdlyvdim0__mcu__DOT__o_ports__v4] 
	    = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v4))) 
		& vlTOPp->mcu__DOT__o_ports[__Vdlyvdim0__mcu__DOT__o_ports__v4]) 
	       | ((IData)(__Vdlyvval__mcu__DOT__o_ports__v4) 
		  << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v4)));
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v5) {
	vlTOPp->mcu__DOT__o_ports[__Vdlyvdim0__mcu__DOT__o_ports__v5] 
	    = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v5))) 
		& vlTOPp->mcu__DOT__o_ports[__Vdlyvdim0__mcu__DOT__o_ports__v5]) 
	       | ((IData)(__Vdlyvval__mcu__DOT__o_ports__v5) 
		  << (IData)(__Vdlyvlsb__mcu__DOT__o_ports__v5)));
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v6) {
	vlTOPp->mcu__DOT__o_ports[4U] = __Vdlyvval__mcu__DOT__o_ports__v6;
    }
    if (__Vdlyvset__mcu__DOT__o_ports__v7) {
	vlTOPp->mcu__DOT__o_ports[__Vdlyvdim0__mcu__DOT__o_ports__v7] 
	    = __Vdlyvval__mcu__DOT__o_ports__v7;
    }
    // ALWAYS at mcu.v:497
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if ((0x31U == (IData)(vlTOPp->mcu__DOT__rdat))) {
		vlTOPp->mcu__DOT__ien = 1U;
	    } else {
		if ((1U == (IData)(vlTOPp->mcu__DOT__rdat))) {
		    vlTOPp->mcu__DOT__ien = 0U;
		}
	    }
	}
    }
    // ALWAYS at mcu.v:144
    vlTOPp->mcu__DOT__mdat = ((0x79U > (IData)(vlTOPp->mcu__DOT__dp))
			       ? ((0x5fU >= ((0x40U 
					      & (IData)(vlTOPp->mcu__DOT__dp))
					      ? (0x5fU 
						 & (IData)(vlTOPp->mcu__DOT__dp))
					      : (IData)(vlTOPp->mcu__DOT__dp)))
				   ? vlTOPp->mcu__DOT__ram
				  [((0x40U & (IData)(vlTOPp->mcu__DOT__dp))
				     ? (0x5fU & (IData)(vlTOPp->mcu__DOT__dp))
				     : (IData)(vlTOPp->mcu__DOT__dp))]
				   : 0U) : ((6U >= 
					     (7U & 
					      ((IData)(vlTOPp->mcu__DOT__dp) 
					       - (IData)(1U))))
					     ? vlTOPp->mcu__DOT__wr
					    [(7U & 
					      ((IData)(vlTOPp->mcu__DOT__dp) 
					       - (IData)(1U)))]
					     : 0U));
    // ALWAYS at mcu.v:258
    vlTOPp->mcu__DOT__we = 1U;
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    vlTOPp->mcu__DOT__we = (1U & (((IData)(vlTOPp->mcu__DOT__rdat) 
					   >> 7U) | 
					  ((0x40U & (IData)(vlTOPp->mcu__DOT__rdat))
					    ? ((0x20U 
						& (IData)(vlTOPp->mcu__DOT__rdat))
					        ? (~ 
						   ((IData)(vlTOPp->mcu__DOT__rdat) 
						    >> 3U))
					        : (
						   ((IData)(vlTOPp->mcu__DOT__rdat) 
						    >> 4U) 
						   | ((8U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((~ 
							((IData)(vlTOPp->mcu__DOT__rdat) 
							 >> 2U)) 
						       & (~ 
							  ((IData)(vlTOPp->mcu__DOT__rdat) 
							   >> 1U)))
						       : 
						      (~ 
						       ((IData)(vlTOPp->mcu__DOT__rdat) 
							>> 1U)))))
					    : ((0x20U 
						& (IData)(vlTOPp->mcu__DOT__rdat))
					        ? (
						   (0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((~ 
						     ((IData)(vlTOPp->mcu__DOT__rdat) 
						      >> 3U)) 
						    | (~ 
						       ((IData)(vlTOPp->mcu__DOT__rdat) 
							>> 2U)))
						    : 
						   (~ 
						    ((IData)(vlTOPp->mcu__DOT__rdat) 
						     >> 3U)))
					        : (
						   (0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((~ 
						     ((IData)(vlTOPp->mcu__DOT__rdat) 
						      >> 3U)) 
						    | ((~ 
							((IData)(vlTOPp->mcu__DOT__rdat) 
							 >> 2U)) 
						       | (~ (IData)(vlTOPp->mcu__DOT__rdat))))
						    : 
						   (((IData)(vlTOPp->mcu__DOT__rdat) 
						     >> 3U) 
						    | (((IData)(vlTOPp->mcu__DOT__rdat) 
							>> 2U) 
						       | ((~ 
							   ((IData)(vlTOPp->mcu__DOT__rdat) 
							    >> 1U)) 
							  | (IData)(vlTOPp->mcu__DOT__rdat)))))))));
	}
    }
    // ALWAYS at mcu.v:298
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    vlTOPp->mcu__DOT__bset = ((0x78U == (0xf8U 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))
				       ? 3U : ((0x68U 
						== 
						(0xf8U 
						 & (IData)(vlTOPp->mcu__DOT__rdat)))
					        ? 2U
					        : 0U));
	}
    }
    // ALWAYS at mcu.v:242
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    vlTOPp->mcu__DOT__waddr = ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				        ? (IData)(vlTOPp->mcu__DOT__dp)
				        : ((0x40U & (IData)(vlTOPp->mcu__DOT__rdat))
					    ? ((0x20U 
						& (IData)(vlTOPp->mcu__DOT__rdat))
					        ? (
						   (8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0x79U
						     : (IData)(vlTOPp->mcu__DOT__dp))
						    : (IData)(vlTOPp->mcu__DOT__dp))
					        : (
						   (0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? (IData)(vlTOPp->mcu__DOT__dp)
						    : 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0x7fU
						        : 0x7eU)
						       : 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0x7dU
						        : 0x7cU))
						      : 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0x7bU
						        : 0x7aU)
						       : (IData)(vlTOPp->mcu__DOT__dp)))
						     : 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0x7fU
						        : 0x7eU)
						       : (IData)(vlTOPp->mcu__DOT__dp))
						      : 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0x7bU
						        : 0x7aU)
						       : (IData)(vlTOPp->mcu__DOT__dp))))))
					    : (IData)(vlTOPp->mcu__DOT__dp)));
	}
    }
    // ALWAYS at mcu.v:278
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    vlTOPp->mcu__DOT__din = ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				      ? 0U : ((0x40U 
					       & (IData)(vlTOPp->mcu__DOT__rdat))
					       ? ((0x20U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   (3U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    : 0U)
						   : 
						  ((0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 0U
						    : 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__dph)
						       : (IData)(vlTOPp->mcu__DOT__dpl))
						      : 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__acc)
						       : 0U))
						     : 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? (IData)(vlTOPp->mcu__DOT__dph)
						        : (IData)(vlTOPp->mcu__DOT__dpl))
						       : 0U)
						      : 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__acc)
						       : 0U)))))
					       : ((0x20U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? (IData)(vlTOPp->mcu__DOT__acc)
						      : 0U)
						     : 0U)
						    : 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__acc)
						     : 0U))
						   : 
						  ((0x10U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__alu_r)
						       : 0U)
						      : 0U)
						     : 0U)
						    : 
						   ((8U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((4U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : 
						     ((2U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      ((1U 
							& (IData)(vlTOPp->mcu__DOT__rdat))
						        ? 0U
						        : (IData)(vlTOPp->mcu__DOT__acc))
						       : 0U)))))));
	}
    }
    vlTOPp->prtC = vlTOPp->mcu__DOT__o_ports[2U];
    vlTOPp->prtD = vlTOPp->mcu__DOT__o_ports[3U];
    vlTOPp->prtE = vlTOPp->mcu__DOT__o_ports[4U];
    vlTOPp->prtF = vlTOPp->mcu__DOT__o_ports[5U];
    vlTOPp->prtG = vlTOPp->mcu__DOT__o_ports[6U];
    vlTOPp->prtH = vlTOPp->mcu__DOT__o_ports[7U];
    vlTOPp->prtI = (7U & vlTOPp->mcu__DOT__o_ports[8U]);
    // ALWAYSPOST at mcu.v:153
    if (__Vdlyvset__mcu__DOT__ram__v0) {
	vlTOPp->mcu__DOT__ram[__Vdlyvdim0__mcu__DOT__ram__v0] 
	    = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__mcu__DOT__ram__v0))) 
		& vlTOPp->mcu__DOT__ram[__Vdlyvdim0__mcu__DOT__ram__v0]) 
	       | ((IData)(__Vdlyvval__mcu__DOT__ram__v0) 
		  << (IData)(__Vdlyvlsb__mcu__DOT__ram__v0)));
    }
    if (__Vdlyvset__mcu__DOT__ram__v1) {
	vlTOPp->mcu__DOT__ram[__Vdlyvdim0__mcu__DOT__ram__v1] 
	    = __Vdlyvval__mcu__DOT__ram__v1;
    }
    vlTOPp->mcu__DOT__dph = __Vdly__mcu__DOT__dph;
    vlTOPp->mcu__DOT__daddr = ((0x40U & (IData)(vlTOPp->mcu__DOT__waddr))
			        ? (0x5fU & (IData)(vlTOPp->mcu__DOT__waddr))
			        : (IData)(vlTOPp->mcu__DOT__waddr));
    // ALWAYS at mcu.v:324
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((1U == (IData)(vlTOPp->mcu__DOT__state))) {
	    if ((0x15U == (IData)(vlTOPp->mcu__DOT__opc))) {
		vlTOPp->mcu__DOT__dpl = (0xfU & (IData)(vlTOPp->mcu__DOT__rdat));
	    }
	} else {
	    if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
		if (((0x2cU == (0xecU & (IData)(vlTOPp->mcu__DOT__rdat))) 
		     | (0x13U == (0xdfU & (IData)(vlTOPp->mcu__DOT__rdat))))) {
		    vlTOPp->mcu__DOT__dpl = vlTOPp->mcu__DOT__alu_r;
		} else {
		    if ((0x80U == (0xf0U & (IData)(vlTOPp->mcu__DOT__rdat)))) {
			vlTOPp->mcu__DOT__dpl = (0xfU 
						 & (IData)(vlTOPp->mcu__DOT__rdat));
		    } else {
			if ((0x4eU == (IData)(vlTOPp->mcu__DOT__rdat))) {
			    vlTOPp->mcu__DOT__dpl = 
				vlTOPp->mcu__DOT__wr
				[5U];
			} else {
			    if ((7U == (IData)(vlTOPp->mcu__DOT__rdat))) {
				vlTOPp->mcu__DOT__dpl 
				    = vlTOPp->mcu__DOT__acc;
			    } else {
				if ((0x4cU == (IData)(vlTOPp->mcu__DOT__rdat))) {
				    vlTOPp->mcu__DOT__dpl 
					= vlTOPp->mcu__DOT__wr
					[3U];
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->mcu__DOT__acc = __Vdly__mcu__DOT__acc;
    // ALWAYSPOST at mcu.v:159
    if (__Vdlyvset__mcu__DOT__wr__v0) {
	vlTOPp->mcu__DOT__wr[__Vdlyvdim0__mcu__DOT__wr__v0] 
	    = (((~ ((IData)(1U) << (IData)(__Vdlyvlsb__mcu__DOT__wr__v0))) 
		& vlTOPp->mcu__DOT__wr[__Vdlyvdim0__mcu__DOT__wr__v0]) 
	       | ((IData)(__Vdlyvval__mcu__DOT__wr__v0) 
		  << (IData)(__Vdlyvlsb__mcu__DOT__wr__v0)));
    }
    if (__Vdlyvset__mcu__DOT__wr__v1) {
	vlTOPp->mcu__DOT__wr[__Vdlyvdim0__mcu__DOT__wr__v1] 
	    = __Vdlyvval__mcu__DOT__wr__v1;
    }
    vlTOPp->mcu__DOT__dp = (((IData)(vlTOPp->mcu__DOT__dph) 
			     << 4U) | (IData)(vlTOPp->mcu__DOT__dpl));
    // ALWAYS at mcu.v:491
    if ((0U == (IData)(vlTOPp->mcu__DOT__clk_cnt))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__state))) {
	    vlTOPp->mcu__DOT__opc = vlTOPp->mcu__DOT__rdat;
	}
    }
    vlTOPp->mcu__DOT__clk_cnt = __Vdly__mcu__DOT__clk_cnt;
    vlTOPp->mcu__DOT__state = __Vdly__mcu__DOT__state;
    // ALWAYS at mcu.v:89
    vlTOPp->mcu__DOT__rdat = vlTOPp->mcu__DOT__rom[vlTOPp->mcu__DOT__pc];
    vlTOPp->mcu__DOT__pc = (((IData)(vlTOPp->mcu__DOT__pcf) 
			     << 8U) | (IData)(vlTOPp->mcu__DOT__pcc));
    // ALWAYS at mcu.v:206
    vlTOPp->mcu__DOT__alu_b = (0xfU & ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				        ? 0U : ((0x40U 
						 & (IData)(vlTOPp->mcu__DOT__rdat))
						 ? 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 0U
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? (IData)(vlTOPp->mcu__DOT__rdat)
						   : 0U))
						 : 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 0U
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 0U
						    : (IData)(vlTOPp->mcu__DOT__rdat)))
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__mdat)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : 0xfU))))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__mdat)))
						    : 0U))))));
    // ALWAYS at mcu.v:220
    vlTOPp->__Vtableidx1 = vlTOPp->mcu__DOT__rdat;
    vlTOPp->mcu__DOT__alu_op = vlTOPp->__Vtable1_mcu__DOT__alu_op
	[vlTOPp->__Vtableidx1];
}

void Vmcu::_settle__TOP__2(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_settle__TOP__2\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mcu__DOT__i_ports[0U] = vlTOPp->prtAI;
    vlTOPp->mcu__DOT__i_ports[1U] = vlTOPp->prtBI;
    vlTOPp->mcu__DOT__i_ports[2U] = vlTOPp->prtCI;
    vlTOPp->mcu__DOT__i_ports[3U] = vlTOPp->prtDI;
    vlTOPp->prtC = vlTOPp->mcu__DOT__o_ports[2U];
    vlTOPp->prtD = vlTOPp->mcu__DOT__o_ports[3U];
    vlTOPp->prtE = vlTOPp->mcu__DOT__o_ports[4U];
    vlTOPp->prtF = vlTOPp->mcu__DOT__o_ports[5U];
    vlTOPp->prtG = vlTOPp->mcu__DOT__o_ports[6U];
    vlTOPp->prtH = vlTOPp->mcu__DOT__o_ports[7U];
    vlTOPp->prtI = (7U & vlTOPp->mcu__DOT__o_ports[8U]);
    vlTOPp->mcu__DOT__daddr = ((0x40U & (IData)(vlTOPp->mcu__DOT__waddr))
			        ? (0x5fU & (IData)(vlTOPp->mcu__DOT__waddr))
			        : (IData)(vlTOPp->mcu__DOT__waddr));
    vlTOPp->mcu__DOT__dp = (((IData)(vlTOPp->mcu__DOT__dph) 
			     << 4U) | (IData)(vlTOPp->mcu__DOT__dpl));
    vlTOPp->mcu__DOT__pc = (((IData)(vlTOPp->mcu__DOT__pcf) 
			     << 8U) | (IData)(vlTOPp->mcu__DOT__pcc));
    // ALWAYS at mcu.v:206
    vlTOPp->mcu__DOT__alu_b = (0xfU & ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				        ? 0U : ((0x40U 
						 & (IData)(vlTOPp->mcu__DOT__rdat))
						 ? 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 0U
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? (IData)(vlTOPp->mcu__DOT__rdat)
						   : 0U))
						 : 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 0U
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 0U
						    : (IData)(vlTOPp->mcu__DOT__rdat)))
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__mdat)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : 0xfU))))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__mdat)))
						    : 0U))))));
    // ALWAYS at mcu.v:220
    vlTOPp->__Vtableidx1 = vlTOPp->mcu__DOT__rdat;
    vlTOPp->mcu__DOT__alu_op = vlTOPp->__Vtable1_mcu__DOT__alu_op
	[vlTOPp->__Vtableidx1];
    // ALWAYS at mcu.v:185
    vlTOPp->mcu__DOT__alu_a = (0xfU & ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				        ? 0U : ((0x40U 
						 & (IData)(vlTOPp->mcu__DOT__rdat))
						 ? 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 0U
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    vlTOPp->mcu__DOT__wr
						    [0U]
						     : (IData)(vlTOPp->mcu__DOT__mdat))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->prtAI)
						     : 
						    vlTOPp->mcu__DOT__i_ports
						    [
						    (3U 
						     & (IData)(vlTOPp->mcu__DOT__dpl))]))
						   : 0U))
						 : 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__dpl)
						     : 0U)
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__dpl)
						       : 0U)
						      : 0U)))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__dpl)
						     : 0U)
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__acc)
						     : 
						    vlTOPp->mcu__DOT__wr
						    [0U])))
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? (IData)(vlTOPp->mcu__DOT__mdat)
						      : 0U)
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__acc)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__dpl)
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      (~ (IData)(vlTOPp->mcu__DOT__acc))
						       : (IData)(vlTOPp->mcu__DOT__acc)))))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? (IData)(vlTOPp->mcu__DOT__acc)
						      : 0U)
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : (IData)(vlTOPp->mcu__DOT__acc))
						      : (IData)(vlTOPp->mcu__DOT__acc)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : (IData)(vlTOPp->mcu__DOT__acc))
						      : 0U)
						     : 0U)))))));
    // ALWAYS at mcu.v:169
    vlTOPp->mcu__DOT__alu_c = 0U;
    if (((((((((0U == (IData)(vlTOPp->mcu__DOT__alu_op)) 
	       | (1U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	      | (2U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	     | (3U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	    | (4U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	   | (5U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	  | (6U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	 | (7U == (IData)(vlTOPp->mcu__DOT__alu_op)))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
	    vlTOPp->mcu__DOT__alu_c = (1U & (((IData)(vlTOPp->mcu__DOT__alu_a) 
					      + (IData)(vlTOPp->mcu__DOT__alu_b)) 
					     >> 4U));
	} else {
	    if ((1U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		vlTOPp->mcu__DOT__alu_c = (1U & ((((IData)(vlTOPp->mcu__DOT__alu_a) 
						   + (IData)(vlTOPp->mcu__DOT__alu_b)) 
						  + (IData)(vlTOPp->mcu__DOT__c)) 
						 >> 4U));
	    } else {
		if ((2U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		    vlTOPp->mcu__DOT__alu_c = (1U & 
					       (((IData)(1U) 
						 + (IData)(vlTOPp->mcu__DOT__alu_a)) 
						>> 4U));
		} else {
		    if ((3U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			vlTOPp->mcu__DOT__alu_c = (1U 
						   & (((IData)(vlTOPp->mcu__DOT__alu_a) 
						       - (IData)(1U)) 
						      >> 4U));
		    } else {
			if ((4U != (IData)(vlTOPp->mcu__DOT__alu_op))) {
			    if ((5U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
				vlTOPp->mcu__DOT__alu_c 
				    = (1U & ((IData)(vlTOPp->mcu__DOT__alu_a) 
					     >> (3U 
						 & (IData)(vlTOPp->mcu__DOT__alu_b))));
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at mcu.v:169
    vlTOPp->mcu__DOT__alu_r = 0U;
    if (((((((((0U == (IData)(vlTOPp->mcu__DOT__alu_op)) 
	       | (1U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	      | (2U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	     | (3U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	    | (4U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	   | (5U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	  | (6U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	 | (7U == (IData)(vlTOPp->mcu__DOT__alu_op)))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
	    vlTOPp->mcu__DOT__alu_r = (0xfU & ((IData)(vlTOPp->mcu__DOT__alu_a) 
					       + (IData)(vlTOPp->mcu__DOT__alu_b)));
	} else {
	    if ((1U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		vlTOPp->mcu__DOT__alu_r = (0xfU & (
						   ((IData)(vlTOPp->mcu__DOT__alu_a) 
						    + (IData)(vlTOPp->mcu__DOT__alu_b)) 
						   + (IData)(vlTOPp->mcu__DOT__c)));
	    } else {
		if ((2U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		    vlTOPp->mcu__DOT__alu_r = (0xfU 
					       & ((IData)(1U) 
						  + (IData)(vlTOPp->mcu__DOT__alu_a)));
		} else {
		    if ((3U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			vlTOPp->mcu__DOT__alu_r = (0xfU 
						   & ((IData)(vlTOPp->mcu__DOT__alu_a) 
						      - (IData)(1U)));
		    } else {
			if ((4U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			    vlTOPp->mcu__DOT__alu_r 
				= ((IData)(vlTOPp->mcu__DOT__alu_a) 
				   ^ (IData)(vlTOPp->mcu__DOT__alu_b));
			} else {
			    if ((5U != (IData)(vlTOPp->mcu__DOT__alu_op))) {
				vlTOPp->mcu__DOT__alu_r 
				    = (0xfU & ((6U 
						== (IData)(vlTOPp->mcu__DOT__alu_op))
					        ? ((IData)(6U) 
						   + (IData)(vlTOPp->mcu__DOT__alu_a))
					        : ((IData)(0xaU) 
						   + (IData)(vlTOPp->mcu__DOT__alu_a))));
			    }
			}
		    }
		}
	    }
	}
    }
}

void Vmcu::_initial__TOP__3(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_initial__TOP__3\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIGW(__Vtemp1,127,0,4);
    // Body
    // INITIAL at mcu.v:86
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x2f726f6dU;
    __Vtemp1[2U] = 0x5f646972U;
    __Vtemp1[3U] = 0x6f626aU;
    VL_READMEM_W(true,8,2048, 0,4, __Vtemp1, vlTOPp->mcu__DOT__rom
		 ,0,~0);
}

VL_INLINE_OPT void Vmcu::_combo__TOP__4(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_combo__TOP__4\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mcu__DOT__i_ports[0U] = vlTOPp->prtAI;
    vlTOPp->mcu__DOT__i_ports[1U] = vlTOPp->prtBI;
    vlTOPp->mcu__DOT__i_ports[2U] = vlTOPp->prtCI;
    vlTOPp->mcu__DOT__i_ports[3U] = vlTOPp->prtDI;
    // ALWAYS at mcu.v:185
    vlTOPp->mcu__DOT__alu_a = (0xfU & ((0x80U & (IData)(vlTOPp->mcu__DOT__rdat))
				        ? 0U : ((0x40U 
						 & (IData)(vlTOPp->mcu__DOT__rdat))
						 ? 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 0U
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    vlTOPp->mcu__DOT__wr
						    [0U]
						     : (IData)(vlTOPp->mcu__DOT__mdat))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->prtAI)
						     : 
						    vlTOPp->mcu__DOT__i_ports
						    [
						    (3U 
						     & (IData)(vlTOPp->mcu__DOT__dpl))]))
						   : 0U))
						 : 
						((0x20U 
						  & (IData)(vlTOPp->mcu__DOT__rdat))
						  ? 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__dpl)
						     : 0U)
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__dpl)
						       : 0U)
						      : 0U)))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__dpl)
						     : 0U)
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? (IData)(vlTOPp->mcu__DOT__acc)
						     : 
						    vlTOPp->mcu__DOT__wr
						    [0U])))
						  : 
						 ((0x10U 
						   & (IData)(vlTOPp->mcu__DOT__rdat))
						   ? 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? (IData)(vlTOPp->mcu__DOT__mdat)
						      : 0U)
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 0U
						      : (IData)(vlTOPp->mcu__DOT__acc)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 0U
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? (IData)(vlTOPp->mcu__DOT__dpl)
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 
						      (~ (IData)(vlTOPp->mcu__DOT__acc))
						       : (IData)(vlTOPp->mcu__DOT__acc)))))
						   : 
						  ((8U 
						    & (IData)(vlTOPp->mcu__DOT__rdat))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? (IData)(vlTOPp->mcu__DOT__acc)
						      : 0U)
						     : 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : (IData)(vlTOPp->mcu__DOT__acc))
						      : (IData)(vlTOPp->mcu__DOT__acc)))
						    : 
						   ((4U 
						     & (IData)(vlTOPp->mcu__DOT__rdat))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->mcu__DOT__rdat))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->mcu__DOT__rdat))
						       ? 0U
						       : (IData)(vlTOPp->mcu__DOT__acc))
						      : 0U)
						     : 0U)))))));
    // ALWAYS at mcu.v:169
    vlTOPp->mcu__DOT__alu_c = 0U;
    if (((((((((0U == (IData)(vlTOPp->mcu__DOT__alu_op)) 
	       | (1U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	      | (2U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	     | (3U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	    | (4U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	   | (5U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	  | (6U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	 | (7U == (IData)(vlTOPp->mcu__DOT__alu_op)))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
	    vlTOPp->mcu__DOT__alu_c = (1U & (((IData)(vlTOPp->mcu__DOT__alu_a) 
					      + (IData)(vlTOPp->mcu__DOT__alu_b)) 
					     >> 4U));
	} else {
	    if ((1U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		vlTOPp->mcu__DOT__alu_c = (1U & ((((IData)(vlTOPp->mcu__DOT__alu_a) 
						   + (IData)(vlTOPp->mcu__DOT__alu_b)) 
						  + (IData)(vlTOPp->mcu__DOT__c)) 
						 >> 4U));
	    } else {
		if ((2U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		    vlTOPp->mcu__DOT__alu_c = (1U & 
					       (((IData)(1U) 
						 + (IData)(vlTOPp->mcu__DOT__alu_a)) 
						>> 4U));
		} else {
		    if ((3U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			vlTOPp->mcu__DOT__alu_c = (1U 
						   & (((IData)(vlTOPp->mcu__DOT__alu_a) 
						       - (IData)(1U)) 
						      >> 4U));
		    } else {
			if ((4U != (IData)(vlTOPp->mcu__DOT__alu_op))) {
			    if ((5U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
				vlTOPp->mcu__DOT__alu_c 
				    = (1U & ((IData)(vlTOPp->mcu__DOT__alu_a) 
					     >> (3U 
						 & (IData)(vlTOPp->mcu__DOT__alu_b))));
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at mcu.v:169
    vlTOPp->mcu__DOT__alu_r = 0U;
    if (((((((((0U == (IData)(vlTOPp->mcu__DOT__alu_op)) 
	       | (1U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	      | (2U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	     | (3U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	    | (4U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	   | (5U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	  | (6U == (IData)(vlTOPp->mcu__DOT__alu_op))) 
	 | (7U == (IData)(vlTOPp->mcu__DOT__alu_op)))) {
	if ((0U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
	    vlTOPp->mcu__DOT__alu_r = (0xfU & ((IData)(vlTOPp->mcu__DOT__alu_a) 
					       + (IData)(vlTOPp->mcu__DOT__alu_b)));
	} else {
	    if ((1U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		vlTOPp->mcu__DOT__alu_r = (0xfU & (
						   ((IData)(vlTOPp->mcu__DOT__alu_a) 
						    + (IData)(vlTOPp->mcu__DOT__alu_b)) 
						   + (IData)(vlTOPp->mcu__DOT__c)));
	    } else {
		if ((2U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
		    vlTOPp->mcu__DOT__alu_r = (0xfU 
					       & ((IData)(1U) 
						  + (IData)(vlTOPp->mcu__DOT__alu_a)));
		} else {
		    if ((3U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			vlTOPp->mcu__DOT__alu_r = (0xfU 
						   & ((IData)(vlTOPp->mcu__DOT__alu_a) 
						      - (IData)(1U)));
		    } else {
			if ((4U == (IData)(vlTOPp->mcu__DOT__alu_op))) {
			    vlTOPp->mcu__DOT__alu_r 
				= ((IData)(vlTOPp->mcu__DOT__alu_a) 
				   ^ (IData)(vlTOPp->mcu__DOT__alu_b));
			} else {
			    if ((5U != (IData)(vlTOPp->mcu__DOT__alu_op))) {
				vlTOPp->mcu__DOT__alu_r 
				    = (0xfU & ((6U 
						== (IData)(vlTOPp->mcu__DOT__alu_op))
					        ? ((IData)(6U) 
						   + (IData)(vlTOPp->mcu__DOT__alu_a))
					        : ((IData)(0xaU) 
						   + (IData)(vlTOPp->mcu__DOT__alu_a))));
			    }
			}
		    }
		}
	    }
	}
    }
}

void Vmcu::_eval(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_eval\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmcu::_eval_initial(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_eval_initial\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void Vmcu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::final\n"); );
    // Variables
    Vmcu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmcu::_eval_settle(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_eval_settle\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vmcu::_change_request(Vmcu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_change_request\n"); );
    Vmcu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmcu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((_INT & 0xfeU))) {
	Verilated::overWidthError("_INT");}
    if (VL_UNLIKELY((prtAI & 0xf0U))) {
	Verilated::overWidthError("prtAI");}
    if (VL_UNLIKELY((prtBI & 0xf0U))) {
	Verilated::overWidthError("prtBI");}
    if (VL_UNLIKELY((prtCI & 0xf0U))) {
	Verilated::overWidthError("prtCI");}
    if (VL_UNLIKELY((prtDI & 0xf0U))) {
	Verilated::overWidthError("prtDI");}
}
#endif // VL_DEBUG

void Vmcu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmcu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    _INT = VL_RAND_RESET_I(1);
    prtAI = VL_RAND_RESET_I(4);
    prtBI = VL_RAND_RESET_I(4);
    prtCI = VL_RAND_RESET_I(4);
    prtDI = VL_RAND_RESET_I(4);
    prtC = VL_RAND_RESET_I(4);
    prtD = VL_RAND_RESET_I(4);
    prtE = VL_RAND_RESET_I(4);
    prtF = VL_RAND_RESET_I(4);
    prtG = VL_RAND_RESET_I(4);
    prtH = VL_RAND_RESET_I(4);
    prtI = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    mcu__DOT__i_ports[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<9; ++__Vi0) {
	    mcu__DOT__o_ports[__Vi0] = VL_RAND_RESET_I(4);
    }}
    mcu__DOT__clk_cnt = VL_RAND_RESET_I(2);
    mcu__DOT__pcf = VL_RAND_RESET_I(3);
    mcu__DOT__pcc = VL_RAND_RESET_I(8);
    mcu__DOT__dph = VL_RAND_RESET_I(3);
    mcu__DOT__dpl = VL_RAND_RESET_I(4);
    mcu__DOT__rdat = VL_RAND_RESET_I(8);
    mcu__DOT__c = VL_RAND_RESET_I(1);
    mcu__DOT__cs = VL_RAND_RESET_I(1);
    mcu__DOT__acc = VL_RAND_RESET_I(4);
    mcu__DOT__state = VL_RAND_RESET_I(2);
    mcu__DOT__opc = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    mcu__DOT__stack[__Vi0] = VL_RAND_RESET_I(11);
    }}
    mcu__DOT__sp = VL_RAND_RESET_I(2);
    mcu__DOT__bcount = VL_RAND_RESET_I(6);
    mcu__DOT__pcount = VL_RAND_RESET_I(6);
    mcu__DOT__tm = VL_RAND_RESET_I(1);
    mcu__DOT__irq = VL_RAND_RESET_I(1);
    mcu__DOT__ien = VL_RAND_RESET_I(1);
    mcu__DOT__dp = VL_RAND_RESET_I(7);
    mcu__DOT__pc = VL_RAND_RESET_I(11);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    mcu__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<7; ++__Vi0) {
	    mcu__DOT__wr[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<96; ++__Vi0) {
	    mcu__DOT__ram[__Vi0] = VL_RAND_RESET_I(4);
    }}
    mcu__DOT__mdat = VL_RAND_RESET_I(4);
    mcu__DOT__din = VL_RAND_RESET_I(4);
    mcu__DOT__waddr = VL_RAND_RESET_I(7);
    mcu__DOT__we = VL_RAND_RESET_I(1);
    mcu__DOT__bset = VL_RAND_RESET_I(2);
    mcu__DOT__daddr = VL_RAND_RESET_I(7);
    mcu__DOT__alu_op = VL_RAND_RESET_I(3);
    mcu__DOT__alu_a = VL_RAND_RESET_I(4);
    mcu__DOT__alu_b = VL_RAND_RESET_I(4);
    mcu__DOT__alu_r = VL_RAND_RESET_I(4);
    mcu__DOT__alu_c = VL_RAND_RESET_I(1);
    mcu__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
    mcu__DOT____Vlvbound2 = VL_RAND_RESET_I(4);
    mcu__DOT____Vlvbound3 = VL_RAND_RESET_I(1);
    mcu__DOT____Vlvbound4 = VL_RAND_RESET_I(4);
    mcu__DOT____Vlvbound5 = VL_RAND_RESET_I(11);
    mcu__DOT____Vlvbound6 = VL_RAND_RESET_I(11);
    mcu__DOT____Vlvbound7 = VL_RAND_RESET_I(11);
    mcu__DOT____Vlvbound8 = VL_RAND_RESET_I(1);
    mcu__DOT____Vlvbound9 = VL_RAND_RESET_I(1);
    mcu__DOT____Vlvbound10 = VL_RAND_RESET_I(4);
    __Vtableidx1 = VL_RAND_RESET_I(8);
    __Vtable1_mcu__DOT__alu_op[0] = 0U;
    __Vtable1_mcu__DOT__alu_op[1] = 0U;
    __Vtable1_mcu__DOT__alu_op[2] = 0U;
    __Vtable1_mcu__DOT__alu_op[3] = 0U;
    __Vtable1_mcu__DOT__alu_op[4] = 0U;
    __Vtable1_mcu__DOT__alu_op[5] = 0U;
    __Vtable1_mcu__DOT__alu_op[6] = 6U;
    __Vtable1_mcu__DOT__alu_op[7] = 0U;
    __Vtable1_mcu__DOT__alu_op[8] = 0U;
    __Vtable1_mcu__DOT__alu_op[9] = 1U;
    __Vtable1_mcu__DOT__alu_op[10] = 7U;
    __Vtable1_mcu__DOT__alu_op[11] = 0U;
    __Vtable1_mcu__DOT__alu_op[12] = 0U;
    __Vtable1_mcu__DOT__alu_op[13] = 2U;
    __Vtable1_mcu__DOT__alu_op[14] = 0U;
    __Vtable1_mcu__DOT__alu_op[15] = 3U;
    __Vtable1_mcu__DOT__alu_op[16] = 4U;
    __Vtable1_mcu__DOT__alu_op[17] = 2U;
    __Vtable1_mcu__DOT__alu_op[18] = 0U;
    __Vtable1_mcu__DOT__alu_op[19] = 3U;
    __Vtable1_mcu__DOT__alu_op[20] = 0U;
    __Vtable1_mcu__DOT__alu_op[21] = 0U;
    __Vtable1_mcu__DOT__alu_op[22] = 0U;
    __Vtable1_mcu__DOT__alu_op[23] = 0U;
    __Vtable1_mcu__DOT__alu_op[24] = 4U;
    __Vtable1_mcu__DOT__alu_op[25] = 1U;
    __Vtable1_mcu__DOT__alu_op[26] = 0U;
    __Vtable1_mcu__DOT__alu_op[27] = 0U;
    __Vtable1_mcu__DOT__alu_op[28] = 0U;
    __Vtable1_mcu__DOT__alu_op[29] = 2U;
    __Vtable1_mcu__DOT__alu_op[30] = 0U;
    __Vtable1_mcu__DOT__alu_op[31] = 3U;
    __Vtable1_mcu__DOT__alu_op[32] = 5U;
    __Vtable1_mcu__DOT__alu_op[33] = 5U;
    __Vtable1_mcu__DOT__alu_op[34] = 5U;
    __Vtable1_mcu__DOT__alu_op[35] = 5U;
    __Vtable1_mcu__DOT__alu_op[36] = 5U;
    __Vtable1_mcu__DOT__alu_op[37] = 5U;
    __Vtable1_mcu__DOT__alu_op[38] = 5U;
    __Vtable1_mcu__DOT__alu_op[39] = 5U;
    __Vtable1_mcu__DOT__alu_op[40] = 0U;
    __Vtable1_mcu__DOT__alu_op[41] = 0U;
    __Vtable1_mcu__DOT__alu_op[42] = 0U;
    __Vtable1_mcu__DOT__alu_op[43] = 0U;
    __Vtable1_mcu__DOT__alu_op[44] = 3U;
    __Vtable1_mcu__DOT__alu_op[45] = 3U;
    __Vtable1_mcu__DOT__alu_op[46] = 3U;
    __Vtable1_mcu__DOT__alu_op[47] = 3U;
    __Vtable1_mcu__DOT__alu_op[48] = 0U;
    __Vtable1_mcu__DOT__alu_op[49] = 0U;
    __Vtable1_mcu__DOT__alu_op[50] = 0U;
    __Vtable1_mcu__DOT__alu_op[51] = 2U;
    __Vtable1_mcu__DOT__alu_op[52] = 0U;
    __Vtable1_mcu__DOT__alu_op[53] = 0U;
    __Vtable1_mcu__DOT__alu_op[54] = 0U;
    __Vtable1_mcu__DOT__alu_op[55] = 0U;
    __Vtable1_mcu__DOT__alu_op[56] = 0U;
    __Vtable1_mcu__DOT__alu_op[57] = 0U;
    __Vtable1_mcu__DOT__alu_op[58] = 0U;
    __Vtable1_mcu__DOT__alu_op[59] = 0U;
    __Vtable1_mcu__DOT__alu_op[60] = 2U;
    __Vtable1_mcu__DOT__alu_op[61] = 2U;
    __Vtable1_mcu__DOT__alu_op[62] = 2U;
    __Vtable1_mcu__DOT__alu_op[63] = 2U;
    __Vtable1_mcu__DOT__alu_op[64] = 0U;
    __Vtable1_mcu__DOT__alu_op[65] = 0U;
    __Vtable1_mcu__DOT__alu_op[66] = 0U;
    __Vtable1_mcu__DOT__alu_op[67] = 0U;
    __Vtable1_mcu__DOT__alu_op[68] = 0U;
    __Vtable1_mcu__DOT__alu_op[69] = 0U;
    __Vtable1_mcu__DOT__alu_op[70] = 0U;
    __Vtable1_mcu__DOT__alu_op[71] = 0U;
    __Vtable1_mcu__DOT__alu_op[72] = 0U;
    __Vtable1_mcu__DOT__alu_op[73] = 0U;
    __Vtable1_mcu__DOT__alu_op[74] = 0U;
    __Vtable1_mcu__DOT__alu_op[75] = 0U;
    __Vtable1_mcu__DOT__alu_op[76] = 0U;
    __Vtable1_mcu__DOT__alu_op[77] = 0U;
    __Vtable1_mcu__DOT__alu_op[78] = 0U;
    __Vtable1_mcu__DOT__alu_op[79] = 0U;
    __Vtable1_mcu__DOT__alu_op[80] = 5U;
    __Vtable1_mcu__DOT__alu_op[81] = 5U;
    __Vtable1_mcu__DOT__alu_op[82] = 5U;
    __Vtable1_mcu__DOT__alu_op[83] = 5U;
    __Vtable1_mcu__DOT__alu_op[84] = 5U;
    __Vtable1_mcu__DOT__alu_op[85] = 5U;
    __Vtable1_mcu__DOT__alu_op[86] = 5U;
    __Vtable1_mcu__DOT__alu_op[87] = 5U;
    __Vtable1_mcu__DOT__alu_op[88] = 5U;
    __Vtable1_mcu__DOT__alu_op[89] = 5U;
    __Vtable1_mcu__DOT__alu_op[90] = 5U;
    __Vtable1_mcu__DOT__alu_op[91] = 5U;
    __Vtable1_mcu__DOT__alu_op[92] = 5U;
    __Vtable1_mcu__DOT__alu_op[93] = 5U;
    __Vtable1_mcu__DOT__alu_op[94] = 5U;
    __Vtable1_mcu__DOT__alu_op[95] = 5U;
    __Vtable1_mcu__DOT__alu_op[96] = 0U;
    __Vtable1_mcu__DOT__alu_op[97] = 0U;
    __Vtable1_mcu__DOT__alu_op[98] = 0U;
    __Vtable1_mcu__DOT__alu_op[99] = 0U;
    __Vtable1_mcu__DOT__alu_op[100] = 0U;
    __Vtable1_mcu__DOT__alu_op[101] = 0U;
    __Vtable1_mcu__DOT__alu_op[102] = 0U;
    __Vtable1_mcu__DOT__alu_op[103] = 0U;
    __Vtable1_mcu__DOT__alu_op[104] = 0U;
    __Vtable1_mcu__DOT__alu_op[105] = 0U;
    __Vtable1_mcu__DOT__alu_op[106] = 0U;
    __Vtable1_mcu__DOT__alu_op[107] = 0U;
    __Vtable1_mcu__DOT__alu_op[108] = 0U;
    __Vtable1_mcu__DOT__alu_op[109] = 0U;
    __Vtable1_mcu__DOT__alu_op[110] = 0U;
    __Vtable1_mcu__DOT__alu_op[111] = 0U;
    __Vtable1_mcu__DOT__alu_op[112] = 0U;
    __Vtable1_mcu__DOT__alu_op[113] = 0U;
    __Vtable1_mcu__DOT__alu_op[114] = 0U;
    __Vtable1_mcu__DOT__alu_op[115] = 0U;
    __Vtable1_mcu__DOT__alu_op[116] = 0U;
    __Vtable1_mcu__DOT__alu_op[117] = 0U;
    __Vtable1_mcu__DOT__alu_op[118] = 0U;
    __Vtable1_mcu__DOT__alu_op[119] = 0U;
    __Vtable1_mcu__DOT__alu_op[120] = 0U;
    __Vtable1_mcu__DOT__alu_op[121] = 0U;
    __Vtable1_mcu__DOT__alu_op[122] = 0U;
    __Vtable1_mcu__DOT__alu_op[123] = 0U;
    __Vtable1_mcu__DOT__alu_op[124] = 0U;
    __Vtable1_mcu__DOT__alu_op[125] = 0U;
    __Vtable1_mcu__DOT__alu_op[126] = 0U;
    __Vtable1_mcu__DOT__alu_op[127] = 0U;
    __Vtable1_mcu__DOT__alu_op[128] = 0U;
    __Vtable1_mcu__DOT__alu_op[129] = 0U;
    __Vtable1_mcu__DOT__alu_op[130] = 0U;
    __Vtable1_mcu__DOT__alu_op[131] = 0U;
    __Vtable1_mcu__DOT__alu_op[132] = 0U;
    __Vtable1_mcu__DOT__alu_op[133] = 0U;
    __Vtable1_mcu__DOT__alu_op[134] = 0U;
    __Vtable1_mcu__DOT__alu_op[135] = 0U;
    __Vtable1_mcu__DOT__alu_op[136] = 0U;
    __Vtable1_mcu__DOT__alu_op[137] = 0U;
    __Vtable1_mcu__DOT__alu_op[138] = 0U;
    __Vtable1_mcu__DOT__alu_op[139] = 0U;
    __Vtable1_mcu__DOT__alu_op[140] = 0U;
    __Vtable1_mcu__DOT__alu_op[141] = 0U;
    __Vtable1_mcu__DOT__alu_op[142] = 0U;
    __Vtable1_mcu__DOT__alu_op[143] = 0U;
    __Vtable1_mcu__DOT__alu_op[144] = 0U;
    __Vtable1_mcu__DOT__alu_op[145] = 0U;
    __Vtable1_mcu__DOT__alu_op[146] = 0U;
    __Vtable1_mcu__DOT__alu_op[147] = 0U;
    __Vtable1_mcu__DOT__alu_op[148] = 0U;
    __Vtable1_mcu__DOT__alu_op[149] = 0U;
    __Vtable1_mcu__DOT__alu_op[150] = 0U;
    __Vtable1_mcu__DOT__alu_op[151] = 0U;
    __Vtable1_mcu__DOT__alu_op[152] = 0U;
    __Vtable1_mcu__DOT__alu_op[153] = 0U;
    __Vtable1_mcu__DOT__alu_op[154] = 0U;
    __Vtable1_mcu__DOT__alu_op[155] = 0U;
    __Vtable1_mcu__DOT__alu_op[156] = 0U;
    __Vtable1_mcu__DOT__alu_op[157] = 0U;
    __Vtable1_mcu__DOT__alu_op[158] = 0U;
    __Vtable1_mcu__DOT__alu_op[159] = 0U;
    __Vtable1_mcu__DOT__alu_op[160] = 0U;
    __Vtable1_mcu__DOT__alu_op[161] = 0U;
    __Vtable1_mcu__DOT__alu_op[162] = 0U;
    __Vtable1_mcu__DOT__alu_op[163] = 0U;
    __Vtable1_mcu__DOT__alu_op[164] = 0U;
    __Vtable1_mcu__DOT__alu_op[165] = 0U;
    __Vtable1_mcu__DOT__alu_op[166] = 0U;
    __Vtable1_mcu__DOT__alu_op[167] = 0U;
    __Vtable1_mcu__DOT__alu_op[168] = 0U;
    __Vtable1_mcu__DOT__alu_op[169] = 0U;
    __Vtable1_mcu__DOT__alu_op[170] = 0U;
    __Vtable1_mcu__DOT__alu_op[171] = 0U;
    __Vtable1_mcu__DOT__alu_op[172] = 0U;
    __Vtable1_mcu__DOT__alu_op[173] = 0U;
    __Vtable1_mcu__DOT__alu_op[174] = 0U;
    __Vtable1_mcu__DOT__alu_op[175] = 0U;
    __Vtable1_mcu__DOT__alu_op[176] = 0U;
    __Vtable1_mcu__DOT__alu_op[177] = 0U;
    __Vtable1_mcu__DOT__alu_op[178] = 0U;
    __Vtable1_mcu__DOT__alu_op[179] = 0U;
    __Vtable1_mcu__DOT__alu_op[180] = 0U;
    __Vtable1_mcu__DOT__alu_op[181] = 0U;
    __Vtable1_mcu__DOT__alu_op[182] = 0U;
    __Vtable1_mcu__DOT__alu_op[183] = 0U;
    __Vtable1_mcu__DOT__alu_op[184] = 0U;
    __Vtable1_mcu__DOT__alu_op[185] = 0U;
    __Vtable1_mcu__DOT__alu_op[186] = 0U;
    __Vtable1_mcu__DOT__alu_op[187] = 0U;
    __Vtable1_mcu__DOT__alu_op[188] = 0U;
    __Vtable1_mcu__DOT__alu_op[189] = 0U;
    __Vtable1_mcu__DOT__alu_op[190] = 0U;
    __Vtable1_mcu__DOT__alu_op[191] = 0U;
    __Vtable1_mcu__DOT__alu_op[192] = 0U;
    __Vtable1_mcu__DOT__alu_op[193] = 0U;
    __Vtable1_mcu__DOT__alu_op[194] = 0U;
    __Vtable1_mcu__DOT__alu_op[195] = 0U;
    __Vtable1_mcu__DOT__alu_op[196] = 0U;
    __Vtable1_mcu__DOT__alu_op[197] = 0U;
    __Vtable1_mcu__DOT__alu_op[198] = 0U;
    __Vtable1_mcu__DOT__alu_op[199] = 0U;
    __Vtable1_mcu__DOT__alu_op[200] = 0U;
    __Vtable1_mcu__DOT__alu_op[201] = 0U;
    __Vtable1_mcu__DOT__alu_op[202] = 0U;
    __Vtable1_mcu__DOT__alu_op[203] = 0U;
    __Vtable1_mcu__DOT__alu_op[204] = 0U;
    __Vtable1_mcu__DOT__alu_op[205] = 0U;
    __Vtable1_mcu__DOT__alu_op[206] = 0U;
    __Vtable1_mcu__DOT__alu_op[207] = 0U;
    __Vtable1_mcu__DOT__alu_op[208] = 0U;
    __Vtable1_mcu__DOT__alu_op[209] = 0U;
    __Vtable1_mcu__DOT__alu_op[210] = 0U;
    __Vtable1_mcu__DOT__alu_op[211] = 0U;
    __Vtable1_mcu__DOT__alu_op[212] = 0U;
    __Vtable1_mcu__DOT__alu_op[213] = 0U;
    __Vtable1_mcu__DOT__alu_op[214] = 0U;
    __Vtable1_mcu__DOT__alu_op[215] = 0U;
    __Vtable1_mcu__DOT__alu_op[216] = 0U;
    __Vtable1_mcu__DOT__alu_op[217] = 0U;
    __Vtable1_mcu__DOT__alu_op[218] = 0U;
    __Vtable1_mcu__DOT__alu_op[219] = 0U;
    __Vtable1_mcu__DOT__alu_op[220] = 0U;
    __Vtable1_mcu__DOT__alu_op[221] = 0U;
    __Vtable1_mcu__DOT__alu_op[222] = 0U;
    __Vtable1_mcu__DOT__alu_op[223] = 0U;
    __Vtable1_mcu__DOT__alu_op[224] = 0U;
    __Vtable1_mcu__DOT__alu_op[225] = 0U;
    __Vtable1_mcu__DOT__alu_op[226] = 0U;
    __Vtable1_mcu__DOT__alu_op[227] = 0U;
    __Vtable1_mcu__DOT__alu_op[228] = 0U;
    __Vtable1_mcu__DOT__alu_op[229] = 0U;
    __Vtable1_mcu__DOT__alu_op[230] = 0U;
    __Vtable1_mcu__DOT__alu_op[231] = 0U;
    __Vtable1_mcu__DOT__alu_op[232] = 0U;
    __Vtable1_mcu__DOT__alu_op[233] = 0U;
    __Vtable1_mcu__DOT__alu_op[234] = 0U;
    __Vtable1_mcu__DOT__alu_op[235] = 0U;
    __Vtable1_mcu__DOT__alu_op[236] = 0U;
    __Vtable1_mcu__DOT__alu_op[237] = 0U;
    __Vtable1_mcu__DOT__alu_op[238] = 0U;
    __Vtable1_mcu__DOT__alu_op[239] = 0U;
    __Vtable1_mcu__DOT__alu_op[240] = 0U;
    __Vtable1_mcu__DOT__alu_op[241] = 0U;
    __Vtable1_mcu__DOT__alu_op[242] = 0U;
    __Vtable1_mcu__DOT__alu_op[243] = 0U;
    __Vtable1_mcu__DOT__alu_op[244] = 0U;
    __Vtable1_mcu__DOT__alu_op[245] = 0U;
    __Vtable1_mcu__DOT__alu_op[246] = 0U;
    __Vtable1_mcu__DOT__alu_op[247] = 0U;
    __Vtable1_mcu__DOT__alu_op[248] = 0U;
    __Vtable1_mcu__DOT__alu_op[249] = 0U;
    __Vtable1_mcu__DOT__alu_op[250] = 0U;
    __Vtable1_mcu__DOT__alu_op[251] = 0U;
    __Vtable1_mcu__DOT__alu_op[252] = 0U;
    __Vtable1_mcu__DOT__alu_op[253] = 0U;
    __Vtable1_mcu__DOT__alu_op[254] = 0U;
    __Vtable1_mcu__DOT__alu_op[255] = 0U;
}
