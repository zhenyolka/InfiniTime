#include "components/motion/MotionController.h"
#include "os/os_cputime.h"
using namespace Pinetime::Controllers;

void MotionController::Update(int16_t x, int16_t y, int16_t z, uint32_t nbSteps) {
  if (this->nbSteps != nbSteps && service != nullptr) {
    service->OnNewStepCountValue(nbSteps);
  }

  if (service != nullptr && (this->x != x || lastYs[lastYIndex] != y || this->z != z)) {
    service->OnNewMotionValues(x, y, z);
  }

  lastYIndex++;
  lastYIndex %= lastYs.size();
  lastYs[lastYIndex] = y;
  this->x = x;
  this->z = z;
  int32_t deltaSteps = nbSteps - this->nbSteps;
  this->nbSteps = nbSteps;
  if (deltaSteps > 0) {
    currentTripSteps += deltaSteps;
  }
}

bool MotionController::Should_RaiseWake(bool isSleeping) {
  if ((x + 335) <= 670 && z < 0) {
    if (not isSleeping) {
      if (lastYs[lastYIndex] <= 0) {
        return false;
      } else {
        lastYForWakeUp = 0;
        return false;
      }
    }

    if (lastYs[lastYIndex] >= 0) {
      lastYForWakeUp = 0;
      return false;
    }
    if (lastYs[lastYIndex] + 230 < lastYForWakeUp) {
      lastYForWakeUp = lastYs[lastYIndex];
      return true;
    }
  }
  return false;
}

bool MotionController::Should_ShakeWake(uint16_t thresh) {
  bool wake = false;
  auto diff = xTaskGetTickCount() - lastShakeTime;
  lastShakeTime = xTaskGetTickCount();
  /* Currently Polling at 10hz, If this ever goes faster scalar and EMA might need adjusting */
  int32_t speed = std::abs(z + (lastYs[lastYIndex] / 2) + (x / 4) - lastYForShake - lastZForShake) / diff * 100;
  //(.2 * speed) + ((1 - .2) * accumulatedspeed);
  // implemented without floats as .25Alpha
  accumulatedspeed = (speed / 5) + ((accumulatedspeed / 5) * 4);

  if (accumulatedspeed > thresh) {
    wake = true;
  }
  lastXForShake = x / 4;
  lastYForShake = lastYs[lastYIndex] / 2;
  lastZForShake = z;
  return wake;
}
int32_t MotionController::currentShakeSpeed() {
  return accumulatedspeed;
}

bool MotionController::ShouldLowerSleep() const {
  if (lastYs[(lastYIndex + 2) % lastYs.size()] < lastYs[(lastYIndex + 1) % lastYs.size()] + 192 ||
      lastYs[(lastYIndex + 2) % lastYs.size()] < 512) {
    return false;
  }

  for (uint8_t i = 3; i < lastYs.size(); i++) {
    if (lastYs[(lastYIndex + i) % lastYs.size()] < 0) {
      return false;
    }
  }

  return true;
}

void MotionController::IsSensorOk(bool isOk) {
  isSensorOk = isOk;
}
void MotionController::Init(Pinetime::Drivers::Bma421::DeviceTypes types) {
  switch (types) {
    case Drivers::Bma421::DeviceTypes::BMA421:
      this->deviceType = DeviceTypes::BMA421;
      break;
    case Drivers::Bma421::DeviceTypes::BMA425:
      this->deviceType = DeviceTypes::BMA425;
      break;
    default:
      this->deviceType = DeviceTypes::Unknown;
      break;
  }
}
void MotionController::SetService(Pinetime::Controllers::MotionService* service) {
  this->service = service;
}
