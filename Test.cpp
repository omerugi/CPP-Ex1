
// authors: Lilach Mor & Omer Rugi



/**

 * An example of how to write unit tests.

 * Use this as a basis to build a more complete Test.cpp file.

 *

 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.

 *

 * Date: 2020-02

 */
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

bool isHanaOrSalima(){
family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara");
	if(T.find("grandmother") == string("hana")||T.find("grandmother") == string("salima"))
		return true;
	return false;
}
bool isMordohOrEliezer(){
family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara");
	if(T.find("grandfather") == string("mordoh")||T.find("grandfather") == string("eliezer"))
		return true;
	return false;
}

bool isKlaraOrMazalTov(){
family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara");
	if(T.find("great-grandmother") == string("klara")||T.find("great-grandmother") == string("mazal tov"))
		return true;
	return false;
}
bool isyehusuaOrbahor(){
family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara");

	if(T.find("great-grandfather") == string("yehushua")||T.find("great-grandfather") == string("bahor"))
		return true;
	return false;
}
bool isHayaOrKlodin(){
family::Tree T2 ("omer");
T2.addFather("omer", "yoram")
	 .addMother("omer", "tali")
	 .addFather("yoram", "shabtai")
	 .addMother("yoram", "haya")
	 .addFather("tali", "armond")
	 .addMother("tali", "klodin")
	 .addMother("haya", "jorjia")
	 .addFather("shabtai", "naim");
	if(T2.find("grandmother") == string("haya")||T2.find("grandmother") == string("klodin"))
		return true;
	return false;
}
bool isShabtaiOrArmond(){
family::Tree T2 ("omer");
T2.addFather("omer", "yoram")
	 .addMother("omer", "tali")
	 .addFather("yoram", "shabtai")
	 .addMother("yoram", "haya")
	 .addFather("tali", "armond")
	 .addMother("tali", "klodin")
	 .addMother("haya", "jorjia")
	 .addFather("shabtai", "naim");
	if(T2.find("grandfather") == string("armond")||T2.find("grandfather") == string("shabtai"))
		return true;
	return false;
}

TEST_CASE("find") {

family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara");


CHECK(T.find("me") == string("lilach"));
CHECK(T.find("mother") == string("bruria"));
CHECK(T.find("father") == string("baruh"));
CHECK(isHanaOrSalima());
CHECK(isMordohOrEliezer());
CHECK(isKlaraOrMazalTov());
CHECK(isyehusuaOrbahor());
CHECK_THROWS_AS(T.find("uncle"), std::exception);
CHECK_THROWS_AS(T.find("great-great-grandfather"), std::exception);

family::Tree T2 ("omer");
T2.addFather("omer", "yoram")
	 .addMother("omer", "tali")
	 .addFather("yoram", "shabtai")
	 .addMother("yoram", "haya")
	 .addFather("tali", "armond")
	 .addMother("tali", "klodin")
	 .addMother("haya", "jorjia")
	 .addFather("shabtai", "naim");

CHECK(T2.find("me") == string("omer"));
CHECK(T2.find("mother") == string("tali"));
CHECK(T2.find("father") == string("yoram"));
CHECK(isHayaOrKlodin());
CHECK(isShabtaiOrArmond());
CHECK(T2.find("great-grandmother") == string("jorjia"));
CHECK(T2.find("great-grandfather") == string("naim"));
CHECK_THROWS_AS(T2.find("uncle"), std::exception);
CHECK_THROWS_AS(T2.find("great-great-grandfather"), std::exception);

family::Tree T3 ("me");
T3.addFather("me", "father")
	 .addMother("me", "mother")
	 .addFather("father", "grandfather")
	 .addMother("father", "grandmother")
	 .addFather("grandmother", "great-grandfather")
	 .addMother("grandfather", "great-grandmother")
	 .addFather("great-grandfather", "great-great-grandfather")
	 .addMother("great-grandfather", "great-great-grandmother")
	.addFather("great-great-grandfather", "great-great-great-grandfather")
	.addMother("great-great-grandfather", "great-great-great-grandmother");


CHECK(T3.find("me") == string("me"));
CHECK(T3.find("mother") == string("mother"));
CHECK(T3.find("father") == string("father"));
CHECK(T3.find("grandmother") == string("grandmother"));
CHECK(T3.find("grandfather") == string("grandfather"));
CHECK(T3.find("great-grandmother") == string("great-grandmother"));
CHECK(T3.find("great-grandfather") == string("great-grandfather"));
CHECK(T3.find("great-great-grandmother") == string("great-great-grandmother"));
CHECK(T3.find("great-great-grandfather") == string("great-great-grandfather"));
CHECK(T3.find("great-great-great-grandmother") == string("great-great-great-grandmother"));
CHECK(T3.find("great-great-great-grandfather") == string("great-great-great-grandfather"));
CHECK_THROWS_AS(T3.find("uncle"), std::exception);
CHECK_THROWS_AS(T3.find("great-great-great-great-grandfather"), std::exception);
}

