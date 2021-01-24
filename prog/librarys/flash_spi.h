#include "main.h"
#include "cmsis_os.h"

//******************
//
// DESCRIPTION:
//  структура для хранения описания пинов для флешки
//
// CREATED: 24.01.2021, by Ierixon-HP
//
// FILE: flash_spi.h
//
typedef struct 
{
  GPIO_TypeDef* GPIO_Port;
  uint16_t GPIO_Pin;  
}pins_spi_t;
//******************
// CLASS: flash
//
// DESCRIPTION:
//  spi flash driver
//
// CREATED: 20.09.2020, by Ierixon-HP
//
// FILE: flash_spi.cpp
//
class flash
{
public:
 flash();
 ~flash();
 bool Init(SPI_HandleTypeDef *hspi, uint32_t startAddr,  pins_spi_t ChipSelect, pins_spi_t WriteProtect, pins_spi_t Hold);
 void Flash_Read(settings_t *data);
 void Flash_Write(settings_t data);
 private:
 uint32_t StartAddres;
 SPI_HandleTypeDef *hspi;
 pins_spi_t ChipSelect;
 pins_spi_t WriteProtect; 
 pins_spi_t Hold;
 HAL_StatusTypeDef lastStatusSPI;
};