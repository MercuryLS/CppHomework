#include "Expression.hpp"
Expression::Expression(string &s) : theStr(s){};

void Expression::show(){
    cout<<theStr<<endl;
}

void Expression::showAns(){
    cout<<"½á¹ûÎª£º"<<val.top()<<endl;
}