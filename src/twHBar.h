#ifndef _TWHBAR_H
#define _TWHBAR_H

#include <Widgets.h>

class twHBar : public Widget {
    private:
        int32_t _min;
        int32_t _max;
        int32_t _value;
        color_t _border;
        color_t _scale;
        color_t _bg;

    public:
        twHBar(Touch &ts, Cariad &dev, int x, int y, int w, int h) : Widget(ts, dev, x, y),
           _min(0), _max(100), _value(0), _border(Color::Blue), _scale(Color::Blue), _bg(Color::Black) {
            _width = w;
            _height = h;
            _touch = true;
            _sense_x = 0;
            _sense_y = 0;
            _sense_w = w;
            _sense_h = h;
        }

        void draw(Cariad *dev, int x, int y);

        void setBorderColor(color_t c) { _border = c; }
        void setScaleColor(color_t c) { _scale = c; }
        void setBackgroundColor(color_t c) { _bg = c; }
        void setMinimum(int32_t m) { _min = m; }
        void setMaximum(int32_t m) { _max = m; }
        void setValue(int32_t m) { _value = m; redraw(); }
};

#endif
