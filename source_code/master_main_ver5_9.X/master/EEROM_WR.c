#include "EEROM_WR.h"
#include "operation_CES.h"

CE save_CE;
char game_flag;
void EEROM_W_SAVE(void)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		save_CE.co[i] = state_CE.co[i];
		save_CE.cp[i] = state_CE.cp[i];
	}
	for (i = 0; i < 12; i++)
	{
		save_CE.eo[i] = state_CE.eo[i];
		save_CE.ep[i] = state_CE.ep[i];
	}
	for (i = 0; i < 6; i++)
	{
		save_CE.sp[i] = state_CE.sp[i];
	}

	char WRITE_ADDRESS;

	DATAEE_WriteByte(EEROM_SAVE_FLAG_ADDRESS, 0);
	WRITE_ADDRESS = EEROM_SAVE_START_ADDRESS;
	for (int i = 0; i < 8; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)save_CE.cp[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 8; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)save_CE.co[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)save_CE.ep[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)save_CE.eo[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 6; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)save_CE.sp[i]);
		WRITE_ADDRESS++;
	}
}

void EEROM_R_SAVE(void)
{
	char READ_ADDRESS;
	if (DATAEE_ReadByte(EEROM_SAVE_FLAG_ADDRESS) == 0xFF)
	{
		over_write_CE(deff_CE);
		return;
	}
	READ_ADDRESS = EEROM_SAVE_START_ADDRESS;
	//
	for (int i = 0; i < 8; i++)
	{
		save_CE.cp[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 8; i++)
	{
		save_CE.co[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		save_CE.ep[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		save_CE.eo[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 6; i++)
	{
		save_CE.sp[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
    		over_write_CE(save_CE);

}

void EEROM_WR_ioport(void)
{

	if (DATAEE_ReadByte(EEROM_DEF_FLAG_ADDRESS) == 0xFF)
	{
		over_write_CE(deff_CE);
		//EEROM_W_DEFF();
	}
	else
	{
		EEROM_R_DEFF();
	}

	game_flag = DATAEE_ReadByte(EEROM_GAME_FLAG_ADDRESS);
	if (game_flag == 0xFF)
	{
		game_flag = GAME_FLAG_OFF;
		DATAEE_WriteByte(EEROM_GAME_FLAG_ADDRESS, GAME_FLAG_OFF);
	}
}

/*
	ƒVƒƒƒbƒtƒ‹Œã‚É‘}“ü‚·‚×‚µ
*/
void EEROM_GAME_ON(void)
{
	game_flag = GAME_FLAG_ON;
	DATAEE_WriteByte(EEROM_GAME_FLAG_ADDRESS, GAME_FLAG_ON);
	EEROM_W_SAVE();
}

/*
	Œ³‚É–ß‚Á‚Ä‚©‚ç‘}“ü‚·‚×‚µ
*/
void EEROM_GAME_OFF(void)
{
	game_flag = GAME_FLAG_OFF;
	DATAEE_WriteByte(EEROM_GAME_FLAG_ADDRESS, GAME_FLAG_OFF);
	EEROM_W_SAVE();
}

void EEROM_R_DEFF(void)
{
	char READ_ADDRESS;
	READ_ADDRESS = EEROM_DEF_START_ADDRESS;
	for (int i = 0; i < 8; i++)
	{
		state_CE.cp[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 8; i++)
	{
		state_CE.co[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		state_CE.ep[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		state_CE.eo[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
	for (int i = 0; i < 6; i++)
	{
		state_CE.sp[i] = (unsigned char)DATAEE_ReadByte(READ_ADDRESS);
		READ_ADDRESS++;
	}
}

void EEROM_W_DEFF(void)
{
	char WRITE_ADDRESS;

	DATAEE_WriteByte(EEROM_DEF_FLAG_ADDRESS, 0);
	WRITE_ADDRESS = EEROM_DEF_START_ADDRESS;
	for (int i = 0; i < 8; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)state_CE.cp[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 8; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)state_CE.co[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)state_CE.ep[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 12; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)state_CE.eo[i]);
		WRITE_ADDRESS++;
	}
	for (int i = 0; i < 6; i++)
	{
		DATAEE_WriteByte(WRITE_ADDRESS, (unsigned char)state_CE.sp[i]);
		WRITE_ADDRESS++;
	}
}

void DATAEE_WriteByte(unsigned char bAdd, unsigned char bData)
{
	char GIEBitValue = INTCONbits.GIE;

	EEADR = (unsigned char)(bAdd & 0xFF);
	EEDATA = bData;
	EECON1bits.EEPGD = 0;
	EECON1bits.CFGS = 0;
	EECON1bits.WREN = 1;
	INTCONbits.GIE = 0; // Disable interrupts
	EECON2 = 0x55;
	EECON2 = 0xAA;
	EECON1bits.WR = 1;
	// Wait for write to complete
	while (EECON1bits.WR)
	{
	}

	EECON1bits.WREN = 0;
	INTCONbits.GIE = GIEBitValue; // Restore interrupt enable
}

unsigned char DATAEE_ReadByte(unsigned char bAdd)
{
	EEADR = (unsigned char)(bAdd & 0xFF);
	EECON1bits.CFGS = 0;
	EECON1bits.EEPGD = 0;
	EECON1bits.RD = 1;
	NOP(); // NOPs may be required for latency at high frequencies
	NOP();

	return (EEDATA);
}
