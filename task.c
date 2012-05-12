#include <stdio.h>

#define MAXBUFFERSIZE 80

int main()
{
	char buffer[MAXBUFFERSIZE];	/* Буффер для команды */
	char c;
	int count;			/* Счетчик символов */
	int exit_flag = 1;

	/*Считываем команды*/
	while(exit_flag)
	{		
		printf("Enter a new command...\n"
			"Type '0' in the end of the command\n");
		c = getchar();
		count = 0;

		while((c != '0') && (count < MAXBUFFERSIZE))
		{
			buffer[count++] = c;
			c = getchar();

		}
		
		buffer[count] = '\0';
		printf("The command u entered was:%s\n", buffer);
		exit_flag = 0;	
	}
}
