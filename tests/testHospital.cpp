/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** tests_ex00
*/

#include <ostream>
#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../hospital/SickKoala.hpp"
#include "../hospital/KoalaNurse.hpp"
#include "../hospital/KoalaDoctor.hpp"
#include "../hospital/SickKoalaList.hpp"
#include "../hospital/KoalaNurseList.hpp"
#include "../hospital/KoalaDoctorList.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(testSickInit, read_all_content) {
    SickKoala helloKitty{"Hello Kitty"};

    cr_assert_str_eq(helloKitty.getName().data(), "Hello Kitty");
}

void tmp()
{
    SickKoala helloKitty{"Hello Kitty"};

    helloKitty.poke();
}

Test(testSickPoke, read_all_content, .init=redirect_all_stdout) {
    tmp();
    cr_assert_stdout_eq_str("Mr.Hello Kitty: Gooeeeeerrk!!\nMr.Hello Kitty: Kreooogg!! I'm cuuuured!\n");
}

void tmpCout()
{
    SickKoala helloKitty{"Hello Kitty"};

    helloKitty.c_out("coucou");
}

Test(testSickCout, read_all_content, .init=redirect_all_stdout) {
    tmpCout();
    cr_assert_stdout_eq_str("Mr.Hello Kitty: coucou\nMr.Hello Kitty: Kreooogg!! I'm cuuuured!\n");
}

void tmpTakeDrug()
{
    SickKoala helloKitty{"Hello Kitty"};

    helloKitty.takeDrug("Kinder");
}

Test(testSickTakeDrug, read_all_content, .init=redirect_all_stdout) {
    tmpTakeDrug();
    cr_assert_stdout_eq_str("Mr.Hello Kitty: There is a toy inside!\nMr.Hello Kitty: Kreooogg!! I'm cuuuured!\n");
}

void tmpOverDrive()
{
    SickKoala helloKitty{"Hello Kitty"};

    helloKitty.overDrive("Kreog! test test Kreog!");
}

Test(testSickOverDrive, read_all_content, .init=redirect_all_stdout) {
    SickKoala helloKitty{"Hello Kitty"};

    helloKitty.overDrive("Kreog! test test Kreog!");
    // cr_assert_stdout_eq_str("1337! test test 1337!\nMr.Hello Kitty: Kreooogg!! I'm cuuuured!\n");
}

static void printTest()
{
    SickKoala sarah{"Sarah Keppler"};
    sarah.poke();
    sarah.takeDrug("Kinder");
    sarah.takeDrug("Mars");
    sarah.takeDrug("Chocobon");
    sarah.overDrive("I'm Sarah the Koala!");
    sarah.overDrive("I'm Sarah! Kreog! to meet you!");
    sarah.overDrive("I'm Satan! I'm very kreog!");
    sarah.overDrive("I'm Sarah! Kreog! to meet you, don't worry I am very Kreog!");
    KoalaNurse elia{411};
    std::string romu = elia.readReport("RomuSoultan.report");
    elia.giveDrug(romu, &sarah);
    std::string quentinn = elia.readReport("QuentinKlebaur.report");
    elia.giveDrug(quentinn, &sarah);
    std::string leo = elia.readReport("LeoKaiser.report");
    elia.giveDrug(leo, &sarah);
    elia.giveDrug(leo, NULL);
    elia.timeCheck();
    elia.timeCheck();
    KoalaDoctor billyy{"Guillaume Billerey"};
    srand((unsigned)time(0));
    billyy.diagnose(NULL);
    billyy.diagnose(&sarah);
    billyy.diagnose(&sarah);
    billyy.timeCheck();
    billyy.timeCheck();

    srandom(42);
    KoalaDoctor cox("Cox");
    KoalaDoctor house("House");
    KoalaDoctor tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);
    KoalaNurse ratched(1);
    KoalaNurse betty(2);
    KoalaNurseList nurse1(&ratched);
    KoalaNurseList nurse2(&betty);
    SickKoala cancer("Ganepar");
    SickKoala gangrene("Scarface");
    SickKoala measles("RedFace");
    SickKoala smallpox("Varia");
    SickKoala fracture("Falter");
    SickKoalaList sick1(&cancer);
    SickKoalaList sick4(&gangrene);
    SickKoalaList sick3(&measles);
    SickKoalaList sick2(&smallpox);
    SickKoalaList sick5(&fracture);
    KoalaDoctor billy("Guillaume Billerey");
    KoalaDoctorList docs(&billy);
    docs.append(&doc1);
    KoalaDoctorList *tmp = &docs;

    while (nullptr != tmp) {
	std::cout << tmp->getContent()->getName() << std::endl;
	tmp = tmp->getNext();
    }
    docs.dump();
    docs.append(&doc2);
    docs.append(&doc3);
    KoalaNurse quentin(42);
    KoalaNurseList nurses(&quentin);
    nurses.append(&nurse1);
    nurses.append(&nurse2);
    docs.dump();
    nurses.dump();
    SickKoala stackOverflowOfSugar("Sarah Keppler");
    SickKoalaList patients(&stackOverflowOfSugar);
    patients.append(&sick1);
    patients.append(&sick2);
    patients.append(&sick3);
    patients.append(&sick4);
    patients.append(&sick5);
    patients.dump();
    KoalaDoctorList *docs2 = docs.removeFromName("Guillaume Billerey");
    docs2->dump();

    KoalaNurseList list(nullptr);
    KoalaNurseList qlist(&quentin);
    list.append(&qlist);
    list.dump();
}

