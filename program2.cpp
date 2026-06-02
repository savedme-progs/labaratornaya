#include <iostream>

using namespace std;

class Detail
{
private:
    double size;

public:
    Detail(double s = 0)
    {
        size = s;
    }

    Detail(const Detail& other)
    {
        size = other.size;
    }

    double getSize() const
    {
        return size;
    }
};

int main()
{
    int n;
    double A, B;

    cout << "Введите количество деталей: ";
    cin >> n;

    cout << "Введите нижнюю границу A: ";
    cin >> A;
    cout << "Введите верхнюю границу B: ";
    cin >> B;

    Detail* parts = new Detail[n];

    cout << "\nВведите размеры деталей:\n";
    for (int i = 0; i < n; i++) {
        double s;
        cout << "Деталь " << i + 1 << ": ";
        cin >> s;
        parts[i] = Detail(s);
    }

    Detail* defects = new Detail[n];
    int defectCount = 0;

    for (int i = 0; i < n; i++) {
        if (parts[i].getSize() < A || parts[i].getSize() > B) {
            defects[defectCount] = Detail(parts[i]);
            defectCount++;
        }
    }

    if (defectCount > 0) {
        cout << "\nБракованных деталей: " << defectCount << endl;
        cout << "Их размеры: ";
        for (int i = 0; i < defectCount; i++) {
            cout << defects[i].getSize() << " ";
        }
        cout << endl;
    } else {
        cout << "\nБракованных деталей нет. Все детали соответствуют норме." << endl;
    }

    delete[] parts;
    delete[] defects;

    return 0;
}
