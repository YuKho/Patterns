#ifndef SINGLTON_H
#define SINGLTON_H

class Singlton
{
public:
    Singlton(const Singlton &) = delete;
    Singlton(Singlton &&) = delete;
    Singlton& operator = (const Singlton &) = delete;
    Singlton& operator = (Singlton &&) = delete;

    static const Singlton& instance()
    {
        const static Singlton _instance;
        return _instance;
    }

private:
    Singlton() = default;
};

#endif // SINGLTON_H
