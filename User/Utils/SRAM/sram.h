//
// Created by WuGaoyuan on 2023/3/11.
//

#ifndef F407_SRAM_DEMO_SRAM_H
#define F407_SRAM_DEMO_SRAM_H

#define SRAM_ADDR_BEGIN     0x68000000UL
#define SRAM_ADDR_HALF      0x68080000UL
#define SRAM_ADDR_END       0x680FFFFFUL
#define DMA_WRITE           1
#define DMA_READ            0
#define DMA_BUSY            1
#define DMA_IDEL            0
void SRAM_WriteByFunc();
void SRAM_ReadByFunc();
void SRAM_WriteByPointer();
void SRAM_ReadByPointer();
void SRAM_WriteDMA();
void SRAM_ReadDMA();
void SRAM_Test();
#endif //F407_SRAM_DEMO_SRAM_H
