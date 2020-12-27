#include<string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }
    int small_output = keypad(num/10,output);
    int small_cal_num = num%10;
    if(small_cal_num == 2)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "a";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "b";
            else
                ref[i] = output[i%small_output] + "c";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }
    else if(small_cal_num == 3)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "d";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "e";
            else
                ref[i] = output[i%small_output] + "f";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }
    else if(small_cal_num == 4)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "g";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "h";
            else
                ref[i] = output[i%small_output] + "i";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }
    else if(small_cal_num == 5)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "j";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "k";
            else
                ref[i] = output[i%small_output] + "l";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }
    else if(small_cal_num == 6)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "m";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "n";
            else
                ref[i] = output[i%small_output] + "o";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }
    else if(small_cal_num == 7)
    {
        string* ref = new string[4 * small_output];
        int flag = 0;
        for(int i=0;i < 4 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "p";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "q";
            else if(flag == 2)
                ref[i] = output[i%small_output] + "r";
            else
                ref[i] = output[i%small_output] + "s";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 4 * small_output;i++)
            output[i] = ref[i];
        return small_output * 4;
    }
    else if(small_cal_num == 8)
    {
        string* ref = new string[3 * small_output];
        int flag = 0;
        for(int i=0;i < 3 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "t";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "u";
            else
                ref[i] = output[i%small_output] + "v";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 3 * small_output;i++)
            output[i] = ref[i];
        return small_output * 3;
    }

    else if(small_cal_num == 9)
    {
        string* ref = new string[4 * small_output];
        int flag = 0;
        for(int i=0;i < 4 * small_output;i++)
        {
            if(flag == 0)
                ref[i] = output[i%small_output] + "w";
            else if(flag == 1)
                ref[i] = output[i%small_output] + "x";
            else if(flag == 2)
                ref[i] = output[i%small_output] + "y";
            else
                ref[i] = output[i%small_output] + "z";
            if((i+1)%small_output == 0)
                flag++;
        }
        for(int i=0;i < 4 * small_output;i++)
            output[i] = ref[i];
        return small_output * 4;
    }
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

