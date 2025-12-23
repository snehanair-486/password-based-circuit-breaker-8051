# password-based-circuit-breaker
The password based circuit breaker is a security system designed to control the supply of electricity using a digital password. It works with the 8051 microcontroller, a keypad, and a LCD display. The keypad lets the user enter the password, which if correct displays a message and activates the mechanism to switch ON the electrical load. 

## Hardware Specifications

### Microcontroller
- 8051 Microcontroller (AT89S52 Development Board)
- Input Voltage: 9V – 15V DC
- Onboard USBASP for loading HEX file
- Onboard USB-to-Serial (CH340) interface
- Operating Frequency: 11.06 MHz

### 4x4 Matrix Keypad (16 Keys)
- Rows connected to Port P1.0 – P1.3
- Columns connected to Port P1.4 – P1.7

### 16x2 LCD Display
- Data Lines (D0 – D7): Connected to Port P2.0 – P2.7
- RS (Register Select): P3.0
- E (Enable): P3.1
- RW (Read/Write): Connected to Ground (Write-only mode)
- V0: Connected to 10k potentiometer for contrast adjustment

### Motor Driver IC (L293D)
- IN1 and IN2 connected to P3.2 and P3.3 respectively
- OUT1 and OUT2 connected to DC motor terminals
- VSS connected to Ground
- VDD connected to +5V supply

### Motor
- DC Motor (3V – 6V)

### Power Supply
- Regulated 5V Power Supply

### Other Components
- Jumper Wires
- Breadboard
- 10k Potentiometer
- Reset Switch

---

## Software Specifications
- **Keil uVision**: Program development, compilation, and HEX file generation
- **ProgISP**: Flashing the HEX file into the AT89S52 microcontroller

---

## Working Model – Sequence of Operation

### 1. Power ON
When the system is powered ON, the LCD displays **“Password”**, prompting the user to enter the password.

### 2. Password Entry
The password is entered using the 4x4 keypad. Each key pressed is displayed on the LCD.

### 3. Password Verification
- If the entered password matches the predefined password stored in the program, the LCD displays **“Correct”**.
- If the password does not match, the LCD displays **“Incorrect”**.

### 4. Circuit Control
- When the password is correct, the microcontroller sends a control signal to the L293D motor driver, thereby turning the motor ON.
- When the password is incorrect, the motor remains in the OFF state and no power is supplied.

### 5. Reset
The reset button can be pressed to restart the system and allow a new password entry operation.
