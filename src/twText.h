#ifndef _TWTEXT_H
#define _TWTEXT_H

#include <Widgets.h>

class twText : public Widget {
    private:
        color_t _color;
        const uint8_t *_font;
        char _text[100];
        uint8_t _align;

    public:
        static const uint8_t AlignLeft = 0;
        static const uint8_t AlignRight = 1;
        static const uint8_t AlignCenter = 2;
        twText(Touch &ts, Cariad &dev, int x, int y, color_t col, const uint8_t *f, const char *txt) : Widget(ts, dev, x, y), 
            _color(col), _font(f), _align(AlignLeft) {
            memset(_text, 0, 100);
            strncpy(_text, txt, 99);
        }
            
        void setPixel(int __attribute__((unused)) x, int __attribute__((unused)) y, color_t __attribute__((unused)) c) {} // No drawing!

        void draw(Cariad *dev, int x, int y);

        void initializeDevice() { }

        void setAlign(uint8_t align);
        void setText(const char *txt);
};

#endif
