#include <iostream>
#include <cstdlib>
#include "room.h"
#include "users.h"

bool emergencyMode=false;

void professorAskKeys(Professor &professorA, Professor &professorB) {
    cout << professorA.getName() << " has forgot his keys in his cabinet. " << professorB.getName() << " was around and he knew that he can help out." << endl;
    if (professorB.access(professorA.getCabinet())) {
        cout << professorA.getName() << " is saved" << endl;
    } else {
        cout << "Oh no, colleague couldn't access the cabinet" << endl;
    }
}

void tryAccessRoom(User &user, Room room){
    if(user.access(room) || emergencyMode)
        cout<<user.getName()<<" went in "<<room.getNumber()<<" room."<<endl;
    else
        cout<<user.getName()<<" tried but could not enter in "<<room.getNumber()<<" room."<<endl;
    }

void startEmergency(User &user){
    cout<<user.getName()<<" turned on emergency. "<<endl;
    emergencyMode= true;
}
void endEmergency(Admin &admin){
    cout<<admin.getName()<<" turned off emergency."<<endl;
    emergencyMode= false;
}


int main() {
    ClassRoom* classes[10];
    for (int i = 0; i < 10; i++) {
        classes[i] = new ClassRoom(i);
    }


    Director director = Director("Director", 0);



    Admin admin = Admin("Admin");
    Admin admin1 = Admin("Admin B");

    Professor professorFunny = Professor("The funniest professor", 11, "Funny joke");
    Professor professorBoring = Professor("Unfunny professor", 12, "Unfunny joke");
    Professor professor = Professor("Professor", 13, "Joke A");
    Professor professor1 = Professor("Professor B", 14, "Joke B");

    Cabinet CSLabCabinet = Cabinet(15);
    LectureRoom PSSLecture = LectureRoom(108,1);
    LectureRoom notPSSLecture = LectureRoom(208,2);
    ConferenceRoom Confernece153 = ConferenceRoom (153,1);
    ConferenceRoom Conference236 = ConferenceRoom(236,2);

    LabEmployee* employees[8];
    for (auto & employee : employees) {
        employee = new LabEmployee("employee", CSLabCabinet);
    }

    Student* students[16];
    for (auto & student : students) {
        student = new Student("student", 1);
    }
    Guest* guests[24];
    for (auto & guest : guests) {
        guest = new Guest("guest");
    }
    professorAskKeys(professor, professor1);

    professor1.addCustomAccess(admin, director.getCabinet());
    tryAccessRoom(professor1,director.getCabinet());

    professor1.cancelCustomAccess(admin1, director.getCabinet());
    tryAccessRoom(professor1,director.getCabinet());

    tryAccessRoom(*employees[3],professor1.getCabinet());

    tryAccessRoom(*students[5],PSSLecture);

    tryAccessRoom(*guests[7],PSSLecture);
    tryAccessRoom(*guests[15],notPSSLecture);


    tryAccessRoom(*guests[20], Conference236);
    startEmergency(professorBoring);
    tryAccessRoom(*guests[20], Conference236);
    endEmergency(admin1);
    tryAccessRoom(*guests[20], Conference236);


    for (auto student : students) { free(student); }
    for (auto guest : guests) { free(guest); }
    for (auto clazz : classes) { free(clazz); }
    for (auto emp : employees) { free(emp); }
}

