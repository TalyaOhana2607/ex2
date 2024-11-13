#include "Profile.h"

void Profile::init(User owner)
{
	_owner = owner;
	_friends.init();
	_page.init();
}

void Profile::clear()
{
	_friends.clear();
	_page.clearPage();
}

User Profile::getOwner() const
{
	return _owner;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(const User friend_to_add)
{
	_friends.add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string s = "Status: " + _page.getStatus() + "\n" + "*******************" + "\n" + "*******************" + "\n" + _page.getPosts();
	return s;
}

std::string Profile::getFriends() const
{
	std::string friends = "";
	UserNode* user = _friends.get_first();
	while (user != nullptr)
	{
		friends += user->get_data().getUserName() + ",";
		user = user->get_next();
	}
	if (!friends.empty())
	{
		friends.pop_back();
	}
	return friends;

}


std::string Profile::getFriendsWithSameNameLength()const
{
	std::string friends = "";
	UserNode* user = _friends.get_first();
	while (user != nullptr)
	{
		if (user->get_data().getUserName().length() == _owner.getUserName().length())
		{
			friends += user->get_data().getUserName() + ",";
		}
		user = user->get_next();
	}
	if (!friends.empty())
	{
		friends.pop_back();
	}
	return friends;
}

void Profile::changeAllWordsInStatus(const std::string word)
{
	const std::string status = _page.getStatus();
	std::string newStatus = "";
	bool inWord = false; 
	int wordCount = 0;
	char ch;
	unsigned int i = 0;
	for (i = 0; i < status.length(); i++)
	{

		ch = status[i];
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			newStatus += ch;
			inWord = false;
		}


		else if (inWord == false)
		{
			newStatus += word;
			inWord = true;
		}
	}
	_page.setStatus(newStatus);
}

void Profile::changeWordInStatus(const std::string word_to_replace, const std::string word)
{
	std::string status =_page.getStatus();
	while (status.find(word_to_replace) != std::string::npos)
	{
		status.replace(status.find(word_to_replace), word_to_replace.length(), word);
	}
	_page.setStatus(status);
}