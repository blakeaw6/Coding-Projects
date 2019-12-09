module  Dflipflop(q, _q, D, clk, clear, set);
  input D, clk, clear, set;
  output q, _q;
  reg q, _q;

  //As long as clear and set are not low, then q will wait for
  //posedge of the clock and change according to the values
  //at D.
  //   If D is high, q is high.
  //   If D is low, q is low.
  
  always @(posedge clk or negedge clear or negedge set)
    begin
      if (~clear) begin
         q <= 1'b0;
        _q <= 1'b1;
      end else if (~set) begin
         q <= 1'b1;
        _q <= 1'b0;
      end else begin
        case ({D})
          1'b1: begin
             q <= 1'b1;
            _q <= 1'b0;
          end
          1'b0: begin
             q <= 1'b0;
            _q <= 1'b1;
          end
        endcase
      end
    end
endmodule

module coin_count (dollar, nickel, cur_stat, reset, enable, clk, coin);
  input reset;
  input enable;
  input clk;
  input coin;
  output dollar;
  output nickel;
  output [3:0] cur_stat;

//  wire [3:0] cur_stat;
  wire s3, sb3, s2, sb2, s1, sb1, s0, sb0;
  wire d3, d2, d1, d0;
  wire x, xb;
  wire gclk;

  // assigning the outputs of the flops to be current state
  assign x = coin;
  assign cur_stat[3] = s3;
  assign cur_stat[2] = s2;
  assign cur_stat[1] = s1;
  assign cur_stat[0] = s0;

  not not_x(xb, coin);
  and clk_g(gclk, clk, enable);
  Dflipflop D3(.q(s3), ._q(sb3), .D(d3), .clk(gclk), .set(1'b1), .clear(reset));
  Dflipflop D2(.q(s2), ._q(sb2), .D(d2), .clk(gclk), .set(1'b1), .clear(reset));
  Dflipflop D1(.q(s1), ._q(sb1), .D(d1), .clk(gclk), .set(1'b1), .clear(reset));
  Dflipflop D0(.q(s0), ._q(sb0), .D(d0), .clk(gclk), .set(1'b1), .clear(reset));

  //D3
   and D3a(D3a, xb, sb3, s2, s0);
   and D3b(D3b, xb, sb3, s1, sb0);
   and D3c(D3c, x, s2, sb1);
   or D3(d3, D3a, D3b, D3c);
   
  //D2
   and D2a(D2a, xb, sb3, s0);
   and D2b(D2b, sb3, s1);
   and D2c(D2c, x, s2, sb1);
   or D2(d2,  D2a, D2b, D2c);
  
  //D1
   and D1a(D1a, xb, sb3, s2, s0);
   and D1b(D1b, xb, s3, s1, sb0);
   and D1c(D1c, xb, sb2, sb1);
   and D1d(D1d, x, s3, sb1);
   and D1e(D1e, x, sb2, s1);
   and D1f(D1f, sb2, sb1, s0);
   or D1(d1, D1a, D1b, D1c, D1d, D1e, D1f);
   
  //D0
   and D0a(D0a, xb, s3, s0);
   and D0b(D0b, xb, s2, s1);
   and D0c(D0c, x, sb1, sb0);
   and D0d(D0d, x, sb3, sb0);
   and D0e(D0e, sb2, sb1, s0);
   or D0(d0, D0a, D0b, D0c, D0d, D0e);

  //dollar voucher out 
   and dollarA(dollarA, xb, s3);
   and dollarB(dollarB, xb, s2, sb1, sb0);
   and dollarC(dollarC, s3, s1);
   or dollar(dollar, dollarA, dollarB, dollarC);
   
   //nickel
   and nickelA(nickelA, xb, s3, sb1, sb0);
   and nickelB(nickelB, xb, s3, s1, s0);
   and nickelC(nickelC, s3, s1, sb0);
   or nickel(nickel, nickelA, nickelB, nickelC);
   
endmodule

module project2_tb ();

  reg clk ;
  reg reset;
  reg enable;
  reg coin;
  reg exp_dlr;
  reg exp_nkl;
  wire dollar;
  wire nickel;
  wire [3:0] cur_stat;
  integer count = 0;
  integer tot = 0;


  always begin
    #5 clk = ~clk;
  end

  always @(negedge clk)  begin
    #6;
    if (~reset) begin
        exp_dlr = 0;
        exp_nkl = 0;
        count = 0;
    end else if (enable) begin
      if (coin == 1 && count == 60) begin
        exp_dlr = 1;
        exp_nkl = 0;
        count = 0;
      end else if (coin == 1 && count == 65) begin
        exp_dlr = 1;
        exp_nkl = 1;
        count = 0;
      end else if (coin == 0 && count == 45) begin
        exp_dlr = 1;
        exp_nkl = 0;
        count = 0;
      end else if (coin == 0 && count == 50) begin
        exp_dlr = 1;
        exp_nkl = 1;
        count = 0;
      end else if (coin == 0 && count == 55) begin
        exp_dlr = 1;
        exp_nkl = 0;
        count = 10;
      end else if (coin == 0 && count == 60) begin
        exp_dlr = 1;
        exp_nkl = 1;
        count = 10;
      end else if (coin == 0 && count == 65) begin
        exp_dlr = 1;
        exp_nkl = 0;
        count = 20;
      end else if (coin == 1) begin
        exp_dlr = 0;
        exp_nkl = 0;
        count = count + 10;
      end else begin
        exp_dlr = 0;
        exp_nkl = 0;
        count = count + 25;
      end
    end else begin
      exp_dlr = 0;
      exp_nkl = 0;
      count = count;
    end
  end

  always @(posedge clk) begin
    case (cur_stat)
      4'b0000: tot = 0;
      4'b0001: tot = 10;
      4'b0011: tot = 20;
      4'b0010: tot = 25;
      4'b0110: tot = 30;
      4'b0111: tot = 35;
      4'b0101: tot = 40;
      4'b0100: tot = 45;
      4'b1100: tot = 50;
      4'b1101: tot = 55;
      4'b1111: tot = 60;
      4'b1110: tot = 65;
      4'b1010: tot = 10;
      4'b1011: tot = 10;
      4'b1001: tot = 10;
      4'b1000: tot = 10;
    endcase
    $display("  %b     %b     %b   %b      %b     %b      %4b   %2d  | %4d     %b    %b   %b   %b   %b   %b", reset, enable, clk, coin, dollar, nickel, cur_stat, tot,  count, exp_dlr, exp_nkl, u_coin_count.d3, u_coin_count.d2, u_coin_count.d1, u_coin_count.d0);
  end

  initial begin
    $display("reset enable clk coin dollar nickel cur_stat tot |  
              etot  edlr enkl D3 D2 D1 D0");
    clk = 1'b0;
    reset  = 1'b0;
    enable = 1'b0;
    coin   = 1'b1;
    repeat (2) @(negedge clk);
    reset = 1'b1;
    enable = 1'b1;
    // Insert 8 dimes
    repeat (8) @(negedge clk);
    @(negedge clk) enable = 1'b0; reset = 1'b0;
    // reset counter
    @(negedge clk) reset = 1'b1; enable = 1'b1; coin = 1'b0;;
    // Insert 5 quarters
    repeat (5) @(negedge clk);
    @(negedge clk) reset = 1'b0; coin = 1'b0;
    @(negedge clk) reset = 1'b1; coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b1;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b0;
    @(negedge clk) coin = 1'b1;
    $finish;
  end


  coin_count u_coin_count (
    .dollar(dollar),
    .nickel(nickel),
    .cur_stat(cur_stat),
    .reset(reset),
    .clk(clk),
    .enable(enable),
    .coin(coin));

endmodule
