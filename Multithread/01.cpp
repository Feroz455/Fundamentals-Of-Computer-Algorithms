/*
ref:-
https://www.youtube.com/watch?v=LL8wkskDlbs&list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M
chennel:-
https://www.youtube.com/user/BoQianTheProgrammer
*/
#include <iostream>
#include <thread>
using namespace std;
void MyFync()
{
    cout << "Life is beautiful" << endl;
    return;
}
int main()
{
    thread t1(MyFync);
    t1.join();
    MyFync();

    return 0;
}