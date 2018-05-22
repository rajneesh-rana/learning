#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
class singleton
{
public:
    static singleton& get();
    void print()
    {   cout<<"rajneesh"<<endl; }
private:
    static singleton obj;
    singleton(){};
    ~singleton(){};
    const singleton& operator=(const singleton& a){ return a; }
    
};

singleton singleton::obj;

static singleton& get()
{
//    static singleton obj;
    return singleton::obj;
}  
#endif

class MySingleton
{
    private:
        // Private Constructor
        MySingleton(){}
        // Stop the compiler generating methods of copy the object
        MySingleton(MySingleton const& copy){}            // Not Implemented
        const MySingleton& operator=(MySingleton const& copy){return copy;} // Not Implemented

    public:
        void print()
        { cout<<"rajneesh"<<endl; }
        static MySingleton& getInstance()
        {
            // The only instance
            // Guaranteed to be lazy initialized
            // Guaranteed that it will be destroyed correctly
            static MySingleton instance;
            return instance;
        }
};
 
int main()
{
    MySingleton &s=MySingleton::getInstance();
   s.print();
    return 0;
} 
