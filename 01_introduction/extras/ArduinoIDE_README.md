By default Arduino works with Aruino's own boards. But it is capable of working with many more. But we need to configure the IDE for the specific boards.
1. Add external board managers:
	File > Preferences > Settings > Additional Board Manager URLs
	insert following three for the families of chips of Esp32, Esp8266 and Pi Pico:
		https://dl.espressif.com/dl/package_esp32_index.json
		http://arduino.esp8266.com/stable/package_esp8266com_index.json
		https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
2. Add following additional board collections:
	- esp32
	- esp8266
	- Raspberry Pi Pico/RP2040
3. Select a board from the list
	In examples we used:
	- AI Thinker ESP32-CAM
	- NodeMCU 1.0 (ESP-12E Module)
	- Raspberry Pi Pico
	These depend on your board manufacturer and might have different extra settings it uses for compiling and or flashing.
4. Select the port at which the board is in
5. Upload

If board doesn't appear in Port list, you might be missing drivers (consult manufacturer for details) or special tools for compiling (on Wondows, try installing set of tools from here https://github.com/ndabas/pico-setup-windows/).