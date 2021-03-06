/*
 * xrick/src/xrick.c
 *
 * Copyright (C) 1998-2002 BigOrno (bigorno@bigorno.net). All rights reserved.
 *
 * The use and distribution terms for this software are contained in the file
 * named README, which can be found in the root of this distribution. By
 * using this software in any fashion, you are agreeing to be bound by the
 * terms of this license.
 *
 * You must not remove this notice, or any other, from this software.
 */

#include "system.h"
#include "game.h"
#include <libgame.h>

void my_putc(char c)
{
	fputc(c, stderr);
}

/*
 * main
 */
int
main(int argc, char *argv[])
{
	libgame_init();
	FILE *fp;
	if ((fp = fopen("xrick_stderr.txt", "w"))) {
		stderr = fp;
		setbuf(fp, NULL);
		//*_diag_putc = my_putc;
	}
	sys_init(argc, argv);
	if (sysarg_args_data)
		data_setpath(sysarg_args_data);
	else
		data_setpath("/fat20a2/hda2/GAME/xrick_data.zip");
	game_run();
	data_closepath();
	sys_shutdown();
	return 0;
}

/* eof */
