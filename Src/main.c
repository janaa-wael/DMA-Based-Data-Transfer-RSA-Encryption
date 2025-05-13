/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
/* MCAL includes. */
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "DMA_interface.h"
#include "NVIC_INTERFACE.h"

#define ARRAY_SIZE		5

u32 SOURCE_MEMO[ARRAY_SIZE] = {1,2,3,4,5};
u32 DESTINATION_MEMO[ARRAY_SIZE] = {0};
#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 369

void Delay_MS(unsigned long long n)
{
	volatile unsigned long long count = 0;
	while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}

void DMA_Handler()
{
	GPIO_YellowLedToggle();

	MDMA_VidClearFlag(CHANNEL1, DMA_TCIF);
	MDMA_VidDMADisable(CHANNEL1);
}

/* The HW setup function */
static void prvSetupHardware( void );

/* FreeRTOS tasks */
void vCopyMemory2MemoryTask(void *pvParameters);
void vEncryptDataTask(void *pvParameters);
void vDecryptDataTask(void *pvParameters);

int main(void)
{
	/* Setup the hardware for use with the Tiva C board. */
	prvSetupHardware();

	/* Create Tasks here */
	xTaskCreate(vCopyMemory2MemoryTask, "Task 1", 256, NULL, 1, NULL);
	xTaskCreate(vEncryptDataTask, "Task 2", 256, NULL, 3, NULL);
	xTaskCreate(vDecryptDataTask, "Task 3", 256, NULL, 2, NULL);


	/* Now all the tasks have been started - start the scheduler.

    NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
    The processor MUST be in supervisor mode when vTaskStartScheduler is
    called.  The demo applications included in the FreeRTOS.org download switch
    to supervisor mode prior to main being called.  If you are not using one of
    these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
    available for the idle task to be created. */
	for (;;);

}


static void prvSetupHardware( void )
{
	/* Place here any needed HW initialization such as GPIO, UART, etc.  */
	MRCC_VidInit();
	GPIO_BuiltinLedsInit();
	MRCC_VidEnablePeripheralClock(AHB_BUS, DMA1_RCC);
	MDMA_VidSetConfiguration(CHANNEL1, MEM_TO_MEM, DMA_DISABLE_CIRCULAR, PERIPHERAL_INCREMENT_ENABLE, MEM_INCREMENT_ENABLE, WORD, WORD, HIGH);
	MDMA_VidInerruptEnable(CHANNEL1, DMA_TCIE);
	MDMA_VidSetAddress(CHANNEL1, DESTINATION_MEMO, SOURCE_MEMO, ARRAY_SIZE);
	MNVIC_VidEnablePeripheral(DMA_ID);
	MDMA_VidSetCallBackChannel1(DMA_Handler);

}

void vCopyMemory2MemoryTask(void *pvParameters)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{

		GPIO_BlueLedToggle();
		MRCC_VidEnablePeripheralClock(AHB_BUS, DMA1_RCC);
		MDMA_VidSetConfiguration(CHANNEL1, MEM_TO_MEM, DMA_DISABLE_CIRCULAR, PERIPHERAL_INCREMENT_ENABLE, MEM_INCREMENT_ENABLE, WORD, WORD, HIGH);
		MDMA_VidInerruptEnable(CHANNEL1, DMA_TCIE);
		MDMA_VidSetAddress(CHANNEL1, DESTINATION_MEMO, SOURCE_MEMO, ARRAY_SIZE);
		MNVIC_VidEnablePeripheral(DMA_ID);
		MDMA_VidDMAEnable(CHANNEL1);
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));

	}
}

void vEncryptDataTask(void *pvParameters)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{
		GPIO_GreenLedToggle();
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(500));
	}
}


void vDecryptDataTask(void *pvParameters)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;)
	{
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(800));
	}
}


/*-----------------------------------------------------------*/
