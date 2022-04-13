# System Timer Demo

Modified: 2022-04

Demo of Reading System Timer Registers on RPi4/CM4 (BCM2711).

## Quickstart
Build the demo for BCM2711 SoCs. This software should work with 
```bash
make
```

The program uses memory mapping to `/dev/mem` for access to the system timer registers. This requires root priveleges:
```bash
sudo ./systimer
```

The output should show the upper 32-bit register followed by the lower 32-bit register in hex:
```bash
SYST: 0000002E 175541B8
SYST: 0000002E 17648510
SYST: 0000002E 1773C7F5
SYST: 0000002E 17830AE1
SYST: 0000002E 17924DC9
...
```

## Further Reading
Check section 10 of the BCM2711 datasheet for more information on the hardware implementation: https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf