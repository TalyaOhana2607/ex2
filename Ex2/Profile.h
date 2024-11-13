#pragma once
#include "UserList.h"
#include "Page.h"
#include <string>

class Profile
{
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(const std::string new_status);
	void addPostToProfilePage(const std::string post);
	void addFriend(const User friend_to_add);
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;
	void changeAllWordsInStatus(const std::string word);
	void changeWordInStatus(const std::string word_to_replace, const std::string word);

private:
	User _owner;
	UserList _friends;
	Page _page;
};