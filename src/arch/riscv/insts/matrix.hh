#ifndef __ARCH_RISCV_INSTS_MATRIX_HH__
#define __ARCH_RISCV_INSTS_MATRIX_HH__

#include <string>

#include "arch/riscv/faults.hh"
#include "arch/riscv/insts/static_inst.hh"
#include "arch/riscv/isa.hh"
#include "arch/riscv/regs/misc.hh"
#include "arch/riscv/utility.hh"
#include "cpu/exec_context.hh"
#include "cpu/static_inst.hh"

namespace gem5
{
namespace RiscvISA
{
    class MConfOp : public RiscvStaticInst
    {
        protected:
        uint64_t mimm10;
        uint64_t msetval;
        MConfOp(const char *mnem, ExtMachInst _extMachInst, OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              mimm10(_extMachInst.imm10), msetval(_extMachInst.setval)
    {
        this->flags[IsMatrix] = true;
    }
    
    std::string generateDisassembly(
        Addr pc, const loader::SymbolTable *symtab) const override;
    };
} // namespace RiscvISA
} // namespace gem5
#endif // __ARCH_RISCV_INSTS_MATRIX_HH__