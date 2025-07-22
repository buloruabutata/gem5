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
std::string
MConfOp::generateDisassembly(Addr pc, const loader::SymbolTable *symtab) const
{
    std::stringstream ss;
    ss << mnemonic << ' ' << registerName(destRegIdx(0)) << ", "<< registerName(srcRegIdx(0));
    return ss.str();
}

} // namespace RiscvISA
} // namespace gem5