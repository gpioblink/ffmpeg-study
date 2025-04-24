#include "libavcodec/vpx_rac.h"
#include "libavcodec/vpx_rac.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint8_t buffer[] = { 0x11, 0x22, 0xaa, 0x55 };
  int buffer_size = sizeof(buffer);

  uint8_t encoded_char = 0;
  int count = 0;

  VPXRangeCoder coder;
  ff_vpx_init_range_decoder(&coder, buffer, buffer_size);

  printf("[  code, high]   (co low)d    [ coden,highn] (norm info)");
  while (!vpx_rac_is_end(&coder)) {
      int bit = vpx_rac_get_prob_branchy(&coder, 204);

      encoded_char = (encoded_char << 1) | bit;
      count++;
      if (count >= 8) {
          printf(" decoded byte(%d): 0x%x ", count, encoded_char);
          count = 0;
          encoded_char = 0;
      }
  }

  if (count > 0) {
    printf(" decoded byte(%d): 0x%x", count, encoded_char);
  }
  printf("\n");

  return 0;
}