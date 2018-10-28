#ifndef FILESELECTIONDIALOG_H
#define FILESELECTIONDIALOG_H

#include <array>
#include <memory>

namespace Mediator {

class Widget;

class FileSelectionDialog
{
private:
    enum Widgets { FilterEdit, DirList, FileList, SelectionEdit };

public:
    FileSelectionDialog();
    ~FileSelectionDialog();

    void handleEvent(size_t which);
    void widgetChanged(const Widget *theChangedWidget) const;

private:
    std::array<std::unique_ptr<Widget>, 4> _components;
};

}

#endif // FILESELECTIONDIALOG_H
