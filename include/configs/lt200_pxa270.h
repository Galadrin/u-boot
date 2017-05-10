/*
 * Leroy-Automation LT200 PXA270 configuration file
 *
 * Copyright (C) 2010 Marek Vasut <marek.vasut@gmail.com>
 * Copyright (C) 2015-2016 Marcel Ziswiler <marcel@ziswiler.com>
 * Copyright (C) 2017 Pierret David <david.pierret@smile.fr>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef	__CONFIG_H
#define	__CONFIG_H

/*
 * High Level Board Configuration Options
 */
#define	CONFIG_CPU_PXA27X		1	/* Marvell PXA270 CPU */
#define	CONFIG_SYS_TEXT_BASE		0x0
/* Avoid overwriting factory configuration block */
#define CONFIG_BOARD_SIZE_LIMIT		0x40000

/* We will never enable dcache because we have to setup MMU first */
#define CONFIG_SYS_DCACHE_OFF

#define CONFIG_DISPLAY_BOARDINFO_LATE	/* Calls show_board_info() */

/*
 * Environment settings
 */
#define	CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_VARS_UBOOT_CONFIG
#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#define	CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 1024*1024)
#define	CONFIG_ARCH_CPU_INIT
#define	CONFIG_BOOTCOMMAND		"tftpboot 0xa0a00000 uImage-lt200-pxa270; bootm"
#define	CONFIG_BOOTARGS			"root=/dev/nfs rw panic=1 nfsroot=192.168.1.101:/nfsroot-lt200 mem=32M console=ttyS0,115200n8 ip=192.168.1.221:192.168.1.101::255.255.255.0::eth0:"
#define	CONFIG_TIMESTAMP
#define	CONFIG_CMDLINE_TAG
#define	CONFIG_SETUP_MEMORY_TAGS

/*
 * Serial Console Configuration
 */
#define	CONFIG_BAUDRATE			115200

/*
 * Bootloader Components Configuration
 */
#define	CONFIG_CMD_ENV

/* I2C support */
#ifdef CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_PXA
#define CONFIG_PXA_STD_I2C
#define CONFIG_PXA_PWR_I2C
#define CONFIG_SYS_I2C_SPEED		400000
#endif

/*
 * Networking Configuration
 */
#ifdef	CONFIG_CMD_NET

#define CONFIG_SMC91111
#define CONFIG_SMC91111_BASE            0x14000300
#define CONFIG_SMC_USE_32_BIT
#undef  CONFIG_SMC91111_EXT_PHY
#define SMC_DEBUG                       0

/* #define CONFIG_SMSC9303_LT */
#define CONFIG_SMC911X
#define CONFIG_SMC911X_BASE             0x14000000
#define CONFIG_SMC911X_16_BIT

#define	CONFIG_NET_RETRY_COUNT		10

#define	CONFIG_BOOTP_BOOTFILESIZE
#define	CONFIG_BOOTP_BOOTPATH
#define	CONFIG_BOOTP_GATEWAY
#define	CONFIG_BOOTP_HOSTNAME
#endif

