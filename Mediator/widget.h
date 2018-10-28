#ifndef WIDGET_H
#define WIDGET_H

#include <string>

namespace Mediator
{

class FileSelectionDialog;

class Widget
{
public:
    Widget(FileSelectionDialog *mediator, std::string name);
    virtual ~Widget();
    virtual void changed() const;
    virtual void updateWidget() const = 0;
    virtual void queryWidget() const = 0;

protected:
    std::string _name;

private:
    FileSelectionDialog *_mediator{nullptr};
};

class List : public Widget
{
public:
    using Widget::Widget;

    void queryWidget() const override;
    void updateWidget() const override;
};

class Edit : public Widget
{
public:
    using Widget::Widget;

    void queryWidget() const override;
    void updateWidget() const override;
};

}

#endif // WIDGET_H
