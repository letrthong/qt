#ifndef DB_BOOLEAN_OPTION_H
#define DB_BOOLEAN_OPTION_H

#include "DbOptionBase.h"
#include <vector>
#include <string>

class DbBooleanOption : public DbOptionBase
{
public:
    DbBooleanOption();
    DbBooleanOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<bool>& arrValues);

    void setCurrentIndex(int index);
    int getCurrentIndex() const;

    void setArrValues( const std::vector<bool>& arrValues);
    void setArrayValue(const std::string& data);
    std::vector<bool> getArrValues() const;
    std::string getArrValuesToString() const;

private:

    int mCurrentIndex;
    std::vector<bool> mArrValues;
    std::string mData;
};

#endif // DB_BOOLEAN_OPTION_H
