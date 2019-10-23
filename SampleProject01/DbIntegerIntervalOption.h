#ifndef DB_INTEGER_INTERVAL_OPTION_H
#define DB_INTEGER_INTERVAL_OPTION_H

#include "DbOptionBase.h"

class DbIntegerIntervalOption : public DbOptionBase
{
public:
    DbIntegerIntervalOption();
    DbIntegerIntervalOption(const std::string& name,  const std::string& iconUrl, int count,int index, int value, int length);

    void setIntervalCount(int count);
    int getIntervalCount() const;

    void setIntervalIndex(int index);
    int getIntervalIndex() const ;

    void setStartingValue(int value);
    int getStartingValue() const ;

    int setIntervalLength(int length);
    int getIntervalLength() const;

private:
    int mIntervalCount;
    int mIntervalIndex;
    int  mStartingValue;
    int  mIntervalLength;
};

#endif // DB_INTEGER_INTERVAL_OPTION_H
