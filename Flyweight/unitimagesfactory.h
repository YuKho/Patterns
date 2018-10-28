#ifndef UNITIMAGESFACTORY_H
#define UNITIMAGESFACTORY_H

#include <map>
#include <string>
#include <memory>

class Image;

namespace Flyweight
{

class UnitImagesFactory final
{
public:
    UnitImagesFactory() = delete;
    UnitImagesFactory(const UnitImagesFactory&) = delete;
    UnitImagesFactory & operator =(const UnitImagesFactory&) = delete;

    static std::shared_ptr<Image> create_dragon_image();
    static std::shared_ptr<Image> create_goblin_image();

private:
    static void init();

private:
    static std::map<std::string, std::shared_ptr<Image>> _images;
};

}

#endif // UNITIMAGESFACTORY_H
