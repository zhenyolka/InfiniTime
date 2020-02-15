#pragma once

#include "Screen.h"

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Rainbow  : public Screen{
        public:
          explicit Rainbow(Components::Gfx& gfx) : Screen(gfx) {}

          void Refresh(bool fullRefresh) override;

        private:
          uint16_t scrollLine = 0;
          uint8_t r = 0;
          uint8_t g = 0;
          uint8_t b = 0;

          uint8_t step = 0;
      };
    }
  }
}