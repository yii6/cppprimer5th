/*Author
	whulinus 1034765650@qq.com
Program
	exercise 7.23
History
	version 1.0  2016.6.3
	version 2.0  2016.6.5
	add class Window_mgr, add size member
	version 3.0  2016.8.21
	add class template
*/
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <vector>
template<typename>struct Screen;
template<typename T>struct Window_mgr {
    using ScreenIndex=typename std::vector<Screen<T>>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen<T>> screens;
};
template <typename T>std::istream &operator>>(std::istream &, Screen<T> &);
template <typename T>std::ostream &operator<<(std::ostream &, const Screen<T> &);
template<typename T>class Screen {
public:
    typedef typename T::size_type pos;
//friends
    friend void Window_mgr<T>::clear(Window_mgr<T>::ScreenIndex);
    friend std::istream &operator>> <T>(std::istream &, Screen<T> &);
    friend std::ostream &operator<< <T>(std::ostream &, const Screen<T> &);
//constructors
    Screen()=default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' ') {}
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c) {}
//functions
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht,pos wd) const;
    Screen &move (pos r,pos c);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    Screen &set(char);
    Screen &set(pos,pos,char);
    pos size() const;
private:
    pos cursor=0;
    pos height=0,width=0;
    std::string contents;
//private functions
    void do_display(std::ostream &os) const {
        os<<contents;
    }
};
//other overloaded operator
template<typename T>std::istream &operator>>(std::istream &is, Screen<T> &s){
	is>>s.cursor>>s.height>>s.width>>s.contents;
	return is;
}
template<typename T>std::ostream &operator<<(std::ostream &os, const Screen<T> &s){
	os<<s.cursor<<" "<<s.height<<" "<<s.width<<" "<<s.contents;
	return os;
}
//public functions
template<typename T>typename Screen<T>::pos Screen<T>::size() const {
    return height*width;
}
template<typename T>char Screen<T>::get(pos r,pos c) const {
    pos row=r*width;
    return contents[row+c];
}
template<typename T>inline Screen<T> &Screen<T>::move(pos r,pos c) {
    pos row =r*width;
    cursor=row+c;
    return *this;
}
template<typename T>inline Screen<T> &Screen<T>::set(char c) {
    contents[cursor]=c;
    return *this;
}
template<typename T>inline Screen<T> &Screen<T>::set(pos r,pos col,char c) {
    contents[r*width+col]=c;
    return *this;
}
//other functions
template<typename T>void Window_mgr<T>::clear(ScreenIndex i) {
    Screen<T> &s=screens[i];
    s.contents=std::string(s.height*s.width,' ');
}
#endif

