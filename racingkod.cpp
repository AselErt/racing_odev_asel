#include <bits/stdc++.h>
#include <math.h>

using namespace std;

float getTorgueFromThrottle(int t, int input[]){
    float output = 0;
    //kod başı
    
    int s1 = input[0]* 256 + input[1];
    int s2 = input[2]* 256 + input[3];

    if(abs(s1-s2) > 65536 * 0.1){
        return 0;
    }

    double pedal = ((s1 +s2)/ 2.0) / 65535.0;

    if (pedal < 0.1) {
        return 0;
    }

    output = (float)(((pedal - 0.1) / 0.9) * t);

    if (output > t) output = t;
    
    return output;
}

int main(){
    int t;
    int inputArr[4];

    cin >> t;

    for(int i=0;i<4; i++){
        cin >> inputArr[i];
    }

    cout << getTorgueFromThrottle(t, inputArr);
}