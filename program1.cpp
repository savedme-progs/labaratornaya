#include <iostream> 

#include <list> 

#include <string> 

using namespace std; 

 

class Book { 

public: 

    string author, title; 

    int year; 

 

    Book(string a, string t, int y) : author(a), title(t), year(y) {} 

 

    bool operator==(const Book& b) const { 

        return author == b.author && title == b.title && year == b.year; 

    } 

 

    void print() const { 

        cout << author << " | " << title << " | " << year << endl; 

    } 

}; 

 

int main() { 

    list<Book> list1 = { 

        {"Толстой", "Война и мир", 1869}, 

        {"Пушкин", "Евгений Онегин", 1833}, 

        {"Гоголь", "Мёртвые души", 1842} 

    }; 

 

    list<Book> list2 = { 

        {"Пушкин", "Евгений Онегин", 1833}, 

        {"Достоевский", "Преступление и наказание", 1866}, 

        {"Булгаков", "Мастер и Маргарита", 1967} 

    }; 

 

    for (const Book& b2 : list2) { 

        bool found = false; 

        for (const Book& b1 : list1) { 

            if (b1 == b2) { 

                found = true; 

                break; 

            } 

        } 

        if (!found) { 

            list1.push_back(b2); 

        } 

    } 

 

    cout << "Итоговый список:" << endl; 

    for (const Book& b : list1) { 

        b.print(); 

    } 

 

    return 0; 

} 
