//
//
// Pins definitions for Atmega644/1284P
// Original file from Maniacbug's Mighty-1284 core
// Modded and fixed by Leonardo Miliani
//
//

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>


//                         ATMEL ATMEGA644PA/1284PA
//
//                                +---\/---+
//            PCINT8/(D4 )  PB0 40|        |39  GND
//            PCINT9/(D5 )  PB1 41|        |38  VCC
//      PCINT10/INT2 (D6 )  PB2 42|        |37  PA0 (A0 / D16)/PCINT0
//      PCINT11/OC0A (D7 )  PB3 43|~       |36  PA1 (A1 / D17)/PCINT1
//   PCINT12/0C0B/SS (D10 ) PB4 44|~       |35  PA2 (A2 / D18)/PCINT2
//      PCINT13/MOSI (D11 ) PB5  1|        |34  PA3 (A3 / D19)/PCINT3
// PCINT14/OC3A/MISO (D12 ) PB6  2|~*      |33  PA4 (A4 / D20)/PCINT4
//  PCINT15/OC3B/SCK (D13 ) PB7  3|~*      |32  PA5 (A5 / D21)/PCINT5
//                          RST  4|        |31  PA6 (A6 / D27)/PCINT6
//                          VCC  5|        |30  PA7 (A7 / D26)/PCINT7   
//                          GND  6|        |29  AREF
//                        XTAL2  7|        |28  GND
//                        XTAL1  8|        |27  AVCC
//       PCINT24/RX0 (D0 )  PD0  9|        |26  PC7 (D8) TOSC2/PCINT23
//       PCINT25/TX0 (D1 )  PD1 10|        |25  PC6 (D9) TOSC1/PCINT22
//  PCINT26/INT0/RX1 (D2)   PD2 11|        |24  PC5 (D25) TDI/PCINT21
//  PCINT27/INT1/TX1 (D3)   PD3 12|        |23  PC4 (D24) TDO/PCINT20
//      PCINT28/OC1B (D20)  PD4 13|~       |22  PC3 (D23) TMS/PCINT19
//      PCINT29/OC1A (D21)  PD5 14|~       |21  PC2 (D22) TCK/PCINT18
//      PCINT30/OC2B (D22)  PD6 15|~       |20  PC1 (D15) SDA/PCINT17  
//      PCINT31/OC2A (D23)  PD7 16|~       |19  PC0 (D14) SCL/PCINT16 
//                          VCC 17|        |18  GND  
//                                +--------+
//
// *: OC3A/OC3B (and corresponding PWMs) are only present on Atmega1284/1284P


/*
   PCINT15-8: D7-0    : bit 1
   PCINT31-24: D15-8  : bit 3
   PCINT23-16: D23-16 : bit 2
   PCINT7-0: D31-24   : bit 0
*/

#define NUM_DIGITAL_PINS            31
#define NUM_ANALOG_INPUTS           8
#define EXTERNAL_NUM_INTERRUPTS     3
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (NUM_ANALOG_INPUTS + 23) : -1)
#define analogPinToChannel(p)       ((p) >= 16 && (p) <= 21 ? (NUM_DIGITAL_PINS -(NUM_DIGITAL_PINS - p)) : -1)
#define digitalPinToInterrupt(p)    ((p) == 6 ? 2 : ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT)))


#if defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644PA__)
#define digitalPinHasPWM(p)         ((p) == 7 || (p) == 10 || (p) == 12 || (p) == 13 || (p) == 28 || (p) == 29 || (p) == 30 || (p) == 31)
#else
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 4 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15)
#endif

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 15;
static const uint8_t SCL = 14;

static const uint8_t A0 = 16;
static const uint8_t A1 = 17;
static const uint8_t A2 = 18;
static const uint8_t A3 = 19;
static const uint8_t A4 = 20;
static const uint8_t A5 = 21;
static const uint8_t A6 = 27;
static const uint8_t A7 = 26;

