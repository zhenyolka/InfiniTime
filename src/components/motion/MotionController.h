#pragma once

#include <cstdint>
#include <array>
#include <drivers/Bma421.h>
#include <components/ble/MotionService.h>

namespace Pinetime {
  namespace Controllers {
    class MotionController {
    public:
      enum class DeviceTypes {
        Unknown,
        BMA421,
        BMA425,
      };

      void Update(int16_t x, int16_t y, int16_t z, uint32_t nbSteps);

      int16_t X() const {
        return x;
      }
      int16_t Y() const {
        return lastYs[lastYIndex];
      }
      int16_t Z() const {
        return z;
      }
      int16_t DeltaY() const {
        return deltaY;
      }
      int16_t DeltaZ() const {
        return deltaZ;
      }
      uint32_t NbSteps() const {
        return nbSteps;
      }

      void ResetTrip() {
        currentTripSteps = 0;
      }
      uint32_t GetTripSteps() const {
        return currentTripSteps;
      }

      bool ShouldRaiseWake() const;
      bool Should_ShakeWake(uint16_t thresh);
      int32_t currentShakeSpeed();
      bool ShouldLowerSleep() const;
      void IsSensorOk(bool isOk);
      bool IsSensorOk() const {
        return isSensorOk;
      }

      DeviceTypes DeviceType() const {
        return deviceType;
      }

      void Init(Pinetime::Drivers::Bma421::DeviceTypes types);
      void SetService(Pinetime::Controllers::MotionService* service);

    private:
      uint32_t nbSteps;
      uint32_t currentTripSteps = 0;
      int16_t x = 0;
      std::array<int16_t, 8> lastYs = {};
      uint8_t lastYIndex = 0;
      int16_t lastYForWakeUp = 0;
      int16_t y = 0;
      int16_t z = 0;
      int16_t deltaY = 0;
      int16_t deltaZ = 0;
      const int16_t raiseWakeXThresh = 512;
      const int16_t raiseWakeYThresh = 0;
      const int16_t raiseWakeSpeed = 192;

      bool isSensorOk = false;
      DeviceTypes deviceType = DeviceTypes::Unknown;
      Pinetime::Controllers::MotionService* service = nullptr;

      int16_t lastXForShake = 0;
      int16_t lastYForShake = 0;
      int16_t lastZForShake = 0;
      int32_t accumulatedspeed = 0;
      uint32_t lastShakeTime = 0;
    };
  }
}
