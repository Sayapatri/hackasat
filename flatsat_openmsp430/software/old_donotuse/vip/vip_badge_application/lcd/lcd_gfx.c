/*
This is the core graphics library for all our displays, providing a common
set of graphics primitives (points, lines, circles, etc.).  It needs to be
paired with a hardware-specific library for each display device we carry
(to handle the lower-level functions).

Adafruit invests time and resources providing this open source code, please
support Adafruit & open-source hardware by purchasing products from Adafruit!
 
Copyright (c) 2013 Adafruit Industries.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
#include <string.h>
#include "lcd_hal.h"
#include "lcd_gfx.h"
#include "glcdfont.c"

#define TRUE 	1
#define FALSE 	0

int16_t CONST_WIDTH, CONST_HEIGHT;   // This is the 'raw' display w/h - never changes
int16_t cur_width, cur_height, cursor_x, cursor_y;
uint16_t textcolor, textbgcolor, bgcolor, fgcolor, hlcolor;
uint8_t textsize, rotation, textwrap;

void lcd_init_gfx(int16_t w, int16_t h)
{
  CONST_WIDTH = w;
  CONST_HEIGHT = h;
  cur_width    = w;
  cur_height   = h;
  rotation  = 0;
  cursor_y  = cursor_x    = 0;
  textsize  = 1;
  hlcolor = textcolor = 0xffff;
  textbgcolor = 0x0000;
  textwrap = 1;
}
/*
// Draw a circle outline
void lcd_gfx_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) 
{
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  lcd_drawPixel(x0  , y0+r, color);
  lcd_drawPixel(x0  , y0-r, color);
  lcd_drawPixel(x0+r, y0  , color);
  lcd_drawPixel(x0-r, y0  , color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    lcd_drawPixel(x0 + x, y0 + y, color);
    lcd_drawPixel(x0 - x, y0 + y, color);
    lcd_drawPixel(x0 + x, y0 - y, color);
    lcd_drawPixel(x0 - x, y0 - y, color);
    lcd_drawPixel(x0 + y, y0 + x, color);
    lcd_drawPixel(x0 - y, y0 + x, color);
    lcd_drawPixel(x0 + y, y0 - x, color);
    lcd_drawPixel(x0 - y, y0 - x, color);
  }
}

void lcd_gfx_drawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color) 
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      lcd_drawPixel(x0 + x, y0 + y, color);
      lcd_drawPixel(x0 + y, y0 + x, color);
    } 
    if (cornername & 0x2) {
      lcd_drawPixel(x0 + x, y0 - y, color);
      lcd_drawPixel(x0 + y, y0 - x, color);
    }
    if (cornername & 0x8) {
      lcd_drawPixel(x0 - y, y0 + x, color);
      lcd_drawPixel(x0 - x, y0 + y, color);
    }
    if (cornername & 0x1) {
      lcd_drawPixel(x0 - y, y0 - x, color);
      lcd_drawPixel(x0 - x, y0 - y, color);
    }
  }
}

void lcd_gfx_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) 
{
  lcd_gfx_drawFastVLine(x0, y0-r, 2*r+1, color);
  lcd_gfx_fillCircleHelper(x0, y0, r, 3, 0, color);
}

// Used to do circles and roundrects
void lcd_gfx_fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) 
{

  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f     += ddF_y;
    }
    x++;
    ddF_x += 2;
    f     += ddF_x;

    if (cornername & 0x1) {
      lcd_gfx_drawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
      lcd_gfx_drawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
    }
    if (cornername & 0x2) {
      lcd_gfx_drawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
      lcd_gfx_drawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
    }
  }
}
*/
uint16_t abs(uint16_t x)
{
  return x>=0? x : -x;
}

