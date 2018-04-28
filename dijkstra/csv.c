#include <stdio.h>

int csvscanf(FILE* csv, char champ[])
{
    char tmp='a', delimiteur=',';
    int i=0;

    while ((tmp!= '\n') && (tmp != delimiteur) && (tmp != EOF))
    {
        if (fscanf(csv, "%c", &tmp)!=EOF)
        {
            champ[i]=tmp;
        }
        else
        {
            tmp=EOF;
        }
        i ++;
    }

    champ[i-1]='\0';
	//printf("\n%s", champ);
    return tmp;
    
}