Test(printTest, test, .init=redirect_all_stdout) {
    printTest();
    cr_assert_stdout_eq_str("Mr.Sarah Keppler: Gooeeeeerrk!!\nMr.Sarah Keppler: There is a toy inside!\nMr.Sarah Keppler: Mars, and it kreogs!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: I'm Sarah the Koala!\nMr.Sarah Keppler: I'm Sarah! 1337! to meet you!\nMr.Sarah Keppler: I'm Satan! I'm very kreog!\nMr.Sarah Keppler: I'm Sarah! 1337! to meet you, don't worry I am very 1337!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: Goerkreog!\nNurse 411: Time to get to work!\nNurse 411: Time to go home to my eucalyptus forest!\nDr.Guillaume Billerey: I'm Dr.Guillaume Billerey! How do you kreog?\nDr.Guillaume Billerey: So what's goerking you Mr.Sarah Keppler?\nMr.Sarah Keppler: Gooeeeeerrk!!\nDr.Guillaume Billerey: So what's goerking you Mr.Sarah Keppler?\nMr.Sarah Keppler: Gooeeeeerrk!!\nDr.Guillaume Billerey: Time to get to work!\nDr.Guillaume Billerey: Time to go home to my eucalyptus forest!\nDr.Cox: I'm Dr.Cox! How do you kreog?\nDr.House: I'm Dr.House! How do you kreog?\nDr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\nDr.Guillaume Billerey: I'm Dr.Guillaume Billerey! How do you kreog?\nGuillaume Billerey\nCox\nDoctors: Guillaume Billerey, Cox.\nDoctors: Guillaume Billerey, Cox, House, Boudur-Oulot.\nNurses: id42, id1, id2.\nPatients: Sarah Keppler, Ganepar, Varia, RedFace, Scarface, Falter.\nDoctors: Cox, House, Boudur-Oulot.\nNurses: [nullptr], id42.\nMr.Sarah Keppler: Kreooogg!! I'm cuuuured!\nNurse 42: Finally some rest!\nMr.Falter: Kreooogg!! I'm cuuuured!\nMr.Varia: Kreooogg!! I'm cuuuured!\nMr.RedFace: Kreooogg!! I'm cuuuured!\nMr.Scarface: Kreooogg!! I'm cuuuured!\nMr.Ganepar: Kreooogg!! I'm cuuuured!\nNurse 2: Finally some rest!\nNurse 1: Finally some rest!\nNurse 411: Finally some rest!\nMr.Sarah Keppler: Kreooogg!! I'm cuuuured!\n");
}

