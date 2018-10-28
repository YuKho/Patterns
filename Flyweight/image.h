#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <memory>

class Image
{
public:
    explicit Image(const std::string &);
    static std::unique_ptr<Image> load(const std::string &path);

private:
    static const size_t imageSize = 10000;
    char _imageData[imageSize][imageSize] {{'0'}};
};

#endif // IMAGE_H
