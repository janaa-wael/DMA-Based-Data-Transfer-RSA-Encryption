/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/

#include "std_types.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void MGPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOA_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			GPIOA_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOA_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//low

			GPIOB_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOB_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOB_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	case GPIOC:
		if(Copy_u8Pin <= 7 )
		{//low
			GPIOC_CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIOC_CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		else if(Copy_u8Pin <=15 )
		{//high
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIOC_CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}
		break;
	default :break;
	}


}

void MGPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOA_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT(  GPIOA_ODR , Copy_u8Pin );
		}
		break;
		
	case GPIOB:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOB_ODR  , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( GPIOB_ODR  , Copy_u8Pin );
		}
		break;
		
	case GPIOC:
		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIOC_ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLR_BIT( GPIOC_ODR , Copy_u8Pin );
		}
		break;

	}

}

void MGPIO_VidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    switch(Copy_u8Port)
    {
        case GPIOA:
            TOGGLE_BIT(GPIOA_ODR, Copy_u8Pin);
            break;

        case GPIOB:
            TOGGLE_BIT(GPIOB_ODR, Copy_u8Pin);
            break;

        case GPIOC:
            TOGGLE_BIT(GPIOC_ODR, Copy_u8Pin);
            break;

        default:
            /* Optional: Handle invalid port */
            break;
    }
}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}

void GPIO_BuiltinLedsInit(void)
{
	MRCC_VidEnablePeripheralClock(APB2_BUS, 4);
	MGPIO_VidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOC, PIN14, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOC, PIN15, OUTPUT_SPEED_10MHZ_PP);

}

void GPIO_GreenLedOn(void)
{
	MGPIO_VidSetPinValue(GPIOC, GREEN_LED_PIN, HIGH);
}

void GPIO_BlueLedOn(void)
{
	MGPIO_VidSetPinValue(GPIOC, BLUE_LED_PIN, HIGH);
}

void GPIO_YellowLedOn(void)
{
	MGPIO_VidSetPinValue(GPIOC, YELLOW_LED_PIN, HIGH);
}


void GPIO_BlueLedToggle(void)
{
	MGPIO_VidTogglePinValue(GPIOC, BLUE_LED_PIN);
}
void GPIO_GreenLedToggle(void)
{
	MGPIO_VidTogglePinValue(GPIOC, GREEN_LED_PIN);
}
void GPIO_YellowLedToggle(void)
{
	MGPIO_VidTogglePinValue(GPIOC, YELLOW_LED_PIN);
}
