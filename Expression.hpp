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
//����������arc...��a...����
const string str7 = "arcsin";
const string str8 = "arccos";
const string str9 = "arctan";

//��������������ʾ�������е�״̬
//#define���ı��滻��ֻҪ����pi�ͽ��任Ϊֵ
//const int ���Ƕ�����ͨ�ĳ���
const int IN=0;
const int OUT=1;

#define pi 3.14159265358
#define SIN_OPT 's'
#define COS_OPT 'c'
#define TAN_OPT 't'
#define ARCSIN_OPT 'S'
#define ARCCOS_OPT 'C'
#define ARCTAN_OPT 'T'
//���ڴ洢�ڲ�����ջ�е����Ǻ��������

bool char_in_string(char,string);//�����ַ��Ƿ����ַ�����
bool isRectangle(char);//�ж��Ƿ������Ǻ���������
int level(char);//��������ȼ��ж�
int cal_factorial(int);//����������׳�
double ComputeRectangle(char c,double x);//�������Ǻ���

class Expression
{
public:
    Expression();
    Expression(string &);
    bool Format();     //��ʽ��
    bool change();            //��׺ת��׺
    char checkRectangle(int); //�ж����Ǻ�����ת��Ϊ�Զ�������Ǻ���������,����Ϊ�ַ����е�λ��
    void RectOptPost();//���Ǻ�����׺���Ա�֮��ת��׺���ʽ
    bool FormatCheck();//��ʽ��飬���ڷǷ��ַ��ѱ��޳����˴���Ҫ��������Ƿ���ȷǶ�ף�����������ӵ�����
    void negative_change();//�������⴦��
    bool compute();//�����׺���ʽ
    void show();
    void showAns();//������;

private:
    string theStr;
    stack<double> val;
    stack<char> opt;
};

#endif