// Bresenham's algorithm - thx wikpedia
void lcd_gfx_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) 
{
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    swap(x0, y0);
    swap(x1, y1);
  }

  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++) {
    if (steep) {
      lcd_drawPixel(y0, x0, color);
    } else {
      lcd_drawPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

// Draw a rectangle
void lcd_gfx_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) 
{
  lcd_gfx_drawFastHLine(x, y, w, color);
  lcd_gfx_drawFastHLine(x, y+h-1, w, color);
  lcd_gfx_drawFastVLine(x, y, h, color);
  lcd_gfx_drawFastVLine(x+w-1, y, h, color);
}

void lcd_gfx_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) 
{
  // Update in subclasses if desired!
  lcd_gfx_drawLine(x, y, x, y+h-1, color);
}

void lcd_gfx_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) 
{
  // Update in subclasses if desired!
  lcd_gfx_drawLine(x, y, x+w-1, y, color);
}
/*
// Draw a rounded rectangle
void lcd_gfx_drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color) 
{
  // smarter version
  lcd_gfx_drawFastHLine(x+r  , y    , w-2*r, color); // Top
  lcd_gfx_drawFastHLine(x+r  , y+h-1, w-2*r, color); // Bottom
  lcd_gfx_drawFastVLine(x    , y+r  , h-2*r, color); // Left
  lcd_gfx_drawFastVLine(x+w-1, y+r  , h-2*r, color); // Right
  // draw four corners
  lcd_gfx_drawCircleHelper(x+r    , y+r    , r, 1, color);
  lcd_gfx_drawCircleHelper(x+w-r-1, y+r    , r, 2, color);
  lcd_gfx_drawCircleHelper(x+w-r-1, y+h-r-1, r, 4, color);
  lcd_gfx_drawCircleHelper(x+r    , y+h-r-1, r, 8, color);
}

// Fill a rounded rectangle
void lcd_gfx_fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color) 
{
  // smarter version
  lcd_fillRect(x+r, y, w-2*r, h, color);

  // draw four corners
  lcd_gfx_fillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, color);
  lcd_gfx_fillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, color);
}

// Draw a triangle
void lcd_gfx_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) 
{
  lcd_gfx_drawLine(x0, y0, x1, y1, color);
  lcd_gfx_drawLine(x1, y1, x2, y2, color);
  lcd_gfx_drawLine(x2, y2, x0, y0, color);
}

// Fill a triangle
void lcd_gfx_fillTriangle ( int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) 
{

  int16_t a, b, y, last;

  // Sort coordinates by Y order (y2 >= y1 >= y0)
  if (y0 > y1) {
    swap(y0, y1); swap(x0, x1);
  }
  if (y1 > y2) {
    swap(y2, y1); swap(x2, x1);
  }
  if (y0 > y1) {
    swap(y0, y1); swap(x0, x1);
  }

  if(y0 == y2) { // Handle awkward all-on-same-line case as its own thing
    a = b = x0;
    if(x1 < a)      a = x1;
    else if(x1 > b) b = x1;
    if(x2 < a)      a = x2;
    else if(x2 > b) b = x2;
    lcd_gfx_drawFastHLine(a, y0, b-a+1, color);
    return;
  }

  int16_t
    dx01 = x1 - x0,
    dy01 = y1 - y0,
    dx02 = x2 - x0,
    dy02 = y2 - y0,
    dx12 = x2 - x1,
    dy12 = y2 - y1,
    sa   = 0,
    sb   = 0;

  // For upper part of triangle, find scanline crossings for segments
  // 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
  // is included here (and second loop will be skipped, avoiding a /0
  // error there), otherwise scanline y1 is skipped here and handled
  // in the second loop...which also avoids a /0 error here if y0=y1
  // (flat-topped triangle).
  if(y1 == y2) last = y1;   // Include y1 scanline
  else         last = y1-1; // Skip it

  for(y=y0; y<=last; y++) {
    a   = x0 + sa / dy01;
    b   = x0 + sb / dy02;
    sa += dx01;
    sb += dx02;

    if(a > b) swap(a,b);
    lcd_gfx_drawFastHLine(a, y, b-a+1, color);
  }

  // For lower part of triangle, find scanline crossings for segments
  // 0-2 and 1-2.  This loop is skipped if y1=y2.
  sa = dx12 * (y - y1);
  sb = dx02 * (y - y0);
  for(; y<=y2; y++) {
    a   = x1 + sa / dy12;
    b   = x0 + sb / dy02;
    sa += dx12;
    sb += dx02;
  
    if(a > b) swap(a,b);
    lcd_gfx_drawFastHLine(a, y, b-a+1, color);
  }
}
*/

