# Brent's notes

I needed to use the following command to compile the GTK code via libraries.
I kept receiving errors during compilation pertaining to the lib path otherwise.

gcc -o gtk/build/gtktest gtk/gtktest.c  $(pkg-config --cflags --libs gtk+-2.0)
