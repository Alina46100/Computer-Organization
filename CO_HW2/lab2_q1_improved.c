// TODO :
"addi x6, x0, 16\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi x5, x0, 1\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"


"vvad: \n\t"
	"vsetvli x5, x6, e16\n\t"
	"addi %[others_cnt], %[others_cnt], 1\n\t"
"vle16.v v0, (%[h])\n\t"//get first vec
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"sub x6, x6, x5\n\t"//decrement number done
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"slli x5, x5, 1\n\t"//<<
"add %[h], %[h], x5\n\t"//h++
	"addi %[arith_cnt], %[arith_cnt], 2\n\t"


"vle16.v v1, (%[x])\n\t"//get second vec
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"add %[x], %[x], x5\n\t"//x++
"vadd.vv v2, v0, v1\n\t"//sum
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

"vse16.v v2, (%[y])\n\t"//store result
	"addi %[sw_cnt], %[sw_cnt], 1\n\t"

"add %[y], %[y], x5\n\t"//y++
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
	"addi %[others_cnt], %[others_cnt], 1\n\t"
"bnez x6, vvad\n\t"//loop
	
