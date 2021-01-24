#include "flash_spi.h"

bool flash :: Init(SPI_HandleTypeDef *hspi, uint32_t StartAddr,  pins_spi_t ChipSelect, pins_spi_t WriteProtect, pins_spi_t Hold){
  
  flash :: WriteProtect = WriteProtect;
  flash :: ChipSelect = ChipSelect;
  flash :: Hold = Hold;
  StartAddres = StartAddr;
  
  HAL_GPIO_WritePin(WriteProtect.GPIO_Port, WriteProtect.GPIO_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(Hold.GPIO_Port, Hold.GPIO_Pin, GPIO_PIN_SET);
  return true;
}

void flash :: Flash_Read(settings_t *data){
  HAL_StatusTypeDef StatusSPI;
  uint32_t sizeData = sizeof(data);
  uint8_t *ptrData = (uint8_t*)data;
  
  StatusSPI = HAL_SPI_Receive(hspi, ptrData, sizeData, 10);
  //StatusSPI2 = StatusSPI2;
  HAL_GPIO_WritePin(SPI3_CS_GPIO_Port, SPI3_CS_Pin, GPIO_PIN_SET);
  
  lastStatusSPI = StatusSPI;
  
}

void flash :: Flash_Write(settings_t data){
  HAL_StatusTypeDef StatusSPI;
  uint32_t sizeData = sizeof(data);
  uint8_t *ptrData = (uint8_t*)&data;
  
  StatusSPI = HAL_SPI_Transmit(hspi, ptrData, sizeData, 10);
  //StatusSPI = StatusSPI;
  HAL_GPIO_WritePin(SPI3_CS_GPIO_Port, SPI3_CS_Pin, GPIO_PIN_SET);
  
  lastStatusSPI = StatusSPI;
}

flash :: flash(){
  
}

