#include "RleDecoder.h"

using namespace Pinetime::Tools;

RleDecoder::RleDecoder(const uint8_t *buffer, size_t size) : buffer{buffer}, size{size} {

}

void RleDecoder::DecodeNext(uint8_t *output, size_t maxBytes) {
  for (;encodedBufferIndex<size; encodedBufferIndex++) {
    uint8_t rl = buffer[encodedBufferIndex] - processedCount;
    while (rl) {
      output[bp] = color >> 8;
      output[bp + 1] = color & 0xff;
      bp += 2;
      rl -= 1;
      processedCount++;

      if (bp >= maxBytes) {
        bp = 0;
        y += 1;
        return;
      }
    }
    processedCount = 0;

    if (color == backgroundColor)
      color = foregroundColor;
    else
      color = backgroundColor;
  }
}