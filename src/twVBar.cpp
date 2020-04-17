#include <Widgets.h>

void twVBar::draw(DisplayCore *dev, int __attribute__((unused)) x, int __attribute__((unused)) y) {
    dev->openWindow(_x, _y, _width, _height);
    int32_t pct = _value * (_height - 4) / (_max - _min);

    for (int iy = 0; iy < _height; iy++) {
        for (int ix = 0; ix < _width; ix++) {
            if (iy == 0 || ix == 0 || iy == _height-1 || ix == _width-1) {
                dev->windowData(_border);
            } else if (iy == 1 || ix == 1 || iy == _height-2 || ix == _width-2) {
                dev->windowData(_bg);
            } else if (iy >= pct+2) {
                dev->windowData(_scale);
            } else {
                dev->windowData(_bg);
            }
        }
    }
    dev->closeWindow();
}
