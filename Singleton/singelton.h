#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton& operator = (const Singleton &) = delete;
    Singleton& operator = (Singleton &&) = delete;

    static const Singleton& instance()
    {
        const static Singleton _instance;
        return _instance;
    }

private:
    Singleton() = default;
};

#endif // SINGELTON_H
