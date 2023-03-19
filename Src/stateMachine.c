#include "stateMachine.h"

uint32_t gPasswordReset  = 11111;
uint32_t gFactoryResetPW = 61297;
uint8_t index = 0;

void onScreenDisplay(void)
{
	// static uint8_t index = 0;
    if (!gButton.button1)
    {
      switch (state1)
      {
      case MENU_PAGE:
        kmi_change_display(VOLTAGE_PAGE);
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
      case ASPHALT_SETPOINTS_PAGE:
        if (index >= 3)
        {
          increaseValueSetpoint((index), (uint16_t *)&gUserSaveDataTemp.lowEnableAsphaltSet);
        }
        else
        {
          increaseValueSetpoint(index, (uint16_t *)&gUserSaveDataTemp.targetTempAsphaltSet);
        }
        
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        increaseValueSetpoint(index, (uint16_t *)&gUserSaveDataTemp.overTempCombustionAlarm);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        increaseValueSetpoint(index, (uint16_t *)&gUserSaveDataTemp.burnerDelaySet);
        break;
      case VOLTAGE_SETPOINT_PAGE:
        getLowVoltageSetpoint(index, (uint16_t *)&gUserSaveDataTemp.lowVoltageCheck);
        break;
      case CP_RESET_AUTH_PAGE:
      case BURNER_RESET_AUTH_PAGE:
        getPasswordReset(index, (uint32_t *)&gUserSaveDataTemp.resetPassword);
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
      case SETTINGS_PAGE:
        kmi_change_display(BURNER_DELAY_SETTINGS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        index++;
        if (index > 5)
        {
          index = 0;
        }
        setAsphaltSetpoint(index);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        index++;
        if (index > 2)
        {
          index = 0;
        }
        setCombustionSetpoint(index);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        index++;
        if (index > 2)
        {
          index = 0;
        }
        setBunerDelaySetpoint(index);
        break;
      case VOLTAGE_SETPOINT_PAGE:
        index++;
        if (index > 3)
        {
          index = 0;
        }
        setLowVoltageSetpoint(index);
        break;
      case BURNER_RESET_AUTH_PAGE:
      case CP_RESET_AUTH_PAGE:
        index++;
        if (index > 4)
        {
          index = 0;
        }
        setPasswordReset(index);
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
      case VOLTAGE_PAGE:
        kmi_change_display(VOLTAGE_SETPOINT_PAGE);
        break;
      case SETTINGS_PAGE:
        kmi_change_display(RUNTIMES_PAGE);
        break;
      case RUNTIMES_PAGE:
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
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(COMBUSTION_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        isConfirmESC(&index);
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        isConfirmESC(&index);
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        isConfirmESC(&index);
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        isConfirmESC(&index);
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        isConfirmESC(&index);
        kmi_change_display(SETTINGS_PAGE);
        break;
      case VOLTAGE_SETPOINT_PAGE:
        isConfirmESC(&index);
        kmi_change_display(VOLTAGE_PAGE);
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
      case TEMP_SETPOINTS_PAGE:
        kmi_change_display(TEMP_PAGE);
        break;
      case RUNTIMES_PAGE:
        kmi_change_display(SETTINGS_PAGE);
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
      case TEMP_UNIT_PAGE:
        isConfirmOk(&index);
        kmi_change_display(TEMP_PAGE);
        break;
      case BURNER_DELAY_SETTINGS_PAGE:
        isConfirmOk(&index);
        kmi_change_display(SETTINGS_PAGE);
        break;
      case COMBUSTION_SETPOINTS_PAGE:
        isConfirmOk(&index);
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case ASPHALT_SETPOINTS_PAGE:
        isConfirmOk(&index);
        kmi_change_display(TEMP_SETPOINTS_PAGE);
        break;
      case CP_RESET_AUTH_PAGE:
        isConfirmOk(&index);
        kmi_change_display(CP_RUNTIMES_PAGE);
        break;
      case BURNER_RESET_AUTH_PAGE:
        isConfirmOk(&index);
        kmi_change_display(BURNER_RUNTIMES_PAGE);
        break;
      case VOLTAGE_SETPOINT_PAGE:
        isConfirmOk(&index);
        kmi_change_display(VOLTAGE_PAGE);
        break;
      default:
        break;
      }
    }
}

void changeUnitTemperature(void)
{
    if (gUserSaveDataTemp.temperatureUnit == CELSIUS)
    {
      gUserSaveDataTemp.temperatureUnit = FAHRENHEIT;
    }
    else
    {
      gUserSaveDataTemp.temperatureUnit = CELSIUS;
    }
    HAL_Delay(300);
}

void setBunerDelayTimeSetpoint(uint8_t index)
{
  uint8_t pIndex[3][2] =
  {
    {1, 0},
    {1, 1},
    {1, 2},
  };
  setBlinkIndexUser(pIndex, index);
  HAL_Delay(DELAY_TIME_USER);
}

void setAsphaltSetpoint(uint8_t index)
{
  uint8_t pIndex[6][2] =
  {
    {1, 7},
    {1, 8},
    {1, 9},
    {2, 7},
    {2, 8},
    {2, 9},
  };
  setBlinkIndexUser(pIndex, index);
  HAL_Delay(DELAY_TIME_USER);
}

void setLowVoltageSetpoint(uint8_t index)
{
  uint8_t pIndex[4][2] =
  {
    {2, 0},
    {2, 1},
    {2, 3},
    {2, 4},
  };
  setBlinkIndexUser(pIndex, index);
  HAL_Delay(DELAY_TIME_USER);
}

void setBlinkIndexUser(uint8_t index[][2], uint8_t count)
{
    setBlinkCursorLCD((*(*(index)+(count*2))),(*(*(index)+(count*2+1))));
}

void increaseValueSetpoint(uint8_t index, uint16_t *pGetValue)
{
  uint8_t temp[5];
  bool displayCursorLowENA = 0;
  if (state1 == COMBUSTION_SETPOINTS_PAGE || state1 == BURNER_DELAY_SETTINGS_PAGE || state1 == ASPHALT_SETPOINTS_PAGE)
  {
      temp[0] = (*pGetValue / 100);
      temp[1] = (*pGetValue / 10) % 10;
      temp[2] = (*pGetValue / 1)  % 10;
      if(index >= 3)
      {
        index -= 3; // use for ASPHALT set low enable value
        displayCursorLowENA = 1;
      }
      for (int i = 0; i < 5; i++)
      {
        if (gUserSaveDataTemp.temperatureUnit == FAHRENHEIT)
        {
          if (index == i)
          {
            temp[i]++;
            if (temp[i] > 9)
            {
              temp[i] = 0;
            }
          }
        }
        else
        {
          if (index == i)
          {
            temp[i]++;
            if (temp[0] > 5)
            {
              temp[0] = 0;
            }
            if (temp[1] > 9)
            {
              temp[1] = 0;
            }
            if (temp[2] > 9)
            {
              temp[2] = 0;
            }
          }
        }
      }
    *pGetValue = (temp[0]*100 + temp[1]*10 + temp[2]);
  }

  if (displayCursorLowENA)
  {
    readLoadInputUserType(index + 3);
  }
  else
  {
    readLoadInputUserType(index);
  }
  HAL_Delay(DELAY_TIME_USER);
}

void getLowVoltageSetpoint(uint8_t index, uint16_t *pGetValue)
{
   uint8_t temp[5];
  if(state1 == VOLTAGE_SETPOINT_PAGE)
  {
      temp[0] = (*pGetValue / 1000);
      temp[1] = (*pGetValue / 100) % 10;
      temp[2] = (*pGetValue / 10)  % 10;
      temp[3] = (*pGetValue /1)    % 10;
      for (int i = 0; i < 4; i++)
      {
        if (index == i)
        {
          temp[i]++;
          if (temp[0] > 1) // not allow > 13V
          {
            temp[0] = 0;
          }
          if (temp[1] > 3)
          {
            temp[1] = 0;
          }
          if (temp[i] > 9)
          {
            temp[i] = 0;
          } 
        }
      }
    *pGetValue = (temp[0]*1000 + temp[1]*100 + temp[2]*10 + temp[3]);
  }
  readLoadInputUserType(index);
  HAL_Delay(DELAY_TIME_USER);
}

void getPasswordReset(uint8_t index, uint32_t *pGetValue)
{
  uint8_t temp[5];
  if (state1 == BURNER_RESET_AUTH_PAGE || state1 == CP_RESET_AUTH_PAGE)
  {
    temp[0] = (*pGetValue / 10000);
    temp[1] = (*pGetValue / 1000) % 10;
    temp[2] = (*pGetValue / 100) % 10;
    temp[3] = (*pGetValue / 10) % 10;
    temp[4] = (*pGetValue % 10);
    for (int i = 0; i < 5; i++)
    {
        if (index == i)
        {
          temp[i]++;
          if (temp[i] > 9)
          {
            temp[i] = 0;
          }
        }
    }

    *pGetValue = (temp[0]*10000 + temp[1]*1000 + temp[2]*100 + temp[3]*10 + temp[4]);
  }

  readLoadInputUserType(index);
  HAL_Delay(DELAY_TIME_USER);
}

void setCombustionSetpoint(uint8_t index)
{
    uint8_t pIndex[3][2] = 
    {
      {1, 6},
      {1, 7},
      {1, 8},
    };
    setBlinkIndexUser(pIndex, index);
    HAL_Delay(DELAY_TIME_USER);
}

void setBunerDelaySetpoint(uint8_t index)
{
    uint8_t pIndex[3][2] = 
    {
      {1, 0},
      {1, 1},
      {1, 2},
    };
    setBlinkIndexUser(pIndex, index);
    HAL_Delay(DELAY_TIME_USER);
}

void setPoisitionBlinkCursor(uint8_t index[][2] ,uint8_t *pIndex, uint8_t size)
{
    (*pIndex)++;
    if((*pIndex) > size)
    {
      *pIndex = 0;
    }
    setBlinkIndexUser(index, *pIndex);
    HAL_Delay(DELAY_TIME_USER);
}


void setPasswordReset(uint8_t index)
{
  uint8_t pIndex[5][2] = 
  {
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    {2, 4},
  };
  setBlinkIndexUser(pIndex, index);
  HAL_Delay(DELAY_TIME_USER);
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
    kmi_redisplay_cp_runtime();
    break;
    case BURNER_RUNTIMES_PAGE:
    kmi_redisplay_burner_runtime();
    break;
  }
}

void readLoadInputUserType(uint8_t index)
{
  setClrCurWithoutReset();
  switch (state1)
  {
  case ASPHALT_SETPOINTS_PAGE:
      kmi_redisplay_asph_setpoint();
      setAsphaltSetpoint(index);
      break;
  case COMBUSTION_SETPOINTS_PAGE:
      kmi_redisplay_comb_setpoint();
      setCombustionSetpoint(index);
      break;
  case CP_RESET_AUTH_PAGE:
      kmi_redisplay_cp_reset_auth(index);
      setPasswordReset(index);
      break;
  case BURNER_RESET_AUTH_PAGE:
      kmi_redisplay_burner_reset_auth(index);
      setPasswordReset(index);
      break;
  case BURNER_DELAY_SETTINGS_PAGE:
      kmi_redisplay_burner_delay_setting();
      setBunerDelaySetpoint(index);
      break;
  case VOLTAGE_SETPOINT_PAGE:
      kmi_redisplay_voltage_setpoint();
      setLowVoltageSetpoint(index);
      break;
  }
}

void isConfirmOk(uint8_t *pIndex)
{
  if (gUserSaveDataTemp.resetPassword  == gFactoryResetPW)
  {
    memcpy(&gUserSetInput, &userDefaultValue, USER_WRITE_SIZE);
    memcpy(&gUserSaveDataTemp, &gUserSetInput, USER_WRITE_SIZE);
    userInputWriteFlash(gUserSetInput);
    clearCursorLCD(pIndex);
    gUserSaveDataTemp.resetPassword = 0;
    return;
  }

  if (gUserSaveDataTemp.resetPassword == gPasswordReset)
  {
      if (state1 == BURNER_RESET_AUTH_PAGE)
      {
        gUserSaveDataTemp.burnerRuntime = 0;
      }
      else if (state1 == CP_RESET_AUTH_PAGE)
      {
        gUserSaveDataTemp.cpRuntime = 0;
      }
  }

  gUserSaveDataTemp.resetPassword = 0;
  memcpy(&gUserSetInput, &gUserSaveDataTemp, USER_WRITE_SIZE);
  userInputWriteFlash(gUserSetInput);
  clearCursorLCD(pIndex);
}

void isConfirmESC(uint8_t *pIndex)
{
  memcpy(&gUserSaveDataTemp, &gUserSetInput, USER_WRITE_SIZE);
  clearCursorLCD(pIndex);
  gUserSaveDataTemp.resetPassword = 0;
}

void killSystemWorking(void)
{
  HAL_TIM_Base_Stop_IT(&htim15);
  HAL_TIM_Base_Stop_IT(&htim6);
  while (1)
    ;
}

void checkAlarmSystem(void)
{
  if (gCombustionTemp > gUserSetInput.overTempCombustionAlarm)
  {
    kmi_display_alarm_over_temp();
    killSystemWorking();
  }
//////////////////////////////////////////////////////////////////////////////////
  if (gButton.eStopEmergency)
  {
    gAlarmSys.emerStop = 0;
    kmi_display_alarm_emer_stop();
    emergencyStopWorking();
    return;
  }
  else
  {
    gAlarmSys.emerStop = 1;
    if (state1 == EMER_STOP_PAGE)
    {
      kmi_display_home();
    }
  }
//////////////////////////////////////////////////////////////////////////////////
  if (asphErrorTher == NO_CONNECT)
  {
    gAlarmSys.asphTherDisc = 0;
    kmi_display_alarm_asphalt_dis();
    emergencyStopWorking();
    return;
  }
  else
  {
    gAlarmSys.asphTherDisc = 1;
    if (state1 == ASPHALT_DIS_PAGE)
    {
      kmi_display_home();
    }
  }
//////////////////////////////////////////////////////////////////////////////////
  if (asphErrorTher == SHORT_GND || asphErrorTher == SHORT_VCC)
  {
    gAlarmSys.asphTherShorted = 0;
    kmi_display_alarm_asphalt_shorted();
    emergencyStopWorking();
    return;
  }
  else
  {
    gAlarmSys.asphTherShorted = 1;
    if (state1 == ASPHALT_SHORT_PAGE)
    {
      kmi_display_home();
    }
  }
//////////////////////////////////////////////////////////////////////////////////  
  if (combErrorTher == NO_CONNECT)
  {
    gAlarmSys.combTherDisc = 0;
    kmi_display_alarm_combustion_dis();
    emergencyStopWorking();
    return;
  }
  else
  {
    gAlarmSys.combTherDisc = 1;
    if (state1 == COMBUSTION_DIS_PAGE)
    {
      kmi_display_home();
    }
  }

  if (combErrorTher == SHORT_GND || combErrorTher == SHORT_VCC)
  {
    gAlarmSys.combTherShorted = 0;
    kmi_display_alarm_combustion_shorted();
    emergencyStopWorking();
    return;
  }
  else
  {
    gAlarmSys.combTherShorted = 1;
    if (state1 == COMBUSTION_SHORT_PAGE)
    {
      kmi_display_home();
    }
  }
  
  if (gVoltageBattery < (float)((gUserSetInput.lowVoltageCheck) / 100 + (((gUserSetInput.lowVoltageCheck) % 100) / 100)))
  {
    gAlarmSys.lowVoltage = 0;
    kmi_display_alarm_low_vol();
    kmi_redisplay_alarm_low_vol();
  }
  else
  {
    gAlarmSys.lowVoltage = 1;
    if (state1 == LOW_VOL_ALARM_PAGE)
    {
      kmi_display_home();
    }
  }
}
