#include "widget.h"
#include "fileselectiondialog.h"
#include <utility>
#include <iostream>

using namespace std;

Mediator::Widget::Widget(Mediator::FileSelectionDialog *mediator, std::string name)
    : _name(std::move(name)), _mediator(mediator)
{
}

Mediator::Widget::~Widget() = default;

void Mediator::Widget::changed() const
{
    _mediator->widgetChanged(this);
}

void Mediator::List::queryWidget() const
{
    cout << "   " << _name << " list queried" << endl;
}

void Mediator::List::updateWidget() const
{
    cout << "   " << _name << " list updated" << endl;
}

void Mediator::Edit::queryWidget() const
{
    cout << "   " << _name << " edit queried" << endl;
}

void Mediator::Edit::updateWidget() const
{
    cout << "   " << _name << " edit updated" << endl;
}
