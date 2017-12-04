#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_menu()
{
	int menu;
	printf("¼ı?ÀÚU¾ßú©?±¸¾¢?°ÔÆOÀÓO (¼ı?ÀÚU ¸Â¬AÃß©¬±â¾a)\n");
	printf("***********±Ô¾OÄ¢¡Ë***********\n");
	printf("Strike:¼ı?ÀÚUÀÇC °ªÆ¨?À§¡×Ä¡¢® Á¤¢´´ä¥a\nBall:¼ı?ÀÚUÀÇC °ªÆ¨?¸¸¬¢?Á¤¢´´ä¥a\nOUT: ¸ğ¬©?µÎ? Æ²¡©?¸²¬©?n");
	printf("4ÀÚU¸®¬¢? 0~9»ç?ÀÌI ¼ı?ÀÚU ÀÔO·Â¤A\n");
	printf("Áß©¬º¹¬©?µÈ? ¼ı?ÀÚU ÀÔO·Â¤A ºÒ¬O°¡Æ¢?n");
	printf("5¹øö©?ÀÇC ±â¾aÈ¸¢¬°¡Æ¢?ÁÖO¾î?Áıy´Ï¥I´Ù¥U\n");
	printf("°¢Æ¡?¼ı?ÀÚU¸¦? ¶ç?¾î?¾²ú©?±â¾a·Î¤I ÀÔO·Â¤A\n");
	printf("**************************\n");
	printf("   ³­ø¡?ÀÌIµµì¥?¸¦? ¼±ù¡?ÅÃAÇÏI¼¼ù¨?¿ä¯a\n");
	printf("       1. Easy\n");
	printf("       2. Hard\n");
	printf("**************************\n");
	fflush(stdin); scanf_s("%d", &menu);
	return menu;
}
int check_menu_number(int n)
{
	if ((1 == n) || (n == 2)) return 1;
	else return 0;
}
int easy()
{
	int com[4], user[4];
	int strike = 0, ball = 0, count = 0;
	int s1, s2, s3, s4, b1, b2, b3, b4;
	char x = 'x', o = 'o';
	int i, j;

	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++)
	{
		com[i] = rand() % 10;
		for (j = 0; j < i; j++)
		{
			if (com[i] == com[j])
			{
				i--;
				break;
			}
		}
	}

	do {
	out:
		count++;
		printf("\n¼ı?ÀÚU¸¦? ÀÔO·Â¤AÇÏI¼¼ù¨?¿ä¯a.(%dÈ¸¢¬)\n", count);
		printf("--------------------------\n");
		scanf_s("%d %d %d %d", &user[0], &user[1], &user[2], &user[3]);

		if (user[0] > 9 || user[1] > 9 || user[2] > 9 || user[3] > 9)
		{
			printf("0~9±î¾iÁöoÀÇC ¼ı?ÀÚU¸¸¬¢?ÀÔO·Â¤AÇÏI¼¼ù¨?¿ä¯a.\n"); count--;
			continue;
		}

		for (i = 0; i<4; i++)
			for (j = 0; j < i; j++)
			{
				if (user[i] == user[j])
				{
					printf("Áß©¬º¹¬©?µÈ? ¼ı?ÀÚU´Â¥A »ç?¿ë¯eÇÒO ¼ö? ¾øú©?½À?´Ï¥I´Ù¥U.\n"); count--;
					goto out;
				}
			}

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (com[i] == user[j])
				{
					if (i == j) strike++;
					else ball++;
				}
			}
		}

		if (com[0] == user[0]) s1 = o; else s1 = x;
		if (com[1] == user[1]) s2 = o; else s2 = x;
		if (com[2] == user[2]) s3 = o; else	s3 = x;
		if (com[3] == user[3]) s4 = o; else s4 = x;

		if (user[0] == com[0] || user[0] == com[1] || user[0] == com[2] || user[0] == com[3])
			b1 = o;
		else 	b1 = x;
		if (user[1] == com[0] || user[1] == com[1] || user[1] == com[2] || user[1] == com[3])
			b2 = o;
		else 	b2 = x;
		if (user[2] == com[0] || user[2] == com[1] || user[2] == com[2] || user[2] == com[3])
			b3 = o;
		else 	b3 = x;
		if (user[3] == com[0] || user[3] == com[1] || user[3] == com[2] || user[3] == com[3])
			b4 = o;
		else 	b4 = x;

		if (strike == 4)
		{
			printf("\n!! You WIN !!\n");
			break;
		}

		if (strike == 0 && ball == 0) printf("OUT\n");
		else
		{
			printf("%c %c %c %c Strike\n", s1, s2, s3, s4);
			printf("%c %c %c %c Ball\n", b1, b2, b3, b4);
		}
		strike = 0; ball = 0;

		if (count == 5)
		{
			printf("\n!! You LOSE !!\nÁ¤¢´´ä¥aÀº¨¬ %d%d%d%dÀÔO´Ï¥I´Ù¥U.\n", com[0], com[1], com[2], com[3]);
			break;
		}

	} while (1);

	system("pause");
	return 0;
}
int hard()
{
	int com[4], user[4];
	int strike = 0, ball = 0, count = 0;
	int i, j;

	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++)
	{
		com[i] = rand() % 10;
		for (j = 0; j < i; j++)
		{
			if (com[i] == com[j])
			{
				i--;
				break;
			}
		}
	}

	do {
	out:
		count++;
		printf("\n¼ı?ÀÚU¸¦? ÀÔO·Â¤AÇÏI¼¼ù¨?¿ä¯a.(%dÈ¸¢¬)\n", count);
		printf("--------------------------\n");
		scanf_s("%d %d %d %d", &user[0], &user[1], &user[2], &user[3]);

		if (user[0] > 9 || user[1] > 9 || user[2] > 9 || user[3] > 9)
		{
			printf("0~9±î¾iÁöoÀÇC ¼ı?ÀÚU¸¸¬¢?ÀÔO·Â¤AÇÏI¼¼ù¨?¿ä¯a.\n"); count--;
			continue;
		}
		for (i = 0; i<4; i++)
			for (j = 0; j < i; j++)
			{
				if (user[i] == user[j])
				{
					printf("Áß©¬º¹¬©?µÈ? ¼ı?ÀÚU´Â¥A »ç?¿ë¯eÇÒO ¼ö? ¾øú©?½À?´Ï¥I´Ù¥U.\n"); count--;
					goto out;
				}
			}


		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (com[i] == user[j])
				{
					if (i == j) strike++;
					else ball++;
				}
			}
		}

		if (strike == 0 && ball == 0) printf("OUT\n");
		else printf("%dStrike %dBall\n", strike, ball);
		strike = 0; ball = 0;

		if (strike == 4)
		{
			printf("\n!! You WIN !!\n");
			break;
		}

		if (count == 5)
		{
			printf("\n!! You LOSE !!\nÁ¤¢´´ä¥aÀº¨¬ %d%d%d%dÀÔO´Ï¥I´Ù¥U.\n", com[0], com[1], com[2], com[3]);
			break;
		}

	} while (1);

	system("pause");
	return 0;
}
int main()
{
	int n = print_menu();

	if (check_menu_number(n) == 1)
	{
		if (n == 1) return easy(n);
		if (n == 2) return hard(n);
	}
	else
	{
		printf("´Ù¥U½Ã? ¼±ù¡?ÅÃAÇÏI¼¼ù¨?¿ä¯a.\n");
		return main();
	}

	system("PAUSE");
	return 0;
}
