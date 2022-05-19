#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>

namespace Pinetime {
  namespace Controllers {
    class NotificationManager {
    public:
      enum class Categories {
        Unknown,
        SimpleAlert,
        Email,
        News,
        IncomingCall,
        MissedCall,
        Sms,
        VoiceMail,
        Schedule,
        HighProriotyAlert,
        InstantMessage
      };
      static constexpr uint8_t MessageSize {100};

      struct Notification {
        using Id = uint8_t;
        bool valid = false;
        uint8_t size;
        std::array<char, MessageSize + 1> message;
        Categories category = Categories::Unknown;

        const char* Message() const;
        const char* Title() const;
      };

      void Push(Notification&& notif);
      Notification GetLastNotification();
      const Notification& At(Notification::Id id) const;
      Notification& At(Notification::Id id);
      Notification GetNext(Notification::Id id) const;
      Notification GetPrevious(Notification::Id id) const;
      bool ClearNewNotificationFlag();
      bool AreNewNotificationsAvailable() const;
      void Dismiss(Notification::Id id);

      static constexpr size_t MaximumMessageSize() {
        return MessageSize;
      };
      bool IsEmpty() const {
        return size_ == 0;
      }
      size_t NbNotifications() const;

    private:
      static constexpr uint8_t TotalNbNotifications = 5;
      std::array<Notification, TotalNbNotifications> notifications;
      size_t begin_idx = TotalNbNotifications - 1; // index of the newest notification
      size_t size_ = 0;                            // number of valid notifications in buffer

      std::atomic<bool> newNotification {false};
    };
  }
}