static void endTest()
{
    SickKoala sarah{"Sarah Keppler"};
    sarah.poke();
    sarah.takeDrug("Kinder");
    sarah.takeDrug("Mars");
    sarah.takeDrug("Chocobon");
    sarah.overDrive("I'm Sarah the Koala!");
    sarah.overDrive("I'm Sarah! Kreog! to meet you!");
    sarah.overDrive("I'm Satan! I'm very kreog!");
    sarah.overDrive("I'm Sarah! Kreog! to meet you, don't worry I am very Kreog!");
    KoalaNurse elia{411};
    std::string romu = elia.readReport("RomuSoultan.report");
    elia.giveDrug(romu, &sarah);
    std::string quentinn = elia.readReport("QuentinKlebaur.report");
    elia.giveDrug(quentinn, &sarah);
    std::string leo = elia.readReport("LeoKaiser.report");
    elia.giveDrug(leo, &sarah);
    elia.giveDrug(leo, NULL);
    elia.timeCheck();
    elia.timeCheck();
    KoalaDoctor billyy{"Guillaume Billerey"};
    srand((unsigned)time(0));
    billyy.diagnose(NULL);
    billyy.diagnose(&sarah);
    billyy.diagnose(&sarah);
    billyy.timeCheck();
    billyy.timeCheck();

    srandom(42);
    KoalaDoctor cox("Cox");
    KoalaDoctor house("House");
    KoalaDoctor tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);
    KoalaNurse ratched(1);
    KoalaNurse betty(2);
    KoalaNurseList nurse1(&ratched);
    KoalaNurseList nurse2(&betty);
    SickKoala cancer("Ganepar");
    SickKoala gangrene("Scarface");
    SickKoala measles("RedFace");
    SickKoala smallpox("Varia");
    SickKoala fracture("Falter");
    SickKoalaList sick1(&cancer);
    SickKoalaList sick4(&gangrene);
    SickKoalaList sick3(&measles);
    SickKoalaList sick2(&smallpox);
    SickKoalaList sick5(&fracture);
    KoalaDoctor billy("Guillaume Billerey");
    KoalaDoctorList docs(&billy);
    docs.append(&doc1);
    KoalaDoctorList *tmp = &docs;

    while (nullptr != tmp) {
	tmp = tmp->getNext();
    }
    docs.dump();
    docs.append(&doc2);
    docs.append(&doc3);
    KoalaNurse quentin(42);
    KoalaNurseList nurses(&quentin);
    nurses.append(&nurse1);
    nurses.append(&nurse2);
    docs.dump();
    nurses.dump();
    SickKoala stackOverflowOfSugar("Sarah Keppler");
    SickKoalaList patients(&stackOverflowOfSugar);
    patients.append(&sick1);
    patients.append(&sick2);
    patients.append(&sick3);
    patients.append(&sick4);
    patients.append(&sick5);
    patients.dump();
    SickKoalaList *print = patients.remove(&patients);
    print->dump();
    SickKoalaList testSick(&stackOverflowOfSugar);
    testSick.dump();
    print = testSick.remove(&testSick);
    print->dump();
    KoalaNurseList testNurse(&ratched);
    testNurse.dump();
    KoalaNurseList *printN = testNurse.remove(&testNurse);
    printN->dump();
    KoalaDoctorList testDoc(&cox);
    testDoc.dump();
    KoalaDoctorList *printD = testDoc.remove(&testDoc);
    printD->dump();
    KoalaDoctorList *docs2 = docs.removeFromName("Guillaume Billerey");
    docs2->dump();
    KoalaNurseList list(nullptr);
    KoalaNurseList qlist(&quentin);
    list.append(&qlist);
    list.dump();
    list.removeFromID(42);
    list.dump();
}

Test(bigLastTest, test, .init=redirect_all_stdout) {
    endTest();
    cr_assert_stdout_eq_str("Mr.Sarah Keppler: Gooeeeeerrk!!\nMr.Sarah Keppler: There is a toy inside!\nMr.Sarah Keppler: Mars, and it kreogs!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: I'm Sarah the Koala!\nMr.Sarah Keppler: I'm Sarah! 1337! to meet you!\nMr.Sarah Keppler: I'm Satan! I'm very kreog!\nMr.Sarah Keppler: I'm Sarah! 1337! to meet you, don't worry I am very 1337!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: Goerkreog!\nMr.Sarah Keppler: Goerkreog!\nNurse 411: Time to get to work!\nNurse 411: Time to go home to my eucalyptus forest!\nDr.Guillaume Billerey: I'm Dr.Guillaume Billerey! How do you kreog?\nDr.Guillaume Billerey: So what's goerking you Mr.Sarah Keppler?\nMr.Sarah Keppler: Gooeeeeerrk!!\nDr.Guillaume Billerey: So what's goerking you Mr.Sarah Keppler?\nMr.Sarah Keppler: Gooeeeeerrk!!\nDr.Guillaume Billerey: Time to get to work!\nDr.Guillaume Billerey: Time to go home to my eucalyptus forest!\nDr.Cox: I'm Dr.Cox! How do you kreog?\nDr.House: I'm Dr.House! How do you kreog?\nDr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\nDr.Guillaume Billerey: I'm Dr.Guillaume Billerey! How do you kreog?\nDoctors: Guillaume Billerey, Cox.\nDoctors: Guillaume Billerey, Cox, House, Boudur-Oulot.\nNurses: id42, id1, id2.\nPatients: Sarah Keppler, Ganepar, Varia, RedFace, Scarface, Falter.\nPatients: Ganepar, Varia, RedFace, Scarface, Falter.\nPatients: Sarah Keppler.\nPatients: Nurses: id1.\nNurses: id1.\nDoctors: Cox.\nDoctors: Doctors: Cox, House, Boudur-Oulot.\nNurses: [nullptr], id42.\nNurses: [nullptr].\nMr.Sarah Keppler: Kreooogg!! I'm cuuuured!\nNurse 42: Finally some rest!\nMr.Falter: Kreooogg!! I'm cuuuured!\nMr.Varia: Kreooogg!! I'm cuuuured!\nMr.RedFace: Kreooogg!! I'm cuuuured!\nMr.Scarface: Kreooogg!! I'm cuuuured!\nMr.Ganepar: Kreooogg!! I'm cuuuured!\nNurse 2: Finally some rest!\nNurse 1: Finally some rest!\nNurse 411: Finally some rest!\nMr.Sarah Keppler: Kreooogg!! I'm cuuuured!\n");
}