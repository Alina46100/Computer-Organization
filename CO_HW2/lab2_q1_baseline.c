// TODO : 	
"addi t3, x0, 0\n\t"	//i
 	 "addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi t4, x0, 16\n\t"//16
	 "addi %[arith_cnt], %[arith_cnt], 1\n\t"                                                
"addi t5, x0, 1\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"loop:\n\t"
	
"lh t0, (%[h])\n\t"//ph   
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"lh t1, (%[x])\n\t"//px
  	"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"add t2, t0, t1\n\t" //py=p_h+p_x
  	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"sh t2, (%[y])\n\t"    //store to p_y 
  	"addi %[sw_cnt], %[sw_cnt], 1\n\t"
"addi %[y], %[y], 2\n\t" //p_y++
  	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi %[h], %[h], 2\n\t" //p_h++
  	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi %[x], %[x], 2\n\t" //p_x++
  	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi t3, t3, 1\n\t"//i++
  	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bne t3, t4, loop\n"//if i!=16 to loop
  	

 	     	
 	     	
 	     
