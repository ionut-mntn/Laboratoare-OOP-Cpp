/*
#include "Controller.h"

template<typename repo_type>
Controller<repo_type>::Controller(repo_type repository) : repo(repository)
{
}


template<typename repo_type>
repo_type Controller<repo_type>::getRepo() { return repo; }
*/

#include "Controller.h"
Controller::Controller( Repository r ) // nu inteleg asa dc nu merge
//Controller::Controller( Repository repo  ) //
{
//	this->repo = r;
	repo = r;
}

/*
Controller::Controller()
{
	repo = 
}
*/

Repository& Controller::getRepo()
{
	// return (this);
//	return &repo;
	return repo;
}

void Controller::setRepo(Repository value)
{
	repo = value
}
