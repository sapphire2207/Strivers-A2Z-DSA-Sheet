// While loop
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 5;

    while(i > 0){
        cout << i << endl;
        i--;
    }
    // Here the while loop will run for 5 times.... condition check chesthundi ikkada prathi okkasari....
    // i.e for i = 5 => prints => 5
    //         i = 4 => prints => 4
    //         i = 3 => prints => 3
    //         i = 2 => prints => 2
    //         i = 1 => prints => 1
}

// Do while loop
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 5;
    do{
        cout << i << endl;
        i--;
    } while(i > 6);
    // ikkada do-while lo emi aithundi ante.... condition last lo checking chesthunam...
    // ippudu first emo i = 5, condition endhi (i > 6) unte ne number print cheyali....
    // So do-while lo emi aithadi ante condition lo emi rasi undo check cheyakunda pakka okasari loop execute aithadi....
    // So 5 print chesthadi
    // next condition check chesthadi (5 > 6) --> idhi false kabbati terminate aipothadi loop.....

    // While loop lo emi aithundi ante pakka first condition check chesthadi loop enter ayyekante modalu....
    // Anduke do-while loop ni rare cases lo use chestham....
    // like manaki ela ante... ippudu nuv oka pani chesdham ankuntunnav... dhani output endo neeku telidu.... so nuv em chesthav ante.... irrespective of the output naaku emi osthundo... atleast nuv dhanni okkasari ana run chesi telsukuntav emi aithundi ani ala.....
}