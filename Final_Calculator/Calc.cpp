#include"calHead.h"

using namespace std;

int main()
{
    Main_Switch();

    return 0;
}

void face()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n\n\n");
    printf("\t\t\t╔════════════════════════════════════════════════════════════╗\n");
    printf("\t\t\t║        ______      __           __      __                 ║\n");
    printf("\t\t\t║       / ____/___ _/ /______  __/ /___ _/ /_____  _____     ║\n");
    printf("\t\t\t║      / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/     ║\n");
    printf("\t\t\t║     / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /         ║\n");
    printf("\t\t\t║     \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/          ║\n");
    printf("\t\t\t║                                                            ║\n");
    printf("\t\t\t╚════════════════════════════════════════════════════════════╝\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\t\t\t\t    1.进入计算\t\t\t2.使用说明\n\n");
    printf("\t\t\t\t    3.开发信息\t\t\t0.退出程序\n\n");

}

void CalFace()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n\n\n");
    printf("\t\t\t╔════════════════════════════════════════════════════════════╗\n");
    printf("\t\t\t║        ______      __           __      __                 ║\n");
    printf("\t\t\t║       / ____/___ _/ /______  __/ /___ _/ /_____  _____     ║\n");
    printf("\t\t\t║      / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/     ║\n");
    printf("\t\t\t║     / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /         ║\n");
    printf("\t\t\t║     \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/          ║\n");
    printf("\t\t\t║                                                            ║\n");
    printf("\t\t\t╚════════════════════════════════════════════════════════════╝\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Main_Switch()//主菜单
{
    int flag = 1;//循环条件
    int ch;
    while (flag)
    {
        face();
        ch = _getch() - 48;//int类型用_getch()得到的值比键入的真实值大48
        switch (ch)
        {
        case 1:Cal(); break;//进入计算
        case 2:state(); break;
        case 3:info(); break;
        case 0:flag = 0; break;//退出循环
        default:break;
        }
    }
}

void Cal()
{
    char inputStr[MAXSIZE_OF_EQUATION];
    while (true)
    {
        CalFace();
        cout << "\n请输入表达式:";
        cin.getline(inputStr, MAXSIZE_OF_EQUATION, '\n');//用户输入
        if (isComputable(inputStr))
        {
            cout << "\n计算结果为:" << compute(inputStr) << endl;
        }
        else
        {
            cout << "用户输入错误，请重新输入\n" << endl;
            system("pause");
            break;
        }


        memset(inputStr, 0, sizeof(char));  //把原本的inputStr给清空
        cout << "按任意键继续\n输入q按敲回车键结束计算" << endl;
        if (getchar() == 'q') { break; }//暂停，等待用户输入
    }
}



void state()
{
    system("CLS");

    printf("\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t\t\t\t使用说明\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t 1.本计算器可以计算加(+)、减(-)、乘(*)、除(/)、求模（%） 、开方(&)和乘方(^) 运算，并能使用括号，用户输入时，请以“=”结尾\n\n\n");
    printf("\t\t 2.计算表达式请勿过长，表达式过长或计算的数据数值过大可能引起精度丢失甚至程序崩溃\n\n\n");
    printf("\t\t 3.请输入正确的表达式，若输入有误，可能会引起程序出现错误\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | COMMON_LVB_UNDERSCORE);
    printf("\t\t 4.如果程序崩溃，请及时关闭程序避免占用过多内存空间引起电脑死机\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t\t\t\t\t\t\t\t2021.10.26\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("pause");
}

void info()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n\n\t\t  【其实是联系方式】\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t  开发环境：Visual Studio 2019 / win10\n\n\n");
    printf("\t\t  Email：diiiiii_9@126.com\n");
    printf("\n\n\n\n");
    system("pause");
}