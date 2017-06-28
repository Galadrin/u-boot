 /*---------------------------------------------------------------------------
 . Copyright (C) 2010 LEROY Automation - PFO
 .
 . This program is free software; you can redistribute it and/or modify
 . it under the terms of the GNU General Public License as published by
 . the Free Software Foundation; either version 2 of the License, or
 . (at your option) any later version.
 .
 . This program is distributed in the hope that it will be useful,
 . but WITHOUT ANY WARRANTY; without even the implied warranty of
 . MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 . GNU General Public License for more details.
 .
 . You should have received a copy of the GNU General Public License
 . along with this program; if not, write to the Free Software
 . Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 .
 ---------------------------------------------------------------------------*/

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

/*
 * High Level Board Configuration Options
 */
#define	CONFIG_CPU_PXA27X		1	/* Marvell PXA270 CPU */
#define CONFIG_SYS_TEXT_BASE            0x0
/* Avoid overwriting factory configuration block */
#define CONFIG_BOARD_SIZE_LIMIT         0x40000
#define BOARD_LATE_INIT
/*
#undef	CONFIG_SKIP_RELOCATE_UBOOT
#undef	CONFIG_SKIP_LOWLEVEL_INIT
*/
/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + SZ_1M)
#define CONFIG_SYS_GBL_DATA_SIZE	128

/*
 * Environment settings
 */
#define	CONFIG_ENV_SIZE			SZ_16K
#define	CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_IS_IN_FLASH		1
#define CONFIG_ENV_ADDR			(CONFIG_SYS_MONITOR_LEN)
#define CONFIG_ENV_SECT_SIZE		SZ_256K

/* environment variables configuration */
#define CONFIG_BOOTCOMMAND		"tftpboot 0xa0a00000 uImage-lt200s-pxa270; bootm"
#define CONFIG_BOOTARGS			"root=/dev/nfs rw panic=1 nfsroot=192.168.1.101:/nfsroot-lt200s mem=32M console=ttyS0,115200n8 ip=192.168.1.221:192.168.1.101::255.255.255.0::eth0:"
#define CONFIG_EXTRA_ENV_SETTINGS			\
	"mode=prod\0"					\
	"console=ttyS0\0"				\
	"ubootfile=u-boot-lt200s-pxa270.bin\0"		\
	"initrdfile=initrd-lt200s-pxa270.img\0"		\
	"jffs2file=jffs2-lt200s-pxa270.img\0"		\
	"ubifsfile=ubifs-lt200s-pxa270.img\0"		\
	"prm=0\0"					\
	"ramdisksize=17500\0"				\
	"switchmode=none\0"				\
	"bootfile=uImage-lt200s-pxa270\0"

/*!
 Definitions related to passing arguments to kernel.
 */
#define CONFIG_CMDLINE_TAG		1	/* send commandline to Kernel */
#define CONFIG_SETUP_MEMORY_TAGS	1	/* send memory definition to kernel */
#define CONFIG_INITRD_TAG		1	/* send initrd params */
#undef  CONFIG_VFD				/* do not send framebuffer setup */

/*
 * Serial Console Configuration
 */
#define	CONFIG_FFUART			1
#define CONFIG_CONS_INDEX		3
#define	CONFIG_BAUDRATE			115200
#define	CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }
#undef  CONFIG_SILENT_CONSOLE

/*
 * Command line configuration.
 */
#define	CONFIG_CMD_JFFS2

/*
 * Networking Configuration
 */
#define CONFIG_ETHADDR			"12:34:56:78:9A:BC"
#define CONFIG_NETMASK			"255.255.255.0"
#define CONFIG_IPADDR			"192.168.1.221"
#define CONFIG_SERVERIP			"192.168.1.101"
#define CONFIG_ROOTPATH			"/nfsroot-lt200s"
#define	CONFIG_NET_MULTI		1
#define CONFIG_NET_RETRY_COUNT		10

