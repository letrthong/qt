#ifndef DB_STRING_OPTION_H
#define DB_STRING_OPTION_H

#include "DbOptionBase.h"
#include <vector>
#include <string>

class DbStringOption : public DbOptionBase
{
public:
    DbStringOption();
    DbStringOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<std::string>& arrValues);

    void setCurrentIndex(int index);
    int getCurrentIndex() const;

    void setArrValues( const std::vector<std::string>& arrValues);
    void setArrayValue(const std::string& data);
    std::vector<std::string> getArrValues() const;
    std::string getArrValuesToString() const;

private:

    int mCurrentIndex;
    std::vector<std::string> mArrValues;
    std::string mData;
};

#endif // DB_STRING_OPTION_H
