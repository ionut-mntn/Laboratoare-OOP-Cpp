/*
#pragma once
#include "Repository.h"
// template<typename repo_type> 
class Controller
{

private:
	Repository repo;

public:
	Controller(repo_type repository);

	// repo_type* getRepo(); {return &repo;}
	Repository getRepo();

};
*/

#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository repo;

public:

	//Controller();
	Controller(Repository r = Repository());

	Repository& getRepo();
	void setRepo(Repository value);
};
