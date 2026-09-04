#include <stdio.h>

void WriteVersion()
{
#ifndef __WIN32__
	FILE* fp = fopen("ver.txt", "w");

	if (fp)
	{
		fprintf(fp, "Game Core Version: %s\n", __SVN_VERSION__);
		fclose(fp);
	}
#endif
}

