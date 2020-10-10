//
// Created by anleeno on 2019/11/24.
//

#include "myfunction.h"

void insert_a_character(char *s) {
    //在字符串的数字前面插$
    int i, j;
    char temp[100];  // 定义一个数组保存转换的字符串
    for (i = 0, j = 0; j < 100 && s[i] != '\0'; i++, j++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp[j] = '$';
            j++;
        }
        temp[j] = s[i];
    }
    temp[j] = '\0';
    for (i = 0; i <= j; i++)
        s[i] = temp[i];   // 再把字符串保存到原数组.
}

double keep_two_decimal_places(double h) {
    //保留两位小数
    return (long) (h * 100 + 0.5) / 100.0;
}

int is_prime(int n) {
    //判断是否是素数
    int i;
    int k = (int) sqrt(n);
    for (i = 2; i <= k; i++) {
        if (n % i == 0) {
            break;
        }
    }
    if (i > k)
        return 1;//是素数返回1
    else
        return 0;//不是素数返回0
}

void Goldbach(int n) {
    //哥德巴赫猜想：任一充分大的偶数，都可以用两个素数之和表示
    int p, q;//两个素数
    if (n < 4 || n % 2 != 0) {//如果不是偶数
        printf("input error!\n");
        exit(-1);//程序结束
    }
    p = 1;
    do {
        p++;
        q = n - p;
    } while (is_prime(p) * is_prime(q) == 0);//当p,q中有一个不为素数时继续循环
    printf("%d=%d+%d\n", n, p, q);
}

double sum_alternate_signs() {
    //计算Π
    int s = 1;
    double n = 1.0, t = 1, pi = 0;
    while (fabs(t) >= 1e-6) {
        pi += t;
        n += 2;
        s = -s;
        t = s / n;
    }
    pi *= 4;
    return pi;
}

void rhombus(int size) {
    //打印菱形
    int star, space;
    if (size <= 0 || size % 2 == 0) {
        printf("the size is error!\n");
        exit(-1);
    }
    for (int i = 1; i <= size; i++) {
        star = (i <= (size + 1) / 2) ? i : size - i + 1;
        star = 2 * star - 1;
        space = (size - star) / 2;
        for (int k = 1; k <= space; k++) {
            printf(" ");
        }
        for (int j = 1; j <= star; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void count_of_capital_letters() {
    //统计每个大写字母数量
    char ch;
    int num[26], i;
    memset(num, 0, 26 * sizeof(int));
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            num[ch - 'A']++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i % 9 == 0)
            printf("\n");
        printf("%c(%d) ", 'A' + i, num[i]);
    }
    printf("\n");
}

#define num 10

void bubble_sort() {
    //i是轮次，j是交换次数，temp是中间变量
    int a[num];
    int i, j, temp;

    //改进后的冒泡排序的标识量
    int flag;

    printf("input %d numbers: \n", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < num; i++) {
        flag = 0;
        for (j = 0; j < num - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
    printf("the sorted numbers:\n");
    for (int k = 0; k < num; ++k) {
        printf("%d ", a[k]);
    }
}

void select_sort() {
    //选择排序
    int a[num];
    int i, j, k, temp;

    printf("input %d numbers: \n", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < num - 1; i++) {
        k = i;//k为当前最小值下标，初始值设为i
        for (j = i + 1; j < num; j++) {//查找比a[k]小的数的下标放入k中
            if (a[k] > a[j]) {//存在比a[k]小的数a[j]
                k = j;//更改最小数的下标值
            }
        }
        if (k != i) {//如果最小数的下标值有更改，将最小数a[k]与a[i]互换
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    printf("the sorted numbers:\n");
    for (k = 0; k < num; ++k) {
        printf("%d ", a[k]);
    }
}

void hanoi(int n, char a, char b, char c) {
    //n是盘子数，a是源柱子，b是临时柱子，c是目标柱子
    if (n == 1) {//一个就直接移动到目标柱子
        hanoi_move(a, c);
    } else {
        //分解为规模更小的问题，假设有两个盘子，那么第一步要把源柱子A的盘子移动到临时柱子B上，
        //此时B应该在目标位置，然后把底座盘子从A移动到C上，接下来就应该是B移动到C上，B作为源柱子，C作为目标柱子。
        hanoi(n - 1, a, c, b);
        hanoi_move(a, c);
        hanoi(n - 1, b, a, c);
    }
}

void hanoi_move(char x, char y) {
    printf("%c----->%c\n", x, y);
}

void char_reverse() {
    //字符串反转
    char *p, *q, str[20], ch;

    gets(str);
    p = str;//首地址
    q = p + strlen(str) - 1;//末地址

    while (p < q) {
        ch = *p;
        *p++ = *q;
        *q-- = ch;
    }

    printf("%s\n", str);
}

//比较字符串长度，输出较长的字符串
char *str_cmp(char *pstr1, char *pstr2) {
    int i, j;

    for (i = 0; pstr1[i] != '\0'; i++);
    for (j = 0; pstr2[j] != '\0'; j++);

    if (i >= j)
        return pstr1;
    else
        return pstr2;
}

//除去字符串中的某个字符
char *remove_char_from_str(char s[], char c) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            for (j = i; s[j] != '\0'; j++) {
                s[j] = s[j + 1];
            }
        }
    }
    return s;
}

//数组元素逆序
int *array_reverse(int *a, int n) {
    int *pstart, *pend, temp = 0;//数组起始地址,数组末尾地址,中间变量
    for (pstart = a, pend = a + n - 1; pstart < pend; pstart++, pend--) {
        temp = *pstart;
        *pstart = *pend;
        *pend = temp;
    }
    return a;
}

//八进制转十进制
void octalToDecimal(){
    char *p,s[6];int n;
    p=s;
    gets(p);
    n=0;
    while(*(p)!='\0')
        {n=n*8+*p-'0';
        p++;
    }
    printf("%d",n);
}

//循环右移三位
void rightloop(char *a, int n){
    char b[100];      //数组b要做的够大即可//
    int m;
    m=strlen(a)-n;               //求出除去要循环右移之后剩下的字符的个数//
    strcpy(b,a+n);             // a+n，a代表a[0]的地址再加上n，表示要把a[n]之后的字符串（即那些不用循环右移的字符，共有m个）复制到数组b中。这时b[]="defghijk"。 //
    strcpy(b+m,a);                  // b+m, 因为上面已经把没有循环的m个字符赋给了b，所以b[m]之前的不能在赋值了，只能把a的全部字符串赋给b[m]之后的空间了。这时b[]="defghijkabcdefghijk"。//
    *(b+strlen(a))='/0';               //这里是问题的关键，要根据a字符串的长度来舍弃b数组中多余的字符串，并给数 组b加结束符。这时b[]="defghijkabc";//
    strcpy(a,b);                                 //把数组b中调整好的字符串重新赋给数组a。//
}