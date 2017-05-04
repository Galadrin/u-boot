/*
 * (C) Copyright 2004
 * Robert Whaley, Applied Data Systems, Inc. rwhaley@applieddata.net
 *
 * (C) Copyright 2002
 * Kyle Harris, Nexus Technologies, Inc. kharris@nexus-tech.net
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/hardware.h>
#include <asm/arch/pxa.h>
#include <asm/arch/regs-mmc.h>
#include <asm/arch/regs-uart.h>
#include <dm/platdata.h>
#include <dm/platform_data/serial_pxa.h>
#include <netdev.h>

DECLARE_GLOBAL_DATA_PTR;

/* ------------------------------------------------------------------------- */
/* we don't use an officially registered machine,
 * so manually specify the mach type.
 */
#ifndef MACH_TYPE_LT200
#define MACH_TYPE_LT200 5224
#endif

/* ------------------------------------------------------------------------- */

int board_init(void)
{
	/* We have RAM, disable cache */
	dcache_disable();
	icache_disable();

	/* arch number of Leroy LT200 PXA270 */
	gd->bd->bi_arch_number = MACH_TYPE_LT200;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0xa0000100;

	return 0;
}

int dram_init(void)
{
	pxa2xx_dram_init();
        gd->ram_size = PHYS_SDRAM_1_SIZE;
        return 0;
}


#ifdef CONFIG_SMC911X
int board_eth_init(bd_t *bis)
{
	return smc911x_initialize(0, CONFIG_SMC911X_BASE);
}
#endif

#ifdef CONFIG_SMSC9303_LT
int smsc9303_init(void);

int board_late_init(void)
{
	printf("Detecting integrated ethernet switch...\n");
	smsc9303_init();
	return 0;
}
#endif

static const struct pxa_serial_platdata serial_platdata = {
        .base = (struct pxa_uart_regs *)FFUART_BASE,
        .port = FFUART_INDEX,
        .baudrate = CONFIG_BAUDRATE,
};

U_BOOT_DEVICE(pxa_serials) = {
        .name = "serial_pxa",
        .platdata = &serial_platdata,
};

