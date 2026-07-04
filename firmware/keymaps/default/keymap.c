#include QMK_KEYBOARD_H
#include "i2c_master.h"
#include "print.h"

// Changed to match the layout name from our JSON
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(KC_NO)
};

void keyboard_post_init_user(void) {
    debug_enable = true;
    i2c_init();
    
    uprintf("\n--- QMK Pocket I2C Scanner Ready ---\n");
    uprintf("Scanning bus for devices...\n");
    
    int devices_found = 0;
    uint8_t dummy_data = 0;
    
    for (uint8_t address = 1; address < 127; address++) {
        uint8_t target_address = (address << 1);
        i2c_status_t status = i2c_read_register(target_address, 0x00, &dummy_data, 1, 100);
        
        if (status == I2C_STATUS_SUCCESS) {
            uprintf("Success! Discovered device at address: 0x%02X\n", address);
            devices_found++;
        }
    }
    
    if (devices_found == 0) {
        uprintf("Scan complete: No external devices responded.\n\n");
    } else {
        uprintf("Scan complete. Found %d active device(s).\n\n", devices_found);
    }
}

void matrix_init_user(void) {}
void matrix_scan_user(void) {}