// Led and Button builtin
#define LED_BUILTIN     13
#define RGB_BUILTIN_R   28
#define RGB_BUILTIN_G   30
#define RGB_BUILTIN_B   29
#define BTN_BUILTIN     31

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))
//#define digitalPinToPCICRbit(p) (((p) <= 7) ? 1 : (((p) <= 15) ? 3 : (((p) <= 23) ? 2 : 0)))
#define digitalPinToPCICRbit(p) ( \
    ((p)== 0) ? 3 : \
    ((p)== 1) ? 3 : \
    ((p)== 2) ? 3 : \
    ((p)== 3) ? 3 : \
    ((p)== 4) ? 1 : \
    ((p)== 5) ? 1 : \
    ((p)== 6) ? 1 : \
    ((p)== 7) ? 1 : \
    ((p)== 8) ? 2 : \
    ((p)== 9) ? 2 : \
    ((p)==10) ? 1 : \
    ((p)==11) ? 1 : \
    ((p)==12) ? 1 : \
    ((p)==13) ? 1 : \
    ((p)==14) ? 2 : \
    ((p)==15) ? 2 : \
    ((p)==16) ? 0 : \
    ((p)==17) ? 0 : \
    ((p)==18) ? 0 : \
    ((p)==19) ? 0 : \
    ((p)==20) ? 0 : \
    ((p)==21) ? 0 : \
    ((p)==22) ? 2 : \
    ((p)==23) ? 2 : \
    ((p)==24) ? 2 : \
    ((p)==25) ? 2 : \
    ((p)==26) ? 0 : \
    ((p)==27) ? 0 : \
    ((p)==28) ? 3 : \
    ((p)==29) ? 3 : \
    ((p)==30) ? 3 : \
    ((p)==31) ? 3 : \
    0 \
)
//#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSK(p) ( \
    ((p)== 0) ? (&PCMSK3) : \
    ((p)== 1) ? (&PCMSK3) : \
    ((p)== 2) ? (&PCMSK3) : \
    ((p)== 3) ? (&PCMSK3) : \
    ((p)== 4) ? (&PCMSK1) : \
    ((p)== 5) ? (&PCMSK1) : \
    ((p)== 6) ? (&PCMSK1) : \
    ((p)== 7) ? (&PCMSK1) : \
    ((p)== 8) ? (&PCMSK2) : \
    ((p)== 9) ? (&PCMSK2) : \
    ((p)==10) ? (&PCMSK1) : \
    ((p)==11) ? (&PCMSK1) : \
    ((p)==12) ? (&PCMSK1) : \
    ((p)==13) ? (&PCMSK1) : \
    ((p)==14) ? (&PCMSK2) : \
    ((p)==15) ? (&PCMSK2) : \
    ((p)==16) ? (&PCMSK0) : \
    ((p)==17) ? (&PCMSK0) : \
    ((p)==18) ? (&PCMSK0) : \
    ((p)==19) ? (&PCMSK0) : \
    ((p)==20) ? (&PCMSK0) : \
    ((p)==21) ? (&PCMSK0) : \
    ((p)==22) ? (&PCMSK2) : \
    ((p)==23) ? (&PCMSK2) : \
    ((p)==24) ? (&PCMSK2) : \
    ((p)==25) ? (&PCMSK2) : \
    ((p)==26) ? (&PCMSK0) : \
    ((p)==27) ? (&PCMSK0) : \
    ((p)==28) ? (&PCMSK3) : \
    ((p)==29) ? (&PCMSK3) : \
    ((p)==30) ? (&PCMSK3) : \
    ((p)==31) ? (&PCMSK3) : \
    ((uint8_t *)0) \
)
//#define digitalPinToPCMSKbit(p) ((p) % 8)
#define digitalPinToPCMSKbit(p) ( \
    ((p)== 0) ? 0 : \
    ((p)== 1) ? 1 : \
    ((p)== 2) ? 2 : \
    ((p)== 3) ? 3 : \
    ((p)== 4) ? 0 : \
    ((p)== 5) ? 1 : \
    ((p)== 6) ? 2 : \
    ((p)== 7) ? 3 : \
    ((p)== 8) ? 7 : \
    ((p)== 9) ? 6 : \
    ((p)==10) ? 4 : \
    ((p)==11) ? 5 : \
    ((p)==12) ? 6 : \
    ((p)==13) ? 7 : \
    ((p)==14) ? 0 : \
    ((p)==15) ? 1 : \
    ((p)==16) ? 0 : \
    ((p)==17) ? 1 : \
    ((p)==18) ? 2 : \
    ((p)==19) ? 3 : \
    ((p)==20) ? 4 : \
    ((p)==21) ? 5 : \
    ((p)==22) ? 2 : \
    ((p)==23) ? 3 : \
    ((p)==24) ? 4 : \
    ((p)==25) ? 5 : \
    ((p)==26) ? 7 : \
    ((p)==27) ? 6 : \
    ((p)==28) ? 4 : \
    ((p)==29) ? 5 : \
    ((p)==30) ? 6 : \
    ((p)==31) ? 7 : \
    0 \
)
#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
  24, // D0 PD0
  25, // D1 PD1
  26, // D2 PD2
  27, // D3 PD3
  8,  // D4 PB0
  9,  // D5 PB1
  10, // D6 PB2
  11, // D7 PB3
  23, // D8 PC7
  22, // D9 PC6
  12, // D10 PB4
  13, // D11 PB5
  14, // D12 PB6
  15, // D13 PB7
  16, // D14 PC0
  17, // D15 PC1
  0, // D16 PA0
  1, // D17 PA1
  2, // D18 PA2
  3, // D19 PA3
  4,  // D20 PA4
  5,  // D21 PA5
  18, // D22 PC2
  19, // D23 PC3
  20, // D24 PC4
  21, // D25 PC5
  7, // D26 PA7
  6, // D27 PA6
  28, // D28 PD4
  29, // D29 PD5
  30, // D30 PD6
  31, // D31 PD7
};

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
  PD, /* 0 */
  PD,
  PD,
  PD,
  PB,
  PB,
  PB,
  PB,
  PC, /* 8 */
  PC,
  PB,
  PB,
  PB,
  PB,
  PC,
  PC,
  PA, /* 16 */
  PA,
  PA,
  PA,
  PA,
  PA,
  PC,
  PC,
  PC, /* 24 */
  PC,
  PA,
  PA,
  PD,
  PD,
  PD,
  PD  /* 31 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
  _BV(0), /* 0, */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(0),
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(7), /* 8,*/
  _BV(6),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0),
  _BV(1),
  _BV(0), /* 16, */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(2),
  _BV(3),
  _BV(4), /* 24, */
  _BV(5),
  _BV(7),
  _BV(6),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER,   /* 0  - PD0 */
  NOT_ON_TIMER,   /* 1  - PD1 */
  NOT_ON_TIMER,   /* 2  - PD2 */
  NOT_ON_TIMER, /* 3  - PD3 */
  NOT_ON_TIMER, /* 4  - PB0 */
  NOT_ON_TIMER,   /* 5  - PB1 */
  NOT_ON_TIMER,   /* 6  - PB2 */
  TIMER0A,    /* 7  - PB3 */

  NOT_ON_TIMER,   /* 8  - PC7 */
  NOT_ON_TIMER,   /* 9  - PC6 */
  TIMER0B,    /* 10 - PB4 */
  NOT_ON_TIMER,   /* 11 - PB5 */
