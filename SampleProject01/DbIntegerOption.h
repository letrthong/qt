#ifndef DB_INTEGER_OPTION_H
#define DB_INTEGER_OPTION_H

#include "DbOptionBase.h"
#include <vector>

class DbIntegerOption : public DbOptionBase
{
public:
    DbIntegerOption();
    DbIntegerOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<int>& arrValues);

    void setCurrentIndex(int index);
    int getCurrentIndex() const;

    void setArrValues( const std::vector<int>& arrValues);
    void setArrayValue(const std::string& data);
    std::vector<int> getArrValues() const;
    std::string getArrValuesToString() const;

private:
    int mCurrentIndex;
    std::vector<int> mArrValues;
    std::string mData;
};

#endif // DB_INTEGER_OPTION_H
