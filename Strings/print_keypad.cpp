#include<string>
#include<iostream>
using namespace std;

void printkeypad(int num, string output)
{
    if(num == 0)
    {
        cout<<output<<endl;
        return;
    }
    int small_cal_num = num%10;
    if(small_cal_num == 2)
    {
        printkeypad(num/10,"a" + output);
        printkeypad(num/10,"b" + output);
        printkeypad(num/10,"c" + output);
        return;
    }
    else if(small_cal_num == 3)
    {
       	printkeypad(num/10,"d" + output);
        printkeypad(num/10,"e" + output);
    	printkeypad(num/10,"f" + output);
        return;
    }
    else if(small_cal_num == 4)
    {
       	printkeypad(num/10,"g" + output);
        printkeypad(num/10,"h" + output);
    	printkeypad(num/10,"i" + output);
        return;
    }
    else if(small_cal_num == 5)
    {
       	printkeypad(num/10,"j" + output);
        printkeypad(num/10,"k" + output);
    	printkeypad(num/10,"l" + output);
        return;
    }
    else if(small_cal_num == 6)
    {
       	printkeypad(num/10,"m" + output);
        printkeypad(num/10,"n" + output);
    	printkeypad(num/10,"o" + output);
        return;
    }
    else if(small_cal_num == 7)
    {
       	printkeypad(num/10,"p" + output);
        printkeypad(num/10,"q" + output);
    	printkeypad(num/10,"r" + output);
        printkeypad(num/10,"s" + output);
        return;
    }else if(small_cal_num == 8)
    {
       	printkeypad(num/10,"t" + output);
        printkeypad(num/10,"u" + output);
    	printkeypad(num/10,"v" + output);
        return;
    }else if(small_cal_num == 9)
    {
       	printkeypad(num/10,"w" + output);
        printkeypad(num/10,"x" + output);
    	printkeypad(num/10,"y" + output);
        printkeypad(num/10,"z" + output);
        return;
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    printkeypad(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
