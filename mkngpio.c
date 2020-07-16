#include "mkngpio.h"

int ExportGPIO(int nPortNum)
{
	char szPath[] = "/sys/class/gpio/export";
	FILE *fp;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if ((fp = fopen(szPath, "w")) == NULL)
	{
		return -2;
	}
	fprintf(fp, "%d", nPortNum);
	fclose(fp);

	return 0;
}

int UnexportGPIO(int nPortNum)
{
	char szPath[] = "/sys/class/gpio/unexport";
	FILE *fp;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if ((fp = fopen(szPath, "w")) == NULL)
	{
		return -2;
	}
	fprintf(fp, "%d", nPortNum);
	fclose(fp);

	return 0;
}

int SetGPIODirection(int nPortNum, int nInOut)
{
	char szPath[1024] = {0};
	FILE *fp;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if (nInOut != IN && nInOut != OUT)
	{
		return -3;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/direction", nPortNum);

	if ((fp = fopen(szPath, "w")) == NULL)
	{
		return -4;
	}
	fprintf(fp, "%s", nInOut ? "out" : "in");
	fclose(fp);
}

int WriteGPIO(int nPortNum, int nValue)
{
	char szPath[1024] = {0};
	FILE *fp;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/value", nPortNum);

	if ((fp = fopen(szPath, "w")) == NULL)
	{
		return -5;
	}
	fprintf(fp, "%d", !!nValue);
	fclose(fp);
}

int ReadGPIO(int nPortNum)
{
	char szPath[1024] = {0};
	FILE *fp;
	int c;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/value", nPortNum);

	if ((fp = fopen(szPath, "r")) == NULL)
	{
		return -5;
	}
	c = getc(fp);
	fclose(fp);

	return !(c == '0');
}
