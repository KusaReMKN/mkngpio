#include "mkngpio.h"

int ExportGPIO(int nPortNum)
{
	char szPath[] = "/sys/class/gpio/export";
	char value[16] = {0};
	int fd;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if ((fd = open(szPath, O_WRONLY)) == -1)
	{
		return -2;
	}
	sprintf(value, "%d", nPortNum);
	write(fd, value, strlen(value));
	close(fd);

	return 0;
}

int UnexportGPIO(int nPortNum)
{
	char szPath[] = "/sys/class/gpio/unexport";
	char value[16] = {0};
	int fd;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if ((fd = open(szPath, O_WRONLY)) == -1)
	{
		return -2;
	}
	sprintf(value, "%d", nPortNum);
	write(fd, value, strlen(value));
	close(fd);

	return 0;
}

int SetGPIODirection(int nPortNum, int nInOut)
{
	char szPath[1024] = {0};
	char value[16] = {0};
	int fd;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	if (nInOut != IN && nInOut != OUT)
	{
		return -3;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/direction", nPortNum);

	if ((fd = open(szPath, O_WRONLY)) == -1)
	{
		return -4;
	}
	sprintf(value, "%s", nInOut ? "out" : "in");
	write(fd, value, strlen(value));
	close(fd);

	return 0;
}

int WriteGPIO(int nPortNum, int nValue)
{
	char szPath[1024] = {0};
	char value[16] = {0};
	int fd;

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/value", nPortNum);

	if ((fd = open(szPath, O_WRONLY)) == -1)
	{
		return -5;
	}
	sprintf(value, "%d", !!nValue);
	write(fd, value, strlen(value));
	close(fd);

	return 0;
}

int ReadGPIO(int nPortNum)
{
	char szPath[1024] = {0};
	int fd;
	char value[16] = {0};

	if (nPortNum < 0 || 27 < nPortNum)
	{
		return -1;
	}

	sprintf(szPath, "/sys/class/gpio/gpio%d/value", nPortNum);

	if ((fd = open(szPath, O_RDONLY)) == -1)
	{
		return -5;
	}
	read(fd, value, 1);
	close(fd);

	return !(value[0] == '0');
}
