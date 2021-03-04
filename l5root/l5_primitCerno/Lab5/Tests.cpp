#include "Movie.h"
#include "Repository.h"
#include "Validator.h"
#include <assert.h>
#include "Controller.h"
void testAll()
{
	Repository repotest("Movies.txt");
	Controller ctrltest(repotest);
	assert(ctrltest.getRepo().getList()[0].getID() == "1");
	ctrltest.getRepo().edit("1", Movie("99", "John", "Action", 2019,99,"www.dorianpopa.ro"));
	assert(ctrltest.getRepo().getList()[0].getTitle() == "John");
	assert(ctrltest.getRepo().getList()[0].getGenre() == "Action");
	assert(ctrltest.getRepo().getList()[0].getYear() == 2019);
	assert(ctrltest.getRepo().getList()[0].getLikes() == 99);
	ctrltest.getRepo().add(Movie("101", "Hatz", "Drama", 2018, 101, "www.dorianpopa.ro"));
	int length = ctrltest.getRepo().getList().size();
	assert(ctrltest.getRepo().getList()[length - 1].getID() == "101");
	ctrltest.getRepo().del("101");
	assert(ctrltest.getRepo().getList().size() == length - 1);


}