#include "Controller.h"
Controller::Controller( Repository repo ) 
{
	this->repo = repo;
}


Repository& Controller::getRepo() {
	return repo;
}

void Controller::setRepo(Repository value) { 
	repo = value;
}