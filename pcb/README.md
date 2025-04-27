# Automatic Vacuum Cleaner Robot Garage  

## Version 1 (Smart Control)

### Operation Flow:
1. **Activation**: 
   - The board powers on when the `POWER_SW` limit switch opens
   - Opens the box for the robot vacuum

2. **Cleaning Cycle**:
   - Robot starts cleaning
   - The board establishes connection with the server and subscribes to vacuum robot updates
   - After a predefined time, the box closes automatically

3. **Completion**:
   - When cleaning finishes, the robot sends a completion notification
   - The box opens and waits for the robot's return

4. **Return Home**:
   - When the robot arrives at the base:
     - After a short delay (using pressure sensor data)
     - The board closes the door

## Version 2 (Simplified Control)

### Operation Flow:
1. **Power Management**:
   - `POWER_SW` is used for physical power toggling:
     - Opening the door powers the board
     - Closing the door cuts power

2. **Cleaning Cycle**:
   - Robot starts cleaning
   - Door opens and remains open until robot returns

3. **Completion**:
   - When robot returns to base:
     - Pressure sensor detects presence
     - Board closes the door
     - Power is physically cut by the `POWER_SW` limit switch

## Key Differences

| Feature          | Version 1                     | Version 2                     |
|------------------|-------------------------------|-------------------------------|
| Power Control    | Logical                       | Physical via POWER_SW         |
| Door Operation   | Timed close during cleaning   | Stays open whole cleaning     |
| Server Connection| Maintains connection          | No server connection          |
| Power Off        | Software controlled           | Physical switch disconnection |