#include<iostream>
#include<future>

int square(std::future<int>& ft)
{
    int number=ft.get();
    return number*number;
}
int factorial(int a)
{
    if(a<=1)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
    
}
int main()
{
    // step 1: make a promise
    std::promise<int> pr;

    //step 2: step 2: A future linked to the promise
    std::future<int> ft=pr.get_future();

    std::future<int> result_ft=std::async(std::launch::async,&square,std::ref(ft));

    std::cout<<factorial(5);
    int val=0;
    std::cout<<"Enter number";
    std::cin>>val;
    pr.set_value(val);
    std::cout<<"Result of Square is : "<<result_ft.get();

    return 0;
}


/* 
    client-server architecture
    future-promise model
    square calculation
    Main needs to delegate the task of square calculation

*/
