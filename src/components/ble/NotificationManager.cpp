#include "components/ble/NotificationManager.h"
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace Pinetime::Controllers;

constexpr uint8_t NotificationManager::MessageSize;

void NotificationManager::Push(NotificationManager::Notification&& notif) {
  notif.valid = true;
  newNotification = true;
  if (begin_idx > 0) {
    --begin_idx;
  } else {
    begin_idx = notifications.size() - 1;
  }
  notifications[begin_idx] = std::move(notif);
  if (size_ < notifications.size()) {
    size_++;
  }
}

NotificationManager::Notification NotificationManager::GetLastNotification() {
  if (this->IsEmpty()) {
    return {};
  }
  return this->At(0);
}

const NotificationManager::Notification& NotificationManager::At(NotificationManager::Notification::Id idx) const {
  if (idx >= notifications.size()) {
    assert(false);
    return notifications.at(begin_idx); // this should not happen
  }
  size_t read_idx = (begin_idx + idx) % notifications.size();
  return notifications.at(read_idx);
}

NotificationManager::Notification& NotificationManager::At(NotificationManager::Notification::Id idx) {
  if (idx >= notifications.size()) {
    assert(false);
    return notifications.at(begin_idx); // this should not happen
  }
  size_t read_idx = (begin_idx + idx) % notifications.size();
  return notifications.at(read_idx);
}

NotificationManager::Notification NotificationManager::GetNext(NotificationManager::Notification::Id idx) const {
  if (idx == 0 || idx > notifications.size()) {
    return {};
  }
  return this->At(idx - 1);
}

NotificationManager::Notification NotificationManager::GetPrevious(NotificationManager::Notification::Id idx) const {
  if (static_cast<size_t>(idx + 1) >= notifications.size()) {
    return {};
  }
  return this->At(idx + 1);
}

void NotificationManager::Dismiss(NotificationManager::Notification::Id idx) {
  if (this->IsEmpty())
    return;
  if (idx >= size_) {
    assert(false);
    return; // this should not happen
  }
  if (idx == 0) { // just remove the first element, don't need to change the other elements
    notifications.at(begin_idx).valid = false;
    begin_idx = (begin_idx + 1) % notifications.size();
  } else {
    // overwrite the specified entry by moving all later messages one index to the front
    for (size_t i = idx; i < size_ - 1; ++i) {
      this->At(i) = this->At(i + 1);
    }
    this->At(size_ - 1).valid = false;
  }
  --size_;
}

bool NotificationManager::AreNewNotificationsAvailable() const {
  return newNotification;
}

bool NotificationManager::ClearNewNotificationFlag() {
  return newNotification.exchange(false);
}

size_t NotificationManager::NbNotifications() const {
  return size_;
}

const char* NotificationManager::Notification::Message() const {
  const char* itField = std::find(message.begin(), message.begin() + size - 1, '\0');
  if (itField != message.begin() + size - 1) {
    const char* ptr = (itField) + 1;
    return ptr;
  }
  return const_cast<char*>(message.data());
}

const char* NotificationManager::Notification::Title() const {
  const char* itField = std::find(message.begin(), message.begin() + size - 1, '\0');
  if (itField != message.begin() + size - 1) {
    return message.data();
  }
  return {};
}
