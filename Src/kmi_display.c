/*
 * kmi_display.c
 *
 *  Created on: Feb 20, 2023
 *      Author: Nhuan Huynh
 */

/* Includes ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

#include "kmi_display.h"
#include "main.h"
#include <stdio.h>
#include "stdbool.h"

uint8_t state1;

extern float gVoltageBattery;
extern float gAsphaltTemp;
extern float gCombustionTemp;
extern bool gUintTemperature;
void kmi_display_init(void)
{
	LCD_init();
	LCD_clear();
}

void kmi_display_startup(void)
{
	state1 = STARTUP_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("K-M INTERNATIONAL");
	LCD_setCursor(1, 0);
	LCD_puts("HOT BOX CONTROLLER");
	LCD_setCursor(2, 0);
	LCD_puts("HB-CP-C2");
	LCD_setCursor(3, 0);
	LCD_puts("REV #.##");
	LCD_setCursor(3, 19);
	LCD_puts("#");
}

void kmi_display_alarm(void)
{
	state1 = ARLARM_PAGE;
	LCD_clear();
	LCD_setCursor(0, 2);
	LCD_puts("!!! CAUTION !!!");
	LCD_setCursor(1, 2);
	LCD_puts("OVERTEMPERATURE");
	LCD_setCursor(2, 2);
	LCD_puts("INSPECT CHAMBER");
	LCD_setCursor(3, 1);
	LCD_puts("POWER OFF TO RESET");
}

void kmi_display_home(float asphastTemp, float combustionTemp)
{
	char buff[20];
	state1 = HOME_PAGE;
	LCD_clear();
	LCD_setCursor(0, 2);
	LCD_puts("  TEMPERATURES");
	LCD_setCursor(1, 0);
	LCD_puts("ASPHALT   COMBUSTION");
	LCD_setCursor(2, 0);
	sprintf(buff," %.1fF       %.1fF",asphastTemp, combustionTemp);
	LCD_puts(buff);
	LCD_setCursor(3, 13);
	LCD_puts("MENU-->");
}

void kmi_display_menu(void)
{
	state1 = MENU_PAGE;
	LCD_clear();
	LCD_setCursor(0, 10);
	LCD_puts("VOLTAGE-->");
	LCD_setCursor(1, 2);
	LCD_puts("I/O DIAGNOSTICS-->");
	LCD_setCursor(2, 9);
	LCD_puts("SETTINGS-->");
	LCD_setCursor(3, 13);
	LCD_puts("HOME-->");
}

void kmi_display_voltage(float vol)
{
	state1 = VOLTAGE_PAGE;
	char buff[20];
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("BATTERY VOLTS");
	LCD_setCursor(1, 0);
	sprintf(buff,"%.2f  VDC",vol);
	LCD_puts(buff);
	LCD_setCursor(3, 13);
	LCD_puts("MENU-->");

}

void kmi_display_analog(void)
{
	state1 = ANALOG_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("ANALOG");
	LCD_setCursor(1, 10);
	LCD_puts("ASPHALT-->");
	LCD_setCursor(2, 11);
	LCD_puts("BURNER-->");
	LCD_setCursor(3, 13);
	LCD_puts("MENU-->");
}

void kmi_display_IOdiagnostics1(void)
{	
	state1 = IO_DIAGNOSTICS_1_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("I/O       SYS EN OFF");
	LCD_setCursor(1, 0);
	LCD_puts("DIAG      E-STOP OFF");
	LCD_setCursor(2, 0);
	LCD_puts("1            NEXT-->");
	LCD_setCursor(3, 0);
	LCD_puts("             MENU-->");
}

void kmi_display_IOdiagnostics2(void)
{
	state1 = IO_DIAGNOSTICS_2_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("I/O   BURNER PWR OFF");
	LCD_setCursor(1, 0);
	LCD_puts("DIAG   BURNER EN OFF");
	LCD_setCursor(2, 0);
	LCD_puts("2            NEXT-->");
	LCD_setCursor(3, 0);
	LCD_puts("             MENU-->");
}

void kmi_display_IOdiagnostics3(void)
{
	state1 = IO_DIAGNOSTICS_3_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("I/O         INCR OFF");
	LCD_setCursor(1, 0);
	LCD_puts("DIAG        DECR OFF");
	LCD_setCursor(2, 0);
	LCD_puts("3            NEXT-->");
	LCD_setCursor(3, 0);
	LCD_puts("             MENU-->");
}

void kmi_display_IOdiagnostics4(void)
{
	state1 = IO_DIAGNOSTICS_4_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("I/O   WORK LIGHT OFF");
	LCD_setCursor(1, 0);
	LCD_puts("DIAG                ");
	LCD_setCursor(2, 0);
	LCD_puts("4            NEXT-->");
	LCD_setCursor(3, 0);
	LCD_puts("             MENU-->");
}

void kmi_display_settings(void)
{
	state1 = SETTINGS_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("SETTINGS     TEMP-->");
	LCD_setCursor(1, 0);
	LCD_puts("     BURNER DELAY-->");
	LCD_setCursor(2, 0);
	LCD_puts("        RUN TIMES-->");
	LCD_setCursor(3, 0);
	LCD_puts("             MENU-->");
}

void kmi_display_temp (void)
{
	state1 = TEMP_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("TEMP         UNIT-->");
	LCD_setCursor(1, 0);
	LCD_puts("        SETPOINTS-->");
	LCD_setCursor(3, 0);
	LCD_puts("              ESC-->");
}

void kmi_display_temp_unit (uint8_t temp)
{
	state1 = TEMP_UNIT_PAGE;
	char buff[20];
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("TEMPERATURE UNITS");
	LCD_setCursor(1, 0);
	sprintf(buff,"%d         CYCLE-->",temp);
	LCD_puts(buff);
	LCD_setCursor(3, 0);
	LCD_puts("               OK-->");
}

void kmi_display_temp_setpoint (void)
{
	state1 = TEMP_SETPOINTS_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("TEMPERATURE SETPOINT");
	LCD_setCursor(1, 0);
	LCD_puts("          ASPHALT-->");
	LCD_setCursor(2, 0);
	LCD_puts("       COMBUSTION-->");
	LCD_setCursor(3, 0);
	LCD_puts("              ESC-->");
}

void kmi_display_asph_setpoint (void)
{
	state1 = ASPHALT_SETPOINTS_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("ASPH. SETPOINT     ^");
	LCD_setCursor(1, 0);
	LCD_puts("TARGET ### F       >");
	LCD_setCursor(2, 0);
	LCD_puts("LO/ENA ### F  ESC-->");
	LCD_setCursor(3, 0);
	LCD_puts("               OK-->");
}

void kmi_display_comb_setpoint (void)
{
	state1 = COMBUSTION_SETPOINTS_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("COMBUSTION SET     ^");
	LCD_setCursor(1, 0);
	LCD_puts("TARGET ###F        >");
	LCD_setCursor(2, 0);
	LCD_puts("LO/ENA ###F   ESC-->");
	LCD_setCursor(3, 0);
	LCD_puts("       OK-->        ");
}

void kmi_display_burner_delay_setting (void)
{
	state1 = BURNER_DELAY_SETTINGS_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("BURNER DELAY TIME  ^");
	LCD_setCursor(1, 0);
	LCD_puts("### HR              ");
	LCD_setCursor(2, 0);
	LCD_puts("              ESC-->");
	LCD_setCursor(3, 0);
	LCD_puts("               OK-->");
}

void kmi_display_runtimes (void)
{
	state1 = RUNTIMES_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("RUN TIMES");
	LCD_setCursor(1, 0);
	LCD_puts("    CONTROL PANEL-->");
	LCD_setCursor(2, 0);
	LCD_puts("           BURNER-->");
	LCD_setCursor(3, 0);
	LCD_puts("             BACK-->");
}

void kmi_display_cp_runtime (void)
{
	state1 = CP_RUNTIMES_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("CP RUN TIME");
	LCD_setCursor(1, 0);
	LCD_puts("##.### HRS          ");
	LCD_setCursor(2, 0);
	LCD_puts("            RESET-->");
	LCD_setCursor(3, 0);
	LCD_puts("             BACK-->");
}

void kmi_display_cp_reset_auth (void)
{
	state1 = CP_RESET_AUTH_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("RESET RUN TIME     ^");
	LCD_setCursor(1, 0);
	LCD_puts("PASSWORD           >");
	LCD_setCursor(2, 0);
	LCD_puts("####          ESC-->");
	LCD_setCursor(3, 0);
	LCD_puts("               OK-->");
}

void kmi_display_burner_runtime (void)
{
	state1 = CP_RUNTIMES_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("BURNER RUN TIME");
	LCD_setCursor(1, 0);
	LCD_puts("##.### HRS          ");
	LCD_setCursor(2, 0);
	LCD_puts("            RESET-->");
	LCD_setCursor(3, 0);
	LCD_puts("             BACK-->");
}

void kmi_display_burner_reset_auth (void)
{
	state1 = BURNER_RESET_AUTH_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("RESET BURNER TIME  ^");
	LCD_setCursor(1, 0);
	LCD_puts("PASSWORD           >");
	LCD_setCursor(2, 0);
	LCD_puts("####          ESC-->");
	LCD_setCursor(3, 0);
	LCD_puts("               OK-->");
}
void kmi_display_burner (void)
{
	state1 = BURNER_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("####               ^");
	LCD_setCursor(3, 0);
	LCD_puts("             BACK-->");
}

void kmi_display_asphalt (void)
{
	state1 =   ASPHALT_PAGE;
	LCD_clear();
	LCD_setCursor(0, 0);
	LCD_puts("####               ^");
	LCD_setCursor(3, 0);
	LCD_puts("             BACK-->");
}

void kmi_change_display(uint8_t userValue)
{
	  switch (userValue)
	  {
		case STARTUP_PAGE:
			kmi_display_startup();
			break;
		case ARLARM_PAGE:
			kmi_display_alarm();
			break;
		case HOME_PAGE:
			kmi_display_home(gAsphaltTemp, gCombustionTemp);
			break;
		case MENU_PAGE:
			kmi_display_menu();
			break;
		case SETTINGS_PAGE:
			kmi_display_settings();
			break;
		case IO_DIAGNOSTICS_1_PAGE:
			kmi_display_IOdiagnostics1();
			break;
		case IO_DIAGNOSTICS_2_PAGE:
			kmi_display_IOdiagnostics2();
			break;
		case IO_DIAGNOSTICS_3_PAGE:
			kmi_display_IOdiagnostics3();
			break;
		case IO_DIAGNOSTICS_4_PAGE:
			kmi_display_IOdiagnostics4();
			break;
		case VOLTAGE_PAGE:
			kmi_display_voltage(gVoltageBattery);
			break;     
		case ANALOG_PAGE:
			kmi_display_analog();
			break;        
        case ASPHALT_PAGE:
			kmi_display_asphalt();
			break;          
        case BURNER_PAGE:
			kmi_display_burner();
			break;                  
        case TEMP_PAGE:
			kmi_display_temp();
			break;          
        case TEMP_UNIT_PAGE:
			kmi_display_temp_unit(gUintTemperature);
			break;          
        case TEMP_SETPOINTS_PAGE:
			kmi_display_temp_setpoint();
			break;          
		case ASPHALT_SETPOINTS_PAGE:
			kmi_display_asph_setpoint();
			break;          
        case COMBUSTION_SETPOINTS_PAGE:
			kmi_display_comb_setpoint();
			break;          
        case BURNER_DELAY_SETTINGS_PAGE:
			kmi_display_burner_delay_setting();
			break;          
        case RUNTIMES_PAGE:
			kmi_display_runtimes();
			break;          
        case CP_RUNTIMES_PAGE:
			kmi_display_cp_runtime();
			break;          
        case CP_RESET_AUTH_PAGE:
			kmi_display_cp_reset_auth();
			break;          
        case BURNER_RUNTIMES_PAGE:
			kmi_display_burner_runtime();
			break;          
        case BURNER_RESET_AUTH_PAGE:
			kmi_display_burner_reset_auth();
			break;          
	 default:
    	break;
	  }
}

void kmi_blinking_cursor (uint8_t userValue)
{


	
}

/*
 * EOF
 * */
