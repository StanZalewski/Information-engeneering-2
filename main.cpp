#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    Time a;
    Time b;
    Time add_result, sub_result, multip_result;
    cin>>a;
    cin>>b;
    cout<<a;
    cout<<b;
    add_result=a+b;
    sub_result=a-b;
    multip_result=a*b;
    cout<<add_result;
    cout<<sub_result;
    cout<<multip_result;

    return 0;
}
