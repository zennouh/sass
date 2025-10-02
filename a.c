#include <stdio.h>
#include <string.h>

int main()
{







    return 0;
    char t1[] = "world";
    char t2[] = "wo.rld";

    int t1Len = strlen(t1);
    int t2Len = strlen(t2);

    int min = t1Len < t2Len ? t1Len : t2Len;
    int isSame = 1;
    for (int i = 0; i < min; i++)
    {
        if (t1[i] != t2[i])
        {
            isSame = 0;
            break;
        }
    }

    if (!isSame)
    {
        printf("Not Same\n");
    }
    else
    {
        printf("Same\n");
    }

    return 0;
    char t[] = "helloh";
    int displayCount = 0;

    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 6; j++)
        {
            if (i > j)
            {
                if (t[i] == t[j])
                {
                    break;
                }
            }
            else
            {
                if (t[i] == t[j])
                {
                    displayCount++;
                }
            }
        }
        if (displayCount != 0)
        {
            printf("%c: %d\n", t[i], displayCount);
        }
        displayCount = 0;
    }

    return 0;
}
