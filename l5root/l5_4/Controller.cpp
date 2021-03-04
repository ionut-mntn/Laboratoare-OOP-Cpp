#include "Controller.h"

template<typename repo_type>
Controller<repo_type>::Controller(repo_type repository) : repo(repository)
{
}


template<typename repo_type>
repo_type Controller<repo_type>::getRepo() { return repo; }