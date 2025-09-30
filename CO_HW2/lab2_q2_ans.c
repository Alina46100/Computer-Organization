"addi x30, x0, 8\n\t"
        "addi x31, x0, 8\n\t"
	"vsetvli x30, x31, e16, ta, ma\n\t"
	"add t0, x0, %[target]\n\t"
	"addi x27, x0, 8\n\t"             // Loop bound
	"addi x28, x0, 0\n\t"                  // i = 0
	"addi x29, x0, 1\n\t"
	"vle16.v v1, (%[p_x])\n\t"     // Load p_x[j] into v1
	"vvad2:\n\t"  
		"lh t1, (%[p_x])\n\t"//t1 = xi
		"vadd.vx v2, v1, t1\n\t"       // xi + xjarray
		
		"vmseq.vx v3, v2, %[target]\n\t"     // compar0(e v2 to tar,if ==1,!=0
		"vredsum.vs v4, v3,v0\n\t"
		"vmv.x.s x29,v4\n\t"
		
		"beq x29,x0, skip\n\t"// v3!=target,loopvvad2
		"slli x30, x30, 1\n\t"
		"addi %[flag], x0, 1\n\t"                // else Set flag to 1
		"j ex\n\t"                    // Exit the loop

		"skip:\n\t"  
		"addi x28, x28, 1\n\t" //i++
		"addi %[p_x], %[p_x], 2\n\t"
		"bne x28, x27, vvad2\n\t"       // If i < 8, continue the loop
	"ex:\n\t"  

