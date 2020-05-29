#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Student{
public:
    string firstname;
    string surname;
    int age;
    int kurs;

    Student(){//1
        firstname = "Ivan";
        surname = "Ivanov";
        age = 18;
        kurs = 1;
    }
    Student(string f, string s, int a, int k){//2
        firstname = f;
        surname = s;
        age = a;
        kurs = k;
    }
    Student(const Student &s){//3
        firstname = s.firstname;
        surname = s.surname;
        age = s.age;
        kurs = s.kurs;
    }

    ~Student() //Деструктор
    {
        cout << "deleted student " <<firstname<< endl;
    }

    void set_student(){         // Заполнение из клавиатуры
        cout<<"firstname: "<<endl;
        getline(cin,firstname);
        cout<<"surname: "<<endl;
        getline(cin,surname);
        cout<<"age: "<<endl;
        cin>>age;
        cout<<"kurs: "<<endl;
        cin>>kurs;
    }
    void print_student(){       //Вывод на экран
        cout<<"firstname: "<<firstname<<endl;
        cout<<"surname: "<<surname<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"mark: "<<kurs<<endl;

    }
    void load_student(){        //Загрузить из файла
        string filename = firstname+"_"+surname+".bin";
        ifstream s_bin(filename, ios::binary | ios::in);
        s_bin.read((char*)this,sizeof *this);
        s_bin.close();
    }
    void save_student(){        //Сохранить в файл
        string filename = firstname+"_"+surname+".bin";
        ofstream s_bin(filename, ios::binary | ios::out);
        s_bin.write((char*)this,sizeof *this);
        s_bin.close();
    }
    //void small_stundent(int kurs, int count) {
    //    Student temp = Student("Sasha", "Mihalkov", 1, 100);
    //  //  int min_old = 0;
    //    for (int i = 0; i < count; i++) {
    //        for (int j = 0; j < count; j++) {
    //        if(this->kurs == kurs && this->age <= age[] )
    //        }
    //    }
    //}

};
int main() {
    setlocale(LC_ALL, "Russian");
    Student s1 = Student("Alexnader","Wang", 14,4);
    Student s2;
    Student s3 = s1;
    Student temp;
    Student st_List[20] = { Student("Alex","Miller", 18,1), Student("Misha","Hokkins", 17,1), Student("Michael","Dorol", 18,1), Student("Miam","New", 18,1), Student("Ivan","Smirnov", 19,1),/****2kurs****/Student("Alexey","Voronin", 18,2),Student("Immanuel","Warter", 19,2),Student("Leo","Milliw", 19,2),Student("Rafael","Dororo", 20,2),Student("Jakob","Landers", 19,2),/****3kurs****/Student("Daniel","Mirov", 20,3),Student("Uriel","Summers", 21,3),Student("Hiro","Zerotwo", 20,3),Student("Don","Makros", 20,3),Student("Markus","Villa", 19,3),/****4kurs****/Student("Petr","Sokolov", 22,4),Student("Artem","Meshkov", 21,4),Student("Gerogie","Spider", 23,4),Student("Java","Enterprise", 22,4),Student("Thomas","Hopelienen", 20,4) };
   
   
   cout << "Младшие студенты на каждом из курсов " << endl << "Первый курс: ";
    for (int i = 0; i < 5; i++) {
        int k = 0;
        for (int j = 0; j < 5; j++) {
            if (st_List[i].age <= st_List[j].age && st_List[i].kurs == 1)
                k++;
            if (k == 5 ) st_List[i].print_student();
        }
    }
    cout << endl << "Второй курс: ";
    for (int i = 5; i < 10; i++) {
        int k = 0;
        for (int j = 5; j < 10; j++) {
            if (st_List[i].age <= st_List[j].age && st_List[i].kurs == 2)
                k++;
            if (k == 5) st_List[i].print_student();
        }
    }
    cout << endl << "Третий курс: ";
    for (int i = 10; i < 15; i++) {
        int k = 0;
        for (int j = 10; j < 15; j++) {
            if (st_List[i].age <= st_List[j].age && st_List[i].kurs == 3)
                k++;
            if (k == 5) st_List[i].print_student();
        }
    }
    cout << endl << "Четвёртый курс: ";
    for (int i = 15; i < 20; i++) {
        int k = 0;
        for (int j = 15; j < 20; j++) {
            if (st_List[i].age <= st_List[j].age && st_List[i].kurs == 4)
                k++;
            if (k == 5) st_List[i].print_student();
        }
    }



    s1.save_student();
    s1.age = 0;
    s1.print_student();
    cout<<endl<<endl;
    s1.load_student();
    s1.print_student();

    return 0;
}
