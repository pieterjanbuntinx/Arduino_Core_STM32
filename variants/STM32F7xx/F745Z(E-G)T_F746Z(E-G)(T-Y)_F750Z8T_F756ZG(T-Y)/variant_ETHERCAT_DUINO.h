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
#pragma once

/*----------------------------------------------------------------------------
 *        STM32 pins number
 *----------------------------------------------------------------------------*/
#define PA8                     11
#define PA9                     12
#define PA15                    13
#define PB10                    16
#define PB11                    17
#define PB14                    2
#define PC6                     7
#define PC7                     8
#define PC8                     9
#define PC9                     10
#define PC10                    1
#define PC11                    0
#define PC13                    48
#define PC14                    46
#define PC15                    47
#define PD5                     14
#define PD6                     15
#define PD12                    3
#define PD13                    4
#define PD14                    5
#define PD15                    6
#define PE2                     53
#define PE3                     52
#define PE4                     51
#define PE5                     50
#define PE6                     49
#define PE7                     19
#define PE8                     18
#define PE9                     30
#define PE10                    31
#define PE11                    28
#define PE15                    29
#define PF3                     45
#define PF4                     44
#define PF10                    43
#define PF11                    36
#define PF12                    35
#define PF13                    34
#define PF14                    21
#define PF15                    20
#define PG0                     32
#define PG1                     33
#define PG2                     26
#define PG3                     27
#define PG4                     24
#define PG5                     25
#define PG6                     22
#define PG7                     23
#define PG9                     37
#define PG10                    38
#define PG11                    39
#define PG12                    40
#define PG13                    41
#define PG14                    42
#define PH0                     112
#define PH1                     113
#define PB3                     54
#define PB8                     55
#define PB9                     56
#define PE12                    57
#define PE13                    58
#define PE14                    59
#define PG15                    60
#define PF2                     61

// Alternate pins number
#define PA15_ALT1               (PA15 | ALT1)
#define PB14_ALT1               (PB14 | ALT1)
#define PB14_ALT2               (PB14 | ALT2)
#define PC6_ALT1                (PC6  | ALT1)
#define PC7_ALT1                (PC7  | ALT1)
#define PC8_ALT1                (PC8  | ALT1)
#define PC9_ALT1                (PC9  | ALT1)
#define PC10_ALT1               (PC10 | ALT1)
#define PC11_ALT1               (PC11 | ALT1)

#define NUM_DIGITAL_PINS        62
#define NUM_ANALOG_INPUTS       12

// On-board LED pin number
#ifndef LED_BUILTIN
  #define LED_BUILTIN           PB3
#endif
#define LED_1                   LED_BUILTIN
#define LED_2                   PG15

// On-board user button
#ifndef USER_BTN
  #define USER_BTN              PNUM_NOT_DEFINED
#endif

// SPI definitions
#ifndef PIN_SPI_SS
  #define PIN_SPI_SS            PE11
#endif
#ifndef PIN_SPI_SS1
  #define PIN_SPI_SS1           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS2
  #define PIN_SPI_SS2           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_SS3
  #define PIN_SPI_SS3           PNUM_NOT_DEFINED
#endif
#ifndef PIN_SPI_MOSI
  #define PIN_SPI_MOSI          PE14
#endif
#ifndef PIN_SPI_MISO
  #define PIN_SPI_MISO          PE13
#endif
#ifndef PIN_SPI_SCK
  #define PIN_SPI_SCK           PE12
#endif

// I2C definitions
#ifndef PIN_WIRE_SDA
  #define PIN_WIRE_SDA          PB9
#endif
#ifndef PIN_WIRE_SCL
  #define PIN_WIRE_SCL          PB8
#endif

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#ifndef TIMER_TONE
  #define TIMER_TONE            TIM6
#endif
#ifndef TIMER_SERVO
  #define TIMER_SERVO           TIM7
#endif

// UART Definitions
#ifndef SERIAL_UART_INSTANCE
  #define SERIAL_UART_INSTANCE  4
#endif

// Default pin used for generic 'Serial' instance
// Mandatory for Firmata
#ifndef PIN_SERIAL_RX
  #define PIN_SERIAL_RX         PC11
#endif
#ifndef PIN_SERIAL_TX
  #define PIN_SERIAL_TX         PC10
#endif

// Extra HAL modules
#if !defined(HAL_DAC_MODULE_DISABLED)
  #define HAL_DAC_MODULE_ENABLED
#endif
#if !defined(HAL_ETH_MODULE_DISABLED)
  #define HAL_ETH_MODULE_ENABLED
#endif
#if !defined(HAL_QSPI_MODULE_DISABLED)
  #define HAL_QSPI_MODULE_ENABLED
#endif
#if !defined(HAL_SD_MODULE_DISABLED)
  #define HAL_SD_MODULE_ENABLED
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #ifndef SERIAL_PORT_MONITOR
    #define SERIAL_PORT_MONITOR   Serial
  #endif
  #ifndef SERIAL_PORT_HARDWARE
    #define SERIAL_PORT_HARDWARE  Serial
  #endif
#endif
