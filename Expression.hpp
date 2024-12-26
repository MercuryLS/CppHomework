#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include <string>
#include <stack>
#include <iostream>
using namespace std;
const string str1 = "sin";
const string str2 = "cos";
const string str3 = "tan";
const string str4 = "asin";
const string str5 = "acos";
const string str6 = "atan";
//反三角输入arc...或a...均可
const string str7 = "arcsin";
const string str8 = "arccos";
const string str9 = "arctan";

//定义两个常量表示在数字中的状态
//#define是文本替换，只要看到pi就将其换为值
//const int 就是定义普通的常量
const int IN=0;
const int OUT=1;

#define pi 3.14159265358
#define SIN_OPT 's'
#define COS_OPT 'c'
#define TAN_OPT 't'
#define ARCSIN_OPT 'S'
#define ARCCOS_OPT 'C'
#define ARCTAN_OPT 'T'
//用于存储在操作符栈中的三角函数运算符

bool char_in_string(char,string);//查找字符是否在字符串内
bool isRectangle(char);//判断是否是三角函数操作符
int level(char);//运算符优先级判断
int cal_factorial(int);//利用数组求阶乘
double ComputeRectangle(char c,double x);//计算三角函数

class Expression
{
public:
    Expression();
    Expression(string &);
    bool Format();     //格式化
    bool change();            //中缀转后缀
    char checkRectangle(int); //判断三角函数并转化为自定义的三角函数操作符,参数为字符串中的位置
    void RectOptPost();//三角函数后缀化以便之后转后缀表达式
    bool FormatCheck();//格式检查，由于非法字符已被剔除，此处主要检查括号是否正确嵌套，运算符的连接等问题
    void negative_change();//负号特殊处理
    bool compute();//计算后缀表达式
    void show();
    void showAns();//输出结果;

private:
    string theStr;
    stack<double> val;
    stack<char> opt;
};

#endif