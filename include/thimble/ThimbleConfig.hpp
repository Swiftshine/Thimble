#include <string>
#include <vector>

#pragma once

namespace th {

class ThimbleConfig {
private:
    struct ConfigParam {
        ConfigParam(const std::string& k, const std::string& v)
            : key(k)
            , value(v)
        { }

        std::string key;
        std::string value;
    };
public:
    static ThimbleConfig& Instance();

    void ConfigureFrom(const char* pFilepath);

    template <typename T>
    T ReadParam(const char* pParamName);
private:
    std::vector<ConfigParam> mParams;
};

}
