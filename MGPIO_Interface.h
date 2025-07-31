#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

// ------------------------
// Port Definitions
// ------------------------
#define PORTA    0
#define PORTB    1
#define PORTC    2

// ------------------------
// Pin Definitions (0�15)
// ------------------------
#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15

// ------------------------
// Mode Definitions
// ------------------------
#define INPUT                0
#define OUTPUT               1  // Push Pull
#define AF                   2  // Alternate Function
#define ANALOG               3

// ------------------------
// Output Type Definitions
// ------------------------
#define PUSH_PULL            0
#define OPEN_DRAIN           1

// ------------------------
// Pull-up / Pull-down
// ------------------------
#define NO_PULL              0
#define PULL_UP              1
#define PULL_DOWN            2

// ------------------------
// Output Speed
// ------------------------
#define LOW_SPEED            0
#define MEDIUM_SPEED         1
#define HIGH_SPEED           2
#define VERY_HIGH_SPEED      3

// ------------------------
// Pin Values
// ------------------------
#define LOW              0
#define HIGH             1

// ------------------------
// Alternate_Type
#define AF0    0
#define AF1    1
#define AF2    2
#define AF3    3
#define AF4    4
#define AF5    5
#define AF6    6
#define AF7    7
#define AF8    8
#define AF9    9
#define AF10   10
#define AF11   11
#define AF12   12
#define AF13   13
#define AF14   14
#define AF15   15

// ------------------------

void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type);
void MGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed);
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void MGPIO_voidSetPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Pull);
u8   MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_voidConfigAlernateFunc(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Alrtrnate);

#endif /* MGPIO_INTERFACE_H_ */
