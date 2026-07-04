# i2c Pocket Scanner

The i2c_pocket_scanner is a lightweight, hardware-level diagnostic utility designed specifically for the RP2040 architecture (powered by QMK Firmware and ChibiOS). Built out of a necessity for seamless embedded development, this tool turns your custom microcontroller setup into an instant, on-the-go I2C bus analyzer.

Instead of relying on clunky external logic analyzers or uploading massive Arduino sketches just to test continuity, this custom QMK firmware bypasses the traditional keyboard matrix entirely. Upon boot, it utilizes a high-level wrapper around the RP2040’s native hardware I2C master driver to rapidly ping all 127 possible addresses on the bus. By listening for hardware acknowledgments and streaming live success logs directly back to the host PC via a designated USB HID console channel, it provides real-time, visual confirmation of exactly which peripherals—like OLED displays, sensors, or encoders—are alive and responsive.

I designed this pocket scanner to streamline the prototyping workflow for custom split keyboards, macropads, and avionics replicas. Before committing to complex layout matrices and deep feature code, the i2c_pocket_scanner serves as the ultimate first-line diagnostic defense—ensuring your hardware routing, pull-up resistors, and I2C lines are electronically flawless from the very first plug-in.

## Features:
* **Zero-Matrix Architecture**: Configured to run flawlessly without requiring physical mechanical switches, diodes, or complex key matrices.
* **RP2040 Optimization**: Leverages the native hardware I2C master driver of the RP2040 chip for rapid bus polling and maximum stability.
* **Live USB Debugging**: Streams real-time diagnostic logs directly to the QMK HID Console using an optimized boot delay to catch initial device handshakes.
* **Full 7-Bit Scanning**: Sequentially pings all 127 standard I2C addresses, instantly flagging any active peripherals like OLED screens, sensors, or split-hand components.

---

## CAD Model & Case Assembly
Everything fits together precisely using a layered enclosure design. The case includes structural mounting points for the PCB, plates, and components to ensure zero deck-flex during heavy use.

### Case Assembly & Fitment
*An isometric 3D CAD visualization highlighting how the PCB, Display, and structural enclosure layers interface together seamlessly.*

<img width="3840" height="3072" alt="i2c-Pocket-Scanner_2026-Jul-04_01-07-56AM-000_CustomizedView21038394676" src="https://github.com/user-attachments/assets/5f2415ad-23ea-4c49-a79a-22da372358aa" />

<img width="3840" height="3072" alt="i2c-Pocket-Scanner_2026-Jul-04_01-12-03AM-000_CustomizedView26051647961" src="https://github.com/user-attachments/assets/89c6c1d9-1fca-478c-95c6-da3384f4a2bb" />

*Designed completely from scratch in Autodesk Fusion 360.*

---

## PCB Design
The underlying electronics were engineered in KiCad. The board features clean routing paths optimized for the RP2040 pin configurations and an external header to wire external components

### Schematic Design
*The underlying circuit schematic mapping the switch routing.*

<img width="1697" height="1052" alt="Screenshot 2026-07-03 181236" src="https://github.com/user-attachments/assets/af66402e-321c-4ffa-a013-8ca5acaf64ad" />

### PCB Layout Architecture
*The routed printed circuit board design detailing trace paths, footprints, and physical alignment.*

<img width="925" height="1440" alt="Screenshot 2026-07-03 181345" src="https://github.com/user-attachments/assets/d0aa0ac6-7b51-43dd-bf94-443aeb80a51d" />

---

## How to Flash
1. Disconnect the USB cable from the Flight Pad.
2. Press and hold the physical **BOOT** button on the RP2040 controller board.
3. Reconnect the USB cable while holding the button, then release it.
4. A virtual drive named will mount to your operating system.
5. Drag and drop the `i2c_pocket_scanner_default.uf2` binary file directly onto the root of the drive.
6. The device will automatically flash, reboot, and initialize as an operational HID keyboard device.

---

## AI Attribution Note
**Please Note that AI was utilized to format this .README file, aswell as some basic project planning and debugging of the Keyboard.JSON, and Keymap.C files in VS.Code**
