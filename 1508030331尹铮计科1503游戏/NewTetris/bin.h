#include"stdafx.h"
#ifndef _BIN_H   //�����ظ�����
#define _BIN_H
class CBin 
{
    private:
        unsigned char** image;
        unsigned int width;
        unsigned int height;
        
    public:
        CBin(unsigned int w, unsigned int h);//���캯��
        ~CBin();
       
        unsigned int getWidth() { return width; };//��ȡ���ο��
        unsigned int getHeight() { return height; };//��ȡ���θ߶�
        
        void getImage(unsigned char** destImage);//��ȡӡ������
        void setImage(unsigned char** srcImage);//����ӡ������
        
        unsigned int removeFullLines();//ɾ������
};
#endif
