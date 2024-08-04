#ifndef IMAGE_MENU_H
#define IMAGE_MENU_H

#include "braille_canvas.h"
#include "ui_resize.h"
#include <memory>
namespace ImageMenu{
void resize(BrailleCanvas* canvas, std::unique_ptr<QDialog> dialog, std::unique_ptr<Ui_Resize>);
void crop_to_content();
}

#endif