void lcd_gfx_drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) 
{

  int16_t i, j, byteWidth = (w + 7) / 8;

  for(j=0; j<h; j++) {
    for(i=0; i<w; i++ ) {
      if( *(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
	lcd_drawPixel(x+i, y+j, color);
      }
    }
  }
}

void lcd_gfx_drawBitmap16(int16_t x, int16_t y,  uint8_t *bitmap, uint16_t *palette, uint8_t width, uint8_t height, uint8_t scale) 
{

  int16_t i, j;
  int index;
  for(j=0; j<height*scale; j++) {
    for(i=0; i<width*scale; i++ ) {
      index = (j/scale)*width + i/scale;
      if(index % 2 == 0)
      {
        if((palette[bitmap[index/2] >> 4]) != 0x1234)
          lcd_drawPixel(x+i, y+j, palette[bitmap[index/2] >> 4]);
      }
      else
      {
        if((palette[bitmap[index/2] & 0x0f]) != 0x1234)
          lcd_drawPixel(x+i, y+j, palette[bitmap[index/2] & 0x0f]);
      }
    }
  }
}

/*
void lcd_gfx_drawBitmap24(uint8_t *bitmap, uint8_t x, uint8_t y) {

  int      bmpWidth, bmpHeight;   // W+H in pixels
  uint8_t  bmpDepth;              // Bit depth (currently must be 24)
  uint32_t bmpImageoffset;        // Start of image data in file
  uint32_t rowSize;               // Not always = bmpWidth; may have padding
  uint8_t  *bitmap_idx = bitmap; // Current position in bitmap
  uint8_t  flip    = 1;        // BMP is stored bottom-to-top
  int      w, h, row, col;
  uint8_t  r, g, b;
  uint32_t pos = 0;

  if((x >= cur_width) || (y >= cur_height)) return;

  // Parse BMP header
  if(*(uint16_t *)bitmap_idx == 0x4D42) { // BMP signature
    bitmap_idx+=2;
    bitmap_idx+=4; // File size
    bitmap_idx+=4; // Read & ignore creator bytes
    bmpImageoffset = *(uint32_t *)bitmap_idx; bitmap_idx+=4;// Start of image data
    // Read DIB header
    bitmap_idx+=4; // DIB Header size
    bmpWidth  = *(uint32_t *)bitmap_idx; bitmap_idx+=4;
    bmpHeight = *(uint32_t *)bitmap_idx; bitmap_idx+=4;
    
    if(*(uint16_t *)bitmap_idx == 1){ // # planes -- must be '1'
      bitmap_idx+=2;
      bmpDepth = *(uint16_t *)bitmap_idx; bitmap_idx+=2; // bits per pixel
      if((bmpDepth == 24) && (*(uint32_t *)bitmap_idx == 0)) { // 0 = uncompressed
        bitmap_idx+=4;
        

        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * 3 + 3) & ~3;

        // If bmpHeight is negative, image is in top-down order.
        // This is not canon but has been observed in the wild.
        if(bmpHeight < 0) {
          bmpHeight = -bmpHeight;
          flip      = 0;
        }

        // Crop area to be loaded
        w = bmpWidth;
        h = bmpHeight;
        if((x+w-1) >= cur_width)  w = cur_width  - x;
        if((y+h-1) >= cur_height) h = cur_height - y;

        // Set TFT address window to clipped image bounds
        lcd_setAddrWindow(x, y, x+w-1, y+h-1);
        LCD_PORT |= LCD_RS_BIT;
        LCD_PORT &= ~LCD_CSN_BIT;
        for (row=0; row<h; row++) { // For each scanline...

          if(flip) // Bitmap is stored bottom-to-top order (normal BMP)
            pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
          else     // Bitmap is stored top-to-bottom
            pos = bmpImageoffset + row * rowSize;
          
          bitmap_idx = (uint8_t *)pos;
          for (col=0; col<w; col++) { // For each pixel...
            
            // Convert pixel from BMP to TFT format, push to display
            b = *bitmap_idx++;
            g = *bitmap_idx++;
            r = *bitmap_idx++;
            lcd_pushColor(lcd_gfx_color565(r,g,b));
          } // end pixel
        } // end scanline
        LCD_PORT |= LCD_CSN_BIT;
      } // end goodBmp
    }
  }
}

uint16_t lcd_gfx_color565(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}
*/

// Draw a character
int8_t lcd_gfx_drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) 
{
  int8_t i, j;

  if((x >= cur_width)            || // Clip right
     (y >= cur_height)           || // Clip bottom
     ((x + 6 * size - 1) < 0) || // Clip left
     ((y + 8 * size - 1) < 0))   // Clip top
    return -1;

  for (i=0; i<6; i++ ) 
  {
    uint8_t line;
    if (i == 5) 
      line = 0x0;
    else 
      line = *(glcd_font+(c*5)+i);
    
    for (j = 0; j<8; j++) 
    {
      if (line & 0x1) 
      {
        if (size == 1) // default size
          lcd_drawPixel(x+i, y+j, color);
        else 
        {  // big size
          lcd_fillRect(x+(i*size), y+(j*size), size, size, color);
        } 
      } 
      else if (bg != color) 
      {
        if (size == 1) // default size
          lcd_drawPixel(x+i, y+j, bg);
        else {  // big size
          lcd_fillRect(x+i*size, y+j*size, size, size, bg);
        }
      }
      line >>= 1;
    }
  }
  return 1;
}