#undef	CONFIG_SYS_LONGHELP		/* Saves 10 KB */
#define	CONFIG_SYS_CBSIZE		256
#define	CONFIG_SYS_PBSIZE		\
	(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define	CONFIG_SYS_MAXARGS		16
#define	CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define	CONFIG_SYS_DEVICE_NULLDEV	1
#undef	CONFIG_CMDLINE_EDITING		/* Saves 2.5 KB */
#undef	CONFIG_AUTO_COMPLETE		/* Saves 2.5 KB */

/*
 * Clock Configuration
 */
#define	CONFIG_SYS_CPUSPEED		0x210		/* 416MHz */

/*
 * DRAM Map
 */
#define	CONFIG_NR_DRAM_BANKS		1		/* We have 1 bank of DRAM */
#define	PHYS_SDRAM_1			0xa0000000	/* SDRAM Bank #1 */
#define	PHYS_SDRAM_1_SIZE		0x04000000	/* 64 MB */

#define	CONFIG_SYS_DRAM_BASE		0xa0000000	/* CS0 */
#define	CONFIG_SYS_DRAM_SIZE		0x04000000	/* 64 MB DRAM */

#define CONFIG_SYS_MEMTEST_START	0xa0400000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0xa0800000	/* 4 ... 8 MB in DRAM */

#define	CONFIG_SYS_LOAD_ADDR		PHYS_SDRAM_1
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define	CONFIG_SYS_INIT_SP_ADDR		0x5c010000

/*
 * NOR FLASH
 */
#ifdef	CONFIG_CMD_FLASH
#define	PHYS_FLASH_1			0x00000000	/* Flash Bank #1 */
#define	PHYS_FLASH_SIZE			0x02000000	/* 32 MB */
#define	CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

#define	CONFIG_SYS_FLASH_CFI
#define	CONFIG_FLASH_CFI_DRIVER		1
#define	CONFIG_SYS_FLASH_CFI_WIDTH      FLASH_CFI_32BIT

#define	CONFIG_SYS_MAX_FLASH_SECT	131
#define	CONFIG_SYS_MAX_FLASH_BANKS	1

#define	CONFIG_SYS_FLASH_ERASE_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_WRITE_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_LOCK_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_UNLOCK_TOUT	(25 * CONFIG_SYS_HZ)

#define	CONFIG_SYS_FLASH_USE_BUFFER_WRITE	1
#define	CONFIG_SYS_FLASH_PROTECTION		1

#define CONFIG_ENV_IS_IN_FLASH		1

#else	/* No flash */
#define	CONFIG_ENV_IS_NOWHERE
#endif

#define	CONFIG_SYS_MONITOR_BASE		PHYS_FLASH_1
#define	CONFIG_SYS_MONITOR_LEN		0x40000

/* Skip factory configuration block */
#define	CONFIG_ENV_ADDR			CONFIG_SYS_MONITOR_LEN
#define	CONFIG_ENV_SIZE			0x4000
#define	CONFIG_ENV_SECT_SIZE		0x40000

/*
 * GPIO settings
 */
#define	CONFIG_SYS_GPSR0_VAL	0x0203821B
#define	CONFIG_SYS_GPSR1_VAL	0x21F32B83
#define	CONFIG_SYS_GPSR2_VAL	0x3019C000
#define	CONFIG_SYS_GPSR3_VAL	0x00600000

#define	CONFIG_SYS_GPCR0_VAL	0xFD385C00
#define	CONFIG_SYS_GPCR1_VAL	0xDC088000
#define	CONFIG_SYS_GPCR2_VAL	0x8FE03FFF
#define	CONFIG_SYS_GPCR3_VAL	0x0186F839

#define	CONFIG_SYS_GPDR0_VAL	0xEBBBDE1B
#define	CONFIG_SYS_GPDR1_VAL	0xADFBAB83
#define	CONFIG_SYS_GPDR2_VAL	0xBFFBFFFF
#define	CONFIG_SYS_GPDR3_VAL	0x01E6F839

#define	CONFIG_SYS_GAFR0_L_VAL	0x80000000
#define	CONFIG_SYS_GAFR0_U_VAL	0x00188010
#define	CONFIG_SYS_GAFR1_L_VAL	0x61929559
#define	CONFIG_SYS_GAFR1_U_VAL	0x00000008
#define	CONFIG_SYS_GAFR2_L_VAL	0xA0000000
#define	CONFIG_SYS_GAFR2_U_VAL	0x00000106
#define	CONFIG_SYS_GAFR3_L_VAL	0x00000000
#define	CONFIG_SYS_GAFR3_U_VAL	0x00001400

#define	CONFIG_SYS_PSSR_VAL	0x20

/*
 * Clock settings
 */
#define	CONFIG_SYS_CKEN		0x00500298
#define	CONFIG_SYS_CCCR		0x00000210

/*
 * Memory settings
 */
#define	CONFIG_SYS_MSC0_VAL	0x7FFC35B2
#define	CONFIG_SYS_MSC1_VAL	0x128C128C
#define	CONFIG_SYS_MSC2_VAL	0x236C1281
#define	CONFIG_SYS_MDCNFG_VAL	0x08000AC9
#define	CONFIG_SYS_MDREFR_VAL	0x01018018
#define	CONFIG_SYS_MDMRS_VAL	0x00000000
#define	CONFIG_SYS_FLYCNFG_VAL	0x00000000
#define	CONFIG_SYS_SXCNFG_VAL	0x00000000

/*
 * PCMCIA and CF Interfaces
 */
#define	CONFIG_SYS_MECR_VAL	0x00000000
#define	CONFIG_SYS_MCMEM0_VAL	0x58CC0000
#define	CONFIG_SYS_MCMEM1_VAL	0x00010504
#define	CONFIG_SYS_MCATT0_VAL	0x00000000
#define	CONFIG_SYS_MCATT1_VAL	0x00000000
#define	CONFIG_SYS_MCIO0_VAL	0x00000000
#define	CONFIG_SYS_MCIO1_VAL	0x00000000

/*
 * NAND-FLASH configuration
 */
#define CONFIG_SYS_MAX_NAND_DEVICE      1               /* Max number of NAND devices. */
#define CONFIG_SYS_NAND_BASE            0x08000000      /* Chip Select 2 */

/*
 * MTD & UBI settings
 */
#define CONFIG_RBTREE
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define CONFIG_MTD_DEVICE
#define MTDIDS_DEFAULT          "nand0=NAND Flash partition 1"
#define MTDPARTS_DEFAULT        "mtdparts=NAND Flash partition 1:-(ubifs)"

#include "pxa-common.h"

#endif /* __CONFIG_H */
