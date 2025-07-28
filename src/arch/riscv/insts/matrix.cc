#include "arch/riscv/insts/matrix.hh"

#include <sstream>
#include <string>

#include "arch/riscv/insts/static_inst.hh"
#include "arch/riscv/isa.hh"
#include "arch/riscv/regs/misc.hh"
#include "arch/riscv/regs/matrix.hh"
#include "arch/riscv/utility.hh"
#include "cpu/static_inst.hh"

namespace gem5
{

namespace RiscvISA
{
uint32_t
getMSew(uint32_t msew)
{
    assert(msew <= 3);
    std::cout << "MSEW = " << (8 << msew) << std::endl;
    return (8 << msew);
}

uint32_t
getMtilemMax(uint32_t mlen, uint32_t mrlen)
{
    uint32_t mtilemmax = mlen/mrlen; 
    return mtilemmax;
}

uint32_t 
getMtilekMax(uint32_t mlen, uint32_t mrlen, uint32_t msew)
{
    uint32_t mtilekmax = (mlen/mrlen < mrlen/msew) ?  mlen/mrlen : mrlen/msew ; 
    return mtilekmax;
}

uint32_t
getMtilenMax(uint32_t mrlen, uint32_t msew)
{
    uint32_t mtilenmax = mrlen/msew; 
    return mtilenmax;
}
    
std::string
MConfOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "<< registerName(srcRegIdx(0));
    return ss.str();
}

std::string
MSetTilemOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << registerName(srcRegIdx(0)); 
    return ss.str();
}

std::string
MSetTilemiOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << imm10;
    return ss.str();
}

std::string
MSetTilekOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << registerName(srcRegIdx(0)); 
    return ss.str();
}

std::string
MSetTilekiOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << imm10;
    return ss.str();
}

std::string
MSetTilenOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << registerName(srcRegIdx(0)); 
    return ss.str();
}

std::string
MSetTileniOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "
    << imm10;
    return ss.str();
}

} // namespace RiscvISA
} // namespace gem5