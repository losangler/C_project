#include <stdio.h>
#include <stdlib.h>

extern Hero heros[100];

int main()
{
    printf("%s\n", heros[0].name);
    return 0;
}
