#ifndef INTERFACE_SCENE_BASE_H
#define INTERFACE_SCENE_BASE_H
#include <string>

class ISceneBase{
public:
   virtual void onClickListener(unsigned int type, const std::string& from) = 0;
   virtual void onChangedListener(int id) = 0;

    virtual void onClickItemOfList(int index, bool status) = 0;

    virtual ~ISceneBase(){}
};

#endif // INTERFACE_SCENE_BASE_H
