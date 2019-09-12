#ifndef INTERFACE_SCENEBASE_H
#define INTERFACE_SCENEBASE_H
#include <string>

class ISceneBase{
public:
   virtual void onClickListener(const std::string& from) = 0;
   virtual void onChangedListener(int id) = 0;

    virtual ~ISceneBase(){}
};

#endif // INTERFACE_SCENEBASE_H