#define SMC_DEBUG			1
#if 0
#define CONFIG_SMC91111
#define CONFIG_SMC91111_BASE		0x14000300
#define CONFIG_SMC_USE_32_BIT
#undef  CONFIG_SMC91111_EXT_PHY
#else
#define CONFIG_SMC911X
#define CONFIG_SMC911X_BASE		0x14000000
#define CONFIG_SMC911X_16_BIT
#endif

/*
 * MMC Card Configuration
*/
#undef CONFIG_MMC


/*
 * GPIO settings
 */

#define CONFIG_SYS_GPDR0_VAL		0xEBBBDE1B
#define CONFIG_SYS_GPSR0_VAL		0x0203821B
#define CONFIG_SYS_GPCR0_VAL		0xFD385C00
#define CONFIG_SYS_GAFR0_L_VAL		0x80000000
#define CONFIG_SYS_GAFR0_U_VAL		0x00188010
#define CONFIG_SYS_GRER0_VAL            0x00000000
#define CONFIG_SYS_GFER0_VAL            0x10000000

#define CONFIG_SYS_GPDR1_VAL		0xADFBAB83
#define CONFIG_SYS_GPSR1_VAL		0x21F32B83
#define CONFIG_SYS_GPCR1_VAL		0xDC088000
#define CONFIG_SYS_GAFR1_L_VAL		0x61929559
#define CONFIG_SYS_GAFR1_U_VAL		0x00000008
#define CONFIG_SYS_GRER1_VAL            0x00000000
#define CONFIG_SYS_GFER1_VAL            0x00000000


#define CONFIG_SYS_GPDR2_VAL		0xBFFBFFFF
#define CONFIG_SYS_GPSR2_VAL		0x3019C000
#define CONFIG_SYS_GPCR2_VAL		0x8FE03FFF
#define CONFIG_SYS_GAFR2_L_VAL		0xA0000000
#define CONFIG_SYS_GAFR2_U_VAL		0x00000106
#define CONFIG_SYS_GRER2_VAL            0x00000000
#define CONFIG_SYS_GFER2_VAL            0x00000000


#define CONFIG_SYS_GPDR3_VAL		0x01E6F839
#define CONFIG_SYS_GPSR3_VAL		0x00600000
#define CONFIG_SYS_GPCR3_VAL		0x0186F839
#define CONFIG_SYS_GAFR3_L_VAL		0x00000000
#define CONFIG_SYS_GAFR3_U_VAL		0x00001400
#define CONFIG_SYS_GRER3_VAL            0x00000000
#define CONFIG_SYS_GFER3_VAL            0x00000000

#define CONFIG_SYS_PSSR_VAL		0x00000020



/*
 * Memory settings
 */
#define CONFIG_SYS_MSC0_VAL		0x7FFC35B2
#define CONFIG_SYS_MSC1_VAL		0x128C128C
#define CONFIG_SYS_MSC2_VAL		0x236C1281
#define CONFIG_SYS_MDCNFG_VAL		0x08000AC9
#define CONFIG_SYS_MDREFR_VAL		0x01018018
#define CONFIG_SYS_MDMRS_VAL		0x00000000
#define	CONFIG_SYS_FLYCNFG_VAL		0x00000000
#define	CONFIG_SYS_SXCNFG_VAL		0x00000000

/*
 * FLASH memory configuration
 */
#define PHYS_FLASH_1			0x00000000      /* Flash Bank #1 */
#define PHYS_FLASH_SIZE			SZ_32M		/* 32 MB */
#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

#define CONFIG_SYS_FLASH_CFI	
#define CONFIG_FLASH_CFI_DRIVER		1
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_32BIT

#define CONFIG_SYS_MAX_FLASH_SECT	131                     /* number of sector in FLASH bank */
#define CONFIG_SYS_MAX_FLASH_BANKS	1

#define CONFIG_SYS_FLASH_ERASE_TOUT     (2 * CONFIG_SYS_HZ)
#define CONFIG_SYS_FLASH_WRITE_TOUT     (2 * CONFIG_SYS_HZ)
#define CONFIG_SYS_FLASH_LOCK_TOUT      (2 * CONFIG_SYS_HZ)
#define CONFIG_SYS_FLASH_UNLOCK_TOUT    (2 * CONFIG_SYS_HZ)

