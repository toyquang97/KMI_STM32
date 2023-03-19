/*
 * flash.h
 *
 *  Created on: Dec 8, 2021
 *      Author: User
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_
#define DATA_START_ADDRESS 		 	((uint32_t)0x0800FC00)	//Page 127
#define TARGET_SP_ADDRESS 		 	DATA_START_ADDRESS	//Page 127
#define LOW_ENABLE_SP_ADDR		 	TARGET_SP_ADDRESS + 2	//Page 127 02
#define OVERTEMP_ALARM_SP_ADDR 		LOW_ENABLE_SP_ADDR + 2	//Page 127 04
#define CP_RUMTIME_SP_ADDR 		 	OVERTEMP_ALARM_SP_ADDR + 2	//Page 127 06
#define BURNER_DELAY_SP_ADDR 		CP_RUMTIME_SP_ADDR + 2	//Page 127 08 
#define BURNER_RUNTIME_SP_ADDR 		BURNER_DELAY_SP_ADDR + 2	//Page 127 0A
#define TEMP_UNIT_ADDR 		 	    BURNER_RUNTIME_SP_ADDR + 2	//Page 127 0C

#include "main.h"
#include "string.h"
#include "stdio.h"
#include "stdint.h"
#ifdef _FLASH_C


void deleteBuffer(char* data);
void 	Flash_Lock(void);
void 	Flash_Unlock(void);
void 	Flash_Erase(uint32_t addr);
void 	Flash_Write_Int(uint32_t addr, int data);
uint16_t Flash_Read_Int(uint32_t addr);
void 	Flash_Write_Char(uint32_t addr, char* data);
void 	Flash_ReadChar(char* dataOut, uint32_t addr1, uint32_t addr2);
void 	Flash_ProgramPage(char* dataIn, uint32_t addr1, uint32_t addr2);

void Flash_Write_Bytes(uint32_t addr, uint16_t* data,uint16_t len);
void Flash_Read_Bytes(uint16_t* dataOut, uint32_t addr1, uint16_t len);
void userDataInit(userInput_t *userSet, userInput_t *userSetTemp, userInput_t defaultValue);
void userInputWriteFlash(userInput_t userSet);

#else
extern void deleteBuffer(char* data);
extern void 	Flash_Lock(void);
extern void 	Flash_Unlock(void);
extern void 	Flash_Erase(uint32_t addr);
extern void 	Flash_Write_Int(uint32_t addr, int data);
extern uint16_t Flash_Read_Int(uint32_t addr);
extern void 	Flash_Write_Char(uint32_t addr, char* data);
extern void 	Flash_ReadChar(char* dataOut, uint32_t addr1, uint32_t addr2);
extern void 	Flash_ProgramPage(char* dataIn, uint32_t addr1, uint32_t addr2);

extern void Flash_Write_Bytes(uint32_t addr, uint16_t* data,uint16_t len);
extern void Flash_Read_Bytes(uint16_t* dataOut, uint32_t addr1, uint16_t len);
extern void userDataInit(userInput_t *userSet, userInput_t *userSetTemp, userInput_t defaultValue);
extern void userInputWriteFlash(userInput_t userSet);

#endif
#endif /* INC_FLASH_H_ */
