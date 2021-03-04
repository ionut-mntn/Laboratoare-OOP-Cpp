#include <assert.h>

#include "Tests.h"

using std::cout;

void testRepositoryConstructor()
{
	//run
	Repository r;

	//verify
	vector<Movie>& list = r.getList();
	assert(list.size() == 13);
	assert(list.at(0).getID() == "1");
	assert(list.at(5).getTitle() == "Schindler's List");
	assert(list.at(7).getYear() == 1994);
	assert(list.at(10).getLikes() == 88);
//	string aux = www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi
//	)";
//	string aux = www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi
//	)";
//	assert(list.at(11).getTrailer() == aux);
	cout << list.at(12).getTrailer() << '\n';
	assert(list.at(12).getTrailer() == "www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
	//assert()
}

void testExists()
{
	//setup

	//run

	//verify
}

void testAll()
{
	testRepositoryConstructor();
	testExists();
	/*
	Repository repotest("Movies.txt");

	Controller ctrltest(repotest);
	assert(ctrltest.getRepo().getList()[0].getID() == "1");
	ctrltest.getRepo().edit("1", Movie("99", "John", "Action", 2019, 99, "www.dorianpopa.ro"));
	assert(ctrltest.getRepo().getList()[0].getTitle() == "John");
	assert(ctrltest.getRepo().getList()[0].getGenre() == "Action");
	assert(ctrltest.getRepo().getList()[0].getYear() == 2019);
	assert(ctrltest.getRepo().getList()[0].getLikes() == 99);
	ctrltest.getRepo().add(Movie("101", "Hatz", "Drama", 2018, 101, "www.dorianpopa.ro"));
	int length = ctrltest.getRepo().getList().size();
	assert(ctrltest.getRepo().getList()[length - 1].getID() == "101");
	ctrltest.getRepo().del("101");
	assert(ctrltest.getRepo().getList().size() == length - 1);
	*/
}