/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 *	Message.h
 *History
 *	ver 1.0 2016.7.17
 *	ver 2.0 2016.7.21
 *	add move()
 */
#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <iostream>
#include <set>
class Folder;
class Message{
//friends
	friend class Folder;
	friend void swap(Message&,Message&);
public:
//constructor
	explicit Message(const std::string &str=""):contents(str){}
//copy constructor
	Message(const Message &); 
//move constructor
	Message(Message&&);
//copy-assignment operator
    Message &operator=(const Message&);
//move-assignment operator
	Message &operator=(Message&&);
//destructor
    ~Message();
//functions
	void save(Folder&);
	void remove(Folder&);
	void move_Folders(Message *);
private:
	std::string contents;
	std::set<Folder*> folders;
//private funcs
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFold(Folder *const);
	void remFold(Folder *const);
};
void Message::addFold(Folder *const f){
	folders.insert(f);
}
void Message::remFold(Folder *const f){
	folders.erase(f);
}
//copy control members
Message::Message(const Message &m):contents(m.contents),folders(m.folders){
	add_to_Folders(m);
}
Message::Message(Message &&m):contents(move(m.contents)){
	move_Folders(&m);
}
Message& Message::operator=(const Message &rhs){
	remove_from_Folders();
	contents=rhs.contents;
	folders=rhs.folders;
	add_to_Folders(rhs);
	return *this;
}
Message& Message::operator=(Message &&rhs){
	if(this!=&rhs){
		remove_from_Folders();
		contents=move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}
Message::~Message() {
	remove_from_Folders();
}

class Folder{
//friends
	friend class Message;
public:
//constructor
	Folder(){}
//copy constructor
	Folder(const Folder &); 
//copy-assignment operator
    Folder& operator=(const Folder&);
//destructor
    ~Folder();
//functions
	void addMsg(Message * m){
	msgs.insert(m);
}
	void remMsg(Message * m){
	msgs.erase(m);
}
private:
	std::set<Message*> msgs;
//private funcs
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
};
void Folder::add_to_Messages(const Folder &f){
	for(auto m:f.msgs)
		m->addFold(this);
}
void Folder::remove_from_Messages(){
	for(auto m:msgs)
		m->remFold(this);
}

//copy control members
Folder::Folder(const Folder &f):msgs(f.msgs){
	add_to_Messages(f);
}
Folder& Folder::operator=(const Folder &rhs){
	remove_from_Messages();
	msgs=rhs.msgs;
	add_to_Messages(rhs);
	return *this;
}
Folder::~Folder() {
	remove_from_Messages();
}
//functions of Message
void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_Folders(const Message &m){
	for(auto f:m.folders)
		f->addMsg(this);
}
void Message::remove_from_Folders(){
	for(auto f:folders)
		f->remMsg(this);
}
void swap(Message &lhs,Message &rhs){
	using std::swap;
	lhs.remove_from_Folders();
    rhs.remove_from_Folders();
	swap(lhs.folders,rhs.folders);
	swap(lhs.contents,rhs.contents);
	lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}
void Message::move_Folders(Message *m){
	folders=move(m->folders);
	for(auto f:folders){
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}
#endif