// This function will print a character string to the screen
// it automatically moves the cursor position as text is printed
void lcd_gfx_print(char *s)
{
  // Print each character
  while(*s != 0x00){
    if (*s == 0x0A){
      // Overwrite the rest of the line 
      lcd_fillRect(cursor_x, cursor_y, cur_width - cursor_x, textsize*7+2, textbgcolor);
      cursor_y += 7*textsize +2;
      cursor_x = 0;
    }
    else{
      if (cursor_x + textsize*5 > cur_width) {
        //Wrap Line 
        cursor_x = 0;
        cursor_y += 7*textsize + 2 ;
        if (!textwrap)
        {
          //Discard remainder of line
          return;
        }
      }
      if (cursor_y + textsize*7 > cur_height) {
        // Wrap Screen
        cursor_y = 0;
      }
      lcd_gfx_drawChar(cursor_x, cursor_y, *s, textcolor, textbgcolor, textsize);
      cursor_x += textsize*5 + 1;
    }
    s++;
  }
}


void lcd_gfx_printCenter(char *s)
{
  uint8_t length;
  uint8_t x;
  uint8_t l,r, size ;
  char buf[27];
  length = strlen(s);
  l = r = size = 0;
  while(l < length)
  {
    while((s[r]!='\n') && (r < length))
      r++;
    r++; // Include the '\n' or '\0'
    size = r - l;
    if (size > 26)
      size = 26;

    memcpy(&buf, &s[l], size);
    buf[size] = '\0';
    while((buf[size-1]=='\0') || (buf[size-1]=='\n'))
    {
      size--;
    }
    if (size > (cur_width/(textsize*5 + 1)))
      x = 0;
    else
    {
      x = (cur_width - (size*(textsize*5 + 1)))/2;
    }
    cursor_x = x;
    lcd_gfx_print((char *)&buf);
    l = r;
  }
}

