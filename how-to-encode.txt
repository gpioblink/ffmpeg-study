<encode>

  Input [0x00, 0x10, 0x20, 0x0a, 0x10, 0x04, 0x88, 0x21]
  Probability {0: 0.8, 1: 0.2} [prob=204]

  norm_shift {0x0: 8, 0x1:7, 0x2-0x3: 6, 0x4-0x7: 5, 0x8-0xF: 4, 0x10-0x1F: 3, 0x20-0x3F: 2, 0x40-0x7F: 1, 0x80-0xFF: 0}

  low = high-range
  bound = 1+((high-1)*prob) >> 8

Encode decision formula
  When bit==1, range_next=high-bound, high_next=high
  When bit==0, range_next=bound, high_next=high-low

(Values are in hexadecimal)

[ high, range]   e(lo,bo)    [ high, range] (norm info)
Encoding byte: 0x0
[   ff,    ff] - 0( 0,cb) -> [   cb,    cb]
[   cb,    cb] - 0( 0,a1) -> [   a1,    a1]
[   a1,    a1] - 0( 0,80) -> [   80,    80]
[   80,    80] - 0( 0,66) -> [   66,    66] shift 1 bits (data 0x0, next -15 bits) 
[   cc,    cc] - 0( 0,a2) -> [   a2,    a2]
[   a2,    a2] - 0( 0,81) -> [   81,    81]
[   81,    81] - 0( 0,67) -> [   67,    67] shift 1 bits (data 0x0, next -14 bits) 
[   ce,    ce] - 0( 0,a4) -> [   a4,    a4]
Encoding byte: 0x10
[   a4,    a4] - 0( 0,82) -> [   82,    82]
[   82,    82] - 0( 0,67) -> [   67,    67] shift 1 bits (data 0x0, next -13 bits) 
[   ce,    ce] - 0( 0,a4) -> [   a4,    a4]
[   a4,    a4] - 1( 0,82) -> [   a4,    22] shift 2 bits (data 0x2, next -11 bits) 
[   90,    88] - 0( 8,72) -> [   72,    6a] shift 1 bits (data 0x0, next -10 bits) 
[   e4,    d4] - 0(10,b5) -> [   b5,    a5]
[   b5,    a5] - 0(10,90) -> [   90,    80]
[   90,    80] - 0(10,72) -> [   72,    62] shift 1 bits (data 0x0, next -9 bits) 
Encoding byte: 0x20
[   e4,    c4] - 0(20,b5) -> [   b5,    95]
[   b5,    95] - 0(20,90) -> [   90,    70] shift 1 bits (data 0x1, next -8 bits) 
[   20,    e0] - 1(ffffff40,19) -> [   20,     7] shift 5 bits (data 0x4, next -3 bits) 
[    0,    e0] - 0(ffffff20, 0) -> [    0,    e0]
[    0,    e0] - 0(ffffff20, 0) -> [    0,    e0]



