#include "libavcodec/vpx_rac.h"
#include "libavcodec/vpx_rac.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  //uint8_t buffer[] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66 };
  uint8_t buffer[] = { 0x12, 0x34, 0x56, 0x78 };
  int buffer_size = sizeof(buffer);

  uint8_t encoded_char = 0;
  int count = 0;

  VPXRangeCoder coder;
  ff_vpx_init_range_decoder(&coder, buffer, buffer_size);

  while (!vpx_rac_is_end(&coder)) {
      // int bit = vpx_rac_get(&coder);
      int bit = vpx_rac_get_prob_branchy(&coder, 204);

      printf("Decoded bit: %d\n", bit);

      encoded_char = (encoded_char << 1) | bit;
      count++;
      if (count >= 8) {
          printf("Decoded byte(%d): 0x%x\n", count, encoded_char);
          count = 0;
          encoded_char = 0;
      }

      printf("\n");
  }

  if (count > 0) {
    printf("Decoded byte(%d): 0x%x\n", count, encoded_char);
  }

  return 0;
}