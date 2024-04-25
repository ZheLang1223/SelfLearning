#include <stdio.h>

/*
    写一个日历，功能：
        1. 按照月份展示
        2. 列为星期
    年月日要求：
        1. 大月31天，小月30天，二月28天（平年）/29天（闰年）
        2. 闰年：年份是4的倍数但不是100的倍数，或者是400的倍数
        3. 1970年1月1号是星期四
*/

//月份             1   2   3   4   5   6   7   8   9   10  11  12
int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int t[12] = {0,3,2,5,0,3,5,1,4,6,2,4};
int calculateDayOfWeek(int year, int month, int day) {
    year -= month < 3;
    int dayOfWeek = (year+ year/4 -year/100 + year/400 + t[month-1] + day) % 7;
    /*
        1-Monday; 2-Tuesday; 3-Wednesday...
    */
    return dayOfWeek;
}

/*
    根据年份和月份打印当月日历
*/
void printCalender(int year, int month) {
    printf("*%d/%d*\n", year, month);    // 日历月份
    /* 打印星期，每个占12个字符位置 */
    printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\t\n");


    int fristDay = calculateDayOfWeek(year, month, 1);
    for(int i = 1; i < fristDay; ++i) {
        printf("\t");
    }
    int days = DaysOfMonth[month-1];
    // 如果是闰年2月则加一天
    if(month == 2 && (year%4==0 && year%100!=0 || year%400==0)) {
        days++;
    }

    for(int i = 0; i < days; ++i) {

        printf("%d\t", i+1);  // 日期
        if((fristDay+i-1)%7 == 6) {
            printf("\n");   // 到周天换行
        }
    }

    printf("\n\n");
}

void menu() {
    printf("**查看日历**\n");
    while(1) {
        printf("input the year & month(use the space to separate):\ninput 0 0 to quit>");
        int year, month;
        scanf("%d %d", &year, &month);
        if(year == 0) break;
        printCalender(year, month);
    }

}

int main() {
    menu();
    return 0;
}