#include"copyfile.h"
int copyfile(char *SRCfile, char *targrtfile)
{
	FILE *Src = NULL;
	FILE *Target = NULL;
	char Buf[1024]; 
	unsigned int stlen,talen;
	int RE=0;
	Src = fopen(SRCfile, "rb");
	Target = fopen(targrtfile, "wb");
	if (SRCfile == NULL&&targrtfile == NULL) return 1;
	if (Src == NULL) return 2;
	if (Target == NULL) return 3;
	while (!feof(Src))
	{
		memset(Buf, '\0', 1024);
		stlen=fread(Buf, 1, sizeof(Buf), Src);
		if (stlen < sizeof(Buf)) RE= 4;
		talen=fwrite(Buf, 1, strlen(Buf), Target);
		if (talen < strlen(Buf)) RE= 5;
	}
	fclose(Src);
	fclose(Target);
	return RE;
}