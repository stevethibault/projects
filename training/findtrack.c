#include <stdio.h>
#include <string.h>

char tracks[][20] = 
{
	"I left my heart",
	"Newark, Newark",
	"Dancing with it",
	"From here",
	"The Girl",
};

void find_track(char search_for[])
{
	int i;
	for (i = 0; i < 5; i++)
	{ 
		if (strstr(tracks[i], search_for))
		{
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
}

void replace_with_null(const char *string, char c)
{
	char* p_c = strchr(string, c);
	if (p_c)
	{
		*p_c = '\0';
	}
}

int main()
{
	char search_for[20];
	printf("Search for:");
	fgets(search_for, 20, stdin);

	replace_with_null(search_for, '\r');
	replace_with_null(search_for, '\n');

	find_track(search_for);
	return 0;
}
