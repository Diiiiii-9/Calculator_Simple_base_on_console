#include"calHead.h"

using namespace std;

int num_count = 0; //������

/**
* �ҵ�ƥ���������
* @param char* ԭ�ַ����׵�ַ
* @param char* �����ŵ�ַ
* @param int ����ʱ��Ҫ�����������Ÿ�����
* @author SXZ
*/
char* findRightParentheses(char* inputStr, char* left, int skip)
{
    for (char* temp = left + 1; (*temp) != '\0'; temp++)
    {
        if ((*temp) == ')')
        {
            if (!skip)
            {
                return temp;//skipΪ0 ���������ż�Ϊ�ҵ�
            }
            else
            {
                skip--;
            }
        }
        else
        {
            if ((*temp) == '(')
            {
                skip++;
                return findRightParentheses(inputStr, temp, skip);
            }
        }
    }
}

/**
* �淶������ַ����ĸ�ʽ�����а�����ɾȥ�ո�ת��sqrt()Ϊ����ʽ�����ַ���ĩβ����"="
* @param char* ������ַ���
* @return �޸ĺ��ԭ�ַ�����ַ
* @author YZ
*/
char* formatStep0(char* inputStr)
{

    string newStrTemp;
    if (*inputStr == '-')
    {
        newStrTemp.push_back('0');//����������ַ�����-��ͷ ��ǰ����ϲ�����0
    }
    for (char* temp = inputStr; (*temp) != '\0'; temp++)
    {
        if ((*temp) != ' ')
        {
            if ((*temp) == 's') //�����Ƿ���Ҫ�ж��û�����������Ƿ���sqrt��������������s��ͷ�����
            {
                char* tempEndOfSqrt = temp;
                char* tempRight = findRightParentheses(inputStr, temp + 4, 0);
                for (temp = temp + 4; temp <= tempRight; temp++)
                {
                    if ((*temp) != ' ')
                    {
                        newStrTemp.push_back(*temp);
                    }
                }
                newStrTemp += "^(0.5)";
                temp--;//���ﲻ��һ���ٶ�һλ
            }
            else
            {
                newStrTemp.push_back(*temp);
            }
        }
    }
    if (newStrTemp.back() != '=') { newStrTemp.push_back('='); }
    //�û��䲻����=������
    memset(inputStr, 0, sizeof(inputStr));
    strcpy(inputStr, newStrTemp.c_str());

    return inputStr;

}

/**
* �ж��û�������ַ����Ƿ��������
 * @param inputStr ������ַ���
 * @return �������з���true
 * @author TDY
*/
bool isComputable(char* inputStr)
{
    /**
     *check
     * ���Ų��ɶ� �ݹ���
     * /0
     * С�������С���� +1.23.45+
     * ...
     */

    //char* temp;
    //temp = inputStr;
    //if (strlen(inputStr) == 0)
    //    return false;
    //else
    //{
    //    for (int i = 0; i < strlen(inputStr); i++)
    //    {
    //        count_p(temp);
    //        if (*temp == 's' && *(temp + 1) == 'q' && *(temp + 2) == 'r' && *(temp + 3) == 't')
    //        {
    //            temp = (temp + 4);
    //            continue;
    //        }
    //        /*if ((int)*temp < 40 || (int)*temp>57)
    //        {
    //            int m = (int)*temp;
    //            printf("yes1%d\n",m);
    //            return false;
    //        }*/
    //        //if (*temp != '1' && *temp != '2' && *temp != '3' && *temp != '4' && *temp != '5' && *temp != '6' && *temp != '7' && *temp != '8' && *temp != '9' && *temp != '0' && *temp != '^' && *temp != '=' && *temp != '+' && *temp != '-' && *temp != '*' && *temp != '/' && *temp != '(' && *temp != ')')
    //        //{
    //        //    for (int i = 0; i < strlen(inputStr); i++)
    //        //    {

    //        //        printf("\n%c", *temp);
    //        //        temp++;
    //        //    }
    //        //    return false;
    //        //}
    //        /*if ((int)*temp == 44) {
    //            printf("yes2\n");
    //            return false;
    //        }*/
    //        /*if (*temp == '.')
    //        {
    //            char* temp1 = temp;
    //            temp = temp + 1;
    //            for (; *temp != '.'; temp++)
    //            {
    //                if (*temp == '+' || *temp == '-' || *temp == '*' || *temp == '/') { break; }

    //            }
    //            temp = temp1;
    //        }*/
    //        if (*temp == '.')
    //        {
    //            floatbool(temp);
    //            if (floatbool(temp) == false) {
    //                printf("yes3\n");
    //                return false;
    //            }
    //        }
    //        temp++;

    //    }
    //    if (num_count != 0)
    //    {
    //        printf("yes4\n");
    //        printf("num=%d", num_count);
    //        return false;
    //    }
    //}


    return true;
}
//�ж�С����
bool floatbool(char* x)
{
    x = x + 1;
    if (*x == '+' || *x == '-' || *x == '*' || *x == '/')
    {
        return true;
    }
    if (*x == '.')
    {
        return false;
    }
    floatbool(x);
}
//�ж�������

