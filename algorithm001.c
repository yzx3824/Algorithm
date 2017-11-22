#include <stdio.h>
#include <string.h>

// 查找文件中单词的个数
int main(void)
{
    char filename[20];// 文件名
    char hit[5];
    int count = 0; // 统计结果
    printf("%s\n", filename);
    printf("%s\n", hit);
    
    strcpy(&filename[0], "algorithm001.dat");
    strcpy(&hit[0], "HIT");
    
    printf("%s\n", filename);
    printf("%s\n", hit);
    
    int i, j;
    int over = 0; // 文件是否读取完毕标识
    int flag = 0; // 是否匹配到的标志
    // int len = 2048;
    int len = 20;
    int max, readed;
    char buf[10000];
    int k = 1;
    
    FILE *fd;
    
    if ((fd = fopen(&filename[0], "rb")) == NULL)
    {
        printf("Error : Can not open file %s\n",&filename[0]);
    }
    
    while (over != 1)
    {
        readed = fread(&buf[0], 1, len, fd);
        printf("readed:%d\n", readed);
        if (readed < len)   // 读到文件末尾
        {
            over = 1;
            max = readed;
        }
        else
        {
            max = len;
        }
        printf("max:%d\n", max);
        
        for (i = 0; i < max-1; i++)
        {
            printf("%d %c outer loop\n", i, buf[i]);
            for (j = 0; j < 3; j++)
            {
                if (hit[j] != buf[i + j])
                {
                    flag = 0;      // 一旦有一个不相同就退出并且标志为0
                    break;
                }
                else
                {
                    flag = 1;      // 一个相同为1，如果连续都相同最后结果定是1
                }
            }
            printf("%d %c outer loop2\n", i, buf[i]);
            if (flag == 1)
            {
                count++;
                i += j - 1;
                printf("match:count:%d,i:%d,j:%d\n", count, i, j);
            }
            else
            {
                if (j == 0)
                {
                    i += j;
                }
                else
                {
                    i += j - 1;
                }
                printf("not match:count:%d,i:%d,j:%d\n", count, i, j);
            }
        }
        //把最后两个字符转移到前面两个字节以防止切断搜索串.
        // buf[0]=buf[max];
        // buf[1]=buf[max+1];
        
        printf("while loop read %d times\n", k++);
    }
    
    fclose(fd);
    
    printf("count:%d\n", count);
    
    return 0;
}
