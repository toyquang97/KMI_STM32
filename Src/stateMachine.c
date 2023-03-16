#include "stateMachine.h"

extern unitTempType_t gUintTemperatureSet;
extern uint32_t gTargetTempAsphaltSet;
extern uint32_t gLowTempEnableAsphaltSet;
extern uint32_t gAlarmTempCombustionSet;
extern float gCpRuntime;
extern float gBurnerRuntime;
extern uint32_t gCPResetPassword;
extern uint32_t gBurnerRuntimeResetPassword;

void onScreenDisplay(void)
{
    if (!gButton.button1)
    {
      switch (state1)
      {
      case MENU_PAGE:
        kmi_display_voltage();
        break;
      case SETTINGS_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case ANALOG_PAGE:
        kmi_change_display(ASPHALT_PAGE);
        break;
      case TEMP_PAGE:
        kmi_change_display(TEMP_UNIT_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(ASPHALT_SETPOINTS_PAGE);
        break;
      default:
        break;
      }
    }
    if (!gButton.button2)
    {
      switch (state1)
      {
      case MENU_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case TEMP_PAGE:
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case TEMP_UNIT_PAGE:
        changeUnitTemperature();
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(ASPHALT_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        setAsphaltSetpoint();
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        setCombustionSetpoint();
        break;
      case SETTINGS_PAGE:
        kmi_change_display(BURNER_DELAY_SETTINGS_PAGE);
        break;
      default:
        break;
      }
    }

    if (!gButton.button3)
    {
      switch (state1)
      {
      case STARTUP_PAGE:
        kmi_change_display(MENU_PAGE);
        break;
      case MENU_PAGE:
        kmi_change_display(HOME_PAGE);
        break;
      case SETTINGS_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        clearCursorLCD();
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        clearCursorLCD();
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case BURNER_RUNTIMES_PAGE:
        kmi_change_display(BURNER_RESET_AUTH_PAGE);
        break;
      case CP_RUNTIMES_PAGE:
        kmi_change_display(CP_RESET_AUTH_PAGE);
        break;
      case IO_DIAGNOSTICS_1_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_2_PAGE);
        break;
      case IO_DIAGNOSTICS_2_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_3_PAGE);
        break;
      case IO_DIAGNOSTICS_3_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_4_PAGE);
        break;
      case IO_DIAGNOSTICS_4_PAGE:
        kmi_change_display(IO_DIAGNOSTICS_1_PAGE);
        break;
      case ANALOG_PAGE:
        kmi_change_display(BURNER_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(COMBUSTION_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        clearCursorLCD();
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        clearCursorLCD();
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;

      default:
        break;
      }
    }
    ////Button4////
    if (!gButton.button4)
    {
      switch (state1)
      {
      case SETTINGS_PAGE:
      case IO_DIAGNOSTICS_1_PAGE:
      case IO_DIAGNOSTICS_2_PAGE:
      case IO_DIAGNOSTICS_3_PAGE:
      case IO_DIAGNOSTICS_4_PAGE:
      case VOLTAGE_PAGE:
      case ANALOG_PAGE:
      case HOME_PAGE:
        kmi_change_display(MENU_PAGE);
        break;
      case TEMP_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case TEMP_UNIT_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        clearCursorLCD();
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        clearCursorLCD();
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        clearCursorLCD();
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        clearCursorLCD();
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case BURNER_RUNTIMES_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case CP_RUNTIMES_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case BURNER_PAGE:
        kmi_change_display(ANALOG_PAGE);
        break;
      case ASPHALT_PAGE:
        kmi_change_display(ANALOG_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        kmi_change_display(SETTINGS_PAGE);
        break;
      default:
        break;
      }
    }
}

void changeUnitTemperature(void)
{
    if (gUintTemperatureSet == CELSIUS)
    {
      gUintTemperatureSet = FAHRENHEIT;
    }
    else
    {
      gUintTemperatureSet = CELSIUS;
    }
    HAL_Delay(200);
}

void setAsphaltSetpoint(void)
{
    static uint8_t indexX = 8;
    static uint8_t indexY = 8;
    setBlinkCursorLCD(1, 7);
    indexX++;
    if (indexX > 8)
    {
        indexY = 7;
        LCD_setCursor(2, indexY);
        LCD_sendCmd(0x0D);
    }
    if(indexY > 8)
    {
        indexX = 7;
        LCD_setCursor(2, indexX);
        LCD_sendCmd(0x0D);
    }
    HAL_Delay(300);
}

void setBlinkIndexUser(uint8_t index[][2], uint8_t count)
{
    setBlinkCursorLCD((*(*(index)+(count*2))),(*(*(index)+(count*2+1))));
}

void setCombustionSetpoint(void)
{
    uint8_t index[3][2] = 
    {
        {1, 6},
        {1, 7},
        {1, 8},
    };

    static uint8_t count = 0;
    setBlinkIndexUser(index, count);
    count++;
    if(count > 2) count = 0;
    HAL_Delay(400);
}

void setBunerDelaySetpoint(void)
{

}


void setPasswordReset(void)
{

}

void reloadPageNeeded(void)
{
    switch (state1)
    {
        case HOME_PAGE:
            kmi_redisplay_home();
        break;
        case VOLTAGE_PAGE:
            kmi_redisplay_voltage();
        break;
        case TEMP_UNIT_PAGE:
            kmi_redisplay_temp_unit();
        break;
        case CP_RUNTIMES_PAGE:
            kmi_redisplay_temp_unit();
        break;
        case BURNER_RUNTIMES_PAGE:
            kmi_redisplay_temp_unit();
        break;
    }
}


void inputUserType(void)
{
    switch (state1)
    {
    case ASPHALT_SETPOINTS_PAGE:
        kmi_redisplay_home();
        break;
    case COMBUSTION_SETPOINTS_PAGE:
        kmi_redisplay_voltage();
        break;
    case CP_RESET_AUTH_PAGE:
        kmi_redisplay_temp_unit();
        break;
    case BURNER_RESET_AUTH_PAGE:
        kmi_redisplay_temp_unit();
        break;
    case BURNER_DELAY_SETTINGS_PAGE:
        kmi_redisplay_temp_unit();
        break;
    }
}
