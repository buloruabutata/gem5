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
    uint32_t
    getMSew(uint32_t msew);

    uint32_t
    getMtilemMax(uint32_t mlen, uint32_t mrlen);

    uint32_t 
    getMtilekMax(uint32_t mlen, uint32_t mrlen, uint32_t msew);

    uint32_t
    getMtilenMax(uint32_t mrlen, uint32_t msew);

    class MConfOp : public RiscvStaticInst
    {
        protected:
        uint64_t mimm10;
        uint64_t mimm;
        MConfOp(const char *mnem, ExtMachInst _extMachInst, OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              mimm10(_extMachInst.imm10), mimm(_extMachInst.mimm)
    {
        this->flags[IsMatrix] = true;
    }
    
    std::string generateDisassembly(
        Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTilemOp : public RiscvStaticInst
    {
        protected:
            uint32_t mlen;
            uint32_t mrlen;

        MSetTilemOp(const char *mnem, ExtMachInst _extMachInst,
                uint32_t _mlen, uint32_t _mrlen,
                OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              mlen(_mlen),
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTilemiOp : public RiscvStaticInst
    {
        protected:
            uint64_t imm10;
            uint32_t mlen;
            uint32_t mrlen;

        MSetTilemiOp(const char *mnem, ExtMachInst _extMachInst,
                uint32_t _mlen, uint32_t _mrlen,
                OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              imm10(_extMachInst.imm10),
              mlen(_mlen),
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTilenOp : public RiscvStaticInst
    {
        protected:
        uint32_t mrlen;
        MSetTilenOp(const char *mnem, ExtMachInst _extMachInst,
            uint32_t _mrlen,
            OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTileniOp : public RiscvStaticInst
    {
        protected:
        uint64_t imm10;
        uint32_t mrlen;
        MSetTileniOp(const char *mnem, ExtMachInst _extMachInst,
                uint32_t _mrlen,
                OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              imm10(_extMachInst.imm10),
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTilekOp : public RiscvStaticInst
    {
        protected:
            uint32_t mlen;
            uint32_t mrlen;

        MSetTilekOp(const char *mnem, ExtMachInst _extMachInst,
                uint32_t _mlen, uint32_t _mrlen,
                OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass),
              mlen(_mlen),
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };

    class MSetTilekiOp : public RiscvStaticInst
    {
        protected:
            uint64_t imm10;
            uint32_t mlen;
            uint32_t mrlen;
        MSetTilekiOp(const char *mnem, ExtMachInst _extMachInst,
                uint32_t _mlen, uint32_t _mrlen,
                OpClass __opClass)
            : RiscvStaticInst(mnem, _extMachInst, __opClass), 
              imm10(_extMachInst.imm10), 
              mlen(_mlen), 
              mrlen(_mrlen)
            
        {
            this->flags[IsMatrix] = true;
        }

        std::string generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const override;
    };
} // namespace RiscvISA
} // namespace gem5
#endif // __ARCH_RISCV_INSTS_MATRIX_HH__