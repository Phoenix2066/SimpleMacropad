import pyautogui
import serial

# Configure the serial port
# For Windows, use 'COMx' (e.g., 'COM3')
# For Linux/macOS, use '/dev/ttyUSBx' or '/dev/ttyACMx'
ser = serial.Serial(
    port="COM3",  # Replace with your port
    baudrate=9600,  # Set to match your device (common: 9600, 115200)
    timeout=1,  # Read timeout in seconds
)

alt_held = False

try:
    while True:
        if ser.in_waiting > 0:  # Check if data is available in the buffer
            # Read a line of data and decode from bytes to string
            line = ser.readline().decode("utf-8").rstrip()
            print(f"Received: {line}")
            if line == "0_p":
                pyautogui.keyDown("alt")
            elif line == "0_r":
                pyautogui.keyUp("alt")
            elif line == "1_p":
                pyautogui.hotkey("win", ".")
            elif line == "2_p":
                pyautogui.press("tab")
            elif line == "3_p":
                pyautogui.hotkey("shift", "tab")
except KeyboardInterrupt:
    print("Stopping script...")
finally:
    ser.close()  # Always close the port when finished
