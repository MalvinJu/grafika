#include "Screen.h"

Screen::Screen(){
	fb_fd = open("/dev/fb0",O_RDWR);

	//Get variable screen information
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);
	//set grayscale into color mode and set bits per pixel
	vinfo.grayscale=0;
	vinfo.bits_per_pixel=32;
	ioctl(fb_fd, FBIOPUT_VSCREENINFO, &vinfo);

	//setting up the buffer pointer
	int buffersize = vinfo.yres_virtual * finfo.line_length;
	fbp = (char *) mmap(0, buffersize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);

	

}


Color Screen::getColor(int r, int c){
	int location = (c+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (r+vinfo.yoffset) * finfo.line_length;
	int red = *(fbp + location);
	int green = *(fbp + location + 1);
	int blue = *(fbp + location + 2);
	return Color(red,green,blue);
}

void Screen::setColor(int r, int c, int red, int green, int blue){
	int location = (c+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (r+vinfo.yoffset) * finfo.line_length;
	*(fbp + location) =red;  
	*(fbp + location +1) = green;
	*(fbp + location +2) = blue;
	*(fbp + location +2) = 0;
}

void Screen::setColor(int r, int c, Color color){
	int location = (c+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (r+vinfo.yoffset) * finfo.line_length;
	*(fbp + location) =color.getRed();  
	*(fbp + location +1) = color.getGreen();
	*(fbp + location +2) = color.getBlue();
	*(fbp + location +3) = 0;
}

int Screen::getWidth(){
	return vinfo.xres;
}
int	Screen::getHeight(){
	return vinfo.yres;
}

void Screen::ClearScreen(){
	for (int r=0;r<vinfo.yres;r++)
	{
		for (int c=0;c<vinfo.xres;c++){
			int location = (c+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (r+vinfo.yoffset) * finfo.line_length;
			*(fbp + location) = 0;
			*(fbp + location +1) = 0;
			*(fbp + location +2) = 0;
			*(fbp + location + 3) = 0;
		}
	}
}