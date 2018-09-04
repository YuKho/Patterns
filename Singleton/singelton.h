#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <string>

class nocopymoveable
{
public:
    nocopymoveable() = default;
    nocopymoveable(const nocopymoveable &) = delete;
    nocopymoveable(nocopymoveable &&) = delete;
    nocopymoveable& operator = (const nocopymoveable &) = delete;
    nocopymoveable& operator = (nocopymoveable &&) = delete;
};

class StaticSingleton : private nocopymoveable
{
private:
    StaticSingleton() = default;

public:
    static StaticSingleton& instance()
    {
        static StaticSingleton _instance;
        return _instance;
    }

    std::string data() const { return _data; }
    void setData(const std::string &data) { _data = data; }

private:
    std::string _data{"Default Data"};
};

class DynamicSingleton : private nocopymoveable
{
private:
    DynamicSingleton() = default;

public:
    static std::unique_ptr<DynamicSingleton>& instance()
    {
        static std::unique_ptr<DynamicSingleton> _instance{new DynamicSingleton};
        if (!_instance)
            _instance.reset(new DynamicSingleton);

        return _instance;
    }

    static void resetInstance()
    {
        instance().reset();
    }

    std::string data() const { return _data; }
    void setData(const std::string &data) { _data = data; }

private:
    std::string _data{"Default Data"};
};

#endif // SINGELTON_H
