#include <stdio.h>

void main()
{
    //伤害、伤害的增加值、攻击距离
    //
    double attach = 90.18;      //伤害值
    double attachAdd = 4.5;     //伤害增加值
    int attachRange = 172;      //攻击距离


    printf("名称：德玛西亚之力·盖伦\n");
    printf("伤害：%.2lf(+%.1lf)\t攻击距离：%d\n", attach, attachAdd, attachRange);
    printf("护甲：27.536(+3.0)\t魔    抗：32.1(+1.25)\n");
    printf("生命：616.28(+84.25)\t生命回复：7.84(+0.5)\n");
    printf("法力：0.0(+0.0)\t\t法力回复：0.0(+0.0)\n");
    printf("移速：340\t\t定    位：上单 辅助 打野\n");
    printf("点券：450\t\t金币：1000\n");

}
