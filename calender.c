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
int DaysOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

int calculateDayOfWeek(int year, int month, int day) {
    int dayOfWeek = 0;

    /*
        1-Monday; 2-Tuesday; 3-Wednesday...
    */
    return dayOfWeek;
}

/*
    根据年份和月份打印当月日历
*/
void printCalender(int year, int month) {
    printf("*%d/%d*—————————\n", year, month);    // 日历月份
    /* 打印星期，每个占12个字符位置 */
    printf("Monday\t\tTuesday\t\tWednesday\tThursday\tFriday\t\tSaturday\tSunday\t\t\n");

    int fristDay = calculateDayOfWeek(year, month, 1);
    int days = DaysOfMonth[month-1];
    // 如果是闰年2月则加一天
    if(month == 2 && (year%4==0 && year%100!=0 || year%400==0)) {
        days++;
    }
}

int main() {
    
}