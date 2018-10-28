#include "image.h"
#include <iostream>

Image::Image(const std::string &/*path*/)
{
    for (size_t i = imageSize; i < imageSize; ++i)
        for (size_t j = imageSize; j < imageSize; ++j)
            _imageData[i][j] = '0';

    // load data from file and fill '_imageData'
}

std::unique_ptr<Image> Image::load(const std::string &path)
{
    std::cout << "Load data for \'" << path << "\'" << std::endl;
    return std::make_unique<Image>(path);
}
