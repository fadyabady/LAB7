﻿#include <stdio.h>
#include <stdlib.h>

struct clientData
{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};

int main(void)
{
	FILE *pRead;
    FILE	*pWrite;
	FILE *cfPtr;
	int cnt = 0;
	struct clientData client = { 0,"","",0.0 };
	int a,c,d;
	a = fopen_s(&pRead,"C://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}

	c = fopen_s(&pWrite,"‪C://credit_bin.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d", &client.acctNum);

		fscanf_s(pRead, "%s", client.lastName,16);
		fscanf_s(pRead, "%s",client.firstName,11);
		fscanf_s(pRead, "%1f", &client.balance);

		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum,
			client.lastName, client.firstName, client.balance);
	}


	fclose(pRead);
	fclose(pWrite);
	printf("ACSII,contact\n\n");
	system("pause");

	printf("\nenter,printout:\n");
	if ((d = fopen_s(&cfPtr,"C:\\credit_bin.txt", "rb")) == 1)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);

		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%19.2f\n", client.acctNum,
				client.lastName, client.firstName, client.balance);

			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}

	system("pause");
	return 0;
}