#include <iostream>
#include "priority_queue.h"


int main()
{
    priority_queue<int> ob;
    priority_queue<int> ob2;
    ob.push(2);
    ob.push(1);
    ob.push(4);
    ob.push(12);
    ob.push(16);
    ob.push(14);
    //ob.pop();
    //ob2.push(5);
    //ob2.push(7);
    //ob2.push(2);
    //ob2.push(3);
    ////ob = ob2;
    //ob.swap(ob2);
    ////std::cout << ob.top();
    ob.print();
    //std::cout << std::endl;
    //ob2.print();
}


