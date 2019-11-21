# All fields are in hex format
# 
# address
# uc_addr_mux[2]    next insn addr = uc_next_addr, flags, IR opcode
# uc_alu_func[2]    0 = add, 1 = xor, 2 = and, 3 = or
# uc_alu_comp_b     1 = compliment b
# uc_alu_ci         1 = carry in
# uc_alu_flags_clk  1 = clock the flag latch
# uc_mar_we         1 = clock a write into MAR
# uc_mem_we         1 = clock a write into the RAM
# uc_mbr_out_we     1 = clock a write into the MBR_out latch
# uc_mbr_in_we      1 = clock a write into the MBR_in latch
# uc_reg_we_clk     1 = clock a write intot he register file
# uc_reg_addr_ir    0 = use reg addr from uc, 1 = use the a field address from IR 
# uc_reg_addr[3]    the uc destination register address if writing 
# uc_alu_reg_a_ir   0 = set alu_reg_a mux using the uc address, 1 = use the a field from the IR
# uc_alu_reg_a[3]   uc address for alu_reg_a
# uc_alu_reg_b_ir   0 = set alu_reg_b mux using the uc address, 1 = use the b field from the IR
# uc_alu_reg_b[3]   uc address for alu_reg_b
# uc_next_addr[16]  uc next instruction

# read a byte from memory and put it into the IR

0000 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # do nothing

#############################
# fetch an insn from PC address 
0001 0  0 0 0  0 1 0 0 0  0 0 5  0 4 0 7 0002   # put the PC reg value into the MAR
0002 0  0 0 0  0 0 0 0 1  0 0 5  0 4 0 7 0003   # falling edge on uc_mar_we, rising edge on uc_mbr_in_we
0003 0  0 0 0  0 0 0 0 0  0 0 5  0 4 0 7 0004   # falling edge on uc_mbr_in_we
0004 0  0 0 0  0 0 0 0 0  1 0 5  0 7 0 4 0005   # rising edge on uc_reg_we_clk w/ir as target
0005 0  0 0 0  0 0 0 0 0  0 0 5  0 7 0 4 0006   # falling edge on uc_reg_we_clk

# add 1 to PC
0006 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 0007   # add 1 to PC & rising edge on uc_reg_we_clk
0007 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 0010   # falling edge on uc_reg_we_clk

#############################
# instruction decode logic
0010 2  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 00f0   # branch based on the opcode in the IR!

00f0 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1000   # opcode 0 NOP
00f1 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1100   # opcode 1 LD Ra,imm
00f2 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1200   # opcode 2 ST Ra,imm
00f3 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1300   # opcode 3 ADD Ra,Rb
00f4 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1400   # opcode 4 SUB Ra,Rb
00f5 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1500   # opcode 5 XOR Ra,Rb
00f6 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1600   # opcode 6 AND Ra,Rb
00f7 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1700   # opcode 7 OR Ra,Rb
00f8 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1800   # opcode 8 MOV Ra,Rb
00f9 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1900   # opcode 9 LD Ra,mem(imm)
00fa 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1a00   # opcode a B imm (absolute)
00fb 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1b00   # opcode b BR PC+imm
00fc 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1c00   # opcode c BZ PC+imm
00fd 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 1d00   # opcode d BNZ PC+imm
00fe 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 ffff   # opcode e
00ff 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 ffff   # opcode f HALT

#############################
# NOP no operation
1000 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch

#############################
# LD Ra,imm
# fetch the byte in memory that the PC is pointing to now
1100 0  0 0 0  0 1 0 0 0  0 0 7  0 4 0 7 1101   # MAR <- PC
1101 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1102   #
1102 0  0 0 0  0 0 0 0 1  0 0 7  0 7 0 7 1103   # MBR_IN <- d_in
1103 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1104   #
1104 0  0 0 0  0 0 0 0 0  1 1 7  0 7 0 4 1105   # Ra <- MBR_IN
1105 0  0 0 0  0 0 0 0 0  0 1 7  0 7 0 4 1106   #
1106 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 1107   # PC <- PC+1
1107 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 1108   # 

1108 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.3 
# ST Ra,imm
# fetch the byte in memory that the PC is pointing to now
1200 0  0 0 0  0 1 0 0 0  0 0 7  0 4 0 7 1201   # MAR <- PC
1201 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1202   #
1202 0  0 0 0  0 0 0 0 1  0 0 7  0 4 0 7 1203   # MBR_IN <- d_in
1203 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1204   #
1204 0  0 0 0  0 1 0 0 0  0 0 7  0 7 0 4 1205   # MAR <- MBR_IN
1205 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 4 1206   #
1206 0  0 0 0  0 0 0 1 0  0 0 7  1 7 0 7 1207   # MBR_OUT <- Ra
1207 0  0 0 0  0 0 0 0 0  0 0 7  1 7 0 7 1208   # 
1208 0  0 0 0  0 0 1 0 0  0 0 7  1 7 0 7 1209   # mem(MAR) <- MBR_OUT
1209 0  0 0 0  0 0 0 0 0  0 0 7  1 7 0 7 120a   # 
120a 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 120b   # PC <- PC+1
120b 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 120c   # 
120c 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch



