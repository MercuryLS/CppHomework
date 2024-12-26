#include "Expression.hpp"

bool Expression::FormatCheck()
{ //��ʽ��飬���ڷǷ��ַ��ѱ��޳����˴���Ҫ��������Ƿ���ȷǶ�ף�����������ӵ�����
    int len = theStr.length();

    //��������������
    int bracket = 0;
    for (int i = 0; i < len; i++)
    {
        if (theStr[i] == '(')
            bracket++;
        if (theStr[i] == ')')
            bracket--;
    }
    if (bracket != 0)
        return false;

    if (!(isdigit(theStr[0]) || isRectangle(theStr[0]) || char_in_string(theStr[0], "(-"))) //��λӦΪ���֣����ǣ����Ż�������
        return false;
    if (!(isdigit(theStr[len - 1]) || char_in_string(theStr[len - 1], ")!"))) //βλӦΪ���֣��׳˻�������
        return false;
    for (int i = 1; i < len - 1; i++)
    {

        if (theStr[i] == '.')
        { //С��������ӦΪ����
            if (theStr[i] == '.' && isdigit(theStr[i - 1]) && isdigit(theStr[i + 1]))
                continue;
            else
            {
                cout << "1";
                return false;
            }
        }
        if (char_in_string(theStr[i], "+*/^"))
        { //˫Ŀ��������Ϊ���֣�')'��'!',�ұ�Ϊ���֣�'('�����Ǻ���
            if ((isdigit(theStr[i - 1]) || char_in_string(theStr[i - 1], ")!")) && (isdigit(theStr[i + 1]) || isRectangle(theStr[i + 1]) || theStr[i + 1] == '('))
                continue;
            else
            {
                cout << "2";
                return false;
            }
        }
        if (theStr[i] == '-')
        { //����/������߲�Ϊ˫Ŀ�������С���㣬�ұ�ӦΪ���֣������Ż�����
            if (!(char_in_string(theStr[i - 1], ".+-*/^")) && (isdigit(theStr[i + 1]) || isRectangle(theStr[i + 1]) || theStr[i + 1] == '('))
                continue;
            else
            {
                cout << "3";
                return false;
            }
        }
        if (theStr[i] == '!')
        {
            //�׳����ӦΪ���ֻ������ţ��ұ�ӦΪ�����Ż�+-*/^
            if ((isdigit(theStr[i - 1]) || theStr[i - 1] == ')') && (char_in_string(theStr[i + 1], ")+-*/")))
                continue;
            else
            {
                cout << "4";
                return false;
            }
        }
        if (isRectangle(theStr[i]))
        {
            //������������ӦΪ+-*/(^,�ұ�ӦΪ���ֻ�'('
            if (char_in_string(theStr[i - 1], "+-*/^(") && (isdigit(theStr[i + 1]) || theStr[i + 1]=='('))
                continue;
            else
            {
                cout << "5" <<i;
                return false;
            }
        }
        if (theStr[i] == '(')
        {
            //���������ӦΪ��+-*/^������,�ұ�ӦΪ���֣�����,'('��'-'
            if ((char_in_string(theStr[i - 1], "+-*/^(") || isRectangle(theStr[i - 1])) && (isdigit(theStr[i + 1]) || char_in_string(theStr[i + 1], "-(") || isRectangle(theStr[i + 1])))
                continue;
            else
                return false;
        }
        if (theStr[i] == ')')
        {
            //���������ӦΪ����,')'��'!',�ұ�ӦΪ)=-*/^!
            if ((isdigit(theStr[i - 1]) || char_in_string(theStr[i - 1], ")!")) && (char_in_string(theStr[i + 1], "+-*/^!)")))
                continue;
            else
                return false;
        }
    }
    return true;
};

void Expression::negative_change(){//������
    int len=theStr.length();
    for(int i=0;i<len;i++){
        if (theStr[i]=='-'&&(i==0||isRectangle(theStr[i-1])||theStr[i-1]=='(')){
            theStr.insert(i,1,'0');
            i++;
        }
    }
}

bool isRectangle(char c)
{ //�ж����Ƿ���
    string s="sctSCT";
    for (int i = 0; i < 6; i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

bool char_in_string(char c, string s)
{ //�����ַ��Ƿ����ַ�����
    int strlen = s.length();
    for (int i = 0; i < strlen; i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}