#pragma once
template<typename repo_type> 
class Controller
{

private:
	repo_type repo;

public:
	Controller(repo_type repository);

	// repo_type* getRepo(); {return &repo;}
	repo_type getRepo();

};