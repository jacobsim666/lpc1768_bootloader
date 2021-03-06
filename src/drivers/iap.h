#ifndef _IAP_H_
#define _IAP_H_
#include "common.h"

extern const uint32 sector_start_map[];
extern const uint32 sector_end_map[];
extern const uint32 crp;


#define CRP1  	0x12345678
#define CRP2  	0x87654321
#define CRP3  	0x43218765
#define NOCRP 	0x11223344

#define CRP 	NOCRP
#define IAP_FCCLK            (96000)
#define IAP_ADDRESS		0x1FFF1FF1	//IAP��ڵ�ַ


typedef enum{
	PREPARE_SECTOR_FOR_WRITE	=50,
	COPY_RAM_TO_FLASH			=51,
	ERASE_SECTOR				=52,
	BLANK_CHECK_SECTOR			=53,
	READ_PART_ID				=54,
	READ_BOOT_VER				=55,
	COMPARE						=56,
	REINVOKE_ISP				=57
}IAP_Command_Code;



#define FLASH_BUF_SIZE 		256

#define	IAP_BUF_LENGTH		(4096UL)


#define CMD_SUCCESS 0
#define 	INVALID_COMMAND	1
#define 	SRC_ADDR_ERROR	2
#define 	DST_ADDR_ERROR	3
#define 	SRC_ADDR_NOT_MAPPED		4

#define 	DST_ADDR_NOT_MAPPED	5


#define 	COUNT_ERROR	6


#define 	INVALID_SECTOR	7


#define 	SECTOR_NOT_BLANK	8
#define 	SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION	9
	
#define 	COMPARE_ERROR	10


#define 	BUSY		11


#define USER_START_SECTOR 	8
#define MAX_USER_SECTOR 	29
#define USER_FLASH_START 	(sector_start_map[USER_START_SECTOR])
#define USER_FLASH_END	 	(sector_end_map[MAX_USER_SECTOR])
#define USER_FLASH_SIZE  	((USER_FLASH_END - USER_FLASH_START) + 1)
#define MAX_FLASH_SECTOR 	30



/* Define start address of each Flash sector */
#define SECTOR_0_START      0x00000000
#define SECTOR_1_START      0x00001000
#define SECTOR_2_START      0x00002000
#define SECTOR_3_START      0x00003000
#define SECTOR_4_START      0x00004000
#define SECTOR_5_START      0x00005000
#define SECTOR_6_START      0x00006000
#define SECTOR_7_START      0x00007000
#define SECTOR_8_START      0x00008000
#define SECTOR_9_START      0x00009000
#define SECTOR_10_START     0x0000A000
#define SECTOR_11_START     0x0000B000
#define SECTOR_12_START     0x0000C000
#define SECTOR_13_START     0x0000D000
#define SECTOR_14_START     0x0000E000
#define SECTOR_15_START     0x0000F000
#define SECTOR_16_START     0x00010000
#define SECTOR_17_START     0x00018000
#define SECTOR_18_START     0x00020000
#define SECTOR_19_START     0x00028000
#define SECTOR_20_START     0x00030000
#define SECTOR_21_START     0x00038000
#define SECTOR_22_START     0x00040000
#define SECTOR_23_START     0x00048000
#define SECTOR_24_START     0x00050000
#define SECTOR_25_START     0x00058000
#define SECTOR_26_START     0x00060000
#define SECTOR_27_START     0x00068000
#define SECTOR_28_START     0x00070000
#define SECTOR_29_START     0x00078000



/* Define end address of each Flash sector */
#define SECTOR_0_END        0x00000FFF
#define SECTOR_1_END        0x00001FFF
#define SECTOR_2_END        0x00002FFF
#define SECTOR_3_END        0x00003FFF
#define SECTOR_4_END        0x00004FFF
#define SECTOR_5_END        0x00005FFF
#define SECTOR_6_END        0x00006FFF
#define SECTOR_7_END        0x00007FFF
#define SECTOR_8_END        0x00008FFF
#define SECTOR_9_END        0x00009FFF
#define SECTOR_10_END       0x0000AFFF
#define SECTOR_11_END       0x0000BFFF
#define SECTOR_12_END       0x0000CFFF
#define SECTOR_13_END       0x0000DFFF
#define SECTOR_14_END       0x0000EFFF
#define SECTOR_15_END       0x0000FFFF
#define SECTOR_16_END       0x00017FFF
#define SECTOR_17_END       0x0001FFFF
#define SECTOR_18_END       0x00027FFF
#define SECTOR_19_END       0x0002FFFF
#define SECTOR_20_END       0x00037FFF
#define SECTOR_21_END       0x0003FFFF
#define SECTOR_22_END       0x00047FFF
#define SECTOR_23_END       0x0004FFFF
#define SECTOR_24_END       0x00057FFF
#define SECTOR_25_END       0x0005FFFF
#define SECTOR_26_END       0x00067FFF
#define SECTOR_27_END       0x0006FFFF
#define SECTOR_28_END       0x00077FFF
#define SECTOR_29_END       0x0007FFFF



extern uint32 result_table[5];

void IAP_prepare_sector(uint32 start_sector,uint32 end_sector);
void IAP_erase_sector(uint32 start_sector,uint32 end_sector);

uint32 IAP_write_flash(uint32 * dst, uint8 * src, uint32 no_of_bytes);
void IAP_execute_user_code(void);
#endif
