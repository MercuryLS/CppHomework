#include "Expression.hpp"

bool Expression::FormatCheck()
{ //格式检查，由于非法字符已被剔除，此处主要检查括号是否正确嵌套，运算符的连接等问题
    int len = theStr.length();

    //检查括号数量配对
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

    if (!(isdigit(theStr[0]) || isRectangle(theStr[0]) || char_in_string(theStr[0], "(-"))) //首位应为数字，三角，负号或左括号
        return false;
    if (!(isdigit(theStr[len - 1]) || char_in_string(theStr[len - 1], ")!"))) //尾位应为数字，阶乘或右括号
        return false;
    for (int i = 1; i < len - 1; i++)
    {

        if (theStr[i] == '.')
        { //小数点左右应为数字
            if (theStr[i] == '.' && isdigit(theStr[i - 1]) && isdigit(theStr[i + 1]))
                continue;
            else
            {
                cout << "1";
                return false;
            }
        }
        if (char_in_string(theStr[i], "+*/^"))
        { //双目运算符左边为数字，')'或'!',右边为数字，'('或三角函数
            if ((isdigit(theStr[i - 1]) || char_in_string(theStr[i - 1], ")!")) && (isdigit(theStr[i + 1]) || isRectangle(theStr[i + 1]) || theStr[i + 1] == '('))
                continue;
            else
            {
                cout << "2";
                return false;
            }
        }
        if (theStr[i] == '-')
        { //减号/负号左边不为双目运算符或小数点，右边应为数字，左括号或三角
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
            //阶乘左边应为数字或右括号，右边应为右括号或+-*/^
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
            //三角运算符左边应为+-*/(^,右边应为数字或'('
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
            //左括号左边应为（+-*/^或三角,右边应为数字，三角,'('或'-'
            if ((char_in_string(theStr[i - 1], "+-*/^(") || isRectangle(theStr[i - 1])) && (isdigit(theStr[i + 1]) || char_in_string(theStr[i + 1], "-(") || isRectangle(theStr[i + 1])))
                continue;
            else
                return false;
        }
        if (theStr[i] == ')')
        {
            //右括号左边应为数字,')'或'!',右边应为)=-*/^!
            if ((isdigit(theStr[i - 1]) || char_in_string(theStr[i - 1], ")!")) && (char_in_string(theStr[i + 1], "+-*/^!)")))
                continue;
            else
                return false;
        }
    }
    return true;
};

void Expression::negative_change(){//处理负号
    int len=theStr.length();
    for(int i=0;i<len;i++){
        if (theStr[i]=='-'&&(i==0||isRectangle(theStr[i-1])||theStr[i-1]=='(')){
            theStr.insert(i,1,'0');
            i++;
        }
    }
}

bool isRectangle(char c)
{ //判断三角符号
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
{ //查找字符是否在字符串内
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