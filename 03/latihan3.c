#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char *namep;
    int *agep;
} status;
int main()
{
    status Mystatus;
    Mystatus.agep =  malloc(sizeof(int));

    if((Mystatus.agep) == NULL)
    {
        printf("FAIL TO ALLOCATE MEMORY\n");
        return 0;
    }

    *Mystatus.agep = 21;
    printf("Umur = %d\n",*Mystatus.agep);

    Mystatus.namep = malloc(sizeof(char) * 12);
    if((Mystatus.namep) == NULL)
    {
        free(Mystatus.agep);
        printf("FAIL TO ALLOCATE MEMORY\n");
        return 0;
    }

    strncpy(Mystatus.namep,"Farhan Adi", (*Mystatus.agep));
    printf("Nama = %s\n",Mystatus.namep);

    return 0;
}