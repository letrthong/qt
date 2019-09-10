#ifndef ISCENEBASE_H
#define ISCENEBASE_H
#include <string>

class ISceneBase{
public:
   virtual void onClickListener(const std::string& from) = 0;
   virtual void onUpdateListener(int id) = 0;
};

#endif // ISCENEBASE_H
