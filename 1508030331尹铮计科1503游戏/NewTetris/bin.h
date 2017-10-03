#include"stdafx.h"
#ifndef _BIN_H   //避免重复定义
#define _BIN_H
class CBin 
{
    private:
        unsigned char** image;
        unsigned int width;
        unsigned int height;
        
    public:
        CBin(unsigned int w, unsigned int h);//构造函数
        ~CBin();
       
        unsigned int getWidth() { return width; };//获取矩形宽度
        unsigned int getHeight() { return height; };//获取矩形高度
        
        void getImage(unsigned char** destImage);//获取印象数据
        void setImage(unsigned char** srcImage);//设置印象数据
        
        unsigned int removeFullLines();//删除整行
};
#endif
