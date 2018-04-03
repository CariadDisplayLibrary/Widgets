Widgets
=======

This is a small collection of basic (and somewhat uninspiring, yet functional) widgets.  All these
widgets inherit from the Widget class and all Widget methods are available to them.

Button
------

This is a basic rectangular button with text and an optional 3D effect.

Constructor:

    twButton button(ts, tft, x, y, width, height, text);

Custom configuration functions:

    button.setBackgroundColour(normal, highlight);
    button.setTextColor(normal, highlight);
    button.setBevel(depth);
    button.setBevelColor(topleft, bottomright);
    button.setFont(font);
    button.setLabel(text);

The bevel colours are drawn as the "topleft" colour in the top and left 
edges and "bottomright" in the bottom and right edges when the button is not active,
and switched over when active.

Horizontal Bar
--------------

This is a horizontal percentage or progress bar. 

Constructor:

    twHBar bar(ts, tft, x, y, width, height);

Custom configuration functions:

    bar.setBorderColor(color);
    bar.setScaleColor(color);
    bar.setBackgroundColor(color);
    bar.setMinimum(value);
    bar.setMaximum(value);
    bar.setValue(value);

All values are 32-bit signed integers.

Icon
----

This draws a raw RGB565 image as an icon and places some text underneath it.

Constructor:

    twIcon icon(ts, tft, x, y, width, height, text, icon, font);

Custom configuration functions:

    icon.setBackgroundColor(color);
    icon.setTextColor(color);
    icon.setFont(font);
    icon.setLabel(text);

The width and height parameters in the constructor define the size of 
the icon image and excludes the dimensions of the text underneath.

Animated Icon
-------------

This functions like the normal Icon except the icon data passed to it 
contains a number of frames of image.  Each frame is associated with
a specific widget value.

Icon data should be prefixed with a short 6-byte header consisting of
three 16-bit values.

* Frames
* Width
* Height

The frames is the number of frames in the data block. Width and Height
define the size of a single frame.  The amount of data should be
Width * Height * Frames * 2 bytes.

Constructor:

    twAnimIcon icon(ts, tft, x, y, text, data, font);

Custom configuration functions:

    icon.setBackgroundColor(color);
    icon.setTextColor(color);
    icon.setFont(font);
    icon.setLabel(text);

Getting the icon dimensions:

    int w = icon.getWidth();
    int h = icon.getHeight();

Static Text
-----------

This is a convenient way of displaying static text within a page. It allows
for various alignments of the text to the coordinates.  The text can also be
modified programatically.

Constructor:

    twText text(ts, tft, x, y, color, font, text);

Custom configuration functions:

    text.setAlign(alignment);
    text.setText(text);

The alignment can be one of: twText::AlignLeft (or 0), twText::AlignRight (or 1), or twText::AlignCenter (or 2).
