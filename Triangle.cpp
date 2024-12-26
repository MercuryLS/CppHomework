#include "Expression.hpp"

char Expression::checkRectangle(int i)
{
    char rectangle_opt = '\0';
    string subStr = theStr.substr(i, 6); //反正弦，反余弦，反正切的判断，取6个字符的子串
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
    { //若被更新过，用自定义的标识符替换arcsin等字母
        theStr.erase(i, 6);
        return rectangle_opt;
    }
    subStr = theStr.substr(i, 4); //反正弦，反余弦，反正切的判断，取4个字符的子串
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
    { //若被更新过，用自定义的标识符替换asin等字母
        theStr.erase(i, 4);
        return rectangle_opt;
    }
    subStr = theStr.substr(i, 3); //正弦，余弦，正切的判断，取3个字符的子串
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
    { //若被更新过，用自定义的标识符替换sin等字母
        theStr.erase(i, 3);
        return rectangle_opt;
    }
    //以上均不是
    return 0;
}

//三角函数后缀化以便之后转后缀表达式
void Expression::RectOptPost()
{
    int len = theStr.length();
    for (int i = 0; i < len; i++)
    {
        int j=i;
        if (isRectangle(theStr[j]))
        {
            if(theStr[j+1]=='('){//是括号，将三角符移动到其配对的右括号后
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
            else if(isdigit(theStr[j+1])){//是数字，将三角符移动到数字后
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
