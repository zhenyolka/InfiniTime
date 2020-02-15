#include "Rainbow.h"

using namespace Pinetime::Applications::Screens;

void Rainbow::Refresh(bool fullRefresh) {
  if(fullRefresh) {
    gfx.FillRectangle(0, 0, 240, 240, 0x0000);

    gfx.SetScrollArea(0, 240, 320 - 240);
    scrollLine = 0;
    b = 31;
    r = 0;
    g = 0;
    step = 0;
  }

  gfx.SetScrollStartLine(scrollLine);

  switch(step) {
    case 0:
      if(r == 31) step = 1;
      else r++;
      break;
    case 1:
      if(b == 0) step = 2;
      else b--;
      break;
    case 2:
      if(g == 31) step = 3;
      else g++;
      break;
    case 3:
      if(r == 0) step = 4;
      else r--;
      break;
    case 4:
      if(b == 31) step = 5;
      else b++;
      break;
    case 5:
      if(g == 0) step = 0;
      else g--;
      break;
  }

  uint16_t color = (g &  0x1f) | ((r & 0x1f) << 6) | ((b & 0x1f) << 11);

  // Invert the 2 byte from color to adapt to the lcd controller
  uint8_t l = color & 0x00ffu;
  uint8_t h = (color >> 8u) & 0x00ffu;

  uint16_t c = h + (l << 8);

  gfx.FillRectangle(0, scrollLine,240,1, c);
  scrollLine+=1;

  if(scrollLine == 240) scrollLine = 0;
}
