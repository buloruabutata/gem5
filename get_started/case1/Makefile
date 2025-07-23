target ?= riscv64-unknown-elf
march ?= rv64gv0p10zfh0p1
src ?= mset

all: run

run:
	mkdir -p build
	clang --target=$(target) \
		-march=$(march) \
		-menable-experimental-extensions \
		-mllvm -riscv-v-vector-bits-min=128 \
		-o build/$(src).riscv $(src).c
	$(target)-objdump -d build/$(src).riscv > build/$(src).dump

dump:
	mkdir -p build
	$(target)-gcc $(src).c -o build/$(src).elf
	$(target)-objdump -d build/$(src).elf > build/$(src).dump

gem5:
	../../build/RISCV/gem5.opt ../../configs/deprecated/example/se.py --cmd=/home/yany/shixi/get_started/case1/mset.riscv | tee build/gem5.log