#include "libavcodec/vpx_rac.h"
#include "libavcodec/vpx_rac.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint8_t input[] = { 0x00, 0x11, 0x24, 0x10, 0xa };
  int input_size = sizeof(input);

  uint8_t buffer[16];
  int buffer_size = sizeof(buffer);

  VPXRangeEncoder coder;
  ff_vpx_init_range_encoder(&coder, buffer, buffer_size);

  // inputがなくなるまで1ビットずつエンコード
  for (int i = 0; i < input_size; i++) {;
      printf("Encoding byte: 0x%x\n", input[i]);
      vpx_rac_put_prob(&coder, (input[i] >> 7) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 2) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 5) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 4) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 3) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 2) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 1) & 1, 204);
      vpx_rac_put_prob(&coder, (input[i] >> 0) & 1, 204);
  }

  // bufferを出力
  printf("Encoded buffer: ");
  for (int i = 0; i < buffer_size; i++) {
      printf("%02x ", buffer[i]);
  }
  printf("\n");

  return 0;
}