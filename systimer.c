/**
 * @file systimer.c
 * @author ztnel (christian.sargusingh@gbatteries.com)
 * @brief Demo of BCM2711 system timer register access
 * @version 0.1
 * @date 2022-04-13
 * 
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#include "systimer.h"


volatile syst_reg_t *timer_reg;

void *map_peripheral(off_t addr, size_t size) {
  // Can only map virtual to physical address space
  int mem_fd;
  // open memory file descriptor for access to DMA
  if ((mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
    perror("Failed to open /dev/mem");
    exit(-1);
  }
  uint32_t *result = (uint32_t *)mmap(
    NULL,
    size,
    PROT_READ | PROT_WRITE,
    MAP_SHARED,
    mem_fd,
    addr
  );
  close(mem_fd);
  if (result == MAP_FAILED) {
    perror("mmap error");
    exit(-1);
  }
  return result;
}

int main(void) {
  // map system clock base pointer peripheral
  uint8_t *syst_base_ptr = map_peripheral(SYST_BASE, PAGE_SIZE);
  // copy data from system clock pointer to buffer
  timer_reg = (syst_reg_t *)syst_base_ptr;
  // read from system timer registers
  for (;;) {
    printf("SYST: %08X %08X\n",
      timer_reg->chi, timer_reg->clo);
    sleep(1);
  }

}