/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 	StrBlob.h
 *History
 *	ver 1.0 2016.7.7
 *	ver 2.0 2016.7.10
 *	define StrBlobPtr, add friend declaration.
 *	ver 2.1 2016.7.10
 *	add ConstStrBlobPtr
 */
#ifndef VALUESTR_H
#define VALUESTR_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> li);
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &t){data->push_back(t);}
	void pop_back();
	std::string& front();
	std::string& back();
	const std::string& front()const;
	const std::string& back()const;
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin()const;
	ConstStrBlobPtr cend()const;
	StrBlob& operator=(const StrBlob &sb){
		data=std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}
	StrBlob(const StrBlob &p):data(std::make_shared<std::vector<std::string>>(*p.data)){}
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};
StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
void StrBlob::check (size_type i,const std::string &msg) const {
	if(i>=data->size())
		throw std::out_of_range(msg);
}
std::string & StrBlob::front(){
	check(0,"front on empty StrBlob");
	return data->front();
}
std::string & StrBlob::back(){
	check(0,"back on empty StrBlob");
	return data->back();
}
const std::string & StrBlob::front()const {
	check(0,"front on empty StrBlob");
	return data->front();
}
const std::string & StrBlob::back()const{
	check(0,"back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back(){
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}
class StrBlobPtr{
	std::shared_ptr<std::vector<std::string>> check(std::size_t ,const std::string&)const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a,std::size_t sz=0):wptr(a.data),curr(sz){}
	std::string& deref() const;
	StrBlobPtr& incr();
	std::size_t rcurr(){return curr;}
};
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i,const std::string &msg) const{
	auto ret=wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if(i>=ret->size())
		throw std::out_of_range(msg);
	return ret;
}
std::string & StrBlobPtr::deref() const{
	auto p=check(curr,"dereference past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr(){
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr StrBlob::begin(){return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end(){auto ret =StrBlobPtr(*this,data->size());return ret;}
class ConstStrBlobPtr{
	std::shared_ptr<std::vector<std::string>> check(std::size_t ,const std::string&)const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
public:
	ConstStrBlobPtr():curr(0){}
	ConstStrBlobPtr (const StrBlob &a,std::size_t sz=0) :wptr(a.data),curr(sz) {}
	std::string& deref() const;
	ConstStrBlobPtr& incr();
	std::size_t rcurr(){return curr;}
};
std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i,const std::string &msg) const{
	auto ret=wptr.lock();
	if(!ret)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if(i>=ret->size())
		throw std::out_of_range(msg);
	return ret;
}
std::string & ConstStrBlobPtr::deref() const{
	auto p=check(curr,"dereference past end");
	return (*p)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr(){
	check(curr,"increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}
ConstStrBlobPtr StrBlob::cbegin()const{return ConstStrBlobPtr(*this);}
ConstStrBlobPtr StrBlob::cend()const{auto ret =ConstStrBlobPtr(*this,data->size());return ret;}
#endif
