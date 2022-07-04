
#include <iostream>

using namespace std;

class kilas{
    public:
    
    int n = 9;
    void fun(){
        cout << "I'm a function-fun\n";
    }
    void funnn(){
        cout << "I'm a function-funnn\nI call another function\n";
        fun();
    }
};

int main()
{
    // cout<<"Hello World";
    // kilas school ;
    // cout <<school.n<<endl;
    // school.fun();
    // school.funnn();
    bool dp[100][100];
    cout << dp[0][0]<<dp[10][10];
    return 0;
}