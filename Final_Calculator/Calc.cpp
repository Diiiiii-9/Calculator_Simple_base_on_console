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
    printf("\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("\t\t\t�U        ______      __           __      __                 �U\n");
    printf("\t\t\t�U       / ____/___ _/ /______  __/ /___ _/ /_____  _____     �U\n");
    printf("\t\t\t�U      / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/     �U\n");
    printf("\t\t\t�U     / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /         �U\n");
    printf("\t\t\t�U     \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/          �U\n");
    printf("\t\t\t�U                                                            �U\n");
    printf("\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\t\t\t\t    1.�������\t\t\t2.ʹ��˵��\n\n");
    printf("\t\t\t\t    3.������Ϣ\t\t\t0.�˳�����\n\n");

}

void CalFace()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\n\n\n");
    printf("\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("\t\t\t�U        ______      __           __      __                 �U\n");
    printf("\t\t\t�U       / ____/___ _/ /______  __/ /___ _/ /_____  _____     �U\n");
    printf("\t\t\t�U      / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/     �U\n");
    printf("\t\t\t�U     / /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /         �U\n");
    printf("\t\t\t�U     \\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/          �U\n");
    printf("\t\t\t�U                                                            �U\n");
    printf("\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Main_Switch()//���˵�
{
    int flag = 1;//ѭ������
    int ch;
    while (flag)
    {
        face();
        ch = _getch() - 48;//int������_getch()�õ���ֵ�ȼ������ʵֵ��48
        switch (ch)
        {
        case 1:Cal(); break;//�������
        case 2:state(); break;
        case 3:info(); break;
        case 0:flag = 0; break;//�˳�ѭ��
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
        cout << "\n��������ʽ:";
        cin.getline(inputStr, MAXSIZE_OF_EQUATION, '\n');//�û�����
        if (isComputable(inputStr))
        {
            cout << "\n������Ϊ:" << compute(inputStr) << endl;
        }
        else
        {
            cout << "�û������������������\n" << endl;
            system("pause");
            break;
        }


        memset(inputStr, 0, sizeof(char));  //��ԭ����inputStr�����
        cout << "�����������\n����q���ûس�����������" << endl;
        if (getchar() == 'q') { break; }//��ͣ���ȴ��û�����
    }
}



void state()
{
    system("CLS");

    printf("\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t\t\t\tʹ��˵��\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t 1.�����������Լ����(+)����(-)����(*)����(/)����ģ��%�� ������(&)�ͳ˷�(^) ���㣬����ʹ�����ţ��û�����ʱ�����ԡ�=����β\n\n\n");
    printf("\t\t 2.������ʽ������������ʽ����������������ֵ����������𾫶ȶ�ʧ�����������\n\n\n");
    printf("\t\t 3.��������ȷ�ı��ʽ�����������󣬿��ܻ����������ִ���\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | COMMON_LVB_UNDERSCORE);
    printf("\t\t 4.�������������뼰ʱ�رճ������ռ�ù����ڴ�ռ������������\n\n\n");
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
    printf("\n\n\t\t  ����ʵ����ϵ��ʽ��\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\t\t  ����������Visual Studio 2019 / win10\n\n\n");
    printf("\t\t  Email��diiiiii_9@126.com\n");
    printf("\n\n\n\n");
    system("pause");
}