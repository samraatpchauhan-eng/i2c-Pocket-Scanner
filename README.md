# i2c Pocket Scanner
i2c Pocket scanner is a portable hardware debugging device, for scanning i2c modules' hexadecimal code and displaying it to the user. I designed it mainly for use if you use public makerspaces alot and don't have the space for a full hardware debugging kit, or need to verify if a part works on the go. 
## Features:
* **Miniature Layout:**  The i2c Pocket Scanner has a very small footprint, making it easy to carry it in your bag, or put it in your pocket!
* **OLED display:** There is a 0.91 inch oled screen to display the hexadecimal code received from the component being tested, and to verify the part actually works.
* **Simple Assembly:** Assembling the i2c Pocket Scanner is simple, and easy, as there is only the Seeed Xiao rp2040 and the OLED display to connect to the PCB.

---

## CAD Model
Due to the small size of the case, everything fits together nice and tight, without an risk of damage. There is also engravings on the case, describing what each header hole is so connecting external components becomes easy

### Case Assembly & Fitment
*A 3D CAD visualization highlighting how all the parts fit together seamlessly.*

<img width="3840" height="3072" alt="i2c-Pocket-Scanner_2026-Jul-04_01-07-56AM-000_CustomizedView21038394676" src="https://github.com/user-attachments/assets/7c35c221-cf3f-46f4-9fcf-ba8bb091ad6f" />

<img width="3840" height="3072" alt="i2c-Pocket-Scanner_2026-Jul-04_01-12-03AM-000_CustomizedView26051647961" src="https://github.com/user-attachments/assets/fe986f80-6d5a-481b-a4a1-3fda0247d0c1" />


---

## PCB Design
The underlying electronics were engineered in KiCad. The board features clean routing paths optimized for the RP2040 pin configurations and a direct connection layout to handle both the OLED display and the open header for connecting other components.

### Schematic Design
*The circuit schematic mapping the display routing, and header connections to the microcontroller.*

<img width="1697" height="1052" alt="Screenshot 2026-07-03 181236" src="https://github.com/user-attachments/assets/76d7e545-11f5-467d-9cda-c38fc7b53813" />

### PCB Layout Architecture
*The routed printed circuit board design detailing trace paths, footprints, and physical alignment.*

<img width="925" height="1440" alt="Screenshot 2026-07-03 181345" src="https://github.com/user-attachments/assets/b32a86db-fdc8-426d-b73f-c0b72359337e" />

---

## How to Flash
1. Press and hold the physical **BOOT** button on the RP2040 controller board.
2. Connect the USB cable while holding the button, then release it.
3. A virtual drive named will mount to your operating system.
4. Drag and drop the `i2c-pocket-scanner.ino.uf2` binary file directly onto the root of the drive.
5. The device will automatically flash, reboot, and initialize as an operational device.

---

## AI Attribution Note
**Please Note that AI was utilized for some basic project planning and debugging of the firmware in VS.Code**
