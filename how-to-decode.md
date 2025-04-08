<decode>

  Input [11, 22, aa, 55]
  Probability {0: 0.8, 1: 0.2} [prob=204]

  norm_shift {0x0: 8, 0x1:7, 0x2-0x3: 6, 0x4-0x7: 5, 0x8-0xF: 4, 0x10-0x1F: 3, 0x20-0x3F: 2, 0x40-0x7F: 1, 0x80-0xFF: 0}

  low = 1+((high-1)*prob) >> 8

Decode decision formula
  When co(code first 8 bytes)< low, code_next=code, high_next=low
  When co(code first 8 bytes)>=low, code_next=code-(low<<16), high_next=high-low

(Values are in hexadecimal)
Reads 3 bytes [11, 22, aa] of code word and initialises code.
[  code, high]   (co low)d    [ coden,highn] (norm info)
[1122aa,   ff] - ( 0< cb)0 -> [1122aa,   cb]
[1122aa,   cb] - ( 0< a1)0 -> [1122aa,   a1]
[1122aa,   a1] - ( 0< 80)0 -> [1122aa,   80]
[1122aa,   80] - ( 0< 66)0 -> [1122aa,   66] shift 1 bits (next -15 bits) 
[224554,   cc] - ( 0< a2)0 -> [224554,   a2]
[224554,   a2] - ( 0< 81)0 -> [224554,   81]
[224554,   81] - ( 0< 67)0 -> [224554,   67] shift 1 bits (next -14 bits) 
[448aa8,   ce] - ( 0< a4)0 -> [448aa8,   a4]
[448aa8,   a4] - ( 0< 82)0 -> [448aa8,   82]
[448aa8,   82] - ( 0< 67)0 -> [448aa8,   67] shift 1 bits (next -13 bits) 
[891550,   ce] - ( 0< a4)0 -> [891550,   a4]
[891550,   a4] - ( 0>=82)1 -> [ 71550,   22] shift 2 bits (next -11 bits) 
[1c5540,   88] - ( 0< 6c)0 -> [1c5540,   6c] shift 1 bits (next -10 bits) 
[38aa80,   d8] - ( 0< ac)0 -> [38aa80,   ac]
[38aa80,   ac] - ( 0< 89)0 -> [38aa80,   89]
[38aa80,   89] - ( 0< 6d)0 -> [38aa80,   6d] shift 1 bits (next -9 bits) 
[715500,   da] - ( 0< ad)0 -> [715500,   ad]
[715500,   ad] - ( 0< 8a)0 -> [715500,   8a]
[715500,   8a] - ( 0>=6e)1 -> [ 35500,   1c] shift 3 bits (next -6 bits) 
[1aa800,   e0] - ( 0< b2)0 -> [1aa800,   b2]
[1aa800,   b2] - ( 0< 8e)0 -> [1aa800,   8e]
[1aa800,   8e] - ( 0< 71)0 -> [1aa800,   71] shift 1 bits (next -5 bits) 
[355000,   e2] - ( 0< b4)0 -> [355000,   b4]
[355000,   b4] - ( 0< 8f)0 -> [355000,   8f]
[355000,   8f] - ( 0< 72)0 -> [355000,   72] shift 1 bits (next -4 bits) 
[6aa000,   e4] - ( 0< b5)0 -> [6aa000,   b5]
[6aa000,   b5] - ( 0< 90)0 -> [6aa000,   90]
[6aa000,   90] - ( 0< 72)0 -> [6aa000,   72] shift 1 bits (next -3 bits) 
[d54000,   e4] - ( 0>=b5)1 -> [204000,   2f] shift 2 bits (next -1 bits) 
[810000,   bc] - ( 0< 96)0 -> [810000,   96]
[810000,   96] - ( 0>=77)1 -> [ a0000,   1f] add 5500(<<2), shift 3 bits (next -14 bits) 
[515400,   f8] - ( 0< c5)0 -> [515400,   c5]
[515400,   c5] - ( 0< 9d)0 -> [515400,   9d]
[515400,   9d] - ( 0< 7d)0 -> [515400,   7d] shift 1 bits (next -13 bits) 
[a2a800,   fa] - ( 0< c7)0 -> [a2a800,   c7]
[a2a800,   c7] - ( 0>=9e)1 -> [ 4a800,   29] shift 2 bits (next -11 bits) 
[12a000,   a4] - ( 0< 82)0 -> [12a000,   82]
[12a000,   82] - ( 0< 67)0 -> [12a000,   67] shift 1 bits (next -10 bits) 
[254000,   ce] - ( 0< a4)0 -> [254000,   a4]
[254000,   a4] - ( 0< 82)0 -> [254000,   82]
[254000,   82] - ( 0< 67)0 -> [254000,   67] shift 1 bits (next -9 bits) 
[4a8000,   ce] - ( 0< a4)0 -> [4a8000,   a4]
[4a8000,   a4] - ( 0< 82)0 -> [4a8000,   82]
[4a8000,   82] - ( 0< 67)0 -> [4a8000,   67] shift 1 bits (next -8 bits) 
[950000,   ce] - ( 0< a4)0 -> [950000,   a4]
[950000,   a4] - ( 0>=82)1 -> [130000,   22] shift 2 bits (next -6 bits) 
[4c0000,   88] - ( 0< 6c)0 -> [4c0000,   6c] shift 1 bits (next -5 bits) 
[980000,   d8] - ( 0< ac)0 -> [980000,   ac]
[980000,   ac] - ( 0>=89)1 -> [ f0000,   23] shift 2 bits (next -3 bits) 
[3c0000,   8c] - ( 0< 6f)0 -> [3c0000,   6f] shift 1 bits (next -2 bits) 
[780000,   de] - ( 0< b1)0 -> [780000,   b1]
[780000,   b1] - ( 0< 8d)0 -> [780000,   8d]
[780000,   8d] - ( 0>=70)1 -> [ 80000,   1d] shift 3 bits (next 1 bits) 
[400000,   e8] - ( 0< b9)0 -> [400000,   b9]
[400000,   b9] - ( 0< 93)0 -> [400000,   93]
[400000,   93] - ( 0< 75)0 -> [400000,   75] shift 1 bits (next 2 bits) 
[800000,   ea] - ( 0< ba)0 -> [800000,   ba]
[800000,   ba] - ( 0< 94)0 -> [800000,   94]
[800000,   94] - ( 0>=76)1 -> [ a0000,   1e] shift 3 bits (next 5 bits) 
[500000,   f0] - ( 0< bf)0 -> [500000,   bf]
[500000,   bf] - ( 0< 98)0 -> [500000,   98]
[500000,   98] - ( 0< 79)0 -> [500000,   79] shift 1 bits (next 6 bits) 
[a00000,   f2] - ( 0< c1)0 -> [a00000,   c1]
[a00000,   c1] - ( 0>=9a)1 -> [ 60000,   27]


