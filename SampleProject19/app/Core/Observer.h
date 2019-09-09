#ifndef SINGAL_MANAGER_H_
#define SINGAL_MANAGER_H_


 /*
*Interface
*/
class Observer
{
public:
    virtual void update(int temperature, int Presure, int Humidity) = 0;
    virtual void destroy() = 0;
    
    //virtual constructors 
    virtual ~Observer(){};
};


  #endif // SINGAL_MANAGER_H_
