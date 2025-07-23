#ifndef __ARCH_RISCV_REGS_MATRIX_HH__
#define __ARCH_RISCV_REGS_MATRIX_HH__

#include <cstdint>
#include <string>

#include "arch/riscv/types.hh"
#include "base/bitunion.hh"
#include "cpu/reg_class.hh"
 
namespace gem5
{
 
namespace RiscvISA
{  
 
BitUnion64(MTYPE)
    Bitfield<63>    mill;
    Bitfield<62,17> reserved;
    Bitfield<16>    mma ;
    Bitfield<15>    mba ;
    Bitfield<14>    mfp64;    
    Bitfield<13,12> mfp32;
    Bitfield<11,10> mfp16;
    Bitfield<9,8>   mfp8;
    Bitfield<7>     mint64;
    Bitfield<6>     mint32;
    Bitfield<5>     mint16;
    Bitfield<4>     mint8;
    Bitfield<3>     mint4;
    Bitfield<2,0>   msew;
EndBitUnion(MTYPE)

BitUnion64(MTILEM)
EndBitUnion(MTILEM)

BitUnion64(MTILEN)
EndBitUnion(MTILEN)

BitUnion64(MTILEK)
EndBitUnion(MTILEK)

}
} // namespace gem5

#endif // __ARCH_RISCV_REGS_MATRIX_HH__