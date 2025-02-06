# Automatic Vacuum Cleaner Robot Garage  

## Overview  
This project was inspired by the challenge of limited space in an apartment. Dedicating a full square meter of floor space for a robot vacuum’s parking spot seemed inefficient. Instead, the idea was to create a niche under the kitchen cabinets where the robot could park and charge.  

## Features  
- Designed to fit under kitchen cabinets  
- Automatic door mechanism to enclose the robot when parked  
- Provides a dedicated charging space  

## Disclaimer  
⚠ **This is an early-stage, untested prototype.** Any modifications, builds, or implementations based on this project are done **at your own risk**.  

## Installation & Assembly  
1. **Build the garage frame**  
   - Construct a housing that fits under your kitchen cabinets and accommodates your specific robot vacuum.  
   - Dimensions are **not provided**, as different robot models require different clearance and space. Ensure there is enough room for smooth docking and undocking.  

2. **Add the control board**  
   - You will need a **control board** (e.g., **NodeMCU**) to handle the opening and closing of the garage door.  
   - The board will control the door mechanism based on signals from the robot (e.g., when it enters the garage).  

3. **Print and install the door mechanism**  
   - Download and 3D print the **gear assembly** responsible for opening and closing the garage door.  
   - The mechanism should be mounted on the **front left wall** of the garage.  
   - ![Gear Assembly](https://github.com/sakonyshev/robot-garage/blob/master/image/gear_assembly2.png)  

4. **Install the door panel**  
   - Use a **standard chipboard (DSP) panel** as the door.  
   - Cut it to fit the gap between the **floor and kitchen cabinets**.  
   - Ensure the panel moves freely with the installed gear mechanism.  

5. **Set up the charging station**  
   - Place the charging dock inside the garage.  
   - Ensure the robot can autonomously navigate into the garage and connect to the charger.  

## Components  
- NodeMCU  
- NEMA17 stepper motor
- DRV8825 stepper motor driver
- Optocoupler EL817
- Resistors 10kOm and 260Om
- Linear Voltage Regulator L7805CV
- MOSFET Transistor IRLZ34N
- Capacitors 470mF, 0.1mF, 0.33mF
- Connectors KF301-2P
- Breakable Pin Headers
- Dip 3p toggle switch
- 12V power supply

## Future Improvements  
- Enhanced automation for door control  
- Sensor integration with home assistants
