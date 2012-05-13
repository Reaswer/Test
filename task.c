#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFFERSIZE 80

/* Функция выделяет первое слово, остальные слова помещает в массив.
   На основании выделенного слова вызывается соответсвующая функция,
   если такой нет выдаётся ошибка */
void parsing_command(char *command);
void add(char *p[], int number);

int main()
{
	char buffer[MAXBUFFERSIZE];	/* Буффер для команды */
	char c;
	int count;			/* Счетчик символов */
	int exit_flag = 1;

	/*Считываем команды*/
	while(exit_flag)
	{		
		char *buf = (char*)malloc(MAXBUFFERSIZE);

		printf("Enter a new command...\n"
			"Type '0' in the end of the command\n");
		c = getchar();
		count = 0;

		while((c != '0') && (count < MAXBUFFERSIZE))
		{
			buf[count++] = c;
			c = getchar();

		}
		
		buf[count] = '\0';
		printf("The command u entered was:%s\n", buf);
		parsing_command(buf);
		//exit_flag = 0;
		free(buf);	
	}
}

void parsing_command(char *command)
{
	printf("Parsing=%s\n", command);
	char com[MAXBUFFERSIZE];
	
	int count=0;
	
	/* Вырезаем первое слово до пробела */
	while(*command != ' ')
	{
		com[count++] = *command;
		command++;
	}
	command++;
	com[count]='\0';
	//printf("First word=%s\n", com);
	
	char *start = command; //Сохраним указатель на начале параметров
	
	/* Посчитаем количество параметров */
	int w = 0; //Количество пробелов
	while(*command != '\0')
	{
		if(*command == ' ') w++;
		command++;
	}w++;	
	
	char *param[w]; //Массив для параметров
	int l = 0;
	int p = 0;
	printf("Number of words = %d\n", w);

	for(int i=0; i<w; i++)
	{
		param[i] = start;
		do
		{
			start++;
			if(*start == '\0') goto end;
		}while (*start != ' ');	
		
		*start = '\0';
		start++;
	}
end:
	/* Вызываем нужную функцию */	
	if(strcmp(com, "add")==0)
	{
		add(param, w);
	}
	else
	{
		printf("Error: No command found.\n");
	}
	

}

void add(char *p[], int number)
{
	printf("Add function.\n");
	printf("Parametrs are:\n");
	for(int i=0; i<number; i++)
		printf("-%s\n", p[i]);
}
