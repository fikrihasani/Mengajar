#include <stdio.h>

struct numberObject {
	int index;
	int number;
};

int main() {
	numberObject TN, NA[100000];
	int FC = 0, C;
	FILE *FP = fopen("items.txt", "r");
	
	if (!FP)
	{
		printf("Error: items.txt does not exist in the directory.\n'");
		return -1;
	}
	
	for (int I1 = 0; I1 < 100000; I1++)
	{
		fscanf(FP, "%d", &NA[I1].number);
		NA[I1].index = I1;
	}
	
	// Prompt for input
	printf("Enter a count number and the keyword number(s) to search items in the list. Example format: 1 1 OR 3 1 2 3\n");
	printf("Input: ");
	scanf("%d", &C);
	int KA[C];
	for (int I2 = 0; I2 < C; I2++)
	{
		scanf("%d", &KA[I2]);
	}
	printf("\n");
	
	for (int I3 = 0; I3 < C; I3++)
	{
		FC = 0;
		for (int I4 = 0; I4 < 100000; I4++)
		{
			if (KA[I3] == NA[I4].number)
			{
				printf("Keyword '%d' is located at the index of %d.\n", KA[I3], NA[I4].index);
				FC++;
				break;
			}
		}
		if (FC == 0)
		{
			printf("No keyword of '%d' has been found in the list.\n", KA[I3]);
		}
	}
	
	return 0;
}