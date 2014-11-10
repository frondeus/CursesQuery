#include "game.h"

std::map<std::string, std::shared_ptr<Tag>> Tag::tags;

void GameObject::addTag(std::string t)
{
	std::shared_ptr<Tag> tag = Tag::getOrCreate(t);
	tags.insert(tag);
	tag->objects.insert(std::shared_ptr<GameObject>(this));
}

std::shared_ptr<Tag> Tag::getOrCreate(std::string t)
{
	auto it = tags.find(t);
	if(it != tags.end())
	{
	   return it->second;
	}

	std::shared_ptr<Tag> tag(new Tag(t));
	tags[t] = tag;
	return tag;
}

Tag::Tag(std::string n) : name("#" + n)
{

}





