#include "unitimagesfactory.h"
#include "image.h"

std::map<std::string, std::shared_ptr<Image>> Flyweight::UnitImagesFactory::_images;

std::shared_ptr<Image> Flyweight::UnitImagesFactory::create_dragon_image()
{
    if (_images.empty())
        init();

    return _images["Dragon"];
}

std::shared_ptr<Image> Flyweight::UnitImagesFactory::create_goblin_image()
{
    if (_images.empty())
        init();

    return _images["Goblin"];
}

void Flyweight::UnitImagesFactory::init()
{
    _images["Dragon"] = Image::load("Dragon.jpg");
    _images["Goblin"] = Image::load("Goblin.jpg");
}