void count_p(char* x)
{
    if (*x == '(')
    {
        num_count = num_count + 1;
    }
    if (*x == ')')
    {
        num_count = num_count - 1;
    }
}

/**
 * @param ch Ҫ�����ȼ����ַ�
 * @param isOutOfStack �Ƿ�Ҫ����ջ�����ȼ�
 * @return ��Ӧ���ȼ�
 * @author CS
*/
int OpCharToPriority(char ch, bool isOutOfStack)
{
    switch (ch)
    {
    case '+': return isOutOfStack ? 2 : 3; break;
    case '-': return isOutOfStack ? 2 : 3; break;
    case '*': return isOutOfStack ? 4 : 5; break;
    case '/': return isOutOfStack ? 4 : 5; break;
    case '%': return isOutOfStack ? 4 : 5; break;
    case '(': return isOutOfStack ? 8 : 1; break;
    case ')': return isOutOfStack ? 1 : 8; break;
    case '^': return isOutOfStack ? 6 : 7; break;
    case '&': return isOutOfStack ? 6 : 7; break;
    case '=': return 0; break;  //LD����Ҫһ��default
    }
}

/**
 * @param chi ջ���ַ�
 * @param cho ջ���ַ�
 * @return
 * 1    ��ջ�����ȼ�����ջ�����ȼ�
 * 0    ��ջ�����ȼ�����ջ�����ȼ�
 * -1   ��ջ�����ȼ�����ջ�����ȼ�
 * @author YZ
*/
int comparePriorityOfOpChar(char chi, char cho)
{
    if (OpCharToPriority(chi, false) < OpCharToPriority(cho, true))
        return 1;
    else
    {
        if (OpCharToPriority(chi, false) > OpCharToPriority(cho, true))
            return 0;
        else
            return -1;
    }
}

/**
 * @param computableStr Ҫ������ַ���
 * @param currentElementEnd ��ǰEIE��ʼ��ַ
 * @return char* ��ǰEIE�����ĵ�ַ
 * @author CS
*/
char* findCurrentEnd(char* computableStr, char* currentElementEnd)
{
    char* temp = currentElementEnd;
    if ((*temp < '0' || *temp > '9'))
    {
        return currentElementEnd; //��ʱָ�����һ��������
    }
    else//��tempָ���������ֻ����ַ�����ͷ
    {

        bool hasFraction = false;
        bool finished = false;
        for (; !finished; temp++)
        {
            if (*(temp + 1) < '0' || *(temp + 1) > '9')
            {//�ҵ��˷����֣���֮ǰ��ʽ��Ϊ��ʽ�ַ���������ֻ���ǲ�����
                if (hasFraction)
                { //���ҵ���С����
                    finished = true;
                }
                else
                { //δ������С����
                    if (*(temp + 1) == '.')
                        hasFraction = true;
                    else
                        finished = true;
                }
            }
        }
        return temp - 1;
    }
}

/**
 * @param computableStr Ҫ������ַ���
 * @param currentElementStart ������ָ���������λ��ַ
 * @return һ��ELE, ���ڼ����һ������(int or double)����һ��������
 * @author LD
 */
EIE readSingleOPcharOrOPnum(char* computableStr, char* currentElementStart, char* currentElementEnd)
{
    EIE temp;
    if (currentElementStart == currentElementEnd)
    { //Ϊ�����������򵥸�����
        if (*currentElementStart < '0' || *currentElementStart>'9')
        {
            temp.intPart = (int)(*currentElementStart);
            temp.fractionPart = 0;
            temp.priority = OpCharToPriority(*currentElementStart, true);
        }
        else
        {
            temp.intPart = (int)(*currentElementStart - 48);
            temp.fractionPart = 0;
            temp.priority = -1;
        }

    }
    else//��������һ�������ֻ���С��
    {
        int sumOfIntPart = 0;//��������
        char* readerPtr;//����ָ��
        for (readerPtr = currentElementStart; readerPtr <= currentElementEnd; readerPtr++)
        {
            if (!isdigit(*readerPtr))
                break;
            else
                sumOfIntPart = sumOfIntPart * 10 + (int)((*readerPtr) - 48);
        }
        char* dot = readerPtr;
        if (readerPtr != currentElementEnd)//ΪС��
        {
            double sumOfFractionPart = 0.0;
            readerPtr++;//ָ��С�����ֵ�һ��
            for (; readerPtr <= currentElementEnd; readerPtr++)
            {
                //double sumOfFraction = 0.0;
                sumOfFractionPart = sumOfFractionPart + (*(readerPtr)-48) * pow(0.1, (readerPtr - dot) / sizeof(char));
                
            }
            temp.intPart = sumOfIntPart;
            temp.fractionPart = sumOfFractionPart;
            temp.priority = -1;

        }
        else//Ϊ����
        {
            temp.intPart = sumOfIntPart;
            temp.fractionPart = 0.0;
            temp.priority = -1;
        }

    }
    return temp;
}

