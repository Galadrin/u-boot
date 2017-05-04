#include <common.h>
#include <asm/io.h>
#include <nand.h>
#include <asm/arch/pxa-regs.h>

/* CLE */
#define CLE_ADDR_BIT (1<<2)
/* ALE */
#define ALE_ADDR_BIT (1<<3)

static void hwcontrol (struct mtd_info *mtd, int cmd,unsigned int ctrl)
{
  struct nand_chip *chip = (struct nand_chip *) mtd->priv;

  if (cmd == NAND_CMD_NONE)
		  return;

  if (ctrl & NAND_CLE)
  {
	  writeb(cmd, chip->IO_ADDR_W+ CLE_ADDR_BIT);
  }
  else
  {
	  writeb(cmd, chip->IO_ADDR_W+ ALE_ADDR_BIT);
  }

}
int board_nand_init(struct nand_chip *nand)
{
	nand->chip_delay  = CONFIG_NAND_LT200_DELAY_US;
	nand->ecc.mode = NAND_ECC_SOFT;
	nand->cmd_ctrl = hwcontrol;
	/* Enable writing WP */
	writel(readl(GPCR0) & ~0x00000001, GPCR0);
	writel(readl(GPSR0) | 0x00000001, GPSR0);

	return 0;
}
