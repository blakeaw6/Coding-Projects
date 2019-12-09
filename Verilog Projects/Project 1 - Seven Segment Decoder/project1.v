//project1.v
//Author: Blake Wishard
//CMPE 212 - Project1

module seven_segment_display(a, b, c, d, e, f, g, A,B,C,D);

   input A, B, C, D;
   output a, b, c, d, e, f, g;

   wire   a1, a2, a3, a4, b1, b2, b3, c1, c2, c3, d1, d2, d3, d4, d5, d5Add, e1,
           e2, e3, e4, f1, f2, f3, g1, g2, g3;
   
   //Segment a
   and a1(a1, ~A, C);
   and a2(a2, ~A, B, D);
   and a3(a3, A, ~B, ~C);
   and a4(a4, ~B, ~C, ~D);
   or a(a, a1, a2, a3, a4);

   //Segment b
   and b1(b1, ~A, ~B);
   and b2(b2, ~A, ~C, ~D);
   and b3(b3, ~A, C, D);
   
   or b(b, A, b1, b2, b3);
   
   //Segment c
   and c1(c1, ~A, ~B, ~C);
   and c2(c2, ~A, C, D);
   and c3(c3, ~A, B);
   or c(c, A, c1, c2, c3);
   
   //Segment d
   and d1(d1, A, ~B, ~C);
   and d2(d2, ~B, ~C, ~D);
   and d3(d3, ~A, ~B, C);
   and d4(d4, ~A, C, ~D);
   and d5(d5, ~A, B, ~C, D);
   or  Add_d4_to_d5(Add_d4_to_d5, d4, d5);
   or d(d, d1, d2, d3, Add_d4_to_d5);

   //Segment e
   and e1(e1, C, ~D);
   and e2(e2, A, B);
   or  Add_e1_to_e2(Add_e1_to_e2, e1, e2);
   and e3(e3, A, ~C, ~D);
   and e4(e4, A, C, D);
   and e5(e5, ~B, ~C, ~D);
   or e(e, Add_e1_to_e2, e3, e4, e5);   
  
   //Segment f
   and f1(f1, B, ~C, D);
   and f2(f2, B, C, ~D);
   and f3(f3,  ~C, ~D);
   or f(f, A, f1, f2, f3);

   //Segment g
   and g1(g1, ~A, B, ~C);
   and g2(g2, C, ~D);
   and g3(g3, ~A, ~B, C);
   or g(g, A, g1, g2, g3);
   
endmodule // sevenSegmentDisplay

module testbench_seven_segment_display();
   logic [0:3] switches;
   wire        a,b,c,d,e,f,g;
   
   seven_segment_display sevSegDisp(a,b,c,d,e,f,g,switches[0],switches[1],switches[2], 
                                    switches[3]);

   initial begin
      switches = 0000;
      $display("switches=ABCD\n");
      #1600 $finish;
   end
   
   always
     begin 
	#100 $display("%t, switches=%b, a=%b, b=%b, c=%b, d=%b, e=%b, f=%b, g=%b", $time, switches,a,b,c,d,e,f,g);
	
	switches = switches + 0001;
	
     end
   
endmodule
	
   
   
   
