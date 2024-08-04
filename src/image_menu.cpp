#include "image_menu.h"
#include "qdialog.h"
#include "ui_resize.h"
#include <memory>
#include "QString"

namespace ImageMenu{
void resize(BrailleCanvas* canvas, std::unique_ptr<QDialog> dialog, std::unique_ptr<Ui_Resize> resize_ui){
    auto scene = canvas->getScene();
    resize_ui->widthLineEdit->setText(QString::number(scene->width()));
    resize_ui->heightLineEdit->setText(QString::number(scene->height()));
    if (dialog->exec() == QDialog::Accepted){
        auto new_width = resize_ui->widthLineEdit->text().toInt();
        auto new_height = resize_ui->heightLineEdit->text().toInt();
        canvas->resizeGrid(new_width, new_height);
    }
}
}