#define CONFIG_SYS_FLASH_PROTECTION	1

#define CONFIG_SYS_MONITOR_BASE         PHYS_FLASH_1
#define CONFIG_SYS_MONITOR_LEN          SZ_256K


/* LT200 specific */
#define CONFIG_FLASH_BASE		0x00000000		//! location of flash memory

/*
 * DRAM Map
 */
#define CONFIG_NR_DRAM_BANKS		1			//! number of SDRAM banks
#define CONFIG_SYS_DRAM_BASE		0xa0000000		//! DRAM base address
#define CONFIG_SYS_DRAM_SIZE		SZ_32M			//! DRAM size (32 MB)
#define PHYS_SDRAM_1			0xa0000000		//! SDRAM Bank #1 base address
#define PHYS_SDRAM_1_SIZE		SZ_32M			//! SDRAM size (32 MB)
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1		/* CS0 */
#define CONFIG_SYS_SDRAM_SIZE		PHYS_SDRAM_1_SIZE	/* 64 MB DRAM */
#define	CONFIG_SYS_INIT_SP_ADDR		0x5c010000

#define CONFIG_SYS_DRAM_TEST		1


/*
 * PCMCIA and CF Interfaces
 */
#define CONFIG_SYS_MECR_VAL		0x00000000
#define CONFIG_SYS_MCMEM0_VAL		0x58CC0000
#define CONFIG_SYS_MCMEM1_VAL		0x00010504
#define CONFIG_SYS_MCATT0_VAL		0x00000000
#define CONFIG_SYS_MCATT1_VAL		0x00000000
#define CONFIG_SYS_MCIO0_VAL		0x00000000
#define CONFIG_SYS_MCIO1_VAL		0x00000000

/*
 * NAND-FLASH configuration
 */
#define CONFIG_SYS_MAX_NAND_DEVICE	1		/* Max number of NAND devices. */
#define CONFIG_SYS_NAND_BASE		0x08000000	/* Chip Select 2 */

/*
 * MTD & UBI settings
 */
#if 0
#define CONFIG_RBTREE
#define MTDIDS_DEFAULT			"nand0=NAND Flash partition 1"
#define MTDPARTS_DEFAULT		"mtdparts=NAND Flash partition 1:-(ubifs)"
#endif

/*
 * Clock Configuration
 */
#undef	CONFIG_SYS_CLKS_IN_HZ
#define	CONFIG_SYS_HZ			1000
#define CONFIG_SYS_CPUSPEED		0x210		/* standard setting for 416MHz; L=16, N=2, A=0, SDCLK!=SystemBus */

/*
 * Clock settings
 */
#define	CONFIG_SYS_CKEN		0x00500298
#define	CONFIG_SYS_CCCR		0x00000210

/*
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#ifdef	CONFIG_USE_IRQ
#define	CONFIG_STACKSIZE_IRQ		4096	/* IRQ stack: 4k */
#define	CONFIG_STACKSIZE_FIQ		4096	/* FIQ stack: 4k */
#endif

/*
 * I2C stuff
 */
#if 0
#define	CONFIG_HARD_I2C
#define CONFIG_SYS_I2C_SPEED           400000
#endif
/*
 * U-BOOT settings
 */
#define CONFIG_AUTOBOOT_KEYED
#ifdef CONFIG_AUTOBOOT_KEYED
#define CONFIG_AUTOBOOT_PROMPT		"Autobooting in %2d seconds\n"
#define CONFIG_AUTOBOOT_STOP_STR	"halt"
#endif

#define CONFIG_VERSION_VARIABLE

/*
 * General options for u-boot. Modify to save memory foot print
 */
#define CONFIG_SYS_AUTOLOAD		"no"	/* set dhcp configuration without download */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_MEMTEST_START	0xa0400000
#define CONFIG_SYS_MEMTEST_END		0xa0800000
#define CONFIG_SYS_LOAD_ADDR		0xa1000000

#include "pxa-common.h"

#endif  /* __CONFIG_H */

