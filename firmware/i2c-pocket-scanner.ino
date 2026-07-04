#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32 
#define OLED_RESET    -1 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int total_devices = 0;
uint8_t last_found_address = 0;
unsigned long last_scan_time = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin(); 
    
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println(F("OLED allocation failed - checking hardware connection..."));
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("I2C Scanner Ready");
    display.display();
    
    delay(2500);
}

void loop() {
    if (millis() - last_scan_time > 5000) {
        last_scan_time = millis();
        
        Serial.println("\n Scanning for device...");
        total_devices = 0;
        
        for (uint8_t address = 1; address < 127; address++) {
            if (address == 0x3C) continue; 
            
            Wire.beginTransmission(address);
            uint8_t error = Wire.endTransmission();
            
            if (error == 0) {
                Serial.print("Found device at: 0x");
                if (address < 16) Serial.print("0");
                Serial.println(address, HEX);
                
                total_devices++;
                last_found_address = address;
            }
        }

        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("  I2C BUS STATUS");
        display.println("---------------------");
        
        if (total_devices == 0) {
            display.println("Devices Found: 0");
        } else {
            display.print("Devices Found: ");
            display.println(total_devices);
            display.print("Last Addr: 0x");
            if (last_found_address < 16) display.print("0");
            display.println(last_found_address, HEX);
        }
        
        display.display(); 
    }
}