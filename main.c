//
// Created by anleeno on 2019/9/27.
//
#include "myfunction.h"
#include "linklist.h"

#define GET_TYPE(expr) \
    _Generic(expr, double: "double", float: "float", \
                   signed char: "schar", unsigned char: "uchar", \
                   int:"int", unsigned int: "uint",\
                   long: "long", unsigned long: "ulong", \
                   default: "unknown")

void test(void) {
    printf("%s\n", GET_TYPE(8 / 4 * (int) 2.5 / (int) (1.25 * (3.7 + 2.3))));
}

void fun() {
    //求四个数字的三位数组合
    int a[4] = {1, 3, 5, 7};
    int j, k, t;
    int num = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
            for (t = 0; t < 4; t++) {
                if ((a[j] != a[k]) && (a[j] != a[t]) && (a[k] != a[t])) {
                    num = a[j] * 100 + a[k] * 10 + a[t];
                    printf("%d\n", num);
                }
            }
        }
    }
}

void fun1(){
    //求文件数据的平均值
    FILE *fp;
    double sum = 0, avg, *arr;
    int n, i;
    if ((fp = fopen("G:\\test.txt", "rt")) == NULL)//打开桌面的文件
    {
        printf("Can't open the file ");
        exit(0);
    }
    fscanf(fp, "%d", &n);//读取文件
    printf("%d\n", n);
    arr = (double *) malloc(n * sizeof(double));//分配动态数组
    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf", &arr[i]);
        printf("%lf\n",arr[i]);
        sum += arr[i];
    } //计算数组数值总和
    avg = sum / n;
    printf("%lf", avg);//打印平均值
    free(arr);//释放数值
    fclose(fp);//关闭文件
}

int main() {
    int n;
    printf("input the number of dishes:\n");
    scanf("%d", &n);
    printf("the step to move %d dishes:\n", n);
    hanoi(n, 'A', 'B', 'C');

    /*Node *head, *pnew;
    int i, j, score;
    head = create_Linklist();
    printf("after create:\n");
    display_Linklist(head);

    printf("input the location you want to insert:\n");
    scanf("%d", &i);

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) {
        printf("no enough memory!\n");
        return;
    }

    printf("input the score you want to insert:\n");
    scanf("%d", &score);
    pnew->score = score;
    insert_Linklist(head, pnew, i);

    printf("after insert:\n");
    display_Linklist(head);

    printf("input the location you want to delete:\n");
    scanf("%d", &j);
    delete_Linklist(head, j);
    printf("after delete:\n");
    display_Linklist(head);

    free_Linklist(head);*/

}

