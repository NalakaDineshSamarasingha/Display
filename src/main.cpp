// main.cpp

#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include "ui.h" // Ensure this path is correct relative to your project structure
#include <src/extra/libs/qrcode/lv_qrcode.h>
#include <WiFi.h>
#include <HTTPClient.h>

void setup() {
#ifdef ARDUINO_USB_CDC_ON_BOOT
    delay(5000);
#endif
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    log_i("Board: %s", BOARD_NAME);
    log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
    log_i("Free heap: %d bytes", ESP.getFreeHeap());
    log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
    log_i("SDK version: %s", ESP.getSdkVersion());

    smartdisplay_init();
    ui_init();  // Initialize the UI
}

void loop() {
    lv_timer_handler();
    delay(5);  // Small delay to let the CPU rest a bit
}
