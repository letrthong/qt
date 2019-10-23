#ifndef DB_OPTION_BASE_H
#define DB_OPTION_BASE_H
#include  <string>

class DbOptionBase
{
public:
    explicit DbOptionBase();
     explicit DbOptionBase(const std::string& name,  const std::string& iconUrl);
    ~DbOptionBase();

    void setName(const std::string& name);
    std::string getName() const;

    void setIconUrl(const std::string& iconUrl);
    std::string getIconUrl() const;

protected:
     std::string mIconURL;
     std::string mName;
     int mProgramId;
     bool mIsEnabled;
     bool mIsDeactivated;
};

#endif // DB_OPTION_BASE_H
