//
// Created by WuGaoyuan on 2023/3/11.
//

#include <stdio.h>
#include "sram.h"
#include "main.h"
#include "fsmc.h"
uint8_t DMA_Direction=1;
uint8_t DMA_Busy=1;
uint32_t rxBuffer[5];
uint32_t txBuffer[5]={4,5,6,7,8};
void SRAM_WriteByFunc()
{
    //写入字符串
    uint32_t *pAddr = (uint32_t *)(SRAM_ADDR_BEGIN);
    uint8_t  strIn[] = "Moment in UPC";
    uint16_t dataLen=sizeof(strIn);

    if(HAL_SRAM_Write_8b(&hsram3,pAddr,strIn,dataLen)==HAL_OK)
    {
        printf("write string successfully,%s\r\n",strIn);
    }
    //写入一个随机数
    uint32_t  num=0;
    pAddr= (uint32_t*)(SRAM_ADDR_BEGIN+256);
    if(HAL_SRAM_Write_32b(&hsram3,pAddr,&num,1) == HAL_OK)
    {
        printf("write number successfully,%lu\r\n",num);
    }

}
void SRAM_ReadByFunc()
{
    uint32_t *pAddr = (uint32_t *)(SRAM_ADDR_BEGIN);
    uint8_t strOut[30];
    uint16_t dataLen = 30;
    if(HAL_SRAM_Read_8b(&hsram3,pAddr,strOut,dataLen) == HAL_OK)
    {
        printf("Read string at 0x6c00 0000\r\n");
        printf("%s\r\n",strOut);
    }

    uint32_t num=0;
    pAddr= (uint32_t*)(SRAM_ADDR_BEGIN+256);
    if(HAL_SRAM_Read_32b(&hsram3,pAddr,&num,1) == HAL_OK)
    {
        printf("Read 32b number at 0x6c00 0100\r\n");
        printf("%lu\r\n",num);
    }
}
void SRAM_WriteDMA()
{
    uint32_t *pAddr = (uint32_t *)(SRAM_ADDR_BEGIN);
    uint8_t  strIn[] = "Moment in aaa";
    uint32_t arr[] = {1,2,3,4,5};
    uint16_t dataLen=sizeof(strIn);

    if(HAL_SRAM_Write_DMA(&hsram3,pAddr,arr,5)==HAL_OK)
    {
        printf("write string successfully,%s\r\n",strIn);
    }
}
void SRAM_ReadDMA()
{
    uint32_t *pAddr = (uint32_t *)(SRAM_ADDR_BEGIN);
    uint8_t strOut[30];
    uint16_t dataLen = 30;
    uint32_t arr[5];
    if(HAL_SRAM_Read_DMA(&hsram3,pAddr,arr,5) == HAL_OK)
    {
        printf("Read string at 0x6c00 0000\r\n");
//        printf("%s\r\n",arr);
        for(int i=0;i<5;i++){
            printf("%d \r\n",arr[i]);
        }
    }

}
void HAL_SRAM_DMA_XferCpltCallback(DMA_HandleTypeDef *hdma)
{
    if(DMA_Direction==DMA_WRITE)
    {
        printf("written by DMA complete.\r\n");
    }
    else
    {
        printf("read by DMA complete.\r\n");
        for(uint8_t i=0;i<5;i++)
        {
            printf("%lu \r",rxBuffer[i]);
        }
        printf("\n");
    }
    DMA_Busy=DMA_IDEL;
}
void SRAM_Test()
{
    for(uint8_t i=0;i<5;i++)
    {
        printf("%lu \r",txBuffer[i]);
    }
    printf("\n");
}
void SRAM_WriteByPointer()
{

}
void SRAM_ReadByPointer()
{

}