#if defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644PA__)
  TIMER3A,    /* 12  - PB6 */
  TIMER3B,    /* 13  - PB7 */
#else
  NOT_ON_TIMER,   /* 12  - PB6 */
  NOT_ON_TIMER,   /* 13  - PB7 */
#endif
  NOT_ON_TIMER,   /* 14 - PC0 */
  NOT_ON_TIMER,   /* 15 - PC1 */
  NOT_ON_TIMER,   /* 16 - PA0 */
  NOT_ON_TIMER,   /* 17 - PA1 */
  NOT_ON_TIMER,   /* 18 - PA2 */
  NOT_ON_TIMER,   /* 19 - PA3 */
  NOT_ON_TIMER,   /* 20 - PA4 */
  NOT_ON_TIMER,   /* 21 - PA5 */
  NOT_ON_TIMER,   /* 22 - PC2 */
  NOT_ON_TIMER,   /* 23 - PC3 */
  NOT_ON_TIMER,   /* 24 - PC4 */
  NOT_ON_TIMER,   /* 25 - PC5 */
  NOT_ON_TIMER,   /* 36 - PA7 */
  NOT_ON_TIMER,    /* 27 - PA6 */
  TIMER1B,      /* 28 - PD4 */
  TIMER1A,      /* 29 - PD5 */
  TIMER2B,      /* 30 - PD6 */
  TIMER2A,      /* 31 - PD7 */
};

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
#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1


#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