/**
* ����һ�β�����ջ���������Ͳ�����ջ��һ��������
* @param double
* 1-2
* 12
* -
* 21
* @author TDY
*/
double calculateOnce(double num1, double num2, char Opch)
{
    switch (Opch)
    {
    case('+'):return num1 + num2; break;
    case('-'):return num2 - num1; break;
    case '*': return num2 * num1; break;
    case '/': return num2 / num1; break;
    case '%': return (int)num2 % (int)num1; break;
    case '^': return pow(num2, num1); break;
    case '&': return pow(num2, 1.0 / num1); break;
    default:break;
    }

}

/**
 * @param computableStr ���ڼ�����ַ���
 * @return EIE������ʽ����ʽ
 * @author SXZ
*/
queue<EIE> convertFromStrToEquation(char* computableStr)
{
    queue<EIE> result;

    for (char* currentElementStart = computableStr;
        currentElementStart < computableStr + strlen(computableStr);
        currentElementStart++)
    {
        char* currentElementEnd = currentElementStart;
        //��ʼ��ָ��ǰEIE������ָ��
        currentElementEnd = findCurrentEnd(computableStr, currentElementEnd);
        /*cout << &currentElementStart << "\t" << *currentElementStart << endl;
        cout << &currentElementEnd << "\t" << *currentElementEnd<<endl;*/
        //ָ��ǰEIE�����ĵ�ַ
        result.push(readSingleOPcharOrOPnum(computableStr, currentElementStart, currentElementEnd));
        //�Ѷ��õ�һ��EIE����������ʽ����ʽ
        //�Ż�������һ��һ���������Լʱ��
        currentElementStart = currentElementEnd;
        //����ָ��ָ����һ��EIEǰһλ
    }
    return result;
}

/**
@param char* �ɼ�����ַ�����ʽ
@return double ������
@author SXZ
*/
double compute(char* computableStr)
{
    stack<double> opnd;//������
    stack<char> optr;//������
    cout << formatStep0(computableStr) << endl;
    queue<EIE> equation = convertFromStrToEquation(formatStep0(computableStr));
    while (!equation.empty())
    {

        if (equation.front().priority == -1)
        {
            opnd.push(equation.front().intPart + equation.front().fractionPart);
            equation.pop();
            //��Ϊ����,����push��������ջ(opnd), ����������һ���ַ�
        }
        else//��ʱΪ������
        {

            if (optr.empty())
            {//��֤������ջ�ڽ�������Ϊ��
                if (equation.front().intPart == '=') { break; }
                optr.push((char)(equation.front().intPart));
                equation.pop();
                if (optr.top() == '(' && equation.front().priority == OpCharToPriority('-', true))
                {
                    opnd.push(0);//���ź����ʽ�ʼ�ļ�����Ҫ��0������
                }
            }
            else
            {
                switch (comparePriorityOfOpChar(optr.top(), equation.front().intPart))
                {
                case(1):
                {
                    optr.push(equation.front().intPart);
                    equation.pop();
                    if (optr.top() == '(' && equation.front().priority == OpCharToPriority('-', true))
                    {
                        opnd.push(0);//���ź����ʽ�ʼ�ļ�����Ҫ��0������
                    }
                    break;
                }
                case(0):
                {
                    if (opnd.size() > 1)
                    {
                        double num1 = opnd.top();
                        opnd.pop();
                        double num2 = opnd.top();
                        opnd.pop();
                        opnd.push(calculateOnce(num1, num2, optr.top()));
                        optr.pop();
                    }
                    break;
                }
                case(-1):
                {
                    optr.pop();
                    equation.pop();
                    break;
                }
                default:break;
                }
            }
        }
    }
    return opnd.top();
}