TEST_CASE("relation") {

family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara")
     	 .addMother("mordoh", "regina")
     	 .addFather("mordoh", "nisim")
     	 .addMother("salima", "gorgia");

CHECK(T.relation("lilach") == string("me"));
CHECK(T.relation("bruria") == string("mother"));
CHECK(T.relation("baruh") == string("father"));
CHECK(T.relation("hana") == string("grandmother"));
CHECK(T.relation("salima") == string("grandmother"));
CHECK(T.relation("eliezer") == string("grandfather"));
CHECK(T.relation("mazal tov") == string("great-grandmother"));
CHECK(T.relation("bahor") == string("great-grandfather"));
CHECK(T.relation("mordoh") == string("grandfather"));
CHECK(T.relation("klara") == string("great-grandmother"));
CHECK(T.relation("yehushua") == string("great-grandfather"));
CHECK(T.relation("regina") == string("great-grandmother"));
CHECK(T.relation("gorgia") == string("great-grandmother"));
CHECK(T.relation("nisim") == string("great-grandfather"));
CHECK(T.relation("random name") == string("unrelated"));


family::Tree T2 ("omer");
T2.addFather("omer", "yoram")
	 .addMother("omer", "tali")
	 .addFather("yoram", "shabtai")
	 .addMother("yoram", "haya")
	 .addFather("tali", "armond")
	 .addMother("tali", "klodin")
	 .addMother("haya", "jorjia")
	 .addFather("shabtai", "naim");

CHECK(T2.relation("omer") == string("me"));
CHECK(T2.relation("tali") == string("mother"));
CHECK(T2.relation("yoram") == string("father"));
CHECK(T2.relation("haya") == string("grandmother"));
CHECK(T2.relation("armond") == string("grandfather"));
CHECK(T2.relation("shabtai") == string("grandfather"));
CHECK(T2.relation("klodin") == string("grandmother"));
CHECK(T2.relation("jorjia") == string("great-grandmother"));
CHECK(T2.relation("naim") == string("great-grandfather"));
CHECK(T2.relation("random name") == string("unrelated"));

family::Tree T3 ("me");
T3.addFather("me", "father")
	 .addMother("me", "mother")
	 .addFather("father", "grandfather")
	 .addMother("father", "grandmother")
	 .addFather("grandmother", "great-grandfather")
	 .addMother("grandfather", "great-grandmother")
	 .addFather("great-grandfather", "great-great-grandfather")
	 .addMother("great-grandfather", "great-great-grandmother")
	 .addFather("great-great-grandfather", "great-great-great-grandfather")
	 .addMother("great-great-grandfather", "great-great-great-grandmother");

CHECK(T3.relation("me") == string("me"));
CHECK(T3.relation("mother") == string("mother"));
CHECK(T3.relation("father") == string("father"));
CHECK(T3.relation("grandmother") == string("grandmother"));
CHECK(T3.relation("grandfather") == string("grandfather"));
CHECK(T3.relation("great-grandmother") == string("great-grandmother"));
CHECK(T3.relation("great-grandfather") == string("great-grandfather"));
CHECK(T3.relation("great-great-grandmother") == string("great-great-grandmother"));
CHECK(T3.relation("great-great-grandfather") == string("great-great-grandfather"));
CHECK(T3.relation("great-great-great-grandmother") == string("great-great-great-grandmother"));
CHECK(T3.relation("great-great-great-grandfather") == string("great-great-great-grandfather"));
CHECK(T3.relation("random name") == string("unrelated"));
}

