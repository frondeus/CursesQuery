#pragma once
#include "systems.h"

class Tag;

class GameObject
{
public:
	virtual ~GameObject() {}
	void addTag(std::string t);

	std::set< std::shared_ptr<Tag> > tags;
};

class Tag
{
public:
	static std::shared_ptr<Tag> getOrCreate(std::string t);
	static std::map<std::string, std::shared_ptr<Tag>> tags;

	Tag(std::string n);

	std::string name;
	std::set<std::shared_ptr<GameObject>> objects;
};
