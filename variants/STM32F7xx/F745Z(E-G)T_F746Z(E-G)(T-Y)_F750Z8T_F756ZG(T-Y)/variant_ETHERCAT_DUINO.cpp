/*
 *******************************************************************************
 * Copyright (c) 2020-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_ETHERCAT_DUINO)
#include "pins_arduino.h"

// Digital PinName array
const PinName digitalPin[] = {
      PC11  // D0    
    , PC10  // D1    
    , PB14  // D2    
    , PD12  // D3    
    , PD13  // D4    
    , PD14  // D5    
    , PD15  // D6    
    , PC6   // D7  
    , PC7   // D8  
    , PC8   // D9  
    , PC9   // D10 
    , PA8   // D11 
    , PA9   // D12 
    , PA15  // D13   
    , PD5   // D14 
    , PD6   // D15 
    , PB10  // D16   
    , PB11  // D17   
    , PE8   // D18 
    , PE7   // D19 
    , PF15  // D20   
    , PF14  // D21   
    , PG6   // D22 
    , PG7   // D23 
    , PG4   // D24 
    , PG5   // D25 
    , PG2   // D26 
    , PG3   // D27 
    , PE11  // D28   
    , PE15  // D29   
    , PE9   // D30 
    , PE10  // D31   
    , PG0   // D32 
    , PG1   // D33 
    , PF13  // D34   
    , PF12  // D35   
    , PF11  // D36   
    , PG9   // D37 
    , PG10  // D38   
    , PG11  // D39   
    , PG12  // D40   
    , PG13  // D41   
    , PG14  // D42   
    , PF10  // D43   
    , PF4   // D44 
    , PF3   // D45 
    , PC14  // D46   
    , PC15  // D47   
    , PC13  // D48   
    , PE6   // D49 
    , PE5   // D50 
    , PE4   // D51 
    , PE3   // D52 
    , PE2   // D53 
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
      PC0   // A0 
    , PC1   // A1 
    , PC2   // A2 
    , PC3   // A3 
    , PA0   // A4 
    , PA1   // A5 
    , PA2   // A6 
    , PA3   // A7 
    , PA6   // A8 
    , PA7   // A9 
    , PC4   // A10
    , PC5   // A11
};

#ifdef __cplusplus
extern "C"
{
#endif

  /**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
  WEAK void SystemClock_Config(void)
  {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    /** Configure the main internal regulator output voltage 
  */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    /** Initializes the CPU, AHB and APB busses clocks 
  */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 4;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
    }
    /** Activate the Over-Drive mode 
  */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
    }
    /** Initializes the CPU, AHB and APB busses clocks 
  */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
    }
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_UART8 | RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_CLK48;
    PeriphClkInitStruct.Uart8ClockSelection = RCC_UART8CLKSOURCE_PCLK1;
    PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
    }
  }

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_ETHERCAT_DUINO */