TEST_CASE("remove") {
family::Tree T ("lilach");
T.addFather("lilach", "baruh")
	 .addMother("lilach", "bruria")
	 .addFather("baruh", "mordoh")
	 .addMother("baruh", "salima")
	 .addFather("bruria", "eliezer")
	 .addMother("bruria", "hana")
	 .addFather("hana", "bahor")
	 .addMother("hana", "mazal tov")
	 .addFather("eliezer", "yehushua")
	 .addMother("eliezer", "klara")
         .addMother("mordoh", "regina")
         .addFather("mordoh", "nisim")
         .addMother("salima", "gorgia");

T.remove("klara");
CHECK(T.relation("klara") == string("unrelated"));
T.remove("yehushua");
CHECK(T.relation("yehushua") == string("unrelated"));
T.remove("hana");
CHECK(T.relation("hana") == string("unrelated"));
CHECK(T.relation("mazal tov") == string("unrelated"));
CHECK(T.relation("bahor") == string("unrelated"));
T.remove("eliezer");
CHECK(T.relation("eliezer") == string("unrelated"));
T.remove("nisim");
CHECK(T.relation("nisim") == string("unrelated"));
T.remove("gorgia");
CHECK(T.relation("gorgia") == string("unrelated"));
T.remove("regina");
CHECK(T.relation("regina") == string("unrelated"));
T.remove("mordoh");
CHECK(T.relation("mordoh") == string("unrelated"));
T.remove("salima");
CHECK(T.relation("salima") == string("unrelated"));
T.remove("baruh");
CHECK(T.relation("baruh") == string("unrelated"));
T.remove("bruria");
CHECK(T.relation("bruria") == string("unrelated"));
CHECK(T.relation("lilach") == string("me"));


family::Tree T2 ("omer");
T2.addFather("omer", "yoram")
	 .addMother("omer", "tali")
	 .addFather("yoram", "shabtai")
	 .addMother("yoram", "haya")
	 .addFather("tali", "armond")
	 .addMother("tali", "klodin")
	 .addMother("haya", "jorjia")
	 .addFather("shabtai", "naim");

T2.remove("naim");
CHECK(T2.relation("naim") == string("unrelated"));
T2.remove("jorjia");
CHECK(T2.relation("jorjia") == string("unrelated"));
T2.remove("klodin");
CHECK(T2.relation("klodin") == string("unrelated"));
T2.remove("armond");
CHECK(T2.relation("armond") == string("unrelated"));
T2.remove("haya");
CHECK(T2.relation("haya") == string("unrelated"));
T2.remove("shabtai");
CHECK(T2.relation("shabtai") == string("unrelated"));
T2.remove("tali");
CHECK(T2.relation("tali") == string("unrelated"));
T2.remove("yoram");
CHECK(T2.relation("yoram") == string("unrelated"));
CHECK(T2.relation("omer") == string("me"));

family::Tree T3 ("me");
T3.addFather("me", "father")
	 .addMother("me", "mother")
	 .addFather("father", "grandfather")
	 .addMother("father", "grandmother")
	 .addFather("grandmother", "great-grandfather")
	 .addMother("grandfather", "great-grandmother")
	 .addFather("great-grandfather", "great-great-grandfather")
	 .addMother("great-grandfather", "great-great-grandmother");

T3.remove("mother");
T3.remove("father");
CHECK(T3.relation("mother") == string("unrelated"));
CHECK(T3.relation("father") == string("unrelated"));
CHECK(T3.relation("grandmother") == string("unrelated"));
CHECK(T3.relation("grandfather") == string("unrelated"));
CHECK(T3.relation("great-grandmother") == string("unrelated"));
CHECK(T3.relation("great-grandfather") == string("unrelated"));
CHECK(T3.relation("great-great-grandmother") == string("unrelated"));
CHECK(T3.relation("great-great-grandfather") == string("unrelated"));
CHECK(T3.relation("great-great-great-grandmother") == string("unrelated"));
CHECK(T3.relation("great-great-great-grandfather") == string("unrelated"));
CHECK(T3.relation("me") == string("me"));

}


