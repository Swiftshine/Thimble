#include <algorithm>
#include <telkin/Runtime.h>
#include <telkin/Print.h>
#include <thimble/ThimbleConfig.hpp>
#include <gfl/gflResArchivedFileInfo.hpp>

using namespace th;

ThimbleConfig& ThimbleConfig::Instance() {
    static th::ThimbleConfig inst;
    return inst;
}

inline void Trim(std::string& s) {
    const char* whitespace = " \t\r\n";

    s.erase(0, s.find_first_not_of(whitespace));
    s.erase(s.find_last_not_of(whitespace) + 1);
}

void ThimbleConfig::ConfigureFrom(const char* pFilepath) {
    gfl::ResFileObject res = gfl::ResArchivedFileInfo::OpenFileFromArchive(pFilepath, 0);

    std::string s(reinterpret_cast<const char*>(res.GetData()), res.GetFilesize());

    tk::println("Collecting configurations...");

    size_t pos = 0;
    bool found = false;

    while (pos < s.size()) {
        size_t end = s.find('\n', pos);
        if (end == std::string::npos)
            end = s.size();

        std::string line(s.data() + pos, end - pos);

        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        Trim(line);

        if (line.empty() || line[0] == '#') {
            pos = end + 1;
            continue;
        }

        size_t eq = line.find('=');
        if (eq != std::string::npos) {
            std::string key = line.substr(0, eq);
            std::string value = line.substr(eq + 1);

            Trim(key);
            Trim(value);

            mParams.emplace_back(key, value);
        }

        pos = end + 1;
    }

    for (const auto& pair : mParams) {
        tk::println("\t%s: %s", pair.key.c_str(), pair.value.c_str());
        found = true;
    }

    if (found) {
        tk::println("Finished collecting configurations.");
    } else {
        tk::println("No configurations found.");
    }
}

template<>
const char* ThimbleConfig::ReadParam<const char*>(const char* pParamName) {
    for (const auto& param : mParams) {
        if (param.key == pParamName)
            return param.value.c_str();
    }

    return "<ERROR>";
}

template<>
int ThimbleConfig::ReadParam<int>(const char* pParamName) {
    const char* value = ReadParam<const char*>(pParamName);
    return static_cast<int>(strtol(value, nullptr, 10));
}

template<>
float ThimbleConfig::ReadParam<float>(const char* pParamName) {
    const char* value = ReadParam<const char*>(pParamName);
    return static_cast<float>(atof(value));
}

template<>
bool ThimbleConfig::ReadParam<bool>(const char* pParamName) {
    const char* value = ReadParam<const char*>(pParamName);

    if (std::strcmp(value, "true") == 0) {
        return true;
    } else if (std::strcmp(value, "false") == 0) {
        return false;
    }

    return false;
}
