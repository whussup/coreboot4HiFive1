/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2017 Siemens AG
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _I2C_RX6110SA_H_
#define _I2C_RX6110SA_H_

/* The address of this RTC is fixed. */
#define RX6110SA_SLAVE_ADR		0x32
#define RX6110SA_I2C_CONTROLLER		0

/* Register layout */
#define SECOND_REG			0x10
#define MINUTE_REG			0x11
#define HOUR_REG			0x12
#define WEEK_REG			0x13
#define DAY_REG				0x14
#define MONTH_REG			0x15
#define YEAR_REG			0x16
#define RESERVED_BIT_REG		0x17
#define  RTC_INIT_VALUE			0x28
#define ALARM_MINUTE_REG		0x18
#define ALARM_HOUR_REG			0x19
#define ALARM_WEEKDAY_REG		0x1A
#define TMR_COUNTER_0_REG		0x1B
#define TMR_COUNTER_1_REG		0x1C
#define EXTENSION_REG			0x1D
#define  TE_BIT				(1 << 4)
#define  FSEL_MASK			0xC0
#define FLAG_REGISTER			0x1E
#define  VLF_BIT			(1 << 1)
#define CTRL_REG			0x1F
#define  AIE_BIT			(1 << 3)
#define  TIE_BIT			(1 << 4)
#define  UIE_BIT			(1 << 5)
#define  STOP_BIT			(1 << 6)
#define  TEST_BIT			(1 << 7)
#define DIGITAL_REG			0x30
#define BATTERY_BACKUP_REG		0x31
#define IRQ_CONTROL_REG			0x32

/* Define CLKOUT frequency divider values valid for parameter cof_selection */
#define COF_OFF				0x00
#define COF_1_HZ			0x01
#define COF_1024_HZ			0x02
#define COF_32768_HZ			0x03

#endif /* _I2C_RX6110SA_H_ */
