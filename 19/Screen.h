/*Author
	whulinus 1034765650@qq.com
Program
	exercise 7.23
History
	version 1.0  2016.6.3
	version 2.0  2016.10.19
	add class member pointer
*/
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
class Link_screen;
struct Screen{
	typedef std::string::size_type pos;
	Screen()=default;
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){}
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
	char get() const{return contents[cursor];}
	inline char get(pos ht,pos wd) const;
	Screen move (pos r,pos c);
	Screen display(std::ostream &os){
		do_display(os);
		return *this;
	}
	const Screen display(std::ostream &os) const{
		do_display(os);
		return *this;
	}
	Screen set(char);
	Screen set(pos,pos,char);
	static const std::string::size_type Screen::*cur(){
		return &Screen::cursor;
	}
private:
	pos cursor=0;
	pos height=0,width=0;
	std::string contents;
	void do_display(std::ostream &os) const {os<<contents;}
	Link_screen *next;
};
class Link_screen{
	Screen window;
};
char Screen::get(pos r,pos c) const{
	pos row=r*width;
	return contents[row+c];
}
inline Screen Screen::move(pos r,pos c){
	pos row =r*width;
	cursor=row+c;
	return *this;
}
inline Screen Screen::set(char c){
	contents[cursor]=c;
	return *this;
}
inline Screen Screen::set(pos r,pos col,char c){
	contents[r*width+col]=c;
	return *this;
}
#endif