void lcd_gfx_printMenu(char * menu[], uint8_t length, uint8_t selection){
  uint8_t i;
  uint16_t orig_textcolor, orig_bgcolor;
  orig_textcolor = textcolor;
  orig_bgcolor = textbgcolor;

  cursor_x = cursor_y = 0;
  for (i = 0; i < length; i++)
  {
    if (i == selection){
      textcolor = orig_bgcolor;
      textbgcolor = orig_textcolor;
    }
    else{
      textcolor = orig_textcolor;
      textbgcolor = orig_bgcolor;
    }
    lcd_gfx_print(menu[i]);
    lcd_gfx_print("\n");
  }
  textcolor = orig_textcolor;
  textbgcolor = orig_bgcolor;
  
}

/*
// Draw a character
void lcd_gfx_drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) 
{
  int8_t i, j;

  if((x >= cur_width)            || // Clip right
     (y >= cur_height)           || // Clip bottom
     ((x + 6 * size - 1) < 0) || // Clip left
     ((y + 8 * size - 1) < 0))   // Clip top
    return;

  for (i=0; i<6; i++ ) {
    uint8_t line;
    if (i == 5) 
      line = 0x0;
    else 
      line = *(glcd_font+(c*5)+i);
    for (j = 0; j<8; j++) {
      if (line & 0x1) {
        if (size == 1) // default size
          lcd_drawPixel(x+i, y+j, color);
        else {  // big size
          lcd_fillRect(x+(i*size), y+(j*size), size, size, color);
        } 
      } else if (bg != color) {
        if (size == 1) // default size
          lcd_drawPixel(x+i, y+j, bg);
        else {  // big size
          lcd_fillRect(x+i*size, y+j*size, size, size, bg);
        }
      }
      line >>= 1;
    }
  }
}
*/

void lcd_gfx_setCursor(int16_t x, int16_t y) 
{
  cursor_x = x;
  cursor_y = y;
}

void lcd_gfx_setTextSize(uint8_t s) 
{
  textsize = (s > 0) ? s : 1;
}

void lcd_gfx_setTextColor(uint16_t c, uint16_t b) 
{
  textcolor   = c;
  textbgcolor = b; 
}

uint8_t lcd_gfx_getRotation(void) 
{
  return rotation;
}

void lcd_gfx_setRotation(uint8_t x) 
{
  rotation = (x & 3);
  switch(rotation) {
   case 0:
   case 2:
    cur_width  = CONST_WIDTH;
    cur_height = CONST_HEIGHT;
    break;
   case 1:
   case 3:
    cur_width  = CONST_HEIGHT;
    cur_height = CONST_WIDTH;
    break;
  }
}

// Return the size of the display 
int16_t lcd_gfx_getWidth(void) 
{
  return cur_width;
}
 
int16_t lcd_gfx_getHeight(void) 
{
  return cur_height;
}

// Set the size of the display 
void lcd_gfx_setWidth(uint16_t w) 
{
  cur_width = w;
}
 
void lcd_gfx_setHeight(uint16_t h) 
{
  cur_height = h;
}

uint16_t lcd_gfx_getBackgroundColor(){
  return bgcolor;
}

void lcd_gfx_setBackgroundColor(uint16_t color){
  bgcolor = color;
}


void lcd_gfx_setTextWrap(uint8_t w){
  textwrap = w;
}

uint16_t lcd_gfx_getForegroundColor(){
  return fgcolor;
}

void lcd_gfx_setForegroundColor(uint16_t color){
  fgcolor = color;
}

uint16_t lcd_gfx_getHighlightColor(){
  return hlcolor;
}

void lcd_gfx_setHighlightColor(uint16_t color){
  hlcolor = color;
}
