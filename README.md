# TEMU
A Mips Simulator written in c.

## Usage 

### Docker Env
```shell
sudo docker build -t temu .   
   
sudo docker run -itd --name TEMU -p 8848:8848 -p 8888:8888 -v /mnt/d/C/TEMU:/temu temu /bin/bash  
  
sudo docker exec -it TEMU /bin/bash  
```

### Download Mips Cross Compiler
```shell
wget https://sourcery.mentor.com/public/gnu_toolchain/mips-sde-elf/mips-2013.05-65-mips-sde-elf.bin 

dpkg-reconfigure –plow dash
```
Then Enter the path of compiler and execute following command:
```shell
export PATH={Your compiler path}/bin:$PATH
```
  
Try to use mips cross compiler:
```shell
mips-sde-elf-gcc –v
```

## GUI
In this project we use node.js as our backend developing tool.
```shell
nodemon --watch './node_be/src/**/*.ts' -L --exec 'ts-node' ./node_be/src/index.ts
```

## 通过测试的指令:  
**I-type Instruction**  

- [x] addi
- [x] addiu
- [x] slti
- [x] sltiu
- [x] andi
- [x] lui
- [x] ori
- [x] xori
- [x] beq
- [x] bne
- [x] bgez
- [x] bgtz
- [x] blez
- [x] bltz
- [x] bgezal
- [x] bltzal
- [x] lb
- [x] lbu
- [x] lh
- [x] lhu
- [x] lw
- [x] sb
- [x] sh
- [x] sw 

**R-type Instruction**
- [x] add
- [x] addu
- [x] sub
- [x] subu
- [x] slt
- [x] sltu
- [x] and
- [x] nor
- [x] or
- [x] div
- [x] divu
- [x] mult
- [x] multu
- [x] mfhi
- [x] mflo
- [x] mthi
- [x] mtlo
- [x] sll
- [x] srav
- [x] sra
- [x] srl
- [x] jr
- [x] jalr

**J-type Instruction**
- [x] j
- [x] jal

**Exception and Other**
- [x] break
- [x] syscall
- [x] mfc0
- [x] mtc0
- [x] eret