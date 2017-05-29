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
#include <serial.h>
#include <asm/arch/hardware.h>
#include <asm/arch/pxa.h>
#include <asm/arch/regs-mmc.h>
#include <asm/arch/regs-uart.h>
//#include <dm/platdata.h>
//#include <dm/platform_data/serial_pxa.h>
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

#define LED_RUN		0x00000001
#define LED_FAIL	0x00000002
#define LED_IO		0x00000004
#define LED_MODE	0x00000010

#define LED_F1		0x01000000
#define LED_F2		0x00010000

int debug_led_count(int cmd)
{
	/* settings des leds RUN, FAIL, I/O et MODE */
	writel(((cmd & (LED_RUN | LED_FAIL)) << 20) \
		| ((cmd & LED_IO) << 21) \
		| ((cmd & LED_MODE) << 18), GPCR1);
	/* Settings des leds F1 et F2 */
	writel(((cmd & LED_F1) >> 15) | (cmd & LED_F2), GPCR0);
	return cmd;
}

int board_init(void)
{

	/* arch number of Leroy LT200 PXA270 */
	gd->bd->bi_arch_number = MACH_TYPE_LT200;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0xa0000100;

	pxa_serial_initialize();

	return 0;
}
int dram_init(void)
{
        gd->ram_size = PHYS_SDRAM_1_SIZE;
	pxa2xx_dram_init();
        return 0;
}

#if defined(CONFIG_SYS_DRAM_TEST)
int
testdram(void)
{
        uint *pstart = (uint *) CONFIG_SYS_MEMTEST_START;
        uint *pend = (uint *) CONFIG_SYS_MEMTEST_END;
        uint *p;

        printf("Testing DRAM from 0x%08x to 0x%08x\n",
               CONFIG_SYS_MEMTEST_START,
               CONFIG_SYS_MEMTEST_END);

        printf("DRAM test phase 1:\n");
        for (p = pstart; p < pend; p++)
                *p = 0xaaaaaaaa;

        for (p = pstart; p < pend; p++) {
                if (*p != 0xaaaaaaaa) {
                        printf("DRAM test fails at: %08x\n", (uint) p);
                        return 1;
                }
        }

        printf("DRAM test phase 2:\n");
        for (p = pstart; p < pend; p++)
                *p = 0x55555555;

        for (p = pstart; p < pend; p++) {
                if (*p != 0x55555555) {
                        printf("DRAM test fails at: %08x\n", (uint) p);
                        return 1;
                }
        }

        printf("DRAM test passed.\n");
        return 0;
}
#endif


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
/*
static const struct pxa_serial_platdata serial_platdata = {
        .base = (struct pxa_uart_regs *)FFUART_BASE,
        .port = FFUART_INDEX,
        .baudrate = CONFIG_BAUDRATE,
};

U_BOOT_DEVICE(pxa_serials) = {
        .name = "serial_pxa",
        .platdata = &serial_platdata,
};
*/
