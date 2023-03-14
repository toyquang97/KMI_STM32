/*
 * kmi_display.h
 *
 *  Created on: Feb 20, 2023
 *      Author: Nhuan Huynh
 */

#ifndef INC_KMI_DISPLAY_H_
#define INC_KMI_DISPLAY_H_

/* Includes ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "lcd.h"
#include "main.h"
#include <stdio.h>
#include "stdbool.h"
#include "MAX31855.h"
#include "string.h"

extern uint8_t state1;
enum {
  STARTUP_PAGE,
  ARLARM_PAGE,
  HOME_PAGE,
  MENU_PAGE,
  VOLTAGE_PAGE,
  IO_DIAGNOSTICS_1_PAGE,
  IO_DIAGNOSTICS_2_PAGE,
  IO_DIAGNOSTICS_3_PAGE,
  IO_DIAGNOSTICS_4_PAGE,
  ANALOG_PAGE,
  ASPHALT_PAGE,
  BURNER_PAGE,
  SETTINGS_PAGE,
  TEMP_PAGE,
  TEMP_UNIT_PAGE,
  TEMP_SETPOINTS_PAGE,
  ASPHALT_SETPOINTS_PAGE,
  COMBUSTION_SETPOINTS_PAGE,
  BURNER_DELAY_SETTINGS_PAGE,
  RUNTIMES_PAGE,
  CP_RUNTIMES_PAGE,
  CP_RESET_AUTH_PAGE,
  BURNER_RUNTIMES_PAGE,
  BURNER_RESET_AUTH_PAGE,
};
/* Functions ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
void kmi_display_init(void);
void kmi_display_startup(void);
void kmi_display_alarm(void);
void kmi_display_home(void);
void kmi_redisplay_home(void);
void kmi_display_menu(void);
void kmi_display_voltage(void);
void kmi_redisplay_voltage(void);
void kmi_display_analog(void);
void kmi_display_IOdiagnostics1(void);
void kmi_display_IOdiagnostics2(void);
void kmi_display_IOdiagnostics3(void);
void kmi_display_IOdiagnostics4(void);
void kmi_display_settings(void);
void kmi_display_temp (void);
void kmi_display_temp_unit (void);
void kmi_redisplay_temp_unit (void);
void kmi_display_temp_setpoint (void);
void kmi_display_asph_setpoint (void);
void kmi_display_comb_setpoint (void);
void kmi_display_burner_delay_setting (void);
void kmi_display_runtimes (void);
void kmi_display_cp_runtime (void);
void kmi_display_cp_reset_auth (void);
void kmi_display_burner_runtime (void);
void kmi_display_burner_reset_auth (void);
void kmi_display_phalt (void);
void kmi_display_burner (void);
void kmi_change_display(uint8_t userValue);
void kmi_blinking_cursor (uint8_t userValue);
#endif /* INC_KMI_DISPLAY_H_ */
