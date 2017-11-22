#include <stdio.h>


// 汉诺塔

/**
对于游戏的玩法，我们可以简单分解为三个步骤
将前63个盘子从X移动到Y上。
将最底下的第64个盘子从X移动到Z上。
将Y上的63个盘子移动到Z上。

问题一：将X上的63个盘子借助Z移到Y上。

问题二：将Y上的63个盘子借助X移到Z上。



问题一（“将X上的63个盘子借助Z移到Y上”）拆解为：
将前62个盘子从X移动到Z上。
将最底下的第63个盘子移动到Y上。
将Z上的62个盘子移动到Y上。

问题二（“将Y上的63个盘子借助X移到Z上”）拆解为：
将前62个盘子从Y移动到X上。
将最底下的第63个盘子移动到Z上。
将X上的62个盘子移动到Y上。
*/

void hanoi(int, char, char, char);

void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("%c --> %c\n", x, z);
    }
    else
    {
        hanoi(n-1, x, z, y);
        printf("%c --> %c\n", x, z);
        hanoi(n-1, y, x, z);
    }
}

int main(void)
{
    int n;
    
    printf("输入汉诺塔的层数:\n");
    scanf("%d", &n);
    
    hanoi(n, 'X', 'Y', 'Z');
    
    return 0;
}
