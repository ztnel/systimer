/**
 * @file systimer.h
 * @author ztnel (christian.sargusingh@gbatteries.com)
 * @brief 
 * @version 0.1
 * @date 2022-04
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#ifndef SYSTIMER_H_
#define SYSTIMER_H_

#include <stdint.h>

/**
 * @brief Low level access to peripherals on the BCM2711 use the ARM view of the
 * full 35-bit Address Map in "Low Peripheral Mode" which maps the main
 * peripherals address space 0x7C00_0000 -> 0x4_7000_0000 -> 0xFE00_0000
 * 
 * See section 1.2 of the datasheet for more details:
 * https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf
 */
#define PAGE_SIZE             4096
#define BCM2711_PERI_BASE     0xFE000000

#define SYST_BASE             (BCM2711_PERI_BASE + 0x00003000)
#define SYST_LEN              0x1C
#define SYST_CLO              0x04
#define SYST_CHI              0x08

/**
 * @brief For implementation details of the rpi system timer:
 * https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf
 */
typedef struct syst_reg_t {
  uint32_t cs;    // system timer control register
  uint32_t clo;   // system timer counter lower 32 bits
  uint32_t chi;   // system timer counter upper 32 bits
  uint32_t stc0;  // system timer compare 0
  uint32_t stc1;  // system timer compare 1
  uint32_t stc2;  // system timer compare 2
  uint32_t stc3;  // system timer compare 3
} syst_reg_t;


#endif // SYSTIMER_H_