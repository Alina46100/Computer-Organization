#include<stdio.h>
int main()
{
 int i=0;
 int h[9]={0}, x[3]={0}, y[3]={0};
 FILE *input = fopen("../input/4.txt","r");
 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
 fclose(input);
 int *p_x = &x[0] ;
 int *p_h = &h[0] ;
 int *p_y = &y[0] ;
 		asm volatile(
 		"li s5, 0\n\t"//s5 = 0
 		"li s1, 1\n\t"//s1 = 1
 		"li s2, 12\n\t"// s2 = 12
 		"li s3, 0\n\t"//f  = 0
 		"li s11, 3\n\t" //s11 = 3
 		"loop:\n\t"
 		"lw s4, (%0)\n\t"    //p_h
  		"lw s7, (%1)\n\t"    //p_x
  		"lw s8, (%2)\n\t"//p_y
  		"mul s9, s4, s7\n\t" //s9 = *p_h*p_x
  		"add s10, s8, s9\n\t"//s10 = *p_x**p_h+py
  		"sw s10, (%2)\n\t"     //store to %2
  		"addi %0, %0, 4\n\t"//*p_h++ 
  		"addi %1, %1, 4\n\t" //*p_x++
  		"add s3, s3 , s1\n\t"//f++
  		"bne s3, s11, loop\n" //If f != 3, jump to label loop
  		//"beq s3, s11, 2f\n\t"  // If f == 3, jump to label 2
  		//"j loop\n\t"//jump to loop:
  		
  		//"label2:\n\t"
  		"sub s3, s3, s11\n\t"//f  = 0
  		"sub %1, %1, s2\n\t"//p_x = &x[0]
  		"addi %2, %2, 4\n\t" //*p_y++
  		"add s5, s5, s1\n\t"//i++
  		"bne s5, s11, loop\n" //If i f!= 3, jump to label loop
  		//"beq s5, s11, 3f\n\t"//If i == 3, jump to label 3
  		//"j loop \n\t"
  		//"label3:\n\t"
  		
  		:"+r"(p_h), "+r"(p_x), "+r"(p_y)
  		: 
  		: "s4", "s7", "s8", "s9", "s10", "s11", "s1", "s2", "s3", "s5", "memory"
  		//p_h, p_x, p_y, *p_h*p_x, result, 3,   1   ,   12, f   ,i
		
 		
 		);
 p_y = &y[0];
 for(i = 0; i<3; i++)
 printf("%d \n", *p_y++);
 return(0) ;

}
/*for (i = 0 ; i < 3; i++)
 {

 p_x = &x[0] ;
 for (f = 0 ; f < 3; f++)
  asm volatile(/*(*p_y = *p_y + *p_h++ * *p_x++;*/
 		/*"lw a0, (%0)\n\t"    
  		"lw a1, (%1)\n\t"    
  		"lw a2, (%2)\n\t"
  		"mul a3, a0, a1\n\t" //*p_h*p_x
  		"add a4, a2, a3\n\t"//*p_x**p_h+py
  		"sw a4, (%2)\n\t"     //store to %2
  		"addi %0, %0, 4\n\t"//*p_x++ 
  		"addi %1, %1, 4\n\t" //*p_h++
  		"li a5, 2\n\t"
  		"bne %3, a5, 1f\n\t"  // If i == 2, jump to label 3
  		"addi %2, %2, 4\n\t" //*p_y++
  		"1:\n\t"
  		
  		:"+r"(p_h), "+r"(p_x), "+r"(p_y), "+r"(f)
  		: 
  		: "a0", "a1", "a2", "a3", "a4", "a5", "memory"
		
 				
 		);*/

 //}
