#include "fileselectiondialog.h"
#include "widget.h"
#include <iostream>

Mediator::FileSelectionDialog::FileSelectionDialog()
{
    _components[FilterEdit] = std::make_unique<Edit>(this, "filter");
    _components[DirList] = std::make_unique<List>(this, "dir");
    _components[FileList] = std::make_unique<List>(this, "file");
    _components[SelectionEdit] = std::make_unique<Edit>(this, "selection");
}

Mediator::FileSelectionDialog::~FileSelectionDialog() = default;

void Mediator::FileSelectionDialog::handleEvent(size_t which)
{
    if (which > static_cast<size_t>(SelectionEdit))
        return;

    _components[which]->changed();
}

void Mediator::FileSelectionDialog::widgetChanged(const Mediator::Widget *theChangedWidget) const
{
    if (theChangedWidget == _components[FilterEdit].get())
    {
        std::cout << "Filter Edit changed" << std::endl;
        _components[FilterEdit]->queryWidget();
        _components[DirList]->updateWidget();
        _components[FileList]->updateWidget();
        _components[SelectionEdit]->updateWidget();
        return;
    }

    if (theChangedWidget == _components[DirList].get())
    {
        std::cout << "Dir List changed" << std::endl;
        _components[DirList]->queryWidget();
        _components[FileList]->updateWidget();
        _components[FilterEdit]->updateWidget();
        _components[SelectionEdit]->updateWidget();
        return;
    }

    if (theChangedWidget == _components[FileList].get())
    {
        std::cout << "File List changed" << std::endl;
        _components[FileList]->queryWidget();
        _components[SelectionEdit]->updateWidget();
        return;
    }

    if (theChangedWidget == _components[SelectionEdit].get())
    {
        std::cout << "Selection Edit changed" << std::endl;
        _components[SelectionEdit]->queryWidget();
        std::cout << "   file opened" << std::endl;
        return;
    }

    std::cout << "This widget will not be handled!" << std::endl;
}
