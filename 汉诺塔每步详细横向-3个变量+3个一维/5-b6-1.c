// 2253209 信07 刘佳朋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int qszzz, zjzzz, mbzzz, qszz[10], zjzz[10], mbzz[10], a = 1;
void hannuo(int n, char qsz, char zjz ,char mbz,char x,char y,char z)
{
    if (n == 1)
    {
        printf("第%4d 步(%2d): %c-->%c", a, n, qsz, mbz);
        if (qsz == x && mbz == z)
        {
            qszzz--;
            int temp;
            temp = qszz[qszzz];
            qszz[qszzz] = 0;
            mbzz[mbzzz] = temp;
            mbzzz++;
        }
        else if (qsz == x && mbz == y)
        {
            qszzz--;
            int temp;
            temp = qszz[qszzz];
            qszz[qszzz] = 0;
            zjzz[zjzzz] = temp;
            zjzzz++;
        }
        else if (qsz == y && mbz == x)
        {
            zjzzz--;
            int temp;
            temp = zjzz[zjzzz];
            zjzz[zjzzz] = 0;
            qszz[qszzz] = temp;
            qszzz++;
        }
        else if (qsz == y && mbz == z)
        {
            zjzzz--;
            int temp;
            temp = zjzz[zjzzz];
            zjzz[zjzzz] = 0;
            mbzz[mbzzz] = temp;
            mbzzz++;
        }
        else if (qsz == z && mbz == x)
        {
            mbzzz--;
            int temp;
            temp = mbzz[mbzzz];
            mbzz[mbzzz] = 0;
            qszz[qszzz] = temp;
            qszzz++;
        }
        else
        {
            mbzzz--;
            int temp;
            temp = mbzz[mbzzz];
            mbzz[mbzzz] = 0;
            zjzz[zjzzz] = temp;
            zjzzz++;
        }
        if (x == 'A'&&y=='B')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'A' && y == 'C')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'B' && y == 'A')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'B' && y == 'C')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'C' && y == 'A')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
        a++;
    }
    else
    {
        hannuo(n - 1, qsz, mbz, zjz,x,y,z);
        printf("第%4d 步(%2d): %c-->%c", a, n, qsz, mbz);
        if (qsz == x && mbz == z)
        {
            qszzz--;
            int temp;
            temp = qszz[qszzz];
            qszz[qszzz] = 0;
            mbzz[mbzzz] = temp;
            mbzzz++;
        }
        else if (qsz == x && mbz == y)
        {
            qszzz--;
            int temp;
            temp = qszz[qszzz];
            qszz[qszzz] = 0;
            zjzz[zjzzz] = temp;
            zjzzz++;
        }
        else if (qsz == y && mbz == x)
        {
            zjzzz--;
            int temp;
            temp = zjzz[zjzzz];
            zjzz[zjzzz] = 0;
            qszz[qszzz] = temp;
            qszzz++;
        }
        else if (qsz == y && mbz == z)
        {
            zjzzz--;
            int temp;
            temp = zjzz[zjzzz];
            zjzz[zjzzz] = 0;
            mbzz[mbzzz] = temp;
            mbzzz++;
        }
        else if (qsz == z && mbz == x)
        {
            mbzzz--;
            int temp;
            temp = mbzz[mbzzz];
            mbzz[mbzzz] = 0;
            qszz[qszzz] = temp;
            qszzz++;
        }
        else
        {
            mbzzz--;
            int temp;
            temp = mbzz[mbzzz];
            mbzz[mbzzz] = 0;
            zjzz[zjzzz] = temp;
            zjzzz++;
        }
        if (x == 'A' && y == 'B')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'A' && y == 'C')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'B' && y == 'A')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'B' && y == 'C')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else if (x == 'C' && y == 'A')
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else
        {
            printf(" A:");
            for (int i = 0; i < 10; i++)
            {
                if (mbzz[i] > 0)
                {
                    printf("%2d", mbzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" B:");
            for (int i = 0; i < 10; i++)
            {
                if (zjzz[i] > 0)
                {
                    printf("%2d", zjzz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf(" C:");
            for (int i = 0; i < 10; i++)
            {
                if (qszz[i] > 0)
                {
                    printf("%2d", qszz[i]);
                }
                else
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
        a++;
        hannuo(n - 1, zjz, qsz, mbz,x,y,z);
    }

}
int main()
{
    int n;
    char qsz, zjz, mbz;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        if (scanf("%d", &n)!=1)
        {
            while (getchar() != '\n')
            {
                ;
            }
        }
        else
        {
            while (getchar() != '\n')
            {
                ;
            }
            if (n < 1 || n>10)
            {
                ;
            }
            else
            {
                break;
            }
        }
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &qsz);
        while (getchar() != '\n')
        {
            ;
        }
        if (qsz == 'a' || qsz == 'b' || qsz == 'c')
        {
            qsz = qsz - 32;
            break;
        }
        else if (qsz == 'A' || qsz == 'B' || qsz == 'C')
        {
            break;
        }
        else
        {
            ;
        }
    }
    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &mbz);
        while (getchar() != '\n')
        {
            ;
        }
        if (mbz == 'a' || mbz == 'b' || mbz == 'c')
        {
            mbz = mbz - 32;
        }
        if (mbz != 'A' && mbz != 'B' && mbz != 'C'||mbz==qsz)
        {
            ;
        }
        else
        {
            break;
        }
    }
    if (qsz == 'B' && mbz == 'C' || qsz == 'C' && mbz == 'B')
    {
        zjz = 'A';
    }
    else if (qsz == 'A' && mbz == 'C' || qsz == 'C' && mbz == 'A')
    {
        zjz = 'B';
    }
    else
    {
        zjz = 'C';
    }
    for (int i = 0; i < n; i++)
    {
        qszz[i] = n - i;
    }
    qszzz = n;
    char x=qsz, y=zjz, z=mbz;
    if (x == 'A')
    {
        printf("初始:                A:");
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                printf("%2d", qszz[i]);
            }
            else
            {
                printf("  ");
            }
        }
        printf(" B:                    ");
        printf(" C:\n");
    }
    else if (x == 'B')
    {
        printf("初始:                A:                    ");
        printf(" B:");
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                printf("%2d", qszz[i]);
            }
            else
            {
                printf("  ");
            }
        }
        printf(" C:\n");
    }
    else
    {
        printf("初始:                A:                    ");
        printf(" B:                    ");
        printf(" C:");
        for (int i = 0; i < 10; i++)
        {
            if (qszz[i] > 0)
            {
                printf("%2d", qszz[i]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    hannuo(n, qsz, zjz, mbz,x,y,z);

	return 0;
}