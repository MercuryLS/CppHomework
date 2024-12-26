#include "Expression.hpp"

char Expression::checkRectangle(int i)
{
    char rectangle_opt = '\0';
    string subStr = theStr.substr(i, 6); //�����ң������ң������е��жϣ�ȡ6���ַ����Ӵ�
    if (subStr == str7)
    {
        rectangle_opt = ARCSIN_OPT;
    }
    else if (subStr == str8)
    {
        rectangle_opt = ARCCOS_OPT;
    }
    else if (subStr == str9)
    {
        rectangle_opt = ARCTAN_OPT;
    }
    if (rectangle_opt)
    { //�������¹������Զ���ı�ʶ���滻arcsin����ĸ
        theStr.erase(i, 6);
        return rectangle_opt;
    }
    subStr = theStr.substr(i, 4); //�����ң������ң������е��жϣ�ȡ4���ַ����Ӵ�
    if (subStr == str4)
    {
        rectangle_opt = ARCSIN_OPT;
    }
    else if (subStr == str5)
    {
        rectangle_opt = ARCCOS_OPT;
    }
    else if (subStr == str6)
    {
        rectangle_opt = ARCTAN_OPT;
    }
    if (rectangle_opt)
    { //�������¹������Զ���ı�ʶ���滻asin����ĸ
        theStr.erase(i, 4);
        return rectangle_opt;
    }
    subStr = theStr.substr(i, 3); //���ң����ң����е��жϣ�ȡ3���ַ����Ӵ�
    if (subStr == str1)
    {
        rectangle_opt = SIN_OPT;
    }
    else if (subStr == str2)
    {
        rectangle_opt = COS_OPT;
    }
    else if (subStr == str3)
    {
        rectangle_opt = TAN_OPT;
    }
    if (rectangle_opt)
    { //�������¹������Զ���ı�ʶ���滻sin����ĸ
        theStr.erase(i, 3);
        return rectangle_opt;
    }
    //���Ͼ�����
    return 0;
}

//���Ǻ�����׺���Ա�֮��ת��׺���ʽ
void Expression::RectOptPost()
{
    int len = theStr.length();
    for (int i = 0; i < len; i++)
    {
        int j=i;
        if (isRectangle(theStr[j]))
        {
            if(theStr[j+1]=='('){//�����ţ������Ƿ��ƶ�������Ե������ź�
                int bracket=1;
                for(int k=j+1;k<len;k++){
                    if(theStr[k]=='(')bracket++;
                    if(theStr[k]==')')bracket--;
                    if(bracket==0){
                        k++;
                        if(theStr[k]=='!')k++;
                        theStr.insert(k,1,theStr[j]);
                        theStr.erase(j,1);
                        break;
                    }
                }
            }
            else if(isdigit(theStr[j+1])){//�����֣������Ƿ��ƶ������ֺ�
                for(int k=j+1;k<len;k++){
                    if(isdigit(theStr[k])||theStr[k]=='.'||theStr[i]=='!')continue;
                    else {
                        theStr.insert(k,1,theStr[j]);
                        theStr.erase(j,1);
                    }
                }
            }
        }
    }
}
