# Piezoelectric Energy-Harvesting Floor Tile

This project is a piezoelectric floor tile designed to generate electrical energy from footsteps. When a person steps on the tile, a 3D-printed PETG flexing plate transfers and distributes the force to piezoelectric elements underneath. The generated electrical signal is rectified into DC power, conditioned through an energy-harvesting circuit, and stored in a battery.

The system also measures the harvested voltage and provides the user with real-time voltage readings. The project combines mechanical design, piezoelectric energy harvesting, power electronics, PCB design, embedded sensing, and 3D printing to explore how everyday human motion can be converted into usable electrical energy.

The tile itself is hot-swappable, meaning that the user can change the surface to whatever texture they want, whether it be a turf surface, hardwood flooring, etc. This allows for the tile to be used in a large variety of applications.



When looking at the images of the CAD, there are 3 main elements to the physical design: the hot-swappable plate, which is held in by M4 screws; the PETG flexion plate to aid the transfer of energy to the piezos; and the TPU flexible padding/ PLA sidewalls to stop overflexion of the PETG plate.

The electrical system has 4 main elements: the rectifier circuit to change AC output from the piezos to DC, the battery backup, a buck converter to USB-C ports, and the ESP-32 voltage logging.