#############################
# 2.4 
# ADD Ra,Rb
# add the contents of Rb to Ra
1300 0  0 0 0  1 0 0 0 0  1 1 7  1 7 1 7 1301   # Ra <- Ra + Rb
1301 0  0 0 0  0 0 0 0 0  0 1 7  1 7 1 7 1302   #
1302 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.5
# SUB Ra,Rb
# Subtract the contents of Rb from Ra
1400 0  0 1 1  1 0 0 0 0  1 1 7  1 7 1 7 1401   # Ra <- Ra -s Rb
1401 0  0 1 1  0 0 0 0 0  0 1 7  1 7 1 7 1402   #
1402 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.6
# XOR Ra,Rb
1500 0  1 0 0  1 0 0 0 0  1 1 7  1 7 1 7 1501   # XOR Ra,Rb
1501 0  1 0 0  0 0 0 0 0  0 1 7  1 7 1 7 1502   #
1502 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.7
# AND Ra,Rb
1600 0  2 0 0  1 0 0 0 0  1 1 7  1 7 1 7 1601   # AND Ra,Rb
1601 0  2 0 0  0 0 0 0 0  0 1 7  1 7 1 7 1602   #
1602 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.8
# OR Ra,Rb
1700 0  3 0 0  1 0 0 0 0  1 1 7  1 7 1 7 1701   # OR Ra,Rb
1701 0  3 0 0  0 0 0 0 0  0 1 7  1 7 1 7 1702   #
1702 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch



#############################
# 2.9
# MOV Ra,Rb
1800 0  0 0 0  0 0 0 0 0  1 1 7  1 7 1 7 1801   # Ra <- Rb + 0
1801 0  0 0 0  0 0 0 0 0  0 1 7  1 7 1 7 1802   #
1802 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.10
# LD Ra,(mem)imm
1900 0  0 0 0  0 1 0 0 0  0 0 7  0 4 0 7 1901   # MAR <- PC
1901 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1902   #
1902 0  0 0 0  0 0 0 0 1  0 0 7  0 7 0 7 1903   # MBR_IN <- d_in
1903 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1904   #
1904 0  0 0 0  0 1 0 0 0  0 0 7  0 7 0 4 1905   # MAR <- MBR_IN
1905 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 4 1906   #
1906 0  0 0 0  0 0 0 0 1  0 0 7  0 7 0 7 1907   # MBR_IN <- d_in
1907 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1908   #
1908 0  0 0 0  0 0 0 0 0  1 1 7  0 7 0 4 1909   # Ra <- MBR_IN
1909 0  0 0 0  0 0 0 0 0  0 1 7  0 7 0 4 190a   #
190a 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 190b   # PC <- PC+1
190b 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 190c   # 
190c 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch




#############################
# 2.11
# B imm
1a00 0  0 0 0  0 1 0 0 0  0 0 7  0 4 0 7 1a01   # MAR <- PC
1a01 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1a02   #
1a02 0  0 0 0  0 0 0 0 1  0 0 7  0 7 0 7 1a03   # MBR_IN <- d_in
1a03 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1a04   #
1a04 0  0 0 0  0 0 0 0 0  1 0 4  0 7 0 4 1a05   # PC <- MBR_IN
1a05 0  0 0 0  0 0 0 0 0  0 0 4  0 7 0 4 1a06   # 
1a06 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.12
# Br imm
1b00 0  0 0 0  0 1 0 0 0  0 0 7  0 4 0 7 1b01   # MAR <- PC
1b01 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1b02   #
1b02 0  0 0 0  0 0 0 0 1  0 0 7  0 4 0 7 1b03   # MBR_IN <- d_in
1b03 0  0 0 0  0 0 0 0 0  0 0 7  0 4 0 7 1b04   #
1b04 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 1b05   # PC <- PC+1
1b05 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 1b06   # 
1b06 0  0 0 0  0 0 0 0 0  1 0 4  0 4 0 4 1b07   # PC <- PC + MBR_IN
1b07 0  0 0 0  0 0 0 0 0  0 0 4  0 4 0 4 1b08   # 
1b08 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch


#############################
# 2.13
# BZ PC+imm
1c00 1  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1c01   # truth table

1c01 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S - - - 
1c02 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - U - -
1c03 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - - Z -  *
1c04 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - - - N
1c05 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S U - -
1c06 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - U Z -  *
1c07 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - - Z N  *
1c08 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S - - N
1c09 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - U - N
1c0a 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S - U -
1c0b 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S U Z -  *
1c0c 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - U Z N  *
1c0d 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S U - N
1c0e 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S - Z N  *
1c0f 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S U Z N  *
1c10 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - - - -



#############################
# 2.14
# BNZ PC+imm
1d00 1  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1d10   # truth table

1d10 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S - - - 
1d11 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - U - -
1d12 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - - Z -  *
1d13 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - - - N
1d14 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S U - -
1d15 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - U Z -  *
1d16 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - - Z N  *
1d17 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S - - N
1d18 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - U - N
1d19 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S - U -
1d1a 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S U Z -  *
1d1b 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # - U Z N  *
1d1c 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # S U - N
1d1d 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S - Z N  *
1d1e 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1e00   # S U Z N  *
1d1f 0  0 0 0  0 0 0 0 0  0 0 7  0 7 0 7 1b00   # - - - -


#############################
# PC <- PC + 1
1e00 0  0 0 1  0 0 0 0 0  1 0 4  0 4 0 7 1e01   # PC <- PC+1
1e01 0  0 0 1  0 0 0 0 0  0 0 4  0 4 0 7 1e02   # 
1e02 0  0 0 0  0 0 0 0 0  0 0 0  0 7 0 7 0001   # go to insn fetch
